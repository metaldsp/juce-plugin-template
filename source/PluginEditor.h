//======================================================================================
// Copyright (c) 2025 Pier Luigi Fiorini
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
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor &processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};

} // namespace AudioPlugin
