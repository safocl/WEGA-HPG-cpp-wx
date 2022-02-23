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

}   // namespace ui
