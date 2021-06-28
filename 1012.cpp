#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int M, N, K;
int map[50][50] = { 0 };
int visit[50][50] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void BFS(int x, int y) {
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x1 = x1 + dx[i];
			int next_y1 = y1 + dy[i];
			if (next_x1 >= 0 && next_y1 >= 0 && next_x1 < M && next_y1 < N) {
				if (map[next_x1][next_y1] == 1 && visit[next_x1][next_y1] == 0) {
					q.push(make_pair(next_x1, next_y1));
					visit[next_x1][next_y1] = 1;
				}
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> M >> N >> K;
		for (int j = 1; j <= K; j++) {
			int x = 0, y = 0;
			cin >> x >> y;
			map[x][y] = 1;
		}
		int count = 0;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == 1 && visit[j][k] == 0) {
					BFS(j, k);
					count++;
				}
			}
		}
		cout << count << endl;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				map[j][k] = 0;
				visit[j][k] = 0;
			}
		}
	}

}
