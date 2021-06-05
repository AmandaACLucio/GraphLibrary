CC=gcc
CFLAGS=-O8
PROGRAMS = Interface GraphLibraryTP2 GraphLibraryTP1 FuncoesAuxiliares Estrutura_de_dados/Estrutura_de_dados Estrutura_de_dados/Lista_adjacencia Estrutura_de_dados/Matriz_adjacencia Estrutura_de_dados/Vetor_adjacencia

all: ${PROGRAMS}

%.o: %.c
    $(CC) $(CFLAGS) -c $<

%: %.o
    $(CC) $(CFLAGS) -o $* $<

clean:
    rm -f ${PROGRAMS} ${PROGRAMS:=.o}