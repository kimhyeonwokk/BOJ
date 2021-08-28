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
	int sum = 10;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i])
			sum += 5;
		else if (s[i - 1] != s[i])
			sum += 10;
	}
	cout << sum;

}
