// 10971 외판원 순회 2 brute force
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 11
using namespace std;
int W[11][11] = { 0 };
bool visted[11] = { 0 };
int route[11] = { 0 };
int n;
int short_path = 999999999;
void find(int cnt) {
	if (cnt == n) {
		int path = 0;
		for (int i = 0; i < n-1; i++) {
			if (W[route[i]][route[i + 1]] == 0) return;
			path += W[route[i]][route[i + 1]];
		}
		if (W[route[n - 1]][route[0]] == 0)return;
		path += W[route[n-1]][route[0]];
		if (path < short_path) {
			short_path = path;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visted[i]) {
			visted[i] = true;
			route[cnt] = i;
			find(cnt + 1);
			visted[i] = false;
		}
	}
}
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> W[i][j];
		}
	}
	find(0);
	cout << short_path << endl;
}
