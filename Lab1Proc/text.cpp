#include <iostream>
#include <fstream>
#include "text.h"
#include "proverb.h"
#include "aphorism.h"
#include "riddle.h"
#include "TryInt32.h"

namespace type_texts {

	text* text_input(ifstream& ifst) {
		text* t;
		int k;
		ifst >> k;
		string rat = "0";
		switch (k)
		{
		case 1:
			t = new text;
			t->content = "";
			ifst >> t->content;
			t = (text*)aphorism_input((aphorism*)t, ifst);
			t->rating = 0;
			ifst >> rat;
			if (!(TryInt32(rat)))
			{
				rat = "0";
			}
			t->rating = stoi(rat);
			t->key = text::type::APHORISM;
			return t;
		case 2:
			t = new text;
			t->content = "";
			ifst >> t->content;
			t = (text*)proverb_input((proverb*)t, ifst);
			t->rating = 0;
			ifst >> rat;
			if (!(TryInt32(rat)))
			{
				rat = "0";
			}
			t->rating = stoi(rat);
			t->key = text::type::PROVERB;
			return t;
		case 3:
			t = new text;
			t->content = "";
			ifst >> t->content;
			t = (text*)riddle_input((riddle*)t, ifst);
			t->rating = 0;
			ifst >> rat;
			if (!(TryInt32(rat)))
			{
				rat = "0";
			}
			t->rating = stoi(rat);
			t->key = text::type::RIDDLE;
			return t;
		default:
			return 0;
		}
	}


	bool text_output(text* t, ofstream& ofst) {


		if (t->key == text::type::APHORISM)
		{
			ofst << "It is aphorism: " << t->content;
			aphorism_output((aphorism*)t, ofst);
			if (!(t->rating == 0))
				ofst << " and its rating is: " << t->rating;
			else
				ofst << " and its rating is unknown ";
			ofst << ". Number of punctuation marks: " << get_punctuation(t) << endl;
			return true;
		}
		else if (t->key == text::type::PROVERB)
		{
			ofst << "It is proverb: " << t->content;
			proverb_output((proverb*)t, ofst);
			if (!(t->rating == 0))
				ofst << " and its rating is: " << t->rating;
			else
				ofst << " and its rating is unknown ";
			ofst << ". Number of punctuation marks: " << get_punctuation(t) << endl;
			return true;
		}
		else if (t->key == text::type::RIDDLE)
		{
			ofst << "It is riddle: " << t->content;
			riddle_output((riddle*)t, ofst);
			if (!(t->rating == 0))
				ofst << " and its rating is: " << t->rating;
			else
				ofst << " and its rating is unknown ";
			ofst << ". Number of punctuation marks: " << get_punctuation(t) << endl;
			return true;
		}
		else
		{
			ofst << "Incorrect text!" << endl;
			return false;
		}
	}

	int get_punctuation(text* t)
	{
		int count = 0;
		string punc = ".,!?;:-()";

		for (int i = 0; i < punc.size(); i++)
		{
			for (int j = 0; j < t->content.size(); j++)
			{
				if (punc[i] == t->content[j])
				{
					count++;
				}
			}
		}
		return count;
	}



	bool compare(text* plt1, text* plt2)
	{
		return get_punctuation(plt1) < get_punctuation(plt2);
	}


}