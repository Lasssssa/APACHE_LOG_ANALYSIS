CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
EXE = prog
OBJ =  main.o LogManager.o Log.o ReferentData.o Stats.o
GCC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) -o $(EXE) $(OBJ) $(CPPFLAGS)

main.o: main.cpp
	$(GCC) -c main.cpp $(CPPFLAGS)

LogManager.o: LogManager.cpp LogManager.h
	$(GCC) -c LogManager.cpp $(CPPFLAGS)

Log.o: Log.cpp Log.h
	$(GCC) -c Log.cpp $(CPPFLAGS)

ReferentData.o: ReferentData.cpp ReferentData.h
	$(GCC) -c ReferentData.cpp $(CPPFLAGS)

Stats.o: Stats.cpp Stats.h
	$(GCC) -c Stats.cpp $(CPPFLAGS)

clean:
	rm -f $(EXE) $(OBJ)

