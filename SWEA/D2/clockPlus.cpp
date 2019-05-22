#include <iostream>

using namespace std;

int main() {
	int t;
	int k = 1;
	cin >> t;

	while (t--) {

		int aHour, aMinute, bHour, bMinute;
		cin >> aHour >> aMinute >> bHour >> bMinute;
		int hour = 0;
		int minute = aMinute+bMinute;

		if (minute >= 60) {
			hour++;
			minute = minute - 60;
		}

		hour += aHour + bHour;
		
		while (hour > 12) {
			hour -= 12;
		}


		cout << "#" << k++ << " "<< hour <<" " << minute <<endl;
	}
}