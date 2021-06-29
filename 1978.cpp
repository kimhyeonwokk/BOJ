#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, c_in = 0, i = 0, k = 0 , index = 0;
	cin >> N;

	for (i = 1; i <= N; i++)
	{
		cin >> c_in;
		if (c_in == 2)
		{
			index++;
		}
		else
		{
			for (k = 2; k < c_in; k++)
			{
				if (c_in % k == 0)
				{
					break;
				}
				else if (k == c_in - 1)
				{
					index++;
				}
			}
		}
	}
	cout << index << endl;
}
