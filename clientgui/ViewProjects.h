// $Id$
//
// The contents of this file are subject to the BOINC Public License
// Version 1.0 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://boinc.berkeley.edu/license_1.0.txt
// 
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License. 
// 
// The Original Code is the Berkeley Open Infrastructure for Network Computing. 
// 
// The Initial Developer of the Original Code is the SETI@home project.
// Portions created by the SETI@home project are Copyright (C) 2002
// University of California at Berkeley. All Rights Reserved. 
// 
// Contributor(s):
//
// Revision History:
//

#ifndef _VIEWPROJECTS_H_
#define _VIEWPROJECTS_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "ViewProjects.cpp"
#endif


#include "BOINCBaseView.h"

class CViewProjects : public CBOINCBaseView
{
    DECLARE_DYNAMIC_CLASS( CViewProjects )

public:
    CViewProjects();
    CViewProjects(wxNotebook* pNotebook);

    ~CViewProjects();

    virtual wxString        GetViewName();
    virtual char**          GetViewIcon();

    virtual void            OnTaskRender( wxTimerEvent& event );
    virtual void            OnListRender( wxTimerEvent& event );

    virtual void            OnListSelected( wxListEvent& event );
    virtual void            OnListDeselected( wxListEvent& event );
    virtual wxString        OnListGetItemText( long item, long column ) const;

    virtual void            OnTaskLinkClicked( const wxHtmlLinkInfo& link );
    virtual void            OnTaskCellMouseHover( wxHtmlCell* cell, wxCoord x, wxCoord y );

private:

    bool                    m_bTaskHeaderHidden;
    bool                    m_bTaskAttachToProjectHidden;
    bool                    m_bTaskDetachFromProjectHidden;
    bool                    m_bTaskResetProjectHidden;
    bool                    m_bTaskSuspendProjectHidden;
    bool                    m_bTaskResumeProjectHidden;
    bool                    m_bTaskUpdateProjectHidden;

    bool                    m_bWebsiteHeaderHidden;
    bool                    m_bWebsiteBOINCHidden;
    bool                    m_bWebsiteProjectHidden;

    bool                    m_bTipsHeaderHidden;

    bool                    m_bItemSelected;

    virtual void            UpdateSelection();
    virtual void            UpdateTaskPane();

    wxInt32                 FormatProjectName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatAccountName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatTeamName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatTotalCredit( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatAVGCredit( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatResourceShare( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatStatus( wxInt32 item, wxString& strBuffer ) const;

};


#endif

