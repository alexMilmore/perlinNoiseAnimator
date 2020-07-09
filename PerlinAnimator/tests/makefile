SOURCES = ../src/vector2.cpp vector2Test.cpp
OBJECTS = vector2.o vector2Test.o

vector2Test: $(OBJECTS)
	g++ $(OBJECTS) -o vector2Test.out

$(OBJECTS): $(SOURCES)
	g++ -c $(SOURCES)

vector2Clean:
	chmod -x vector2Test.out
	rm $(OBJECTS) vector2Test.out
