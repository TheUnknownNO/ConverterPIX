CXX=gcc
CXXFLAGS=-c -g -w -static -I./
LDFLAGS=-ldl -lpthread -static
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../libs/libzlib.a

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -Rf $(OBJECTS) $(EXECUTABLE)
