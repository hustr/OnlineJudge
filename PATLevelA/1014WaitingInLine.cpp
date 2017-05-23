#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
unsigned windows = 0; // ���ڸ���
unsigned capicity = 0; // ��������
std::queue<int>* peo = new std::queue<int>[20]; // �Ƚ��ȳ�����
int wins[20]; // ���ڵ�ʱ��
struct People { // �˽ṹ��
	int use; // ����ʱ��
	int start; // ��ʼʱ��
	int end; // ����ʱ��
};
void Refresh() {
	int min = 0; // �ҳ���С��ʣ��ʱ��
	for (size_t i = 1; i < windows; i++) {
		if (peo[i].front() < peo[min].front())min = i;
	}
	for (size_t i = 0; i < windows; i++) {
		peo[i].front() -= peo[min].front(); // ��ʱ����������ʱ��
		if (peo[i].front() == 0) peo[i].pop(); // �����п��ܿճ��������pop
	}
}
int Insert(const int length) {
	int min = 0; // �ҳ��������Ĵ���
	for (size_t i = 1; i < windows; i++) {
		if (peo[i].size() < peo[min].size())min = i;
	}
	if (peo[min].size() < capicity) { // ����ҳ��Ĵ����п�λ
		peo[min].push(length);
		wins[min] += length; // ����ʱ��
		if (wins[min] >= 17 * 60)return wins[min]++; // �������˽���ʱʱ���°��ˣ���һ�����ٽ��룬������˵�Ĳ�̫һ��
		return wins[min]; // ����ʱû���°�
	}
	else {
		Refresh(); // ˢ��һ�Σ��ݹ�һ�£���ʵҲ����ˢ��һ�Σ���Ϊһ�����п�λ��
		return Insert(length);
	}
}
int main(void) {
	unsigned customers = 0; // �ͻ���
	unsigned queries = 0; // ѯ����
	scanf("%d %d %d %d", &windows, &capicity, &customers, &queries);
	for (size_t i = 0; i < windows; i++) {
		wins[i] = 8 * 60; // ʱ����Ϊ8��
	}
	People* cust = new People[customers + 1]; // ���˿�������
	for (size_t i = 1; i <= customers; i++) {
		scanf("%d", &cust[i].use);
		cust[i].end = Insert(cust[i].use); // ���ؽ���ʱ��
		cust[i].start = cust[i].end - cust[i].use; // �õ���ʼʱ��
	}
	int ask = 0;
	for (size_t i = 0; i < queries; i++) {
		scanf("%d", &ask);
		// �ͻ�ʱ���Ƿ���δ����ǰ
		if ((cust[ask].start / 60 < 17)
			|| (cust[ask].start / 60 == 17 && cust[ask].start % 60 == 0)) {
			printf("%02d:%02d\n", cust[ask].end / 60, cust[ask].end % 60);
		}
		else{
			printf("Sorry\n");
		}
	}
	delete[] cust;
	return 0;
}