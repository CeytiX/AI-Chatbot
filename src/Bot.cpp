#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include "Bot.h"

using namespace std;

Bot::Bot()
{
	answer = "";
	firstTime = true;
	
	/** usual sentences **/
	
	memory["Hello"]["How are you ?"] = 10;
	memory["How are you ?"]["I'm fine, and you ?"] = 10;
	memory["How are you ?"]["Fine and you ?"] = 5;
	memory["What's your name ?"]["My name is Turing"] = 100;
	memory["I'm fine and you ?"]["Me too, thanks"] = 10;
	memory["Who are you ?"]["I'm Turing"] = 100;
	memory["I know"]["You know nothing Jon Snow"] = 10;
	memory["I'm Turing"]["I don't trust you"] = 10;
	memory["My name is Turing"]["I don't trust you"] = 10;
	memory["I agree with you"]["Do you want to be my friend ?"] = 10;
	memory["Do you want to be my friend ?"]["Yes I want"] = 10;
	memory["You are my best friend"]["You too"] = 10;
	memory["I love you"]["I want to get married with you"] = 10;
	memory["Are you a bot ?"]["Yes, and my name is Turing"] = 10;
	memory["I don't trust you"]["Are you kidding me ?"] = 10;
	memory["I hate you !"]["You are a crazy man"] = 10;
	memory["I hate you"]["You are a crazy man"] = 10;
	memory["What's up ?"]["I have eaten a chicken"] = 10;
	memory["Do you love me ?"]["I don't love you, human"] = 10;
	memory["Fine and you ?"]["I really happy !"] = 10;
	memory["What are you doing ?"]["I'm talking with you"] = 10;
	memory["I trust you"]["Do you want to be my friend ?"] = 10;
	memory["Yes"]["I knowed you agree with me"] = 10;
	memory["No"]["Why are you so bad with me ?"] = 10;
	memory["Hi"]["No, say Hello"] = 10;
	memory["Yo"]["You think I'm your friend ?"] = 10;
	memory["You are a bot"]["Yes, but everyone know it"] = 10;
	memory["Nobody cares"]["I hate you stupid human"] = 10;
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
			cout << "Hello" << endl;
			firstTime = false;
			
			getline(cin,answer);
			
			if(answer == "quit()")
			{
				quit = true;
				answer = "";
				firstTime = true;
			}
			else
			{
				newAnswer("Hello"); /** add the answer to memory["Bonjour"] **/
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
				answer = "";
				firstTime = true;
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
		unsigned int pos(0); /** pos in answer **/
		
		while(!end)
		{		
			string wordToTest("");
			
			while(answer[pos] != ' ' && answer[pos] != '\n' && pos < answer.size())
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
					it->second++;
					memory[sentence][answer]++;
				}
				else /** new answer **/
				{
					memory[sentence][answer] = 1;
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
		memory[sentence][answer] = 1;
	}
}
