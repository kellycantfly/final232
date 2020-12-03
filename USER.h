<<<<<<< HEAD
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
		string firstName;
		string lastName;
		string phoneNumber;
		string address;

	public:
		USER() 
		{
			string input;

			cout << "Enter First Name: " << endl;
			getline(cin, input);
			firstName = input;

			//cout << "Enter Last Name: " << endl;
			//getline(cin, input);
			//lastName = input;

			//cout << "Enter Phone Number: " << endl;
			//getline(cin, input);
			//phoneNumber = input;

			//cout << "Enter Address: " << endl;
			//cin>>input;
			//address = input;

			cin.clear();
			cin.ignore();
		}

		string getUsername() { return username; }
		string getPassword() { return password; }


		void setUsername(string name) { username = name; }
		void setPassword(string word) { password = word; }

		virtual void generateUsername(string name) {};
		virtual void greet() {};
		virtual void menu() {};

		void generatePassword()
		{
			string first, second;
			bool match = 0;

			do
			{
				try
				{
					cout << "######################" << endl;
					cout << "Enter your password: \n";
					cout << "######################" << endl;
					cin >> first;
					cin.clear();
					cout << "######################" << endl;
					cout << "Confirm your password: \n";
					cout << "######################" << endl;
					cin >> second;
					cin.clear();

					if (first == second)
					{
						setPassword(first);
						match = 1;
					}
					else
					{
						throw first;
					}
				}
				catch (string)
				{
					cout << "######################" << endl;
					cout << "Passwords do not match.\n";
				}
			} while (match != 1);

		}
};

class HOLDER : public USER
{
	public:

		HOLDER()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'H')
			{
				name.insert(0, "H");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as a HOLDER.\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}

};

class ADMIN : public USER
{
	public:
		ADMIN()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'A')
			{
				name.insert(0, "A");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as an ADMIN.\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}
	};

	class OFFICAL : public USER
	{

	public:
		OFFICAL()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'O')
			{
				name.insert(0, "O");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as an OFFICIAL\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}

		void menu()
		{
			cout << "test" << endl;
		}

		void open()
		{
			cin.clear();
			cin.ignore();
			char type;
			try
			{
				cout << "New account registry" << endl;
				cout << "[H]older, [O]fficial, [A]min" << endl;
				cin >> type;

				if ((type != 'H') && (type != 'A') && (type != 'O'))
				{
					throw type;
				}

				switch (type)
				{
					case 'H':
					{
						break;
					}
					case 'A':
					{
						break;
					}
					case 'O':
					{
						break;
					}
				}
			}
			catch (char)
			{
				cout << "Invalid account type" << endl;
				cin.clear();
				cin.ignore();
			}

		}
};

=======
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
		string firstName;
		string lastName;
		string phoneNumber;
		string address;

	public:
		USER() 
		{
			string input;

			cout << "Enter First Name: " << endl;
			getline(cin, input);
			firstName = input;

			cout << "Enter Last Name: " << endl;
			getline(cin, input);
			lastName = input;

			cout << "Enter Phone Number: " << endl;
			getline(cin, input);
			phoneNumber = input;

			cout << "Enter Address: " << endl;
			cin>>input;
			address = input;

			cin.clear();
			cin.ignore();
		}

		string getUsername() { return username; }
		string getPassword() { return password; }


		void setUsername(string name) { username = name; }
		void setPassword(string word) { password = word; }

		virtual void generateUsername(string name) {};
		virtual void greet() {};
		virtual void menu() {};

		void generatePassword()
		{
			string first, second;
			bool match = 0;

			do
			{
				try
				{
					cout << "######################" << endl;
					cout << "Enter your password: \n";
					cout << "######################" << endl;
					cin >> first;
					cin.clear();
					cout << "######################" << endl;
					cout << "Confirm your password: \n";
					cout << "######################" << endl;
					cin >> second;
					cin.clear();

					if (first == second)
					{
						setPassword(first);
						match = 1;
					}
					else
					{
						throw first;
					}
				}
				catch (string)
				{
					cout << "######################" << endl;
					cout << "Passwords do not match.\n";
				}
			} while (match != 1);

		}
};

class HOLDER : public USER
{
	public:

		HOLDER()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'H')
			{
				name.insert(0, "H");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as a HOLDER.\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}

};

class ADMIN : public USER
{
	public:
		ADMIN()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'A')
			{
				name.insert(0, "A");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as an ADMIN.\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}
	};

	class OFFICAL : public USER
	{

	public:
		OFFICAL()
		{
			string name;
			cout << "######################" << endl;
			cout << "Enter a new username: \n";
			cout << "######################" << endl;
			cin >> name;
			generateUsername(name);
			generatePassword();

			greet();

			cin.clear();
			cin.ignore();
		}
		void generateUsername(string name)
		{
			char check;
			if (name.at(0) != 'O')
			{
				name.insert(0, "O");
			}
			setUsername(name);
			return;
		}

		void greet()
		{
			cout << "######################" << endl;
			cout << "You're all set up as an OFFICIAL\n";
			cout << "Your unique username is " << getUsername() << " and your password is " << getPassword() << endl;
			cout << "If you need to edit your account details, contact an ADMIN." << endl;
		}

		void menu()
		{
			int userSelection = 0;

			do {

				try
				{

					cout << "[1] Edit an Account" << endl;
					cout << "[2] Create an Account" << endl;
					cout << "[3] Log out" << endl;

					cin >> userSelection;

					if ((!cin) || (userSelection < 0) || (userSelection > 3))
					{
						throw userSelection;
					}

					switch (userSelection)
					{
						case 1:
						{
							open();
							break;
						}
						case 2:
						{
							break;
						}
					}
				}
				catch (int)
				{
					cout << "Invalid input... Restarting" << endl;
					cin.clear();
					cin.ignore();
				}

			} while (userSelection != 3);
		}

		void open()
		{
			cin.clear();
			cin.ignore();
			char type;
			try
			{
				cout << "New account registry" << endl;
				cout << "[H]older, [O]fficial, [A]min" << endl;
				cin >> type;

				if ((type != 'H') && (type != 'A') && (type != 'O'))
				{
					throw type;
				}

				switch (type)
				{
					case 'H':
					{
						break;
					}
					case 'A':
					{
						break;
					}
					case 'O':
					{
						break;
					}
				}
			}
			catch (char)
			{
				cout << "Invalid account type" << endl;
				cin.clear();
				cin.ignore();
			}

		}
};

>>>>>>> 3766df0a8d8b69452f4201877bfaeec3ee7d16c6
#endif