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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
	priority_queue<int, vector<int>, greater<int>> answer;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int day, cost;
		cin >> day >> cost;
		pq.push(make_pair(day, cost));
	}
	int result = 0;
	while (!pq.empty()) {
		answer.push(pq.top().second);
		result += pq.top().second;
		if (answer.size() > pq.top().first) {
			result -= answer.top();
			answer.pop();
		}
		pq.pop();
	}
	cout << result << endl;
}
