#include "Bot.cpp"

int main()
{
	Bot turing;
	
	cout << "How many talks ?" << endl;
	int talks;
	cin >> talks;
	
	for(int i=0; i<talks; i++)
	{
		turing.talk();
	}
	
	return 0;
}
