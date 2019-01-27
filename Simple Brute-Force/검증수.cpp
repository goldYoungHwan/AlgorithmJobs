#include <iostream>
using namespace std;

#define SIZE 5

int main() {
	int input[SIZE];
	int result=0;

	for (int i = 0; i < SIZE; i++) cin >> input[i];

	for (int i = 0; i < SIZE; i++)
		result = result + input[i] * input[i];


	cout << result % 10 << endl;
}