#ifndef TEXT_H
#define TEXT_H
#include <fstream>
#include <string>
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_texts 
{
	struct text
	{
		text() {}
		~text() {}

		enum type { APHORISM, PROVERB, RIDDLE };
		type key;
		string content;
		int rating;
		union {
			aphorism a;
			proverb p;
			riddle r;
		};
	};
	text* text_input(ifstream& ifst);
	bool text_output(text* t, ofstream& ofst);
	bool compare(text* plt1, text* plt2);
	int get_punctuation(text* t);

}
#endif