#ifndef card_hpp
#define card_hpp
#include <string>


using namespace std;


class Card{
	string cardNo;
	string cvv;
	string secret;
	string expiry;
	Account* account;
	int cardType;
public:
	Card();
	newCard(Account* ac , int type);

};


#endif