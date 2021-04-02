#ifndef TEXT_H
#define TEXT_H
#include <fstream>
#include <string>
#include "aphorism.h"
#include "proverb.h"

using namespace std;
namespace type_texts {


	struct text
	{
		text() {}
		~text() {}

		enum type { APHORISM, PROVERB };
		type key; 
		string content;
		union {
			aphorism a;
			proverb p;
		};
	};

	text* text_input(ifstream& ifst);
	bool text_output(text* t, ofstream& ofst);


}
#endif