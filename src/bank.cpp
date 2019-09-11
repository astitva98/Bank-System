#include<string>
#include<iostream>

#include "bank.hpp"
using namespace std;

Bank::Bank(){
	acs = 0;
	accounts = new Account[MAX_ACCS];
	cards = new Card[MAX_ACCS*2];
	for(int i=0;i<MAX_ACCS ; i++){
		acstatus.insert(i);
		cout<<accounts[i].getTrans()<<endl;
	}
	return;
}

// Account Bank::addAccount(User u , int actype, int acno , string pass){
// 	Account ac(u , actype , acno);
// 	return ac;
// }

bool Bank::openAccount(User u , int ac_type , int acno , string pass , string c1,string c2){
	if(acs == MAX_ACCS-1){
		cout<<"Account cant be opened, Capacity Full\n\n";
		return false;
	}
	int indx = *acstatus.begin();
	// cards[2*indx] = new Dcard();
	// if(ac_type==2)
	// 	cards[2*indx] = new Ccard();
	// else
	// 	cards[2*indx+1] = NULL;
	accounts[indx].newAccount( u , ac_type ,  acno ,  pass , cards[2*indx] , cards[2*indx+1] , c1 , c2) ;
	// cards[indx*2].addAcc(&accounts[indx])
	acstatus.erase(acstatus.begin());
	acs++;
	return true;
}

Card Bank::getCard(int indx){
	return cards[indx];
}

int Bank::findCard(string cNo){
	for(int i=0;i<2*MAX_ACCS;i++){
		if(cards[i].getCardNo() == cNo)	return i;
	}
	return -1;
}

bool Bank::endAccount(int indx , string pass){
	// if(accounts[indx].secret == pass){
		acstatus.insert(indx);
		accounts[indx].endAccount(pass);

		// delete accounts[indx];
		return true;
	
	return false;
}

int Bank::findAccount(int acno1){
	for(int i=0;i<MAX_ACCS;i++){
		if(accounts[i].getAcno() == acno1)	return i;
	}
	return -1;
}

Account* Bank::getAccount(int indx){
	return &accounts[indx];
}

