// Copyright (c) 2004  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Author(s)     : Christophe Delage <christophe.delage@sophia.inria.fr>

// cell of a triangulation of any dimension <=3
// with hidden points (for the regular triangulation)

#ifndef CGAL_REGULAR_TRIANGULATION_CELL_BASE_3_H
#define CGAL_REGULAR_TRIANGULATION_CELL_BASE_3_H

#include <list>
#include <CGAL/Triangulation_vertex_base_3.h>

CGAL_BEGIN_NAMESPACE

template < typename GT,
           typename Cb = Triangulation_cell_base_3<GT>,
           typename C = std::list<typename GT::Weighted_point_3> >
class Regular_triangulation_cell_base_3
  : public Cb
{
public:
  static const bool DO_HIDE_POINT = true;
  typedef typename Cb::Vertex_handle                   Vertex_handle;
  typedef typename Cb::Cell_handle                     Cell_handle;

  typedef GT                                           Geom_traits;
  typedef typename Geom_traits::Weighted_point_3       Point;

  typedef C                                            Point_container;
  typedef typename Point_container::iterator           Point_iterator;
  typedef typename Point_container::const_iterator     Point_const_iterator;

  template < typename TDS2 >
  struct Rebind_TDS {
    typedef typename Cb::template Rebind_TDS<TDS2>::Other     Cb2;
    typedef Regular_triangulation_cell_base_3<GT, Cb2, C>     Other;
  };

  Regular_triangulation_cell_base_3()
    : Cb() {}

  Regular_triangulation_cell_base_3(const Vertex_handle& v0,
                                    const Vertex_handle& v1,
				    const Vertex_handle& v2,
                                    const Vertex_handle& v3)
    : Cb(v0, v1, v2, v3) {}

  Regular_triangulation_cell_base_3(const Vertex_handle& v0,
                                    const Vertex_handle& v1,
				    const Vertex_handle& v2,
                                    const Vertex_handle& v3,
				    const Cell_handle&   n0,
                                    const Cell_handle&   n1,
				    const Cell_handle&   n2,
                                    const Cell_handle&   n3)
    : Cb(v0, v1, v2, v3, n0, n1, n2, n3) {}

  Point_iterator hidden_points_begin() { return _hidden.begin(); }
  Point_iterator hidden_points_end() { return _hidden.end(); }

  Point_const_iterator hidden_points_begin() const { return _hidden.begin(); }
  Point_const_iterator hidden_points_end() const { return _hidden.end(); }

  void hide_point (const Point &p) { _hidden.push_back(p); }
  //  void unhide_point (Point_iterator i) { _hidden.delete(i); }

private:
  Point_container _hidden;
};

CGAL_END_NAMESPACE

#endif // CGAL_REGULAR_TRIANGULATION_CELL_BASE_3_H
