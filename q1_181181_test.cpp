#include "bank.h"


int main()
{
	cout << "FAST BANK  the name of trust\n\n";
	string a ;
	int b;
	cout << "Enter your name: ";
	getline(cin , a);
	bool f =  true;
	char c;
	cout << "Sure you wanna go with this name bcoz it can't be change later (Y/N)";
	cin >> c;
	if (c == 'n' || c == 'N')
	{
		cout << "Enter your name again please: ";
		cin.ignore();
		getline(cin , a);
	}
	else 
	{
		while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
		{
			cout << "Invalid\nInput your choice again please: ";
			cin >> c;
		}
		if (c == 'y' || c == 'Y')
		cout << "Thanks.\n";
		else if (c == 'n' || c == 'N')
		{
			cout << "Enter your name again please: ";
			cin.ignore();
			getline(cin , a);
		}
	}
	cout << "Enter your account number: ";
	cin >> b;
	bankAccount A(a, b);

	float w;
	cout << "How much money you wanna withdraw: ";                  //These function callings are for checking purposes
	cin >> w;
	A.withdrawl(w);

	float d;
	cout << "Enter amount you wanna deposit: ";
		cin >> d;
		A.deposit(d);

		A.print();
		cout << "Enter amount you wanna deposit: ";
		cin >> d;
		A.deposit(d);
		cout << "How much money you wanna withdraw: ";
	cin >> w;
	A.withdrawl(w);
	A.print();

}