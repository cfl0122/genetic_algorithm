#ifndef _API_NEW_H
#define _API_NEW_H

# include <vector>
# include <map>
// #include "pybind11-2.6.1/include/pybind11/pybind11.h"
using namespace std;

vector<int> high_low_new(float land_area, float building_density, float residential_area,
                                    vector<float> bungalow_house_type, vector<float> villa_house_type,                         // {'190': 0.69, '125': 0.31}
                                    vector<float> bungalow_house_ratio, vector<float> villa_house_ratio, 
                                    vector<int> bungalow_building_floor_num,    // map<float, float> villa_house_floor_height_dict, // {'190': 3.15, '125': 2.95}
                                    vector<vector<float> > bungalow_building_type, vector<vector<float> > villa_building_type,                   // {{190.0, 190.0}, {125.0, 125.0}, {115.0, 105.0, 105.0, 115.0}, {140.0, 140.0}}
                                    vector<float> bungalow_building_cover_area, vector<float> villa_building_cover_area,                       // {360,360,320}
                                    vector<float> bungalow_building_single_area,vector<float> villa_building_single_area,
                                    vector<int> bungalow_drop_layer_flag,
                                    int mode, bool log_flag=true);


 vector<int> old_high_low_new(float residential_area, 
                                vector<float> house_type, vector<float> house_rate, 
                                vector<vector<float>> building_type,vector<int> building_floor_num,vector<float> building_single_area,vector<int> building_drop_layer_flag,
                                float cross_rate, float mutation_rate, int flag, int pop_size, bool log_flag);


 vector<int> villa_high_low(float land_area, float building_density, float residential_area, vector<float> villa_house_type, vector<float> villa_house_ratio, vector<vector<float>> villa_building_type, vector<float> villa_building_cover_area,vector<float> villa_building_single_area,
                    float cross_rate, float mutation_rate, bool flag, int pop_size, bool log_flag);

#endif