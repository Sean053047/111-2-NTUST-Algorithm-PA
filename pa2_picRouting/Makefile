CC=g++
LDFLAGS=-std=c++11 -O3 -lm
SOURCES=./lib/Dijkstra.cpp ./lib/utils.cpp ./main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
INCLUDES=./header/*.h

all: $(SOURCES) ./$(EXECUTABLE)

./$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./$(EXECUTABLE)
