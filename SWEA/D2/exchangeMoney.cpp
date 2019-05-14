#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	int input;
	int i = 1;

	vector<int> money;
	vector<int> count;

	money.push_back(50000);
	money.push_back(10000);
	money.push_back(5000);
	money.push_back(1000);
	money.push_back(500);
	money.push_back(100);
	money.push_back(50);
	money.push_back(10);

	cin >> t;

	while (t--) {

		cin >> input;

		//vector<int> count;

		for (int i = 0; i < money.size(); i++) {
			count.push_back(input / money[i]);
			input = input % money[i];
		}


		cout << "#" << i << endl;

		for (int i = 0; i < count.size(); i++) {
			cout << count[i] << " ";
		}
		cout << endl;
		count.clear();
		i++;
	}
}