#include <iostream>
#include <string>
using namespace std;


class USER
{
	private:
		string userName;
		string password;

	public:
		void setUserName(string name);
		void setPassword(string word);
		string getUserName();
		string getPassword();
};