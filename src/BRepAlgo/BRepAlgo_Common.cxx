// Created on: 1993-10-15
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
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


#include <BRepAlgo_Common.hxx>
#include <TopoDS_Shape.hxx>

Standard_DISABLE_DEPRECATION_WARNINGS

//=======================================================================
//function : BRepAlgo_Common
//purpose  : 
//=======================================================================
BRepAlgo_Common::BRepAlgo_Common(const TopoDS_Shape& S1, 
				   const TopoDS_Shape& S2)
: BRepAlgo_BooleanOperation(S1,S2)
{
  InitParameters();
  PerformDS();
  Perform(TopAbs_IN,TopAbs_IN);
}

Standard_ENABLE_DEPRECATION_WARNINGS
