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
int T; // TEST_CASE
int n; // 돌린 횟수
/*
W 위 G 왼쪽 R 앞면 Y 아래면 B 오른쪽면 왼쪽 초록색
	  O O O
	  O O O
	  O O O
G G G Y Y Y B B B W W W
G G G Y Y Y B B B W W W
G G G Y Y Y B B B W W W
	  R R R
	  R R R
	  R R R

		 1  2  3
		 4  5  6
		 7  8  9
10 11 12 19 20 21 28 29 30 37 38 39
13 14 15 22 23 24 31 32 33 40 41 42
16 17 18 25 26 27 34 35 36 43 44 45
		 46 47 48
		 49 50 51
		 52 53 54
*/
// 0 L, 1 R, 2 U, 3 D, 4 F, 5 B
int oper[6][12] = {
	{39,42,45,52,49,46,25,22,19,7 ,4 ,1 },
	{43,40,37,3 ,6 ,9 ,21,24,27,48,51,54},
	{30,33,36,54,53,52,16,13,10,1 ,2 ,3 },
	{34,31,28,9 ,8 ,7 ,12,15,18,46,47,48},
	{45,44,43,36,35,34,27,26,25,18,17,16},
	{10,11,12,19,20,21,28,29,30,37,38,39}
};
int cube[6][3][3] = {
	{{10,13,16},{11,14,17},{12,15,18}},
	{{36,33,30},{35,32,29},{34,31,28}},
	{{39,38,37},{42,41,40},{45,44,43}},
	{{21,20,19},{24,23,22},{27,26,25}},
	{{52,53,54},{49,50,51},{46,47,48}},
	{{3 ,2 ,1 },{6 ,5 ,4 },{9 ,8 ,7}}
};
char MAP_init[55] = { 0,
'o','o','o','o','o','o','o','o','o',
'g','g','g','g','g','g','g','g','g',
'y','y','y','y','y','y','y','y','y',
'b','b','b','b','b','b','b','b','b',
'w','w','w','w','w','w','w','w','w',
'r','r','r','r','r','r','r','r','r'
};
char MAP_COPY[55];
void turn(const string& op) {
	int num_oper;
	if (op[0] == 'L')
		num_oper = 0;
	else if (op[0] == 'R')
		num_oper = 1;
	else if (op[0] == 'U')
		num_oper = 2;
	else if (op[0] == 'D')
		num_oper = 3;
	else if (op[0] == 'F')
		num_oper = 4;
	else if (op[0] == 'B')
		num_oper = 5;
	deque<char> index;
	deque<char> cube_front[3];
	for (const auto& i : oper[num_oper]) 
		index.push_back(MAP_COPY[i]);
	if (op[1] == '+') {
		for (int i = 0; i < 3; i++) {
			index.push_front(index.back());
			index.pop_back();
		}
		for (int j = 0; j <= 2; j++) {
			for (int i = 2; i >= 0; i--) {
				cube_front[j].push_back(MAP_COPY[cube[num_oper][i][j]]);
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			index.push_back(index.front());
			index.pop_front();
		}
		int count = 0;
		for (int j = 2; j >= 0; j--) {
			for (int i = 0; i <=2; i++) {
				cube_front[count].push_back(MAP_COPY[cube[num_oper][i][j]]);
			}
			count++;
		}
	}
	for (const auto& i : oper[num_oper]) {
		MAP_COPY[i] = index.front();
		index.pop_front();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			MAP_COPY[cube[num_oper][i][j]] = cube_front[i][j];
			
		}
	}
}
void print() {
	cout << MAP_COPY[39] << MAP_COPY[38] << MAP_COPY[37] << "\n";
	cout << MAP_COPY[42] << MAP_COPY[41] << MAP_COPY[40] << "\n";
	cout << MAP_COPY[45] << MAP_COPY[44] << MAP_COPY[43] << "\n";
}
void solve() {
	cin >> T;
	while (T--) {
		memcpy(MAP_COPY, MAP_init, sizeof(MAP_init));
		cin >> n;
		while (n--) {
			string oper;
			cin >> oper;
			turn(oper);
		}
		print();
	}
}
int main() {
	init();
	solve();
}
