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
    cout << "B            : " << B << endl;
    try {
        cout << B(1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "B(1)         : Exception catched: " << e.what() << endl;
    }
    cout << "A            : " << A << endl;
    cout << "A(1)         : " << A(1) << endl;
    cout << "A.dim(0)     : " << A.dim(0) << endl;
    try {
        cout << A(10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "A(10)        : Exception catched: " << e.what() << endl;
    }


    //===========================================================================
    // Array 2D
    //===========================================================================


    dfndarray::Array2D<double> C(4,2);
    dfndarray::Array2DComputeValue* g = new dfndarray::Array2DComputeTestValue();
    C.fill(g);

    dfndarray::Array2D<double> D;

    cout << endl << "------------------- Array 2D -------------------" << endl;
    cout << "D            : " << D << endl;
    try {
        cout << D(1,1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "D(1,1)       : Exception catched: " << e.what() << endl;
    }
    cout << "C            : " << C << endl;
    cout << "C(2,1)       : " << C(2,1) << endl;
    cout << "C.dim(1)     : " << C.dim(1) << endl;
    try {
        cout << C(10,10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "C(10,10)     : Exception catched: " << e.what() << endl;
    }


    //===========================================================================
    // Array 3D
    //===========================================================================


    dfndarray::Array3D<double> E(4,2,3);
    dfndarray::Array3DComputeValue* h = new dfndarray::Array3DComputeTestValue();
    E.fill(h);

    dfndarray::Array3D<double> F;

    cout << endl << "------------------- Array 3D -------------------" << endl;
    cout << "F           : " << F << endl;
    try {
        cout << F(1,1,1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "F(1,1,1)    : Exception catched: " << e.what() << endl;
    }
    cout << "E           : " << E << endl;
    cout << "E(2,1,1)    : " << E(2,1,1) << endl;
    cout << "E.dim(1)    : " << E.dim(1) << endl;
    try {
        cout << E(10,10,10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "E(10,10,10) : Exception catched: " << e.what() << endl;
    }
}
