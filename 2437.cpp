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
// 2437 저울
int N, K;
vector<int> v;
vector<int> sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 2 <= v[i]) break;
		sum += v[i];
	}
	cout << sum + 1 << " ";
}
