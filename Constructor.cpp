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

class Point
{
	friend ostream &operator<<(ostream &os, const Point &buf);
private:
	double _x = 0.0;
	double _y = 0.0;
public:
	Point() = default;

	//��������ת�����캯�� Conversion Constructor
	//����������Ĵ��������ʱ������ѳ�ʼ��
	//�����������,���������֮��, ���������ֵ�ı������Ƕ���Ļ��ͻ������������ת�����캯��
	//�𵽵���ʵ������ת��������, ��double����ת��ΪPoint����
	Point(double x) { _x = x; }
	Point(double x, double y) { _x = x; _y = y; }

	//����ת������ Type conversion function
	//�ѵ�ǰ������ת��Ϊ��������, ֻ���Գ�Ա��������ʽ����
	//��ΪҪת����Ŀ�������Ѿ���ȷ�ĸ�����,���Բ���Ҫ��д����ֵ(����û��,������ʽ��ָ���˷�������)
	//����Ҳû�� (ʵ���ϲ���Ҳ��Ĭ�ϵ� thisָ��)
	operator double()const { return _x; }
};

class A
{
public:
	virtual void func()const { cout << "Class A" << endl; }
private:
	int m_a;
};
class B :public A
{
public:
	virtual void func()const { cout << "Class B" << endl; }
private:
	int m_b;
};
class C :public B
{
public:
	virtual void func()const { cout << "Class C" << endl; }
private:
	int m_c;
};
class D :public C
{
public:
	virtual void func()const { cout << "Class D" << endl; }
private:
	int m_d;
};
void FourCast()
{
	/*
	(1)static_cast
		1. ԭ�е��Զ�����ת��, ����intתdouble,��constתconst,����ת��
		2. voidָ��;�������ָ��֮���ת��
		3. ת�����캯��

		���������з��յ�ת����
		1. ������������ָ��֮���ת��, ����int *��double *���ת��
		2. һ������������ָ������֮���ת��
		3. constתnon-const
	*/

	/*
	(2)const_cast
		1.��const/volatile ת��Ϊ non-const/non-volatile
	*/
	cout << endl << "After const_cast: " << endl;
	const int n = 100;
	int *p = const_cast<int*>(&n);
	*p = 234;
	cout << "n = " << n << endl;
	cout << "*p = " << *p << endl;
	//Ҫע��*p��Ȼ����,����n��ֵ����100, ������ΪC++�Գ����Ĵ��������#define����ֵ�滻����

	/*
	(3)reinterpret_cast
		1. reinterpret��"���½���"����˼,����ת�������ǶԶ�����λ�����½���
			�ǳ��򵥴ֱ�,���Է��պܸ�,�����򲻵��ѵ�ʱ��Ҫ��
	*/

	/*
	(4)dynamic_cast
		1. �������۵ü̳в��֮���������ת��,��������ת�ͺ�����ת��
		2. ����ת�ͱ������Ǻܰ�ȫ��, ��������ת����dynamic_cast���൱��static_cast
		3. ����ת��Ҫ����RTTI�Ļ��ƽ��м��,���뱣֤��ȫ��ǰ���²��ܳɹ�ת��
		4. ֻ������ָ�����ͺ��������͵�ת��, �������Ͷ�����
			����ָ��,���ת��ʧ�ܽ�����NULL; ��������,ת��ʧ�ܽ��׳�bad_cast�쳣
		5. dunamic_cast���ڳ������й����б����̳���,���;��������Ҫת����Ŀ������,
			�Ǿ��ܹ�ת���ɹ�,���Ա�������˵����ֻ��������ת��  (����ʲô�Ǽ̳��������)
	*/

	cout << endl << "After dynamic_cast: " << endl;
	A *pa = new A();
	B *pb;
	C *pc;

	pb = dynamic_cast<B*>(pa);	//����ת��ʧ��
	if (pb == NULL) {
		cout << "Dnowcasting failed: A* to B*" << endl;
	}
	else {
		cout << "Downcasting successfully: A* to B*" << endl;
		pb->func();
	}

	pc = dynamic_cast<C*>(pa);	//����ת��ʧ��
	if (pc == NULL) {
		cout << "Dnowcasting failed: A* to C*" << endl;
	}
	else {
		cout << "Downcasting successfully: A* to C*" << endl;
		pc->func();
	}

	cout << "---------------------------------------" << endl;

	pa = new D();		//����ת�Ͷ��������
	pb = dynamic_cast<B*>(pa);	//����ת�ͳɹ�
	if (pb == NULL) {
		cout << "Dnowcasting failed: A* to B*" << endl;
	}
	else {
		cout << "Downcasting successfully: A* to B*" << endl;
		pb->func();
	}

	pc = dynamic_cast<C*>(pa);	//����ת�ͳɹ�
	if (pc == NULL) {
		cout << "Dnowcasting failed: A* to C*" << endl;
	}
	else {
		cout << "Downcasting successfully: A* to C*" << endl;
		pc->func();
	}
}

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


	/*Test 3: ת�����캯��*/
	cout << endl << "*****Test 3: ת�����캯��*****" << endl;
	Point point;
	point = 15.4;			//�����Զ����ת�����캯��Point(double)
	cout << "After point = 15,4"; cout << point << endl;

	//��ִ��ϵͳĬ�ϵ�ת��ģʽ,Ȼ������Զ����ת�����캯��
	point = 'A';			//char --> int --> double --> Point
	cout << "After point = 'A'"; cout << point << endl;

	point = true;			//bool --> int --> double --> Point
	cout << "After point = true"; cout << point << endl;


	/*Test 4: ����ת������*/
	cout << endl << "*****Test 4: ����ת������*****" << endl;
	Point pt(24.6, 100);
	double ptx = pt;
	cout << "After type conversion function: ";
	cout << "ptx is " << ptx << endl;

	int bufx = Point(55.5, 66.6);	//�ȴ�������������,�ڽ�Pointת��Ϊdouble, �ٽ�doubleת��Ϊint
	cout << "bufx is " << bufx << endl;


	/*Test 5: ��������ת�������*/
	cout << endl << "*****Test 5: ��������ת�������*****" << endl;
	FourCast();


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

ostream & operator<<(ostream & os, const Point & buf)
{
	cout << "(" << buf._x << ", " << buf._y << ")";
	return os;
}
