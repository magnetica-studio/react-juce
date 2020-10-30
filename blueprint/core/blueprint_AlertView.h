/*
  ==============================================================================

    blueprint_View.h
    Created: 26 Nov 2018 3:38:37am

  ==============================================================================
*/

#pragma once

#include <map>


namespace blueprint
{

    // Internally we use a juce::Uuid for uniquely identifying views, but we
    // need that same identifier to make a transit through JavaScript land
    // and still match afterwards. So we map our Uuids into a signed 32-bit integer
    // type and leave Duktape to perform the appropriate cast through JavaScript's
    // double-width "Number" type.
    typedef juce::int32 ViewId;

    //==============================================================================
    /** The View class is the core component abstraction for Blueprint's declarative
        flex-based component composition.
     */
    class AlertView :
            public View,
            public juce::AlertWindow
    {
    public:
        //==============================================================================
        AlertView();
        ~AlertView() override = default;

    protected:
        void mouseDown(const juce::MouseEvent &e) override;

        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlertView)
    };

}
