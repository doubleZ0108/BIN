/*
Q: "һ����N�������ֱ��ǲ�����N�Ĳ��ظ���������
	���N"
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
	/*���ֻҪ���N�ͺ�*/
	//��getline��һ����ֱ�Ӷ������ٴ��� (�����жϽ�β)
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

	/*�����Ҫ������N����*/
	//����һ��һ���, ��'\n'��Ϊ������־
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
