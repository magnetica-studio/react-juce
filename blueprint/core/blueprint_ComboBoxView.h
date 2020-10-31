/*
  ==============================================================================

    blueprint_ComboBox.h

  ==============================================================================
*/

#pragma once

#include "blueprint_View.h"


namespace blueprint
{

    //==============================================================================
    /** The ImageView class is a core view for drawing images within Blueprint's
        layout system.
     */
    class ComboBoxView : public View
    {
    public:
        //==============================================================================
        ComboBoxView()
            : View()
        {
            addAndMakeVisible(comboBox, 1);
            comboBox.addItem("Plain",  1);
            comboBox.addItem("Bold",   2);
            comboBox.addItem("Italic", 3);
            comboBox.setSelectedId(1);
            comboBox.setLookAndFeel(&lookAndFeel);
        }

        void setProperty(const juce::Identifier &name, const juce::var &value) override
        {
            if (name == juce::StringRef("background-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::backgroundColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::textColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("arrow-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::arrowColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("button-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::buttonColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("focused-outline-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::focusedOutlineColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("outline-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::outlineColourId,
                        juce::Colour::fromString(value.toString())
                );
            if (name == juce::StringRef("popup-color"))
            {
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::backgroundColourId,
                        juce::Colour::fromString(value.toString()));
            }
            if (name == juce::StringRef("highlight-color"))
            {
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::highlightedBackgroundColourId,
                        juce::Colour::fromString(value.toString()));
            }
            if (name == juce::StringRef("highlight-background-color"))
            {
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::highlightedTextColourId,
                        juce::Colour::fromString(value.toString()));
            }

            View::setProperty(name, value);
        }

        void resized() override
        {
            comboBox.setBounds(0, 0, getWidth() , getHeight());
            View::resized();
        }
    private:
        //==============================================================================
        juce::ComboBox comboBox;
        juce::LookAndFeel_V4 lookAndFeel;
        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxView)
    };

}
