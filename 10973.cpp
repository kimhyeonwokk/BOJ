// 10973 이전 순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v1;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}
	if (prev_permutation(v1.begin(), v1.end()) == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (auto i : v1) {
		cout << i << " ";
	}
	return 0;
}
