#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	int t;
	int k = 1;
	int aMonth, bMonth, aDate, bDate;
	map<int, int> date;

	date.insert({ 1, 31 });
	date.insert({ 2, 28 });
	date.insert({ 3, 31 });
	date.insert({ 4, 30 });
	date.insert({ 5, 31 });
	date.insert({ 6, 30 });
	date.insert({ 7, 31 });
	date.insert({ 8, 31 });
	date.insert({ 9, 30 });
	date.insert({ 10, 31 });
	date.insert({ 11, 30 });
	date.insert({ 12, 31 });

	cin >> t;

	while (t--) {
		int totalDate;
		cin >> aMonth >> aDate >> bMonth >> bDate;

		if (bMonth - aMonth == 0) {
			totalDate = bDate - aDate + 1;
		}
		else if (bMonth - aMonth == 1) {
			totalDate = date.find(aMonth)->second - aDate + 1 + bDate;
		}
		else {
			totalDate = date.find(aMonth)->second - aDate + 1;
			for (int i = aMonth+1; i < bMonth; i++) {
				totalDate += date.find(i)->second;
			}
			totalDate += bDate;
		}
		cout << "#" << k++ << " " << totalDate << endl;
	}
}