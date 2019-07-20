#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10
typedef struct{
	int x;
	int y;
}Interval;
Interval I[maxn];

bool cmp(Interval a, Interval b){
	if(a.x != b.x){
		return a.x > b.x;
	}else{
		return a.y < b.y;
	}
}
int main(){
	int n = 4;
	//1. ��������
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &I[i].x, &I[i].y);
	}
	//2.����xֵ��С��������
	sort(I, I+n, cmp);
	//3. ����x��ֵ�Ӵ�С��������
	//3.1 ����ѡȡx����һ����Ϊ���ұߵ�����,lastXΪ��ǰѡ������������
	int flag[maxn], cnt = 0, lastX;
	flag[cnt++] = 0, lastX = I[0].x;
	for(int i = 1; i < n; ++i){
		if(I[i].y <= lastX){ //�ҵ���һ������ѡ�����䲻�ص�������
			lastX = I[i].x;
			flag[cnt++] = i;
		}
	}
	//4.�������
	for(int i = cnt-1; i >= 0;  --i){
		printf("%d %d ", I[flag[i]].x, I[flag[i]].y);
	}
	return 0;
}