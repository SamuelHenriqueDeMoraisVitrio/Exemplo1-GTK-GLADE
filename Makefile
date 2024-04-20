COMP = gcc
OPC = -Wall -std=c99
GTK = `pkg-config --cflags --libs gtk+-3.0`
NOME = EXE
START = echo "" && echo "Compilação concluida. Iniciando..." && echo "" && echo "" && ./$(NOME)

nome: clear
	$(COMP) $(OPC) -o $(NOME) *.c $(GTK)
	@$(START)

compile: clear
	$(COMP) $(OPC) -o $(NOME) *.c $(GTK)

clear:
	rm -f EXE
	clear

start:
	@$(START)
