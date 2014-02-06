#ifndef CAMERAMACROS_H
#define CAMERAMACROS_H
/***********************************************************************

    Copyright (c) Industrial Research Limited 2004-2011

    This file is part of Camwire, a generic camera interface.

    Camwire is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation; either version 2.1 of the
    License, or (at your option) any later version.

    Camwire is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Camwire; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
    USA


    Title: Macro header for Camwire modules

    Description:
    This header file provides some macros for printing debugging
    information and for error status returns to make the code more
    readable and maintainable.  This header should only be included in
    implementation-specific files, i.e. into files that contain `1394'
    in the file name.

CamwirePlus: Michele Adduci <adducimi@informatik.hu-berlin.de>
***********************************************************************/

#include <iostream>

#include <Camera.h>

/* Print debugging error message: */
#ifdef CAMWIRE_DEBUG
#define DPRINTF(m) std::err << "In " << __FILE__ << " line "<< __LINE__ << " function " << __func__ << ": " << m << std::endl;
#else
#define DPRINTF(m) std::cout << m << std::endl;
#endif

/* Function error status returns, for readability and
   maintainability: */
#define ERROR_IF_NULL(p) \
    if ((p)==NULL) {DPRINTF("Null pointer."); return(CAMERA_FAILURE);}
#define ERROR_IF_ZERO(v) \
    if ((v)==0) {DPRINTF("Bad (zero) value."); return(CAMERA_FAILURE);}
#define ERROR_IF_CAMWIRE_FAIL(r) \
    if ((r)!=CAMERA_SUCCESS) \
      {DPRINTF("Camwire function call failed."); \
       return(CAMERA_FAILURE);}
#define ERROR_IF_DC1394_FAIL(r)	\
    if ((r)!= DC1394_SUCCESS) \
      {DPRINTF("dc1394 function call failed."); \
       return(CAMERA_FAILURE);}


#endif /* ndef CAMWIREMACROS_H */
