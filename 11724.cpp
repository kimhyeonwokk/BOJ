#include <iostream>
#include <queue>
#include <utility>
#define max 1001
using namespace std;
int maxtix[max][max] = { 0 };
int visit[max] = { 0 };
int N, M;
void BFS(int x) {
	visit[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int pre = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (maxtix[pre][i] == 1 && visit[i] != 1) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int x, y;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		maxtix[x][y] = maxtix[y][x] = 1;
	}
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			BFS(i);
			index++;
		}
	}
	cout << index << endl;
}

