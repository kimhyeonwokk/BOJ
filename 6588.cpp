// 6588
#include <iostream>
#include <vector>
bool check[1000000] = { 0 };
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int index = 0;
	check[2] = 1;
	check[3] = 1;
	check[5] = 1;
	check[7] = 1;
	check[11] = 1;
	check[13] = 1;
	for (int i = 3; i <= 1000000; i++) {
		if (i % 2 == 0) 
			continue;
		if (i % 3 == 0)
			continue;
		if (i % 5 == 0)
			continue;
		if (i % 7 == 0)
			continue;
		if (i % 11 == 0)
			continue;
		for (int k = 2; k*k <= i; k++) {
			if (i % k == 0) {
				index = 1;
				continue;
			}
		}
		if (index == 1) {
			index = 0;
			continue;
		}
		check[i] = 1;
	}
	for (;;) {
		cin >> n;
		if (n == 0) break;
		cout << n << " = ";
		int i = 2;
		for (;;) {
			if (check[i] == 0) {
				i++;
				continue;
			}
			if (check[i] == 1 && check[n - i] == 1) {
				cout << i << " + " << n - i << "\n";
				break;
			}
			i++;
		}
	}
}
