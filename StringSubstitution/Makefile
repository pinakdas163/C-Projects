stringsub: main.o stringSub.o custStream.o
	g++ -o stringsub main.o stringSub.o custStream.o

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

stringSub.o: stringSub.cpp stringSub.h custStream.h
	g++ -c -g -std=c++11 stringSub.cpp

custStream.o: custStream.cpp custStream.h TrackingDeque.h
	g++ -c -g -std=c++11 custStream.cpp

clean:
	rm -f main.o stringSub.o custStream.o stringsub
