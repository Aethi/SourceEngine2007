#ifndef _MColorArray
#define _MColorArray
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
//
// CLASS:    MColorArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MColorArray)
//
//	This class implements an array of MColor's.  Common convenience functions
//	are available, and the implementation is compatible with the internal
//	Maya implementation so that it can be passed efficiently between plugins
//	and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MColor.h>

// *****************************************************************************

// DECLARATIONS


// *****************************************************************************

// CLASS DECLARATION (MColorArray)

/// Array of MColor data type
/**
  Implement an array of MColor data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MColorArray  
{
public:
	///
					MColorArray();
	///
					MColorArray( const MColorArray& other );
	///
					MColorArray( const MColor src[], unsigned int count );
	///
					MColorArray( const float src[][4], unsigned int count );
	///
					MColorArray( const double src[][4], unsigned int count );
	///
					MColorArray( unsigned int initialSize, 
								 const MColor &initialValue );
	///
					~MColorArray();
	///
	const MColor&	operator[]( unsigned int index ) const;
	///
	MColor&	        operator[]( unsigned int index );
 	///
 	MColorArray &   operator=( const MColorArray & other );
	///
	MStatus			set( const MColor& element, unsigned int index );
	///
	MStatus 		set( unsigned int index, float r, float g, float b, float a=1 );
	///
	MStatus			set( float val[4], unsigned int index);
	///
	MStatus			set( float elements[][4], unsigned int size);
	///
	MStatus			set( double elements[][4], unsigned int size);
	///
	MStatus			setLength( unsigned int length );
	///
	unsigned int		length() const;
	///
	MStatus			remove( unsigned int index );
	///
	MStatus			insert( const MColor & element, unsigned int index );
	///
	MStatus			append( const MColor & element );
	///
	MStatus 		append( float r, float g, float b, float a=1 );
	///
	MStatus			clear();
	///
	MStatus			get( float dest[][4] ) const;
	///
	void			setSizeIncrement ( unsigned int newIncrement );
	///
	unsigned int		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os, 
											   const MColorArray &array);

protected:
// No protected members

private:
	MColorArray( void* );
	void * arr;
	struct api_data
	{
		float r;
		float g;
		float b;
		float a;
	};
	const api_data* debugPeekValue;
	bool   own;
	void syncDebugPeekValue();
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MColorArray */