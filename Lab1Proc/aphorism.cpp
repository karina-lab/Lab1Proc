#include <iostream>
#include <fstream>
#include "aphorism.h"

	namespace type_texts {

	aphorism* aphorism_input(aphorism* a, ifstream& ifst)
	{
		a->autor = "";
		ifst >> a->autor;
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << ", it's autor is: " << a->autor;


	}
}