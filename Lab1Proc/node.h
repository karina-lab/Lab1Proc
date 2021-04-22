#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <string>
#include "text.h"

using namespace std;

namespace type_texts 
{
	struct node
	{
		text* plt;
		node* next;
		node* prev;
	};
	bool add_node(struct container* currentList, ifstream& ifst);
	bool output_node(struct node* headNode, int pos, ofstream& ofst);
	void clear_node(struct node* startNode, int pos);
}
#endif