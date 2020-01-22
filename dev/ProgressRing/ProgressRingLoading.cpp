﻿// This file was auto-generated then been modified to update animation visuals with inherited visual properties

#include "pch.h"
#include "common.h"
#include "ProgressRingLoading.h"
#include "WindowsNumerics.h"

static bool IsRuntimeCompatible()
{
    if (!winrt::Windows::Foundation::Metadata::ApiInformation::IsTypePresent(L"Windows.UI.Composition.CompositionGeometricClip"))
    {
        return false;
    }
    return true;
}

class ProgressRingAnimatedVisual :
    public winrt::implements<ProgressRingAnimatedVisual, winrt::IAnimatedVisual, winrt::IClosable>
{
    static constexpr auto c_durationTicks = 2000ms;
    winrt::Compositor const _c{ nullptr };
    winrt::ExpressionAnimation const _reusableExpressionAnimation{ nullptr };
    winrt::CubicBezierEasingFunction _cubicBezierEasingFunction{ nullptr };
    winrt::StepEasingFunction _holdThenStepEasingFunction{ nullptr };
    winrt::ContainerVisual _root{ nullptr };
    winrt::ExpressionAnimation _scalarExpressionAnimation{ nullptr };

    double _strokeThickness{ 4 };
    winrt::Size _size{ 40, 40 };
    winrt::Color _foreground{ winrt::ColorHelper::FromArgb(0xFF, 0x00, 0x78, 0xD7) };
    winrt::Color _background{ winrt::ColorHelper::FromArgb(0xFF, 0xD3, 0xD3, 0xD3) };

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    winrt::CompositionColorBrush AnimatedColorBrush_AlmostDodgerBlue_FF0078D7_to_TransparentAlmostDodgerBlue_000078D7()
    {
        auto result = _c.CreateColorBrush(_foreground);
        result.StartAnimation(L"Color", ColorAnimation_AlmostDodgerBlue_FF0078D7_to_TransparentAlmostDodgerBlue_000078D7());
        auto controller = result.TryGetAnimationController(L"Color");
        controller.Pause();
        controller.StartAnimation(L"Progress", _scalarExpressionAnimation);
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    winrt::CompositionColorBrush AnimatedColorBrush_TransparentAlmostDodgerBlue_000078D7_to_AlmostDodgerBlue_FF0078D7()
    {
        auto result = _c.CreateColorBrush(winrt::Colors::Transparent());
        result.StartAnimation(L"Color", ColorAnimation_TransparentAlmostDodgerBlue_000078D7_to_AlmostDodgerBlue_FF0078D7());
        auto controller = result.TryGetAnimationController(L"Color");
        controller.Pause();
        controller.StartAnimation(L"Progress", _scalarExpressionAnimation);
        return result;
    }

    // Color
    winrt::ColorKeyFrameAnimation ColorAnimation_AlmostDodgerBlue_FF0078D7_to_TransparentAlmostDodgerBlue_000078D7()
    {
        auto result = _c.CreateColorKeyFrameAnimation();
        result.Duration({ c_durationTicks });
        auto test = winrt::CompositionColorSpace::Rgb;
        result.InterpolationColorSpace(test);
        // Foreground
        result.InsertKeyFrame(0, _foreground, _holdThenStepEasingFunction);
        // Transparent
        result.InsertKeyFrame(0.5F, winrt::Colors::Transparent(), _holdThenStepEasingFunction);
        return result;
    }

    // Color
    winrt::ColorKeyFrameAnimation ColorAnimation_TransparentAlmostDodgerBlue_000078D7_to_AlmostDodgerBlue_FF0078D7()
    {
        auto result = _c.CreateColorKeyFrameAnimation();
        result.Duration({ c_durationTicks });
        result.InterpolationColorSpace(winrt::CompositionColorSpace::Rgb);
        // Transparent
        result.InsertKeyFrame(0, winrt::Colors::Transparent(), _holdThenStepEasingFunction);
        // Foreground Color
        result.InsertKeyFrame(0.5F, _foreground, _holdThenStepEasingFunction);
        return result;
    }

    // Ellipse Path
    winrt::CompositionColorBrush ColorBrush_LightGray()
    {
        return _c.CreateColorBrush(_background);
    }

    // Layer (Shape): Radial
    winrt::CompositionContainerShape ContainerShape_0()
    {
        auto result = _c.CreateContainerShape();
        result.TransformMatrix({5, 0, 0, 5, 50, 50});
        result.Offset({ _size.Width / 10.0f - 10.0f, _size.Height / 10.0f - 10.0f });
        auto shapes = result.Shapes();
        shapes.Append(ContainerShape_1());
        return result;
    }

    // Layer (Shape): Radial
    // Transforms for Radial
    winrt::CompositionContainerShape ContainerShape_1()
    {
        auto result = _c.CreateContainerShape();
        auto shapes = result.Shapes();
        shapes.Append(SpriteShape_2());
        shapes.Append(SpriteShape_3());
        result.StartAnimation(L"RotationAngleInDegrees", RotationAngleInDegreesScalarAnimation_0_to_900());
        auto controller = result.TryGetAnimationController(L"RotationAngleInDegrees");
        controller.Pause();
        controller.StartAnimation(L"Progress", _scalarExpressionAnimation);
        return result;
    }

    winrt::CubicBezierEasingFunction CubicBezierEasingFunction()
    {
        return _cubicBezierEasingFunction = _c.CreateCubicBezierEasingFunction({ 0.166999996F, 0.166999996F }, { 0.833000004F, 0.833000004F });
    }

    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    winrt::CompositionEllipseGeometry Ellipse_7_0()
    {
        auto result = _c.CreateEllipseGeometry();
        const float calculatedRadius = std::max(_size.Width / 10.0f - static_cast<float>(_strokeThickness) / 10.0f, 0.0f);
        result.Center({ _size.Width / 10.0f - 10.0f, _size.Height / 10.0f - 10.0f });
        result.Radius({ calculatedRadius, calculatedRadius });
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    winrt::CompositionEllipseGeometry Ellipse_7_1()
    {
        auto result = _c.CreateEllipseGeometry();
        result.TrimEnd(0.5F);
        const float calculatedRadius = std::max(_size.Width / 10.0f - static_cast<float>(_strokeThickness) / 10.0f, 0.0f);
        result.Radius({ calculatedRadius, calculatedRadius });
        result.StartAnimation(L"TrimStart", TrimStartScalarAnimation_0_to_0p5());
        auto controller = result.TryGetAnimationController(L"TrimStart");
        controller.Pause();
        controller.StartAnimation(L"Progress", ScalarExpressionAnimation());
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    winrt::CompositionEllipseGeometry Ellipse_7_2()
    {
        auto result = _c.CreateEllipseGeometry();
        const float calculatedRadius = std::max(_size.Width / 10.0f - static_cast<float>(_strokeThickness) / 10.0f, 0.0f);
        result.Radius({ calculatedRadius, calculatedRadius });
        result.StartAnimation(L"TrimEnd", TrimEndScalarAnimation_0_to_0p5());
        auto controller = result.TryGetAnimationController(L"TrimEnd");
        controller.Pause();
        controller.StartAnimation(L"Progress", _scalarExpressionAnimation);
        return result;
    }

    winrt::StepEasingFunction HoldThenStepEasingFunction()
    {
        auto result = _holdThenStepEasingFunction = _c.CreateStepEasingFunction();
        result.IsFinalStepSingleFrame(true);
        return result;
    }

    // The root of the composition.
    winrt::ContainerVisual Root()
    {
        auto result = _root = _c.CreateContainerVisual();
        auto propertySet = result.Properties();
        propertySet.InsertScalar(L"Progress", 0);
        auto children = result.Children();
        children.InsertAtTop(ShapeVisual());
        result.RelativeSizeAdjustment({ 1, 1 });
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Rotation
    winrt::ScalarKeyFrameAnimation RotationAngleInDegreesScalarAnimation_0_to_900()
    {
        auto result = _c.CreateScalarKeyFrameAnimation();
        result.Duration({ c_durationTicks });
        result.InsertKeyFrame(0, 0, _holdThenStepEasingFunction);
        result.InsertKeyFrame(0.5F, 450, _cubicBezierEasingFunction);
        result.InsertKeyFrame(1, 900, _cubicBezierEasingFunction);
        return result;
    }

    winrt::ExpressionAnimation ScalarExpressionAnimation()
    {
        auto result = _scalarExpressionAnimation = _c.CreateExpressionAnimation();
        result.SetReferenceParameter(L"_", _root);
        result.Expression(L"_.Progress");
        return result;
    }

    winrt::ShapeVisual ShapeVisual()
    {
        auto result = _c.CreateShapeVisual();
        result.Size(_size);
        auto shapes = result.Shapes();
        // Ellipse Path
        shapes.Append(SpriteShape_1());
        // Layer (Shape): Radial
        shapes.Append(ContainerShape_0());
        return result;
    }

    // Ellipse Path
    winrt::CompositionSpriteShape SpriteShape_1()
    {
        auto result = _c.CreateSpriteShape();
        result.TransformMatrix({5, 0, 0, 5, 50, 50});
        result.Geometry(Ellipse_7_0());
        result.StrokeBrush(ColorBrush_LightGray());
        result.StrokeDashCap(winrt::CompositionStrokeCap::Round);
        result.StrokeEndCap(winrt::CompositionStrokeCap::Round);
        result.StrokeStartCap(winrt::CompositionStrokeCap::Round);
        result.IsStrokeNonScaling(true);
        result.StrokeThickness(static_cast<float>(_strokeThickness));
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    winrt::CompositionSpriteShape SpriteShape_2()
    {
        auto result = _c.CreateSpriteShape();
        result.Geometry(Ellipse_7_1());
        result.StrokeBrush(AnimatedColorBrush_TransparentAlmostDodgerBlue_000078D7_to_AlmostDodgerBlue_FF0078D7());
        result.StrokeDashCap(winrt::CompositionStrokeCap::Round);
        result.StrokeEndCap(winrt::CompositionStrokeCap::Round);
        result.StrokeStartCap(winrt::CompositionStrokeCap::Round);
        result.IsStrokeNonScaling(true);
        result.StrokeThickness(static_cast<float>(_strokeThickness));
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    winrt::CompositionSpriteShape SpriteShape_3()
    {
        auto result = _c.CreateSpriteShape();
        result.Geometry(Ellipse_7_2());
        result.StrokeBrush(AnimatedColorBrush_AlmostDodgerBlue_FF0078D7_to_TransparentAlmostDodgerBlue_000078D7());
        result.StrokeDashCap(winrt::CompositionStrokeCap::Round);
        result.StrokeEndCap(winrt::CompositionStrokeCap::Round);
        result.StrokeStartCap(winrt::CompositionStrokeCap::Round);
        result.IsStrokeNonScaling(true);
        result.StrokeThickness(static_cast<float>(_strokeThickness));
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    // TrimStart
    winrt::StepEasingFunction StepThenHoldEasingFunction()
    {
        auto result = _c.CreateStepEasingFunction();
        result.IsInitialStepSingleFrame(true);
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    // TrimEnd
    winrt::ScalarKeyFrameAnimation TrimEndScalarAnimation_0_to_0p5()
    {
        auto result = _c.CreateScalarKeyFrameAnimation();
        result.Duration({ c_durationTicks });
        result.InsertKeyFrame(0, 9.99999975E-05F, _holdThenStepEasingFunction);
        result.InsertKeyFrame(0.5F, 0.5F, _cubicBezierEasingFunction);
        return result;
    }

    // Layer (Shape): Radial
    // Transforms: Radial
    // Ellipse Path
    // Ellipse Path.EllipseGeometry
    // TrimStart
    winrt::ScalarKeyFrameAnimation TrimStartScalarAnimation_0_to_0p5()
    {
        auto result = _c.CreateScalarKeyFrameAnimation();
        result.Duration({ c_durationTicks });
        result.InsertKeyFrame(0, 0, StepThenHoldEasingFunction());
        result.InsertKeyFrame(0.5F, 0, HoldThenStepEasingFunction());
        result.InsertKeyFrame(1, 0.5F, CubicBezierEasingFunction());
        return result;
    }

public:
    ProgressRingAnimatedVisual(winrt::Compositor compositor, double strokeThickness, winrt::Size size, winrt::Color foreground, winrt::Color background)
        : _c(compositor),
        _reusableExpressionAnimation(compositor.CreateExpressionAnimation()),
        _strokeThickness(strokeThickness),
        _size(size),
        _foreground(foreground),
        _background(background)
    {
        Root();
    }

    [[nodiscard]] auto RootVisual() const
    {
        return _root;
    }

    [[nodiscard]] winrt::float2 Size() const
    {
        return _size;
    }

    [[nodiscard]] std::chrono::milliseconds Duration() const
    {
        return { c_durationTicks };
    }

    void Close()
    {
        if (_root)
        {
            _root.Close();
        }
    }
};

ProgressRingLoading::ProgressRingLoading(double strokeThickness, winrt::Size size, winrt::Color foreground, winrt::Color background)
    : m_strokeThickness(strokeThickness),
    m_size(size),
    m_foreground(foreground),
    m_background(background)
{

}

winrt::IAnimatedVisual ProgressRingLoading::TryCreateAnimatedVisual(
    const winrt::Compositor& compositor,
    winrt::IInspectable& diagnostics)
{
    diagnostics = nullptr;
    if (!IsRuntimeCompatible())
    {
        return nullptr;
    }
    return winrt::make<ProgressRingAnimatedVisual>(compositor, m_strokeThickness, m_size, m_foreground, m_background);
}
