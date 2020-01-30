#include "list.h"
#include <stdio.h>

/** 
 * Takes a linked_list struct pointer and prints out the 
 * contents of the linked_list.
*/
static inline void print_list(struct linked_list *ll){
	struct Node *node = ll->head;
	printf("[");
	while(node != NULL){
		int value = node->value;
		printf("%d", value);
		node = node->next;
		if(node != NULL)
			printf(", ");		
	}
	printf("] ");
	printf("with the list's length being %d\n\n", ll_length(ll));
}

/**
 * Tests whether or not a linked_list pointer is 
 * initiated when ll_create() is called.
*/
static inline void test_createLinkedList(){
	printf("=======Testing ll_create()================\n");
	struct linked_list *list = ll_create();
	if(list == NULL)
		printf("The list was not created\n\n");
	else
		printf("The list was successfully created\n\n");
}

/**
 * Tests whether the functionality responsible for adding an
 * element to the linked list structure is functioning 
 * properly.
*/
static inline void test_add_element(){
	printf("=======Testing add_element()================\n");
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	printf("I inserted the element 4 into the list. The expected output is [4] with a length of 1. \nThe output is: ");
	print_list(list);
}

/**
 * Tests whether the functionality responsible for adding an
 * element to the linked list structure is functioning 
 * properly when multiple values are added.
*/
static inline void test_add_element_multiple(){
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	ll_add(list, 5);
	ll_add(list, 6);
	printf("The expected output is [6, 5, 4] with a length of 3.\nThe output is: ");
	print_list(list); 
}

/**
 * Test the removal of the beginning element in the linked list
*/
static inline void test_remove_element(){
	printf("=======Testing ll_remove_first()================\n");
	struct linked_list *list = ll_create();
	ll_add(list,4);
	ll_add(list, 5);
	ll_add(list, 6);
	ll_remove_first(list);
	printf("The expected output is [5, 4] with a length of 2.\nThe output is: ");
	print_list(list);
}

/**
 * Tests the removal of multiple elements from the linked list
*/
static inline void test_remove_element_multiple(){
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	ll_add(list, 5);
	ll_remove_first(list);
	ll_add(list, 6);
	ll_remove_first(list);
	ll_add(list, 4);
	printf("The expected output is [4, 4] with a length of 2.\nThe output is: ");
	print_list(list);
}

/** 
 * Tests the case of removing from an empty linked list
*/
static inline void test_remove_element_empty(){
	struct linked_list *list = ll_create();
	bool rmVal = ll_remove_first(list);
	if(rmVal == true)
		printf("The removal method correctly handled removal on a empty list\n\n");
}

/** 
 * Tests whether a linked list will be freed 
 * when there are elements cotained within
 * the list. 
*/
static inline void test_ll_destroy_fail(){
	printf("=======Testing ll_destroy()================\n");
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	int result = ll_destroy(list);
	printf("Given the list [4], the expected output of ll_destroy(list) is 0.\nThe output is: %d\n\n", result);
}

/**
 * Tests whether a linked list is properly
 * freed.
 */ 
static inline void test_ll_destroy_success(){
	struct linked_list *list = ll_create();
	int result = ll_destroy(list);
	printf("Given the list [], the expected output of ll_destroy(list) is 1.\nThe output is: %d\n\n", result);
}

/**
 * Tests whether the contains method correctly identifies
 * the position of an element within the linked list.
*/

static inline void test_contains_value(){
	printf("=======Testing ll_contains()================\n");
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	ll_add(list, 5);
	ll_add(list, 6);
	int result = ll_contains(list, 4);
	printf("Given the list [6, 5, 4], the expected output of ll_contains(list, 4) is 3.\nThe output is: %d\n\n", result);
}

/** 
 * Tests whether the contains method correctly handles
 * the case where the user's input value is not 
 * contained within the linked list.
*/
static inline void test_does_not_contain_value(){
	struct linked_list *list = ll_create();
	ll_add(list, 4);
	ll_add(list, 5);
	ll_add(list, 6);
	int result = ll_contains(list, 7);
	printf("Givne the list [6, 5, 4], the expected output of ll_contains(list, 7) is 0.\nThe output is: %d\n\n", result);
}



int main(void){
	test_createLinkedList();
	test_add_element();
	test_add_element_multiple();
	test_remove_element();
	test_remove_element_multiple();
	test_remove_element_empty();
	test_ll_destroy_fail();
	test_ll_destroy_success();
	test_contains_value();
	test_does_not_contain_value();
	return 0;
}
