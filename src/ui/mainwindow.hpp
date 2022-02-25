#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/notebook.h>

#include <vector>

namespace ui {

class MainWindow : public wxFrame {
public:
    MainWindow();

    ~MainWindow() = default;

private:
    wxNotebook * mTabs;

    std::vector< wxPanel * > mPanels;
};

template < class... Elements > class PlacePanel : public wxPanel {
public:
    PlacePanel( wxWindow * parent ) : wxPanel( parent ) {
        auto gridSizer = new wxFlexGridSizer( 1 );
        //auto gridSizer = new wxBoxSizer( wxVERTICAL );

        gridSizer->SetFlexibleDirection( wxVERTICAL );
        gridSizer->SetNonFlexibleGrowMode(
        wxFlexSizerGrowMode::wxFLEX_GROWMODE_ALL );
        gridSizer->SetVGap( 9 );
        gridSizer->SetHGap( 9 );

        wxSizerFlags defaultFlags( 0 );
        defaultFlags.Expand();

        ( gridSizer->Add( ( new Elements( this ) ), defaultFlags ), ... );

        SetSizerAndFit( gridSizer );
    }

    virtual ~PlacePanel() = default;
};
}   // namespace ui
