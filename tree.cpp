#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int org[10][10] = { 5, };
int change[10][10];
vector<int> tree[10][10];

void sorting(int n) {
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() > 1)
				sort(tree[i][j].begin(), tree[i][j].end());
		}
}

void winter(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			org[i][j] += change[i][j];
}

void fall(int n, int k) {
	int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int dy[8] = { 1,-1, 0, 0, 1, 1, -1, -1 };

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			int treeOfCount = tree[i][j].size();
			if (treeOfCount > 0) {
				for (int k = 0; k < treeOfCount; k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int p = 0; p < 8; p++) {
							int nx = i + dx[p];
							int ny = j + dy[p];

							if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n)) {
								tree[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
}

void summer(int i, int j, int k, int size) {
	for (int a = k; k < size; k++) {
		org[i][j] += (tree[i][j][k] / 2);
		tree[i][j].erase(tree[i][j].begin() + k);
		k--;
		size--;
	}
	
}

void spring(int n) {
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			
			if (tree[i][j].size() > 0) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (org[i][j] >= tree[i][j][k]) {
						org[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
					else {
						summer(i,j, k, tree[i][j].size());
						//tree[i][j].erase(tree[i][j].begin() + k);

						break;
					}
						
				}
	
			}
		}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> change[i][j];
			org[i][j] = 5;
		}

	int x, y, age;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> age;
		tree[x-1][y-1].push_back(age);
	}

	sorting(n);


	while (k>0) {

		k--;
		spring(n);
		sorting(n);
		fall(n, k);
		sorting(n);
		winter(n);

	}

	int sum = 0;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) 
			sum += tree[i][j].size();
	
	cout << sum << endl;
}