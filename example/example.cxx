/*
Copyright 2014 David Froger

This file is part of dfndarray.

dfndarray is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

dfndarray is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
dfndarray.  If not, see <http://www.gnu.org/licenses/>.

Home page: https://github.com/dfroger/dfndarray
*/

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
