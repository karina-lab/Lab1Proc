#ifndef RIDDLE_H
#define RIDDLE_H
#include <fstream>
#include <string>

using namespace std;

namespace type_texts 
{
	struct riddle
	{
		string answer;
	};
	riddle* riddle_input(riddle* r, ifstream& ifst);
	void riddle_output(riddle* r, ofstream& ofst);
}
#endif