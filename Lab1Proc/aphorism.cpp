#include <iostream>
#include <fstream>
#include "aphorism.h"
	namespace type_texts {

	aphorism* aphorism_input(ifstream& ifst)
	{
		aphorism* a = new aphorism;
		a->content = "";
		a->autor = "";
		ifst >> a->content >> a->autor;
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << "It is aphorism: " << a->content << " and it's autor is: " << a ->autor << ". Number of punctuation marks: " << get_punctuation(a) << endl;
	}

	int get_punctuation(aphorism* a)
	{
		int count = 0;
		string punc = ".,!?;:-()";

		for (int i = 0; i < punc.size(); i++)
		{
			for (int j = 0; j < a->content.size(); j++)
			{
				if (punc[i] == a->content[j])
				{
					count++;
				}
			}
		}

		return count;
	}

}