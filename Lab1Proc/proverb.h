#ifndef PROVERB_H
#define PROVERB_H
#include <fstream>
#include <string>

using namespace std;

namespace type_texts 
{
	struct proverb
	{
		string country;
		int rating;
	};
	proverb* proverb_input(proverb* p, ifstream& ifst);
	void proverb_output(proverb* p, ofstream& ofst);
}
#endif