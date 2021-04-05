#ifndef RIDDLE_H
#define RIDDLE_H
#include <fstream>
#include <string>
//#include "text.h"

using namespace std;
namespace type_texts {
	struct riddle
	{
		string content;
		string answer;
		int rating;
	};
	riddle* riddle_input(ifstream& ifst);
	void riddle_output(riddle* r, ofstream& ofst);
	int get_punctuation(riddle* r);
}
#endif