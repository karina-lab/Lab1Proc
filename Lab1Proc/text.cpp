#include <iostream>
#include <fstream>
#include "text.h"
#include "proverb.h"
#include "aphorism.h"

namespace type_texts {

	text* text_input(ifstream& ifst) {
		text* t;
		int k;
		ifst >> k;
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
		else
		{
			ofst << "Incorrect text!" << endl;
			return false;
		}
	}
}