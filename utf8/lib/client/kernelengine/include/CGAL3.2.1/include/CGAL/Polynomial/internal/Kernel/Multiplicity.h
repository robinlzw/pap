// Copyright (c) 2005  Stanford University (USA).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.2-branch/Kinetic_data_structures/include/CGAL/Polynomial/internal/Kernel/Multiplicity.h $
// $Id: Multiplicity.h 28567 2006-02-16 14:30:13Z lsaboret $
// 
//
// Author(s)     : Daniel Russel <drussel@alumni.princeton.edu>

#ifndef CGAL_POLYNOMIAL_INTERNAL_MULTIPLICITY_H
#define CGAL_POLYNOMIAL_INTERNAL_MULTIPLICITY_H

#include <CGAL/Polynomial/basic.h>
#include <CGAL/Polynomial/internal/Rational/Rational_multiplicity.h>

CGAL_POLYNOMIAL_BEGIN_INTERNAL_NAMESPACE

//! Compute the sign after a root.
/*!
  This has specializations for Explicit_roots.
*/
template <class K>
class Multiplicity: public Rational_multiplicity<K>
{
    typedef Rational_multiplicity<K> P;
    public:
        Multiplicity(const typename K::Function &p, K k=K()): P(p,k){  }
        Multiplicity(){}

        using P::operator();
        typename P::result_type operator()(const typename K::Root &v) const
        {
            CGAL_Polynomial_precondition(0);
            return 1;
        }
};

CGAL_POLYNOMIAL_END_INTERNAL_NAMESPACE
#endif
