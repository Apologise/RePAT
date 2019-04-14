#include<cstdio>

/*
	Author: apolo
	Time:   2019/4/14
	Info:   Êý×Ö·ÖÀà
*/
int calA1(int num[], int n);
int calA2(int num[], int n);
int calA3(int num[], int n);
double calA4(int num[], int n);
int calA5(int num[], int n);

struct Answer{
	int flag1;
	int flag2;
	int flag3;
	int flag4;
	int flag5;
	Answer(){
		flag1 = 1;
		flag2 = 1;
		flag3 = 1;
		flag4 = 1;
		flag5 = 1;
	}
}ansFlag;
int num[1010];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}
	int ansA1 = calA1(num, n);
	if(ansFlag.flag1 == 1){
		printf("%d ", ansA1);
	}else{
		printf("N ");
	}
	int ansA2 = calA2(num, n);
	if(ansFlag.flag2 == 1){
		printf("%d ", ansA2);
	}else{
		printf("N ");
	}
	int ansA3 = calA3(num, n);
	if(ansFlag.flag3 == 1){
		printf("%d ", ansA3);
	}else{
		printf("N ");
	}
	double ansA4 = calA4(num, n);
	if(ansFlag.flag4 == 1){
		printf("%.1f ", ansA4);
	}else{
		printf("N ");
	}
	int ansA5 = calA5(num, n);
	if(ansFlag.flag5 == 1){
		printf("%d", ansA5);
	}else{
		printf("N");
	}
	return 0;
}


int calA1(int num[], int n){
	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(num[i]%10 == 0){
			ans += num[i];
			cnt++;
		}
	}
	if(cnt == 0){
		ansFlag.flag1 = 0;
	}
	return ans;
}

int calA2(int num[], int n){
	int cnt = 0;
	int flag = 1;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(num[i]%5 == 1){
			ans = ans+ flag*num[i];
			flag = -flag;
			cnt++;
		}
	}
	if(cnt == 0){
		ansFlag.flag2 = 0;
	}
	return ans;
}

int calA3(int num[], int n){
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(num[i]%5 == 2){
			cnt++;
		}
	}
	if(cnt == 0){
		ansFlag.flag3 = 0;
	}
	return cnt;
}

double calA4(int num[], int n){
	double ans = 0.0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(num[i]%5 == 3){
			cnt++;
			ans += num[i];

		}
	}
	if(cnt == 0){
		ansFlag.flag4 = 0;
	}
	return ans/cnt;
}

int calA5(int num[], int n){
	int max = -1;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(num[i]%5 == 4){
			cnt++;
			if(num[i] > max){
				max = num[i];
			}
		}
	}
	if(cnt == 0){
		ansFlag.flag5 = 0;
	}
	return max;
}