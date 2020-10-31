/*
  ==============================================================================

    blueprint_View.cpp
    Created: 26 Nov 2018 3:38:37am

  ==============================================================================
*/


namespace blueprint
{

    AlertView::AlertView()
        : juce::AlertWindow(
                juce::String(TRANS("License Activation")),
                TRANS("Enter License Key"),
                AlertWindow::AlertIconType::NoIcon
                )
    {
        juce::AlertWindow::setVisible (true);
        juce::AlertWindow::setColour(ColourIds::backgroundColourId, juce::Colour::fromString("ff000000"));
    }
    void AlertView::mouseDown(const juce::MouseEvent &e)
    {
        DBG("mouseDown");
        juce::AlertWindow::mouseDown(e);
    }
    void AlertView::addChild (View* childView, int /*index*/)
    {
        addCustomComponent(childView);
    }
}
