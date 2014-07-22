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
    //===========================================================================
    // allocate
    //===========================================================================


    cout << endl << "------------------- allocate -------------------" << endl;
    dfndarray::Array3D<double> G;
    cout << "G           : " << G << endl;
    G.allocate(4,2,3);
    cout << "G           : " << G << endl;
    try {
        G.allocate(4,2,3);
    } catch (dfndarray::DFArrayError& e) {
        cout << "G.allocate(4,2,3) : Exception catched: " << e.what() << endl;
    }

    G.fill(15.);
    cout << "G(2,1,1)    : " << G(2,1,1) << endl;


    //===========================================================================
    // resize
    //===========================================================================

    cout << endl << "-------------------- resize --------------------" << endl;
    dfndarray::Array3D<double> H(5,4,3);
    H.fill(h);

    cout << "H           : " << H << endl;
    cout << "values      : " 
         << H(0,0,0) << " " << H(3,2,1) <<  " " << H(4,3,2) << endl;

    H.resize(5,4,3);
    cout << "H           : " << H << endl;
    cout << "values      : " 
         << H(0,0,0) << " " << H(3,2,1) <<  " " << H(4,3,2) << endl;

    H.resize(3,5,4);
    cout << "H           : " << H << endl;
    cout << "values      : " 
         << H(0,0,0) << " " << H(2,0,3) <<  " " << H(2,4,3) << endl;

    H.resize(4,3,2);
    cout << "H           : " << H << endl;
    cout << "values      : " 
         << H(0,0,0) << " " << H(2,0,2) <<  " " << H(2,0,2) << endl;

    H.resize(5,4,3);
    cout << "H           : " << H << endl;
    cout << "values      : " 
         << H(0,0,0) << " " << H(2,0,0) << " " << H(2,0,1) << " " << H(4,3,2) << endl;
}
