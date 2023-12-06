CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
EXE = prog
OBJ =  main.o Stats.o Log.o
GCC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) -o $(EXE) $(OBJ) $(CPPFLAGS)

main.o: main.cpp
	$(GCC) -c main.cpp $(CPPFLAGS)

Log.o: Log.h Log.cpp
	$(GCC) -c Log.cpp $(CPPFLAGS)

Stats.o: Stats.h Stats.cpp
	$(GCC) -c Stats.cpp $(CPPFLAGS)

clean:
	rm -f $(EXE) $(OBJ)

