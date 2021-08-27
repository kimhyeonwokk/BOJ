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
// 1374 강의실

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<int, vector<int>, greater<int>> tq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, st, ed;
		cin >> num >> st >> ed;
		pq.push(make_pair(st, ed));
	}
	while (!pq.empty()) {
		pair<int, int> pre = pq.top();
		pq.pop();
		if (tq.empty()) {
			tq.push(pre.second);
		}
		else {
			if (pre.first >= tq.top()) {
				tq.pop();
				tq.push(pre.second);
			}
			else {
				tq.push(pre.second);
			}
		}
	}
	cout << tq.size();
}
