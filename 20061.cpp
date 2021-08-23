#include <iostream>
#include <deque>
using namespace std;
int map[10][10];
int N, T, X, Y;
int block[4][2] = { {0,0},{0,0},{0,1},{1,0} };
int total_result = 0;
void print() {
    cout << "green" << endl;
    for (int i = 4; i <= 9; i++) {
        for (int j = 0; j < 4; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "blue" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 4; j <= 9; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void down_block_point_or_disappear(int index, int line) { // line 0 이면 블루, 1 이면 그린
    deque<int> dq;
    if (line == 1) {
        for (int i = 4; i <= index - 1; i++) {
            for (int j = 0; j < 4; j++) {
                dq.push_back(map[i][j]);
                map[i][j] = 0;
            }
        }
        for (int i = 5; i <= index; i++) {
            for (int j = 0; j < 4; j++) {
                map[i][j] = dq.front();
                dq.pop_front();
            }
        }
    }
    else {
        for (int j = 4; j <= index - 1; j++) {
            for (int i = 0; i < 4; i++) {
                dq.push_back(map[i][j]);
                map[i][j] = 0;
            }
        }
        for (int j = 5; j <= index; j++) {
            for (int i = 0; i < 4; i++) {
                map[i][j] = dq.front();
                dq.pop_front();
            }
        }
    }
}
void check_soft() {
    int count = 0;
    for (int i = 4; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 1) {
                count++;
                break;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        down_block_point_or_disappear(9, 1);
    }
    count = 0;
    for (int j = 4; j < 6; j++) {
        for (int i = 0; i < 4; i++) {
            if (map[i][j] == 1) {
                count++;
                break;
            }
        }
    }
    for (int i = 0; i < count; i++) 
        down_block_point_or_disappear(9, 0);
}
void check_point() {
    for (int i = 6; i <= 9; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 1)
                count++;
        }
        if (count == 4) {
            for (int j = 0; j < 4; j++) {
                map[i][j] = 0;
            }
            total_result++;
            down_block_point_or_disappear(i, 1);
        }
    }
    for (int j = 6; j <= 9; j++) {
        int count= 0;
        for (int i = 0; i < 4; i++) {
            if (map[i][j] == 1)
                count++;
        }
        if (count == 4) {
            for (int i = 0; i < 4; i++) {
                map[i][j] = 0;
            }
            total_result++;
            down_block_point_or_disappear(j, 0);
        }
    }
}
void block_add() {
    int x1 = X;
    int x2 = X + block[T][0];
    int y1 = Y;
    int y2 = Y + block[T][1];
    while (1) {
        if (x1 == 10 || x2 == 10) {
            x1--, x2--;
            break;
        }
        if (map[x1][y1] == 1 || map[x2][y2] == 1) {
            x1--, x2--;
            break;
        }
        else {
            x1++, x2++;
        }
    }
    map[x1][y1] = 1; map[x2][y2] = 1;
    x1 = X;
    x2 = X + block[T][0];
    y1 = Y;
    y2 = Y + block[T][1];
    while (1) {
        if (y1 == 10 || y2 == 10) {
            y1--, y2--;
            break;
        }
        if (map[x1][y1] == 1 || map[x2][y2] == 1) {
            y1--, y2--;
            break;
        }
        else {
            y1++, y2++;
        }
    }
    map[x1][y1] = 1; map[x2][y2] = 1;
}
void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T >> X >> Y;
        block_add();
        check_point();
        check_soft();
    }
    cout << total_result << endl;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1)
                count++;
        }
    }
    cout << count << endl;
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int main() {
    init();
    solve();
}
