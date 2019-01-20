/*
STL --- sort
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>
using namespace std;

#define MaxSize 50

class myClass
{
	friend ostream& operator<<(ostream& os, const myClass &buf);

public:
	int x, y;

	myClass() = default;
	myClass(int bufx,int bufy):x(bufx),y(bufy){}

	bool operator<(const myClass &buf) const
	{ return this->x < buf.x; }
};

bool myless(const myClass &cl1, const myClass &cl2)
{
	return (cl1.y < cl2.y);
}

void Sort_for_myClass(vector<myClass> sequence)
{
	
	cout << "Before sort: ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	sort(sequence.begin(), sequence.end());
	cout << "After sort(compartion funct -> class): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	sort(sequence.begin(), sequence.end(), myless);
	cout << "After sort(compartion funct -> global function): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

void mySort(vector<myClass> sequence)
{
	sort(sequence.begin(), sequence.end());
	cout << "After sort(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}
void myStableSort(vector<myClass> sequence)
{
	stable_sort(sequence.begin(), sequence.end());
	cout << "After stable_sort(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}
void test_StableSort(vector<myClass> sequence)
{
	cout << "Before sort:";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	mySort(sequence);
	myStableSort(sequence);
}

void test_PartialSort(vector<myClass> sequence)
{
	cout << "Before partial_sort(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	//�ҳ�sequence����С�����Ԫ��, ʹ�õıȽϺ�����myClass�����ص� operator<
	partial_sort(sequence.begin(), sequence.begin() + 5, sequence.end());

	cout << "After partial_sort(5): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}
void test_PartialSortCopy(vector<myClass> sequence)
{
	vector<myClass> fresh(MaxSize / 2);

	cout << "Before partial_sort_copy(), sequence: ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	//�ҵ�fresh������С ��С�ļ����� �ŵ�fresh��
	partial_sort_copy(sequence.begin(), sequence.end(), fresh.begin(), fresh.end());

	cout << "After partial_sort_copy(), sequence: ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	cout << "After partial_sort_copy(), fresh: ";
	for_each(fresh.begin(), fresh.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

void test_nthElement(vector<myClass> sequence)
{
	cout << "Before nth_element(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	//ע��begin()�ǵ�һ��Ԫ��, �൱��begin()+0
	//�������ҵ����ĸ�����Ӧ���� begin()+3
	nth_element(sequence.begin(), sequence.begin() + 3, sequence.end());
	cout << "The 4th element is:\t" << *(sequence.begin() + 3) << endl;

	cout << "After nth_element(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

void test_Partition(vector<myClass> sequence)
{
	myClass pivot(6, 6);
	cout << "Before partition(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	/*�ȶ��Ļ��ֿ��Ա�֤ԭ�����е�Ԫ���ڻ��ֺ���Դ��򲻱�*/
	//partition(sequence.begin(), sequence.end(), bind2nd(less<myClass>(), pivot));
	stable_partition(sequence.begin(), sequence.end(), bind2nd(less<myClass>(), pivot));

	cout << "After partition(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

int main(void)
{
	srand(time(NULL));
	vector<myClass> sequence(MaxSize);
	for (int i = 0; i < MaxSize; ++i)
	{
		sequence[i].x = rand() % MaxSize;
		sequence[i].y = rand() % MaxSize;
	}

	/*sort���Զ����������������ַ���*/
	//sort���õ��ǳ����"���������㷨"
	//(Ŀǰ�󲿷�STL�汾�Ѿ����ǲ��ü򵥵Ŀ������򣬶��ǽ���ڲ������㷨)��
	//Sort_for_myClass(sequence);

	/*stable_sort STL�ȶ������㷨��*/
	//stable_sort���õ���"�鲢����"
	//test_StableSort(sequence);	

	/*partial_sort �Ծֲ���������*/
	//partial_sort���õĶ�����(heapsort)
	//���ϣ����partial_sort��ʵ��ȫ����ֻҪ��middle=last�Ϳ�����
	//�������� ��������������С�ļ�����
	//test_PartialSort(sequence);

	/*partial_sort_copy ����������С����������������*/
	//partial_sort_copy��ʵ��copy��partial_sort�����
	//������(������)��������[first, last)��[result_first, result_last)�������С���Ǹ�
	//���[result_first, result_last)�������[first, last)����
	//��ôpartial_sort�൱��copy��sort�����
	//test_PartialSortCopy(sequence);

	/*nth_element ֻ�ҳ���n����С����*/
	//������10��ѧ��������֪���������ڵ�����4����ѧ����
	//������sort�ź���Ȼ��ȡ��4λ����Ϊ����С������)
	//������������partial_sort, ֻ��ǰ4λ��Ȼ��õ���4λ��
	//��ʵ���������˷ѣ���Ϊǰ��λ�����û�б�Ҫ���򣬴�ʱ������nth_element
	//test_nthElement(sequence);

	/*partition ����������ĳ����׼���ֳ�������*/
	//����Ӧ���� ���༶ͬѧ�ɼ����ռ������ֳ�������
	//test_Partition(sequence);

	system("pause");
	return 0;
}

ostream & operator<<(ostream & os, const myClass & buf)
{
	os << '(' << buf.x << ',' << buf.y << ')';
	return os;
}
