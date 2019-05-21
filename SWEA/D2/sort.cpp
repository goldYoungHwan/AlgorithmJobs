#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	int k = 1;
	cin >> t;

	while (t--) {
		cin >> n;

		int *arr = new int[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr+n);

		cout << "#" << k << " ";
		
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";

		cout << endl;
		k++;
	}
}