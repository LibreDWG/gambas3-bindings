/***************************************************************************

  c_dwg_gen.c

  (C) 2020 Reini Urban <rurban@cpan.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
  MA 02110-1301, USA.

***************************************************************************/

#define __CDWG_GEN_C
#include "c_dwg.h"

/* Generated properties, do not change */

/*
GB_DESC DwgRectDesc[] =
{
	GB_DECLARE("DwgRect", sizeof(CDWGRECT)), GB_NOT_CREATABLE(),
	
	GB_PROPERTY_READ("X", "f", DwgRect_X),
	GB_PROPERTY_READ("Y", "f", DwgRect_Y),
	GB_PROPERTY_READ("Width", "f", DwgRect_Width),
	GB_PROPERTY_READ("Height", "f", DwgRect_Height),
	GB_PROPERTY_READ("W", "f", DwgRect_Width),
	GB_PROPERTY_READ("H", "f", DwgRect_Height),
	GB_PROPERTY_READ("Left", "f", DwgRect_X),
	GB_PROPERTY_READ("Top", "f", DwgRect_Y),
	GB_PROPERTY_READ("Right", "f", DwgRect_Right),
	GB_PROPERTY_READ("Bottom", "f", DwgRect_Bottom),
	
	GB_END_DECLARE
};


GB_DESC DwgResultDesc[]=
{
	GB_DECLARE(".DwgDocumentPage.Result",0), GB_VIRTUAL_CLASS(),

	GB_METHOD("_get","DwgRect",DWGPAGERESULT_get,"(Index)i"),
	GB_PROPERTY_READ("Count","i",DWGPAGERESULT_count),

	GB_END_DECLARE
};


GB_DESC DwgLinkDataDesc[]=
{
	GB_DECLARE(".DwgDocumentPage.Link.Data",0), GB_VIRTUAL_CLASS(),

	GB_PROPERTY_READ("Type","i",DWGPAGELINKDATA_type),
	GB_PROPERTY_READ("Target","s",DWGPAGELINKDATA_uri),
	GB_PROPERTY_READ("Parameters","s",DWGPAGELINKDATA_parameters),
	GB_PROPERTY_READ("Page","i",DWGPAGELINKDATA_page),
	GB_PROPERTY_READ("Zoom","f",DWGPAGELINKDATA_zoom),
	GB_PROPERTY_READ("Rect", "DwgRect", DwgPageLinkData_Rect),

	GB_END_DECLARE
};


GB_DESC DwgLinkDesc[]=
{
	GB_DECLARE(".DwgDocumentPage.Link",0), GB_VIRTUAL_CLASS(),

	GB_PROPERTY_READ("Rect", "DwgRect", DwgPageLink_rect),
	GB_PROPERTY_READ("Data",".DwgDocumentPage.Link.Data", DWGPAGELINKDATA_check),

	GB_END_DECLARE
};


GB_DESC DwgIndexDesc[]=
{
	GB_DECLARE(".DwgDocument.Index",0), GB_VIRTUAL_CLASS(),

	GB_PROPERTY("Expanded","b",DWGINDEX_is_open),
	GB_PROPERTY_READ("Count","i",DWGINDEX_count),
	GB_PROPERTY_READ("HasChildren","b",DWGINDEX_has_children),
	GB_PROPERTY_READ("Title","s",DWGINDEX_title),
	GB_PROPERTY_READ("Text","s",DWGINDEX_title),

	GB_PROPERTY_READ("Data", ".DwgDocumentPage.Link.Data", DWGPAGELINKDATA_check),
	GB_METHOD("MovePrevious","b",DWGINDEX_prev,0),
	GB_METHOD("MoveNext","b",DWGINDEX_next,0),
	GB_METHOD("MoveChild","b",DWGINDEX_child,0),
	GB_METHOD("MoveParent","b",DWGINDEX_parent,0),
	GB_METHOD("MoveRoot",0,DWGINDEX_root,0),

	GB_END_DECLARE
};


GB_DESC DwgPageDesc[]=
{
	GB_DECLARE(".DwgDocumentPage",0), GB_VIRTUAL_CLASS(),

	GB_PROPERTY_READ("W","f",DWGPAGE_width),
	GB_PROPERTY_READ("H","f",DWGPAGE_height),
	GB_PROPERTY_READ("Width","f",DWGPAGE_width),
	GB_PROPERTY_READ("Height","f",DWGPAGE_height),
	
	GB_PROPERTY_READ("Image","Image",DWGPAGE_property_image),
	GB_PROPERTY_SELF("Result",".DwgDocumentPage.Result"),

	GB_METHOD("GetImage","Image",DWGPAGE_image,"[(X)i(Y)i(Width)i(Height)i]"),
	GB_METHOD("Find","b",DWGPAGE_find,"(Text)s[(CaseSensitive)b]"),
	GB_METHOD("Select","s",DWGPAGE_select,"[(X)i(Y)i(W)i(H)i]"),

	GB_METHOD("_get",".DwgDocumentPage.Link",DWGPAGELINKS_get,"(Index)i"),
	GB_PROPERTY_READ("Count","i",DWGPAGELINKS_count),

	GB_END_DECLARE
};
*/

GB_DESC DwgDocumentSummaryInfo[] =
{
   GB_DECLARE(".DwgDocument.SummaryInfo",0), GB_NOT_CREATABLE(),

   GB_PROPERTY_READ("Title","s",DWGINFO_title),
   GB_PROPERTY_READ("Author","s",DWGINFO_author),
   GB_PROPERTY_READ("Subject","s",DWGINFO_subject),
   GB_PROPERTY_READ("Keywords","s",DWGINFO_keywords),
   GB_PROPERTY_READ("Comments","s",DWGINFO_comments),
   //GB_PROPERTY_READ("??Date","d",DWGINFO_tdindwg),
   GB_PROPERTY_READ("CreationDate","d",DWGINFO_tdcreate),
   GB_PROPERTY_READ("ModificationDate","d",DWGINFO_tdupdate),

   GB_END_DECLARE
};

/*
GB_DESC DwgLayoutDesc[] =
{
   GB_DECLARE("DwgLayout", 0), GB_NOT_CREATABLE(),

   GB_CONSTANT("Unset","i",Catalog::pageLayoutNone),
   GB_CONSTANT("SinglePage","i",Catalog::pageLayoutSinglePage),
   GB_CONSTANT("OneColumn","i",Catalog::pageLayoutOneColumn),
   GB_CONSTANT("TwoColumnLeft","i",Catalog::pageLayoutTwoColumnLeft),
   GB_CONSTANT("TwoColumnRight","i",Catalog::pageLayoutTwoColumnRight),
   GB_CONSTANT("TwoPageLeft","i",Catalog::pageLayoutTwoPageLeft),
   GB_CONSTANT("TwoPageRight","i",Catalog::pageLayoutTwoPageRight),

   GB_END_DECLARE
};

GB_DESC DwgModeDesc[] =
{
   GB_DECLARE("DwgPageMode",0), GB_NOT_CREATABLE(),

   GB_CONSTANT("Unset","i",Catalog::pageModeNone),
   GB_CONSTANT("UseOutlines","i",Catalog::pageModeOutlines),
   GB_CONSTANT("UseThumbs","i",Catalog::pageModeThumbs),
   GB_CONSTANT("FullScreen","i",Catalog::pageModeFullScreen),
   GB_CONSTANT("UseOC","i",Catalog::pageModeOC),
   GB_CONSTANT("UseAttachments","i",Catalog::pageModeAttach),

   GB_END_DECLARE
};
*/

// This is mostly the same as the DwgDocument, just the importers and exporters are different.
// It really should create a DwgDocument, and just provide some methods.
GB_DESC DxfDocumentDesc[] =
{
  GB_DECLARE("DxfDocument", sizeof(CDXFDOCUMENT)),

  GB_METHOD("_new", 0, DXFDOCUMENT_new, "[(File)]"),
  GB_METHOD("_free", 0, DXFDOCUMENT_free, 0),

  GB_METHOD("Open",0,DXFDOCUMENT_open,"File"),
  GB_METHOD("Save",0,DXFDOCUMENT_save,"(File)"),
  GB_METHOD("SaveAs",0,DXFDOCUMENT_saveas,"[File, (Version)]"),
  GB_METHOD("Close",0,DXFDOCUMENT_close,0),

  GB_END_DECLARE
}

GB_DESC DwgDocumentDesc[] =
{
  GB_DECLARE("DwgDocument", sizeof(CDWGDOCUMENT)),

  // Versions:
  GB_CONSTANT("R_INVALID","i", R_INVALID),
  GB_CONSTANT("R_1_1","i", R_1_1),	/* MC0.0  MicroCAD Release 1.1 */
  GB_CONSTANT("R_1_2","i", R_1_2),	/* AC1.2  AutoCAD Release 1.2 */
  GB_CONSTANT("R_1_3","i", R_1_3),	/* AC1.3  AutoCAD Release 1.3 */
  GB_CONSTANT("R_1_4","i", R_1_4),	/* AC1.40 AutoCAD Release 1.4 */
  GB_CONSTANT("R_2_0","i", R_2_0),	/* AC1.50 AutoCAD Release 2.0 */
  GB_CONSTANT("R_2_1","i", R_2_1),	/* AC2.10 AutoCAD Release 2.10 */
  GB_CONSTANT("R_2_4","i", R_2_4),	/* AC1001 AutoCAD Release 2.4 */
  GB_CONSTANT("R_2_5","i", R_2_5),	/* AC1002 AutoCAD Release 2.5 */
  GB_CONSTANT("R_2_6","i", R_2_6),	/* AC1003 AutoCAD Release 2.6 */
  GB_CONSTANT("R_9","i", R_9),		/* AC1004 AutoCAD Release 9 */
  GB_CONSTANT("R_10","i", R_10),	/* AC1006 AutoCAD Release 10 */
  GB_CONSTANT("R_11","i", R_11),	/* AC1009 AutoCAD Release 11/12 (LT R1/R2) */
  GB_CONSTANT("R_13","i", R_13),	/* AC1012 AutoCAD Release 13 */
  GB_CONSTANT("R_13c3","i", R_13c3),	/* AC1013 AutoCAD Release 13C3 */
  GB_CONSTANT("R_14","i", R_14),	/* AC1014 AutoCAD Release 14 */
  GB_CONSTANT("R_2000","i", R_2000),	/* AC1015 AutoCAD Release 2000 */
  GB_CONSTANT("R_2004","i", R_2004),	/* AC1018 AutoCAD Release 2004 (includes versions AC1019/0x19 and AC1020/0x1a) */
  GB_CONSTANT("R_2007","i", R_2007),	/* AC1021 AutoCAD Release 2007 */
  GB_CONSTANT("R_2010","i", R_2010),	/* AC1024 AutoCAD Release 2010 */
  GB_CONSTANT("R_2013","i", R_2013),	/* AC1027 AutoCAD Release 2013 */
  GB_CONSTANT("R_2018","i", R_2018),	/* AC1032 AutoCAD Release 2018 */
  GB_CONSTANT("R_AFTER","i", R_AFTER)   // also invalid

  GB_METHOD("_new", 0, DWGDOCUMENT_new, "[(File)]"),
  GB_METHOD("_free", 0, DWGDOCUMENT_free, 0),

  GB_METHOD("Open",0,DWGDOCUMENT_open,"File"),
  GB_METHOD("Save",0,DWGDOCUMENT_save,"(File)"),
  GB_METHOD("SaveAs",0,DWGDOCUMENT_saveas,"[File, (Version)]"),
  GB_METHOD("Export",0,DWGDOCUMENT_export,"[File, Extension ]"),
  GB_METHOD("Close",0,DWGDOCUMENT_close,0),
  //GB_METHOD("_get",".DwgDocumentPage",DWGDOCUMENT_get,"(Index)i"),

  //GB_PROPERTY("Zoom", "f", DWGDOCUMENT_scale),
  //GB_PROPERTY("Orientation", "i", DWGDOCUMENT_rotation),

  //GB_PROPERTY_READ("Ready","b",DWGDOCUMENT_ready),
  //GB_PROPERTY_READ("Count","i",DWGDOCUMENT_count),
  //GB_PROPERTY_READ("HasIndex","b",DWGDOCUMENT_has_index),
  //GB_PROPERTY_READ("Index",".DwgDocument.Index",DWGDOCUMENT_index),
  GB_PROPERTY_READ("SummaryInfo",".DwgDocument.SummaryInfo",DWGDOCUMENT_summaryinfo),

  GB_END_DECLARE
};
