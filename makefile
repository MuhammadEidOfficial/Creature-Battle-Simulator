all: derle calistir

derle:
	gcc -I ./include/ -c ./src/Canli.c -o ./lib/Canli.o
	gcc -I ./include/ -c ./src/Bitki.c -o ./lib/Bitki.o
	gcc -I ./include/ -c ./src/Bocek.c -o ./lib/Bocek.o
	gcc -I ./include/ -c ./src/Pire.c -o ./lib/Pire.o
	gcc -I ./include/ -c ./src/Sinek.c -o ./lib/Sinek.o
	gcc -I ./include/ -c ./src/Habitat.c -o ./lib/Habitat.o
	
	gcc -I ./include/ -c ./src/Test.c -o ./lib/Test.o
	gcc -o ./bin/program ./lib/Canli.o ./lib/Bitki.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Habitat.o ./lib/Test.o

calistir:
	./bin/program
