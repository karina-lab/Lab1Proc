#ifndef APHORISM_H
#define APHORISM_H
#include <fstream>
#include <string>
//#include "text.h"
using namespace std;
namespace type_texts {

	struct aphorism
	{
		string content;
		string autor;
	};
	aphorism* aphorism_input(ifstream& ifst);
	void aphorism_output(aphorism* a, ofstream& ofst);
	int get_punctuation(aphorism* a);
}
#endif