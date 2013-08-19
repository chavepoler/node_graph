#ifndef _NODE_STRUCT
#define _NODE_STRUCT

typedef struct node_lnk LINK;
typedef struct prop PROP;
typedef struct node NODE;

struct prop {
	int type;
	char *nme;
	union {
		char *c;
		int *n;
	}val;
	PROP *prev,*next;
};

struct node_lnk {
	NODE *adr;
	LINK *prev,*next;
};

struct node {
	int node_type;
	char *node_nme;
	PROP node_prop;
	PROP *s_prop;
	LINK node_prev;
	LINK node_next;
	LINK *t_prev;
	LINK *t_next;
};

#endif
