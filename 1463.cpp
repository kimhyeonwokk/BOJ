// 1463
#include <iostream>
#include <queue>
using namespace std;
int check[1000001] = { 0 };
int number;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> number;
	queue<int> q;
	q.push(number);
	int index;
	for (;;) {
		index = q.front();
		q.pop();
		if (index == 1) {
			break;
		}
		if (index % 3 == 0 && check[index / 3] == 0) {
			check[index / 3] = check[index] + 1;
			q.push(index / 3);
		}
		if (index % 2 == 0 && check[index / 2] == 0) {
			check[index / 2] = check[index] + 1;
			q.push(index / 2);
		}
		if (check[index - 1] == 0) {
			check[index - 1] = check[index] + 1;
			q.push(index - 1);
		}
	}
	cout << check[1] << endl;
}
