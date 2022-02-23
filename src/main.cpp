#include "ui/mainwindow.hpp"

#include <iostream>
#include <wx/chartype.h>
#include <wx/init.h>
#include <wx/wx.h>

#include <cstdlib>

class HpgApp final : public wxApp {
    bool OnInit() override {
        ui::MainWindow * mainwindow = new ui::MainWindow;
        mainwindow->CreateStatusBar();
        mainwindow->SetStatusText( "HPG status" );
        mainwindow->Show();

        //std::cout << "TEST" << std::endl;

        //SetTopWindow( mainwindow );
        return true;
    }
    //MainWindow mainwindow;
};
//DECLARE_APP( HpgApp )
//IMPLEMENT_APP( HpgApp )
int main( int argc, char ** argv ) {
    [[maybe_unused]] HpgApp * app = new HpgApp;

    wxEntry( argc, argv );
    return EXIT_SUCCESS;
}
