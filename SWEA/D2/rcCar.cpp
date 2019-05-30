#include <iostream>

using namespace std;

int main() {
	int t;
	int k = 1;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int speed = 0;
		int distance = 0;

		int firstCommand;
		int secondCommand;
		for (int i = 0; i < n; i++) {
			cin >> firstCommand;

			if (firstCommand == 0) {
				distance += speed * 1;
			}
			else {
				cin >> secondCommand;
				firstCommand == 1 ? speed += secondCommand : speed -= secondCommand;

				if (speed < 0)
					speed = 0;
				distance += speed * 1;
			}
		}

		cout << "#" << k++ << " " <<distance << endl;
	}
}