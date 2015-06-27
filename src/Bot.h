using namespace std;

class Bot
{
	public:
		Bot();
		Bot(string);
		~Bot();
		void talk();
		string answerTo(string);
		void newAnswer(string);

	private:
		map <string, map <string, int> > memory;
		string name;
		string answer;
		bool firstTime;
};
