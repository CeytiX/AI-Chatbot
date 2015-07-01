/**
 * ========================
 * 
 * Filename: Bot.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: Bot class
 * 
 * Created: 27/06/15
 * =========================
 **/
 
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include "Bot.h"
#include "functions.cpp"

using namespace std;

Bot::Bot() /** constructor **/
{
	answer = "";
	firstTime = true;
	
	/** usual sentences **/
	
	string empty;
	ifstream log("memory/memory.txt");
	
	if(!log)
	{
		memory["hello"]["how are you ?"] = 5;
		memory["how are you ?"]["i'm fine, and you ?"] = 5;
		memory["how are you ?"]["fine and you ?"] = 3;
		memory["what's your name ?"]["it is a secret"] = 5;
		memory["i'm fine and you ?"]["me too, thanks"] = 5;
		memory["who are you ?"]["i'm an unkown man"] = 50;
		memory["i know"]["you know nothing Jon Snow"] = 5;
		memory["i agree with you"]["do you want to be my friend ?"] = 5;
		memory["do you want to be my friend ?"]["yes I want"] = 5;
		memory["you are my best friend"]["you too"] = 5;
		memory["i love you"]["i want to get married with you"] = 5;
		memory["are you a bot ?"]["no, of course"] = 5;
		memory["i don't trust you"]["are you kidding me ?"] = 5;
		memory["i hate you"]["you are a crazy man"] = 5;
		memory["what's up ?"]["i have eaten a chicken"] = 5;
		memory["do you love me ?"]["i don't love you, guy"] = 5;
		memory["fine and you ?"]["i am really happy !"] = 5;
		memory["what are you doing ?"]["i am talking with you"] = 5;
		memory["i trust you"]["do you want to be my friend ?"] = 5;
		memory["yes"]["i knowed you agree with me"] = 5;
		memory["no"]["why are you so bad with me ?"] = 5;
		memory["hi"]["no, say Hello"] = 5;
		memory["yo"]["do you think I am your friend ?"] = 5;
		memory["you are a bot"]["you are crazy !"] = 5;
		memory["nobody cares"]["i hate you stupid guy"] = 5;
		memory["ok"]["why are you so bad with me ?"] = 5;
		memory["ok."]["i think i will hit you"] = 5;
		memory["i don't care"]["ok."] = 5;
		memory["really ?"]["yes"] = 5;
		memory["thank you"]["your welcome"] = 5;
		memory["i don't know"]["why don't you know ?"] = 5;
		memory["you are very nice"]["i know"] = 5;
		memory["why ?"]["i don't want to say it"] = 5;
	}
	else
	{
		load(); /** load all the memory from files **/
	}
}

Bot::~Bot() /** destructor **/
{
	/** void **/
}

void Bot::talk() /** void talk() **/
{
	bool quit(false);
	
	while(!quit)
	{
		if(firstTime)
		{
			cout << "Hello" << endl;
			firstTime = false;
			
			getline(cin,answer);
			answer = toLower(answer);
			
			if(answer == "quit()")
			{
				quit = true;
				answer = "";
				firstTime = true;
			}
			else
			{
				newAnswer("hello"); /** add the answer to memory["hello"] **/
			}
		}
		else
		{
			string sentence = answerTo(answer); /** answer to the answer of the human **/
			
			cout << grower(sentence) << endl;
			
			getline(cin, answer);
			answer = toLower(answer); /** changes "Hello !" to "hello  " **/
			
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
	
	save(); /** save all the memory into files **/
}

string Bot::answerTo(string sentence) /** string answerTo() **/
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

void Bot::newAnswer(string sentence) /** void newAnswer() **/
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
			bool knownWord(false);
			
			while(answer[pos] != ' ' && answer[pos] != '\n' && pos < answer.size())
			{
				wordToTest += answer[pos];
				pos++;
			}
			pos++;
						
			/** NEW WORD **/
			
			for(it = memory[sentence].begin(); it!=memory[sentence].end(); it++) /** test all answers to sentence **/
			{				
				size_t found = it->first.find(wordToTest); /** does the word below to an existing answer ? **/
				
				if(found != string::npos)
				{
					it->second++;
					memory[sentence][answer]++;
					knownWord = true;
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
		knownWord = false;
	}
	
	if(!knownWord) memory[sentence][answer]=1;
}

/**************
* void load() *
**************/

void Bot::load()
{
	ifstream log("memory/memory.txt");
	queue<string> sentences;
	string sentence;
	
	while(getline(log, sentence)) /** load of all sentences **/
	{
		sentences.push(sentence);
	}
	
	while(!sentences.empty())
	{	
		string fileName = "memory/sentences/" + sentences.front();
		ifstream file(fileName.c_str());
		string answer_sentence;
		
		while(getline(file, answer_sentence))
		{	
			int value;
			string svalue;
			getline(file, svalue);
			value = atoi(svalue.c_str());
			
			memory[sentences.front()][answer_sentence] = value;
		}
		
		sentences.pop();
	}
}

/**************
* void save() *
**************/

void Bot::save()
{
	map<string, map <string, int> >::iterator it1;
	map<string, int>::iterator it2;
	
	ofstream log("memory/memory.txt");
	
	for(it1 = memory.begin(); it1!=memory.end(); it1++)
	{
		log << it1->first << endl;
		
		string fileName = "memory/sentences/" + it1->first;
		ofstream file(fileName.c_str());
		
		for(it2 = memory[it1->first].begin(); it2!=memory[it1->first].end(); it2++)
		{
			file << it2->first << endl << it2->second << endl;
		}
	}
}
