CC = g++
CFLAGS = 

SRC = tree.cpp mechanics.cpp test-tree.cpp
OBJ = ${SRC:.cpp=.o}

all: tree

.cpp.o:
	${CC} -c ${CFLAGS} $<

tree: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ}
