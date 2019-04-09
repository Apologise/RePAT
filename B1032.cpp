#include<cstdio>
#define N 100000
/*
Author: apolo
Time:   2019.4.9
info:   统计多个学校中的最高分和对应学校的编号
*/

int school[N];	//全局变量系统默认为对应类型赋初值
int maxScore, index;
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int num, score;
		scanf("%d %d", &num, &score);
		school[num] += score;
		//更新数据后，更新最高分数以及对应学校的下标
		if(school[num] > maxScore){
			maxScore = school[num];
			index = num;
		}
	}
	printf("%d %d", index, school[index]);
}