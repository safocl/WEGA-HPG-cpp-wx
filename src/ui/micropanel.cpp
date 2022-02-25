#include "micropanel.hpp"

#include <cstdint>
#include <wx/gbsizer.h>
#include <wx/gdicmn.h>
#include <wx/colour.h>
#include <wx/gtk/textctrl.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/window.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>

namespace ui {
namespace {
wxSpinCtrlDouble * allocSpin( wxWindow *   parent,
                              double       incrementStep = 1.0,
                              unsigned int digits        = 0,
                              double       max           = 9999 ) {
    auto spin = new wxSpinCtrlDouble( parent, wxID_ANY, wxT( "0.0" ) );
    spin->SetIncrement( incrementStep );
    spin->SetRange( 0, max );
    spin->SetDigits( digits );

    return spin;
}

wxStaticText * allocStaticText( wxWindow * parent, wxString label ) {
    auto staticText = new wxStaticText( parent, wxID_ANY, label );

    return staticText;
}

[[maybe_unused]] void
addMicroCompositionRow( MicroCompositions::Elements::Salt & salt,
                        wxString &&                         nameText,
                        wxWindow *                          parent,
                        wxGridBagSizer *                    sizer,
                        wxGBPosition &&                     pos ) {
    sizer->Add( allocStaticText( parent, nameText ),
                pos,
                wxGBSpan( 1, 1 ),
                wxALIGN_CENTER_VERTICAL );

    salt.spinPercent = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.001, 4, 100 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 1 ) )
    ->GetWindow() );

    salt.spinWeight = static_cast< wxSpinCtrlDouble * >(
    sizer
    ->Add( allocSpin( parent, 0.01, 5, 99999 ),
           wxGBPosition( pos.GetRow(), pos.GetCol() + 2 ) )
    ->GetWindow() );
}

}   // namespace

MicroProfile::MicroProfile( wxWindow * parent ) : BoxType( wxHORIZONTAL, parent ) {
    GetStaticBox()->SetLabel( wxT( "Microprofile" ) );
    //AddSpacer( 10 );

    auto grid = new wxGridBagSizer();
    grid->SetCols( 8 );
    grid->SetRows( 2 );
    grid->SetHGap( 5 );
    grid->SetVGap( 5 );

    std::uint32_t colIndex { 0 };

    mElements.spinFe = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, colIndex ) )
    ->GetWindow() );

    mElements.spinMn = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinB = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinZn = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinCu = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinMo = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinCo = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    mElements.spinSi = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox() ), wxGBPosition( 1, ++colIndex ) )
    ->GetWindow() );

    colIndex = 0;
    grid->Add( allocStaticText( GetStaticBox(), wxT( "Fe" ) ),
               wxGBPosition( 0, colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Mn" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "B" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Zn" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Cu" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Mo" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Co" ) ),
               wxGBPosition( 0, ++colIndex ) );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Si" ) ),
               wxGBPosition( 0, ++colIndex ) );

    Add( grid );

    customize();
}

void MicroProfile::customize() {}

MicroCompositions::MicroCompositions( wxWindow * parent ) :
BoxType( wxHORIZONTAL, parent ) {
    GetStaticBox()->SetLabel( wxT( "Micro composition" ) );
    //AddSpacer( 10 );

    auto grid = new wxGridBagSizer();
    grid->SetCols( 4 );
    grid->SetRows( 13 );
    grid->SetHGap( 5 );
    grid->SetVGap( 5 );

    std::uint32_t colIndex { 0 };

    addMicroCompositionRow( mElements.Fe,
                            wxT( "Fe (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Mn,
                            wxT( "Mn (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.B,
                            wxT( "B (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Zn,
                            wxT( "Zn (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Cu,
                            wxT( "Cu (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Mo,
                            wxT( "Mo (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Co,
                            wxT( "Co (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    addMicroCompositionRow( mElements.Si,
                            wxT( "Si (%)" ),
                            GetStaticBox(),
                            grid,
                            wxGBPosition( ++colIndex, 0 ) );

    mElements.borComplexElement.checkboxIsBorComplex = static_cast< wxCheckBox * >(
    grid
    ->Add( new wxCheckBox( GetStaticBox(), wxID_ANY, wxT( "Bor complex" ) ),
           wxGBPosition( 9, 0 ),
           wxGBSpan( 1, 2 ) )
    ->GetWindow() );

    mElements.borComplexElement.spinWeight = static_cast< wxSpinCtrlDouble * >(
    grid->Add( allocSpin( GetStaticBox(), 0.001, 5, 99999 ), wxGBPosition( 9, 2 ) )
    ->GetWindow() );

    mElements.borComplexElement.textComposition =
    static_cast< decltype( mElements.borComplexElement.textComposition ) >(
    grid
    ->Add( new wxTextCtrl(
           GetStaticBox(),
           wxID_ANY,
           wxT( "Composite: Fe=0% Mn=0% B=0% Zn=0% Cu=0% Mo=0% Co=0% Si=0%" ),
           wxDefaultPosition,
           wxDefaultSize,
           wxTE_READONLY ),
           wxGBPosition( 10, 0 ),
           wxGBSpan( 1, 4 ),
           wxEXPAND )
    ->GetWindow() );

    grid->Add(
    allocStaticText(
    GetStaticBox(),
    wxT(
    "Micronutrient dilution in water (liquid concentrate of micronutrients)" ) ),
    wxGBPosition( 11, 0 ),
    wxGBSpan( 1, 4 ),
    wxALIGN_CENTER );

    grid->Add( allocStaticText( GetStaticBox(), wxT( "Volume to (ml):" ) ),
               wxGBPosition( 12, 0 ),
               wxGBSpan( 1, 4 ) );

    mElements.borComplexElement.spinVolume = static_cast< wxSpinCtrlDouble * >(
    grid
    ->Add( allocSpin( GetStaticBox(), 1, 0, 99999 ),
           wxGBPosition( 13, 0 ),
           wxGBSpan( 1, 2 ) )
    ->GetWindow() );

    mElements.borComplexElement.textComposition =
    static_cast< decltype( mElements.borComplexElement.textComposition ) >(
    grid
    ->Add(
    new wxTextCtrl(
    GetStaticBox(),
    wxID_ANY,
    wxT( "Concentration: 0.00 g/l, Ratio: 0:0, Spending: 0 ml/l of nutrient" ),
    wxDefaultPosition,
    wxDefaultSize,
    wxTE_READONLY ),
    wxGBPosition( 13, 2 ),
    wxGBSpan( 1, 2 ),
    wxEXPAND )
    ->GetWindow() );

    Add( grid );

    customize();
}

void MicroCompositions::customize() {}

}   // namespace ui
