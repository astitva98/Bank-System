#ifndef usr_hpp
#define usr_hpp

#include<string>
using namespace std;

class User{
	string fName;
	string lName;
	string mob;
	int gender;
public:

	User();
	User(string a , string b , int g , string number);
	string getName();

};


#endif