#include<cstdio>
#define N 100000
/*
Author: apolo
Time:   2019.4.9
info:   ͳ�ƶ��ѧУ�е���߷ֺͶ�ӦѧУ�ı��
*/

int school[N];	//ȫ�ֱ���ϵͳĬ��Ϊ��Ӧ���͸���ֵ
int maxScore, index;
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int num, score;
		scanf("%d %d", &num, &score);
		school[num] += score;
		//�������ݺ󣬸�����߷����Լ���ӦѧУ���±�
		if(school[num] > maxScore){
			maxScore = school[num];
			index = num;
		}
	}
	printf("%d %d", index, school[index]);
}