// 2010
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == n - 1) {
			total += num;
			break;
		}
		total += num - 1;
	}
	cout << total << endl;
}
