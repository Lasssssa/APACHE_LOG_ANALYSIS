CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
EXE = prog
OBJ =  main.o LogManager.o Log.o ReferentData.o Stats.o Reader.o Utils.o
GCC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) -o $(EXE) $(OBJ) $(CPPFLAGS)

main.o: main.cpp LogManager.cpp LogManager.h Utils.cpp Utils.h
	$(GCC) -c main.cpp $(CPPFLAGS)

Log.o: Log.cpp Log.h
	$(GCC) -c Log.cpp $(CPPFLAGS)

ReferentData.o: ReferentData.cpp ReferentData.h
	$(GCC) -c ReferentData.cpp $(CPPFLAGS)

Stats.o: Stats.cpp Stats.h ReferentData.cpp ReferentData.h Log.cpp Log.h
	$(GCC) -c Stats.cpp $(CPPFLAGS)

Reader.o: Reader.cpp Reader.h Log.cpp Log.h
	$(GCC) -c Reader.cpp $(CPPFLAGS)

LogManager.o: LogManager.cpp LogManager.h Reader.cpp Reader.h Stats.cpp Stats.h
	$(GCC) -c LogManager.cpp $(CPPFLAGS)

Utils.o: Utils.cpp Utils.h
	$(GCC) -c Utils.cpp $(CPPFLAGS)

run:
	make clean
	make

valgrind:
	make clean
	make
	valgrind --leak-check=full ./$(EXE) -t 12 -e -g test.dot exemple-mini-non-exhaustif.log

clean:
	rm -f $(EXE) $(OBJ)

