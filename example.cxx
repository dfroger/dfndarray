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
}
