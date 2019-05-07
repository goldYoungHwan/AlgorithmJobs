#include <iostream>
#include <memory.h>

using namespace std;

int score[101] = { 0 };

int main() {
	int t;
	int number;
	int input;
	int max;
	int maxScore;

	cin >> t;

	while (t--) {

		cin >> number;

		for (int i = 0; i < 1000; i++) {
			cin >> input;
			score[input]++;
		}
		max = score[0];
		maxScore = 0;

		/*for (int i = 0; i < 101; i++) {
			cout << i << " " << score[i] << endl;
		}*/

		for (int i = 1; i < 101; i++) {
			if (max <= score[i]) {
				maxScore = i;
				max = score[i];
			}
		}

		cout << "#" << number << " " << maxScore << endl;
		memset(score, 0, sizeof(score));
	}
}