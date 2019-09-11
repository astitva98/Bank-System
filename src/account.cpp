#include "account.hpp"
#include<string>
#include<iostream>

using namespace std;

Account::Account(void){
	acno = -1;
	secret = "";
	transactions = NULL;
	trans = 0;
	acc_type = 0;
	maxTrans = 0;


}

void Account::newAccount(User us , int ac_type , int acno1 , string pass , Card& card1 , Card& card2 , string c1 , string c2){

	u = us;
	acno = acno1;
	acc_type = ac_type;
	secret = pass;
	maxTrans = 10;
	balance = 0.0;
	card1.newCard(this , c1 , 1);
	card2.newCard(this , c2 , 2);
	// else				&c2 = NULL;
	ccard = &card2;
	dcard = &card1;
	transactions = new Transaction[maxTrans];
	cout<<"New Account Opened!\nWelcome "<<u.getName()<<".\n\n";
	cout<<"DBGOPT total trans areeeee "<<trans<<endl;
	// Card->newCard(this);
	return;
}

void Account::endAccount(string pass){
	if(pass != secret){
		cout<<"Wrong Password.\nExiting...\n\n";
		return;
	}
	// delete u;
	acno = -1;
	secret = "";
	balance = 0.0;
	delete [] transactions;
	transactions = NULL;
	acc_type = 0;
	trans = 0;
	dcard->endCard();
	ccard->endCard();
	return;
}

int Account::getTransactionCount(){
	return trans;
}


void Account::newTransaction(int type , float amount){
	// if(trans == maxTrans-1){
	// 	Transaction* temp = new Transaction[2*maxTrans];
	// 	for(int i=0;i<maxTrans;i++){
	// 		transactions[i] = temp[i];
	// 	}
	// 	transactions = temp;
	// 	maxTrans = 2*maxTrans;
	// }
	Transaction temp(type , amount);
	transactions[trans] = temp;
	trans = trans+1;
	cout<<"DBGOPT 3\n"<<trans<<endl;
	return;

}

// void Bank::open(){

// }

float Account::getBalance(){
	return balance;
}

void Account::getTransactions(string pass){
	if(pass != secret)	return;
	cout<<"Your Current Balance is : "<<balance<<" Rupees.\n";
	cout<<"You have total "<<trans<<" transactions.\n";
	// cout<<"DBGOPT 4\n";

	for(int i=0;i<trans;i++){
		cout<<"Transaction "<<i+1<<" : ";
		if(transactions[i].getTransactionType() == -1){
			cout<<"Debit  : Rupees "<<transactions[i].getAmount()<<".\n";
		}
		else{
			cout<<"Credit : Rupees "<<transactions[i].getAmount()<<".\n";
		}
	}
}

bool Account::makeDeposit(float amount){
	cout<<"DBGOPT2 "<<endl;
	balance = balance+amount;
	newTransaction(1,amount);
	return true;
}

bool Account::makeWithdraw(string pass  ,float amount){
	if(secret == pass){
		if(balance >= amount){
			balance = balance - amount;
			newTransaction(-1 , amount);
			return true;
		}
		cout<<"Insufficient Funds\n\n";
		return false;
	}
	return false;

}

void Account::getDetails(string pass){
	if(secret==pass){
		cout<<"Welcome "<<u.getName()<<".\n";
		cout<<"Your Current Balance is : "<<balance<<" Rupees.\n";
		cout<<"You have total "<<trans<<" transactions.\n";

	}
}

int Account::getAcno(){
	return acno;
}

int Account::getTrans(){
	return trans;
}

string randomString(int a){
	string res;
	
	for(int i=0;i<a;i++){
		res.push_back(((char)(rand()%9))+'0');
	}
	return res;

}

Card::Card(){
	cvv = randomString(3);
	// string temp ;
	// int fg = 1;
	// while(fg){
	// 	fg = 0;
	// 	temp = randomString(16);
	// 	for(auto it:cardLi){
	// 		if(it==temp)	fg=1;
	// 	}
	// }
	// cardNo = temp;
	// cardLi.insert(temp);
	// cout<<"\nEnter the password\n";

	// cin>>secret;
}

void Card::endCard(){
		// cardLi.erase(cardLi.find(cardNo));
		cardNo = "";
		cvv = "";
		secret = "";
		expiry = "";
		// limit = 0.0f;
		// rate = 0.0f;

}


string Card::getCardNo(){
	return cardNo;
}

bool Account::makeWithdraw(float amount){
	return this->makeWithdraw(this->secret , amount);
}

void Card::makeWithdraw(string pass , float amount){

	if(pass == secret){
		if(account->makeWithdraw(amount)){
			cout<<"\nWithdraw Sucessful\n";

		}
		else{
			cout<<"\nInsufficiant Funds\n";
		}
		return;
	}
	else{
		cout<<"\nWrong Password\n";
	}
	return;

}

void Card::newCard(Account* ac , string c1 , int type){
	account = ac;
	if(type==1)
		cout<<"\nYour Debit card number is : "<<c1<<".\n";
	else
		cout<<"\nYour Credit card number is : "<<c1<<".\n";
	cardNo = c1;
	cType = type;
	if(type == 1)
		cout<<"\nEnter the password for your debit card\n";
	else
		cout<<"\nEnter the password for your credit card\n";

	// if(type == 1)
	// 	// limit = 0.0f;
	// else
	// 	limit = 500000.0f;
	// rate = 5.5f

	cin>>secret;

}

Ccard::Ccard(Account* ac){
	account = ac;
	limit = 500000.0f;
	rate = 5.5f;
	
}

Dcard::Dcard(Account* ac){
	account = ac;
}