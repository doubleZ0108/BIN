int gcd_recrusive(int m, int n)
{
	if (n == 0) { return m; }
	else { return gcd_recrusive(n, m%n); }
}

int gcd_loop(int m, int n)
{
	int r;
	while (n)
	{
		r = n;
		n = m % n;
		m = r;
	}
	return m;
}
