#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	//Please Enter Your Code Here

	int date;
	int carNumber[5];
	int result = 0;

	cin >> date;
	for (int i = 0; i<5; i++) {
		cin >> carNumber[i];
	}
	for (int i = 0; i<5; i++) {
		if (date == carNumber[i]) {
			result++;
		}
	}
	cout << result;

	return 0;
}