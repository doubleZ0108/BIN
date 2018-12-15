/*
*�����ѧ��Ŀ:	
*		"Ӳ���е������"
* �Ƚ����ֻ��ң�����ҡ���Ԫ��ŷԪ����Ӳ�ҹ��ɸ��Ի�����10Ԫ����������Ա�˵��ÿ��Ӳ�ҵı�����
* ���������������Ӳ�ң��ֱ���1�֡�2�֡�5�֡�1�ǡ�5�ǡ�1Ԫ��
* ��Ԫ����������Ӳ�ң��ֱ���1���֡�5���֡�10���֡�25���֣�50���֡�1��Ԫ��
* ŷԪ�а�������Ӳ�ң��ֱ��� 1ŷ�֡�2ŷ�֡�5ŷ�֡�10ŷ�֡�20ŷ�֡�50ŷ�֡�1ŷԪ��2ŷԪ��
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void Combination_Yuan(const vector<int> &coins, vector<vector<int> > &result, const int amount=1000)
{
	//��0��Ӳ������������λ����Ϊ0
	for (int sum = 0; sum <= amount; ++sum)
	{ result[0][sum] = 0; }

	//����Ӳ���������0Ԫ��1�ֿ���
	for (int i = 0; i <= coins.size(); ++i)
	{
		result[i][0] = 1;
	}


	for (int i = 1; i <= coins.size(); ++i)
	{
		for (int sum = 1; sum <= amount; ++sum)
		{
			for (int k = 0; k <= sum / coins[i-1]; ++k)
			{
				result[i][sum] += result[i - 1][sum - k * coins[i-1]];
			}
		}
	}
}
void showConbination(const int kinds, const vector<vector<int> >&result, const int amount=1000)
{
	cout << setw(10) << "amount"
		<< setw(10) << "Yuan"
		<< setw(10) << "Dollar"
		<< setw(10) << "Euro" << endl;

	for (int sum = 1; sum <= amount; ++sum)
	{
		cout << setw(10) << sum;
		cout << setw(10) << result[kinds][sum] << endl;
	}
	
}
int main(void)
{
	int kinds, amount;
	kinds = 6; amount = 1000;

	vector<int> Yuan = { 1,2,5,10,50,100 };
	vector<vector<int> >ComYuan(kinds+1, vector<int>(amount+1, 0));	//����0��Ӳ�ҵ���� �� 0ԪǮ�����
	Combination_Yuan(Yuan, ComYuan);
	//cout << ComYuan[kinds][amount] << endl;
	showConbination(kinds, ComYuan);
	
	system("pause");
	return 0;
}

