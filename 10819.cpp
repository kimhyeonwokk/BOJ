// 10819 차이 최대로
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
	sort(v1.begin(), v1.end());
	int max = 0;
	while (next_permutation(v1.begin(), v1.end())) {
		int temp = 0;
		for (int i = 0; i < N-1; i++) {
			temp += abs(v1[i] - v1[i + 1]);
		}
		if (temp > max)
			max = temp;
	}
	cout << max << endl;
}
