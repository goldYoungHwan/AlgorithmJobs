#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int t, n;
	int k = 1;
	cin >> t;

	while (t--) {

		int sum = 0;
		double average;
		int a[10];

		for (int i = 0; i < 10; i++)
			cin >> a[i];

		sort(a, a + 10);
		
		for (int i = 1; i < 9; i++)
			sum += a[i];

		average = round(sum/double(8));

		cout << "#" << k++ << " " << average<< endl;
	}
}