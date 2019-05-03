//#include <iostream>
//
//using namespace std;
//
//void print(int i, int count) {
//	if (count == 0)
//		cout << i << " ";
//	else if (count == 1)
//		cout << "-" << " ";
//	else if (count == 2)
//		cout << "--" << " ";
//	else if (count == 3)
//		cout << "---" << " ";
//}
//int second(int i) {
//	int div;
//	int rest;
//	int count = 0;
//
//	div = i / 10;
//	rest = i % 10;
//
//	if (div != 0 && div % 3 == 0)
//		count++;
//
//	if (rest != 0 && rest % 3 == 0)
//		count++;
//
//	return count;
//}
//int first(int i) {
//
//	int count = 0;
//	if (i % 3 == 0) {
//		count++;
//	}
//
//	return count;
//}
//
//int main() {
//	int n;
//	int div, rest;
//	int count = 0;
//
//	cin >> n;
//	
//	for (int i = 1; i <= n; i++) {
//		if (i >= 1 && i <= 9) {
//			count = first(i);
//			print(i, count);
//		}
//
//		if (i >= 10 && i <= 99) {
//			count = second(i);
//			print(i, count);
//		}
//		if (i >= 100 && i <= 999) {
//			div = i / 100;
//			rest = i % 100;
//			count = first(div);
//			count += second(rest);
//			print(i, count);
//		}
//	}
//	cout << endl;
//}

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	a[10] = { 0 };
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x) {
			a[x % 10]++;
			x = x / 10;
		}
		if (a[3] || a[6] || a[9]) {
			while (a[3]--)
				cout << "-";
			while (a[6]--)
				cout << "-";
			while (a[9]--)
				cout << "-";
			cout << " ";
		}
		else
			cout << i << " ";
	}

}