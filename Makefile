main: main.o dfndarray.o dfndarray.hxx dfndarray.txx
	g++ -g -o $@ main.o dfndarray.o

%.o: %.cxx
	g++ -g -c $<

test: main
	./main

clean:
	rm -f main *.o
