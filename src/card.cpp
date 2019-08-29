#include "account.hpp"
#include<string>
#include<iostream>
#include<unordered_set>

using namespace std;

string randomString(int a){
	string res;
	
	for(int i=0;i<a;i++){
		res.push_back(((char)(rand()%9))+'0');
	}
	return res;

}

Card::Card(){
	cvv = randomString(3);
	string temp ;
	int fg = 1;
	while(fg){
		fg = 0;
		temp = randomString(16);
		for(auto it:cardList){
			if(it==temp)	fg=1;
		}
	}
	cardNo = temp;
	cardList.insert(temp);
	cout<<"\nEnter the password\n";

	cin>>secret;
}

void Card::endCard(){
		cardList.erase(cardList.find(cardNo));
		cardNo = "";
		cvv = "";
		secret = "";
		expiry = "";

	}

// void Card::newCard(Account* ac , int type){
// 	account = ac;
// 	CardType = tyep;

// }

Ccard::Ccard(Account* ac){
	account = ac;
	limit = 500000.0f;
	rate = 5.5f;
	
}

Dcard::Dcard(Account* ac){
	account = ac;
}