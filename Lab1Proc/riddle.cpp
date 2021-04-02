#include <iostream>
#include <fstream>
#include "riddle.h"
namespace type_texts {

	riddle* riddle_input(ifstream& ifst)
	{
		riddle* r = new riddle;
		r->content = "";
		r->answer = "";
		ifst >> r->content >> r->answer;
		return r;
	}


	void riddle_output(riddle* r, ofstream& ofst)
	{
		ofst << "It is riddle: " << r->content << " and it's from country: " << r->answer << endl;
	}

}