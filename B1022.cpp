#include<stdio.h>

void transformDenNumToDNum(int demNum, int D);
char transformIntDigitToChar(int num);
/*
Author: apolo
Time:   2019.4.10
Info:   求A+B的D进制的数
*/

//由于A+B在int范围之内，因此D进制的位数不会超过32位，因此设置保存A+B的结果数组最大为33位
char digit[33];	//	由于D进制可能包含16进制，因此设置其类型为char类型
int digitSize;
int main(){
	int A, B;
	int D;
	scanf("%d %d %d", &A, &B, &D);
	int demDigit = A+B;
	//To:将十进制转化为D进制
	transformDenNumToDNum(demDigit, D);
	//To:打印转化为D进制的结果（由于是逆序保存，因此需要逆序输出）
	for(int i = digitSize-1; i >=0; --i){
		printf("%c", digit[i]);
	}
	return 0;
}

/*
	To:将十进制数转为D进制
	Return: 修改全局变量digit数组
*/
void transformDenNumToDNum(int demNum, int D){
	do{
		int reminder = demNum%D;
		digit[digitSize++] = transformIntDigitToChar(reminder);
		demNum = demNum/D;
	}while(demNum!=0);
}

char transformIntDigitToChar(int num){
	char ch;
	if(num >=0 && num <= 9){
		ch = '0'+num;
	}else{
		ch = 'a'+num-10;
	}
	return ch;
}
