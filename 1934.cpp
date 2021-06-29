// 1934
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int n;
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
}
