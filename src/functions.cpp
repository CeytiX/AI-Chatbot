/**
 * ========================
 * 
 * Filename: functions.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: many functions which allow us to change easily strings
 * 
 * Created: 28/06/15
 * =========================
 **/
 
#include <string>
#include <cctype>
#include "functions.h"

using namespace std;

string toLower(string sentence) /** toLower() **/
{
	string value;
	
	for(unsigned int i=0; i<sentence.size(); i++)
	{
		value += tolower(sentence[i]);
	}
	
	return value;
}

string grower(string sentence) /** grower() **/
{
	sentence[0] = toupper(sentence[0]);
	
	return sentence;
}
