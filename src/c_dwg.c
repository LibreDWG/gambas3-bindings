/***************************************************************************

  c_dwg.c

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

#define _C_DWG_C

#include "c_dwg.h"
//#include "gb_common.h"
#include <stdbool.h>

//#include <stdio.h>
//#include <stdint.h>
//#include <math.h>

/**********************************************************************
 Gambas Interface
***********************************************************************/

// returns a field value
static GB_VARIANT_VALUE dynapi_to_gb_value (const Dwg_Data *dwg,
                                            const Dwg_DYNAPI_field *f,
                                            const CDwg_Variant *input)
{
  if (!f) {
    fprintf (stderr, "Unknown field");
    GB.Error(GB_ERR_BOUND);
    GB.ReturnVariant (NULL);
    return;
  }
  switch (f->size) {
  case 1:
    if (strEQc (f->type, "B")) {
      GB.ReturnBoolean (input->b);
      return;
    }
    if (strEQc (f->type, "RC") || strEQc (f->type, "BB")) {
      //GB.ReturnByte (input->rc);
      GB.ReturnInteger (input->rc);
      return;
    }
  case 2:
    if (strEQc (f->type, "BS") || strEQc (f->type, "RS")) {
      //GB.ReturnShort (input->bs);
      GB.ReturnInteger (input->bs);
      return;
    }
  case 4:
    if (strEQc (f->type, "BL") || strEQc (f->type, "RL")) {
      GB.ReturnInteger (input->bl);
      return;
    }
  case 8:
    if (strEQc (f->type, "BLL") || strEQc (f->type, "RLL")) {
      GB.ReturnLong (input->bll);
      return;
    }
    // FIXME TF -> Array_Byte_FromString
    if (*f->type == 'T') {
      GB.ReturnString (input->t);
      //value->type = GB_T_CSTRING;
      //value->value._string = input->t;
      return;
    }
    if (*f->type == 'H') {
      //value->type = GB_T_LONG;
      // TODO OBJECT of type DwgHandle
      //value->value._long = input->h->absolute_ref;
      GB.ReturnLong (input->h->absolute_ref);
      return;
    }
    break;
  case 16:
  case 24: // Float[] or NATIVE_FloatArray
    {
      GB_ARRAY floats;
      if (f->size < 16) {
        break;
      }
      GB.Array.New (POINTER(&floats), GB_T_FLOAT, f->size == 16 ? 2 : 3);
      *(double*)GB.Array.Get (floats, 0) = input->pt.x;
      *(double*)GB.Array.Get (floats, 1) = input->pt.y;
      if (f->size == 24)
        *(double*)GB.Array.Get (floats, 2) = input->pt.z;
      GB.ReturnObject (floats);
      return;
    }
  default:
    break;
  }
  fprintf (stderr, "Unhandled type %s", f->type);
  GB.Error(GB_ERR_TYPE);
  GB.ReturnVariant (NULL);
  return;
}

// sets a field value
static bool gb_to_dynapi_value (const Dwg_Data *dwg,
                                const GB_VALUE *input,
                                CDwg_Variant *output)
{
  GB.Error(GB_ERR_TYPE);
  return false;
}

// returns generic Object
static GB_VARIANT_VALUE obj_generic_to_gb (dwg_obj_generic *_obj)
{
  GB.ReturnVariant (NULL);  
}
// returns generic Object
static GB_VARIANT_VALUE obj_to_gb (dwg_obj_generic *_obj)
{
  GB.ReturnVariant (NULL);  
}
// returns generic Object
static GB_VARIANT_VALUE handle_to_gb (dwg_obj_generic *_obj)
{
  GB.ReturnVariant (NULL);  
}

GB_DESC DwgDocument_Desc[] =
{
  GB_DECLARE("DwgDocument", sizeof(CDwgDocument)),

  // Versions
  GB_CONSTANT("R_INVALID","i", R_INVALID),
  GB_CONSTANT("R_1_1","i", R_1_1),	/* MC0.0  MicroCAD Release 1.1 */
  GB_CONSTANT("R_1_2","i", R_1_2),	/* AC1.2  AutoCAD Release 1.2 */
  GB_CONSTANT("R_1_3","i", R_1_3),	/* AC1.3  AutoCAD Release 1.3 */
  GB_CONSTANT("R_1_4","i", R_1_4),	/* AC1.40 AutoCAD Release 1.4 */
  GB_CONSTANT("R_1_402b","i", R_1_402b),/* AC1.402b AutoCAD Release 1.402b */
  GB_CONSTANT("R_2_0","i", R_2_0),	/* AC1.50 AutoCAD Release 2.0 */
  GB_CONSTANT("R_2_1","i", R_2_1),	/* AC2.10 AutoCAD Release 2.10 */
  GB_CONSTANT("R_2_21","i", R_2_21),	/* AC2.21 AutoCAD Release 2.21 */
  GB_CONSTANT("R_2_22","i", R_2_22),	/* AC2.22 AutoCAD Release 2.22 */
  GB_CONSTANT("R_2_4","i", R_2_4),	/* AC1001 AutoCAD Release 2.4 */
  GB_CONSTANT("R_2_5","i", R_2_5),	/* AC1002 AutoCAD Release 2.5 */
  GB_CONSTANT("R_2_6","i", R_2_6),	/* AC1003 AutoCAD Release 2.6 */
  GB_CONSTANT("R_9","i", R_9),		/* AC1004 AutoCAD Release 9 */
  GB_CONSTANT("R_10","i", R_10),	/* AC1006 AutoCAD Release 10 */
  GB_CONSTANT("R_10c1","i", R_10c1),	/* AC1007 AutoCAD Release 10c1 */
  GB_CONSTANT("R_10c2","i", R_10c2),	/* AC1008 AutoCAD Release 10c2 */
  GB_CONSTANT("R_11","i", R_11),	/* AC1009 AutoCAD Release 11/12 (LT R1/R2) */
  GB_CONSTANT("R_12","i", R_12),	/* AC1010 AutoCAD Release 12 */
  GB_CONSTANT("R_12c1","i", R_12c1),	/* AC1011 AutoCAD Release 12c1 */
  GB_CONSTANT("R_13","i", R_13),	/* AC1012 AutoCAD Release 13 */
  GB_CONSTANT("R_13c3","i", R_13c3),	/* AC1013 AutoCAD Release 13C3 */
  GB_CONSTANT("R_14","i", R_14),	/* AC1014 AutoCAD Release 14 */
  GB_CONSTANT("R_2000","i", R_2000),	/* AC1015 AutoCAD Release 2000 */
  GB_CONSTANT("R_2004","i", R_2004),	/* AC1018 AutoCAD Release 2004-2006
                                           (includes versions AC1019/0x19 and AC1020/0x1a) */
  GB_CONSTANT("R_2007","i", R_2007),	/* AC1021 AutoCAD Release 2007-2009 */
  GB_CONSTANT("R_2010","i", R_2010),	/* AC1024 AutoCAD Release 2010-2012 */
  GB_CONSTANT("R_2013","i", R_2013),	/* AC1027 AutoCAD Release 2013-2017 */
  GB_CONSTANT("R_2018","i", R_2018),	/* AC1032 AutoCAD Release 2018-2021 */
  GB_CONSTANT("R_AFTER","i", R_AFTER),   // also invalid

  /*
  GB_METHOD("_new",  0, DwgDocument_new, "[(File)]"),
  GB_METHOD("_free", 0, DwgDocument_free, 0),
  GB_METHOD("Open",  0, DwgDocument_open,"File"),
  GB_METHOD("Save",  0, DwgDocument_save,"(File)"),
  GB_METHOD("SaveAs",0, DwgDocument_saveas,"[File, (Version)]"),
  GB_METHOD("Export",0, DwgDocument_export,"[File, Extension ]"),
  GB_METHOD("Close", 0, DwgDocument_close,0),

  GB_PROPERTY_READ("SummaryInfo","SummaryInfo", DwgDocument_SummaryInfo),
  */
  GB_END_DECLARE
};

// This is mostly the same as the DwgDocument, just the importers and exporters are different.
// It really should create a DwgDocument, and just provide some methods.
GB_DESC DxfDocument_Desc[] =
{
  GB_DECLARE("DxfDocument", sizeof(CDxfDocument)),
  /*
  GB_METHOD("_new",  0, DxfDocument_new, "[(File)]"),
  GB_METHOD("_free", 0, DxfDocument_free, 0),
  GB_METHOD("Open",  0, DxfDocument_open, "File"),
  GB_METHOD("Save",  0, DxfDocument_save, "(File)"),
  GB_METHOD("SaveAs",0, DxfDocument_saveas, "[File, (Version)]"),
  GB_METHOD("Close", 0, DxfDocument_close, 0),
  */
  GB_END_DECLARE
};

GB_DESC SummaryInfo_Desc[] =
{
   GB_DECLARE("SummaryInfo", 0), GB_NOT_CREATABLE(),
   /*
   GB_PROPERTY_READ("Title","s",SummaryInfo_title),
   GB_PROPERTY_READ("Author","s",SummaryInfo_author),
   GB_PROPERTY_READ("Subject","s",SummaryInfo_subject),
   GB_PROPERTY_READ("Keywords","s",SummaryInfo_keywords),
   GB_PROPERTY_READ("Comments","s",SummaryInfo_comments),
   //GB_PROPERTY_READ("??Date","d",SummaryInfo_tdindwg),
   GB_PROPERTY_READ("CreationDate","d",SummaryInfo_tdcreate),
   GB_PROPERTY_READ("ModificationDate","d",SummaryInfo_tdupdate),
   */
   GB_END_DECLARE
};

#define DWG (((CDwg *)_object)->dwg)

BEGIN_METHOD(Header_get, GB_STRING name;)

  char *key = GB.ToZeroString(ARG(name));
  const Dwg_Data *dwg = DWG;
  CDwg_Variant value;
  Dwg_DYNAPI_field f;
  GB_VARIANT retval;

  if (!dwg_dynapi_header_value (dwg, _key, &value, &f))
    {
      GB.Error(GB_ERR_BOUND);
      return;
    }
  retval = dynapi_to_gb_value (dwg, &f, &value);
  //g_value_init(value, type);
  //return_value (&value);
  //g_value_unset (&retval);
  GB.ReturnConvVariant ();

END_METHOD

BEGIN_METHOD(Header_put, GB_VARIANT value, GB_STRING name;)

  char *key = GB.ToZeroString(ARG(name));
  GB_VALUE *value = (GB_VALUE *)ARG(value);
  const Dwg_Data *dwg = DWG;
  CDwg_Variant out;

  if (!gb_to_dynapi_value (dwg, value, &out))
    GB.Error(GB_ERR_TYPE);
  else
    if (!dwg_dynapi_header_set_value (dwg, _key, &out, true))
      GB.Error(GB_ERR_BOUND);

END_METHOD

GB_DESC Header_Desc[] =
{
   GB_DECLARE("Header", 0), GB_NOT_CREATABLE(),
   // Just declare the getter and setter method via dynapi.
   // No properties, no autocompletion on the header_vars fields
   GB_METHOD("_get", "v", Header_get, "(Name)s"),
   GB_METHOD("_put", NULL, Header_put, "(Value)v(Name)s"),
   GB_END_DECLARE
};

// List of ModelSpace, PaperSpace or Blocks entities.
// Returns dwg_ent_generic Object
BEGIN_METHOD(Entities_get, GB_INTEGER index;)
  
END_METHOD

// Returns dwg_ent_generic Object
BEGIN_METHOD_VOID(Entities_next)
  
    if (*curr < 0 || *curr >= count)
      GB.StopEnum();
    else
      {
        //THIS_MESSAGE->lastKey = gst_structure_nth_field_name(data, *index);
        //const GValue *value = gst_structure_get_value(data, THIS_MESSAGE->lastKey);
        return_value(value);
            
        GB.ReturnConvVariant();
        (*iter)++;
      }
END_METHOD
  
BEGIN_PROPERTY(Entities_Count)

  const Dwg_Data *dwg = DWG;
  // FIXME number of entities in this collection
  GB.ReturnInt(dwg->num_objects);

END_PROPERTY

// This is backed by block_header iterators,
// but the key is not a string, but indices or handles. Returns dwg_ent_generic.
#define ENTITY_COLLECTION(token)                                \
GB_DESC token##_Desc[] =                                        \
  {                                                             \
    GB_DECLARE(#token, sizeof(C##token)), GB_NOT_CREATABLE(),   \
    /* List of entities */                                      \
    GB_PROPERTY_READ("Count", "i", Entities_Count),             \
    GB_METHOD("Add",  "o", Entities_Add, NULL),                 \
    GB_METHOD("_get", "o", Entities_get, "(Index)i"),           \
    /*GB_METHOD("_put", NULL, Entities_put, "(Object)v(Index)i"),*/ \
    GB_METHOD("_next", "o",Entities_next, NULL),                \
    GB_END_DECLARE                                              \
  }
ENTITY_COLLECTION (ModelSpace);
ENTITY_COLLECTION (PaperSpace);
//ENTITY_COLLECTION (Blocks);

BEGIN_PROPERTY(Objects_Count)

  // FIXME number of entities in this collection
  GB.ReturnInt(0);

END_PROPERTY

BEGIN_METHOD(Objects_get, GB_INTEGER index;)

  const Dwg_Data *dwg = DWG;
  int index = VARG(index);
  Dwg_Object *obj;
  if (index < 0 || index >= dwg->num_objects) 
    {
      GB.Error(GB_ERR_BOUND);
      return;
    }
  obj = dwg->objects [index];
  // convert to Object/Entity/Table/Dict depending on type

END_METHOD

// This is backed by the dwg->object[] array. By Index. Returns Dwg_Object_OBJECT*
#define OBJECTS_ARRAY(token)                                    \
GB_DESC token##_Desc[] =                                        \
  {                                                             \
    GB_DECLARE(#token, sizeof(C##token)), GB_NOT_CREATABLE(),   \
    /* Array of objects */                                      \
    GB_PROPERTY_READ("Count", "i", Objects_count),              \
    /*GB_METHOD("_new", "v", Objects_add, "(Type)s"),*/         \
    GB_METHOD("_get", "v", Objects_get, "(Index)i"),            \
    /*GB_METHOD("_put", NULL,Objects_put, "(Object)v(Index)i"),*/ \
    GB_END_DECLARE                                              \
  }

BEGIN_PROPERTY(Table_Count)
  GB.ReturnInt(_ctrl->num_entries);
END_PROPERTY

// Add to TABLE
BEGIN_METHOD(Table_Add, GB_STRING name;)
  char *name = STRING(name);
  Dwg_Type type = ctrl->fixedtype;

#define ADD_TABLE(token)                                 \
  if (type == DWG_TYPE_##token)                          \
    {                                                    \
      Dwg_Object_##token *_obj = dwg_add_##token (THIS_DWG, name); \
      GB.ReturnObject (_obj);                            \
    }
  ADD_TABLE (BLOCK_HEADER) else
  ADD_TABLE (LAYER) else
  ADD_TABLE (LTYPE) else
  ADD_TABLE (DIMSTYLE) else
  ADD_TABLE (APPID) else
  ADD_TABLE (STYLE) else
  ADD_TABLE (UCS) else
  ADD_TABLE (VPORT) else
  ADD_TABLE (VIEW) else
  if (type == DWG_TYPE_UCS) {
    dwg_point_3d origin = {0.0,0.0,0.0}, x_axis = {1.0,0.0,0.0}, y_axis = {0.0,1.0,0.0};
    Dwg_Object_UCS *_obj = dwg_add_UCS (THIS_DWG, name, &origin, &x_axis, &y_axis);
    GB.ReturnObject (obj_generic_to_gb (_obj));
  }
  else {
      GB.Error(GB_ERR_TYPE);
      return;
  }
END_METHOD

// lookup in TABLE_CONTROL
BEGIN_METHOD(Table_get_by_index, GB_INTEGER index;)
  unsigned index = VARG(index);
  if (index >= _ctrl->num_entries)
    {
      GB.Error (GB_ERR_BOUND);
      return;
    }
  GB.ReturnObject (handle_to_gb (_ctrl->entries[index]);
END_METHOD

BEGIN_METHOD(Table_get_by_name, GB_STRING name;)
  char *name = STRING(name);
  for (unsigned i = 0; i < _ctrl->num_entries; i++)
    {
      if (strEQ (_ctrl->entries[i]->name, name)) {
        GB.ReturnObject (handle_to_gb (_ctrl->entries[i]);
        return;
      }
    }
  GB.ReturnVariant (NULL);
END_METHOD

// This is backed by an TABLE_CONTROL array, looked up by name or index.
// Returns Dwg_Object_OBJECT*
#define TABLE_ARRAY(token, obj)                               \
GB_DESC token##_Desc[] =                                      \
  {                                                           \
    GB_DECLARE(#token, sizeof(C##token)), GB_NOT_CREATABLE(), \
    /* Array of table records */                              \
    GB_PROPERTY_READ("Count", "i", Table_Count),              \
    GB_METHOD("Add", "v", Table_Add, "(Name)s"),              \
    GB_METHOD("_get", "v", Table_get_by_index, "(Index)i"),   \
    GB_METHOD("_get", "v", Table_get_by_name, "(Name)s"),     \
    /*GB_METHOD("_put", NULL,Table_put, "(Object)v(Index)i"),*/\
    /*GB_METHOD("_next", "v",Table_next, NULL),*/             \
    GB_END_DECLARE                                            \
  }
TABLE_ARRAY (Blocks, BLOCK_HEADER);
TABLE_ARRAY (DimStyles, DIMSTYLE);
TABLE_ARRAY (Layers, LAYER);
TABLE_ARRAY (Linetypes, LTYPE);
TABLE_ARRAY (RegisteredApplications, APPID);
TABLE_ARRAY (TextStyles, STYLE);
TABLE_ARRAY (UCSs, UCS);
TABLE_ARRAY (Viewports, VPORT);
TABLE_ARRAY (Views, VIEW);

// Lookup by name in the dictionary array. Returns a dwg_obj_generic or handle
#define DICT_COLLECTION(token, nodkey, obj)                   \
GB_DESC token##_Desc[] =                                      \
  {                                                           \
    GB_DECLARE(#token, sizeof(C##token)), GB_NOT_CREATABLE(), \
    /* Hash of dict items */                                  \
    GB_PROPERTY_READ("Count", "i", Dict_count),               \
    GB_METHOD("_get", "o", Dict_get, "(Key)s"),               \
    GB_METHOD("_put", NULL,Dict_put, "(Object)o(Key)s"),      \
    GB_METHOD("_next", "o",Dict_next, NULL),                  \
    GB_END_DECLARE                                            \
  }
#define DICT_COLLECTION2(token, obj) DICT_COLLECTION(token, obj)

DICT_COLLECTION (Dictionaries, NAMED_OBJECT_DICTIONARY, DICTIONARY);
//DICT_COLLECTION (PlotConfigurations, PLOTSTYLENAME, PLOTSTYLE);
DICT_COLLECTION2 (Groups, GROUP);
DICT_COLLECTION (Colors, COLOR, DBCOLOR);
DICT_COLLECTION2 (Layouts, LAYOUT);
DICT_COLLECTION2 (MlineStyles, MLINESTYLE);
DICT_COLLECTION2 (MLeaderStyles, MLEADERSTYLE);
DICT_COLLECTION2 (Materials, MATERIAL);
//DICT_COLLECTION2 (PlotStyles, PLOTSTYLE);
DICT_COLLECTION2 (DetailViewStyles, DETAILVIEWSTYLE);
DICT_COLLECTION2 (SectionViewStyles, SECTIONVIEWSTYLE);
DICT_COLLECTION2 (VisualStyles, VISUALSTYLE);
DICT_COLLECTION (Scales, SCALELIST, SCALE);
DICT_COLLECTION2 (TableStyles, TABLESTYLE);
DICT_COLLECTION (WipeoutVars, WIPEOUT_VARS, WIPEOUTVARIABLES);
DICT_COLLECTION2 (AssocNetworks, ASSOCNETWORK);
DICT_COLLECTION2 (PersSubentManagers, PERSUBENTMGR);
DICT_COLLECTION2 (AssocPersSubentManagers, ASSOCPERSSUBENTMANAGER);
#undef TABLE_COLLECTION
#undef DICT_COLLECTION
#undef DICT_COLLECTION2

/* get/set Object or Entity fields by fieldname */

BEGIN_PROPERTY(Object_Count)

  const dwg_ent_generic *obj = VARG(_object);
  int n = 0;
  // TODO dynapi: all object specific plus all common fields
  GB.ReturnInt(n);

END_PROPERTY

BEGIN_METHOD(Object_get, GB_STRING name;)

  const char *key = STRING(name);
  const dwg_ent_generic *obj = VARG(_object);
  const Dwg_Data *dwg = DWG;
  CDwg_Variant value;
  Dwg_DYNAPI_field f;
  GB_VARIANT retval;

  if (!dwg_dynapi_entity_value (obj, _key, &value, &f))
    {
      GB.Error(GB_ERR_BOUND);
      return;
    }
  dynapi_to_gb_value (dwg, &f, &value, &retval);
  GB.ReturnVariant (&retval);

END_METHOD

BEGIN_METHOD(Object_set, GB_STRING name; GB_VARIANT value;)

  const char *key = STRING(name);
  const dwg_ent_generic *obj = VARG(_object);
  GB_VALUE *value = (GB_VALUE *)ARG(value);
  const Dwg_Data *dwg = DWG;
  CDwg_Variant out;

  if (!gb_to_dynapi_value (dwg, value, &out))
    {
      GB.Error(GB_ERR_TYPE);
      return;
    }
  if (!dwg_dynapi_entity_set_value (dwg, key, &out, true))
    GB.Error(GB_ERR_TYPE);

END_METHOD

#define DWG_OBJECT(token)                                \
GB_DESC token##_Desc[] =                                 \
  {                                                      \
    GB_DECLARE(#token, sizeof(C##token)),                \
    /* get/set Object or Entity fields by fieldname */   \
    GB_PROPERTY_READ("Count", "i", Object_count),        \
    GB_METHOD("_get", "v", Object_get, "(Key)s"),        \
    GB_METHOD("_put", NULL,Object_set, "(Value)v(Key)s"),\
    GB_METHOD("_next", "s",Object_nextfield, NULL),      \
    GB_END_DECLARE                                       \
  };
#define DWG_ENTITY(token) DWG_OBJECT(token)
#include "objects.inc"
#undef DWG_OBJECT
#undef DWG_ENTITY
