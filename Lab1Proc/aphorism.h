#ifndef APHORISM_H
#define APHORISM_H
#include <fstream>
#include <string>

using namespace std;

namespace type_texts 
{
	struct aphorism
	{
		string autor;
		int rating;
	};
	aphorism* aphorism_input(aphorism* a, ifstream& ifst);
	void aphorism_output(aphorism* a, ofstream& ofst);
}
#endif