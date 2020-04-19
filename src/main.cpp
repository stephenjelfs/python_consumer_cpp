#include <pybind11/pybind11.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void run(string body) {
    cout << " [x] Received "<< body << endl;
    cout.flush();
    size_t count = std::count(body.begin(), body.end(), '.');
    this_thread::sleep_for(chrono::seconds (count) );
    cout << " [x] Done" << endl;
}

namespace py = pybind11;

PYBIND11_MODULE(python_consumer_cpp, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_consumer_cpp

        .. autosummary::
           :toctree: _generate

           run
    )pbdoc";

    m.def("run", &run, R"pbdoc(
        Does something with the body

        Some other explanation about the run function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
