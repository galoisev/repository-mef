CC=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=mon_executable
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

mon_executable: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	
#main.o: mesh.h matrix.h
	
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
	

exe:
	./$(EXEC)
	@echo " Compilation, et execution: 	OK !"
	
	
clean:
	rm -f *.o core
	
mrproper: clean
	rm -f $(EXEC)
	@echo " Suppressions fichiers *.o et executable:	 OK !"

cls:
	clear
	@echo " Effacage ecran !"
