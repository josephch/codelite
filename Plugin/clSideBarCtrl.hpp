#ifndef CLSIDEBARCTRL_HPP
#define CLSIDEBARCTRL_HPP

#include "codelite_exports.h"

#include <wx/aui/auibar.h>
#include <wx/bitmap.h>
#include <wx/control.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/simplebook.h>
#include <wx/sizer.h>

#if 0
class SideBarButton;
class WXDLLIMPEXP_SDK clSideBarButtonCtrl : public wxControl
{
    friend class SideBarButton;
    friend class clSideBarCtrl;

protected:
    wxDirection m_buttonsPosition = wxLEFT;
    std::vector<SideBarButton*> m_buttons;
    std::unordered_map<wxString, wxBitmap> m_bitmaps;

protected:
    void MoveAfter(SideBarButton* src, SideBarButton* target);
    void MoveBefore(SideBarButton* src, SideBarButton* target);
    int GetButtonIndex(SideBarButton* btn) const;
    SideBarButton* GetButtonFromPos(const wxPoint& pt) const;
    const std::vector<SideBarButton*>& GetAllButtons() const;
    wxWindow* DoChangeSelection(int pos, bool notify);
    void LoadBitmaps();
    void OnPaint(wxPaintEvent& event);
    void OnLeftDown(wxMouseEvent& event);

public:
    clSideBarButtonCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize, long style = 0);
    virtual ~clSideBarButtonCtrl();

    /// Set the buttons packing (horizontal or vertical)
    bool IsHorizontalLayout() const;
    void SetButtonsPosition(wxDirection direction);

    /// Add new button at the end, returns its index
    /// Note that the `label` property is used as the tooltip
    /// It is here for convenience: it can be used to fetch
    int AddButton(const wxString& bitmap_name, const wxString& label, wxWindow* linked_page, bool select = false);

    /// Remove a button by index, return the associated page
    wxWindow* RemoveButton(size_t pos);

    /// Return the current selection
    int GetSelection() const;

    /// Change selection -> this call fires an event
    /// return the new selection linked page
    wxWindow* SetSelection(int pos);

    /// Change selection -> no event is fired
    /// return the new selection linked page
    wxWindow* ChangeSelection(int pos);

    /// How many buttons do we have in this control?
    size_t GetButtonCount() const;

    /// Return the page position
    int GetPageIndex(wxWindow* page) const;

    /// Return the page position
    int GetPageIndex(const wxString& label) const;

    /// return the linked page for the current selection
    wxWindow* GetSelectionLinkedPage() const;

    /// Return the button at position `pos`
    SideBarButton* GetButton(size_t pos) const;

    /// Return the button identified by `label`
    SideBarButton* GetButton(const wxString& label) const;

    /// Remove all buttons
    void Clear();
};
#endif

#if defined(__WXMAC__) || defined(__WXMSW__)
#define USE_AUI_TOOLBAR 1
#else
#define USE_AUI_TOOLBAR 0
#endif

class WXDLLIMPEXP_SDK clSideBarCtrl : public wxControl
{
#if USE_AUI_TOOLBAR
    wxAuiToolBar* m_toolbar = nullptr;
#else
    wxToolBar* m_toolbar = nullptr;
#endif

    wxSimplebook* m_book = nullptr;
    wxDirection m_buttonsPosition = wxLEFT;
    wxBoxSizer* m_mainSizer = nullptr;
    std::unordered_map<size_t, wxString> m_bitmapByPos;

protected:
    /// Return the page position
    int SimpleBookGetPageIndex(wxWindow* page) const;
    void DoRemovePage(size_t pos, bool delete_it);
    void PlaceButtons();
    void OnSize(wxSizeEvent& event);
    void AddTool(const wxString& label, const wxBitmap& bmp, size_t book_index);

public:
    clSideBarCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize, long style = 0);
    virtual ~clSideBarCtrl();

    /// Book API
    void AddPage(wxWindow* page, const wxString& label, const wxString& bmpname, bool selected = false);

    /// Move page identified by `label` to a new position
    void MovePageToIndex(const wxString& label, int new_pos);

    /// return the number of pages in the control
    size_t GetPageCount() const;

    /// return page by index
    wxWindow* GetPage(size_t pos) const;

    /// return page by its label
    wxWindow* GetPage(const wxString& label) const;

    /// return page label
    wxString GetPageText(size_t pos) const;

    /// return the page bitmap
    wxString GetPageBitmap(size_t pos) const;

    /// Set the page bitmap
    void SetPageBitmap(size_t pos, const wxString& bmp);

    /// Remove page (this does not delete it)
    void RemovePage(size_t pos);

    /// Delete page
    void DeletePage(size_t pos);

    /// Change selection and fire an event
    void SetSelection(size_t pos);

    /// Change selection - no event is fired
    void ChangeSelection(size_t pos);

    /// return the current selection
    int GetSelection() const;

    /// Return the page position
    int GetPageIndex(wxWindow* page) const;

    /// Return the page position
    int GetPageIndex(const wxString& label) const;

    /// place the buttons position (top, left, right or bottom)
    void SetButtonPosition(wxDirection direction);

    void Realize();
};

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_SDK, wxEVT_SIDEBAR_SELECTION_CHANGED, wxCommandEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_SDK, wxEVT_SIDEBAR_CONTEXT_MENU, wxContextMenuEvent);
#endif // CLSIDEBARCTRL_HPP
