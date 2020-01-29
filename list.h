#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
};

struct linked_list{
	struct Node *head;
	int length;
};

static inline struct linked_list* ll_create(void){
	struct linked_list *list = (struct linked_list*)malloc(sizeof(struct linked_list));
	list->length = 0;
	list->head = NULL;
	if(list == NULL)
		return NULL;
	return list;
}

static inline int ll_destroy(struct linked_list *ll){
	if(ll->length)
		return 0;
	else{
		free(ll);
		return 1;
	}
}

static inline void ll_add(struct linked_list *ll, int value){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->value = value;
	node->next = ll->head;
	ll->head = node;
	ll->length++;
}

static inline int ll_length(struct linked_list *ll){
	return ll->length;
}

static inline bool ll_remove_first(struct linked_list *ll){
	if(ll->length){
		struct Node *deleteNode = ll->head;
		ll->head = ll->head->next;
		free(deleteNode);
		ll->length--;
		return true;
	}
	return false;
	
}

static inline int ll_contains(struct linked_list *ll, int value){
	bool isFound = false;
	struct Node *ptr = ll->head;
	int offset = 1;
	while(ptr != NULL && !isFound){
		if(ptr->value == value)
			isFound = true;
		else{
			ptr = ptr->next;
			offset++;	
		}
	}
	if(isFound)
		return offset;
	return 0;
}

#endif
