// 마법사 상어와 블리자드 21611번
#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#define MAX 50
using namespace std;
int N, M;
// ↑, ↓, ←, →
int pop_dx[5] = { 0,-1,1,0,0 };
int pop_dy[5] = { 0,0,0,-1,1 };
// ←, ↓, →, ↑ 일짜로 피는 과정
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int MAP[MAX][MAX];
vector<pair<int, int>> operation;
// 처음부터 맵을 피고, 저렇게 할 때만 맵을 새로 만든다 그리고 다시 벡터로 맵 만들고
deque<pair<int, int>> map_1;
deque<int> map_2;
deque<int> magic_pop;
int total_count = 0;
void turn(int& x, int& y, int& dir, int& index, int& count) {
	for (int i = 0; i < index; i++) {
		x += dx[dir];
		y += dy[dir];
		if (MAP[x][y] == 0) {
			MAP[x][y] = count++;
		}
		else {
			map_2.push_back(MAP[x][y]);
			MAP[x][y] = count++;
		}
	}
	dir += 1;
	if (dir == 4)
		dir = 0;
}
void make_in_a_row() {
	// map2 만들고, MAP을 순서에 따라 index
	int x = N / 2 + 1;
	int y = N / 2 + 1;
	int dir = 0;
	int index = 1;
	int count = 1;
	map_2.push_back(0);
	while (x != 1 || y != 1) {
		if (index == N - 1) {
			turn(x, y, dir, index, count);
			turn(x, y, dir, index, count);
			turn(x, y, dir, index, count);
		}
		else {
			turn(x, y, dir, index, count);
			turn(x, y, dir, index, count);
			index++;
		}
	}
}
void pop_marble() {
	for (int i = 0; i < map_2.size(); i++) {
		if (!magic_pop.empty() && i == magic_pop.front()) {
			magic_pop.pop_front();
			continue;
		}
		if (map_2[i] == 0)
			map_1.push_back(make_pair(0, 0));
		else if (map_1.back().second == map_2[i])
			map_1.back().first++;
		else 
			map_1.push_back(make_pair(1, map_2[i]));
	}
	map_2.clear();
	magic_pop.clear();
	bool flag = false;
	while (flag == false) {
		deque<pair<int, int>> temp;
		flag = true;
		temp.push_back(map_1.front());
		map_1.pop_front();
		while (!map_1.empty()) {
			if (map_1.front().first >= 4) {
				total_count += map_1.front().first * map_1.front().second;
				map_1.pop_front();
				flag = false;
				continue;
			}
			if (temp.back().second == map_1.front().second) {
				temp.back().first += map_1.front().first;
				map_1.pop_front();
				continue;
			}
			temp.push_back(map_1.front());
			map_1.pop_front();
		}
		map_1 = temp;
	}
	int count = 0;
	for (auto i : map_1) {
		if (i.first == 0) {
			map_2.push_front(0);
			continue;
		}
		if (count == N * N - 1) {
			break;
		}
		map_2.push_back(i.first);
		map_2.push_back(i.second);
		count += 2;
	}
	map_1.clear();
}
void magic(const int& dir, const int& size) {
	int x = N / 2 + 1;
	int y = N / 2 + 1;
	for (int i = 0; i < size; i++) {
		x += pop_dx[dir];
		y += pop_dy[dir];
		magic_pop.push_back(MAP[x][y]);
	}
}
void solve() {
	make_in_a_row();
	for (auto i : operation) {
		magic(i.first, i.second);
		pop_marble();
	}
	cout << total_count << endl;
}
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> MAP[i][j];
	for (int i = 1; i <= M; i++) {
		int dir, size;
		cin >> dir >> size;
		operation.push_back(make_pair(dir, size));
	}
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main() {
	init();
	input();
	solve();
}
