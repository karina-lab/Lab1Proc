#include <iostream>
#include <fstream>
#include "aphorism.h"
#include "TryInt32.h"
	namespace type_texts {

	aphorism* aphorism_input(ifstream& ifst)
	{
		aphorism* a = new aphorism;
		a->content = "";
		a->autor = "";
		a->rating = 0;
		string rat = "0";
		ifst >> a->content >> a->autor >> rat;
		if (!(TryInt32(rat)))
		{
			rat = "0";
		}
		a->rating = stoi(rat);
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << "It is aphorism: " << a->content << ", its autor is: " << a ->autor;
		if (!(a->rating == 0))
			ofst << " and its rating is: " << a->rating;
		else
			ofst << " and its rating is unknown";
		ofst << ". Number of punctuation marks: " << get_punctuation(a) << endl;
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