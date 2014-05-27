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
