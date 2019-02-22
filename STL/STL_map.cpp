/*
STL --- map
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;

int main(void)
{
	map<int, string> mymap;

	/*����Ԫ��*/
		//���ܲ���, ����ȥ���������ڵļ�ֵ�Ƿ����,
		//��������ڻ��ȴ����ն����ٸ�ֵ(����Ϊ��������ʱЧ������)
		mymap[1] = "One";
		mymap[2] = "Two";

		//���⿪��
		mymap.insert(pair<int,string>(3, "Three"));
		mymap.insert(map<int, string>::value_type(4, "Four"));


	/*���map�е�Ԫ��*/
		//ֻ�е�map���������ֵ��ʱ�����ַ������ܻ�ȡ��Ԫ��
		//�粻���ڻ��Զ�����һ��ʵ��,ֵΪ��ʼ��ֵ
		string tmpstr = mymap[0];


	/*��ѯĳ����ֵ�Ƿ����*/
		//find
		int destKey = 2;
		map<int, string>::iterator iter = mymap.find(destKey);
		if (iter == mymap.end()) {
			//û�ҵ�
		}
		else {
			cout << "�ؼ�����" << iter->first << endl;
			cout << "�洢��������" << iter->second << endl;
		}

	system("pause");
	return 0;
}