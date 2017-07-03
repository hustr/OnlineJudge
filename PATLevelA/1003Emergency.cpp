#include<cstdio>
#include<cstring>

#define INF 0x7FFFFF
int u[502] = { 0 }; // ��¼�Ƿ�����ˣ�1�ѱ�����0δ����
int teams[502] = { 0 }; // ��¼����
int dist[502]; // ��¼����
int mp[502][502]; // ��¼ͼ
int n, m, st, en;
int shortNum = 0, maxteam = 0, mindist = INF;

void dfs(int s, int dis, int team) {//��ʼ�㣬����S���ʱ�ľ��룬teams
	// ��������յ�
	if (s == en) {
		if (dis<mindist) {
			mindist = dis;
			shortNum = 1; //�����̣���ǰ����ȥ
			maxteam = team; //
		}
		// ����������̵�һ��
		else if (dis == mindist) {
			shortNum++;
			if (team>maxteam) maxteam = team;
		}
		return;
	}
	u[s] = 1; // ����Ϊ�ѱ���
	// �ٴα���δ�����Ľ�㣬��������ĵݹ��в�Ӧ���ٱ����˽ڵ�
	for (int i = 0; i<n; i++) {
		// ���δ�����Ҵ���·
		if (u[i] == 0 && mp[s][i]>0) {
			dfs(i, dis + mp[s][i], team + teams[i]);
		}
	}
	u[s] = 0; //��Ϊ���Ա���״̬
}

int main() {
	int i;
	scanf("%d %d %d %d", &n, &m, &st, &en);
	for (i = 0; i<n; i++) scanf("%d", &teams[i]);
	memset(mp, -1, sizeof(mp));
	for (i = 0; i<m; i++) {
		int t1, t2, dis;
		scanf("%d %d %d", &t1, &t2, &dis);
		mp[t1][t2] = mp[t2][t1] = dis;
	}

	//u[st]=1;
	dfs(st, 0, teams[st]);

	printf("%d %d\n", shortNum, maxteam);
	return 0;
}
