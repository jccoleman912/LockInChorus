/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LockInChorusAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener,
public juce::Button::Listener
{
public:
    LockInChorusAudioProcessorEditor (LockInChorusAudioProcessor&);
    ~LockInChorusAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider *slider) override;
    void buttonClicked (juce::Button *button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LockInChorusAudioProcessor& audioProcessor;
    
    
    juce::Slider rateSlider;
    juce::Slider depthSlider;
    juce::Slider makeUpGainSlider;
    juce::Slider mixSlider;
    juce::Slider offsetSlider;
    
    juce::Label rateLabel;
    juce::Label depthLabel;
    juce::Label makeUpGainLabel;
    juce::Label mixLabel;
    juce::Label offsetLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LockInChorusAudioProcessorEditor)
};
