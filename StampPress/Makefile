
test_stamp: test_stamp.o stamp.o stampbuf.o stampstream.o
	g++ -o test_stamp test_stamp.o stamp.o stampbuf.o stampstream.o

test_stamp.o: test_stamp.cpp stamp.h stampstream.h
	g++ -c test_stamp.cpp

Stamp.o: stamp.cpp stamp.h
	g++ -c -g stamp.cpp

Stampbuffer.o: stampbuf.cpp stampbuf.h stamp.h
	g++ -c -g stampbuffer.cpp

Stampstream.o: stampstream.cpp stampstream.h stampbuf.h
	g++ -c -g stampstream.cpp

clean:
	rm -f test_stamp.o stamp.o stampbuf.o stampstream.o test_stamp
