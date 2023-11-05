#pragma once

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <map>
#include "SQLController.h"

/// <summary>
/// Implementation of a GUI(Graphical user interface)
/// </summary>
class GUI : public wxFrame
{	
	/// <summary>
	/// Handling an event when a button is clicked
	/// </summary>
	/// <param name="event"></param>
	static void OnButtonClicked(wxCommandEvent& event);

	static void OnListBoxSelect(wxCommandEvent& event);

	static wxPanel* panel; // A panel(A window on which controls are placed)
	
	static wxListBox* tableslistBox;

	/// <summary>
	/// Sorted associative container that contains wxListCtrl* table and its unique key(table name)
	/// </summary>
	static std::map<wxString, wxListCtrl*> tables;

	/// <summary>
	/// Sorted associative container that contains container of wxCheckBox* objects and its unique key(table name)
	/// </summary>
	static std::map<wxString, std::vector<wxCheckBox*>> checkBoxes;

public: 
	
	/// <summary>
	/// Initializing the GUI of the main window
	/// </summary>
	/// <param name="mainWindow - main window(wxFrame class object)"></param>
	static void MainWindow(wxFrame* mainWindow, SQLController* sqlController);

	static void AddDataWindow(wxFrame* mainWindow);

	static void ConfirmationWindow(wxFrame* mainWindow);

	/// <summary>
	/// Tables initialization. Creating and hiding visual tables 
	/// </summary>
	/// <param name="sqlController"></param>
	static void TableInit(SQLController* sqlController, sqlite3_stmt* stmt, const char* tableName);

};