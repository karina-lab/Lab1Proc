#include <iostream>
#include <fstream>
#include "aphorism.h"

	namespace type_texts {

	aphorism* aphorism_input(aphorism* a, ifstream& ifst)
	{
		a->autor = "";
		ifst >> a->autor;
		if (ifst.fail())
		{
			cout << "Wrong input!" << endl;
			return 0;
		}
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << ", it's autor is: " << a->autor;


	}
}