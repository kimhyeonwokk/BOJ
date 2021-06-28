#include <iostream>
using namespace std;
int main()
{
	int n,a=-1,b,i=0;
	cin >> n;
	
	while (a != n)
	{

		if (n == 0)
		{
			i = 1;
			break;
		}
		if (i == 0)
			a = n;


		b = a / 10 + a % 10;
		a = (a % 10) * 10 + b % 10;
		i++;
	}
	printf("%d", i);
}
 
