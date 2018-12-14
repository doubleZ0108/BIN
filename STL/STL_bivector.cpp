/*
STL --- 用vector表示二维数组
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int row = 3, col = 5;
	
	/*方法一: 先声明, 再依照需求定义大小*/
	vector<vector<int> > bivec;
	bivec.resize(row, vector<int>(col));

	/*方法二: 声明时直接定义及初始化*/
	vector<vector<int> > bivec2(row, vector<int>(col, 0));
			//第二个参数里的0, 表示用0初始化二维数组中的每一个元素


	/*访问方法与普通二维数组一样*/
	for (int i = 0; i < bivec.size(); ++i)			//就是row
	{
		for (int j = 0; j < bivec[i].size(); ++j)	//就是col
		{
			cout << bivec2[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}