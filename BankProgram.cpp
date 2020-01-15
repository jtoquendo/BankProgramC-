
/* CIT 120 Gradable Project 2 (Group 3)
*
* This program will begins with five savings accounts and five checking accounts with preassigned balances. 
* Program will prompt the user for an account number and validate (EX. A1234567).
* It contains 5 options/actions to perform, 1. make a deposit, 2. make a withdrawal, 3. transfer funds, 4. check balance, 5. exit the program
* To begin the program, please refer to five preassigned Account IDs : "A1234567", "B2345678", "C3456789", "D4567890", "E5678901" 
*
* Written by : Dongwoo, Juan, Joshua, Luke, and Naoufal.
*
* Data Modified : 1 November, 2017
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	string s, t;
    	// Variables, Arrays design created by Dongwoo
	string id[5] = { "A1234567", "B2345678", "C3456789", "D4567890", "E5678901" };
	// 5 account ID
	double balance[5][2] = { { 500.00, 600.00 }, { 300.00, 400.00 }, { 300.00, 900.00 }, { 400.00, 600.00 }, { 500.00, 200.00 } };  // 2 accounts were preassigned for each account
	double action, amount = 0.00;
	int j, i;

	setprecision(2);
	// show upto two decimal places
	do{
		system("cls");
		cout << "\t*******************************\n"
		// Banner/Menu design by Dongwoo, Juan, Luke, Joshua and Naoufal
		<< "\t  Welcome to CIT Bigbuck Bank  \n"
		<< "\t*******************************\n\n"
		<< "\t1. Make a Deposit   \n"
		<< "\t2. Make a Withdrawal\n"
		<< "\t3. Transfer Funds   \n"
		<< "\t4. Check Balance    \n"
		<< "\t5. EXIT             \n\n";

		cout << "Choose the action to perform (1-5): ";
		// Prompt the user for action to be performed
		while (!(cin >> action) || (action < 1 || action > 5))
		// by Dongwoo, Juan, Luke,  and Naoufal
		{
			cin.clear();
			cin.ignore(80, '\n');
			// Only read the first digit and validate, any garbage after first digit will be ignored
			cout << "Invalid input.  Try again: ";
			// action validation by Dongwoo
		}

		if (action == 5){
		// Exit feature by Dongwoo
		cout << "Thank you for visiting us! See you next time! " << endl;
		system("pause");
		exit(0);
	}

	cout << "Enter your account ID (EX.D1234567): ";
	//prompt the user for account ID
	cin >> s;
	//by Dongwoo, Juan, Luke, Joshua, and Naoufal

	while ((s.length() < 8) || (s[0] < 'A' || s[0] > 'Z'))
	//account number validation by Dongwoo
	{
		cin.clear();
		cout << "Account number has to be 8 digits with first digit as a uppercase letter\n"
		<< "Try again: ";
		cin >> s;
	}
	if (s == id[0])
	// account search condition statements by dongwoo, Luke, Juan, and Joshua
	j = 0;
	else if (s == id[1])
	j = 1;
	else if (s == id[2])
	j = 2;
	else if (s == id[3])
	j = 3;
	else if (s == id[4])
	j = 4;
	else
	j = 5;

	if (j != 5){
	// show balance task by dongwoo
	if (action == 4){
	cout << "Access granted!\n";
	cout << "Your current balance is checking $" << balance[j][0] << ", and savings $" << balance[j][1] << endl;
	}
	else{
		cout << "Access granted!\n"
		<< "Please choose account type.\n"
		<< "Enter [1] for Checking or [2] for Savings: ";
		//prompt user to select account type
		while (!(cin >> i) || (i <= 0 || i > 2) ){
		// checking and savings validation by dongwoo, Naoufal
		cin.clear();     cin.ignore(80, '\n');
		cout << "Invalid option chosen. Try again: ";
	}
	i = i - 1;
	cout << "Your current balance is $" << balance[j][i] << ".\n";
	// output the remaining balance of account chosen
	cout << "Enter an amount: $";
   // amount validation by dongwoo park
	while (!(cin >> amount) || !(amount > 0)){
	cin.clear();  cin.ignore(80, '\n');
	cout << "Invalid input. Try again: ";
	}
}
switch ((int)action){
	case 1:
	balance[j][i] += amount; cout << "Successfully deposited, your current balance is $" << balance[j][i] << ".\n"; break;     // deposite task by Juan, dongwoo, Naoufal, and Joshua
	case 2:
	if (balance[j][i] <= 0.00){
 	 // withdraw task by dongwoo, Juan, Luke, Naoufal, and Joshua
	cout << "Sorry, your account does not have enough balance. Thank you." << endl;
}
else{
	if (amount > balance[j][i]){
	cout << "Sorry, your account does not have enough balance. Thank you." << endl;
}
else{
	balance[j][i] -= amount; cout << "Successfully withdrawn, your current balance is $" << balance[j][i] << ".\n";
	}
} break;
case 3:
if ((balance[j][i] <= 0.00) || (amount > balance[j][i])){
// Transfer funds task by dongwoo
cout << "Sorry, your account does not have enough balance.Thank you." << endl;
}
else{
if (i == 0){
// When balance reaches 0, don't do the task
balance[j][0] -= amount;
balance[j][1] += amount;
}
if (i == 1){
balance[j][0] += amount;
balance[j][1] -= amount;
}
cout << "Sucessfully transferred, checking balance: $" << balance[j][0] << ", savings balance: $" << balance[j][1] << ".\n"; break;
default:
break;
}
}
}
else
cout << "Account ID cannot be found, please check your account number and try again!" << endl;
cout << "Continue? (Y/N)";
} while (toupper(_getch()) != 'N');
return 0;
}
