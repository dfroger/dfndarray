#include "dfndarray.hxx"

#include <iostream>

using namespace std;

int main()
{
    dfndarray::Array2D<double> A(4,2);
    dfndarray::Array2DComputeValue* f = new dfndarray::Array2DComputeTestValue();
    A.fill(f);

    dfndarray::Array2D<double> B;

    cout << "B        : " << B << endl;
    try {
        cout << B(1,1) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "B(1,1)   : Exception catched: " << e.what() << endl;
    }
    cout << "A        : " << A << endl;
    cout << "A(2,1)   : " << A(2,1) << endl;
    cout << "A.dim(1) : " << A.dim(1) << endl;
    try {
        cout << A(10,10) << endl;
    } catch (dfndarray::DFArrayError& e) {
        cout << "A(10,10) : Exception catched: " << e.what() << endl;
    }
}
