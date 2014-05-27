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
#include <sstream>

#include "dfndarray.hxx"

using namespace std;

namespace dfndarray {


//===========================================================================
// Error management.
//===========================================================================


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
