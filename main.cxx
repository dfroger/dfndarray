#include "dfndarray.hxx"

#include <iostream>

using namespace std;

int main()
{
    //===========================================================================
    // Array 1D
    //===========================================================================


    dfndarray::Array1D<double> A(4);
    dfndarray::Array1DComputeValue* f = new dfndarray::Array1DComputeTestValue();
    A.fill(f);

    dfndarray::Array1D<double> B;

    cout << "------------------- Array 1D -------------------" << endl;
    cout << "B        : " << B << endl;
    try {
        cout << B(1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "B(1)     : Exception catched: " << e.what() << endl;
    }
    cout << "A        : " << A << endl;
    cout << "A(1)     : " << A(1) << endl;
    cout << "A.dim(0) : " << A.dim(0) << endl;
    try {
        cout << A(10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "A(10)    : Exception catched: " << e.what() << endl;
    }


    //===========================================================================
    // Array 2D
    //===========================================================================


    dfndarray::Array2D<double> C(4,2);
    dfndarray::Array2DComputeValue* g = new dfndarray::Array2DComputeTestValue();
    C.fill(g);

    dfndarray::Array2D<double> D;

    cout << endl << "------------------- Array 2D -------------------" << endl;
    cout << "D        : " << D << endl;
    try {
        cout << D(1,1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "D(1,1)   : Exception catched: " << e.what() << endl;
    }
    cout << "C        : " << C << endl;
    cout << "C(2,1)   : " << C(2,1) << endl;
    cout << "C.dim(1) : " << C.dim(1) << endl;
    try {
        cout << C(10,10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "C(10,10) : Exception catched: " << e.what() << endl;
    }
}
