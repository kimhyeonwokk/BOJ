// 15655 N과 M (6)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> all;
vector<int> choose;
void find(int index, int cnt) {
	if (cnt == M) {
		for (auto i : choose) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	if (index >= N) return;
	choose.push_back(all[index]);
	find(index + 1, cnt + 1);
	choose.pop_back();
	find(index + 1, cnt);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		all.push_back(temp);
	}
	sort(all.begin(), all.end());
	find(0, 0);
}
