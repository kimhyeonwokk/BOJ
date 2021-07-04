// 1476 날짜 계산
#include <iostream>
using namespace std;
int main() {
	int E, S, M;
	cin >> E >> S >> M;
	int e1 = 1, s1 = 1, m1 = 1;
	int count = 1;
	for (;;) {
		if (e1 == E && s1 == S && m1 == M) {
			cout << count << endl;
			break;
		}
		e1++, s1++, m1++;
		count++;
		if (e1 == 16)
			e1 = 1;
		if (s1 == 29)
			s1 = 1;
		if (m1 == 20)
			m1 = 1;
	}
}
