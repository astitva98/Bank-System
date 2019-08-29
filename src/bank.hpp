#ifndef bank_hpp
#define bank_hpp
#include<unordered_set>
#include<string>
using namespace std;

#include "account.hpp"
#define MAX_ACCS 100
class Bank{
	Account* accounts;
	int acs;
	unordered_set<int> acstatus;
	Card* cards;

public:
	Bank();
	bool openAccount(User u , int ac_type , int acno , string pass , string c1 , string c2);
	// Account addAccount(User u , int actype, int acno , string pass);
	bool endAccount(int indx , string pass);
	int findAccount(int acno1);
	Account* getAccount(int indx);
	int findCard(string cNo);

};

#endif