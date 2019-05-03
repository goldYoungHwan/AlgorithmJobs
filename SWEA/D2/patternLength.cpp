#include <iostream>
#include <string>

using namespace std;

int compareString(string cmp, string input) {
	string a;
	int cmpLength = cmp.size();
	int flag = 0;

	for (int j = 1; j <= input.size() / cmpLength; j++) {
		a.assign(input, j*cmpLength, cmpLength);
		if (j != 1 && cmpLength > a.size()) {
			flag = 1;
			break;
		}
		if (cmp != a)
			break;
	}
	return flag;
	
}

int main() {
	int t;
	cin >> t;
	string input;
	int i = 1;
	string cmp="";
	int flag = 0;

	while (t>=i) {
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			cmp += input[j];
			flag = compareString(cmp, input);
			if (flag == 1)
				break;
		}

		cout << "#" << i << " " << cmp.size() << endl;
		i++;
		cmp = "";
	}
}