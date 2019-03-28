#include <iostream>
#include <stack>
#include <map>
using namespace std;

int check[100][100] = { 0 }; // 방문 체크

class Area {
public:
	int moveNum;
	int x;
	int y;

	Area(int num, int x, int y);
};

Area::Area(int num, int x, int y) {
	this->moveNum = num;
	this->x = x;
	this->y = y;
}

void findArea(stack<Area>& move, int **arr, int n) {
	
	while(!move.empty()) {

		int count = move.top().moveNum;
		int y = move.top().y;
		int ny = move.top().y + count;
		int x = move.top().x;
		int nx = move.top().x + count; // 이동..

		check[x][y] += 1;
		if (check[x][y] == 2) {
			move.pop();
		}
		

		if ((x == n - 1) && (y == n - 1)) {
			cout << "YES" << endl;
			return;
		}
		if ((y+count < n) && (check[x][ny] ==0)) {
			move.push(Area(arr[x][ny], x, ny));
		}else if ((x + count < n) && (check[nx][y] == 0)) {
			move.push(Area(arr[nx][y], nx, y));
		}
	}
	cout << "NO" << endl;
}

int main() {
	int num;
	int n;
	int input;

	cin >> num >> n;

	int **arr = new int*[n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}

	stack<Area> move;
	int start = arr[0][0]; // 첫 이동수 입력
	int x = 0, y = 0; // 첫 시작점

	move.push(Area(start, x, y));

	findArea(move, arr, n);
}