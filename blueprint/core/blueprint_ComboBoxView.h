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
        }
        void resized() override
        {
            comboBox.setBounds(0, 0, getWidth() , getHeight());
            View::resized();
        }
    private:
        //==============================================================================
        juce::ComboBox comboBox;

        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxView)
    };

}
