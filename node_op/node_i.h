#include "struct.h"

extern int _init_node(NODE*, int, char*);

extern int _add_prop(NODE*, char*, char*, int*);

extern int _edt_prop(NODE*, char*, char*, int*);

extern int _del_prop(NODE*, char*);

extern int _add_link(NODE*, int, NODE*);

extern int _del_link(NODE*, int, NODE*);

extern int _dsp_node(NODE*);

extern int err(int);

extern int dsp_prop(NODE*);

extern int dsp_link(NODE*);

