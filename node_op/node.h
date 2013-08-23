#include "struct.h"

extern int init_node(NODE*, int, char*);
	//node to be inited
	//node type (int)
	//node name (char)

extern int add_prop(NODE*, char*, char*, int*);
	//node to be add a prop
	//prop name
	//prop value (char)
	//prop value (int)

extern int edt_prop(NODE*, char*, char*, int*);

extern int del_prop(NODE*, char*);

extern int add_link(NODE*, int, NODE*);

extern int del_link(NODE*, int, NODE*);

extern int dsp_node(NODE*);
