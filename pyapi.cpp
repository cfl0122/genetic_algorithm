#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "api_new.h"
#include "api.h"



#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

int add(int a,int b)
{
    return a+b;
}



PYBIND11_MODULE(pyapi, m) {
 m.doc() = "geneticAlgorithm bindings";
 
 m.def("high_low", &high_low, "villa  high-low Collocation geneticAlgorithm");
 m.def("high_low_new", &high_low_new, "villa  high-low Collocation geneticAlgorithm");
 m.def("old_high_low", &old_high_low, "old  high-low Collocation geneticAlgorithm");
 m.def("old_high_low_new", &old_high_low_new, "old  high-low Collocation geneticAlgorithm");
 m.def("villa_high_low", &villa_high_low, "old  high-low Collocation geneticAlgorithm");
 m.def("add", &add, "add function");



#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
