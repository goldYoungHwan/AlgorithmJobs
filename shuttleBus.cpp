#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

void timeCalculate(deque<string> &busQue, string start, int num, int term) {
	busQue.push_front(start); // 시작 시간 넣기
	
	string token;
	string hour= "09";
	string minute= "00";

	for (int i = 0; i < num - 1; i++) {
		int temp = stoi(minute) + term;

		minute = to_string(temp);

		if (minute >= "60") {
			temp = stoi(minute) / 60;
			hour = to_string(stoi(hour) + temp);
			temp = stoi(minute) % 60;
			minute = to_string(temp);
		}
		if (minute.size() == 1)
			minute = "0" + minute;
		token = hour + ":" + minute;
		busQue.push_front(token);
	}
}

void conTime(deque<string> &busQue, queue<string> &crewQue, int member) {
	while (!busQue.empty()) {
		if (busQue.size() == 1) {
			if (crewQue.size() < member) {
				cout << busQue.front() << endl;
				busQue.pop_front();
				return;
			}
			else {
				for (int i = 0; i < member - 1; i++)
					crewQue.pop();
				string answer = crewQue.front();
				string hour = answer.substr(0, 2);
				string minute = answer.substr(3, 2);
				if (minute == "00") {
					hour = to_string(stoi(hour) - 1);
					if (hour.size() == 1)
						hour = "0" + hour;

					cout << hour << ":59" << endl;
					return;
				}
				else {
					minute = to_string(stoi(minute) - 1);
					if (minute.size() == 1)
						minute = "0" + minute;

					cout << hour << ":" << minute << endl;
					return;
				}
			}
		}
		else {
			string bus = busQue.front();
			string crew;
			busQue.pop_front();
			for (int i = 0; i < member; i++) {
				crew = crewQue.front();
				if (crew <= bus)
					crewQue.pop();
			}

		}
	}
}

int main() {

	int num, term, member;
	cin >> num >> term >> member;


	
	vector<string> crew = { "08:03", "08:02", "08:00", "08:01" }; // 크루 넣기.
	//vector<string> crew = { "09:10", "09:09", "08:00" };
	//vector<string> crew = { "09:00", "09:00", "09:00", "09:00", "09:00"};
	//vector<string> crew = { "00:01", "00:01", "00:01", "00:01", "00:01" };
	//vector<string> crew = {"23:59"};
	//vector<string> crew = { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59" };

	sort(crew.begin(), crew.end());

	deque<string> busQue;
	queue<string> crewQue;

	timeCalculate(busQue, "09:00", num, term); // 버스 시간표 넣기.

	for (int i = 0; i < crew.size(); i++) {
		if (busQue.back() < crew[i]) {
			string answer = busQue.back();
			string hour = answer.substr(0, 2);
			string minute = to_string(stoi(answer.substr(3, 2))+1);
			crew[i] = hour+":"+minute;
		}
	}

	for (int i = 0; i < crew.size(); i++)
		crewQue.push(crew[i]);

	conTime(busQue, crewQue, member);
}