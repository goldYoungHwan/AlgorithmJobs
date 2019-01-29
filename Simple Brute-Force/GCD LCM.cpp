#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}



int main() {
	int a, b;
	cin >> a >> b;

	int k;
	int glc, lcm;
	k = a > b ? a : b;

	glc = gcd(a, b);
	
	
	lcm = a*b/glc;

	cout << glc << endl << lcm << endl;

	
}