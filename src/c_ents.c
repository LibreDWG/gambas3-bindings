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

#define THIS ((CModelSpace *)_object)

// List of ModelSpace, PaperSpace or Blocks entities.
// Returns dwg_ent_generic Object
BEGIN_METHOD(Entities_get, GB_INTEGER index;)
  
END_METHOD

// Returns dwg_ent_generic Object
BEGIN_METHOD_VOID(Entities_next)
    if (THIS->iter >= THIS->blkhdr->num_owned)
      GB.StopEnum();
    else
      GB.ReturnObject (handle_to_gb (THIS->dwg, THIS->blkhdr->entities[THIS->iter++]));
END_METHOD
  
BEGIN_PROPERTY(Entities_Count)
  GB.ReturnInteger (THIS->blkhdr->num_owned);
END_PROPERTY

#define SET_PT(tgt, arg) \
  tgt.x = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 0); \
  tgt.y = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 1); \
  tgt.z = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 2)
#define SET_PT1(arg) \
  arg.x = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 0); \
  arg.y = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 1); \
  arg.z = *(double*)GB.Array.Get ((GB_ARRAY)VARG(arg), 2)

BEGIN_METHOD(Blk_Add3DFace, GB_OBJECT pt1; GB_OBJECT pt2; GB_OBJECT pt3; GB_OBJECT pt4)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity__3DFACE *_obj;
  dwg_point_3d pt1, pt2, pt3, pt4;
  SET_PT1 (pt1);
  SET_PT1 (pt2);
  SET_PT1 (pt3);
  SET_PT1 (pt4);
  _obj = dwg_add_3DFACE (blkhdr, &pt1, &pt2, &pt3, &pt4);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_Add3DMesh, GB_INTEGER m; GB_INTEGER n; GB_OBJECT matrix)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_POLYLINE_MESH *_obj;
  unsigned m = VARG(m);
  unsigned n = VARG(n);
  const unsigned num = m * n;
  GB_ARRAY matrix = (GB_ARRAY)VARG(matrix);
  dwg_point_3d *verts = calloc (num, sizeof (dwg_point_3d));
  if (GB.Array.Count(matrix) / 3 != num) {
    GB.Error(GB_ERR_BOUND);
    GB.ReturnVariant (NULL);
    return;
  }
  for (unsigned i = 0, j = 0; i < num; i++) {
    verts[i].x = *(double*)GB.Array.Get (matrix, j++);
    verts[i].y = *(double*)GB.Array.Get (matrix, j++);
    verts[i].z = *(double*)GB.Array.Get (matrix, j++);
  }
  _obj = dwg_add_POLYLINE_MESH (blkhdr, m, n, verts);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_Add3DPoly, GB_OBJECT points)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_POLYLINE_3D *_obj;
  GB_ARRAY *ptsarr = (GB_ARRAY)VARG (points);
  unsigned num_pts = GB.Array.Count (ptsarr) / 3;
  dwg_point_3d *pts = calloc (num_pts, sizeof (dwg_point_3d));
  for (unsigned i = 0, j = 0; i < num_pts; i++) {
    pts[i].x = *(double*)GB.Array.Get (ptsarr, j++);
    pts[i].y = *(double*)GB.Array.Get (ptsarr, j++);
    pts[i].z = *(double*)GB.Array.Get (ptsarr, j++);
  }
  _obj = dwg_add_POLYLINE_3D (blkhdr, num_pts, pts);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// (Center)f[3](Radius)f(StartAngle)f(EndAngle)f
BEGIN_METHOD(Blk_AddArc, GB_OBJECT center; GB_FLOAT radius; GB_FLOAT start_angle; GB_FLOAT end_angle)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_ARC *_obj;
  double radius = (double)VARG(radius);
  double start_angle = (double)VARG(start_angle);
  double end_angle = (double)VARG(end_angle);
  dwg_point_3d center;
  SET_PT1 (center);
  _obj = dwg_add_ARC (blkhdr, &center, radius, start_angle, end_angle);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// (Center)f[3](Radius)f
BEGIN_METHOD(Blk_AddCircle, GB_OBJECT center; GB_FLOAT radius)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_CIRCLE *_obj;
  double radius = (double)VARG(radius);
  dwg_point_3d center;
  SET_PT1 (center);
  _obj = dwg_add_CIRCLE (blkhdr, &center, radius);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// (AngleVertex)f[3](FirstEndPoint)f[3](SecondEndPoint)f[3](TextPoint)f[3]
BEGIN_METHOD(Blk_AddDim3PointAngular, GB_OBJECT center; GB_OBJECT xline1_pt; GB_OBJECT xline2_pt;
                                      GB_OBJECT text_midpt)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_ANG3PT *_obj;
  dwg_point_3d center, xline1_pt, xline2_pt, text_midpt;
  SET_PT1 (center);
  SET_PT1 (xline1_pt);
  SET_PT1 (xline2_pt);
  SET_PT1 (text_midpt);
  _obj = dwg_add_DIMENSION_ANG3PT (blkhdr, &center, &xline1_pt, &xline2_pt, &text_midpt);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_AddDimAligned, GB_OBJECT xline1_pt; GB_OBJECT xline2_pt;
                                GB_OBJECT text_midpt)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_ALIGNED *_obj;
  dwg_point_3d xline1_pt, xline2_pt, text_midpt;
  SET_PT1 (xline1_pt);
  SET_PT1 (xline2_pt);
  SET_PT1 (text_midpt);
  _obj = dwg_add_DIMENSION_ALIGNED (blkhdr, &xline1_pt, &xline2_pt, &text_midpt);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_AddDimAngular, GB_OBJECT center_pt; GB_OBJECT xline1end_pt;
                                GB_OBJECT xline2end_pt; GB_OBJECT text_midpt)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_ANG2LN *_obj;
  dwg_point_3d center_pt, xline1end_pt, xline2end_pt, text_midpt;
  SET_PT1 (center_pt);
  SET_PT1 (xline1end_pt);
  SET_PT1 (xline2end_pt);
  SET_PT1 (text_midpt);
  _obj = dwg_add_DIMENSION_ANG2LN (blkhdr, &center_pt, &xline1end_pt, &xline2end_pt, &text_midpt);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

/*
BEGIN_METHOD(Blk_AddDimArc, GB_OBJECT center; GB_OBJECT xline1_pt; GB_OBJECT xline2_pt;
                            GB_OBJECT arc_pt)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_ARC_DIMENSION *_obj;
  dwg_point_3d center, xline1_pt, xline2_pt, arc_pt;
  SET_PT1 (center);
  SET_PT1 (xline1_pt);
  SET_PT1 (xline2_pt);
  SET_PT1 (arc_pt);
  _obj = dwg_add_ARC_DIMENSION (blkhdr, &center, &xline1_pt, &xline2_pt, &arc_pt);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD
*/

BEGIN_METHOD(Blk_AddDimDiametric, GB_OBJECT chord_pt; GB_OBJECT far_chord_pt;
                                  GB_FLOAT leader_len)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_DIAMETER *_obj;
  double leader_len = (double)VARG(leader_len);
  dwg_point_3d chord_pt, far_chord_pt;
  SET_PT1 (chord_pt);
  SET_PT1 (far_chord_pt);
  _obj = dwg_add_DIMENSION_DIAMETER (blkhdr, &chord_pt, &far_chord_pt, leader_len);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_AddDimOrdinate, GB_OBJECT feature_location_pt; GB_OBJECT leader_endpt;
                                 GB_BOOLEAN use_x_axis)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_ORDINATE *_obj;
  bool use_x_axis = (bool)VARG(use_x_axis);
  dwg_point_3d feature_location_pt, leader_endpt;
  SET_PT1 (feature_location_pt);
  SET_PT1 (leader_endpt);
  _obj = dwg_add_DIMENSION_ORDINATE (blkhdr, &feature_location_pt, &leader_endpt, use_x_axis);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// (Center)f[3](ChordPoint)f[3](LeaderLength)f
BEGIN_METHOD(Blk_AddDimRadial, GB_OBJECT center_pt; GB_OBJECT chord_pt;
                               GB_FLOAT leader_len)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_RADIUS *_obj;
  double leader_len = (double)VARG(leader_len);
  dwg_point_3d center_pt, chord_pt;
  SET_PT1 (center_pt);
  SET_PT1 (chord_pt);
  _obj = dwg_add_DIMENSION_RADIUS (blkhdr, &center_pt, &chord_pt, leader_len);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// (Center)f[3](ChordPoint)f[3](LeaderLength)f
BEGIN_METHOD(Blk_AddDimRadialLarge, GB_OBJECT center_pt; GB_OBJECT first_arc_pt;
                                    GB_OBJECT ovr_center_pt; GB_OBJECT jog_pt;
                                    GB_FLOAT jog_angle)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_LARGE_RADIAL_DIMENSION *_obj;
  dwg_point_3d center_pt, first_arc_pt, ovr_center_pt, jog_pt;
  double jog_angle = (double)VARG(jog_angle);
  SET_PT1 (center_pt);
  SET_PT1 (first_arc_pt);
  SET_PT1 (ovr_center_pt);
  SET_PT1 (jog_pt);
  _obj = dwg_add_LARGE_RADIAL_DIMENSION (blkhdr, &center_pt, &first_arc_pt, &ovr_center_pt,
                                         &jog_pt, jog_angle);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

BEGIN_METHOD(Blk_AddDimRotated, GB_OBJECT xline1_pt; GB_OBJECT xline2_pt;
                                GB_OBJECT def_pt; GB_FLOAT rotation_angle)
  Dwg_Object_BLOCK_HEADER *blkhdr = THIS->blkhdr;
  Dwg_Entity_DIMENSION_LINEAR *_obj;
  dwg_point_3d xline1_pt, xline2_pt, def_pt;
  double rotation_angle = (double)VARG(rotation_angle);
  SET_PT1 (xline1_pt);
  SET_PT1 (xline2_pt);
  SET_PT1 (def_pt);
  _obj = dwg_add_DIMENSION_LINEAR (blkhdr, &xline1_pt, &xline2_pt, &def_pt, rotation_angle);
  GB.ReturnObject (obj_generic_to_gb (_obj));
END_METHOD

// This is backed by block_header iterators,
// but the key is not a string, but indices or handles. Returns dwg_ent_generic.
#undef ENTITY_COLLECTION
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
    /* \
    GB_METHOD("AddAttribute", "_ATTDEF;", Blk_AddAttribute, "(Height)f(Mode)i(Prompt)s(InsPoint)f[3](Tag)s(Value)s"), \
    GB_METHOD("AddBox", "_3DSOLID;", Blk_AddBox, "(Origin)f[3](Length)f(Width)f(Height)f"), \
    */                                                                     \
    GB_METHOD("AddCircle", "_CIRCLE;", Blk_AddCircle, "(Center)f[3](Radius)f"), \
    /*                                                                     \
    GB_METHOD("AddCone", "_ACSH_CONE_CLASS;", Blk_AddCone, "(Center)f[3](BaseRadius)f(Height)f"), \
    GB_METHOD("AddCustomObject", "o", Blk_AddCustomObject, "(ClasseName)s"), \
    GB_METHOD("AddCylinder", "_ACSH_CYLINDER_CLASS;", Blk_AddCylinder, "(Center)f[3](Radius)f(Height)f"), \
    */                                                                     \
    GB_METHOD("AddDim3PointAngular", "_DIMENSION_ANG3PT;", Blk_AddDim3PointAngular, "(AngleVertex)f[3](FirstEndPoint)f[3](SecondEndPoint)f[3](TextPoint)f[3]"), \
    GB_METHOD("AddDimAligned", "_DIMENSION_ALIGNED;", Blk_AddDimAligned, "(FirstEndPoint)f[3](SecondEndPoint)f[3](TextPoint)f[3]"), \
    GB_METHOD("AddDimAngular", "_DIMENSION_ANG2LN;", Blk_AddDimAngular, "(CenterPoint)f[3](FirstEndPoint)f[3](SecondEndPoint)f[3](TextPoint)f[3]"), \
    /*GB_METHOD("AddDimArc", "_ARC_DIMENSION;", Blk_AddDimArc, "(Center)f[3](FirstEndPoint)f[3](SecondEndPoint)f[3](ArcPoint)f[3]"),*/ \
    GB_METHOD("AddDimDiametric", "_DIMENSION_DIAMETER;", Blk_AddDimDiametric, "(FirstEndPoint)f[3](SecondEndPoint)f[3](TextPoint)f[3]"), \
    GB_METHOD("AddDimOrdinate", "_DIMENSION_ORDINATE;", Blk_AddDimOrdinate, "(DefPoint)f[3](LeaderEndPoint)f[3](UseXAxis)b"), \
    GB_METHOD("AddDimRadial", "_DIMENSION_RADIUS;", Blk_AddDimRadial, "(Center)f[3](ChordPoint)f[3](LeaderLength)f"), \
    GB_METHOD("AddDimadialLarge", "_DIMENSION_LARGE_RADIAL_DIMENSION;", Blk_AddDimRadialLarge, "(Center)f[3](ChordPoint)f[3](OverrideCenter)f[3](JogPoint)f[3](JogAngle)f"), \
    GB_METHOD("AddDimRotated", "_DIMENSION_LINEAR;", Blk_AddDimRotated, "(XLine1Point)f[3](XLine2Point)f[3](DefPoint)f[3](RotationAngle)f"), \
                                                                           \
    GB_METHOD("_get", "_CDwgObject;", Entities_get, "(Index)i"),           \
    /*GB_METHOD("_put", NULL, Entities_put, "(Object)v(Index)i"),*/        \
    GB_METHOD("_next", "_CDwgObject;",Entities_next, NULL),                \
    GB_END_DECLARE                                                         \
  }
ENTITY_COLLECTION (ModelSpace);
ENTITY_COLLECTION (PaperSpace);
//ENTITY_COLLECTION (Blocks);
