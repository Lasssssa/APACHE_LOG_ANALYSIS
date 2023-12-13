CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
EXE = prog
OBJ =  main.o LogManager.o Log.o ReferentData.o Stats.o Reader.o FonctionsAnnexe.o
GCC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) -o $(EXE) $(OBJ) $(CPPFLAGS)

main.o: main.cpp LogManager.cpp LogManager.h FonctionsAnnexe.cpp FonctionsAnnexe.h
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

FonctionsAnnexe.o: FonctionsAnnexe.cpp FonctionsAnnexe.h
	$(GCC) -c FonctionsAnnexe.cpp $(CPPFLAGS)

clean:
	rm -f $(EXE) $(OBJ)

