#include<cstdio>
#include<algorithm>
using namespace std;

/*
	Author: apolo
	Time:   2019.5.4
	Info:   数字黑洞
*/
int asc[5];
int des[5];
int flag;
void integerToChar(int num, int order);
int intArrayToInteger(int arry[4]);

int main(){
	int N;
	scanf("%d", &N);
	do{
		integerToChar(N, 0);
		if(flag == 0){
			printf("%04d - %04d = %04d", N, N, 0);
			return 0;
		}
		integerToChar(N,1);
		int ascNum = intArrayToInteger(asc);
		
		int desNum = intArrayToInteger(des);
		int ans = ascNum - desNum;
			printf("%04d - %04d = %04d\n", ascNum, desNum, ans);
		
		N= ans;
	}while(N != 6174);
	return 0;
}

/*
	TODO:整数转化为数字数组，order为升序或逆序
	RETURN：修改结果数组
*/
void integerToChar(int num, int order){
	int temp[5];
	int index = 0;
	while(num!=0){
		int	n = num%10;
		temp[index++] = n;
		num /= 10;
	}
	
	for(int i = index; i < 4; ++i){
		temp[index++] = 0;
	}
	//判断num的每一位是否相等
	for(int i = 1; i < 4; ++i){
		if(temp[i] != temp[i-1]){
			flag = 1;
		}
	}
	//按照升序排序
	sort(temp, temp+4);
	if(order == 0){
		//将temp数组逆序放入des数组中
		for(int i = 3; i >=0; --i){
			des[3-i] = temp[i];
		}
	}else{
		for(int i = 0; i < 4; ++i){
			asc[i] = temp[i];
		}
	}
	
}

int intArrayToInteger(int arry[4]){
	return arry[3]*1000+arry[2]*100+arry[1]*10+arry[0];
}