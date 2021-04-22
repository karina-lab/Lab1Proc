#include <iostream>
#include <fstream>
#include "proverb.h"

namespace type_texts 
{
	proverb* proverb_input(proverb* p, ifstream& ifst)
	{
		p->country = "";
		ifst >> p->country;
		if (ifst.fail())
		{
			cout << "Wrong input!" << endl;
			return 0;
		}
		return p;
	}
	void proverb_output(proverb* p, ofstream& ofst)
	{
		ofst << ", it's from country: " << p->country;
	}
}