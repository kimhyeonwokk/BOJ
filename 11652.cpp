#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main() {
	int N;
	cin >> N;
	map<long long, int> ma;
	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		ma[n]++;
	}
	long long min_index = 0;
	long long num = 0;
	for (auto& i : ma) {
		if (i.second > min_index) {
			min_index = i.second;
			num = i.first;
		}
	}

	cout << num << endl;
}
