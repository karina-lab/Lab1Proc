#include <iostream>
#include <fstream>
#include "container.h"
namespace type_texts {

	void init_list(container* initList)
	{
		initList->size = 0;
		initList->head = NULL;
	}


	void clear_list(container* listToClear)
	{
		if (listToClear->head == NULL)
		{
			return;
		}
		else
		{
			for (int i = listToClear->size; i > 0; i--)
			{
				clear_node(listToClear->head, i);
			}
			listToClear->head = NULL;
		}

		listToClear->size = 0;
	}


	void fill_list(struct container* listToFill, ifstream& ifst)
	{
		
		if (listToFill->head != NULL)
		{
			cout << "LIST IS NOT EMPTY!" << endl;
			return;
		}
		while (!ifst.eof())
		{
			if (add_node(listToFill, ifst))
			{
				(listToFill->size)++;
			}
		}


	}

	bool output_node(struct node* headNode, int pos, ofstream& ofst)
	{
		node* currentNode = headNode;

		for (int i = 0; i < pos; i++)
		{
			currentNode = currentNode->next;
		}

		if (!text_output(currentNode->plt, ofst))
		{
			cout << "Cannot output text!" << endl;
			return false;
		}
		
		return true;
	}

	void output_list(struct container* listToOutput, ofstream& ofst)
	{
		if (listToOutput->size == 0)
		{
			cout << "LIST IS EMPTY!" << endl;
			return;
		}

		ofst << "Container contains " << listToOutput->size << " elements. " << endl;
		for (int i = 0; i < listToOutput->size; i++)
		{
			if (!output_node(listToOutput->head, i, ofst))
			{
				cout << "Node is broken!" << endl;
			}
		}
	}

} 
