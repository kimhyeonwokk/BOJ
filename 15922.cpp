#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
// 아우으 우아으이야!! 15922

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>> line;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		line.push_back(make_pair(x, y));
	}
	int temp_x = line.front().first;
	int temp_y = line.front().second;
	int total = temp_y - temp_x;
	for (int i = 1; i < N; i++) {
		int next_x = line[i].first;
		int next_y = line[i].second;
		if (next_x <= temp_y && next_y <= temp_y) {
			continue;
		}
		else if (next_x <= temp_y && next_y >= temp_y) {
			total += next_y - temp_y;
			temp_x = temp_y;
			temp_y = next_y;
		}
		else {
			total += next_y - next_x;
			temp_x = next_x;
			temp_y = next_y;
		}
	}
	cout << total << endl;
}
