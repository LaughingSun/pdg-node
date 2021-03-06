// -----------------------------------------------
// refcounted.h
// 
// utility template for implementing a reference counted object
//
// Written by Ed Zavada, 2004-2012
// Copyright (c) 2012, Dream Rock Studios, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// -----------------------------------------------


#ifndef PDG_REFCOUNTED_H_INCLUDED
#define PDG_REFCOUNTED_H_INCLUDED

#include "pdg_project.h"

#include "pdg/sys/platform.h"

namespace pdg {

// reference counted object template

/// @cond C++
template <class T>
class RefCountedImpl : public T {
public:
    virtual void addRef() const throw() { ++refs; }
	virtual void release() const throw() {
	            --refs; 
	            if (refs == 0) {
	                delete this; 
	            }
	        }
	virtual ~RefCountedImpl() {
//                DEBUG_ONLY( OS::_DOUT("dt RefCountedImpl %p", this); )
	        };
protected:
/// @cond INTERNAL
    mutable long refs;
    RefCountedImpl() : refs(0) {};
/// @endcond
};
/// @endcond

class RefCountedObj {
public:
    virtual void addRef() const throw() { ++refs; }
	virtual void release() const throw() { 
	            --refs; 
	            if (refs == 0) {
	                delete this;
	            }
	        }
protected:
/// @cond INTERNAL
    virtual ~RefCountedObj() {
//                DEBUG_ONLY( OS::_DOUT("dt RefCountedObject %p", this); )
            };
    mutable long refs;
    RefCountedObj() : refs(0) {};
/// @endcond
};

} // end namespace pdg

#endif // PDG_REFCOUNTED_H_INCLUDED

