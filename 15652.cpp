// 15652번  N과 M (4)
#include <iostream>
#define max 8
using namespace std;
int N, M;
int v1[max] = { 0 };
void find(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M - 1; i++) {
			if (v1[i] > v1[i + 1]) {
				return;
			}
		}
		for (int i = 0; i < M; i++) {
			cout << v1[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		v1[cnt] = i;
		find(cnt + 1);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	find(0);
}
