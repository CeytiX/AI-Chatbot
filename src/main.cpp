/**
 * ========================
 * 
 * Filename: main.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: main function
 * 
 * Created: 27/06/15
 * =========================
 **/
 
#include "Bot.cpp"

int main()
{
	Bot turing;
	bool quit(false);

	while(!quit)
	{
		turing.talk();
		
		cout << "(s)top or (c)ontinue ?" << endl;
		
		char choice;
		cin >> choice;
		cin.ignore();

		if(choice == 's')
		{
			quit = true;
		}
	}
	
	return 0;
}
