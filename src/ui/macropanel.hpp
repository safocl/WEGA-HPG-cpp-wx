#include <wx/radiobox.h>
#include <wx/colour.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/window.h>
#include <wx/panel.h>
#include <wx/wx.h>

namespace ui {

using BoxType = wxStaticBoxSizer;

const wxColour darkGreen( 30, 60, 20 );

class Macroprofile : public BoxType {
public:
    struct Elements final {
        wxSpinCtrlDouble * spinNitrogen;
        wxSpinCtrlDouble * spinNo3;
        wxSpinCtrlDouble * spinNh4;
        wxSpinCtrlDouble * spinPhosphor;
        wxSpinCtrlDouble * spinKalium;
        wxSpinCtrlDouble * spinCalcium;
        wxSpinCtrlDouble * spinMagnesium;
        wxSpinCtrlDouble * spinSulfur;
        wxSpinCtrlDouble * spinChlorum;
        wxSpinCtrlDouble * spinEc;
        wxSpinCtrlDouble * spinNh4no3;

        wxStaticText * textNh4no3Ratio;
        wxStaticText * textElementRatio;
        wxStaticText * textSPPM;
        wxStaticText * textNpk;
        wxStaticText * textCaoPercentage;
        wxStaticText * textMgoPercentage;
        wxStaticText * textSo3Percentage;
    };

public:
    Macroprofile( wxWindow * parent );
    virtual ~Macroprofile() = default;

private:
    void customize();

private:
    Elements mElements;
};

class ElementsRatio : public BoxType {
public:
    struct Elements final {
        wxSpinCtrlDouble * spinPToN;
        wxSpinCtrlDouble * spinKToN;
        wxSpinCtrlDouble * spinCaToN;
        wxSpinCtrlDouble * spinMgToN;
        wxSpinCtrlDouble * spinSToN;
        wxSpinCtrlDouble * spinNToP;
        wxSpinCtrlDouble * spinKToP;
        wxSpinCtrlDouble * spinCaToP;
        wxSpinCtrlDouble * spinMgToP;
        wxSpinCtrlDouble * spinSToP;
        wxSpinCtrlDouble * spinNToK;
        wxSpinCtrlDouble * spinPToK;
        wxSpinCtrlDouble * spinCaToK;
        wxSpinCtrlDouble * spinMgToK;
        wxSpinCtrlDouble * spinSToK;
        wxSpinCtrlDouble * spinNToCa;
        wxSpinCtrlDouble * spinPToCa;
        wxSpinCtrlDouble * spinKToCa;
        wxSpinCtrlDouble * spinMgToCa;
        wxSpinCtrlDouble * spinSToCa;
        wxSpinCtrlDouble * spinNToMg;
        wxSpinCtrlDouble * spinPToMg;
        wxSpinCtrlDouble * spinKToMg;
        wxSpinCtrlDouble * spinCaToMg;
        wxSpinCtrlDouble * spinSToMg;
        wxSpinCtrlDouble * spinNToS;
        wxSpinCtrlDouble * spinPToS;
        wxSpinCtrlDouble * spinKToS;
        wxSpinCtrlDouble * spinMgToS;
        wxSpinCtrlDouble * spinCaToS;
    };

public:
    ElementsRatio( wxWindow * parent );
    virtual ~ElementsRatio() = default;

private:
    void customize();

private:
    Elements mElements;
};

class SaltCompositions : public BoxType {
public:
    struct Elements final {
        struct Salt final {
            wxSpinCtrlDouble * spinCationPercent;
            wxSpinCtrlDouble * spinPrimaryAnionPercent;
            wxSpinCtrlDouble * spinWeight;

            wxStaticText * textName;
        };

        struct SaltCaNo3 final {
            wxSpinCtrlDouble * spinCationPercent;
            wxSpinCtrlDouble * spinPrimaryAnionPercent;
            wxSpinCtrlDouble * spinSecondaryAnionPercent;
            wxSpinCtrlDouble * spinWeight;

            wxStaticText * textName;
        };

        SaltCaNo3 CaNO3;
        Salt KNO3;
        Salt NH4NO3;
        Salt MgNO3;
        Salt MgSO4;
        Salt K2SO4;
        Salt KH2PO4;
        Salt CaCl2;

        wxRadioBox * radioKSoVsMgNo;
    };

public:
    SaltCompositions( wxWindow * parent );
    virtual ~SaltCompositions() = default;

private:
    void customize();

private:
    Elements mElements;
};

class MacroPanel : public wxPanel {
public:
    MacroPanel( wxWindow * parent );
    virtual ~MacroPanel() = default;
};
}   // namespace ui
