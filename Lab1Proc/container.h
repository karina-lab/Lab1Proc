#ifndef CONTAINER_H
#define CONTAINER_H
#include <fstream>
#include <string>
#include "node.h"

using namespace std;
namespace type_texts {

	struct container
	{
		long size;
		node* head;

	};

	void init_list(struct container* newList);
	void clear_list(struct container* listToClear);
	void fill_list(struct container* listToFill, ifstream& ifst);
	void output_list(struct container* listToOutput, ofstream& ofst);
	struct node* get_node(struct node* head, int index);
	void swap(struct node* head, int first, int second);
	void sort(int size, struct node* head);

}   
#endif 
