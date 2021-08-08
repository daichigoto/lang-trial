SRCS!=	ls *.c
OBJS=	${SRCS:.c=.o}
CMDS=	${SRCS:.c=}

CFLAGS+=-g

CC=	clang

build: ${OBJS}

.c.o:
	${CC} -c $< -o $@
	${CC} ${CFLAGS} -o ${@:.o=} $@

clean:
	rm -f ${OBJS}
	rm -f ${CMDS}
