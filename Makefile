node : test.o node.o
	g++ -o node test.o node.o node_i.o
	echo "Successfully build executitive file"
	./node

test.o : test.c node.h
	g++ -c test.c

node.o : node.c node.h
	g++ -c node.c

node_i.o : node_i.c node_i.h
	g++ -c node_i.c
clean : 
	rm test.o node.o node_i.o
