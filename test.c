#include "node.h"

int main(int c, char **argv)
{
	NODE pp;
	init_node(&pp,-1,"sssss");
	add_link(&pp,0,&pp);
	add_link(&pp,0,&pp);
	dsp_node(&pp);
	del_link(&pp,0,&pp);
	dsp_node(&pp);
	return 0;
}
