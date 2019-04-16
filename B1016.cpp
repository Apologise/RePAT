#include<cstdio>

/*
	Author: apolo
	Time: 2019.4.15
	Info: 统计两个数中的位数，将其转化为数后相加
*/
int countdAInNum(char* A, int dA);
void add(int ans[], int cntA, int cntB);

char A[11], B[11];
int dA, dB;
int main(){
	int cntA =0 , cntB = 0;
	scanf("%s %d %s %d", A, &dA, B, &dB);
	cntA = countdAInNum(A, dA);
	cntB = countdAInNum(B, dB);
	if((cntA == 0 && cntB == 0) || (dA == 0 && dB == 0)){
		printf("0");
		return 0;
	}
	//将两个数转化为整型数组，因为整数相加可能会溢出
	int ans[13];
	for(int i = 0; i < 13; ++i){
		ans[i] = 0;
	}
	add(ans, cntA, cntB);
	int flag = 0;
	for(int i = 12; i >= 0; --i){
		if(flag == 0 && ans[i] == 0){
			continue;
		}
		printf("%d", ans[i]);
		flag = 1;
	}
	if(flag == 0){
		printf("0");
	}

	return 0;
}

/*
	TODO:统计num中dA的个数
*/
int countdAInNum(char *A, int dA){
	int cnt = 0;
	while(*A != 0){
		int temp = *A-'0';
		if(temp == dA){
			cnt++;
		}
		A++;
	}
	return cnt;
}

/*
	TODO:将两个数加入到数组中
	RETURN:修改参数中ans数组
*/

void add(int ans[], int cntA, int cntB){
	for(int i = 0; i < cntA; ++i){
		ans[i] = dA;
	}
	int flag = 0;
	for(int i = 0; i < cntB ; ++i){
		int temp = dB+ans[i]+flag;
		flag = 0;
		if(temp > 9){
			ans[i] = temp%10;
			flag = 1;
		}else{
			ans[i] = temp;
		}
	}
	
	while(flag != 0){
		int temp = flag + ans[cntB];
		flag = 0;
		if(temp > 9){
			ans[cntB] = temp%10;
			flag = 1;
		}else{
			ans[cntB] = temp;
		}
		cntB++;
	}
}