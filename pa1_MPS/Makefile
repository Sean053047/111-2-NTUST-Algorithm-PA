CC=g++
LDFLAGS=-std=c++11 -O3 -lm
SOURCES=./lib/MPS.cpp ./lib/utils.cpp ./main.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main
INCLUDES=./header/utils.h ./header/MPS.h

all: $(SOURCES) ./$(EXECUTABLE)

./$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./$(EXECUTABLE)
