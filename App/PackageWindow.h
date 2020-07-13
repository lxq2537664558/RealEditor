#pragma once
#include <wx/frame.h>
#include <wx/splitter.h>
#include <wx/dataview.h>
#include <wx/toolbar.h>
#include <wx/propgrid/manager.h>

#include <Tera/Core.h>

#include "GenericEditor.h"

class App;
class PackageWindow : public wxFrame {
public:
  PackageWindow(std::shared_ptr<FPackage>& package, App* application);
	~PackageWindow();
  wxString GetPackagePath() const;

private:

	void InitLayout();
	void LoadTreeIcons();
	void LoadObjectTree();

	wxDECLARE_EVENT_TABLE();
	// Menu
	void OnNewClicked(wxCommandEvent&);
	void OnOpenClicked(wxCommandEvent&);
	void OnSaveClicked(wxCommandEvent&);
	void OnSaveAsClicked(wxCommandEvent&);
	void OnCloseClicked(wxCommandEvent&);
	void OnExitClicked(wxCommandEvent&);
	void OnCloseWindow(wxCloseEvent& e);
	void OnMoveEnd(wxMoveEvent& e);
	void OnMaximized(wxMaximizeEvent& e);

	void SidebarSplitterOnIdle(wxIdleEvent&);
	void OnObjectTreeStartEdit(wxDataViewEvent& e);
	void OnObjectTreeSelectItem(wxDataViewEvent& e);

	void OnImportObjectSelected(INT index);
	void OnExportObjectSelected(INT index);
	void OnNoneObjectSelected();

	void SetPropertiesHidden(bool hidden);
	void SetContentHidden(bool hidden);

	void ShowEditor(GenericEditor* editor);

private:
  App* Application = nullptr;
  std::shared_ptr<FPackage> Package = nullptr;
	wxDataViewTreeCtrl* ObjectTreeCtrl = nullptr;
	wxTextCtrl* ObjectFlagsTextfield = nullptr;
	wxStaticText* ObjectOffsetLabel = nullptr;
	wxStaticText* ObjectSizeLabel = nullptr;
	wxStaticText* PropertiesSizeLabel = nullptr;
	wxStaticText* DataSizeLabel = nullptr;
	wxTextCtrl* ExportFlagsTextfield = nullptr;
	wxToolBar* Toolbar = nullptr;
	wxPropertyGridManager* PropertiesCtrl = nullptr;
	wxStaticText* ObjectTitleLabel = nullptr;
	wxSplitterWindow* ContentSplitter = nullptr;
	wxSplitterWindow* SidebarSplitter = nullptr;
	wxButton* BackButton = nullptr;
	wxButton* ForwardButton = nullptr;
	wxPanel* MainPanel = nullptr;
	wxPanel* EditorContainer = nullptr;
	wxPanel* PropertiesPanel = nullptr;
	wxPanel* ObjectInfoPanel = nullptr;
	wxImageList* ImageList = nullptr;

	std::map<PACKAGE_INDEX, GenericEditor*> Editors;

	bool ContentHidden = false;
	bool PropertiesHidden = false;
	int PropertiesPos = 0;
};