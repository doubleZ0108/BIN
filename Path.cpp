#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX 105
#define INFINITY 65535
int N, M, A[MAX][MAX], ECT, EarliestTime[MAX] = { 0 }, LatestTime[MAX], D[MAX][MAX], idx;  //ETC--earliest completion time
int getMax(int arr[]) {
	int max = 0;
	for (int i = 0; i < N; i++)
		if (max < arr[i]) {
			max = arr[i];
			idx = i;
		}
	return max;
}
int TopSort_Earliest() {
	int V, cnt = 0, Indegree[MAX] = { 0 };
	queue<int> q;
	//������������
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (A[i][j] != INFINITY)
				Indegree[j]++;	//���������<i,j>�ۼ��յ�j�����
								//���Ϊ0�����
	for (int i = 0; i < N; i++)
		if (Indegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		V = q.front();
		q.pop();
		cnt++;
		for (int j = 0; j < N; j++)
			if (A[V][j] != INFINITY) {  //<V, j>�������
				if (EarliestTime[V] + A[V][j] > EarliestTime[j]) { //��� V���������ʱ�� + j����ʱ�� > j���������ʱ��
					EarliestTime[j] = EarliestTime[V] + A[V][j];
				}
				if (--Indegree[j] == 0)  //ȥ��V�����j�����Ϊ0
					q.push(j);
			}
	}
	ECT = getMax(EarliestTime); //�������ʱ��Ӧ������Ԫ��������
	if (cnt != N) return 0;	//���û��ȡ������Ԫ�أ�˵��ͼ���л�·
	else return 1;
}
void TopSort_Latest() {
	int V, Outdegree[MAX] = { 0 };
	queue<int> q;
	//��������ĳ���
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (A[i][j] != INFINITY)
				Outdegree[i]++;	//���������<i,j>�ۼ����i�ĳ���
								//����Ϊ0�����
	for (int i = 0; i < N; i++)
		if (Outdegree[i] == 0)
			q.push(i);
	//��ʼ��LatestTime
	for (int i = 0; i < N; i++)
		LatestTime[i] = INFINITY;
	LatestTime[idx] = ECT;	//�����һ������������ʱ����Ϊ�����������ʱ��
	while (!q.empty()) {
		V = q.front();
		q.pop();
		//cnt++;	//����Ҫ����cnt��
		for (int j = 0; j < N; j++)
			if (A[j][V] != INFINITY) {  //<j, V>�������
				if (LatestTime[V] - A[j][V] <= LatestTime[j]) {  //������<=,ֻ<�Ļ�ֻ����һ���ؼ�·����<=����������еĹؼ�·��(����ԭ��)
					LatestTime[j] = LatestTime[V] - A[j][V];
					D[j][V] = LatestTime[V] - EarliestTime[j] - A[j][V];
				}
				if (--Outdegree[j] == 0)  //ȥ��V�����j�ĳ���Ϊ0
					q.push(j);
			}
	}
}
void PrintKeyRoute() {
	for (int i = 0; i < N; i++)
		for (int j = N - 1; j >= 0; j--)	//������ĿҪ��i��ͬʱҪjҪ�������
			if (D[i][j] == 0)
				printf("%d->%d\n", i + 1, j + 1);
}
int main() {
	int a, b;
	scanf("%d %d", &N, &M);
	//��ʼ��ͼ�ı�A������Ļ���ʱ��D
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			D[i][j] = A[i][j] = INFINITY;
	//read
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		scanf("%d", &A[--a][--b]);	//��Ŀ�б�Ŵ�1��ʼ������ԭ��
	}
	if (!TopSort_Earliest())
		printf("0\n");
	else {
		printf("%d\n", ECT);
		TopSort_Latest();
		PrintKeyRoute();
	}
	system("pause");
	return 0;
}
