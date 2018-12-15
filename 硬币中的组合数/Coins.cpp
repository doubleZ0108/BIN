/*
*�����ѧ��Ŀ:	
*		"Ӳ���е������"
* �Ƚ����ֻ��ң�����ҡ���Ԫ��ŷԪ����Ӳ�ҹ��ɸ��Ի�����10Ԫ����������Ա�˵��ÿ��Ӳ�ҵı�����
* ���������������Ӳ�ң��ֱ���1�֡�2�֡�5�֡�1�ǡ�5�ǡ�1Ԫ��
* ��Ԫ����������Ӳ�ң��ֱ���1���֡�5���֡�10���֡�25���֣�50���֡�1��Ԫ��
* ŷԪ�а�������Ӳ�ң��ֱ��� 1ŷ�֡�2ŷ�֡�5ŷ�֡�10ŷ�֡�20ŷ�֡�50ŷ�֡�1ŷԪ��2ŷԪ��
*
*
* �ο���Դ:
*		https://www.cnblogs.com/python27/archive/2013/09/05/3303721.html
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void Combination(const vector<int> &coins, vector<vector<int> > &result, const int amount=1000)
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
void showConbination(const vector<vector<int> >&Yuan, const vector<vector<int> >&Dollar
	, const vector < vector<int >> &Euro, const int amount = 1000)
{
	cout << setw(10) << "amount"
		<< setw(10) << "Yuan"
		<< setw(10) << "Dollar"
		<< setw(10) << "Euro" << endl;

	for (int sum = 1; sum <= amount; ++sum)
	{
		cout << setw(10) << sum;
		cout << setw(10) << Yuan[Yuan.size()-1][sum];
		cout << setw(10) << Dollar[Dollar.size()-1][sum];
		cout << setw(10) << Euro[Euro.size()-1][sum];
		cout << endl;
	}
}

int main(void)
{
	const int amount = 1000;

	vector<int> Yuan = { 1,2,5,10,50,100 };
	vector<vector<int> >ComYuan(Yuan.size()+1, vector<int>(amount+1, 0));	//����0��Ӳ�ҵ���� �� 0ԪǮ�����
	Combination(Yuan, ComYuan);
	//cout << ComYuan[Yuan.size()][amount] << endl;
	
	vector<int> Dollar = { 1,5,10,25,50,100 };
	vector<vector<int> > ComDollar(Dollar.size() + 1, vector<int>(amount + 1, 0));
	Combination(Dollar, ComDollar);
	//cout << ComDollar[Dollar.size()][amount] << endl;

	vector<int> Euro = { 1,2,5,10,20,50,100,200 };
	vector<vector<int> > ComEuro(Euro.size() + 1, vector<int>(amount + 1, 0));
	Combination(Euro, ComEuro);
	//cout << ComEuro[Euro.size()][amount] << endl;

	showConbination(ComYuan, ComDollar, ComEuro);

	system("pause");
	return 0;
}

