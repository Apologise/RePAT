#include<cstdio>
#include<cstring>
#define N 1010

char num[N];

int main(){
	int b;
	scanf("%s %d", num, &b);
	int len = strlen(num);
	int ans[N];
	int cnt = 0;
	/*
	if(len == 1){
		printf("%d %d", (num[0]-'0')/b, (num[0]-'0')%b);
		return 0;
	}
	*/
	
	int sum = 0;
	for(int i = 0; i < len; i++){
		int temp = num[i] - '0';
		sum = sum*10+temp;
		ans[cnt++] = sum/b;
		sum = sum%b;
	}
	int flag = 0;
	for(int i = 0; i < cnt; ++i){
		//去除数组前端的0
		if(flag == 0 && ans[i] == 0){
			continue;
		}
		printf("%d", ans[i]);
		flag = 1;
	}
	if(flag == 0){
		printf("0");
	}
	printf(" %d", sum);
	return 0;
}