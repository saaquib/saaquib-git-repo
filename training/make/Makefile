C=gcc
FILE = app 1.o 2.o

app : 1.o 2.o
	$C -o $(FILE)

1.o : 1.c
	$C -c 1.c

2.o : 2.c
	$C -c 2.c

clean :
	rm -f *.o

