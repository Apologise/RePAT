#include<stdio.h>

int digit[10];
int ans[50];
int main(){
	for(int i = 0; i < 10; ++i){
		scanf("%d", &digit[i]);
	}
	int cnt = 0;
	//第一次找非零最小的数
	for(int i = 1; i < 10; ++i){
		if(digit[i]){
			ans[cnt++] = i;
			digit[i]--;
			break;
		}
	}
	//找到最小的数
	for(int i = 0; i < 10; ){
		if(digit[i] > 0){
			ans[cnt++] = i;
			digit[i]--;
		}else{
			//如果当前没有数字，那么就表明该数字个数为0
			i++;
		}
	}

	for(int i = 0; i < cnt; ++i){
		printf("%d", ans[i]);
	}
	return 0;
}




