#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_texts 
{
	riddle* riddle_input(riddle* r, ifstream& ifst)
	{
		r->answer = "";
		ifst >> r->answer;
		if (ifst.fail())
		{
			cout << "Wrong input!" << endl;
			return 0;
		}
		return r;
	}
	void riddle_output(riddle* r, ofstream& ofst)
	{
		ofst << " and it's from country: " << r->answer;
	}
}