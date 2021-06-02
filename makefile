OS = $(shell uname -s)

CC = gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALETO=ansi
CFLAGS = -Wall -ansi
LFLAGS = -Wall

ifeq ($(dialeto), C99)
DIALETO = c99
CFLAGS = -Wall -std=c99
endif

ifeq ($(dialeto), C11)
DIALETO = c11
CFLAGS = -Wall -std=c11
endif

EXEMPLO001OBJS = exemplo_001.o
EXEMPLO002OBJS = exemplo_002.o
EXEMPLO003OBJS = exemplo_003.o
EXEMPLO004OBJS = exemplo_004.o
EXEMPLO005OBJS = exemplo_005.o
EXEMPLO006OBJS = exemplo_006.o
EXEMPLO007OBJS = exemplo_007.o
EXEMPLO008OBJS = exemplo_008.o
EXEMPLO009OBJS = exemplo_009.o
EXEMPLO010OBJS = exemplo_010.o
EXEMPLO011OBJS = exemplo_011.o
EXEMPLO012OBJS = exemplo_012.o
EXEMPLO013OBJS = exemplo_013.o
EXEMPLO014OBJS = exemplo_014.o
EXEMPLO015OBJS = exemplo_015.o
EXEMPLO016OBJS = exemplo_016.o
EXEMPLO017OBJS = exemplo_017.o
EXEMPLO018OBJS = exemplo_018.o
EXEMPLO020AOBJS = exemplo_019a.o exemplo_020.o
EXEMPLO020BOBJS = exemplo_019b.o exemplo_020.o
EXEMPLO020COBJS = exemplo_019c.o exemplo_020.o
EXEMPLO020DOBJS = exemplo_019d.o exemplo_020.o
EXEMPLO021OBJS = exemplo_021.o
EXEMPLO022OBJS = exemplo_022.o
EXEMPLO023OBJS = exemplo_023.o
EXEMPLO024OBJS = exemplo_024.o
EXEMPLO025OBJS = exemplo_025.o
EXEMPLO027OBJS = exemplo_026.o exemplo_027.o

EXECS = exemplo_001\
				exemplo_002\
				exemplo_003\
				exemplo_004\
				exemplo_005\
				exemplo_006\
				exemplo_007\
				exemplo_009\
				exemplo_010\
				exemplo_011\
				exemplo_012\
				exemplo_013\
				exemplo_014\
				exemplo_015\
				exemplo_016\
				exemplo_017\
				exemplo_018\
				exemplo_020a\
				exemplo_020b\
				exemplo_020c\
				exemplo_020d\
				exemplo_021\
				exemplo_022\
				exemplo_023\
				exemplo_024\
				exemplo_025\
				exemplo_027

LIBS =

ALL = $(EXECS) $(LIBS)

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

exemplo_001: $(EXEMPLO001OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO001OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_002: $(EXEMPLO002OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO002OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_003: $(EXEMPLO003OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO003OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_004: $(EXEMPLO004OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO004OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_005: $(EXEMPLO005OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO005OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_006: $(EXEMPLO006OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO006OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_007: $(EXEMPLO007OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO007OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_008: $(EXEMPLO008OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO008OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_009: $(EXEMPLO009OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO009OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_010: $(EXEMPLO010OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO010OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_011: $(EXEMPLO011OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO011OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_012: $(EXEMPLO012OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO012OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_013: $(EXEMPLO013OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO013OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_014: $(EXEMPLO014OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO014OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_015: $(EXEMPLO015OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO015OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_016: $(EXEMPLO016OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO016OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_017: $(EXEMPLO017OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO017OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_018: $(EXEMPLO018OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO018OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_020a: $(EXEMPLO020AOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO020AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_020b: $(EXEMPLO020BOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO020BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_020c: $(EXEMPLO020COBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO020COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_020d: $(EXEMPLO020DOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO020DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_021: $(EXEMPLO021OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO021OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_022: $(EXEMPLO022OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO022OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_023: $(EXEMPLO023OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO023OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_024: $(EXEMPLO024OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO024OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_025: $(EXEMPLO025OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO025OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

exemplo_027: $(EXEMPLO027OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXEMPLO027OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALETO)

.PHONY: clean clean-all clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c99 clean-c11

clean:
	rm -f *.o $(ALL)

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-*

clean-bsd:
	rm -f *.o $(ALL) *-FreeBSD-*

clean-linux:
	rm -f *.o $(ALL) *-Linux-*

clean-gcc:
	rm -f *.o $(ALL) *-gcc-*

clean-clang:
	rm -f *.o $(ALL) *-clang-*

clean-ansi:
	rm -f *.o $(ALL) *-ansi

clean-c99:
	rm -f *.o $(ALL) *-c99

clean-c11:
	rm -f *.o $(ALL) *-c11