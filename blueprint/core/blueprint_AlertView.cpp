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
//        juce::AlertWindow::centreWithSize (300, 200);
        juce::AlertWindow::setVisible (true);

    }
    void AlertView::mouseDown(const juce::MouseEvent &e) {
        DBG("mouseDown");
        juce::AlertWindow::mouseDown(e);
    }
}
