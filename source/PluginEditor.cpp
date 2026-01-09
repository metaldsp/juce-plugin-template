//======================================================================================
// Copyright (c) 2026 Pier Luigi Fiorini
// All rights reserved.
//======================================================================================

#include "PluginEditor.h"
#include "PluginProcessor.h"

namespace AudioPlugin {

PluginEditor::PluginEditor(PluginProcessor &p)
    : AudioProcessorEditor(&p)
    , processorRef(p)
    , m_gainLabel({}, "Gain")
    , m_gainAttachment(
          std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
              processorRef.getState(), PluginParameters::gainID, m_gainSlider))
{
    m_gainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    m_gainSlider.setTextValueSuffix(" dB");
    m_gainLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(m_gainLabel);
    addAndMakeVisible(m_gainSlider);
    setSize(400, 300);
}

PluginEditor::~PluginEditor() {}

void PluginEditor::paint(juce::Graphics &g)
{
    // (Our component is opaque, so we must completely fill the background with a
    // solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void PluginEditor::resized()
{
    auto bounds = getLocalBounds().reduced(24);
    m_gainLabel.setBounds(bounds.removeFromTop(24));
    m_gainSlider.setBounds(bounds.withSizeKeepingCentre(180, 180));
}

} // namespace AudioPlugin
