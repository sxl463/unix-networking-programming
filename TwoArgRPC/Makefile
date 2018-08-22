#include ../Make.defines

CC = clang
CFLAGS = -g -Wall
LIBS = ../libunpipc.a -lrt

LIBS_RPC = 
RANLIB = ranlib
RPCGEN_OPTS = -C
CLEANFILES =  *.o temp.* *.out typescript* \
		*.[234]c *.[234]h *~

PROGS =	client server

all:	${PROGS}

test.h test_clnt.c test_svc.c test_xdr.c:	test.x
			rpcgen -C test.x

test_clnt.o: test_clnt.c test.h

test_svc.o: test_svc.c test.h

client:	test.h client.o test_clnt.o test_xdr.o
			${CC} ${CFLAGS} -o $@ client.o test_clnt.o test_xdr.o \
				${LIBS} ${LIBS_RPC}

server:	test.h server.o test_svc.o test_xdr.o
			${CC} ${CFLAGS} -o $@ server.o test_svc.o test_xdr.o \
				${LIBS} ${LIBS_RPC}

clean:
		rm -f ${PROGS} ${CLEANFILES} *_clnt.c *_svc.c *_xdr.c test.h
