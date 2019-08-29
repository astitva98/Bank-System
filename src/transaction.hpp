#ifndef tran_hpp
#define tran_hpp
#include<string>
using namespace std;



class Transaction{
	int transactionType;

	float amount;

public:
	Transaction();
	Transaction(int type , float f);
	int getTransactionType();
	float getAmount();

};


#endif