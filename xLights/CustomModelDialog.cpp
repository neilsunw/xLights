#include "CustomModelDialog.h"


#include <wx/msgdlg.h>
#include <wx/clipbrd.h>


//(*InternalHeaders(CustomModelDialog)
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include "models/CustomModel.h"

//(*IdInit(CustomModelDialog)
const long CustomModelDialog::ID_SPINCTRL1 = wxNewId();
const long CustomModelDialog::ID_SPINCTRL2 = wxNewId();
const long CustomModelDialog::ID_BITMAPBUTTON_CUSTOM_CUT = wxNewId();
const long CustomModelDialog::ID_BITMAPBUTTON_CUSTOM_COPY = wxNewId();
const long CustomModelDialog::ID_BITMAPBUTTON_CUSTOM_PASTE = wxNewId();
const long CustomModelDialog::ID_BUTTON_CustomModelZoomIn = wxNewId();
const long CustomModelDialog::ID_BUTTON_CustomModelZoomOut = wxNewId();
const long CustomModelDialog::ID_GRID_Custom = wxNewId();
//*)

BEGIN_EVENT_TABLE(CustomModelDialog,wxDialog)
	//(*EventTable(CustomModelDialog)
	//*)
END_EVENT_TABLE()

CustomModelDialog::CustomModelDialog(wxWindow* parent)
{
	//(*Initialize(CustomModelDialog)
	wxStaticText* StaticText2;
	wxFlexGridSizer* Sizer2;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticText* StaticText1;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, _("Custom Model"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	SetClientSize(wxDLG_UNIT(parent,wxSize(450,350)));
	SetMinSize(wxDLG_UNIT(parent,wxSize(300,200)));
	Sizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	Sizer1->AddGrowableCol(1);
	Sizer1->AddGrowableRow(0);
	Sizer2 = new wxFlexGridSizer(3, 1, 0, 0);
	Sizer2->AddGrowableCol(0);
	Sizer2->AddGrowableRow(2);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, wxID_ANY, _("Width"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	WidthSpin = new wxSpinCtrl(this, ID_SPINCTRL1, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 1, 500, 10, _T("ID_SPINCTRL1"));
	WidthSpin->SetValue(_T("10"));
	FlexGridSizer2->Add(WidthSpin, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, wxID_ANY, _("Height"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	HeightSpin = new wxSpinCtrl(this, ID_SPINCTRL2, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 1, 500, 10, _T("ID_SPINCTRL2"));
	HeightSpin->SetValue(_T("10"));
	FlexGridSizer2->Add(HeightSpin, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Sizer2->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 7, 0, 0);
	BitmapButtonCustomCut = new wxBitmapButton(this, ID_BITMAPBUTTON_CUSTOM_CUT, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CUT")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON_CUSTOM_CUT"));
	FlexGridSizer5->Add(BitmapButtonCustomCut, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButtonCustomCopy = new wxBitmapButton(this, ID_BITMAPBUTTON_CUSTOM_COPY, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_COPY")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON_CUSTOM_COPY"));
	BitmapButtonCustomCopy->SetDefault();
	FlexGridSizer5->Add(BitmapButtonCustomCopy, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButtonCustomPaste = new wxBitmapButton(this, ID_BITMAPBUTTON_CUSTOM_PASTE, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_PASTE")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON_CUSTOM_PASTE"));
	BitmapButtonCustomPaste->SetDefault();
	FlexGridSizer5->Add(BitmapButtonCustomPaste, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_CustomModelZoomIn = new wxButton(this, ID_BUTTON_CustomModelZoomIn, _("+"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CustomModelZoomIn"));
	Button_CustomModelZoomIn->SetMinSize(wxSize(24,-1));
	Button_CustomModelZoomIn->SetToolTip(_("Zoom In"));
	FlexGridSizer5->Add(Button_CustomModelZoomIn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_CustomModelZoomOut = new wxButton(this, ID_BUTTON_CustomModelZoomOut, _("-"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CustomModelZoomOut"));
	Button_CustomModelZoomOut->SetMinSize(wxSize(24,-1));
	Button_CustomModelZoomOut->SetToolTip(_("Zoom Out"));
	FlexGridSizer5->Add(Button_CustomModelZoomOut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Sizer2->Add(FlexGridSizer5, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	Sizer2->Add(StdDialogButtonSizer1, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxFIXED_MINSIZE, 5);
	Sizer1->Add(Sizer2, 1, wxALL|wxEXPAND, 5);
	GridCustom = new wxGrid(this, ID_GRID_Custom, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_GRID_Custom"));
	GridCustom->CreateGrid(1,1);
	GridCustom->EnableEditing(true);
	GridCustom->EnableGridLines(true);
	GridCustom->SetColLabelSize(20);
	GridCustom->SetRowLabelSize(30);
	GridCustom->SetDefaultColSize(30, true);
	GridCustom->SetDefaultCellFont( GridCustom->GetFont() );
	GridCustom->SetDefaultCellTextColour( GridCustom->GetForegroundColour() );
	Sizer1->Add(GridCustom, 0, wxEXPAND, 0);
	SetSizer(Sizer1);
	SetSizer(Sizer1);
	Layout();
	Center();

	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&CustomModelDialog::OnWidthSpinChange);
	Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&CustomModelDialog::OnHeightSpinChange);
	Connect(ID_BITMAPBUTTON_CUSTOM_CUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomModelDialog::OnBitmapButtonCustomCutClick);
	Connect(ID_BITMAPBUTTON_CUSTOM_COPY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomModelDialog::OnBitmapButtonCustomCopyClick);
	Connect(ID_BITMAPBUTTON_CUSTOM_PASTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomModelDialog::OnBitmapButtonCustomPasteClick);
	Connect(ID_BUTTON_CustomModelZoomIn,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomModelDialog::OnButton_CustomModelZoomInClick);
	Connect(ID_BUTTON_CustomModelZoomOut,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomModelDialog::OnButton_CustomModelZoomOutClick);
	//*)
    Connect(ID_GRID_Custom,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&CustomModelDialog::OnGridCustomCellChange);
}

CustomModelDialog::~CustomModelDialog()
{
	//(*Destroy(CustomModelDialog)
	//*)
}

void CustomModelDialog::Setup(CustomModel *m) {
    std::string data = m->GetCustomData();
    if (data == "") {
        ResizeCustomGrid();
        return;
    }

    wxArrayString cols;
    wxArrayString rows=wxSplit(data, ';');
    for(size_t row=0; row < rows.size(); row++)
    {
        if (row >= GridCustom->GetNumberRows()) GridCustom->AppendRows();
        cols=wxSplit(rows[row],',');
        for(size_t col=0; col < cols.size(); col++)
        {
            if (col >= GridCustom->GetNumberCols()) GridCustom->AppendCols();
            wxString value=cols[col];
            if (!value.IsEmpty() && value != "0")
            {
                GridCustom->SetCellValue(row,col,value);
            }
        }
    }
    WidthSpin->SetValue(GridCustom->GetNumberCols());
    HeightSpin->SetValue(GridCustom->GetNumberRows());
    
    
    wxFont font = GridCustom->GetDefaultCellFont();
    GridCustom->SetRowMinimalAcceptableHeight(5); //don't need to read text, just see the shape
    GridCustom->SetColMinimalAcceptableWidth(5); //don't need to read text, just see the shape
    for (int c = 0; c < GridCustom->GetNumberCols(); ++c)
        GridCustom->SetColSize(c, 2 * font.GetPixelSize().y); //GridCustom->GetColSize(c) * 4/5);
    for (int r = 0; r < GridCustom->GetNumberRows(); ++r)
        GridCustom->SetRowSize(r, int(1.5 * (float)font.GetPixelSize().y)); //GridCustom->GetRowSize(r) * 4/5);
    font = GridCustom->GetLabelFont();
    GridCustom->SetColLabelSize(int(1.5 * (float)font.GetPixelSize().y));
    //Sizer1->Fit(this);
    Sizer1->Layout();
    Layout();
}

// make grid the size specified by the spin controls
void CustomModelDialog::ResizeCustomGrid()
{
    int numCols=WidthSpin->GetValue();
    int numRows=HeightSpin->GetValue();
    int deltaCols=numCols - GridCustom->GetNumberCols();
    int deltaRows=numRows - GridCustom->GetNumberRows();
    if (deltaCols > 0) GridCustom->AppendCols(deltaCols);
    if (deltaRows > 0) GridCustom->AppendRows(deltaRows);
    if (deltaCols < 0) GridCustom->DeleteCols(numCols,-deltaCols);
    if (deltaRows < 0) GridCustom->DeleteRows(numRows,-deltaRows);
}

void CustomModelDialog::Save(CustomModel *m) {
    m->SetCustomHeight(HeightSpin->GetValue());
    m->SetCustomWidth(WidthSpin->GetValue());
    std::string customChannelData;
    wxString value;
    int numCols=GridCustom->GetNumberCols();
    int numRows=GridCustom->GetNumberRows();
    for(int row=0; row < numRows; row++) {
        if (row > 0) customChannelData+=";";
        for(int col=0; col<numCols; col++) {
            if (col > 0) customChannelData+=",";
            value = GridCustom->GetCellValue(row,col);
            if (value == "0" || value.StartsWith("-")) value.clear();
            customChannelData += value;
        }
    }
    m->SetCustomData(customChannelData);
}


void CustomModelDialog::OnWidthSpinChange(wxSpinEvent& event)
{
    ResizeCustomGrid();
}

void CustomModelDialog::OnHeightSpinChange(wxSpinEvent& event)
{
    ResizeCustomGrid();
}


void CustomModelDialog::OnButton_CustomModelZoomInClick(wxCommandEvent& event)
{
    GridCustom->BeginBatch();
    wxFont font = GridCustom->GetLabelFont();
    font.MakeLarger();
    GridCustom->SetLabelFont(font);
    font = GridCustom->GetDefaultCellFont();
    font.MakeLarger();
    GridCustom->SetDefaultCellFont(font);
    for (int c = 0; c < GridCustom->GetNumberCols(); ++c)
        GridCustom->SetColSize(c, 2 * font.GetPixelSize().y); //GridCustom->GetColSize(c) * 5/4);
    for (int r = 0; r < GridCustom->GetNumberRows(); ++r)
        GridCustom->SetRowSize(r, int(1.5 * (float)font.GetPixelSize().y)); //GridCustom->GetRowSize(r) * 5/4);
    GridCustom->EndBatch();
}

void CustomModelDialog::OnButton_CustomModelZoomOutClick(wxCommandEvent& event)
{
    GridCustom->BeginBatch();
    wxFont font = GridCustom->GetLabelFont();
    font.MakeSmaller();
    GridCustom->SetLabelFont(font);
    font = GridCustom->GetDefaultCellFont();
    font.MakeSmaller();
    GridCustom->SetDefaultCellFont(font);
    GridCustom->SetRowMinimalAcceptableHeight(5); //don't need to read text, just see the shape
    GridCustom->SetColMinimalAcceptableWidth(5); //don't need to read text, just see the shape
    for (int c = 0; c < GridCustom->GetNumberCols(); ++c)
        GridCustom->SetColSize(c, 2 * font.GetPixelSize().y); //GridCustom->GetColSize(c) * 4/5);
    for (int r = 0; r < GridCustom->GetNumberRows(); ++r)
        GridCustom->SetRowSize(r, int(1.5 * (float)font.GetPixelSize().y)); //GridCustom->GetRowSize(r) * 4/5);
    GridCustom->EndBatch();
}

void CustomModelDialog::OnButtonCustomModelHelpClick(wxCommandEvent& event)
{
    wxMessageBox("To create a custom model, set 'Display As' to 'Custom';\nthen set the model width and model height values.\n\nA custom model allows you to represent almost any display element \ncreated from RGB lights. If your element has 12 RGB nodes in it, then \nyou will need to place the numbers 1 through 12 in the grid. \nPlace the numbers so that they are in the shape of your display \nelement. If you enter a number and then need to erase it, enter a 0.\n\nNode 1 will be assigned:\n  StartChannel\n  StartChannel+1\n  StartChannel+2\nNode 2 will be assigned:\n  StartChannel+3\n  StartChannel+4\n  StartChannel+5\netc.\n\nFor example, to model a candy cane with 12 nodes, you could \nstart with a grid 4 columns wide and 10 rows high. You would place the \nnumbers 1-9 up the right-hand side, 10 and 11 would go in the middle \ncells in the top row, and then 12 would go in column A, row 2.\n\n     11 10\n12           9\n               8\n               7\n               6\n               5\n               4\n               3\n               2\n               1");
}

void CustomModelDialog::OnGridCustomCellChange(wxGridEvent& event)
{
}

#ifdef __WXOSX__
wxString GetOSXFormattedClipboardData();
#endif


void CustomModelDialog::OnBitmapButtonCustomCutClick(wxCommandEvent& event)
{
    CutOrCopyToClipboard(true);
}

void CustomModelDialog::OnBitmapButtonCustomCopyClick(wxCommandEvent& event)
{
    CutOrCopyToClipboard(false);
}
void CustomModelDialog::CutOrCopyToClipboard(bool IsCut) {
    int i,k;
    wxString copy_data;
    bool something_in_this_line;
    
    for (i=0; i< GridCustom->GetNumberRows(); i++)        // step through all lines
    {
        something_in_this_line = false;             // nothing found yet
        for (k=0; k<GridCustom->GetNumberCols(); k++)     // step through all colums
        {
            if (GridCustom->IsInSelection(i,k))     // this field is selected!!!
            {
                if (!something_in_this_line)        // first field in this line => may need a linefeed
                {
                    if (!copy_data.IsEmpty())       // ... if it is not the very first field
                    {
                        copy_data += "\n";     // next LINE
                    }
                    something_in_this_line = true;
                }
                else                                    // if not the first field in this line we need a field seperator (TAB)
                {
                    copy_data += "\t";  // next COLUMN
                }
                copy_data += GridCustom->GetCellValue(i,k);    // finally we need the field value
                if (IsCut) GridCustom->SetCellValue(i,k,wxEmptyString);
            }
        }
    }
    
    if (wxTheClipboard->Open())
    {
        if (!wxTheClipboard->SetData(new wxTextDataObject(copy_data)))
        {
            wxMessageBox(_("Unable to copy data to clipboard."), _("Error"));
        }
        wxTheClipboard->Close();
    }
    else
    {
        wxMessageBox(_("Error opening clipboard."), _("Error"));
    }

}

void CustomModelDialog::OnBitmapButtonCustomPasteClick(wxCommandEvent& event)
{
    wxString copy_data;
    wxString cur_line;
    wxArrayString fields;
    int i,k,fieldnum;
    long val;
    
#ifdef __WXOSX__
    //wxDF_TEXT gets a very strange formatted string from the clipboard if using Numbers
    //native ObjectC code can get the proper tab formatted version.
    copy_data = GetOSXFormattedClipboardData();
#endif
    
    if (copy_data == "") {
        if (wxTheClipboard->Open())
        {
            if (wxTheClipboard->IsSupported(wxDF_TEXT))
            {
                wxTextDataObject data;
                
                if (wxTheClipboard->GetData(data))
                {
                    copy_data = data.GetText();
                }
                else
                {
                    wxMessageBox(_("Unable to copy data from clipboard."), _("Error"));
                }
            }
            else
            {
                wxMessageBox(_("Non-Text data in clipboard."), _("Error"));
            }
            wxTheClipboard->Close();
        }
        else
        {
            wxMessageBox(_("Error opening clipboard."), _("Error"));
            return;
        }
    }
    
    i = GridCustom->GetGridCursorRow();
    k = GridCustom->GetGridCursorCol();
    int numrows=GridCustom->GetNumberRows();
    int numcols=GridCustom->GetNumberCols();
    bool errflag=false;
    wxString errdetails; //-DJ
    
    copy_data.Replace("\r\r", "\n");
    copy_data.Replace("\r\n", "\n");
    copy_data.Replace("\r", "\n");
    
    do
    {
        cur_line = copy_data.BeforeFirst('\n');
        copy_data = copy_data.AfterFirst('\n');
        fields = wxSplit(cur_line, (cur_line.Find(',') != wxNOT_FOUND)? ',': '\t'); //allow comma or tab delim -DJ
        for(fieldnum=0; fieldnum<fields.Count(); fieldnum++)
        {
            if (i < numrows && k+fieldnum < numcols)
            {
                wxString field = fields[fieldnum].Trim(true).Trim(false);
                if (field.IsEmpty() || field.ToLong(&val))
                {
                    GridCustom->SetCellValue(i, k+fieldnum, fields[fieldnum].Trim(true).Trim(false)); //strip surrounding spaces -DJ
                }
                else
                {
                    errflag=true;
                    errdetails += wxString::Format("\n'%s' row %d/col %d of %d", fields[fieldnum].c_str(), i - GridCustom->GetGridCursorRow(), fieldnum, fields.Count()); //tell the user what was wrong; show relative row#, col# (more user friendly) -DJ
                }
            }
        }
        i++;
    }
    while (copy_data.IsEmpty() == false);
    if (errflag)
    {
        wxMessageBox(_("One or more of the values were not pasted because they did not contain a number") + errdetails,_("Paste Error")); //-DJ
    }
}
