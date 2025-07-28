#include "calculator.h"
#include "MainFrame.h"


wxIMPLEMENT_APP(calculator);

bool calculator::OnInit() {

    MainFrame* mainFrame = new MainFrame("Another Calculator");
    mainFrame->SetClientSize(450, 500);
    mainFrame->SetBackgroundColour(*wxCYAN);
    mainFrame->Center();
    mainFrame->Show(true);

    return true;
}

