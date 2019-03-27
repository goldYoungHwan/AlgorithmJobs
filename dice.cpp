#include <iostream>
#include <vector>
#include <map>

using namespace std;

//주사위 이동방향
int standard[7][6] = {
	{0,0,0,0,0},
	{0,4,3,5,2},
	{0,4,3,1,6},
	{0,1,6,5,2},
	{0,2,5,6,1},
	{0,4,3,6,1},
	{0,4,3,2,5} 
};
int dice[7] = {0};

void moveDice(int **square, vector<int> move, int x, int y, int n, int m) {

	map<int, int> crossSide;
	crossSide.insert({ 1, 6 });
	crossSide.insert({ 2, 5 });
	crossSide.insert({ 3, 4 });
	crossSide.insert({ 4, 3 });
	crossSide.insert({ 5, 2 });
	crossSide.insert({ 6, 1 });

	int cx = x, cy = y; // 현재 주사위 위치
	int diceMid = 1; // 처음 주사위가 지도와 만나는 면

	int dx[4] = { 1, -1, 0, 0 }; // 동서남북 이동
	int dy[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < move.size(); i++) { // 이동명령 수만큼
		
		int change = move[i];
		cx += dx[change - 1];
		cy += dy[change - 1]; // 이동
		if ((cx >= 0 && cx < m) && (cy >= 0 && cy < n)) { // 범위 안에 들어올 경우에만 실행
			diceMid = standard[diceMid][change]; // diceMid 가 0->1로 변함...
			
			if (square[cy][cx] == 0) {
				square[cy][cx] = dice[crossSide[diceMid]]; // 주사위 값을 지도에 입력.. 주사위가 0이어도 상관없음.
			}
			else {
				dice[crossSide[diceMid]] = square[cy][cx];
				square[cy][cx] = 0;
			}
			cout << "현재 하늘 : " << diceMid << " 현재 바닥 : " << crossSide[diceMid] << " ";
			cout << dice[diceMid] << endl; // 반대편 주사위의 값
		}
	}
}

int main() {
	int n, m; // 지도 크기
	int x, y; // 주사위 출발 위치
	int num;
	int input;

	vector<int> move;

	cin >> n >> m >> x >> y >> num;

	int **square = new int*[n];

	for (int i = 0; i < n; i++) {
		square[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			square[i][j] = input;
		}
	}
	for (int i = 0; i < num; i++) {
		cin >> input;
		move.push_back(input);
	}

	moveDice(square, move, x, y, n, m); // 이동하면서 결과 찍는 함수
}