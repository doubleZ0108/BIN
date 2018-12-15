#include <stdio.h>
#include <stdlib.h>

int Combination_Yuan(int amount)
{
	int cnt = 0;
	for (int a1 = 0; a1 <= amount / 1; ++a1)
	{
		for (int a2 = 0; a2 <= amount / 2; ++a2)
		{
			for (int a3 = 0; a3 <= amount / 5; ++a3)
			{
				for (int a4 = 0; a4 <= amount / 10; ++a4)
				{
					for (int a5 = 0; a5 <= amount / 50; ++a5)
					{
						for (int a6 = 0; a6 <= amount / 100; ++a6)
						{
							if (a1 * 1 + a2 * 2 + a3 * 5 + a4 * 10 + a5 * 50 + a6 * 100 == amount)
							{
								++cnt;
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}
int Combination_Dollar(int amount)
{
	int cnt = 0;
	for (int a1 = 0; a1 <= amount / 1; ++a1)
	{
		for (int a2 = 0; a2 <= amount / 5; ++a2)
		{
			for (int a3 = 0; a3 <= amount / 10; ++a3)
			{
				for (int a4 = 0; a4 <= amount / 25; ++a4)
				{
					for (int a5 = 0; a5 <= amount / 50; ++a5)
					{
						for (int a6 = 0; a6 <= amount / 100; ++a6)
						{
							if (a1 * 1 + a2 * 5 + a3 *10 + a4 * 25 + a5 * 50 + a6 * 100 == amount)
							{
								++cnt;
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}
int Combination_Euro(int amount)
{
	int cnt = 0;
	for (int a1 = 0; a1 <= amount / 1; ++a1)
	{
		for (int a2 = 0; a2 <= amount / 2; ++a2)
		{
			for (int a3 = 0; a3 <= amount / 5; ++a3)
			{
				for (int a4 = 0; a4 <= amount / 10; ++a4)
				{
					for (int a5 = 0; a5 <= amount / 20; ++a5)
					{
						for (int a6 = 0; a6 <= amount / 50; ++a6)
						{
							for (int a7 = 0; a7 <= amount / 100; ++a7)
							{
								for (int a8 = 0; a8 <= amount / 200; ++a8)
								{
									if (a1 * 1 + a2 * 2 + a3 * 5 + a4 * 10 + a5 * 20 + a6 * 50 + a7 * 100 + a8 * 200 == amount)
									{
										++cnt;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	printf("三种货币（人民币、美元、欧元）中硬币构成各自货币里10元的组合数\n\n");
	printf("%10s %10s %10s %10s\n", "amount", "Yuan", "Dollar", "Euro");

	for (int i = 0; i <= 1000; ++i)
	{
		printf("%10d %10d %10d %10d\n",i,
			Combination_Yuan(i), Combination_Dollar(i), Combination_Euro(i));
	}

	system("pause");
	return 0;
}