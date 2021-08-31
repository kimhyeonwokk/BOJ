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
	string s;
	int num[10] = { 0 };
	cin >> s;
	for (auto i : s) {
		num[i - '0']++;
	}
	int index = num[0];
	for (int i = 1; i < 10; i++) {
		if (i == 6 || i == 9)
			continue;
		index = max(index, num[i]);
	}
	index = max(index, (num[6] + num[9] + 1) / 2);
	cout << index << endl;
}
