#Copyright 2014 David Froger

#This file is part of dfndarray.

#dfndarray is free software: you can redistribute it and/or modify it under the
#terms of the GNU General Public License as published by the Free Software
#Foundation, either version 3 of the License, or (at your option) any later
#version.

#dfndarray is distributed in the hope that it will be useful, but WITHOUT ANY
#WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
#PARTICULAR PURPOSE.  See the GNU General Public License for more details.

#You should have received a copy of the GNU General Public License along with
#dfndarray.  If not, see <http://www.gnu.org/licenses/>.

default: test.x example.x

test.x: test.o dfndarray.o dfndarray.hxx dfndarray.txx
	g++ -g -o $@ test.o dfndarray.o

example.x: example.o dfndarray.o dfndarray.hxx dfndarray.txx
	g++ -g -o $@ example.o dfndarray.o

%.o: %.cxx
	g++ -g -c $<

test: test.x
	./test.x

clean:
	rm -f *.x *.o
