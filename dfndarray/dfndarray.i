%module dfndarray

%{
#define SWIG_FILE_WITH_INIT
#include "dfndarray.hxx"
%}

%include "numpy.i"

%init %{
    import_array(); 
%}

%include "dfndarray.hxx"
