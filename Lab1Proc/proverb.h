#ifndef PROVERB_H
#define PROVERB_H
#include <fstream>
#include <string>
//#include "text.h"

using namespace std;
namespace type_texts {
	struct proverb
	{
		string content;
		string country;
	};
	proverb* proverb_input(ifstream& ifst);
	void proverb_output(proverb* p, ofstream& ofst);
}
#endif