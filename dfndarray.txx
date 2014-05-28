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
*/

#include <string.h>

#include "dfndarray.hxx"

using namespace std;

//===========================================================================
// Array 1D
//===========================================================================


// Constructors.
template <typename T>
Array1D<T>::Array1D(size_t n0):
    m_n0(n0),
    m_size(n0),
    m_data(NULL)
{
    m_dim[0] = n0;
    m_data = new T[n0];
}

template <typename T>
Array1D<T>::Array1D():
    m_n0(0),
    m_size(0),
    m_data(NULL)
{
    m_dim[0] = 0;
}

// Destructor.
template <typename T>
Array1D<T>::~Array1D()
{
    if (m_data) {
        delete[] m_data;
    }
}

// Initialization.
template <typename T>
void
Array1D<T>::allocate(size_t n0)
{
    DFA_ASSERT(m_data == NULL);
    m_n0 = n0;
    m_size = n0;
    m_dim[0] = n0;
    m_data = new T[n0];
}

template <typename T>
void
Array1D<T>::resize(size_t n0)
{
    DFA_ASSERT(m_data != NULL);

    m_n0 = n0;
    m_dim[0] = n0;

    size_t size = n0;
    if (size == m_size) 
        return;

    T* data = new T[n0];
    if (size < m_size) {
        memcpy(data, m_data, size*sizeof(T));
    } else {
        memcpy(data, m_data, m_size*sizeof(T));
        for (T* p = data+m_size+1 ; p < data+size ; p++) {
            *p = T();
        }
    }
    
    m_size = size;
    if (m_data) delete[] m_data;
    m_data = data;
}

// Fill function.
template <typename T>
void
Array1D<T>::fill(Array1DComputeValue* f)
{
    DFA_ASSERT(m_data != NULL);
    for (size_t i0 = 0 ; i0 < m_n0 ; i0++) {
        m_data[i0] = f->operator()(i0);
    }
}

template <typename T>
void
Array1D<T>::fill(T value)
{
    DFA_ASSERT(m_data != NULL);
    for (T* p = m_data ; p < m_data+m_size ; p++)
        *p = value;
}


//===========================================================================
// Array 2D
//===========================================================================


// Constructors.
template <typename T>
Array2D<T>::Array2D(size_t n0, size_t n1):
    m_n0(n0),
    m_n1(n1),
    m_size(n0*n1),
    m_data(NULL)
{
    m_dim[0] = n0;
    m_dim[1] = n1;
    m_data = new T[n0*n1];
}

template <typename T>
Array2D<T>::Array2D():
    m_n0(0),
    m_n1(0),
    m_size(0),
    m_data(NULL)
{
    m_dim[0] = 0;
    m_dim[1] = 0;
}

// Destructor.
template <typename T>
Array2D<T>::~Array2D()
{
    if (m_data) {
        delete[] m_data;
    }
}

// Initialization.
template <typename T>
void
Array2D<T>::allocate(size_t n0, size_t n1)
{
    DFA_ASSERT(m_data == NULL);
    m_n0 = n0;
    m_n1 = n1;
    m_size = n0*n1;
    m_dim[0] = n0;
    m_dim[1] = n1;
    m_data = new T[n0*n1];
}

template <typename T>
void
Array2D<T>::resize(size_t n0, size_t n1)
{
    DFA_ASSERT(m_data != NULL);

    m_n0 = n0;
    m_n1 = n1;
    m_dim[0] = n0;
    m_dim[1] = n1;

    size_t size = n0*n1;
    if (size == m_size) 
        return;

    T* data = new T[n0*n1];
    if (size < m_size) {
        memcpy(data, m_data, size*sizeof(T));
    } else {
        memcpy(data, m_data, m_size*sizeof(T));
        for (T* p = data+m_size+1 ; p < data+size ; p++) {
            *p = T();
        }
    }
    
    m_size = size;
    if (m_data) delete[] m_data;
    m_data = data;
}

// Fill function.
template <typename T>
void
Array2D<T>::fill(Array2DComputeValue* f)
{
    DFA_ASSERT(m_data != NULL);
    size_t s0;
    for (size_t i0 = 0 ; i0 < m_n0 ; i0++) {
        s0 = i0*m_n1;
        for (size_t i1 = 0 ; i1 < m_n1 ; i1++) {
            m_data[s0 + i1] = f->operator()(i0,i1);
        }
    }
}

template <typename T>
void
Array2D<T>::fill(T value)
{
    DFA_ASSERT(m_data != NULL);
    for (T* p = m_data ; p < m_data+m_size ; p++)
        *p = value;
}


//===========================================================================
// Array 3D
//===========================================================================


// Constructors.
template <typename T>
Array3D<T>::Array3D(size_t n0, size_t n1, size_t n2):
    m_n0(n0),
    m_n1(n1),
    m_n2(n2),
    m_n1n2(n1*n2),
    m_size(n0*n1*n2),
    m_data(NULL)
{
    m_dim[0] = n0;
    m_dim[1] = n1;
    m_dim[2] = n2;
    m_data = new T[n0*n1*n2];
}

template <typename T>
Array3D<T>::Array3D():
    m_n0(0),
    m_n1(0),
    m_n2(0),
    m_n1n2(0),
    m_size(0),
    m_data(NULL)
{
    m_dim[0] = 0;
    m_dim[1] = 0;
    m_dim[2] = 0;
}

// Destructor.
template <typename T>
Array3D<T>::~Array3D()
{
    if (m_data) {
        delete[] m_data;
    }
}

// Initialization.
template <typename T>
void
Array3D<T>::allocate(size_t n0, size_t n1, size_t n2)
{
    DFA_ASSERT(m_data == NULL);
    m_n0 = n0;
    m_n1 = n1;
    m_n2 = n2;
    m_n1n2 = n1*n2;
    m_size = n0*n1*n2;
    m_dim[0] = n0;
    m_dim[1] = n1;
    m_dim[2] = n2;
    m_data = new T[n0*n1*n2];
}

template <typename T>
void
Array3D<T>::resize(size_t n0, size_t n1, size_t n2)
{
    DFA_ASSERT(m_data != NULL);

    m_n0 = n0;
    m_n1 = n1;
    m_n2 = n2;
    m_n1n2 = n1*n2;
    m_dim[0] = n0;
    m_dim[1] = n1;
    m_dim[2] = n2;

    size_t size = n0*n1*n2;
    if (size == m_size) 
        return;

    T* data = new T[n0*n1*n2];
    if (size < m_size) {
        memcpy(data, m_data, size*sizeof(T));
    } else {
        memcpy(data, m_data, m_size*sizeof(T));
        for (T* p = data+m_size+1 ; p < data+size ; p++) {
            *p = T();
        }
    }
    
    m_size = size;
    if (m_data) delete[] m_data;
    m_data = data;
}

// Fill function.
template <typename T>
void
Array3D<T>::fill(Array3DComputeValue* f)
{
    DFA_ASSERT(m_data != NULL);
    size_t s0,s1;
    for (size_t i0 = 0 ; i0 < m_n0 ; i0++) {
        s0 = i0*m_n1n2;
        for (size_t i1 = 0 ; i1 < m_n1 ; i1++) {
            s1 = i1*m_n2;
            for (size_t i2 = 0 ; i2 < m_n2 ; i2++) {
                m_data[s0 + s1 + i2] = f->operator()(i0,i1,i2);
            }
        }
    }
}

template <typename T>
void
Array3D<T>::fill(T value)
{
    DFA_ASSERT(m_data != NULL);
    for (T* p = m_data ; p < m_data+m_size ; p++)
        *p = value;
}
