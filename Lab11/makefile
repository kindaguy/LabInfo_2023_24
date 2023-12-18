solEs1.o: solEs1.C
	g++ -c solEs1.C

libMyArrayInt.o: ../Librerie/libMyArrayInt.C ../Librerie/libMyArrayInt.h
	g++ -c libMyArrayInt.C

solEs1.x: solEs1.o libMyArrayInt.o 
	g++ solEs1.o libMyArrayInt.o -o solEs1.x

compila: solEs1.x

esegui: compila
	./solEs1.x
