#include<iostream>
using namespace std;
 int main () {
 	int num1,num2;
 	
 	cout << "enter first integer: ";
 	cin >> num1;
 	cout << "enter second integer: ";
 	cin >> num2;
 	
 	int addition = num1 + num2;
 	int subtraction = num1 - num2;
 	int multiplication = num1 * num2;
 	int division = num1 / num2;
 	int modulo = num1 % num2;
 	
 	cout <<"addition: " <<num1 << " + " << num2 << " = " << addition << endl;
 	cout <<"subtraction: " << num1 << " - " << num2 << " = " << subtraction << endl;
 	cout <<"multiplication: " << num1 << " * " << num2 << " = " << multiplication << endl;
 	cout <<"division: " << num1 << " / " << num2 << " = " << division << endl;
 	cout <<"modulo: " <<num1 << " % " <<num2 << " = " << modulo << endl;
	 
	 return 0; 
 }
