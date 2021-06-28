#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, count = 0, a = 0, b = 0, c = 0, num = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i <= 99)
			count++;
		else if (i >= 100 && i <= 999)
		{
			num = i;
			c = num % 10;
			num = num / 10;
			b = num % 10;
			num = num / 10;
			a = num % 10;

			if (c - b == b - a)
			{
				count++;
			}
		}
	}
	cout << count;

}

 
