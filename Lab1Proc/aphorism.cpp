#include <iostream>
#include <fstream>
#include "aphorism.h"
#include "TryInt32.h"
	namespace type_texts {

	aphorism* aphorism_input(ifstream& ifst)
	{
		aphorism* a = new aphorism;
		a->content = "";
		a->autor = "";
		a->rating = 0;
		string rat = "0";
		ifst >> a->content >> a->autor >> rat;
		if (!(TryInt32(rat)))
		{
			rat = "0";
		}
		a->rating = stoi(rat);
		return a;
	}


	void aphorism_output(aphorism* a, ofstream& ofst)
	{
		ofst << "It is aphorism: " << a->content << ", it's autor is: " << a ->autor;
		if (!(a->rating == 0))
			ofst << " and its rating is: " << a->rating << endl;
		else
			ofst << " and its rating is unknown " << endl;
	}

}