node : test.o node.o node_i.o
	g++ -o node test.o node.o node_i.o
	echo "\nSuccessfully build executitive file\n"
	./node
	make clean

test.o : test.c node_op/node.h
	g++ -c test.c

node.o : node_op/node.c node_op/node.h
	g++ -c node_op/node.c

node_i.o : node_op/node_i.c node_op/node_i.h
	g++ -c node_op/node_i.c
clean : 
	rm test.o node.o node_i.o
