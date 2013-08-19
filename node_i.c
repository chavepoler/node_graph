#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_i.h"

int _dsp_node(NODE *node) {
	printf("type:\t%d\n",node->node_type);
	printf("name:\t%s\n",node->node_nme);
	dsp_prop(node);
	dsp_link(node);
	printf("\n");
	return 0;
}

int dsp_link(NODE *node) {
	LINK *p=&(node->node_prev);
	printf("prev node:\n");
	while((p=p->next))
		printf("\tadress:0x%lx\tname:%s\n",(long)p->adr,p->adr->node_nme);
	p=&(node->node_next);
	printf("next node:\n");
	while((p=p->next))
		printf("\tadress:0x%lx\tname:%s\n",(long)p->adr,p->adr->node_nme);
	return 1;
}

int dsp_prop(NODE *node) {
	PROP *p=&(node->node_prop),*s=p;
	printf("property:\n");
	while((p=p->next)!=s)
		switch(p->type) {
			case 1:
				printf("\tname:\t%s\tvalue:\t%s\n",p->nme,p->val.c);
				break;
			case 2:
				printf("\tname:\t%s\tvalue:\t%d\n",p->nme,*(p->val.n));
				break;
			default:
				break;
		}
	return 1;
}

int _init_node(NODE* node, int type, char* nme) {
	if(!node) return -1;
	node->node_type=type;
	node->node_nme=(char*)malloc(sizeof(strlen(nme)+1));
	strcpy(node->node_nme,nme);
	node->node_prop.type=-1;
	node->node_prop.nme=NULL;
	node->node_prop.val.c=NULL;
	node->node_prop.val.n=NULL;
	node->node_prop.prev=&(node->node_prop);
	node->node_prop.next=&(node->node_prop);
	node->s_prop=&(node->node_prop);
	node->node_prev.adr=NULL;
	node->node_next.adr=NULL;
	node->node_prev.prev=NULL;
	node->node_prev.next=NULL;
	node->node_next.prev=NULL;
	node->node_next.next=NULL;
	node->t_prev=&(node->node_prev);
	node->t_next=&(node->node_next);
	return 1;
}

int _add_prop(NODE* node, char* nme, char* val_c, int* val_n) {
	PROP *p=node->node_prop.prev,*fp;
	fp=(PROP*)malloc(sizeof(PROP));
	fp->nme=(char*)malloc(strlen(nme)+1);
	strcpy(fp->nme,nme);
	if(val_c) {
		fp->type=1;
		fp->val.c=(char*)malloc(strlen(val_c)+1);
		strcpy(fp->val.c,val_c);
	}
	if(val_n) {
		fp->type=2;
		fp->val.n=(int*)malloc(sizeof(int));
		*(fp->val.n)=*val_n;
	}
	fp->next=&(node->node_prop);
	fp->prev=p;
	node->node_prop.prev=fp;
	p->next=fp;
	return 1;
}

int _del_prop(NODE* node, char* nme) {
	PROP *p=node->node_prop.next,*fp;
	for(;p->type!=node->node_prop.type;p=p->next)
		if(!strcmp(nme,p->nme)) {
			fp=p->prev;
			fp->next=p->next;
			free(p);
			p=fp->next;
			return 1;
		}
	return -1;
}

int _edt_prop(NODE* node, char* nme, char* val_c, int* val_n) {
	PROP *p=node->node_prop.next;
	for(;p->type!=node->node_prop.type;p=p->next)
		if(!strcmp(nme,p->nme)) {
			free(p->val.c);
			if(val_c) {
				p->type=1;
				p->val.c=(char*)malloc(strlen(val_c)+1);
				strcpy(p->val.c,val_c);
			}
			if(val_n) {
				p->type=2;
				p->val.n=(int*)malloc(sizeof(int));
				*(p->val.n)=*val_n;
			}
			return 1;
		}
	return -1;
}

int _add_link(NODE* node, int sel, NODE* dst_node) {
	LINK **p=sel?&(node->t_next):&(node->t_prev),*fp=*p;
	fp=fp->next=(LINK*)malloc(sizeof(LINK));
	fp->adr=dst_node;
	fp->prev=*p;
	fp->next=NULL;
	*p=fp;
	return 1;
}

int _del_link(NODE* node, int sel, NODE* dst_node) {
	LINK **p=sel?&(node->t_next):&(node->t_prev),*fp=*p;
	if(fp->adr==dst_node) {
		*p=fp->prev;
		(*p)->next=NULL;
		free(fp);
		return 1;
	}
	while((fp=fp->prev))
		if(fp->adr==dst_node) {
			fp->prev->next=fp->next;
			fp->next->prev=fp->prev;
			free(fp);
			return 1;
		}
	return -1;	
}
