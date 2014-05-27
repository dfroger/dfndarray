#include "dfndarray.hxx"

using namespace std;

//===========================================================================
// Array 1D
//===========================================================================


// Constructors.
template <typename T>
Array1D<T>::Array1D(size_t n0):
    m_n0(n0),
    m_data(NULL)
{
    m_dim[0] = n0;
    m_data = new T[n0];
}

template <typename T>
Array1D<T>::Array1D():
    m_n0(0),
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


//===========================================================================
// Array 2D
//===========================================================================


// Constructors.
template <typename T>
Array2D<T>::Array2D(size_t n0, size_t n1):
    m_n0(n0),
    m_n1(n1),
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
