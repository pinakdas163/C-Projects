CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic

library: Media.o Book.o Film.o Periodical.o Video.o CardCatalog.o library.o 
	$(CXX) Media.o Book.o Film.o Periodical.o Video.o CardCatalog.o library.o -o library

library.o: library.cpp Media.h CardCatalog.h
	$(CXX) $(CXXFLAGS) library.cpp

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) Media.cpp

Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) Book.cpp

Film.o: Film.cpp Film.h
	$(CXX) $(CXXFLAGS) Film.cpp

Periodical.o: Periodical.cpp Periodical.h
	$(CXX) $(CXXFLAGS) Periodical.cpp

Video.o: Video.cpp Video.h
	$(CXX) $(CXXFLAGS) Video.cpp

CardCatalog.o: CardCatalog.cpp Media.h
	$(CXX) $(CXXFLAGS) CardCatalog.cpp

clean :
	rm library *.o
