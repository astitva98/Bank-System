#include "user.hpp"
#include<iostream>

#include<string>

using namespace std;
User::User(){

}
User::User(string a , string b , int g , string number){
	fName = a;
	lName = b;
	gender = g;
	mob = number;
	return;
}

string User::getName(){
	return fName + " " + lName;
}

