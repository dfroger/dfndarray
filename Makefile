main: main.o array2d.o array2d.hxx array2d.txx
	g++ -g -o $@ main.o array2d.o

%.o: %.cxx
	g++ -g -c $<

test: main
	./main

clean:
	rm -f main *.o
