#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_texts {

	riddle* riddle_input(riddle* r, ifstream& ifst)
	{
		r->answer = "";
		ifst >> r->answer;
		return r;
	}


	void riddle_output(riddle* r, ofstream& ofst)
	{
		ofst << " and it's from country: " << r->answer;
	}

}