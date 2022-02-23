#include "macropanel.hpp"

#include <wx/arrstr.h>
#include <wx/defs.h>
#include <wx/gbsizer.h>
#include <wx/gdicmn.h>
#include <wx/colour.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/window.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>

namespace ui {

namespace {
wxSpinCtrlDouble * allocSpin( wxWindow * parent, double incrementStep = 1.0 ) {
    auto spin = new wxSpinCtrlDouble( parent, wxID_ANY, wxT( "0.0" ) );
    spin->SetIncrement( incrementStep );
    spin->SetRange( 0, 999 );
    spin->SetDigits( 3 );

    return spin;
}

wxStaticText * allocStaticText( wxWindow * parent, wxString label ) {
    auto staticText = new wxStaticText( parent, wxID_ANY, label );

    return staticText;
}
}   // namespace

Macroprofile::Macroprofile( wxWindow * parent ) : BoxType( wxHORIZONTAL, parent ) {
    GetStaticBox()->SetLabel( wxT( "Macroprofile" ) );
    //AddSpacer( 10 );

    auto grid = new wxGridBagSizer();
    grid->SetCols( 9 );
    grid->SetRows( 4 );
    grid->SetHGap( 5 );
    grid->SetVGap( 5 );

    mElements.spinNitrogen = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 1 ) )->GetWindow() );

    mElements.spinPhosphor = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 2 ) )->GetWindow() );

    mElements.spinKalium = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 3 ) )->GetWindow() );

    mElements.spinCalcium = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 4 ) )->GetWindow() );

    mElements.spinMagnesium = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 5 ) )->GetWindow() );

    mElements.spinSulfur = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 6 ) )->GetWindow() );

    mElements.spinChlorum = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 7 ) )->GetWindow() );

    mElements.spinEc = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, 8 ) )->GetWindow() );

    mElements.spinNh4 = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 2, 1 ) )->GetWindow() );

    mElements.spinNo3 = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 3, 1 ) )->GetWindow() );

    mElements.spinNh4no3 = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 3, 2 ) )->GetWindow() );

    mElements.textCaoPercentage = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "CaO=0%" ) ),
           wxGBPosition( 3, 4 ),
           wxDefaultSpan,
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textElementRatio = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "N : 0 : 0 : 0 : 0 : 0 : 0 : 0" ) ),
           wxGBPosition( 2, 4 ),
           wxGBSpan( 1, 3 ),
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textMgoPercentage = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "MgO=0%" ) ),
           wxGBPosition( 3, 5 ),
           wxDefaultSpan,
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textNh4no3Ratio = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "NH4:NO3 1:1" ) ),
           wxGBPosition( 2, 2 ),
           wxGBSpan( 1, 2 ),
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textNpk = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "NPK: 1-1-1" ) ),
           wxGBPosition( 3, 7 ),
           wxGBSpan( 1, 2 ),
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textSPPM = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "sPPM=1" ) ),
           wxGBPosition( 2, 8 ),
           wxDefaultSpan,
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    mElements.textSo3Percentage = static_cast< wxStaticText * >(
    grid
    ->Add( allocStaticText( GetStaticBox(), wxT( "SO3=0%" ) ),
           wxGBPosition( 3, 6 ),
           wxDefaultSpan,
           wxALIGN_CENTER_VERTICAL )
    ->GetWindow() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "N" ) ),
               wxGBPosition( 0, 1 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "P" ) ),
               wxGBPosition( 0, 2 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "K" ) ),
               wxGBPosition( 0, 3 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Ca" ) ),
               wxGBPosition( 0, 4 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Mg" ) ),
               wxGBPosition( 0, 5 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "S" ) ),
               wxGBPosition( 0, 6 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Cl" ) ),
               wxGBPosition( 0, 7 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "EC" ) ),
               wxGBPosition( 0, 8 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "NO3" ) ),
               wxGBPosition( 2, 0 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "NH4" ) ),
               wxGBPosition( 3, 0 ),
               wxDefaultSpan,
               wxALIGN_CENTER );

    Add( grid );

    customize();
}

void Macroprofile::customize() {
    mElements.spinEc->SetBackgroundColour( darkGreen );
    mElements.spinChlorum->SetBackgroundColour( darkGreen );
    mElements.spinPhosphor->SetBackgroundColour( darkGreen );
    mElements.spinNh4no3->SetBackgroundColour( darkGreen );

    mElements.spinEc->SetForegroundColour( *wxWHITE );
    mElements.spinChlorum->SetForegroundColour( *wxWHITE );
    mElements.spinPhosphor->SetForegroundColour( *wxWHITE );
    mElements.spinNh4no3->SetForegroundColour( *wxWHITE );

    mElements.spinEc->SetIncrement( 0.001 );
}

ElementsRatio::ElementsRatio( wxWindow * parent ) : BoxType( wxHORIZONTAL, parent ) {
    GetStaticBox()->SetLabel( wxT( "Elements ratio" ) );
    AddSpacer( 10 );

    auto grid = new wxGridBagSizer();
    grid->SetCols( 7 );
    grid->SetRows( 7 );
    grid->SetHGap( 5 );
    grid->SetVGap( 5 );

    wxSizerFlags defaultFlags( 1 );
    defaultFlags.Align( wxALIGN_CENTER );

    wxSizerFlags rightAlign( 1 );
    rightAlign.Align( wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "N" ) ),
               wxGBPosition( 0, 1 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "P" ) ),
               wxGBPosition( 0, 2 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "K" ) ),
               wxGBPosition( 0, 3 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Ca" ) ),
               wxGBPosition( 0, 4 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );
    grid->Add( allocStaticText( GetStaticBox(), wxT( "Mg" ) ),
               wxGBPosition( 0, 5 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "S" ) ),
               wxGBPosition( 0, 6 ),
               wxDefaultSpan,
               defaultFlags.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "N" ) ),
               wxGBPosition( 1, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "P" ) ),
               wxGBPosition( 2, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "K" ) ),
               wxGBPosition( 3, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Ca" ) ),
               wxGBPosition( 4, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Mg" ) ),
               wxGBPosition( 5, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "S" ) ),
               wxGBPosition( 6, 0 ),
               wxDefaultSpan,
               rightAlign.GetFlags() );

    mElements.spinPToN = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 1, 2 ) )
    ->GetWindow() );

    mElements.spinKToN = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 1, 3 ) )
    ->GetWindow() );

    mElements.spinCaToN = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 1, 4 ) )
    ->GetWindow() );

    mElements.spinMgToN = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 1, 5 ) )
    ->GetWindow() );

    mElements.spinSToN = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 1, 6 ) )
    ->GetWindow() );

    mElements.spinNToP = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 2, 1 ) )
    ->GetWindow() );

    mElements.spinKToP = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 2, 3 ) )
    ->GetWindow() );

    mElements.spinCaToP = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 2, 4 ) )
    ->GetWindow() );

    mElements.spinMgToP = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 2, 5 ) )
    ->GetWindow() );

    mElements.spinSToP = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 2, 6 ) )
    ->GetWindow() );

    mElements.spinNToK = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 3, 1 ) )
    ->GetWindow() );

    mElements.spinPToK = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 3, 2 ) )
    ->GetWindow() );

    mElements.spinCaToK = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 3, 4 ) )
    ->GetWindow() );

    mElements.spinMgToK = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 3, 5 ) )
    ->GetWindow() );

    mElements.spinSToK = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 3, 6 ) )
    ->GetWindow() );

    mElements.spinNToCa = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 4, 1 ) )
    ->GetWindow() );

    mElements.spinPToCa = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 4, 2 ) )
    ->GetWindow() );

    mElements.spinKToCa = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 4, 3 ) )
    ->GetWindow() );

    mElements.spinMgToCa = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 4, 5 ) )
    ->GetWindow() );

    mElements.spinSToCa = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 4, 6 ) )
    ->GetWindow() );

    mElements.spinNToMg = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 5, 1 ) )
    ->GetWindow() );

    mElements.spinPToMg = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 5, 2 ) )
    ->GetWindow() );

    mElements.spinKToMg = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 5, 3 ) )
    ->GetWindow() );

    mElements.spinCaToMg = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 5, 4 ) )
    ->GetWindow() );

    mElements.spinSToMg = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 5, 6 ) )
    ->GetWindow() );

    mElements.spinNToS = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 6, 1 ) )
    ->GetWindow() );

    mElements.spinPToS = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 6, 2 ) )
    ->GetWindow() );

    mElements.spinKToS = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 6, 3 ) )
    ->GetWindow() );

    mElements.spinCaToS = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 6, 4 ) )
    ->GetWindow() );

    mElements.spinMgToS = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001 ), wxGBPosition( 6, 5 ) )
    ->GetWindow() );

    Add( grid );

    customize();
}

void ElementsRatio::customize() {
    mElements.spinKToN->SetBackgroundColour( darkGreen );
    mElements.spinKToCa->SetBackgroundColour( darkGreen );
    mElements.spinKToMg->SetBackgroundColour( darkGreen );

    mElements.spinKToN->SetForegroundColour( *wxWHITE );
    mElements.spinKToCa->SetForegroundColour( *wxWHITE );
    mElements.spinKToMg->SetOwnForegroundColour( *wxWHITE );
}

namespace {

void addSaltCompositionRow( SaltCompositions::Elements::Salt & salt,
                            wxString &&                        initialNameText,
                            wxString &&                        cationText,
                            wxString &&                        anionText,
                            wxWindow *                         parent,
                            wxGridBagSizer *                   sizer,
                            wxGBPosition &&                    pos ) {
    salt.textName =
    static_cast< wxStaticText * >( sizer
                                   ->Add( allocStaticText( parent, initialNameText ),
                                          pos,
                                          wxGBSpan( 1, 1 ),
                                          wxALIGN_CENTER_VERTICAL )
                                   ->GetWindow() );

    sizer->Add( allocStaticText( parent, cationText ),
                wxGBPosition( pos.GetRow(), pos.GetCol() + 1 ),
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinCationPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 2 ) )
    ->GetWindow() );

    sizer->Add( allocStaticText( parent, anionText ),
                wxGBPosition( pos.GetRow(), pos.GetCol() + 3 ),
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinPrimaryAnionPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 4 ) )
    ->GetWindow() );

    salt.spinWeight = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 7 ) )
    ->GetWindow() );
}

void addSaltCompositionRow( SaltCompositions::Elements::SaltCaNo3 & salt,
                            wxString &&                             initialNameText,
                            wxString &&                             cationText,
                            wxString &&                             primaryAnionText,
                            wxString &&      secondaryAnionText,
                            wxWindow *       parent,
                            wxGridBagSizer * sizer,
                            wxGBPosition &&  pos ) {
    salt.textName =
    static_cast< wxStaticText * >( sizer
                                   ->Add( allocStaticText( parent, initialNameText ),
                                          pos,
                                          wxGBSpan( 1, 1 ),
                                          wxALIGN_CENTER_VERTICAL )
                                   ->GetWindow() );

    sizer->Add( allocStaticText( parent, cationText ),
                wxGBPosition( pos.GetRow(), pos.GetCol() + 1 ),
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinCationPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 2 ) )
    ->GetWindow() );

    sizer->Add( allocStaticText( parent, primaryAnionText ),
                wxGBPosition( pos.GetRow(), pos.GetCol() + 3 ),
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinPrimaryAnionPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 4 ) )
    ->GetWindow() );

    sizer->Add( allocStaticText( parent, secondaryAnionText ),
                wxGBPosition( pos.GetRow(), pos.GetCol() + 5 ),
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinSecondaryAnionPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 6 ) )
    ->GetWindow() );

    salt.spinWeight = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 7 ) )
    ->GetWindow() );
}
}   // namespace

SaltCompositions::SaltCompositions( wxWindow * parent ) :
BoxType( wxHORIZONTAL, parent ) {
    GetStaticBox()->SetLabel( wxT( "Salt compositions" ) );
    AddSpacer( 10 );

    auto grid = new wxGridBagSizer();
    grid->SetCols( 8 );
    grid->SetRows( 9 );
    grid->SetHGap( 5 );
    grid->SetVGap( 5 );

    auto textFlags = wxSizerFlags( 1 ).Center().GetFlags();

    grid->Add( allocStaticText( GetStaticBox(), wxT( "%" ) ),
               wxGBPosition( 0, 2 ),
               wxDefaultSpan,
               textFlags );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "%" ) ),
               wxGBPosition( 0, 4 ),
               wxDefaultSpan,
               textFlags );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "%" ) ),
               wxGBPosition( 0, 6 ),
               wxDefaultSpan,
               textFlags );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "grams" ) ),
               wxGBPosition( 0, 7 ),
               wxDefaultSpan,
               textFlags );

    addSaltCompositionRow( mElements.CaNO3,
                           wxT( "Ca(NO3)2*4H2O" ),
                           wxT( "Ca" ),
                           wxT( "NO3" ),
                           wxT( "NH4" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 1, 0 ) );

    addSaltCompositionRow( mElements.KNO3,
                           wxT( "KNO3" ),
                           wxT( "K" ),
                           wxT( "NO3" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 2, 0 ) );

    addSaltCompositionRow( mElements.NH4NO3,
                           wxT( "NH4NO3" ),
                           wxT( "NH4" ),
                           wxT( "NO3" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 3, 0 ) );

    addSaltCompositionRow( mElements.MgSO4,
                           wxT( "MgSO4*7H2O" ),
                           wxT( "Mg" ),
                           wxT( "S" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 4, 0 ) );

    addSaltCompositionRow( mElements.KH2PO4,
                           wxT( "KH2PO4" ),
                           wxT( "K" ),
                           wxT( "P" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 5, 0 ) );

    addSaltCompositionRow( mElements.K2SO4,
                           wxT( "K2SO4" ),
                           wxT( "K" ),
                           wxT( "S" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 6, 0 ) );

    addSaltCompositionRow( mElements.MgNO3,
                           wxT( "Mg(NO3)2*6H2O" ),
                           wxT( "Mg" ),
                           wxT( "NO3" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 7, 0 ) );

    addSaltCompositionRow( mElements.CaCl2,
                           wxT( "CaCl2*6H2O" ),
                           wxT( "Ca" ),
                           wxT( "Cl" ),
                           GetStaticBox(),
                           grid,
                           wxGBPosition( 8, 0 ) );

    wxArrayString radioStrings {};
    radioStrings.Add( wxT( "" ), 2 );

    mElements.radioKSoVsMgNo =
    static_cast< wxRadioBox * >( grid
                                 ->Add( new wxRadioBox( GetStaticBox(),
                                                        wxID_ANY,
                                                        wxT( "" ),
                                                        wxDefaultPosition,
                                                        wxDefaultSize,
                                                        radioStrings,
                                                        0,
                                                        wxRA_SPECIFY_ROWS ),
                                        wxGBPosition( 6, 6 ),
                                        wxGBSpan( 2, 1 ),
                                        wxSizerFlags( 1 ).Right().GetFlags() )
                                 ->GetWindow() );

    Add( grid );

    customize();
}

void SaltCompositions::customize() {}

}   // namespace ui
