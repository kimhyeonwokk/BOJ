#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
}
int main() {
	init();
	string s;
	cin >> s;
	float score;
	if (s[0] == 'A') {
		score = 4.0;
	}
	else if (s[0] == 'B') {
		score = 3.0;
	}
	else if (s[0] == 'C') {
		score = 2.0;
	}
	else if (s[0] == 'D') {
		score = 1.0;
	}
	else {
		cout <<fixed;
		cout.precision(1);
		cout << 0.0;
		return 0;
	}
	if (s[1] == '+') {
		cout << fixed;
		cout.precision(1);
		cout << score + 0.3;
	}
	else if (s[1] == '0') {
		cout << fixed;
		cout.precision(1);
		cout << score;
	}
	else if (s[1] == '-') {
		cout << fixed;
		cout.precision(1);
		cout << score - 0.3;
	}
}
