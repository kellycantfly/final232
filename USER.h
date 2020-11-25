#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;


class USER
{
	private:
		string username;
		string password;

	public:
		void setUsername(string name);
		void setPassword(string word);
		string getUsername();
		string getPassword();
};

#endif