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
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	priority_queue < pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		pq.push(make_pair(S, T));
	}
	priority_queue<int, vector<int>, greater<int>> time;
	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		if (time.empty()) {
			time.push(top.second);
		}
		else {
			if (top.first >= time.top()) {
				time.pop();
				time.push(top.second);
			}
			else {
				time.push(top.second);
			}
		}
	}
	cout << time.size() << endl;
}
