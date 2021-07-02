// 15649번  N과 M (1)
#include <iostream>
#define max 9
using namespace std;
int N, M;
bool visited[max] = { false, };
int arr[max] = { 0 };
void back_tracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			back_tracking(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	back_tracking(0);
}
