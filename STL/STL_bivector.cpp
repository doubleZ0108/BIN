/*
STL --- ��vector��ʾ��ά����
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int row = 3, col = 5;
	
	/*����һ: ������, �������������С*/
	vector<vector<int> > bivec;
	bivec.resize(row, vector<int>(col));

	/*������: ����ʱֱ�Ӷ��弰��ʼ��*/
	vector<vector<int> > bivec2(row, vector<int>(col, 0));
			//�ڶ����������0, ��ʾ��0��ʼ����ά�����е�ÿһ��Ԫ��


	/*���ʷ�������ͨ��ά����һ��*/
	for (int i = 0; i < bivec.size(); ++i)			//����row
	{
		for (int j = 0; j < bivec[i].size(); ++j)	//����col
		{
			cout << bivec2[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}