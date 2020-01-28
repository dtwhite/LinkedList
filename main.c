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
	printf("]\n");
	printf("The length of the list is %d\n\n", ll_length(ll));
}

/**
 * Tests whether or not a linked_list pointer is 
 * initiated when ll_create() is called.
*/
static inline void test_createLinkedList(){
	struct linked_list *list = ll_create();
	int val = ll_length(list);
	print_list(list);
}

/**
 * Tests whether the functionality responsible for adding an
 * element to the linked list structure is functioning 
 * properly.
*/
static inline void test_add_element(){
	struct linked_list *list = ll_create();
	int test_value = 4;
	void *valPtr = &test_value;
	ll_add(list, valPtr);
	print_list(list);
}

/**
 * Tests whether the functionality responsible for adding an
 * element to the linked list structure is functioning 
 * properly when multiple values are added.
*/
static inline void test_add_element_multiple(){
	struct linked_list *list = ll_create();
	int test_value1 = 4;
	int test_value2 = 5;
	int test_value3 = 6;
	void *valPtr1 = &test_value1;
	void *valPtr2 = &test_value2;
	void *valPtr3 = &test_value3;
	ll_add(list, valPtr1);
	ll_add(list, valPtr2);
	ll_add(list, valPtr3);
	printf("The expected output is [6, 5, 4] with a length of 3. The output is: \n");
	print_list(list); 
}

/**
 * Test the removal of the beginning element in the linked list
*/
static inline void test_remove_element(){
	struct linked_list *list = ll_create();
	int test_value1 = 4;
	int test_value2 = 5;
	int test_value3 = 6;
	void *valPtr1 = &test_value1;
	void *valPtr2 = &test_value2;
	void *valPtr3 = &test_value3;
	ll_add(list, valPtr1);
	ll_add(list, valPtr2);
	ll_add(list, valPtr3);
	ll_remove_first(list);
	printf("The expected output is [5, 4] with a length of 2. The output is \n");
	print_list(list);
}

/**
 * Tests the removal of multiple elements from the linked list
*/
static inline void test_remove_element_multiple(){
	struct linked_list *list = ll_create();
	int test_value1 = 4;
	int test_value2 = 5;
	int test_value3 = 6;
	void *valPtr1 = &test_value1;
	void *valPtr2 = &test_value2;
	void *valPtr3 = &test_value3;
	ll_add(list, valPtr1);
	ll_add(list, valPtr2);
	ll_remove_first(list);
	ll_add(list, valPtr3);
	ll_remove_first(list);
	ll_add(list, valPtr1);
	printf("The expected output is [4, 4] with a length of 2. The output is \n");
	print_list(list);
}

/** 
 * Tests whether a linked list will be freed 
 * when there are elements cotained within
 * the list. 
*/
static inline void test_ll_destroy_fail(){
	struct linked_list *list = ll_create();
	int test_val = 4;
	void *valPtr = &test_val;
	ll_add(list, valPtr);
	int result = ll_destroy(list);
	printf("The expected output is 0. The output is: \n%d\n\n", result);
}

/**
 * Tests whether a linked list is properly
 * freed.
 */ 
static inline void test_ll_destroy_success(){
	struct linked_list *list = ll_create();
	int result = ll_destroy(list);
	printf("The expected output is 1. The output is: \n%d\n\n", result);
}

/**
 * Tests whether the contains method correctly identifies
 * the position of an element within the linked list.
*/

static inline void test_contains_value(){
	struct linked_list *list = ll_create();
	int test_value1 = 4;
	int test_value2 = 5;
	int test_value3 = 6;
	void *valPtr1 = &test_value1;
	void *valPtr2 = &test_value2;
	void *valPtr3 = &test_value3;
	ll_add(list, valPtr1);
	ll_add(list, valPtr2);
	ll_add(list, valPtr3);
	int result = ll_contains(list, valPtr1);
	printf("The expected output is 3. The output is: \n%d\n\n", result);
}

/** 
 * Tests whether the contains method correctly handles
 * the case where the user's input value is not 
 * contained within the linked list.
*/
static inline void test_does_not_contain_value(){
	struct linked_list *list = ll_create();
	int test_value1 = 4;
	int test_value2 = 5;
	int test_value3 = 6;
	int test_value4 = 7;
	void *valPtr1 = &test_value1;
	void *valPtr2 = &test_value2;
	void *valPtr3 = &test_value3;
	void *valPtr4 = &test_value4;
	ll_add(list, valPtr1);
	ll_add(list, valPtr2);
	ll_add(list, valPtr3);
	int result = ll_contains(list, valPtr4);
	printf("The expected output is 0. The output is: \n%d\n\n", result);
}



int main(void){
	test_createLinkedList();
	test_add_element();
	test_add_element_multiple();
	test_remove_element();
	test_remove_element_multiple();
	test_ll_destroy_fail();
	test_ll_destroy_success();
	test_contains_value();
	test_does_not_contain_value();
	return 0;
}
