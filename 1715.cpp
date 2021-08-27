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
// 백준 1715 카드 정렬하기
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	/*
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	*/
	if (N == 1) {
		cout << 0;
		return 0;
	}
	int num1 = 0;
	int num2 = 0;
	int result = 0;
	while (1) {
		num1 = pq.top(); pq.pop();
		num2 = pq.top(); pq.pop();
		result += num1 + num2;
		if (pq.empty()) break;
		pq.push(num1 + num2);
	}
	cout << result;
}
