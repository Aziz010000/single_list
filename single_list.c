#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#include "single_list.h"


Node *head(List *mylist)
{
  if (mylist == NULL)
    return(NULL);
  return(mylist->head);
}

bool empty(List *mylist)
{
  if (mylist == NULL)
    return(true);
  return(head(mylist)==NULL);
}

Node *next(Node *mynode)
{
  if (mynode == NULL)
    return(NULL);
  return(mynode->next);
}

Node *prev(List *mylist, Node *mynode)
{
  Node *current=head(mylist);
  while(current!=NULL){
    if (current->next == mynode)
      return(current);
    current = current->next;
  }
  return(NULL);
}

Node *tail(List *mylist) 
{
  Node *current=head(mylist); 

  while (current != NULL) {
    if ((current -> next) == NULL)
      return(current);
    current = current->next; 
  }
  return(NULL);  
}


void printNode(Node *mynode)
{
	if(mynode){
		printf("Posizione: %p valore: %d\n", mynode,mynode->value);
	}

}


void printList(List *mylist)
{
	Node *current; 
	current = head(mylist); 
	while(current){
		printNode(current); 
		current = current->next;
	}

}

Node *createNode(int value)
{
	Node *mynode = malloc(sizeof(Node)); 
	if(!mynode){
		fprintf(stderr, "Errore in allocazione\n"); 
		exit(EXIT_FAILURE);
	}
	mynode->next = NULL; 
	mynode->value = value;
	return mynode;
}

//codice che inserisce alla fine della lista
void InsertEndNode(List *mylist,int value)
{
	Node *new = createNode(value);
	Node *current;
	if(!mylist){
		fprintf(stderr,"Errore, lista non inizializzata!!"); 
		exit(EXIT_FAILURE);
	}
	current = mylist->head; 
	if(!current){
		mylist->head = new;
		mylist->tail = new;
	}else{
		mylist->tail->next = new; 
		mylist->tail = new;
	}	
}

void InsertNode(List *mylist, Node *pos,int value)
{
	Node *new;
	if(!mylist){
		fprintf(stderr,"Errore, lista non inizializzata!!"); 
		exit(EXIT_FAILURE);
	}
	new = createNode(value);
	if(!mylist->head){
		assert(pos==NULL);
		mylist->head = new; 
		mylist->tail = new;
	}else if(pos == NULL){
		new->next = mylist->head;
		mylist->head = new;
	}else{
		new->next = pos->next; 
		pos->next = new;
		if(pos == mylist->tail){
			mylist->tail = new;
		}
	}
}

void removeNode(List *mylist, Node *mynode)
{
	Node *lprev;
	if(!mylist || !mylist->head){
		fprintf(stderr, "Errore, lista non inizializzata!!");
		exit(EXIT_FAILURE);
	}
	if(mylist->head == mynode){
		mylist->head = mynode->next;
	}else{
		lprev = prev(mylist, mynode);
		if(lprev){
			lprev->next = mynode->next;
		}else{
			fprintf(stderr, "Errore, nodo da rimuovere non presente!!");
			exit(EXIT_FAILURE);
		}	
		free(mynode);
	}

}

List *createList()
{
	List *mylist = malloc(sizeof(List));
	if(!mylist){
		fprintf(stderr, "Errore in allocazione\n"); 
		exit(EXIT_FAILURE);
	}
	mylist->head = NULL; 
	mylist->tail = NULL;
	return mylist;

}

