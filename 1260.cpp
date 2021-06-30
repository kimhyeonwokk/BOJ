#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int matrix[1001][1001] = { 0 };
int visit[1001] = { 0 };
int N, M, v;
void dfs(int v) {
	cout << v << ' ';
	visit[v] = 1;            //방문한 노드를 visit 0에서 1로 변경
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || matrix[v][i] == 0)
			continue;
		dfs(i);                //dfs에서 재귀를 사용
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x = 0, y = 0;
	cin >> N >> M >> v;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		matrix[x][y] = 1, matrix[y][x] = 1;
	}
	dfs(v);
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	cout << endl;
	queue<int> q;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int pre = q.front();
		cout << pre << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (matrix[pre][i] == 1 && visit[i] != 1) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}
