/* -*- mode: c; -*- */
/*****************************************************************************/
/*  LibreDWG - free implementation of the DWG file format                    */
/*                                                                           */
/*  Copyright (C) 2020 Free Software Foundation, Inc.                        */
/*                                                                           */
/*  This library is free software, licensed under the terms of the GNU       */
/*  General Public License as published by the Free Software Foundation,     */
/*  either version 3 of the License, or (at your option) any later version.  */
/*  You should have received a copy of the GNU General Public License        */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*****************************************************************************/

/*
 * names.inc: associate libredwg names with public VBA names.
 * Taken from objects.inc
 * This is for all objects with no specific methods, and objects with extra methods.
 * written by Reini Urban
 *
 * DWG_ENTITY(token)
 * DWG_ENTITY2(obj,token)
 * DWG_ENTITY4_EXTRA(obj,token,gbname,extra)
 */

DWG_ENTITY4_EXTRA (_3DFACE, _3DFace, "3DFace", _3DFACE)
DWG_ENTITY4_EXTRA (_3DSOLID, _3DSolid, "3DSolid", NONE)
DWG_ENTITY2 (ALIGNMENTPARAMETERENTITY, BlockAlignmentParameterEntity)
DWG_ENTITY2 (ARC, Arc)
DWG_ENTITY2 (ARC_DIMENSION, DimArc)
DWG_ENTITY2 (ARCALIGNEDTEXT, ArcAlignedText)
DWG_ENTITY2 (ATTDEF, AttributeDefinition)
DWG_ENTITY2 (ATTRIB, Attribute)
DWG_ENTITY2 (BASEPOINTPARAMETERENTITY, BlockBasepointParameterEntity)
DWG_ENTITY2 (BLOCK, Block)
DWG_ENTITY2 (BODY, Body)
DWG_ENTITY (CAMERA)
DWG_ENTITY2 (CIRCLE, Circle)
DWG_ENTITY2 (DIMENSION_ALIGNED, DimAligned)
DWG_ENTITY2 (DIMENSION_ANG2LN, DimAngular)
DWG_ENTITY2 (DIMENSION_ANG3PT, Dim3PointAngular)
DWG_ENTITY2 (DIMENSION_DIAMETER, DimDiametric)
DWG_ENTITY2 (DIMENSION_LINEAR, DimRotated)
DWG_ENTITY2 (DIMENSION_ORDINATE, DimOrdinate)
DWG_ENTITY2 (DIMENSION_RADIUS, DimRadial)
DWG_ENTITY2 (ELLIPSE, Ellipse)
//DWG_ENTITY2 (_3DSOLID, Box)
//DWG_ENTITY2 (_3DSOLID, Cone)
//DWG_ENTITY2 (_3DSOLID, Cylinder)
//DWG_ENTITY2 (_3DSOLID, EllipticalCone)
//DWG_ENTITY2 (_3DSOLID, EllipticalCylinder)
//DWG_ENTITY2 (_3DSOLID, ExtrudedSolid)
//DWG_ENTITY2 (_3DSOLID, ExtrudedSolidAlongPath)
//DWG_ENTITY2 (_3DSOLID, Sphere)
//DWG_ENTITY2 (_3DSOLID, Torus)
//DWG_ENTITY2 (_3DSOLID, Wedge)
DWG_ENTITY (ENDBLK)
DWG_ENTITY2 (EXTRUDEDSURFACE, ExtrudedSurface)
DWG_ENTITY2 (FLIPPARAMETERENTITY, BlockFlipParameterEntity)
DWG_ENTITY2 (GEOPOSITIONMARKER, GeoPositionMarker)
DWG_ENTITY2 (HATCH, Hatch)
DWG_ENTITY2 (HELIX, Helix)
DWG_ENTITY2 (IMAGE, RasterImage)
DWG_ENTITY4_EXTRA (INSERT, BlockRef, "BlockRef", INSERT) // created via InsertBlock
DWG_ENTITY2 (LARGE_RADIAL_DIMENSION, DimRadialLarge)
DWG_ENTITY2 (LEADER, Leader)
DWG_ENTITY2 (LIGHT, Light)
DWG_ENTITY2 (LINE, Line)
DWG_ENTITY2 (LINEARPARAMETERENTITY, BlockLinearParameterEntity)
DWG_ENTITY2 (LOFTEDSURFACE, LoftedSurface)
DWG_ENTITY4_EXTRA (LWPOLYLINE, LightWeightPolyline, "LightWeightPolyline", PLINE)
DWG_ENTITY2 (MESH, Mesh)
DWG_ENTITY4_EXTRA (MINSERT, MInsertBlock, "MInsertBlock", INSERT) // Note, the single is called BlockRef
DWG_ENTITY2 (MLINE, MLine)
DWG_ENTITY2 (MPOLYGON, MPolygon)
DWG_ENTITY2 (MTEXT, MText)
DWG_ENTITY2 (MULTILEADER, MLeader)
DWG_ENTITY2 (NAVISWORKSMODEL, NavisworksModel)
DWG_ENTITY2 (NURBSURFACE, NurbSurface)
DWG_ENTITY2 (OLE2FRAME, Ole2Frame)
DWG_ENTITY (OLEFRAME)
DWG_ENTITY2 (PLANESURFACE, PlaneSurface) // or just Surface?
DWG_ENTITY2 (POINT, Point)
DWG_ENTITY2 (POINTCLOUD, PointCloud)
DWG_ENTITY2 (POINTCLOUDEX, PointCloudEx)
DWG_ENTITY2 (POINTPARAMETERENTITY, BlockPointParameterEntity)
DWG_ENTITY2 (POLARGRIPENTITY, BlockPolarGripEntity)
DWG_ENTITY4_EXTRA (POLYLINE_2D, Polyline, "Polyline", PLINE) // GetBulge
DWG_ENTITY4_EXTRA (POLYLINE_3D, _3DPoly, "3DPoly", PMESH) // only AppendVertex
DWG_ENTITY4_EXTRA (POLYLINE_MESH, _3DMesh, "3DMesh", PMESH)
DWG_ENTITY2 (POLYLINE_PFACE, PolyfaceMesh)
DWG_ENTITY2 (PROXY_ENTITY, ProxyEntity)
DWG_ENTITY2 (RAY, Ray)
DWG_ENTITY2 (REGION, Region)
DWG_ENTITY2 (REVOLVEDSURFACE, RevolvedSurface)
DWG_ENTITY2 (ROTATIONPARAMETERENTITY, BlockRotationParameterEntity)
DWG_ENTITY2 (RTEXT, RText)
DWG_ENTITY2 (SECTIONOBJECT, Section)
DWG_ENTITY (SEQEND)
DWG_ENTITY2 (SHAPE, Shape)
DWG_ENTITY2 (SOLID, Solid)
DWG_ENTITY2 (SPLINE, Spline)
DWG_ENTITY2 (SWEPTSURFACE, SweptSurface)
DWG_ENTITY2 (TABLE, Table)
DWG_ENTITY2 (TEXT, Text)
DWG_ENTITY2 (TOLERANCE, Tolerance)
DWG_ENTITY2 (TRACE, Trace)
DWG_ENTITY2 (PDFUNDERLAY, PdfUnderlay)
DWG_ENTITY2 (DGNUNDERLAY, DgnUnderlay)
DWG_ENTITY2 (DWFUNDERLAY, DwfUnderlay)
DWG_ENTITY (UNKNOWN_ENT)
DWG_ENTITY (VERTEX_2D)
DWG_ENTITY (VERTEX_3D)
DWG_ENTITY (VERTEX_MESH)
DWG_ENTITY (VERTEX_PFACE)
DWG_ENTITY (VERTEX_PFACE_FACE)
DWG_ENTITY2 (VIEWPORT, PViewport)
DWG_ENTITY2 (VISIBILITYGRIPENTITY, BlockVisibilityGripEntity)
DWG_ENTITY2 (VISIBILITYPARAMETERENTITY, BlockVisibilityParameterEntity)
DWG_ENTITY2 (WIPEOUT, Wipeout)
DWG_ENTITY2 (XLINE, XLine)
DWG_ENTITY2 (XYPARAMETERENTITY, BlockXYParameterEntity)

DWG_OBJECT (ACMECOMMANDHISTORY)
DWG_OBJECT (ACMESCOPE)
DWG_OBJECT (ACMESTATEMGR)
DWG_OBJECT2 (ACSH_BOOLEAN_CLASS, ShBoolean)
DWG_OBJECT2 (ACSH_BOX_CLASS, ShBox)
DWG_OBJECT2 (ACSH_BREP_CLASS, ShBrep)
DWG_OBJECT2 (ACSH_CHAMFER_CLASS, ShChamfer)
DWG_OBJECT2 (ACSH_CONE_CLASS, ShCone)
DWG_OBJECT2 (ACSH_CYLINDER_CLASS, ShCylinder)
DWG_OBJECT2 (ACSH_EXTRUSION_CLASS, ShExtrusion)
DWG_OBJECT2 (ACSH_FILLET_CLASS, ShFillet)
DWG_OBJECT2 (ACSH_HISTORY_CLASS, ShHistory)
DWG_OBJECT2 (ACSH_LOFT_CLASS, ShLoft)
DWG_OBJECT2 (ACSH_PYRAMID_CLASS, ShPyramid)
DWG_OBJECT2 (ACSH_REVOLVE_CLASS, ShRevolve)
DWG_OBJECT2 (ACSH_SPHERE_CLASS, ShSphere)
DWG_OBJECT2 (ACSH_SWEEP_CLASS, ShSweep)
DWG_OBJECT2 (ACSH_TORUS_CLASS, ShTorus)
DWG_OBJECT2 (ACSH_WEDGE_CLASS, ShWedge)
DWG_OBJECT2 (ALDIMOBJECTCONTEXTDATA, AlignedDimensionObjectContextData)
DWG_OBJECT2 (ANGDIMOBJECTCONTEXTDATA, AngularDimensionObjectContextData)
DWG_OBJECT2 (ANNOTSCALEOBJECTCONTEXTDATA, AnnotScaleObjectContextData)
DWG_OBJECT2 (APPID, RegApp)
DWG_OBJECT2 (APPID_CONTROL, RegApps)
DWG_OBJECT2 (ASSOC2DCONSTRAINTGROUP, Assoc2dConstraintGroup)
DWG_OBJECT2 (ASSOC3POINTANGULARDIMACTIONBODY, Assoc3PointAngularDimActionBody)
DWG_OBJECT2 (ASSOCACTION, AssocAction)
DWG_OBJECT2 (ASSOCACTIONPARAM, AssocActionParam)
DWG_OBJECT2 (ASSOCALIGNEDDIMACTIONBODY, AssocAlignedDimActionBody)
DWG_OBJECT2 (ASSOCARRAYACTIONBODY, AssocArrayActionBody)
DWG_OBJECT2 (ASSOCARRAYMODIFYACTIONBODY, AssocArrayModifyActionBody)
DWG_OBJECT2 (ASSOCARRAYMODIFYPARAMETERS, AssocArrayModifyParameters)
DWG_OBJECT2 (ASSOCARRAYPATHPARAMETERS, AssocArrayPathParameters)
DWG_OBJECT2 (ASSOCARRAYPOLARPARAMETERS, AssocArrayPolarParameters)
DWG_OBJECT2 (ASSOCARRAYRECTANGULARPARAMETERS, AssocArrayRectangularParameters)
DWG_OBJECT2 (ASSOCASMBODYACTIONPARAM, AssocAsmbodyActionParam)
DWG_OBJECT2 (ASSOCBLENDSURFACEACTIONBODY, AssocBlendSurfaceActionBody)
DWG_OBJECT2 (ASSOCCOMPOUNDACTIONPARAM, AssocCompoundActionParam)
DWG_OBJECT2 (ASSOCDEPENDENCY, AssocDependency)
DWG_OBJECT2 (ASSOCDIMDEPENDENCYBODY, AssocDimDependencyBody)
DWG_OBJECT2 (ASSOCEDGEACTIONPARAM, AssocEdgeActionParam)
DWG_OBJECT2 (ASSOCEDGECHAMFERACTIONBODY, AssocEdgeChamferActionBody)
DWG_OBJECT2 (ASSOCEDGEFILLETACTIONBODY, AssocEdgeFilletActionBody)
DWG_OBJECT2 (ASSOCEXTENDSURFACEACTIONBODY, AssocExtendSurfaceActionBody)
DWG_OBJECT2 (ASSOCEXTRUDEDSURFACEACTIONBODY, AssocExtrudedSurfaceActionBody)
DWG_OBJECT2 (ASSOCFACEACTIONPARAM, AssocFaceActionParam)
DWG_OBJECT2 (ASSOCFILLETSURFACEACTIONBODY, AssocFilletSurfaceActionBody)
DWG_OBJECT2 (ASSOCGEOMDEPENDENCY, AssocGeomDependency)
DWG_OBJECT2 (ASSOCLOFTEDSURFACEACTIONBODY, AssocLoftedSurfaceActionBody)
DWG_OBJECT2 (ASSOCMLEADERACTIONBODY, AssocMLeaderActionBody)
DWG_OBJECT2 (ASSOCNETWORK, AssocNetwork)
DWG_OBJECT (ASSOCNETWORKSURFACEACTIONBODY)
DWG_OBJECT (ASSOCOBJECTACTIONPARAM)
DWG_OBJECT (ASSOCOFFSETSURFACEACTIONBODY)
DWG_OBJECT2 (ASSOCORDINATEDIMACTIONBODY, AssocOrdinatedDimActionBody)
DWG_OBJECT (ASSOCOSNAPPOINTREFACTIONPARAM)
DWG_OBJECT (ASSOCPATCHSURFACEACTIONBODY)
DWG_OBJECT2 (ASSOCPATHACTIONPARAM, AssocPathActionParam)
DWG_OBJECT2 (ASSOCPERSSUBENTMANAGER, AssocPersSubentManager)
DWG_OBJECT2 (ASSOCPLANESURFACEACTIONBODY, AssocPlaneSurfaceActionBody)
DWG_OBJECT2 (ASSOCPOINTREFACTIONPARAM, AssocPointRefActionParam)
DWG_OBJECT2 (ASSOCRESTOREENTITYSTATEACTIONBODY, AssocRestoreEntityStateActionBody)
DWG_OBJECT2 (ASSOCREVOLVEDSURFACEACTIONBODY, AssocRevolvedSurfaceActionBody)
DWG_OBJECT2 (ASSOCROTATEDDIMACTIONBODY, AssocRotatedDimActionBody)
DWG_OBJECT2 (ASSOCSWEPTSURFACEACTIONBODY, AssocSweptSurfaceActionBody)
DWG_OBJECT2 (ASSOCTRIMSURFACEACTIONBODY, AssocTrimSurfaceActionBody)
DWG_OBJECT (ASSOCVALUEDEPENDENCY)
DWG_OBJECT (ASSOCVARIABLE)
DWG_OBJECT (ASSOCVERTEXACTIONPARAM)
DWG_OBJECT2 (BLKREFOBJECTCONTEXTDATA, BlkrefObjectContextData)
DWG_OBJECT (BLOCKALIGNEDCONSTRAINTPARAMETER)
DWG_OBJECT2 (BLOCKALIGNMENTGRIP, BlockAlignmentGrip)
DWG_OBJECT2 (BLOCKALIGNMENTPARAMETER, BlockAlignmentParameter)
DWG_OBJECT (BLOCKANGULARCONSTRAINTPARAMETER)
DWG_OBJECT (BLOCKARRAYACTION)
DWG_OBJECT2 (BLOCKBASEPOINTPARAMETER, BlockBasepointParameter)
DWG_OBJECT (BLOCKDIAMETRICCONSTRAINTPARAMETER)
DWG_OBJECT2 (BLOCKFLIPACTION, BlockFlipAction)
DWG_OBJECT2 (BLOCKFLIPGRIP, BlockFlipGrip)
DWG_OBJECT2 (BLOCKFLIPPARAMETER, BlockFlipParameter)
DWG_OBJECT (BLOCKGRIPLOCATIONCOMPONENT)
DWG_OBJECT (BLOCKHORIZONTALCONSTRAINTPARAMETER)
DWG_OBJECT (BLOCKLINEARCONSTRAINTPARAMETER)
DWG_OBJECT2 (BLOCKLINEARGRIP, BlockLinearGrip)
DWG_OBJECT2 (BLOCKLINEARPARAMETER, BlockLinearParameter)
DWG_OBJECT2 (BLOCKLOOKUPACTION, BlockLookupAction)
DWG_OBJECT2 (BLOCKLOOKUPGRIP, BlockLookupGrip)
DWG_OBJECT2 (BLOCKLOOKUPPARAMETER, BlockLookupParameter)
DWG_OBJECT2 (BLOCKMOVEACTION, BlockMoveAction)
DWG_OBJECT (BLOCKPARAMDEPENDENCYBODY)
DWG_OBJECT2 (BLOCKPOINTPARAMETER, BlockPointParameter)
DWG_OBJECT2 (BLOCKPOLARGRIP, BlockPolarGrip)
DWG_OBJECT2 (BLOCKPOLARPARAMETER, BlockPolarParameter)
DWG_OBJECT (BLOCKPOLARSTRETCHACTION)
DWG_OBJECT (BLOCKPROPERTIESTABLE)
DWG_OBJECT (BLOCKPROPERTIESTABLEGRIP)
DWG_OBJECT (BLOCKRADIALCONSTRAINTPARAMETER)
DWG_OBJECT (BLOCKREPRESENTATION)
DWG_OBJECT2 (BLOCKROTATEACTION, BlockRotationAction)
DWG_OBJECT2 (BLOCKROTATIONGRIP, BlockRotationGrip)
DWG_OBJECT2 (BLOCKROTATIONPARAMETER, BlockRotationParameter)
DWG_OBJECT2 (BLOCKSCALEACTION, BlockScaleAction)
DWG_OBJECT (BLOCKSTRETCHACTION)
DWG_OBJECT (BLOCKUSERPARAMETER)
DWG_OBJECT (BLOCKVERTICALCONSTRAINTPARAMETER)
DWG_OBJECT2 (BLOCKVISIBILITYGRIP, BlockVisibilityGrip)
DWG_OBJECT2 (BLOCKVISIBILITYPARAMETER, BlockVisibilityParameter)
DWG_OBJECT2 (BLOCKXYGRIP, BlockXYGrip)
DWG_OBJECT2 (BLOCKXYPARAMETER, BlockXYParameter)
DWG_OBJECT2 (BLOCK_CONTROL, Blocks)
DWG_OBJECT (BLOCK_HEADER)
DWG_OBJECT2 (CELLSTYLEMAP, CellStyleMap)
DWG_OBJECT2 (CONTEXTDATAMANAGER, ContextDataManager)
DWG_OBJECT (CSACDOCUMENTOPTIONS)
DWG_OBJECT2 (CURVEPATH, CurvePath)
DWG_OBJECT2 (DATALINK, DataLink)
DWG_OBJECT2 (DATATABLE, DataTable)
DWG_OBJECT2 (DBCOLOR, DbColor)
DWG_OBJECT2 (DETAILVIEWSTYLE, DetailViewstyle)
DWG_OBJECT2 (DICTIONARY, Dictionary)
DWG_OBJECT2 (DICTIONARYVAR, DictionaryVariables)
DWG_OBJECT2 (DICTIONARYWDFLT, DictionaryWithDefault)
DWG_OBJECT2 (DIMASSOC, DimAssoc)
DWG_OBJECT2 (DIMSTYLE, DimStyle)
DWG_OBJECT2 (DIMSTYLE_CONTROL, DimStyles)
DWG_OBJECT2 (DMDIMOBJECTCONTEXTDATA, DiametricDimensionObjectContextData)
DWG_OBJECT2 (DUMMY, Dummy)
DWG_OBJECT (DYNAMICBLOCKPROXYNODE)
DWG_OBJECT (DYNAMICBLOCKPURGEPREVENTER)
DWG_OBJECT2 (EVALUATION_GRAPH, EvalGraph)
DWG_OBJECT2 (FCFOBJECTCONTEXTDATA, FcfObjectContextData) // TOLERANCE
DWG_OBJECT2 (FIELD, Field)
DWG_OBJECT2 (FIELDLIST, FieldList)
DWG_OBJECT2 (GEODATA, GeoData)
DWG_OBJECT2 (GEOMAPIMAGE, GeomapImage)
DWG_OBJECT2 (GRADIENT_BACKGROUND, GradientBackground)
DWG_OBJECT2 (GROUND_PLANE_BACKGROUND, GroundPlaneBackground)
DWG_OBJECT2 (GROUP, Group)
DWG_OBJECT2 (IBL_BACKGROUND, IblBackground)
DWG_OBJECT2 (IDBUFFER, IdBuffer)
DWG_OBJECT2 (IMAGEDEF, RasterImageDef)
DWG_OBJECT2 (IMAGEDEF_REACTOR, RasterImageDefReactor)
DWG_OBJECT2 (IMAGE_BACKGROUND, ImageBackground)
DWG_OBJECT2 (INDEX, Index)
DWG_OBJECT2 (LAYER, Layer)
DWG_OBJECT2 (LAYERFILTER, LayerFilter)
DWG_OBJECT2 (LAYER_CONTROL, Layers)
DWG_OBJECT2 (LAYER_INDEX, LayerIndex)
DWG_OBJECT2 (LAYOUT, Layout)
DWG_OBJECT (LAYOUTPRINTCONFIG)
DWG_OBJECT2 (LEADEROBJECTCONTEXTDATA, LeaderObjectContextData)
DWG_OBJECT2 (LIGHTLIST, LightList)
DWG_OBJECT (LONG_TRANSACTION)
DWG_OBJECT2 (LTYPE, Linetype)
DWG_OBJECT2 (LTYPE_CONTROL, Linetypes)
DWG_OBJECT2 (MATERIAL, Material)
DWG_OBJECT (MENTALRAYRENDERSETTINGS)
DWG_OBJECT2 (MLEADEROBJECTCONTEXTDATA, MLeaderObjectContextData)
DWG_OBJECT (MLEADERSTYLE)
DWG_OBJECT2 (MLINESTYLE, MlineStyle)
DWG_OBJECT2 (MOTIONPATH, MotionPath)
DWG_OBJECT (MTEXTATTRIBUTEOBJECTCONTEXTDATA)
DWG_OBJECT (MTEXTOBJECTCONTEXTDATA)
DWG_OBJECT2 (NAVISWORKSMODELDEF, NavisworksModelDef)
DWG_OBJECT2 (OBJECT_PTR, ObjectPtr)
DWG_OBJECT2 (ORDDIMOBJECTCONTEXTDATA, OrdinateDimensionObjectContextData)
DWG_OBJECT2 (PERSUBENTMGR, PersSubentManager)
DWG_OBJECT2 (PLACEHOLDER, PlaceHolder)
DWG_OBJECT2 (PLOTSETTINGS, PlotSettings)
DWG_OBJECT2 (POINTCLOUDCOLORMAP, PointCloudColorMap)
DWG_OBJECT2 (POINTCLOUDDEF, PointCloudDef)
DWG_OBJECT2 (POINTCLOUDDEFEX, PointCloudDefEx)
DWG_OBJECT2 (POINTCLOUDDEF_REACTOR, PointCloudReactor)
DWG_OBJECT2 (POINTCLOUDDEF_REACTOR_EX, PointCloudReactorEx)
DWG_OBJECT2 (POINTPATH, PointPath)
DWG_OBJECT2 (PROXY_OBJECT, ProxyObject)
DWG_OBJECT2 (RADIMLGOBJECTCONTEXTDATA, RadialDimensionLargeObjectContextData)
DWG_OBJECT2 (RADIMOBJECTCONTEXTDATA, RadialDimensionObjectContextData)
DWG_OBJECT2 (RAPIDRTRENDERSETTINGS, RapidRTRenderSettings)
DWG_OBJECT2 (RASTERVARIABLES, RasterVariables)
DWG_OBJECT2 (RENDERENTRY, RenderEntry)
DWG_OBJECT2 (RENDERENVIRONMENT, RenderEnvironment)
DWG_OBJECT2 (RENDERGLOBAL, RenderGlobal)
DWG_OBJECT2 (RENDERSETTINGS, RenderSettings)
DWG_OBJECT2 (SCALE, Scale)
DWG_OBJECT2 (SECTIONVIEWSTYLE, SectionViewstyle)
DWG_OBJECT2 (SECTION_MANAGER, SectionManager)
DWG_OBJECT2 (SECTION_SETTINGS, SectionSettings)
DWG_OBJECT2 (SKYLIGHT_BACKGROUND, SkylightBackground)
DWG_OBJECT2 (SOLID_BACKGROUND, SolidBackground)
DWG_OBJECT2 (SORTENTSTABLE, SortentsTable)
DWG_OBJECT2 (SPATIAL_FILTER, SpatialFilter)
DWG_OBJECT2 (SPATIAL_INDEX, SpatialIndex)
DWG_OBJECT2 (STYLE, TextStyle)
DWG_OBJECT2 (STYLE_CONTROL, TextStyles)
DWG_OBJECT2 (SUN, Sun)
DWG_OBJECT2 (SUNSTUDY, SunStudy)
DWG_OBJECT2 (TABLECONTENT, TableContent)
DWG_OBJECT2 (TABLEGEOMETRY, TableGeometry)
DWG_OBJECT2 (TABLESTYLE, TableStyle)
DWG_OBJECT2 (TEXTOBJECTCONTEXTDATA, TextObjectContextData)
DWG_OBJECT (TVDEVICEPROPERTIES)
DWG_OBJECT2 (UCS, UCS)
DWG_OBJECT2 (UCS_CONTROL, UCSs)
DWG_OBJECT2 (PDFDEFINITION, PdfDefinition)
DWG_OBJECT2 (DGNDEFINITION, DgnDefinition)
DWG_OBJECT2 (DWFDEFINITION, DwfDefinition)
DWG_OBJECT (UNKNOWN_OBJ)
DWG_OBJECT2 (VBA_PROJECT, VbaProject)
DWG_OBJECT2 (VIEW, View)
DWG_OBJECT2 (VIEW_CONTROL, Views)
DWG_OBJECT2 (VISUALSTYLE, VisualStyle)
DWG_OBJECT2 (VPORT, Viewport)
DWG_OBJECT2 (VPORT_CONTROL, Viewports)
DWG_OBJECT2 (VX_CONTROL, VXTable)
DWG_OBJECT2 (VX_TABLE_RECORD, VX)
DWG_OBJECT (WIPEOUTVARIABLES)
DWG_OBJECT2 (XRECORD, Xrecord)
