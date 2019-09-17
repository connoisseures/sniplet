#include <iostream>
using namespace std;

int divLinear(int dividend, int divisor) {
	int dvs = divisor;
	int dvd = dividend;
	int ans = 0;
	while (dvd > dvs) {
		dvd -= dvs;
		ans++;
	}
	cout << "reminder = " << dvd << endl;
	return ans;
}

int divLog(int dividend, int divisor) {
	int dvs = divisor;
	int dvd = dividend;
	int ans = 0;
	while (dvd > dvs) {
		int shift = 0;
		while (dvd > 2 * dvs) {
			dvs = dvs << 1;
			shift++;
		}
		dvd -= dvs;
		ans += 1 << shift;
		dvs = divisor;
	}
	cout << "reminder = " << dvd << endl;	
	return ans;
}

using namespace std;
int main(int argc, char *argv[]) {
	cout << divLinear(20, 3) << " is quotient" << endl;
	cout << divLog(50, 3) << " is quotient" << endl;

}