prog.o: prog.C
	g++ -c prog.C

libMyArraySfera.o: libMyArraySfera.C libMyArraySfera.h
	g++ -c libMyArraySfera.C

sfera.o: sfera.C sfera.h
	g++ -c sfera.C


libSorting.o: libSorting.C libSorting.h
	g++ -c libSorting.C

prog.x: sfera.o libMyArraySfera.o prog.o libSorting.o 
	g++ sfera.o libMyArraySfera.o  libSorting.o prog.o -o prog.x


compila: prog.x

esegui: compila
	./prog.x
