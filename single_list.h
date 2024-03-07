#include<stdbool.h>

typedef struct node{
	int value; 
	struct node *next;

}Node;

typedef struct list{
	Node *head; 
	Node *tail;

}List;

Node *head(List *mylist);
bool empty(List *mylist);
Node *next(Node *mynode);
Node *prev(List *mylist, Node *mynode);
Node *tail(List *mylist);
void printNode(Node *mynode);
void printList(List *mylist);
Node *createNode(int value);
void insertNode(List *mylist,Node *pos,int value);
void insertEndNode(List *mylist,int value);
void removeNode(List *mylist, Node *mynode);
List *createList();
