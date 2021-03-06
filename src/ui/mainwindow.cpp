#include "mainwindow.hpp"
#include "macropanel.hpp"
#include "micropanel.hpp"

#include <stdexcept>
#include <wx/defs.h>
#include <wx/gdicmn.h>
#include <wx/notebook.h>
#include <wx/sizer.h>

namespace ui {

MainWindow::MainWindow() :
wxFrame( nullptr, wxID_ANY, "WEGA-HPG-cpp-wx" ), mTabs( new wxNotebook() ) {
    mTabs->Create( this, wxID_ANY );

    auto mainVSizer = new wxBoxSizer( wxVERTICAL );
    mainVSizer->Add( mTabs, wxSizerFlags( 1 ).Left().Expand() );

    auto mainHSizer = new wxBoxSizer( wxHORIZONTAL );
    mainHSizer->Add( mainVSizer, wxSizerFlags( 1 ).Top().Expand() );

    mPanels.emplace_back(
    new PlacePanel< Macroprofile, ElementsRatio, SaltCompositions >( mTabs ) );
    mTabs->AddPage( mPanels.back(), "Macroprofile" );

    mPanels.emplace_back(
    new PlacePanel< MicroProfile, MicroCompositions >( mTabs ) );
    mTabs->AddPage( mPanels.back(), "Microprofile" );

    SetSizerAndFit( mainHSizer );
}

}   // namespace ui
