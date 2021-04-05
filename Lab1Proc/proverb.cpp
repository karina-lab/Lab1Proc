#include <iostream>
#include <fstream>
#include "proverb.h"
#include "TryInt32.h"
namespace type_texts {

	proverb* proverb_input(ifstream& ifst)
	{
		proverb* p = new proverb;
		p->content = "";
		p->country = "";
		p->rating = 0;
		string rat = "0";
		ifst >> p->content >> p->country >> rat;
		if (!(TryInt32(rat)))
		{
			rat = "0";
		}
		p->rating = stoi(rat);
		return p;
	}


	void proverb_output(proverb* p, ofstream& ofst)
	{
		ofst << "It is proverb: " << p->content << ", it's from country: " << p->country ;
		if (!(p->rating == 0))
			ofst << " and its rating is: " << p->rating;
		else
			ofst << " and its rating is unknown ";
		ofst << ". Number of punctuation marks: " << get_punctuation(p) << endl;
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