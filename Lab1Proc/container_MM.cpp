#include <iostream>
#include <fstream>
#include "container.h"
namespace type_texts {

	bool node_output(struct node* headNode, int pos, ofstream& ofst);

	void MultiMethod(struct container* list, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		node* currentNode1;
		node* currentNode2;
		for (int i = 0; i < list->size - 1; i++) {
			currentNode1 = list->head;
			for (int p = 0; p < i; p++) {
				currentNode1 = currentNode1->next;
			}
			currentNode2 = currentNode1->next;
			for (int j = i + 1; j < list->size; j++) {
				switch (currentNode1->plt->key) {
				case text::type::APHORISM:
					switch (currentNode2->plt->key) {
					case text::type::APHORISM:
						ofst << "Aphorism and Aphorism." << endl;
						break;
					case text::type::PROVERB:
						ofst << "Aphorism and Proverb." << endl;
						break;
					default:
						ofst << "Aphorism and Unknown type." << endl;
						break;
					}
					currentNode2 = currentNode2->next;
					break;
				case text::type::PROVERB:
					switch (currentNode2->plt->key) {
					case text::type::APHORISM:
						ofst << "Proverb and Aphorism." << endl;
						break;
					case text::type::PROVERB:
						ofst << "Proverb and Proverb." << endl;
						break;
					default:
						ofst << "Proverb and Unknown type." << endl;
						break;
					}
					currentNode2 = currentNode2->next;
					break;
				default:
					ofst << "Unknown type." << endl;
					break;
				}

				node_output(list->head, i, ofst);
				node_output(list->head, j, ofst);

			}
		}
	}

}
