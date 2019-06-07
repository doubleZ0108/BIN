#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MaxSize 4		//分配给作业的总内存块数
#define EMPTY -1		//内存块为空标识
#define TOTALNUM 320	//指令总条数
typedef int PageNum;

/*返回[low, high]间的随机整数*/
PageNum getRand(PageNum low, PageNum high)
{
	return (rand() % (high - low + 1) + low);
}

class Memory
{
private:
	vector<PageNum> block;	//内存块

	int runTime = 0, adjustTime = 0;		//运行次数, 调页次数
	void execute(string algorithm, PageNum now);	//按照算法执行一条指令
public:
	Memory() = default;
	~Memory() = default;

	void Init();
	void Simulate(string algorithm, char type);	//按照算法和执行模式执行指令 

	int getRunTime() { return this->runTime; }			//返回运行次数
	int getAdjustTime() { return this->adjustTime; }	//返回调页次数
	double getAdjustRate(){ return (1.0*this->adjustTime / this->runTime); }	//返回缺页率


};

int main(void)
{
	Memory myMemory;		//创建内存对象
	char method, type, operate;	//置换算法, 执行模式, 功能

	do
	{
		/*选择置换算法*/
		cout <<
			"*********************************************************************************\n"
			"**                                                                             **\n"
			"**                             请选择置换算法：                                **\n"
			"**                             A.       LRU                                    **\n"
			"**                             B.       FIFO                                   **\n"
			"**                                                                             **\n"
			"*********************************************************************************\n" << endl;
		cout << "你想选择: ";
		do
		{
			cin >> method;
			if (method != 'A' && method != 'a' && method != 'B' && method != 'b')
			{
				cout << "您输入的置换算法有误, 请重新输入: ";
			}
		} while (method != 'A' && method != 'a' && method != 'B' && method != 'b');

		string algorithm = (method == 'A' || method == 'a' ? string("LRU") : string("FIFO"));

		/*选择执行模式*/
		cout <<
			"*********************************************************************************\n"
			"**                                                                             **\n"
			"**                             请选择执行模式：                                **\n"
			"**                             A.执行前" << TOTALNUM << "条指令                               **\n"
			"**                             B.执行完所有指令                                **\n"
			"**                                                                             **\n"
			"*********************************************************************************\n" << endl;
		cout << "你想选择: ";
		do
		{
			cin >> type;
			if (type != 'A' && type != 'a' && type != 'B' && type != 'b')
			{
				cout << "您输入的执行模式有误, 请重新输入: ";
			}
		} while (type != 'A' && type != 'a' && type != 'B' && type != 'b');

		//TODO
		myMemory.Init();						//初始化内存
		srand((unsigned)time(NULL));			//获取随机数种子
		myMemory.Simulate(algorithm, type);		//按照该算法和该执行模式进行模拟
		
		cout << algorithm<<"算法, "
			<< (type == 'A' || type == 'a' ? "执行前%d条指令" : "执行完所有指令", TOTALNUM)
			<< "模拟结果如下: " << endl;
		cout << "======================================" << endl
			<< "共执行" << myMemory.getRunTime() << "条指令" << endl
			<< "调页次数为" << myMemory.getAdjustTime() << "次" << endl
			<< "缺页率为" << myMemory.getAdjustRate() << endl
			<< "=======================================" << endl;


		/*选择功能*/
		cout <<
			"*********************************************************************************\n"
			"**                                                                             **\n"
			"**                             请选择功能：                                    **\n"
			"**                             A.初始化                                        **\n"
			"**                             B.结束程序                                      **\n"
			"**                                                                             **\n"
			"*********************************************************************************\n" << endl;
		cout << "你想选择: ";
		do
		{
			cin >> operate;
			if (operate != 'A' && operate != 'a' && operate != 'B' && operate != 'b')
			{
				cout << "您输入的功能有误, 请重新输入: ";
			}
		} while (operate != 'A' && operate != 'a' && operate != 'B' && operate != 'b');

		if (operate == 'B' || operate == 'b') { break; }

	} while (operate!='B' && operate!='b');

		

	system("pause");
	return 0;
}

void Memory::execute(string algorithm, PageNum now)
{

}

void Memory::Init()
{
	this->block.resize(MaxSize, EMPTY);
}



void Memory::Simulate(string algorithm, char type)
{
	int aim;
	if (type == 'A' || type == 'a')
	{
		int cnt = 0;

		//随机选取一个起始指令
		aim = getRand(0, TOTALNUM - 1);
		execute(algorithm, aim); cnt++;
		//顺序执行下一条指令
		aim++;
		execute(algorithm, aim); cnt++;
		while (true)
		{
			if (cnt == TOTALNUM) { break; }
			//跳转到前地址部分
			aim = getRand(0, aim - 1);
			execute(algorithm, aim); cnt++;

			if (cnt == TOTALNUM) { break; }
			//顺序执行下一条指令
			aim++;
			execute(algorithm, aim); cnt++;

			if (cnt == TOTALNUM) { break; }
			//跳转到后地址部分
			aim = getRand(aim + 1, TOTALNUM - 1); 
			execute(algorithm, aim); cnt++;

			if (cnt == TOTALNUM) { break; }
			//顺序执行下一条指令
			aim++;
			execute(algorithm, aim); cnt++;
		}
	}

	
}
