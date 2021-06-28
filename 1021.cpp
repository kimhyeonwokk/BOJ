#include <iostream>
#include <deque>
using namespace std;

string find_route(deque<int> deque, int index)
{
	int front = 0, back = 0;
	while ( deque.front() != index)
	{
		deque.pop_front();
		front++;
	}
	while (deque.back() != index)
	{
		deque.pop_back();
		back++;
	}
	if (front > back)
		return "back";
	else
		return "front";
}
int main(void) {
	deque<int> circle_deque;
	int N, M, k = 0, i = 0, index = 0;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		circle_deque.push_back(i);
	}
	for (i = 1; i <= M; i++)
	{
		cin >> k;
		if (find_route(circle_deque, k) == "front")
		{
			while (circle_deque.front() != k)
			{
				circle_deque.push_back(circle_deque.front());
				circle_deque.pop_front();
				index++;
			}
			circle_deque.pop_front();
		}
		else
		{
			while (circle_deque.front() != k)
			{
				circle_deque.push_front(circle_deque.back());
				circle_deque.pop_back ();
				index++;
			}
			circle_deque.pop_front();
		}
	}
	cout << index;
}
