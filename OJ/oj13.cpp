/*
Q: "一行有N个数，分别是不超过N的不重复的正整数
	求出N"
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int main(void)
{
	/*如果只要求出N就好*/
	//用getline把一整行直接读进来再处理 (不用判断结尾)
	int MaxSize = 0, buf1;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		buf1 = 0;
		while (str[i] != ' ' && str[i] != '\0')
		{
			buf1 *= 10;
			buf1 += str[i] - '0';
			++i;
		}
		if (buf1 > MaxSize) { MaxSize = buf1; }
	}
	cout << MaxSize << endl;

	/*如果需要保存这N个数*/
	//采用一点一点读, 以'\n'作为结束标志
	vector<int> sequence;
	char ch;
	int buf2;
	while ((ch = getchar()) != '\n')
	{
		buf2 = 0;
		while (ch != ' ' && ch != '\n')
		{
			buf2 *= 10;
			buf2 += ch - '0';
			ch = getchar();
		}
		sequence.push_back(buf2);
		if (ch == '\n') { break; }
	}
	cout << sequence.size() << endl;

	system("pause");
	return 0;
}
