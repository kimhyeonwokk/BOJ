#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
/*
	  01 02
	  03 04
13 14 05 06 17 18 21 22
15 16 07 08 19 20 23 24
	  09 10
	  11 12
*/
deque<int> init_map;
// 그 면에서 보는 기준
// (0,왼)(1,오)(2,위)(3,아래)(4,정면)(5,뒷면)

int oper[6][8] = {
	{22,24,11,9 ,7 ,5 ,3 ,1 },
	{23,21,2 ,4 ,6 ,8 ,10,12},
	{18,20,12,11,16,14,1 ,2 },
	{19,17,4 ,3 ,14,16,9 ,10},
	{24,23,20,19,8 ,7 ,16,15},
	{13,14,5 ,6 ,17,18,21,22}
};
int cube[6][2][2] = {
	{{13,15},{14,16}},
	{{20,18},{19,17}},
	{{22,21},{24,23}},
	{{6,5},{8,7}},
	{{11,12},{9,10}},
	{{2,1},{4,3}}
};
int result = 0;
int check(const deque<int> &map_copy) {
	for (int i = 0; i < 6; i++) {
		int num = map_copy[cube[i][0][0]];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (num != map_copy[cube[i][j][k]]) {
					return 0;
				}
			}
		}
	}
	//cout << "111";
	return 1;
}
void turn(const int& oper_num) {
	// 시계방향
	deque<int> map_copy = init_map;
	deque<int> index;
	for (const auto& i : oper[oper_num]) {
		index.push_back(map_copy[i]);
	}
	for (int i = 0; i < 2; i++) {
		index.push_front(index.back());
		index.pop_back();
	}
	for (const auto& i : oper[oper_num]) {
		map_copy[i] = index.front();
		index.pop_front();
	}
	result = max(check(map_copy), result);
	// 시계반대 방향
	map_copy = init_map;
	for (const auto& i : oper[oper_num]) {
		index.push_back(map_copy[i]);
	}
	for (int i = 0; i < 2; i++) {
		index.push_back(index.front());
		index.pop_front();
	}
	for (const auto& i : oper[oper_num]) {
		map_copy[i] = index.front();
		index.pop_front();
	}
	result = max(check(map_copy),result);
}
void solve() {
	for (int i = 0; i < 6; i++)
		turn(i);
	cout << result << endl;
}
void input() {
	init_map.push_back(0);
	for (int i = 1; i <= 24; i++) {
		int temp;
		cin >> temp;
		init_map.push_back(temp);
	}

}
int main() {
	init();
	input();
	solve();
}
