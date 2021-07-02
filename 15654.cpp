// 15654번  N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
bool visited[9] = { 0 };
vector<int> number;
int choose[9];
void find(int cnt) {
	if (cnt == M) {
		for (auto i : choose) {
			if (i == 0) continue;
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			choose[cnt] = number[i];
			find(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());
	find(0);
}
