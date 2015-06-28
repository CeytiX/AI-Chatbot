#include "Bot.cpp"

int main()
{
	Bot turing;
	
	cout << "How many talks ?" << endl;
	int talks;
	cin >> talks;
	cin.ignore();

	for(int i=0; i<talks; i++)
	{
		turing.talk();
	}
	
	return 0;
}
