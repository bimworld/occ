// Created on: 1996-06-06
// Created by: Stagiaire Xuan Trang PHAMPHU
// Copyright (c) 1996-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _BlendFunc_Chamfer_HeaderFile
#define _BlendFunc_Chamfer_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <BlendFunc_Corde.hxx>
#include <BlendFunc_GenChamfer.hxx>
#include <Standard_Boolean.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
class Adaptor3d_HSurface;
class Adaptor3d_HCurve;
class math_Matrix;
class gp_Pnt;
class gp_Vec;
class gp_Vec2d;
class gp_Lin;
class Blend_Point;



//! Class for a function used to compute a "ordinary" chamfer:
//! when distances from spine to surfaces are constant
class BlendFunc_Chamfer  : public BlendFunc_GenChamfer
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT BlendFunc_Chamfer(const Handle(Adaptor3d_HSurface)& S1, const Handle(Adaptor3d_HSurface)& S2, const Handle(Adaptor3d_HCurve)& CG);
  
  //! computes the values <F> of the Functions for the
  //! variable <X>.
  //! Returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT Standard_Boolean Value (const math_Vector& X, math_Vector& F) Standard_OVERRIDE;
  
  //! returns the values <D> of the derivatives for the
  //! variable <X>.
  //! Returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT Standard_Boolean Derivatives (const math_Vector& X, math_Matrix& D) Standard_OVERRIDE;
  
  Standard_EXPORT void Set (const Standard_Real Param) Standard_OVERRIDE;
  
  Standard_EXPORT Standard_Boolean IsSolution (const math_Vector& Sol, const Standard_Real Tol) Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Pnt& PointOnS1() const Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Pnt& PointOnS2() const Standard_OVERRIDE;
  
  Standard_EXPORT Standard_Boolean IsTangencyPoint() const Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Vec& TangentOnS1() const Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Vec2d& Tangent2dOnS1() const Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Vec& TangentOnS2() const Standard_OVERRIDE;
  
  Standard_EXPORT const gp_Vec2d& Tangent2dOnS2() const Standard_OVERRIDE;
  
  //! Returns the tangent vector at the section,
  //! at the beginning and the end of the section, and
  //! returns the normal (of the surfaces) at
  //! these points.
  Standard_EXPORT void Tangent (const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, gp_Vec& TgFirst, gp_Vec& TgLast, gp_Vec& NormFirst, gp_Vec& NormLast) const Standard_OVERRIDE;
  
  //! Sets the distances and the "quadrant".
  Standard_EXPORT void Set (const Standard_Real Dist1, const Standard_Real Dist2, const Standard_Integer Choix) Standard_OVERRIDE;
  
  //! Returns the length of the maximum section
  Standard_EXPORT Standard_Real GetSectionSize() const Standard_OVERRIDE;
  




protected:





private:


  BlendFunc_Corde corde1;
  BlendFunc_Corde corde2;


};







#endif // _BlendFunc_Chamfer_HeaderFile
