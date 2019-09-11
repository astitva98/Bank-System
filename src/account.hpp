#ifndef acc_hpp
#define acc_hpp
#include<string>
// #include "card.hpp"
#include"transaction.hpp"
#include<unordered_set>

#include "user.hpp"
using namespace std;

class Card;


class Account{
	Card* dcard;
	Card* ccard;
	User u;
	int acc_type;
	int maxTrans;
	int trans;
	int acno;
	float balance;
	Transaction* transactions;
	string secret;

public:
	Account(void);
	void newAccount(User u , int ac_type , int acno , string pass , Card& card1 , Card& card2 , string c1 , string c2);
	bool makeWithdraw(float amount);
	// ~Account();
	void endAccount( string pass);
	int getTransactionCount();
	void newTransaction(int type , float amount);
	// void open();
	// void close();
	float getBalance();
	void getTransactions(string pass);
	bool makeDeposit(float amount);
	bool makeWithdraw(string pass , float amount);
	void getDetails(string pass);
	int getAcno();
	int getTrans();


	
	// void getTransactions();
};


class Card{
	string cardNo;
	string cvv;
	string secret;
	string expiry;
	
	
	// int cardType;
public:
	Card();
	Account* account;
	void endCard();
	void newCard(Account* ac , string c1 , int type);
	string getCardNo();
	int cType;
	void makeWithdraw(string pass , float amount);

};

class Ccard : public Card{
	float limit;
	float rate;
public:
	Ccard(Account* ac);

	// newCcard();
};

class Dcard : public Card{
public:
	Dcard(Account* ac);
	// newDcard();
	
};

string randomString(int i);




#endif