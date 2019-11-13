/* #include "Account.h"
Account::Account()
{
    email= "unknown";
    password = "unknown";
    guest = true;
	accountNum = 0;
}
bool satisfyPass(std::string pass)
{
	if(pass.size() > 7)
	{
		for(int i = 0; i < pass.size(); i++)
		{
			if(pass.[i] == '!' || pass.[i] == '@' || pass.[i] == '#' || pass.[i] == '$' || pass.[i] == '%' || pass.[i] == '&')
			{
				return true;
			}
		}
	}
	return false;
}
bool checkAccExist(std::string username)
{
	string name = getAccount(username);
	if(username.toUpper() == name.toUpper())//search database for username and if one is there return true
	{
		return true;
	}
	return false;
}
bool isGuest()
{
    return guest;
}
bool login(std::string username, std::pass) //Not dealing with hashing currently
{
//Currently assuming is case based
    if(username == email && pass == password){
    email = username;
    password = pass;
    guest = false;

        return true;}
    else
    {return false;}
}
std::string passHash(std::string pass) //change the password into a string of numbers instead
{
	std::string number = "";
	int num = 0;
	while(pass.length > num)//get the first character in the string and convert it to a 2 digit number and add it to the new string number
	{
		//number system is shifted up 14 so that A is 14 and Z is 40
		//symbols are placed before the letter A
		if(pass[num]=='A')//switch probably better option........
		{
			number += "14"
		}
		num++;
	}
	
}
void createAccount(std::string username, std::string pass)
{
	addUser(username, pass); //should pass the username and password to be added into the database
}
void deleteAccount()
{
	deleteUser(accountNum);//should remove all relevent information of the accoount in the database
}
void logout()//resets the account login information.
{
	email= "unknown";
    password = "unknown";
    guest = true;
    accountNum = 0;
}
*/
