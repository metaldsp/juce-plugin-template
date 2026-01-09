//======================================================================================
// Copyright (c) 2026 Pier Luigi Fiorini
// All rights reserved.
//======================================================================================

#pragma once

#include "PluginProcessor.h"

namespace AudioPlugin {

class PluginEditor : public juce::AudioProcessorEditor
{
public:
    explicit PluginEditor(PluginProcessor &);
    ~PluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    PluginProcessor &processorRef;
    juce::Label m_gainLabel;
    juce::Slider m_gainSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_gainAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};

} // namespace AudioPlugin
