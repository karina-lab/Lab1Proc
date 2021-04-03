#include <iostream>
#include <fstream>
#include "proverb.h"
#include "TryInt32.h"
namespace type_texts {

	proverb* proverb_input(ifstream& ifst)
	{
		proverb* p = new proverb;
		p->content = "";
		p->country = "";
		p->rating = 0;
		string rat = "0";
		ifst >> p->content >> p->country >> rat;
		if (!(TryInt32(rat)))
		{
			rat = "0";
		}
		p->rating = stoi(rat);
		return p;
	}


	void proverb_output(proverb* p, ofstream& ofst)
	{
		ofst << "It is proverb: " << p->content << ", it's from country: " << p->country ;
		if (!(p->rating == 0))
			ofst << " and its rating is: " << p->rating << endl;
		else
			ofst << " and its rating is unknown " << endl;
	}

}