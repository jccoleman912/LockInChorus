/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LockInChorusAudioProcessorEditor::LockInChorusAudioProcessorEditor (LockInChorusAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 500);
    
    /*
     Elements associated with the "Rate" parameter. The unit for this input is Hz
     */
    rateSlider.setBounds(400,100,150,150);
    rateSlider.setName("Rate");
    rateSlider.setDescription("RATE");
    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    rateSlider.setRange(0.01f, 20.f, 0.01f); // (min, max, interval)
    rateSlider.setValue(35.f); // initial value
    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rateSlider.addListener(this);
    rateSlider.setTextValueSuffix(" HZ");
    addAndMakeVisible(rateSlider);

    rateLabel.setText("Rate", juce::dontSendNotification);
    rateLabel.attachToComponent(&rateSlider, false);
    rateLabel.setJustificationType(juce::Justification::centredTop);
    rateLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(rateLabel);
    
    
    /*
     Elements associated with the "Depth" parameter. The unit for this input is ms
     */
    depthSlider.setBounds(50,100,150,150);
    depthSlider.setName("Depth");
    depthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    depthSlider.setRange(0.f, 15.f, 0.01f); // (min, max, interval)
    depthSlider.setValue(35.f); // initial value
    depthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    depthSlider.addListener(this);
    depthSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(depthSlider);

    depthLabel.setText("Depth", juce::dontSendNotification);
    depthLabel.attachToComponent(&depthSlider, false);
    depthLabel.setJustificationType(juce::Justification::centredTop);
    depthLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(depthLabel);
    
    
    /*
     Elements associated with the "Make-Up Gain" parameter. The unit for this input is dB
     */
    makeUpGainSlider.setBounds(400,300,150,150);
    makeUpGainSlider.setName("Gain");
    makeUpGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    makeUpGainSlider.setRange(-24.f, 24.f, 0.1f); // (min, max, interval)
    makeUpGainSlider.setValue(35.f); // initial value
    makeUpGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    makeUpGainSlider.addListener(this);
    makeUpGainSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(makeUpGainSlider);

    makeUpGainLabel.setText("Gain", juce::dontSendNotification);
    makeUpGainLabel.attachToComponent(&makeUpGainSlider, false);
    makeUpGainLabel.setJustificationType(juce::Justification::centredTop);
    makeUpGainLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(makeUpGainLabel);
    
    
    /*
     Elements associated with the "Mix" parameter
     */
    mixSlider.setBounds(50,300,150,150);
    mixSlider.setName("Mix");
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    mixSlider.setRange(0.f, 100.f, 0.1f); // (min, max, interval)
    mixSlider.setValue(35.f); // initial value
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixSlider.addListener(this);
    mixSlider.setTextValueSuffix("%");
    addAndMakeVisible(mixSlider);

    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    mixLabel.setJustificationType(juce::Justification::centredTop);
    mixLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(mixLabel);
    
    /*
     Elements associated with the "Offset" parameter
     */
    offsetSlider.setBounds(225,30,150,150);
    offsetSlider.setName("Mix");
    offsetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    offsetSlider.setRange(15.f, 50.f, 0.1f); // (min, max, interval)
    offsetSlider.setValue(35.f); // initial value
    offsetSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    offsetSlider.addListener(this);
    offsetSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(offsetSlider);

    offsetLabel.setText("Offset", juce::dontSendNotification);
    offsetLabel.attachToComponent(&offsetSlider, false);
    offsetLabel.setJustificationType(juce::Justification::centredTop);
    offsetLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(offsetLabel);
}

LockInChorusAudioProcessorEditor::~LockInChorusAudioProcessorEditor()
{
}

//==============================================================================
void LockInChorusAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void LockInChorusAudioProcessorEditor::resized()
{
//    rateSlider.setBounds(400,200,100,100);
//    rateSlider.setName("Rate");
//    rateSlider.setDescription("RATE");
//    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 100);
//    rateSlider.setRange(20.f, 50.f, 0.1f); // (min, max, interval)
//    rateSlider.setValue(35.f); // initial value
//    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
//    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 0, 0);
//    rateSlider.addListener(this);
//    addAndMakeVisible(rateSlider);
}

void LockInChorusAudioProcessorEditor::buttonClicked (juce::Button *button) {};

void LockInChorusAudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{ }
