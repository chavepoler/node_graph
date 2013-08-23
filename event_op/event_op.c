#include "../node_op/node.h"

int init();
int insert_event();
int del_event();
int new_events(){
	node meta_node;
	init_node(&meta_node,-1,events_name);
	cnode=&meta_node;
	add_prop(cnode,"type",type);
	add_prop(cnode,"event counter",0);
	add_prop(cnode,"created time",current_time);
	add_prop(cnode,"modified time",current_time);
	add_prop(cnode,"accessed time",current_time);
	add_prop(cnode,"emblems",0);
	add_prop(cnode,"owner",current_user);
	add_prop(cnode,"group",current_group);
	add_prop(cnode,"permission",0);
	add_prop(cnode,"note",note);
	add_link
