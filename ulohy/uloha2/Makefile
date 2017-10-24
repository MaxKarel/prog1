main: SVGdraw.o main.o
	g++ SVGdraw.o main.o -o main.out
SVGdraw.o: ../../SVGdraw.cpp ../../SVGdraw.h
	g++ -c ../../SVGdraw.cpp
main.o: main.cpp ../../SVGdraw.h
	g++ -c -I../../ main.cpp
clean:
	rm *.o main.out *.svg
