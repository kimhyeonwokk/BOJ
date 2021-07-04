// 15656 N과 M (7)
#include <iostream>
#include <vector>
#include <algorithm>
#define max 7
using namespace std;
int N, M;
int all[max] = { 0 };
int choose[max] = { 0 };
bool visit[max];
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
		choose[cnt] = all[i];
		find(cnt + 1);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> all[i];
	}
	sort(all, all + N);
	find(0);
}
