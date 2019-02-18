#include <iostream>
#include <string>
using namespace std;



class bankAccount
{
    string name;
	int id;
	float balance;
	float balance_limit;
	float* trans;
	int translimit;
	int trans_size;
	float *transs;

public:
	void print();
	void deposit(float a);
	void withdrawl(float a);
	void inc_trans();



	bankAccount(string name, int id);
	~bankAccount();
};