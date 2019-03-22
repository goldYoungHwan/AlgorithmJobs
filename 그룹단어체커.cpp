#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main() {

	int N;
	int check[26] = { 0, };
	int result=0;

	string inputString;
	int stringLength;

	cin >> N;
		
	for (int i = 0; i < N; i++) {
		cin >> inputString;
		stringLength = inputString.size();

		for (int j = 0; j < stringLength; j++) {
			if (check[inputString[j] - 97] == 0)
				check[inputString[j] - 97] = 1;
			else
				if (inputString[j - 1] == inputString[j]) {}
				else break;

			if (j == stringLength-1)
				result++;
		}
		inputString = "";
		memset(check, 0, sizeof(check));

	}

	cout << result << endl;
	return 0;
}