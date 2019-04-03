#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int visit[100001] = { 0 };


void findSister(int x, int y) {
	queue<pair<int, int>> queFind;

	int time = 0;
	queFind.push({ x, time });

	while (!queFind.empty()) {
		int soobeanLocation = queFind.front().first;
		time = queFind.front().second;
		visit[soobeanLocation] = 1;

		queFind.pop();
		if (soobeanLocation == y) {
			cout << time << endl;
			return;
		}

		time++;

		if (soobeanLocation - 1 >= 0 && visit[soobeanLocation - 1] == 0) {
			queFind.push({ soobeanLocation - 1, time });
		}

		if (soobeanLocation + 1 <= 100000 && visit[soobeanLocation + 1] == 0) {
			queFind.push({ soobeanLocation + 1, time });
		}

		if (soobeanLocation * 2 <= 100000 && visit[soobeanLocation * 2] == 0) {
			queFind.push({ soobeanLocation * 2, time });
		}
	}
}

int main() {
	int soobean, sister;
	cin >> soobean >> sister;

	findSister(soobean, sister);
}