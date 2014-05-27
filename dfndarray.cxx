#include <string.h>
#include <sstream>

#include "dfndarray.hxx"

using namespace std;

namespace dfndarray {

DFArrayError::DFArrayError():
  str_(NULL)
{
}

DFArrayError::DFArrayError(const char * str,const char * file,int line):
  str_(NULL)
{
  ostringstream msg;
  msg << file << ":" << line << ": " << str ;
  msg.flush();
  str_ = new char[ strlen( msg.str().c_str() )+1 ];
  strcpy(str_, msg.str().c_str() );
}

const char*
DFArrayError::what() const throw()
{
  return str_;
}

void
dfa_assert(const char * expr,const char * file,int line)
{
  ostringstream stream;
  stream << "assertion '" << expr << "' failed.";
  DFArrayError err(stream.str().c_str(),file,line);
  throw err;
}

void
dfa_assert_equal(const char* expr_a, const char* expr_b, size_t a, size_t b,
                 const char * file,int line)
{
  if (a!=b) {
    ostringstream stream;
    stream << "expected '" << expr_a << " == " << expr_b << "'"
           << ", but got: '" << a << " != " << b << "'.";
    DFArrayError err(stream.str().c_str(),file,line);
    throw err;
  }
}

void
dfa_assert_lt(const char* expr_a, const char* expr_b, size_t a, size_t b,
              const char * file,int line)
{
  if (a>=b) {
    ostringstream stream;
    stream << "expected '" << expr_a << " < " << expr_b << "'"
           << ", but got: '" << a << " >= " << b << "'.";
    DFArrayError err(stream.str().c_str(),file,line);
    throw err;
  }
}

}
