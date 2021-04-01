#include <iostream>
#include <fstream>
#include "aphorism.h"
	namespace type_texts {

	aphorism* aphorism_input(ifstream& ifst)
	{
		aphorism* a = new aphorism;
		a->content = "";
		a->autor = "";
		ifst >> a->content >> a->autor;
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << "It is aphorism: " << a->content << " and it's autor is: " << a ->autor << endl;
	}

}