GXX = gcc
FLAGS = -Wall -Werror -O3

SOURCES = vector.c pointer.c
OBJ_FILES = ${SOURCES:.c=.o}

all: vector pointer
	${GXX} ${FLAGS} ${OBJ_FILES} -o all.exe

vector: vector.c
	${GXX} ${FLAGS} -c $^

pointer: pointer.c
	${GXX} ${FLAGS} -c $^

clean:
	rm *.exe *.o