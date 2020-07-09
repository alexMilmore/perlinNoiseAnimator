all: main.o imgGen.o
	g++ main.o imgGen.o \
	-o perlin.out -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main.o: src/main.cpp
	g++ -c src/main.cpp

imgGen.o: src/imgGen.cpp
	g++ -c src/imgGen.cpp

clean:
	rm perlin.out main.o imgGen.o

run:
	./perlin.out
