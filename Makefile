house: SVGdraw.o svg_house.o
	g++ SVGdraw.o svg_house.o -o house.out
SVGdraw.o: SVGdraw.cpp SVGdraw.h
	g++ -c SVGdraw.cpp
svg_house.o: svg_house.o SVGdraw.h
	g++ -c svg_house.cpp
clean:
	rm *.o house.out
#Also works:
#g++ svg_house.cpp SVGdraw.a
