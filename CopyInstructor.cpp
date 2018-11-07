#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Array
{
private:
	int *m_p = NULL;
	int m_len = 0;
public:
	Array(int len);
	Array(const Array &buf);	//����������const, ��������������
		//�������const��,���arr1��const���Ͷ����,
		//nonconst��arr2�ڿ��������ʱ��ͻᱨ��û�к��ʵĿ������캯��
		//
		//������ﲻ����������, ���ڵ������������ʱ��
		//ʵ�ε��βεĹ����о�Ҫ��������������캯��,Ȼ����Ҫ��,��Ҫ��,������ѭ��
		//C++�﷨�ϾͲ��������������鷢��

	~Array();

	int operator[](int index)const { return m_p[index]; }
	int &operator[](int index) { return m_p[index]; }

	Array &operator=(const Array &buf);	//ע��������ͺͷ���ֵ����
		//���û�������ֵ�����, ��m_p�ᱻarr1��arr3���ͷ�һ��,����ڴ����
		//����ֵΪ&��Ŀ�Ĳ����ܹ������ڷ������ݵ�ʱ����ÿ������캯��
		//�����Դﵽ�������Ƶ�Ŀ�� arr1=arr2=arr3=arr4;
		//ע:��������������⻹��������������,�������������������Ĭ��ֵ

	int length()const { return m_len; }
	void display()const;
};

int main(void)
{
	Array arr1(10);
	for (int i = 0; i < arr1.length(); ++i)
	{
		arr1[i] = i;
	}

	/*Test 1: ������캯����ǳ�������캯��*/
	cout << endl << "*****Test 1: ������캯����ǳ�������캯��*****" << endl;
	Array arr2(arr1);	//����д Array arr2 = arr1; ����ôд��һģһ����,������ÿ������캯��

	arr2[3] = 99;	//������Ϊ�Զ��������,�����޸�arr2������,arr1�������仯
					//�������û���Լ���ʾ����,ϵͳĬ�ϵ�ǳ��������,��arr1��arr2ͬʱ�仯

	cout << "After changes of arr2: " << endl;
	cout << "arr1: "; arr1.display();
	cout << "arr2: "; arr2.display();

	/*Test 2: ���ظ�ֵ�����*/
	cout << endl << "*****Test 2: ���ظ�ֵ�����*****" << endl;
	Array arr3(4);
	for (int i = 11; i < 11 + arr3.length(); ++i)
	{
		arr3[i-11] = i;
	}
	
	cout << "At the beginning: " << endl;
	cout << "arr1: "; arr1.display();
	cout << "arr3: "; arr3.display();

	arr3 = arr1;

	arr3[3] = 234;	//û�����ص������ֵ�����, ��arr1��ֵҲ�ᱻ�޸�
	cout << "After arr3=arr1 && change of arr3: " << endl;
	cout << "arr1: "; arr1.display();
	cout << "arr3: "; arr3.display();

	system("pause");
	return 0;
}
Array::Array(int len)
	:m_len(len)
{
	m_p = new int[m_len];
}

Array::Array(const Array & buf)
//�Լ�����Ŀ������캯��Ϊ���
//������Լ�����ʾ����,ϵͳ���Զ�����һ��,�������Ϊǳ����
{
	this->m_len = buf.m_len;
	this->m_p = new int[m_len];
	memcpy(this->m_p, buf.m_p, this->m_len*sizeof(int));
}

Array::~Array()
{
	if (m_p)
	{
		delete[]m_p;
	}
}

Array & Array::operator=(const Array & buf)
{
	if (this != &buf)	//�ж��Ƿ��Ǹ��Լ���ֵ
	{
		this->m_len = buf.m_len;

		if (this->m_p)
		{
			delete[]this->m_p;		//��ԭ�����ڴ��ͷŵ�
		}

		this->m_p = new int[this->m_len];
		memcpy(this->m_p, buf.m_p, this->m_len * sizeof(int));
	}
	return *this;
}

void Array::display() const
{
	for (int i = 0; i < this->m_len; ++i)
	{
		cout << m_p[i] << ' ';
	}
	cout << endl;
}
