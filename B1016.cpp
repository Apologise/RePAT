#include<cstdio>

/*
	Author: apolo
	Time: 2019.4.15
	Info: ͳ���������е�λ��������ת��Ϊ�������
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
	//��������ת��Ϊ�������飬��Ϊ������ӿ��ܻ����
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
	TODO:ͳ��num��dA�ĸ���
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
	TODO:�����������뵽������
	RETURN:�޸Ĳ�����ans����
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