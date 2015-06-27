#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include "Bot.h"

using namespace std;

Bot::Bot()
{
	name = "Turing";
	memory["Bonjour"]["Bonjour, ça va ?"] = 2;
	answer = "";
	firstTime = true;
}

Bot::Bot(string NAME)
{
	name = NAME;
	memory["Bonjour"]["Bonjour, ça va ?"] = 2;
	answer = "";
	firstTime = true;
}

Bot::~Bot()
{
	/** void **/
}

void Bot::talk()
{
	bool quit(false);
	
	while(!quit)
	{
		if(firstTime)
		{
			cout << "Bonjour" << endl;
			firstTime = false;
		
			getline(cin,answer);
			
			if(answer == "quit()")
			{
				quit = true;
			}
			else
			{
				newAnswer("Bonjour"); /** add the answer to memory["Bonjour"] **/
			}
		}
		else
		{
			string sentence = answerTo(answer); /** answer to the answer of the human **/
			
			cout << sentence << endl;
		
			getline(cin, answer);
		
			if(answer == "quit()")
			{
				quit = true;
			}
			else
			{
				newAnswer(sentence); /** add the answer to memory[sentence] **/
			}
		}
	}
}

string Bot::answerTo(string sentence)
{
	map<string, int>::iterator it;
	
	map<string, int> voidMap;
	
	string answerToSay("");
	int max(0);
	
	if(memory[sentence] != voidMap) /** if the bot knows an answer **/
	{
		for(it = memory[sentence].begin(); it!=memory[sentence].end(); it++) /** test all answers to sentence **/
		{
			if(it->second > max)
			{
				max = it->second;
				answerToSay = it->first;
			}
		}
	}
	else /** if the bot doesn't know an answer, it repeats the sentence of the human **/
	{
		answerToSay = sentence;
	}
	
	return answerToSay;
}

void Bot::newAnswer(string sentence)
{	
	map<string, int>::iterator it;
	
	map<string, int> voidMap;
	
	if(memory[sentence] != voidMap) /** if the bot knows an answer **/
	{
		bool end (false);
		int pos(0); /** pos in answer **/
		
		while(!end)
		{		
			string wordToTest("");
			
			while(answer[pos] != ' ' && answer[pos] != '\n' && pos <= answer.size())
			{
				wordToTest += tolower(answer[pos]);
				pos++;
			}
			pos++;
			
			
			/** NEW WORD **/
			
			for(it = memory[sentence].begin(); it!=memory[sentence].end(); it++) /** test all answers to sentence **/
			{
				string lower(""); /** tolower of it->first **/
				
				for(unsigned int i=0; i<(it->first).size(); i++)
				{
					lower += tolower((it->first)[i]);
				}
				
				size_t found = lower.find(wordToTest); /** does the word below to an existing answer ? **/
				
				if(found != string::npos)
				{
					cout << "ok" << endl;
					it->second++;
					memory[sentence][answer]++;
				}
			}
			
			/** END NEW WORD **/
			
			if(pos >= answer.size()) /** if all words have been read **/
			{
				end = true;
			}
		}
	}
	else /** if the bot doesn't know an answer, it adds this answer **/
	{
		memory[sentence][answer] == 1;
	}
	
	cout << memory["Bonjour"]["Bonjour"] << endl;
	cout << memory["Bonjour"]["Bonjour, ça va ?"] << endl;
}
