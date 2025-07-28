#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame {
    public:
        MainFrame(const wxString& title);

    private:
        void CreateControls();
        void BindEventHandlers();
        void OnAbout(wxCommandEvent& event);

        void OnClear(wxCommandEvent& event);
        void OnDelete(wxCommandEvent& event);
        void OnButton1(wxCommandEvent& event);
        void OnButton2(wxCommandEvent& event);
        void OnButton3(wxCommandEvent& event);
        void OnButton4(wxCommandEvent& event);
        void OnButton5(wxCommandEvent& event);
        void OnButton6(wxCommandEvent& event);
        void OnButton7(wxCommandEvent& event);
        void OnButton8(wxCommandEvent& event);
        void OnButton9(wxCommandEvent& event);
        void OnButton0(wxCommandEvent& event);
        void OnButtonAdd(wxCommandEvent& event);
        void OnButtonSubtract(wxCommandEvent& event);
        void OnButtonDivide(wxCommandEvent& event);
        void OnButtonMultiply(wxCommandEvent& event);
        void OnButtonEquals(wxCommandEvent& event);
        void OnButtonLeftB(wxCommandEvent& event);
        void OnButtonRightB(wxCommandEvent& event);
        void OnButtonDot(wxCommandEvent& event);
        void OnEnterPressed(wxCommandEvent& event);
        void OnDeleteKey(wxKeyEvent& event);



        wxMenu *menu;
        wxMenuBar *menuBar;


        wxPanel* panel;
        wxTextCtrl* inputField;


        //BUTTON START
        wxButton* buttonClear;
        wxButton* buttonDelete;
        wxButton* buttonDot;
        wxButton* button0;
        wxButton* button1;
        wxButton* button2;
        wxButton* button3;
        wxButton* button4;
        wxButton* button5;
        wxButton* button6;
        wxButton* button7;
        wxButton* button8;
        wxButton* button9;
        wxButton* buttonAdd;
        wxButton* buttonSubtract;
        wxButton* buttonMultiply;
        wxButton* buttonDivide;
        wxButton* buttonEquals;
        wxButton* buttonLeftB;
        wxButton* buttonRightB;
        //BUTTON END
};

