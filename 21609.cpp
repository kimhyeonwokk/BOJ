// 백준 21609 상어 중학교
#include <iostream>
#include <queue>
#include <deque>
#include <utility>
#include <iomanip>
#include <cstring>
#include <algorithm>
#define MAX 20+1
using namespace std;
struct block {
	deque<pair<int, int>> Rainbow_block;
	deque<pair<int, int>> Base_block;
	int total_size;
	int base_block_x;
	int base_block_y;
	int base_color;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int MAP[MAX][MAX];
bool check[MAX][MAX] = { false };
deque<block> block_group;
int result_point = 0;
void reverse_clock_wise() {
	// 시계방향으로 돌리면 1열 2열 3열 4열 5열 -> 5행 4행 3행 2행 1행
	queue<int> q;
	for (int j = 1; j <= N; j++)
		for (int i = 1; i <= N; i++)
			q.push(MAP[i][j]);
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = q.front();
			q.pop();
		}
	}
}
void Gravity() {
	// 내려가는 방향은 1번 인덱스
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == -1 || MAP[i][j] == -2)
				continue;
			int num = MAP[i][j];
			MAP[i][j] = -2;
			int prev_x = i;
			prev_x++;
			while (prev_x <= N) {
				if (MAP[prev_x][j] != -2)
					break;
				prev_x++;
			}
			prev_x--;
			MAP[prev_x][j] = num;
		}
	}
}
bool cmp(const block& x, const block& y) {
	if (x.total_size != y.total_size)
		return x.total_size > y.total_size;
	else {
		if (x.Rainbow_block.size() != y.Rainbow_block.size())
			return x.Rainbow_block.size() > y.Rainbow_block.size();
		else {
			if (x.base_block_x != y.base_block_x)
				return x.base_block_x > y.base_block_x;
			else
				return x.base_block_y > y.base_block_y;
		}
	}
}
bool check_range(const int& next_x, const int& next_y) {
	if (next_x >= 1 && next_y >= 1 && next_x <= N && next_y <= N)
		return true;
	else
		return false;
}
void bfs(const int& i, const int& j) {
	block temp;
	queue<pair<int, int>> q;
	// 색깔지정 및 탐색 준비
	temp.base_color = MAP[i][j];
	temp.total_size = 0;
	temp.base_block_x = i;
	temp.base_block_y = j;
	check[i][j] = true;
	q.push(make_pair(i, j));
	// 베이스 블럭이 당연히 맨 처음시작하는 곳 아닌가? 라고 생각
	// 위에서 부터 시작하니
	// 탐색 시작
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (MAP[x][y] == temp.base_color) {
			temp.Base_block.push_back(make_pair(x, y));
			temp.total_size++;
		}
		else if (MAP[x][y] == 0) {
			temp.Rainbow_block.push_back(make_pair(x, y));
			temp.total_size++;
		}
		for (int index = 0; index < 4; index++) {
			int next_x = x + dx[index];
			int next_y = y + dy[index];
			if (check_range(next_x, next_y) && check[next_x][next_y] == false) {
				if (MAP[next_x][next_y] == temp.base_color || MAP[next_x][next_y] == 0) {
					check[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	// 탐색 종료 후 정리
	for (auto i : temp.Rainbow_block)
		check[i.first][i.second] = false;
	if (temp.total_size < 2)
		return;
	block_group.push_back(temp);
}
bool find_block_group() {
	// 블록 그룹 먼저 찾기
	memset(check, false, sizeof(check));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (MAP[i][j] != 0 && MAP[i][j] != -1 && MAP[i][j] != -2 && check[i][j] == false)
				bfs(i, j);
	if (block_group.empty())
		return false;
	sort(block_group.begin(), block_group.end(), cmp);
	// block 터트리기 -2 는 빈칸
	result_point += block_group[0].total_size * block_group[0].total_size;
	for (auto i : block_group[0].Rainbow_block)
		MAP[i.first][i.second] = -2;
	for (auto i : block_group[0].Base_block)
		MAP[i.first][i.second] = -2;
	block_group.clear();
	return true;
}
void solve() {
	for (;;) {
		if (find_block_group() == false)
			return;
		Gravity();
		reverse_clock_wise();
		Gravity();
	}
}
void input() {
	cin >> N >> M;
	// (-1,검은색),(0,무지개),그리고 나머지 M까지 색
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> MAP[i][j];
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main() {
	init();
	input();
	solve();
	cout << result_point << endl;
}
