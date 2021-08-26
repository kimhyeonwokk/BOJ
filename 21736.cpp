#include <iostream>
#include <queue>
using namespace std;
int N, M;
char MAP[601][601];
bool check[601][601];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'I') {
				q.push(make_pair(i, j));
			}
		}
	}
	int count = 0;
	check[q.front().first][q.front().second] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (MAP[x][y] == 'P')
			count++;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 1 && next_y >= 1 && next_x <= N && next_y <= M) {
				if (MAP[next_x][next_y] != 'X' && check[next_x][next_y] == false) {
					check[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	if (count == 0)
		cout << "TT";
	else
		cout << count;
}
