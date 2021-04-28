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
		string kk;
		ifst >> kk;
		if (!(TryInt32(kk)))
		{
			kk = "0";
		}
		int k = stoi(kk);
		switch (k)
		{
		case 1:
			t = new text;
			t = (text*)aphorism_input(ifst);
			t->key = text::type::APHORISM;
			return t;
		case 2:
			t = new text;
			t = (text*)proverb_input(ifst);
			t->key = text::type::PROVERB;
			return t;
		case 3:
			t = new text;
			t = (text*)riddle_input(ifst);
			t->key = text::type::RIDDLE;
			return t;
		default:
			return 0;
		}
	}


	bool text_output(text* t, ofstream& ofst) {


		if (t->key == text::type::APHORISM)
		{
			aphorism_output((aphorism*)t, ofst);
			return true;
		}
		else if (t->key == text::type::PROVERB)
		{
			proverb_output((proverb*)t, ofst);
			return true;
		}
		else if (t->key == text::type::RIDDLE)
		{
			riddle_output((riddle*)t, ofst);
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
		if (t->key == text::type::APHORISM)
		{
			return get_punctuation((aphorism*)t);
		}
		if (t->key == text::type::PROVERB)
		{
			return get_punctuation((proverb*)t);
		}
		if (t->key == text::type::RIDDLE)
		{
			return get_punctuation((riddle*)t);
		}
		return -1;
	}


	bool compare(text* plt1, text* plt2)
	{
		return get_punctuation(plt1) < get_punctuation(plt2);
	}


}