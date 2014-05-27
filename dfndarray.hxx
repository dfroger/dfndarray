#ifndef DFNDARRAY_HXX_INCLUDED
#define DFNDARRAY_HXX_INCLUDED

#include <iostream>
#include <assert.h>

// Error management macro, deactivated with NDEBUG preprocessor macro.
#ifdef NDEBUG
#define DFA_ASSERT(test)
#define DFA_ASSERT_EQUAL(a,b)
#define DFA_ASSERT_LT(a,b)
#else
#define DFA_ASSERT(test)  if (!(test)) dfa_assert(#test,__FILE__,__LINE__);
#define DFA_ASSERT_EQUAL(a,b)  dfa_assert_equal(#a,#b,a,b,__FILE__,__LINE__);
#define DFA_ASSERT_LT(a,b)  dfa_assert_lt(#a,#b,a,b,__FILE__,__LINE__);
#endif


namespace dfndarray {


//===========================================================================
// Error management.
//===========================================================================


// Exception.
class DFArrayError: public std::exception {
public:
  DFArrayError();
  DFArrayError(const char * str,const char * file,int line);
  virtual ~DFArrayError() throw() {}
  virtual const char* what() const throw();
private:
  char *str_;
};

// Assert functions.
void
dfa_assert(const char* expr,const char* file,int line);

void
dfa_assert_equal(const char* expr_a, const char* expr_b, size_t a, size_t b, 
                 const char* file, int line);

void
dfa_assert_lt(const char* expr_a, const char* expr_b, size_t a, size_t b,
              const char* file, int line);


//===========================================================================
// Array 1D
//===========================================================================


// Base functor class to set array value from index.
class Array1DComputeValue
{
    public:
        virtual double operator() (size_t i0) = 0;
};

// Usefull functor for tests.
class Array1DComputeTestValue: public Array1DComputeValue
{
    public:
        virtual double operator() (size_t i0){return i0;};
};


template <typename T>
class Array1D
{
    public:
        Array1D();
        Array1D(size_t n0);
        ~Array1D();

        friend std::ostream& operator<<(std::ostream& o, Array1D<T> const& array1d)
        {
            if (array1d.m_data) {
                o << "<Array1d of shape (" << array1d.m_n0 << ")>";
            } else {
                o << "<Array1d not allocated>";
            }
            return o;
        }

        inline T operator()(size_t i0) const
        {
            DFA_ASSERT(m_data != NULL);
            DFA_ASSERT_LT(i0,m_n0);
            return m_data[i0];
        }

        void fill(Array1DComputeValue* f);

        size_t dim(size_t idim)
        {
            DFA_ASSERT_LT(idim,1);
            return m_dim[idim];
        };

        inline size_t n0() const
        {
            DFA_ASSERT(m_data != NULL);
            return m_n0;
        }

        inline T* data() const {
            DFA_ASSERT(m_data != NULL);
            return m_data;
        }

    private:
        size_t m_n0;
        size_t m_dim[1];
        T* m_data;
};


//===========================================================================
// Array 2D
//===========================================================================


// Base functor class to set array value from index.
class Array2DComputeValue
{
    public:
        virtual double operator() (size_t i0, size_t i1) = 0;
};

// Usefull functor for tests.
class Array2DComputeTestValue: public Array2DComputeValue
{
    public:
        virtual double operator() (size_t i0, size_t i1){return i0*10. + i1;};
};


template <typename T>
class Array2D
{
    public:
        Array2D();
        Array2D(size_t n0, size_t n1);
        ~Array2D();

        friend std::ostream& operator<<(std::ostream& o, Array2D<T> const& array2d)
        {
            if (array2d.m_data) {
                o << "<Array2d of shape (" << array2d.m_n0 << "," << array2d.m_n1 << ")>";
            } else {
                o << "<Array2d not allocated>";
            }
            return o;
        }

        inline T operator()(size_t i0, size_t i1) const
        {
            DFA_ASSERT(m_data != NULL);
            DFA_ASSERT_LT(i0,m_n0);
            DFA_ASSERT_LT(i1,m_n1);
            return m_data[i0*m_n1 + i1];
        }

        void fill(Array2DComputeValue* f);

        size_t dim(size_t idim)
        {
            DFA_ASSERT_LT(idim,2);
            return m_dim[idim];
        };

        inline size_t n0() const
        {
            DFA_ASSERT(m_data != NULL);
            return m_n0;
        }

        inline size_t n1() const {
            DFA_ASSERT(m_data != NULL);
            return m_n1;
        }

        inline T* data() const {
            DFA_ASSERT(m_data != NULL);
            return m_data;
        }

    private:
        size_t m_n0;
        size_t m_n1;
        size_t m_dim[2];
        T* m_data;
};

#include "dfndarray.txx"

}

#endif
