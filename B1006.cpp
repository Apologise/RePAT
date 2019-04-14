#include<cstdio>

int main(){
	char ans[100];
	int size = 0;
	int b = 0;
	int s = 0;
	int g = 0;
	int num;
	scanf("%d", &num);
	b = num/100;
	s = num/10%10;
	g = num%10;
	for(int i = 0; i < b; ++i){
		ans[size++] = 'B';
	}
	for(int i = 0; i < s; ++i){
		ans[size++] = 'S';
	}
	for(int i = 0; i < g; ++i){
		ans[size++] = '0'+i+1;
	}
	ans[size] = '\0';
	printf("%s", ans);
	return 0;
}