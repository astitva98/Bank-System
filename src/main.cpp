#include<iostream>
#include<string>
#include "bank.hpp"
using namespace std;


// string randomString(int a){
// 	string res;
	
// 	for(int i=0;i<a;i++){
// 		res.push_back(((char)(rand()%9))+'0');
// 	}
// 	return res;

// }
//add credit and debit card functionality

//
bool parseNumber(string number){
	long long int op;
	
	for(int i=0;i<10;i++){
		if(number[i] > '9' || number[i] < '0')	return false;
	}
	return true;
}
void initialize(Bank& bank){
	return;
}
bool sanatizeAcno(string acno , Bank& bank , int size = 7 , int type = 1){
	if(type==1){
		if(acno.size() !=size){
			cout<<"\nWrong acno\n";
			return false;
		}
		// int op;
		
		for(int i=0;i<size;i++){
			if(acno[i] > '9' || acno[i] < '0')	return false;
		}
		if(bank.findAccount(stoi(acno))!=-1)	return false;
		return true;
	}
	else{
		if(bank.findCard(acno)!=-1)	return false;
		return true;
	}
}
int sanatizeAcno(string acno){
	if(acno.size() !=7){
		cout<<"\nWrong acno\n";
		return -1;
	}
	for(int i=0;i<7;i++){
		if(acno[i] > '9' || acno[i] < '0')	return -1;
	}
	// if(bank.findAccount(op)!=-1)	return false;
	return stoi(acno);
}
bool newAccount(Bank& bank){
	string a;
	cout<<"\nEnter your first name\n";
	cin>>a;
	string b;
	cout<<"\nEnter your last name\n";
	cin>>b;
	cout<<"\nMale/Female (M/F)\n";
	int g;
	char gen;
	cin>>gen;
	int fg = 1;
	while(fg){
		if(toupper(gen) == 'M'){	
			g = 1;
			fg=0;
		}
		else if(toupper(gen) == 'F'){	g = 2;
			fg=0;}
		else{
			cout<<"\nwrong imput, please try again\n";
		}
	}
	string number;
	cout<<"\nEnter 10 digit mobile number\n";
	int f2 = 1;
	while(f2){
		cin>>number;
		if(number.size()==10 && parseNumber(number)==true){
			f2=0;
		}
		else{
			cout<<"\nWrong number, Try again\n";
		}
	}
	User u(a,b , g , number);
	fg=1;
	int cho;
	while(fg){
		cout<<"\nChoose Account type\nPress 1 for savings account\nPress 2 for credit account\n";
		
		cin>>cho;
		if(cho == 1 || cho == 2)	fg=0;
		else	cout<<"\nWrong choice, please try again\n";
	}
	string acno;
	cout<<"\nEnter a 7 digit account number\n";
	int flag = 1;
	
	int acc;
	// TBD sanetize acno and chk for duplicates
	while(flag){
		cin>>acno;
		if(acno.size() == 7 && sanatizeAcno(acno , bank)){
			acc = stoi(acno);
			flag = 0;
		}
		else{
			cout<<"Wrong input or account number already exists, please try again\n";
		}
	}
	string pass;
	cout<<"Enter the Password\n";
	cin>>pass;
	string c1 ;
	string c2 ;
	flag = 1;
	while(flag){
		c1 = randomString(5);
		if(sanatizeAcno(c1 , bank , 5 , 2))	flag = 0;
		// string c2 = randomString(16);
	}
	flag = 1;
	while(flag){
		c2 = randomString(5);
		if(sanatizeAcno(c2 , bank , 5 , 2))	flag = 0;
		// string c2 = randomString(16);
	}
	// Account ac(u , cho , acc , pass);
	return bank.openAccount(u , cho , acc , pass , c1,c2);

}

void closeAccount(Bank& bank){

	cout<<"Enter Your Account Number\n";
	string acno;
	cin>>acno;
	int acn = sanatizeAcno(acno);
	cout<<"Enter the password\n";
	string pass;
	cin>>pass;

	int indx = bank.findAccount(acn);
	if(indx == -1){
		cout<<"Accout does not exist\nbye\n\n";
		return;
	}

	bank.endAccount(indx , pass);

	return;

}

void withdraw(Bank& bank){

	string acno;
	cout<<"Enter the account number\n";
	cin>>acno;
	int acc = sanatizeAcno(acno);
	cout<<"\n\n"<<acc<<"\n\n";
	int indx = bank.findAccount(acc);
	if(indx == -1){
		cout<<"\nAccount Not Found\n\n";
		return;
	}
	string pass;
	cout<<"Enter the Password\n";
	cin>>pass;
	float amount;
	Account* temp = bank.getAccount(indx);
	cout<<"Enter amount\n";
	cin>>amount;
	if(amount < 0){
		return;
	}
	temp->makeWithdraw(pass , amount);


	return;

}

void deposit(Bank& bank){
	float amount;
	cout<<"Enter amount\n";
	cin>>amount;
	string acno;
	cout<<"Enter the account number\n";
	cin>>acno;
	int acc = sanatizeAcno(acno);

	int indx = bank.findAccount(acc);
	if(indx == -1){
		return;
	}
	Account* temp = bank.getAccount(indx);

	temp->makeDeposit(amount);
	return;

}

void accountInfo(Bank& bank){
	string acno;
	cout<<"Enter the account number\n";
	cin>>acno;
	int acc = sanatizeAcno(acno);

	int indx = bank.findAccount(acc);
	if(indx == -1){
		return;
	}
	string pass;
	cout<<"Enter the Password\n";
	cin>>pass;
	float amount;
	Account* temp = bank.getAccount(indx);

	temp->getDetails(pass);

}

void accountHistory(Bank& bank){
	string acno;
	cout<<"Enter the account number\n";
	cin>>acno;
	int acc = sanatizeAcno(acno);

	int indx = bank.findAccount(acc);
	if(indx == -1){
		return;
	}
	cout<<"DEBUGOPT "<<indx<<'\n';
	string pass;
	cout<<"Enter the Password\n";
	cin>>pass;
	// float amount;
	Account* temp = bank.getAccount(indx);

	// if(temp->secret == pass){
		temp->getDetails(pass);
		temp->getTransactions(pass);
		return;
	// }
}

void menu(){
	cout<< "\n\n------------------------------------------\n";
	cout<< "| Press E to close the application       |\n";
	cout<< "| Press N to open new account            |\n";
	cout<< "| Press C to close the account           |\n";
	cout<< "| Press W to withdraw money              |\n";
	cout<< "| Press D to deposit money               |\n";
	cout<< "| Press I to get account info            |\n";
	cout<< "| Press H to get your transaction history|\n";
	cout<< "------------------------------------------\n\n\n";
	return;
}

int main(){
	Bank bank;

	initialize(bank);

	bool rn = true;
	while(rn){
		menu();
		char ch;
		cin>>ch;
		ch = toupper(ch);
		switch(ch){
			case 'E' : {
				rn = false;
				break;
			}
			case 'N' : {
				newAccount(bank);
				break;
			}
			case 'C' : {
				closeAccount(bank);
				break;
			}
			case 'W' : {
				withdraw(bank);
				break;
			}
			case 'D' : {
				deposit(bank);
				break;
			}
			case 'I' : {
				accountInfo(bank);
				break;
			}
			case 'H' : {
				accountHistory(bank);
				break;
			}
			default : {
				cout<<"Wrong input, please try again\n";
				break;
			}
		}
	}

	return 0;
}