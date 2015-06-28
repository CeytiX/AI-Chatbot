#include <string>
#include <cctype>
#include "functions.h"

using namespace std;

string toLower(string sentence)
{
	string value;
	
	for(unsigned int i=0; i<sentence.size(); i++)
	{
		value += tolower(sentence[i]);
	}
	
	return value;
}

string grower(string sentence)
{
	sentence[0] = toupper(sentence[0]);
	
	return sentence;
}
