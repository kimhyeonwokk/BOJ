// 10974 모든 순열
#include <iostream>
#include <vector>
#define max 9
using namespace std;
int N;
int num[max] = { 0 };
bool visit[max];
void find(int cnt) {
	if (cnt == N)
	{
		for (int i = 0; i < N; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			num[cnt] = i;
			find(cnt + 1);
			visit[i] = false;
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	find(0);
}
