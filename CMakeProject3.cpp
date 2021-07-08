// CMakeProject3.cpp: 定义应用程序的入口点。
//

#include "CMakeProject3.h"

//#include <CGAL/draw_surface_mesh.h>



int main2()
{

	vector<float> walls = { -93.37551536411047, 19.08054158370942, -92.47630469501019, 19.042856494430453, -92.6655675843358, 14.526820650324225, -81.4554078951478, 14.057013206649572, -81.43028450012207, 14.656486991327256, -54.73371881991625, 13.537658569868654, -54.42721342295408, 20.851238742936403, -55.626160986721516, 20.90148552833125, -55.47877041250467, 24.41839839844033, -81.87559920549393, 25.52466512331739, -81.85047581791878, 26.124138907995075, -93.06063550710678, 26.59394635166973 };
	vector<vector<int>> triindex = { {11, 0, 1}, { 1, 2, 3 }, { 1, 3, 4 }, { 4, 5, 6 }, { 4, 6, 7 }, { 7, 8, 9 }, { 9, 10, 11 }, { 9, 11, 1}, { 9, 1, 4}, { 9, 4, 7} };
	int level = 6;
	float level_height = 3.5;
	Mesh a, b;
	vector<Point_3> points;
	vector<Triple_int> patch;
	points.push_back(Point_3(0, 0,0));
	points.push_back(Point_3(0, 1,0));
	points.push_back(Point_3(1, 1,0));
	points.push_back(Point_3(1, 0,0));
	points.push_back(Point_3(0, 0,0));
	//Polygon_2 polygon(points.begin(),points.end());
	Triangulation T(points.begin(), points.end());
	CGAL::Polygon_mesh_processing::triangulate_hole_polyline(points, std::back_inserter(patch));
	vector<vertex_descriptor> ver_descs;
	for (size_t i = 0; i < points.size(); i++)
	{
		ver_descs.push_back(a.add_vertex(points[i]));
	}
	for (size_t i = 0; i < patch.size(); i++)
	{
		a.add_face(ver_descs[patch[i].first], ver_descs[patch[i].second], ver_descs[patch[i].third]);
	}
	CGAL::Polygon_mesh_processing::extrude_mesh(a, b, K::Vector_3(0, 0, 2.5));

	Tree tree(faces(b).first, faces(b).second, b);
	Point_3 src(5, 0.5, 0.7);
	K::Vector_3 dir(-1, 0, 0);
	Segment segment_query(src, src + 10*dir);

	if (tree.do_intersect(segment_query))
		std::cout << "intersection(s)" << std::endl;
	else
		std::cout << "no intersection" << std::endl;

	cout << "Hello CMake." << endl;

	//CGAL::draw(b);

	return 0;
}


int main(void)
{
	vector<vector<float>> walls = {
		{26.275591767620718, 40.71254933840274, 25.911132830711576, 34.022469397898085, 43.88448193431164, 33.04332598330039, 44.21902260058056, 39.184220262614176, 63.98970661993607, 38.10716250787171, 63.644286582404874, 31.766564349588805, 63.54443464529946, 31.77200403508874, 62.766559600873975, 17.493176689245587, 10.144585740490072, 20.35989075232102, 11.297799113153605, 41.5285022771153 },

	};
	vector<vector<vector<int>>> triindex = { { {9, 0, 1},{2, 3, 4},{2, 4, 5},{2, 5, 6},{6, 7, 8},{8, 9, 1},{1, 2, 6},{1, 6, 8 } } };

	clock_t startTime, endTime;
	startTime = clock();

	cout << "start....." << endl;
	float height = 18;
	
	vector<vector<int>> sunshine = get_sunshine(walls,triindex,height,"2020/12/23",32.0);
	cout <<"finish......."<< endl;

	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	//CGAL::draw(mesh);
	return 0;

}




Mesh extrude_mesh(vector<float> &triangles, vector<vector<int>> &triindex, float height)
{
	vector<vertex_descriptor> ver_descs;
	Mesh a,b;
	for (size_t i = 0; i < triangles.size(); i+=2)
	{
		ver_descs.push_back(a.add_vertex(Point_3(triangles[i], triangles[i + 1], 0)));
		
	}
	for (size_t i = 0; i < triindex.size(); i++)
	{
		a.add_face(ver_descs[triindex[i][0]], ver_descs[triindex[i][1]], ver_descs[triindex[i][2]]);
	}
	CGAL::Polygon_mesh_processing::extrude_mesh(a, b, K::Vector_3(0, 0, height));
	return b;
}


bool get_time_mesh_sunshine(Tree &tree, Point_3 src, K::Vector_3 &dir)
{
	Point_3 point2 = src + 1000 * dir;
	Segment segment_query(src, point2);

	bool inter = false;
	inter = tree.do_intersect(segment_query);
	return inter;
}


Mesh create_meshs(vector<vector<float>>& triangles, vector<vector<vector<int>>>& triindex, float height)
{
	Mesh m;
	for (size_t i = 0; i < triangles.size(); i++)
	{
		m += extrude_mesh(triangles[i], triindex[i], height);
		
	}
	return m;
	
}

void get_time_space_mesh_sunshine(Tree &tree, SunPositionCaculate &sun,string &date,int hour,int min,float lat, vector < vector<int>> &sunshine)
{
	//float minx, miny, maxx, maxy;

	//tree.build();
	//CGAL::Bbox_3 bbox = tree.bbox();
	//minx = bbox.min(0);
	//miny = bbox.min(1);
	//maxx = bbox.max(0);
	//maxy = bbox.max(1);
	Point_3 src;
	vector<float> dir1 = sun.getLight(date, hour, min, lat);
	K::Vector_3  dir(dir1[0], dir1[1], dir1[2]);

	if (dir.squared_length()>0)
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 100; j++)
			{
				src = Point_3(i, j, 0);
				if (!get_time_mesh_sunshine(tree, src, dir))
				{
					sunshine[i][j] += 1;
				}
			}
		}
	}

}

vector<vector<int>> get_sunshine(vector<vector<float>>& triangles, vector<vector<vector<int>>>& triindex, float height, string date, float lat)
{
	vector<vector<int>> sunshine(300, vector<int>(300));
	SunPositionCaculate sun;
	Mesh m = create_meshs(triangles, triindex, height);
	Tree tree(faces(m).first, faces(m).second, m);
	for (size_t i = 0; i < 24; i++)
	{
		for (size_t j = 0; j < 60; j++)
		{
			get_time_space_mesh_sunshine(tree, sun, date, i, j, lat, sunshine);
		}
	}
	return sunshine;
}