# Project: gofish
# Makefile created by Dev-C++ 4.9.9.2
# Modified by jwebb

CPP  = g++
RES  =
OBJ  = main.o $(RES)
LINKOBJ  = main.o $(RES)
BIN  = cheaters
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f


all: cheaters

clean:
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o cheaters $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

