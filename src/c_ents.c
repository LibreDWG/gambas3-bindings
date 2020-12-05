/***************************************************************************

  c_ents.c

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

#define _C_ENTS_C

#include "c_dwg.h"
#include "c_ents.h"

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

  const Dwg_Data *dwg = THIS_DWG;
  // FIXME number of entities in this collection
  GB.ReturnInt(dwg->num_objects);

END_PROPERTY

#define SET_PT (tgt, arg) \
  tgt.x = VARG(arg)[0]; \
  tgt.y = VARG(arg)[1]; \
  tgt.z = VARG(arg)[2]

BEGIN_METHOD(Blk_Add3DFace, GB_FLOAT pt1[3]; GB_FLOAT pt2[3]; GB_FLOAT pt3[3]; GB_FLOAT pt4[3];)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_3DFACE *_obj;
  dwg_point_3d pt1, pt2, pt3, pt4;
  SET_PT (pt1, pt1);
  SET_PT (pt2, pt2);
  SET_PT (pt3, pt3);
  SET_PT (pt4, pt3);
  _obj = dwg_add_3DFACE (blkhdr, pt1, pt2, pt3, pt4);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_Add3DMesh, GB_INTEGER m; GB_INTEGER n; GB_FLOAT matrix[];)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_POLYLINE_MESH *_obj;
  unsigned m = VARG(m);
  unsigned n = VARG(n);
  double *matrix = VARG(matrix);
  dwg_point_3d *verts = calloc (m * n, sizeof (dwg_point_3d));
  for (unsigned i = 0, j = 0; i < m * n; i++) {
    verts[i].x = matrix[j++];
    verts[i].y = matrix[j++];
    verts[i].z = matrix[j++];
  }
  _obj = dwg_add_POLYLINE_MESH (blkhdr, m, n, verts);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_Add3DPoly, GB_INTEGER m; GB_INTEGER n; GB_FLOAT matrix[];)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_POLYLINE_MESH *_obj;
  unsigned m = VARG(m);
  unsigned n = VARG(n);
  double *matrix = VARG(matrix);
  dwg_point_3d *verts = calloc (m * n, sizeof (dwg_point_3d));
  for (unsigned i = 0, j = 0; i < m * n; i++) {
    verts[i].x = matrix[j++];
    verts[i].y = matrix[j++];
    verts[i].z = matrix[j++];
  }
  _obj = dwg_add_POLYLINE_MESH (blkhdr, m, n, verts);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// This is backed by block_header iterators,
// but the key is not a string, but indices or handles. Returns dwg_ent_generic.
#define ENTITY_COLLECTION(token)                                \
GB_DESC token##_Desc[] =                                        \
  {                                                             \
    GB_DECLARE(#token, sizeof(C##token)), GB_NOT_CREATABLE(),   \
    /* List of entities */                                      \
    GB_PROPERTY_READ("Count", "i", Entities_Count),             \
    /* Foreach entity type AddType */                           \
    GB_METHOD("Add3DFace", "_3DFACE;", Blk_Add3DFace, "(Point1)f[3](Point2)f[3](Point3)f[3](Point4)f[3]"), \
    GB_METHOD("Add3DMesh", "_POLYLINE_MESH;", Blk_Add3DMesh, "(M)i(N)i(PointsMatrix)f[16]"), \
    GB_METHOD("Add3DPoly", "_POLYLINE_3D;", Blk_Add3DPoly, "(Points)f[]"), \
    GB_METHOD("AddArc", "_ARC;", Blk_AddArc, "(Center)f[3](Radius)f(StartAngle)f(EndAngle)f"), \
    GB_METHOD("AddAttribute", "_ATTDEF;", Blk_AddAttribute, "(Height)f(Mode)i(Prompt)s(InsPoint)f[3](Tag)s(Value)s"), \
    GB_METHOD("AddBox", "_3DSOLID;", Blk_AddBox, "(Origin)f[3](Length)f(Width)f(Height)f"), \
    \
    GB_METHOD("_get", "o", Entities_get, "(Index)i"),           \
    /*GB_METHOD("_put", NULL, Entities_put, "(Object)v(Index)i"),*/ \
    GB_METHOD("_next", "o",Entities_next, NULL),                \
    GB_END_DECLARE                                              \
  }
ENTITY_COLLECTION (ModelSpace);
ENTITY_COLLECTION (PaperSpace);
//ENTITY_COLLECTION (Blocks);
