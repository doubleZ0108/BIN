#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
	float y, x, a;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			a = x * x + y * y - 1;
			putchar(a*a*a - x * x*y*y*y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}