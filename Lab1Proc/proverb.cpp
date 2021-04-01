#include <iostream>
#include <fstream>
#include "proverb.h"
namespace type_texts {

	proverb* proverb_input(ifstream& ifst)
	{
		proverb* p = new proverb;
		p->content = "";
		p->country = "";
		ifst >> p->content >> p->country;
		return p;
	}


	void proverb_output(proverb* p, ofstream& ofst)
	{
		ofst << "It is proverb: " << p->content << " and it's from country: " << p->country << endl;
	}

}