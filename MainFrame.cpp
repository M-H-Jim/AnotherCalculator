#include "MainFrame.h"
#include "ExpressionParser.h"

#include <wx/wx.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

enum {

    ID_Input = 11,
    ID_Clear = 12,
    ID_Delete = 13,
    ID_Dot = 14,


    ID_Button1 = 101,
    ID_Button2 = 102,
    ID_Button3 = 103,
    ID_Button4 = 104,
    ID_Button5 = 105,
    ID_Button6 = 106,
    ID_Button7 = 107,
    ID_Button8 = 108,
    ID_Button9 = 109,
    ID_Button0 = 100,

    ID_Add = 201,
    ID_Subtract = 202,
    ID_Multiply = 203,
    ID_Divide = 204,
    ID_Equals = 205,

    ID_LeftB = 206,
    ID_RightB = 207

};


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition,
                                                      wxDefaultSize, wxDEFAULT_FRAME_STYLE &
                                                      ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
   SetIcon(wxIcon("AnotherCalculator.ico", wxBITMAP_TYPE_ICO));


    CreateControls();
    BindEventHandlers();
}

void MainFrame::CreateControls() {

    //MENU START
    menu = new wxMenu;
    menu->Append(wxID_ABOUT);

    menuBar = new wxMenuBar;
    menuBar->Append(menu, "About");

    SetMenuBar(menuBar);
    //MENU END


    wxFont inputFont(wxFontInfo(wxSize(0, 24)));
    wxFont buttonFont(wxFontInfo(wxSize(0, 36)));

    panel = new wxPanel(this);

    inputField = new wxTextCtrl(panel, ID_Input, "", wxPoint(25, 25), wxSize(400, 40),
                                wxTE_PROCESS_ENTER);
    inputField->SetFont(inputFont);
    inputField->SetBackgroundColour(*wxCYAN);

    buttonClear = new wxButton(panel, ID_Clear, "Clear", wxPoint(25, 65), wxSize(100, 35));
    buttonClear->SetBackgroundColour(*wxCYAN);
    buttonDelete = new wxButton(panel, ID_Delete, "Delete", wxPoint(325, 65), wxSize(100, 35));
    buttonDelete->SetBackgroundColour(*wxCYAN);

    buttonAdd = new wxButton(panel, ID_Add, '+', wxPoint(25, 100), wxSize(100, 100));
    buttonAdd->SetBackgroundColour(*wxCYAN);
    buttonSubtract = new wxButton(panel, ID_Subtract, '-', wxPoint(125, 100), wxSize(100, 100));
    buttonSubtract->SetBackgroundColour(*wxCYAN);
    buttonMultiply = new wxButton(panel, ID_Multiply, '*', wxPoint(225, 100), wxSize(100, 100));
    buttonMultiply->SetBackgroundColour(*wxCYAN);
    buttonDivide = new wxButton(panel, ID_Divide, '/', wxPoint(325, 100), wxSize(100, 100));
    buttonDivide->SetBackgroundColour(*wxCYAN);
    buttonEquals = new wxButton(panel, ID_Equals, '=', wxPoint(325, 200), wxSize(100, 100));
    buttonEquals->SetBackgroundColour(*wxCYAN);


    button1 = new wxButton(panel, ID_Button1, '1', wxPoint(25, 200), wxSize(100, 100));
    button1->SetBackgroundColour(*wxCYAN);
    button2 = new wxButton(panel, ID_Button2, '2', wxPoint(125, 200), wxSize(100, 100));
    button2->SetBackgroundColour(*wxCYAN);
    button3 = new wxButton(panel, ID_Button3, '3', wxPoint(225, 200), wxSize(100, 100));
    button3->SetBackgroundColour(*wxCYAN);

    button4 = new wxButton(panel, ID_Button4, '4', wxPoint(25, 300), wxSize(100, 100));
    button4->SetBackgroundColour(*wxCYAN);
    button5 = new wxButton(panel, ID_Button5, '5', wxPoint(125, 300), wxSize(100, 100));
    button5->SetBackgroundColour(*wxCYAN);
    button6 = new wxButton(panel, ID_Button6, '6', wxPoint(225, 300), wxSize(100, 100));
    button6->SetBackgroundColour(*wxCYAN);

    button7 = new wxButton(panel, ID_Button7, '7', wxPoint(25, 400), wxSize(100, 100));
    button7->SetBackgroundColour(*wxCYAN);
    button8 = new wxButton(panel, ID_Button8, '8', wxPoint(125, 400), wxSize(100, 100));
    button8->SetBackgroundColour(*wxCYAN);
    button9 = new wxButton(panel, ID_Button9, '9', wxPoint(225, 400), wxSize(100, 100));
    button9->SetBackgroundColour(*wxCYAN);

    button0 = new wxButton(panel, ID_Button0, '0', wxPoint(325, 400), wxSize(100, 100));
    button0->SetBackgroundColour(*wxCYAN);
    buttonDot = new wxButton(panel, ID_Dot, ".(dot)", wxPoint(225, 65), wxSize(100, 35));
    buttonDot->SetBackgroundColour(*wxCYAN);

    buttonLeftB = new wxButton(panel, ID_LeftB, '(', wxPoint(325, 300), wxSize(50, 100));
    buttonLeftB->SetBackgroundColour(*wxCYAN);
    buttonRightB = new wxButton(panel, ID_RightB, ')', wxPoint(375, 300), wxSize(50, 100));
    buttonRightB->SetBackgroundColour(*wxCYAN);

    button1->SetFont(buttonFont);
    button2->SetFont(buttonFont);
    button3->SetFont(buttonFont);
    button4->SetFont(buttonFont);
    button5->SetFont(buttonFont);
    button6->SetFont(buttonFont);
    button7->SetFont(buttonFont);
    button8->SetFont(buttonFont);
    button9->SetFont(buttonFont);
    button0->SetFont(buttonFont);
    buttonAdd->SetFont(buttonFont);
    buttonSubtract->SetFont(buttonFont);
    buttonMultiply->SetFont(buttonFont);
    buttonDivide->SetFont(buttonFont);
    buttonEquals->SetFont(buttonFont);
    buttonLeftB->SetFont(buttonFont);
    buttonRightB->SetFont(buttonFont);

    CreateStatusBar();
    SetStatusText("Hi");
}


void MainFrame::BindEventHandlers() {

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

    buttonClear->Bind(wxEVT_BUTTON, &MainFrame::OnClear, this);
    buttonDelete->Bind(wxEVT_BUTTON, &MainFrame::OnDelete, this);

    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2, this);
    button3->Bind(wxEVT_BUTTON, &MainFrame::OnButton3, this);
    button4->Bind(wxEVT_BUTTON, &MainFrame::OnButton4, this);
    button5->Bind(wxEVT_BUTTON, &MainFrame::OnButton5, this);
    button6->Bind(wxEVT_BUTTON, &MainFrame::OnButton6, this);
    button7->Bind(wxEVT_BUTTON, &MainFrame::OnButton7, this);
    button8->Bind(wxEVT_BUTTON, &MainFrame::OnButton8, this);
    button9->Bind(wxEVT_BUTTON, &MainFrame::OnButton9, this);
    button0->Bind(wxEVT_BUTTON, &MainFrame::OnButton0, this);
    buttonDot->Bind(wxEVT_BUTTON, &MainFrame::OnButtonDot, this);

    buttonAdd->Bind(wxEVT_BUTTON, &MainFrame::OnButtonAdd, this);
    buttonSubtract->Bind(wxEVT_BUTTON, &MainFrame::OnButtonSubtract, this);
    buttonMultiply->Bind(wxEVT_BUTTON, &MainFrame::OnButtonMultiply, this);
    buttonDivide->Bind(wxEVT_BUTTON, &MainFrame::OnButtonDivide, this);
    buttonEquals->Bind(wxEVT_BUTTON, &MainFrame::OnButtonEquals, this);
    buttonLeftB->Bind(wxEVT_BUTTON, &MainFrame::OnButtonLeftB, this);
    buttonRightB->Bind(wxEVT_BUTTON, &MainFrame::OnButtonRightB, this);

    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnEnterPressed, this);
    inputField->Bind(wxEVT_KEY_DOWN, &MainFrame::OnDeleteKey, this);

}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("'Another Calculator'\n"
        "----------------------\n"
        "Developed by M.H. Jim\n\n"
        "Built with C++ and wxWidgets.\n"
        "Supports basic arithmetic with expression parsing.\n\n"
        ,"About this app",
                  wxOK | wxICON_INFORMATION);
}

void MainFrame::OnClear(wxCommandEvent& event) {
    inputField->Clear();
    inputField->SetFocus();
}

void MainFrame::OnDelete(wxCommandEvent& event) {
    wxString currentExpression = inputField->GetValue();
    long pos = inputField->GetInsertionPoint();
    if(!currentExpression.IsEmpty() && pos > 0) {
        currentExpression.Remove(pos - 1, 1);
        inputField->SetValue(currentExpression);
        inputField->SetInsertionPoint(pos - 1);
        inputField->SetFocus();
    }
}

void MainFrame::OnButton1(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("1");
    inputField->SetFocus();
    wxLogStatus("1");
}
void MainFrame::OnButton2(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("2");
    inputField->SetFocus();
    wxLogStatus("2");
}
void MainFrame::OnButton3(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("3");
    inputField->SetFocus();
    wxLogStatus("3");
}
void MainFrame::OnButton4(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("4");
    inputField->SetFocus();
    wxLogStatus("4");
}
void MainFrame::OnButton5(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("5");
    inputField->SetFocus();
    wxLogStatus("5");
}
void MainFrame::OnButton6(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("6");
    inputField->SetFocus();
    wxLogStatus("6");
}
void MainFrame::OnButton7(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("7");
    inputField->SetFocus();
    wxLogStatus("7");
}
void MainFrame::OnButton8(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("8");
    inputField->SetFocus();
    wxLogStatus("8");
}
void MainFrame::OnButton9(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("9");
    inputField->SetFocus();
    wxLogStatus("9");
}
void MainFrame::OnButton0(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("0");
    inputField->SetFocus();
    wxLogStatus("0");
}

void MainFrame::OnButtonDot(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText(".");
    inputField->SetFocus();
    wxLogStatus(".");
}



void MainFrame::OnButtonAdd(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("+");
    inputField->SetFocus();
    wxLogStatus("+");
}
void MainFrame::OnButtonSubtract(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("-");
    inputField->SetFocus();
    wxLogStatus("-");
}
void MainFrame::OnButtonMultiply(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("*");
    inputField->SetFocus();
    wxLogStatus("*");
}
void MainFrame::OnButtonDivide(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("/");
    inputField->SetFocus();
    wxLogStatus("/");
}
void MainFrame::OnButtonLeftB(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText("(");
    inputField->SetFocus();
    wxLogStatus("(");
}
void MainFrame::OnButtonRightB(wxCommandEvent& event) {
    long pos = inputField->GetInsertionPoint();
    inputField->SetInsertionPoint(pos);
    inputField->WriteText(")");
    inputField->SetFocus();
    wxLogStatus(")");
}


void MainFrame::OnButtonEquals(wxCommandEvent& event) {

    wxString wxStr = inputField->GetValue();
    wxLogStatus(wxStr);
    string express = wxStr.ToStdString();

    POSTFIX_AND_CHECK receivePostfix = postfix(express);

    if(receivePostfix.chk1 != 0) {
        wxLogStatus("Error. Check your syntax.");
        inputField->SetInsertionPointEnd();
    }
    else {

        RESULT_AND_CHECK receiveResult = answer(receivePostfix.output);

        if(receiveResult.chk2 != 0) {
            wxLogStatus("Error. Check your syntax.");
            inputField->SetInsertionPointEnd();
        }
        else {
            string FINAL = to_string(receiveResult.result.top());
            wxString wxvalue(FINAL);
            inputField->SetValue(wxvalue);
        }

    }
    inputField->SetFocus();
}


void MainFrame::OnEnterPressed(wxCommandEvent& event) {

    wxString wxStr = inputField->GetValue();
    wxLogStatus(wxStr);
    string express = wxStr.ToStdString();

    POSTFIX_AND_CHECK receivePostfix = postfix(express);

    if(receivePostfix.chk1 != 0) {
        wxLogStatus("Error. Check your syntax.");
        inputField->SetInsertionPointEnd();
    }
    else {

        RESULT_AND_CHECK receiveResult = answer(receivePostfix.output);

        if(receiveResult.chk2 != 0) {
            wxLogStatus("Error. Check your syntax.");
            inputField->SetInsertionPointEnd();
        }
        else {
            string FINAL = to_string(receiveResult.result.top());
            wxString wxvalue(FINAL);
            inputField->SetValue(wxvalue);
        }

    }
    inputField->SetFocus();
}

void MainFrame::OnDeleteKey(wxKeyEvent& event) {
    if(event.GetKeyCode() == WXK_DELETE) {
        inputField->Clear();
    }
    else {
        event.Skip();
    }
}



