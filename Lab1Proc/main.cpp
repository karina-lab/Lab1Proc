#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;
using namespace type_texts;

int main(int argc, char const* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line!"
			<< "Waited: command infile outfile" << endl;
		exit(1);
	}
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	ifstream ifst(argv[1]);

	if (!ifst.is_open())
	{
		cout << "file is not open!" << endl;
		return 1;
	}
	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		cout << "file is not open!" << endl;
		return 1;
	}

	cout << "Start" << endl;
	container* c = new container;
	init_list(c);
	fill_list(c, ifst);
	cout << "Filled container. " << endl;
	output_list(c, ofst);
	clear_list(c);
	cout << "Empty container. " << endl;
	output_list(c, ofst);
	cout << "Stop" << endl;

	return 0;
}
