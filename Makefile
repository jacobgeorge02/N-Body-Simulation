CC = g++
CFLAGS = -std=c++14 -Wall -Werror -pedantic
NB_OBJECTS = CelestialBody.o NBody.o Universe.o
HEADERS = CelestialBody.h Universe.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody

NBody: $(NB_OBJECTS)
	$(CC) $(CFLAGS) -o NBody $(NB_OBJECTS) $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm NBody *.o