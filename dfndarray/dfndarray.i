%module dfndarray

%{
#define SWIG_FILE_WITH_INIT
#include "dfndarray.hxx"
#include <sstream>
%}

%include "exception.i"
%include "std_vector.i"
%include "numpy.i"

%init %{
    import_array(); 
%}

%ignore  dfndarray::Array1D<double>::operator()(size_t);
%ignore &dfndarray::Array1D<double>::operator()(size_t);

%ignore  dfndarray::Array2D<double>::operator()(size_t,size_t);
%ignore &dfndarray::Array2D<double>::operator()(size_t,size_t);

%ignore  dfndarray::Array3D<double>::operator()(size_t,size_t,size_t);
%ignore &dfndarray::Array3D<double>::operator()(size_t,size_t,size_t);

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

%template(vec_size_t) std::vector<size_t>;

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
        msg.flush();
        static char tmp[256];
        strcpy(tmp, msg.str().c_str() );
        return &tmp[0];
    }
}

%extend dfndarray::Array2D<double> {
    double __getitem__(std::vector<size_t> idx) {
        if (idx.size() != 2) {
            dfndarray::DFArrayError err("two index required",__FILE__,__LINE__);
            throw err;
        }
        return (*($self))(idx[0],idx[1]);
    }
    void __setitem__(size_t i0, size_t i1, double val) {
        (*($self))(i0,i1) = val;
    }
    char* __str__() {
        std::ostringstream msg;
        msg << *($self);
        msg.flush();
        static char tmp[256];
        strcpy(tmp, msg.str().c_str() );
        return &tmp[0];
    }
}

%extend dfndarray::Array3D<double> {
    double __getitem__(std::vector<size_t> idx) {
        if (idx.size() != 3) {
            dfndarray::DFArrayError err("three index required",__FILE__,__LINE__);
            throw err;
        }
        return (*($self))(idx[0],idx[1],idx[2]);
    }
    void __setitem__(size_t i0, size_t i1, size_t i2, double val) {
        (*($self))(i0,i1,i2) = val;
    }
    char* __str__() {
        std::ostringstream msg;
        msg << *($self);
        msg.flush();
        static char tmp[256];
        strcpy(tmp, msg.str().c_str() );
        return &tmp[0];
    }
}

%feature("director") Wheel;


%include "dfndarray.hxx"

%template(DoubleArray1D) dfndarray::Array1D<double>;
%template(DoubleArray2D) dfndarray::Array2D<double>;
%template(DoubleArray3D) dfndarray::Array3D<double>;
