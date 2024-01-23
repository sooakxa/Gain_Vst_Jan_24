/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTutorialAudioProcessorEditor::GainTutorialAudioProcessorEditor (GainTutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-60.0f, 1.0f, 0.01f);
    mGainSlider.setValue(0.50f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    
    setSize (200, 300);
}

GainTutorialAudioProcessorEditor::~GainTutorialAudioProcessorEditor()
{
}

//==============================================================================
void GainTutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void GainTutorialAudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth() / 2 - 50, getHeight() /2 - 75, 100, 150);
}

void GainTutorialAudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
