#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> match;

void change(string &input) {
	int count = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '#') {
			input[i] = ' '; // # NULL로 초기화
			input[i - 1] = tolower(input[i - 1]); // 해당 문자 소문자로 변환
			count++;
		}
		//remove(input.begin(), input.end(), ' '); // algorithm header file포함
		input.erase(remove(input.begin(), input.end(), ' '), input.end()); // remove함수로 원하는 문자열 제거 후, 
	}
}


class Music {
public:

	int duration;
	string title;
	string info;
	string findStr;

	Music(vector<string> input, string findStr);
	void check();
};

vector<string> split(string input, char token) {
	vector<string> internal;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, token)) {
		internal.push_back(temp);
	}

	return internal;
}

Music::Music(vector<string> input, string findStr) {
	int startHour = stoi(input[0].substr(0, 2));
	int endHour = stoi(input[1].substr(0, 2));
	int startMin = stoi(input[0].substr(3, 2));
	int endMin = stoi(input[1].substr(3, 2));

	this->duration = (endHour - startHour) * 60 + endMin - startMin;
	this->title = input[2];
	
	change(input[3]); // 문자변환
	this->info = input[3];
	this->findStr = findStr;

	check();
}

void Music::check() {
	string newInfo = info;

	if (duration <= info.size()) {
		string temp = info.substr(0, duration);
		if (temp.find(findStr) != string::npos) { // 찾는 곡이 실행시간 동안 재생된 악보에 있는지 확인
			match.push_back(title);
		}
		else {
			match.push_back("none");
		}
	}
	else { // 재생시간이 악보보다 큰 경우
		int count = duration / info.size(); // 재생 반복 횟수
		int rest = duration % info.size(); // 재생 반복 횟수 나머지
		for (int i = 0; i < count - 1; i++) {
			newInfo.append(info);
		}
		newInfo.append(info.substr(0, rest)); // 나머지 부분 만큼 붙이기

		if (newInfo.find(findStr) != string::npos) {
			match.push_back(title);
		}
		else {
			match.push_back("none");
		}
	}
}


int main() {
	string findStr;
	cin >> findStr;
	
	change(findStr); // 문자변환


	vector<string> input = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
	//vector<string> input = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
	//vector<string> input = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
	vector<Music> music;

	for (int i = 0; i < input.size(); i++) {
		vector<string> strSplit = split(input[i], ',');
		music.push_back(Music(strSplit, findStr));
	}

	for (int i = 0; i < match.size(); i++) {
		cout << match[i] << endl;
	}
}