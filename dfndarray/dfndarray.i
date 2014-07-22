%module dfndarray

%{
#define SWIG_FILE_WITH_INIT
#include "dfndarray.hxx"
#include <sstream>
%}

%include "exception.i"
%include "numpy.i"

%init %{
    import_array(); 
%}

%ignore  dfndarray::Array1D<double>::operator()(size_t);
%ignore &dfndarray::Array1D<double>::operator()(size_t);

%ignore operator<<;

%warnfilter(401) dfndarray::DFArrayError;

%exception {
   try {
      $action
   }
   catch (dfndarray::DFArrayError &e) {
      PyErr_SetString(PyExc_RuntimeError, const_cast<char*>(e.what()));
      return NULL;
   }
}

%extend dfndarray::Array1D<double> {
    double __getitem__(size_t i) {
        return (*($self))(i);
    }
    void __setitem__(size_t i, double val) {
        (*($self))(i) = val;
    }
    char* __str__() {
        std::ostringstream msg;
        msg << *($self);
        return (char*) msg.str().c_str();
    }
}

%feature("director") Wheel;


%include "dfndarray.hxx"

%template(DoubleArray1D) dfndarray::Array1D<double>;

/*../dfndarray.hxx:47: Warning 401: Nothing known about base class 'std::exception'. Ignored.*/
