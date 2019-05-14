#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair<double, int> &a, const pair<double, int> &b ) {
	return a.first > b.first;
}

int main() {
	int t;
	int j = 1;
	int n, k;
	double a, b, c;

	vector<pair<double, int>> score;
	map<int, string> grade;

	grade.insert({ 1, "A+" });
	grade.insert({ 2, "A0" });
	grade.insert({ 3, "A-" });
	grade.insert({ 4, "B+" });
	grade.insert({ 5, "B0" });
	grade.insert({ 6, "B-" });
	grade.insert({ 7, "C+" });
	grade.insert({ 8, "C0" });
	grade.insert({ 9, "C-" });
	grade.insert({ 10, "D0" });

	cin >> t;
	while (t--) {

		cin >> n >> k;

		for(int i=0; i<n; i++){
			double total = 0;
			cin >> a >> b >> c;

			total =a * 0.35 + b * 0.45 + c * 0.2;
			score.push_back({ total, i+1});

		}

		sort(score.begin(), score.end(), compare);

		int divide = n / 10;

		for (int i = 0; i < score.size(); i++) {
			if (score[i].second == k) {

				if ((i + 1) % divide == 0) {
					cout << "#" << j << " ";
					cout << grade.find((i + 1)/divide)->second << endl;
				}
				else {
					cout << "#" << j << " ";
					cout << grade.find(((i + 1) / divide)+1)->second << endl;
				}
				
			}
		}

		score.clear();
		j++;
	}
}