All: compile run

compile:
	gcc -I ./include/ -o ./lib/Taktik.o -c ./src/Taktik.c
	gcc -I ./include/ -o ./lib/ATaktik.o -c ./src/ATaktik.c
	gcc -I ./include/ -o ./lib/Koloni.o -c ./src/Koloni.c
	gcc -I ./include/ -o ./lib/Uretim.o -c ./src/Uretim.c
	gcc -I ./include/ -o ./lib/AUretim.o -c ./src/AUretim.c
	gcc -I ./include/ -o ./lib/BTaktik.o -c ./src/BTaktik.c
	gcc -I ./include/ -o ./lib/Buretim.o -c ./src/Buretim.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./bin/Test ./lib/ATaktik.o ./lib/AUretim.o ./lib/BTaktik.o ./lib/Buretim.o ./lib/Koloni.o ./lib/Oyun.o ./lib/Taktik.o ./lib/Uretim.o ./src/Test.c 

run:
	./bin/Test