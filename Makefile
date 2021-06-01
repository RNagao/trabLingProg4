CPP = g++
CPPFLAGS = -Wall

TRABALHO4OBJS = main.o cadastro.o paciente.o pacienteMenor.o pacienteMaior.o

trabalho4: $(TRABALHO4OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(TRABALHO4OBJS)