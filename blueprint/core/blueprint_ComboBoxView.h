/*
  ==============================================================================

    blueprint_ComboBox.h

  ==============================================================================
*/

#pragma once

#include "blueprint_View.h"


namespace blueprint {

    //==============================================================================
    /** The ImageView class is a core view for drawing images within Blueprint's
        layout system.
     */
    class ComboBoxView : public View {
    public:
        //==============================================================================
        ComboBoxView()
                : View() {
            addAndMakeVisible(comboBox, 1);
            comboBox.setLookAndFeel(&lookAndFeel);
        }

//        void setProperty(const juce::Identifier &name, const juce::var &value) override {
//        }

        void paint(juce::Graphics &g) override {
            View::paint(g);
            if (props.contains("options")) {
                // addOption to comboBox
                auto options = props["options"].getArray();
                for(auto& option : *options) {
                    auto value = option.getDynamicObject()->getProperty("value");
                    auto label = option.getDynamicObject()->getProperty("label");
                    auto id = static_cast<int>(value);
                    addOption(id, label.toString());
                }
            }

            if (props.contains("onValueChange") && props["onValueChange"].isMethod()) {
                comboBox.onChange = [&] {
                    std::vector<juce::var> jsArgs{{comboBox.getSelectedId()}};
                    juce::var::NativeFunctionArgs nfArgs(juce::var(), jsArgs.data(), static_cast<int>(jsArgs.size()));
                    std::invoke(props["onValueChange"].getNativeFunction(), nfArgs);
                };
            }
            if (props.contains("background-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::backgroundColourId,
                        juce::Colour::fromString(props["background-color"].toString())
                );
            if (props.contains("color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::textColourId,
                        juce::Colour::fromString(props["color"].toString())
                );
            if (props.contains("arrow-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::arrowColourId,
                        juce::Colour::fromString(props["arrow-color"].toString())
                );
            if (props.contains("button-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::buttonColourId,
                        juce::Colour::fromString(props["button-color"].toString())
                );
            if (props.contains("focused-outline-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::focusedOutlineColourId,
                        juce::Colour::fromString(props["focused-outline-color"].toString())
                );
            if (props.contains("outline-color"))
                comboBox.setColour(
                        juce::ComboBox::ColourIds::outlineColourId,
                        juce::Colour::fromString(props["outline-color"].toString())
                );
            if (props.contains("popup-color"))
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::backgroundColourId,
                        juce::Colour::fromString(props["popup-color"].toString()));

            if (props.contains("highlight-color"))
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::highlightedBackgroundColourId,
                        juce::Colour::fromString(props["highlight-color"].toString()));

            if (props.contains("highlight-background-color"))
                lookAndFeel.setColour(
                        juce::PopupMenu::ColourIds::highlightedTextColourId,
                        juce::Colour::fromString(props["highlight-background-color"].toString()));
        }

        void addOption(const int id, const juce::String& label ) {
            // skip addItem() if comboBox already has the same id
            for (int idx = 0; idx < comboBox.getNumItems(); idx++) {
                if (id == comboBox.getItemId(idx)) return;
            }
            comboBox.addItem(label, id);
        }

        void resized() override {
            comboBox.setBounds(0, 0, getWidth(), getHeight());
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
