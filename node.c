#include "node.h"
#include "node_i.h"

extern int init_node(NODE* node, int type, char* nme) {
	return _init_node(node,type,nme);
}

extern int add_prop(NODE* node, char* nme, char* val_c, int* val_n) {
	return _add_prop(node,nme,val_c,val_n);
}

extern int edt_prop(NODE* node, char* nme, char* val_c, int* val_n) {
	return _edt_prop(node,nme,val_c,val_n);
}

extern int del_prop(NODE* node, char* nme) {
	return _del_prop(node,nme);
}

extern int add_link(NODE* node, int sel, NODE* dst_node) {
	return _add_link(node,sel,dst_node);
}

extern int del_link(NODE* node, int sel, NODE* dst_node) {
	return _del_link(node,sel,dst_node);
}

extern int dsp_node(NODE* node) {
	return _dsp_node(node);
}
