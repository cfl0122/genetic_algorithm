// CMakeProject3.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/General_polygon_with_holes_2.h>
#include <CGAL/Polygon_with_holes_2.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/polygon_mesh_processing.h>
#include <CGAL/Triangulation_simplex_3.h>
#include <CGAL/Triangulation_3.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "sunPositionCaculate.h"
#include <CGAL/Partition_2/Matrix.h>

#include<time.h>


using namespace std;


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef K::Point_3 Point_3;
typedef CGAL::Polygon_2<K> Polygon_2;
typedef CGAL::Surface_mesh<Point_3> Mesh;
typedef CGAL::Triple<int, int, int> Triple_int;
typedef CGAL::Triangulation_3<K>      Triangulation;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;
typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> Primitive;
typedef CGAL::AABB_traits<K, Primitive> Traits;
typedef CGAL::AABB_tree<Traits> Tree;
typedef K::Segment_3 Segment;


Mesh extrude_mesh(vector<float> &triangles, vector<vector<int>> &triindex, float height);
bool get_time_mesh_sunshine(Tree& tree, Point_3 src, K::Vector_3& dir);
Mesh create_meshs(vector<vector<float>>& triangles, vector<vector<vector<int>>>& triindex, float height);
void get_time_space_mesh_sunshine(Tree &tree, SunPositionCaculate& sun, string& date, int hour, int min, float lat, vector<vector<int>> & sunshine);
vector<vector<int>> get_sunshine(vector<vector<float>>& triangles, vector<vector<vector<int>>>& triindex, float height, string date, float lat);

// TODO: 在此处引用程序需要的其他标头。
