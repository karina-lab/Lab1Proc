#include <iostream>
#include <fstream>
#include "container.h"
namespace type_texts 
{
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
	node* get_node(node* head, int index)
	{
		struct node* returnNode = head;
		for (int i = 0; i < index; i++)
		{
			returnNode = returnNode->next;
		}
		return returnNode;
	}
	void swap(node* head, int index_first, int index_second)
	{
		struct node* temp = new node;
		temp->plt = get_node(head, index_first)->plt;
		get_node(head, index_first)->plt = get_node(head, index_second)->plt;
		get_node(head, index_second)->plt = temp->plt;
	}
	void sort(int size, struct node* head)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (compare(get_node(head, i)->plt, get_node(head, j)->plt))
				{
					swap(head, i, j);
				}
			}
		}
	}

	void output_aphorism(container* listToOutput, ofstream& ofst)
	{
		node* currentNode;
		if (listToOutput->size == 0)
		{
			cout << "LIST IS EMPTY!" << endl;
			return;
		}
		int count = 0;
		for (int i = 0; i < listToOutput->size; i++)
		{
			currentNode = listToOutput->head;
			for (int j = 0; j < i; j++)
			{
				currentNode = currentNode->next;
			}
			if (currentNode->plt->key == text::type::APHORISM)
			{
				count++;
			}
		}
		ofst << "Container contains " << count << " aphorisms. " << endl;
		for (int i = 0; i < listToOutput->size; i++)
		{
			currentNode = listToOutput->head;
			for (int j = 0; j < i; j++)
			{
				currentNode = currentNode->next;
			}
			if (currentNode->plt->key == text::type::APHORISM)
			{
				if (!output_node(listToOutput->head, i, ofst))
				{
					cout << "Node is broken!" << endl;
				}
			}
		}
	}
}
