#include "bank.h"




bankAccount::bankAccount(string nameer, int ider)
{
	name = nameer;
	id = ider;
	balance = 0;
	balance_limit = 200000;
	translimit = 10 ;
	trans = new float [translimit];
	trans_size = 0;
	

}
void bankAccount::inc_trans()
{
	transs = new float [trans_size + 10];
	for (int i = 0 ; i < trans_size ;i++)
	{
		transs[i] = trans[i];
	}
	translimit = translimit + 10;
	delete [] trans;
	trans = nullptr;
	cout << "Transactions add successfully\n";
}

void bankAccount::print()
{
	cout << "<------------------------------------------>\n";
	cout << "\nName:"<<name << endl;
	cout << "Account number: "<<id<<endl;
	if (balance == 0)
		cout << "No Balance present yet\n";
	else 
		cout << "Balance present: "<<balance;
	if (trans_size == 0)
		cout << "No transactions made yet\n";
	else 
		cout << "\nTransactions made: "<<trans_size;
	cout << endl;
	if (trans_size > 0)
	{
		if (trans != nullptr)
		{
			for (int i = 0 ; i < trans_size ;i++)
			cout << "Transaction " << i + 1 << " : " << trans[i]<<endl;
		}
		else 
			{
			for (int i = 0 ; i < trans_size ;i++)
			cout << "Transaction " << i + 1 << " : " << transs[i]<<endl;
		}

	}


}

void bankAccount::deposit (float a)
{
	if (trans_size >= translimit)
	{
		cout << "Your transactions has reached ... so increasing your transactions\n";
		inc_trans();
	}	
		if (balance + a <= balance_limit)
		{
		if (trans != nullptr)
		trans[trans_size] = +a;
		else 
			transs[trans_size] = a;
		trans_size++;
		balance = balance + a;
		cout << "Amount deposited successfully\n";
		}
		else
		{
				cout << "Sorry you can't deposit it because you can't deposit more than 2 lacs\n";
		}
}
void bankAccount::withdrawl(float a)
{
	if (trans_size >= translimit)
	{
		cout << "Your transactions has reached so increasing your transactions\n";
		inc_trans();
	}
	if (a <= balance)
	{
		balance = balance - a;
		if (trans != nullptr)
		trans[trans_size] = -a;
		else 
			transs[trans_size] = a;
		trans_size++;
		cout << "Successfully withdrawn\n";
		cout << "Remaining balance is: "<< balance;
	}
	else if (a > balance)
	{
		//cout << "You are trying to get beyond your auqat\n";
	cout << "Transaction Unsuccessful: Insufficient balance";
	}
}





bankAccount:: ~bankAccount()
{
	if (trans != nullptr)
	{
		delete [] trans;
		trans = nullptr;
	}
	else 
		{
			delete [] transs;
		transs = nullptr;
	}
			
}