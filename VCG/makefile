CC=clang++
RM=rm -f 
LIBS=-liostream -lctime -lcstdlib -lstring -lfstream

VCG: bin/main.o
	$(CC) -o bin/VCG bin/main.o
	
bin/main.o: 
	$(CC) -c src/main/cpp/main.cpp -o bin/main.o
