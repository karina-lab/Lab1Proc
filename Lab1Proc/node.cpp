#include <iostream>
#include <fstream>
#include "node.h"
#include "container.h"

namespace type_texts 
{
	void clear_node(struct node* startNode, int pos)
	{
		node* currNode = startNode;

		for (int i = 0; i < pos - 1; i++)
		{
			currNode = currNode->next;
		}

		free(currNode);
	}
	bool add_node(container* currentList, ifstream& ifst)
	{
		struct node* newNode = new node();
		newNode->plt = text_input(ifst);
		if (newNode->plt == 0)
		{
			delete (newNode);
			return false;
		}
		if (currentList->head == NULL)
		{
			currentList->head = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		}
		else
		{
			newNode->next = currentList->head;
			newNode->prev = currentList->head->prev;
			currentList->head->prev->next = newNode;
			currentList->head->prev = newNode;
		}
		return true;
	}
	bool node_output(struct node* headNode, int pos, ofstream& ofst) {
		node* currentNode = get_node(headNode, pos);

		if (!text_output(currentNode->plt, ofst)) {
			cout << "|Cannot to output node #" << (pos + 1) << "|" << endl;
			return false;
		}
		else {
			ofst << "Number of punctuation marks: " << get_punctuation(currentNode->plt) << "." << endl;
			return true;
		}

	}
}