// 5598
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') {
			cout << "X"; continue;
		}
		if (s[i] == 'B') {
			cout << "Y"; continue;
		}
		if (s[i] == 'C') {
			cout << "Z"; continue;
		}
		cout << char(s[i] - 3);
	}
}
