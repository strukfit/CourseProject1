#pragma once

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/dataview.h>
#include <wx/notebook.h>
#include <map>
#include "SQLController.h"

/// <summary>
/// Implementation of the dialog box for adding data 
/// </summary>
class AddDataDialog : public wxDialog
{
private:

	void OnSave(wxCommandEvent& event);

	wxString selectedTable;

	std::vector<wxTextCtrl*> formFields; // Stores form fields data

	SQLController* sqlController;

public:
	AddDataDialog(wxWindow* parent, SQLController* sqlController, wxString selectedTable, wxDataViewListCtrl* table);
};

/// <summary>
/// Implementation of the dialog box for updating data 
/// </summary>
class UpdateDataDialog : public wxDialog
{
private:

	void OnSave(wxCommandEvent& event);

	wxString selectedTable;

	std::vector<wxTextCtrl*> formFields; // Stores form fields data

	SQLController* sqlController;

	wxDataViewListCtrl* table;

	wxString selectedRowId;

	wxString IdColumnName;

public:
	UpdateDataDialog(wxWindow* parent, SQLController* sqlController, wxString selectedTable, wxDataViewListCtrl* table);
};

/// <summary>
/// Implementation of the about program dialog box 
/// </summary>
class AboutProgramDialog : public wxDialog
{

public:
	AboutProgramDialog(wxWindow* parent);
};

/// <summary>
/// Implementation of the about developer dialog box 
/// </summary>
class AboutDeveloperDialog : public wxDialog
{

public:
	AboutDeveloperDialog(wxWindow* parent);
};

/// <summary>
/// Implementation of the dialog box for adding data 
/// </summary>
class TotalInfoDialog : public wxDialog
{

public:
	TotalInfoDialog(wxWindow* parent, SQLController* sqlController);
};

/// <summary>
/// Implementation of a GUI(Graphical user interface)
/// </summary>
class GUI : public wxFrame
{	
	/// <summary>
	/// Tables initialization. Creating and hiding visual tables 
	/// </summary>
	/// <param name="tableName"></param>
	static void TableInit(const char* tableName);

	/// <summary>
	/// Table update
	/// </summary>
	/// <param name="tableName"></param>
	static void UpdateTable(const char* tableName);

	/// <summary>
	/// Setting table column widths
	/// </summary>
	/// <param name="table"></param>
	static void SetTableColumnWidths(wxDataViewListCtrl* table);

	/// <summary>
	/// Handling an event when a checkbox is clicked
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnCheckBoxToggled(wxCommandEvent& event);

	/// <summary>
	/// Handling an event when a check all checkboxes button is clicked
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnCheckAllButtonClicked(wxCommandEvent& event);


	/// <summary>
	/// Handling an event when a listbox string(table name) is selected
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnListBoxSelect(wxCommandEvent& event);

	/// <summary>
	/// Handling an event when a add data button is clicked
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnAddDataButtonClicked(wxCommandEvent& event);

	/// <summary>
	/// Handling an event when a update data button is clicked
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnUpdateDataButtonClicked(wxCommandEvent& event);

	/// <summary>
	/// Handling an event when a update data button is clicked
	/// </summary>
	/// <param name="event - event for handling"></param>
	static void OnDeleteDataButtonClicked(wxCommandEvent& event);

	/// <summary>
	/// Handling an event when a total info button is clicked
	/// </summary>
	/// <param name="event"></param>
	static void OnTotalInfoButtonClicked(wxCommandEvent& event);
	
	/// <summary>
	/// Handling an event when a selection of the table's row is changed
	/// </summary>
	/// <param name="event"></param>
	static void OnSelectionChanged(wxDataViewEvent& event);

	static SQLController* sqlController;

	static wxPanel* panel; // A panel(A window on which controls are placed)

	static wxPanel* tablePanel; // A panel(A window on which controls are placed)
	
	static wxListBox* tableslistBox; // A tableListBox is used to select one of a list of table names.
	
	/// <summary>
	/// Sorted associative container that contains wxDataViewListCtrl* table and its unique key(table name)
	/// </summary>
	static std::map<wxString, wxDataViewListCtrl*> tables; 

	static wxString selectedTable; // Stores the name of the selected table 

	static wxButton* updateDataButton;

	static wxButton* deleteDataButton;

	static AboutProgramDialog* aboutProgramDialog; // Stores about program dialog box

	static AboutDeveloperDialog* aboutDeveloperDialog; // Stores about developer dialog box

	static bool rowSelected;

	/// <summary>
	/// Sorted associative container that contains wxCheckListBox* objects(listbox of checkboxes) and its unique key(table name)
	/// </summary>
	static std::map<wxString, wxCheckListBox*> checkBoxes;

public: 
	
	/// <summary>
	/// Initializing the GUI of the main window
	/// </summary>
	/// <param name="mainWindow - main window(wxFrame class object)"></param>
	/// <param name="sqlController"></param>
	static void MainWindowInit(wxFrame* mainWindow, SQLController* sqlController);
};