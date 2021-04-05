#include <iostream>
#include <fstream>
#include "riddle.h"
#include "TryInt32.h"
namespace type_texts {

	riddle* riddle_input(ifstream& ifst)
	{
		riddle* r = new riddle;
		r->content = "";
		r->answer = "";
		r->rating = 0;
		string rat = "0";
		ifst >> r->content >> r->answer >> rat;
		if (!(TryInt32(rat)))
		{
			rat = "0";
		}
		r->rating = stoi(rat);
		return r;
	}


	void riddle_output(riddle* r, ofstream& ofst)
	{
		ofst << "It is riddle: " << r->content << " and it's from country: " << r->answer;
		if (!(r->rating == 0))
			ofst << " and its rating is: " << r->rating;
		else
			ofst << " and its rating is unknown ";
		ofst << ". Number of punctuation marks: " << get_punctuation(r) << endl;
	}

	int get_punctuation(riddle* r)
	{
		int count = 0;
		string punc = ".,!?;:-()";

		for (int i = 0; i < punc.size(); i++)
		{
			for (int j = 0; j < r->content.size(); j++)
			{
				if (punc[i] == r->content[j])
				{
					count++;
				}
			}
		}

		return count;
	}

}