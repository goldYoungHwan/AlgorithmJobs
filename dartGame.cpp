#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

void calculate(vector<int> &score, char input) {
	map<char, int> bonus;
	bonus.insert(make_pair('S', 1));
	bonus.insert(make_pair('D', 2));
	bonus.insert(make_pair('T', 3));

	char star = '*';
	char sharp = '#';

	if (bonus.find(input) == bonus.end()) { // map에서 찾지 못한 경우
		if (input == star) {
			score.back() *= 2;
			if (score.size() > 1)
				score[score.size() - 2] *= 2;
		}
		else if (input == sharp) {
			score.back() *= -1;
		}
	}
	else {
		score.back() = pow(score.back(), bonus[input]);
	}
}

int main() {
	string input;
	cin >> input;

	int length = input.size();
	vector<int> score;

	for (int i = 0; i < length; i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			if (input[i] == '1' && input[i + 1] == '0') {
				score.push_back(10);
				i++; // 두 자리를 넣어줬기 때문에 i 추가 증가
			}
			else {
				score.push_back(input[i] - '0');
			}
		}
		else {
			calculate(score, input[i]);
		}
	}
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += score[i];
	}
	cout << sum << endl;
}