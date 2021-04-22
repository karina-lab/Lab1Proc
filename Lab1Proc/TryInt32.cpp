#include <iostream>
#include <fstream>
#include "TryInt32.h"

using namespace std;

namespace type_texts 
{
	bool TryInt32(string rat)
	{
		bool result = false;
		for (int i = 1; i < 11; i++)
		{
			if (rat == to_string(i))
			{
				result = true;
				break;
			}
		}
		return result;
	}
}