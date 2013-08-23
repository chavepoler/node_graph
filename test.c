#include "node_op/node.h"

int main(int c, char **argv)
{
	NODE pp[3];
	int i;
	for(i=0;i<3;i++) init_node(pp+i,-1,"A");
	//need a flag to echo whether or not a node had been initized
	//to control the access to uninitial node
	//(add_link,dsp_node,del_link,etc)
	//
	//every node need a unique number to specify the init status
	//to be compared with a number list(inc list)
	//to add a necessary col to a node !(no. type etc..
	add_link(pp,0,pp+2);
	add_link(pp,0,pp+1);
	add_link(pp+1,0,pp+2);
	for(i=0;i<3;i++) dsp_node(pp+i);
	return 0;
}
