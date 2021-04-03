#include <iostream>
#include <fstream>
#include "proverb.h"
namespace type_texts {

	proverb* proverb_input(ifstream& ifst)
	{
		proverb* p = new proverb;
		p->content = "";
		p->country = "";
		ifst >> p->content >> p->country;
		return p;
	}


	void proverb_output(proverb* p, ofstream& ofst)
	{
		ofst << "It is proverb: " << p->content << " and it's from country: " << p->country << ". Number of punctuation marks: " << get_punctuation(p) << endl;
	}

	int get_punctuation(proverb* p)
	{
		int count = 0;
		string punc = ".,!?;:-()";

		for (int i = 0; i < punc.size(); i++)
		{
			for (int j = 0; j < p->content.size(); j++)
			{
				if (punc[i] == p->content[j])
				{
					count++;
				}
			}
		}

		return count;
	}

}