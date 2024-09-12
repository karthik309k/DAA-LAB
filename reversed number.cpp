#include<iostream>
using namespace std;
 int main() {
 	int number,originalnumber = 0;
 	cout<<"enter the number:";
 	cin>>number;
 	while (number != 0){
	 
 	    int digit = number % 10;
       	originalnumber = originalnumber*10 + digit;
 	    number /=10;
    }
 	if (round(result) == number)
        cout << number << " is an Armstrong number." << endl;
    else
        cout << number << " is not an Armstrong number." << endl;

    return 0;
}
