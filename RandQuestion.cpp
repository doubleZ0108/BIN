#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	vector<string> question = {
		string("监听法->响应CPU->不替换"),
		string("监听法->响应CPU->替换"),
		string("监听法->响应总线"),
		string("目录法->响应CPU"),
		string("目录法->响应宿主结点"),
		string("目录法->状态转化"),
	};

	srand(time(NULL));
	char next = '\0';
	int num;
	while (question.size())
	{
		next = '\0';
		cout << "Next Question?" << endl;
		cin >> next;
		if (next != '\0')
		{
			num = rand() % question.size();
			cout << endl << "===" << question[num] << "===" << endl << endl;
			question.erase(question.begin() + num, question.begin() + num + 1);
		}
	}
	cout << endl << "**********" << "All Done!" << "**********" << endl;
	system("pause");
	return 0;
}
