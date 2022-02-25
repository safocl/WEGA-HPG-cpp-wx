#include "constants.hpp"

#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/colour.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/window.h>
#include <wx/panel.h>
#include <wx/wx.h>

namespace ui {

using BoxType = wxStaticBoxSizer;

class MicroProfile : public BoxType {
public:
    struct Elements final {
        wxSpinCtrlDouble * spinFe;
        wxSpinCtrlDouble * spinMn;
        wxSpinCtrlDouble * spinB;
        wxSpinCtrlDouble * spinZn;
        wxSpinCtrlDouble * spinCu;
        wxSpinCtrlDouble * spinMo;
        wxSpinCtrlDouble * spinCo;
        wxSpinCtrlDouble * spinSi;
    };

public:
    MicroProfile( wxWindow * parent );
    virtual ~MicroProfile() = default;

private:
    void customize();

private:
    Elements mElements;
};

class MicroCompositions : public BoxType {
public:
    struct Elements final {
        struct Salt final {
            wxSpinCtrlDouble * spinPercent;
            wxSpinCtrlDouble * spinWeight;
        };

        struct BorComplex final {
            wxCheckBox *       checkboxIsBorComplex;
            wxSpinCtrlDouble * spinWeight;
            wxTextCtrl *       textComposition;
            wxSpinCtrlDouble * spinVolume;
            wxTextCtrl *       textVolumeParametres;
        };

        Salt Fe;
        Salt Mn;
        Salt B;
        Salt Zn;
        Salt Cu;
        Salt Mo;
        Salt Co;
        Salt Si;

        BorComplex borComplexElement;
    };

public:
    MicroCompositions( wxWindow * parent );
    virtual ~MicroCompositions() = default;

private:
    void customize();

private:
    Elements mElements;
};

}   // namespace ui
