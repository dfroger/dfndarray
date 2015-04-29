dfndarray
=========

Minimalist C++ multidimensional array implementation.

Example source code:

    #include "dfndarray.hxx"

    #include <iostream>

    using namespace std;

    int main()
    {
        dfndarray::Array3D<double> A(4,2,3);

        cout << "A           : " << A << endl;
        cout << "A.dim(0)    : " << A.dim(0) << endl;

        for (size_t i0 = 0 ; i0 < A.n0() ; i0++) {
        for (size_t i1 = 0 ; i1 < A.n1() ; i1++) {
        for (size_t i2 = 0 ; i2 < A.n2() ; i2++) {
            A(i0,i1,i2) = i0*100 + i1*10 + i2;
        } } }

        cout << "A(2,1,0)    : " << A(2,1,0) << endl;

        for (double* p = A.data() ; p < A.data()+A.size() ; p++) {
            *p = 0.;
        }

        cout << "A(2,1,0)    : " << A(2,1,0) << endl;

        // An exception with be catched fi example.cxx is compiled with
        // -DDFNDARRAY_RUNTIME_CHECK, otherwise a segmentation fault
        // occurs, or a wrong result is returned.
        try {
            cout << A(10,10,10) << endl;
        } catch (dfndarray::DFArrayError e) {
            cout << "Exception catched: " << e.what() << endl;
        }

        return 0;
    }


Compile:

    $ ../waf build_debug

Run example:

    $ ./build/debug/main

Result:

    A           : <Array3D of shape (4,2,3) at 0x90b010>
    A.dim(0)    : 4
    A(2,1,0)    : 210
    A(2,1,0)    : 0
    Exception catched: /local/froger/miniconda/envs/test-dfndarrray/include/dfndarray.hxx:330: expected 'i0 < m_n0', but got: '10 >= 4'.
