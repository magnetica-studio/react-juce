/*
  ==============================================================================

    blueprint_ComboBox.h

  ==============================================================================
*/

#pragma once

#include "blueprint_View.h"


namespace blueprint {

    class LookAndFeel_NoArrow : public juce::LookAndFeel_V4 {
    public:
        void
        drawComboBox(juce::Graphics &g, int width, int height, bool /*isButtonDown*/, int /*buttonX*/, int /*buttonY*/,
                     int /*buttonW*/,
                     int /*buttonH*/, juce::ComboBox &box) override {
            auto cornerSize = box.findParentComponentOfClass<juce::ChoicePropertyComponent>() != nullptr ? 0.0f : 3.0f;
            juce::Rectangle<int> boxBounds(0, 0, width, height);

            g.setColour(box.findColour(juce::ComboBox::backgroundColourId));
            g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);

            g.setColour(box.findColour(juce::ComboBox::outlineColourId));
            g.drawRoundedRectangle(boxBounds.toFloat().reduced(0.5f, 0.5f), cornerSize, 1.0f);
        }


    };

    //==============================================================================
    class ComboBoxView : public View {
    public:
        //==============================================================================
        ComboBoxView()
                : View() {
            addAndMakeVisible(comboBox, 1);
            comboBox.setLookAndFeel(&lookAndFeelV4);
        }

        void addOptions(const juce::Array<juce::var> &options) {
            for (int idx = 0; idx < options.size(); idx++) {
                const auto &option = options.getReference(idx);
                int id = option.getDynamicObject()->getProperty("value");
                juce::String label = option.getDynamicObject()->getProperty("label");
                addItemToComboBox(label, id);
            }

        }

        void addItemToComboBox(const juce::String &label, int id) {
            // skip comboBox.addItem() if it already has the same id
            if (comboBox.indexOfItemId(id) != -1) return;
            comboBox.addItem(label, id);
        }

        void paint(juce::Graphics &g) override {
            View::paint(g);

            if (props.contains("options")) {
                addOptions(*(props["options"].getArray()));
            }
            if (props.contains("onChange") && props["onChange"].isMethod()) {
                comboBox.onChange = [&] {
                    std::vector<juce::var> jsArgs{{comboBox.getSelectedId()}};
                    juce::var::NativeFunctionArgs nfArgs(juce::var(), jsArgs.data(), static_cast<int>(jsArgs.size()));
                    std::invoke(props["onChange"].getNativeFunction(), nfArgs);
                };
            }
            if (props.contains("value")) {
                comboBox.setSelectedId(static_cast<int>(props["value"]));
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
                setColorOfLookAndFeel(
                        juce::PopupMenu::ColourIds::backgroundColourId,
                        juce::Colour::fromString(props["popup-color"].toString()));

            if (props.contains("highlight-color"))
                setColorOfLookAndFeel(
                        juce::PopupMenu::ColourIds::highlightedBackgroundColourId,
                        juce::Colour::fromString(props["highlight-color"].toString()));

            if (props.contains("highlight-background-color"))
                setColorOfLookAndFeel(
                        juce::PopupMenu::ColourIds::highlightedTextColourId,
                        juce::Colour::fromString(props["highlight-background-color"].toString()));
            if (props.contains("no-arrow"))
                comboBox.setLookAndFeel(&lookAndFeelNoArrow);
        }

        void resized() override {
            comboBox.setBounds(0, 0, getWidth(), getHeight());
            View::resized();
        }

        void setColorOfLookAndFeel(int colorId, juce::Colour color)
        {
            lookAndFeelNoArrow.setColour(colorId, color);
            lookAndFeelV4.setColour(colorId, color);
        }

    private:
        //==============================================================================
        juce::LookAndFeel_V4 lookAndFeelV4;
        LookAndFeel_NoArrow lookAndFeelNoArrow;
        juce::ComboBox comboBox;
        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxView)
    };

}

