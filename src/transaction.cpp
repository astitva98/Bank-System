#include "transaction.hpp"
#include<string>
#include<iostream>

using namespace std;


Transaction::Transaction(){
	transactionType = 0;
	amount = 0.0;
}

Transaction::Transaction(int type , float f){
	transactionType = type;
	amount = f;
}

int Transaction::getTransactionType(){
	return transactionType;
}

float Transaction::getAmount(){
	return amount;
}

