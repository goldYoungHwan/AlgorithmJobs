#include <iostream>
#include <vector>
#include <map>

using namespace std;

//�ֻ��� �̵�����
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

	int cx = x, cy = y; // ���� �ֻ��� ��ġ
	int diceMid = 1; // ó�� �ֻ����� ������ ������ ��

	int dx[4] = { 1, -1, 0, 0 }; // �������� �̵�
	int dy[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < move.size(); i++) { // �̵���� ����ŭ
		
		int change = move[i];
		cx += dx[change - 1];
		cy += dy[change - 1]; // �̵�
		if ((cx >= 0 && cx < m) && (cy >= 0 && cy < n)) { // ���� �ȿ� ���� ��쿡�� ����
			diceMid = standard[diceMid][change]; // diceMid �� 0->1�� ����...
			
			if (square[cy][cx] == 0) {
				square[cy][cx] = dice[crossSide[diceMid]]; // �ֻ��� ���� ������ �Է�.. �ֻ����� 0�̾ �������.
			}
			else {
				dice[crossSide[diceMid]] = square[cy][cx];
				square[cy][cx] = 0;
			}
			cout << "���� �ϴ� : " << diceMid << " ���� �ٴ� : " << crossSide[diceMid] << " ";
			cout << dice[diceMid] << endl; // �ݴ��� �ֻ����� ��
		}
	}
}

int main() {
	int n, m; // ���� ũ��
	int x, y; // �ֻ��� ��� ��ġ
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

	moveDice(square, move, x, y, n, m); // �̵��ϸ鼭 ��� ��� �Լ�
}