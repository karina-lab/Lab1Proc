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
	void output_aphorism(container* listToOutput, ofstream& ofst);

}   
#endif 
