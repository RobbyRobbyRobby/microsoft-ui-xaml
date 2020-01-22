﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "ProgressRing.h"
#include "RuntimeProfiler.h"
#include "ResourceAccessor.h"
#include "math.h"

ProgressRing::ProgressRing()
{
    __RP_Marker_ClassById(RuntimeProfiler::ProfId_ProgressRing);

    SetDefaultStyleKey(this);

    RegisterPropertyChangedCallback(winrt::RangeBase::ValueProperty(), { this, &ProgressRing::OnRangeBasePropertyChanged });
    RegisterPropertyChangedCallback(winrt::Control::ForegroundProperty(), { this, &ProgressRing::OnForegroundPropertyChanged });
    RegisterPropertyChangedCallback(winrt::Control::BackgroundProperty(), { this, &ProgressRing::OnBackgroundPropertyChanged });

    SizeChanged({ this, &ProgressRing::OnSizeChanged });
}

void ProgressRing::OnApplyTemplate()
{
    winrt::IControlProtected controlProtected{ *this };

    m_outlineFigure.set(GetTemplateChildT<winrt::PathFigure>(s_OutlineFigureName, controlProtected));
    m_outlineArc.set(GetTemplateChildT<winrt::ArcSegment>(s_OutlineArcName, controlProtected));
    m_ringFigure.set(GetTemplateChildT<winrt::PathFigure>(s_BarFigureName, controlProtected));
    m_ringArc.set(GetTemplateChildT<winrt::ArcSegment>(s_BarArcName, controlProtected));
    m_player.set(GetTemplateChildT<winrt::AnimatedVisualPlayer>(s_LottiePlayerName, controlProtected));

    ApplyLottieAnimation();
    UpdateRing();
    UpdateStates();
}

void ProgressRing::OnSizeChanged(const winrt::IInspectable&, const winrt::IInspectable&)
{
    ApplyLottieAnimation();
    UpdateRing();
}

void ProgressRing::OnRangeBasePropertyChanged(const winrt::DependencyObject&, const winrt::DependencyProperty&)
{
    UpdateSegment();
}

void ProgressRing::OnForegroundPropertyChanged(const winrt::DependencyObject&, const winrt::DependencyProperty&)
{
    ApplyLottieAnimation();
}

void ProgressRing::OnBackgroundPropertyChanged(const winrt::DependencyObject&, const winrt::DependencyProperty&)
{
    ApplyLottieAnimation();
}

void ProgressRing::OnStrokeThicknessPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    ApplyLottieAnimation();
    UpdateRing();
}

void ProgressRing::OnIsIndeterminatePropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    UpdateStates();
}

void ProgressRing::ApplyLottieAnimation()
{
    if (auto&& player = m_player.get())
    {
        // ProgressRing only accounts for ActualWidth to ensure that it is always a circle
        const float diameter = static_cast<float>(ActualWidth());
        const auto size = winrt::Size({ diameter, diameter });

        auto foreground = SharedHelpers::FindResource(s_DefaultForegroundThemeResourceName, winrt::Application::Current().Resources()).as<winrt::SolidColorBrush>().Color();
        auto background = SharedHelpers::FindResource(s_DefaultBackgroundThemeResourceName, winrt::Application::Current().Resources()).as<winrt::SolidColorBrush>().Color();

        if (Foreground().try_as<winrt::SolidColorBrush>())
        {
            foreground = Foreground().try_as<winrt::SolidColorBrush>().Color();
        }
        if (Background().try_as<winrt::SolidColorBrush>())
        {
            background = Background().try_as<winrt::SolidColorBrush>().Color();
        }
        
        player.Source(winrt::make<ProgressRingLoading>(StrokeThickness(), size, foreground, background));
    }
}

void ProgressRing::UpdateStates()
{
    if (IsIndeterminate())
    {
        winrt::VisualStateManager::GoToState(*this, s_IndeterminateStateName, true);

        if (auto&& player = m_player.get())
        {
            player.PlayAsync(0, 1, true);
        }
    }
    else if (!IsIndeterminate())
    {
        winrt::VisualStateManager::GoToState(*this, s_DeterminateStateName, true);

        if (auto&& player = m_player.get())
        {
            player.Stop();
        }
    }
}

winrt::Size ProgressRing::ComputeCircleSize(double thickness, double actualWidth)
{
    const double safeThickness = std::max(thickness, static_cast<double>(0.0));

    // ProgressRing only accounts for ActualWidth to ensure that it is always a circle
    const double radius = std::max((actualWidth - safeThickness) / 2.0, 0.0);

    return {static_cast<float>(radius), static_cast<float>(radius)};
}


void ProgressRing::UpdateSegment()
{
    if (auto&& ringArc = m_ringArc.get())
    {
        auto const angle = [this]()
        {
            auto const normalizedRange = [this]()
            {
                const double minimum = Minimum();
                const double range = Maximum() - minimum;
                const double delta = Value() - minimum;

                const double normalizedRange = (range == 0.0) ? 0.0 : (delta / range);
                // normalizedRange offsets calculation to display a full ring when value = 100%
                // std::nextafter is set as a float as winrt::Point takes floats 
                return std::min(normalizedRange, static_cast<double>(std::nextafterf(1.0, 0.0)));
            }();
            return 2 * M_PI * normalizedRange;
        }();

        const double thickness = StrokeThickness();
        const auto size = ComputeCircleSize(thickness, ActualWidth());
        const double translationFactor = std::max(thickness / 2.0, 0.0);

        const double x = (std::sin(angle) * size.Width) + size.Width + translationFactor;
        const double y = (((std::cos(angle) * size.Height) - size.Height) * -1) + translationFactor;

        ringArc.IsLargeArc(angle >= M_PI);
        ringArc.Point(winrt::Point(static_cast<float>(x), static_cast<float>(y)));
    }

}

void ProgressRing::UpdateRing()
{
    const double thickness = StrokeThickness();
    const auto size = ComputeCircleSize(thickness, ActualWidth());

    const float segmentWidth = size.Width;
    const float translationFactor = static_cast<float>(std::max(thickness / 2.0, 0.0));

    if (auto&& outlineFigure = m_outlineFigure.get())
    {
        outlineFigure.StartPoint(winrt::Point(segmentWidth + translationFactor, translationFactor));
    }

    if (auto&& ringFigure = m_ringFigure.get())
    {
        ringFigure.StartPoint(winrt::Point(segmentWidth + translationFactor, translationFactor));
    }

    if (auto&& outlineArc = m_outlineArc.get())
    {
        outlineArc.Size(winrt::Size(segmentWidth, size.Height));
        outlineArc.Point(winrt::Point(segmentWidth + translationFactor - 0.05f, translationFactor));
    }

    if (auto&& ringArc = m_ringArc.get())
    {  
        ringArc.Size(winrt::Size(segmentWidth, size.Height));
    }

    UpdateSegment();
}
