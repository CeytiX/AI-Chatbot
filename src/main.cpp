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
