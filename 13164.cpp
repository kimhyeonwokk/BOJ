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
// 13164 행복유치원
int N, K;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	int prev_height = 0;
	cin >> prev_height;
	for (int i = 0; i < N - 1; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp - prev_height);
		prev_height = temp;
	}
	sort(v.begin(), v.end());
	int result = 0;
	for (int i = 0; i < N - K; i++) {
		result += v[i];
	}
	cout << result << endl;
}
