// 11723 집합
#include <iostream>
#include <vector>
using namespace std;
bool check[21] = { false };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string temp;
	int temp_int;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "add") {
			cin >> temp_int;
			check[temp_int] = true;
		}
		if (temp == "remove") {
			cin >> temp_int;
			check[temp_int] = false;
		}
		if (temp == "check") {
			cin >> temp_int;
			if (check[temp_int] == true) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (temp == "toggle") {
			cin >> temp_int;
			if (check[temp_int] == true) {
				check[temp_int] = false;
			}
			else {
				check[temp_int] = true;
			}
		}
		if (temp == "all") {
			for (int i = 1; i <= 20; i++)
				check[i] = true;
		}
		if (temp == "empty") {
			for (int i = 1; i <= 20; i++)
				check[i] = false;
		}
	}
}
