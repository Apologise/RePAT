#include<stdio.h>

void transformDenNumToDNum(int demNum, int D);
char transformIntDigitToChar(int num);
/*
Author: apolo
Time:   2019.4.10
Info:   ��A+B��D���Ƶ���
*/

//����A+B��int��Χ֮�ڣ����D���Ƶ�λ�����ᳬ��32λ��������ñ���A+B�Ľ���������Ϊ33λ
char digit[33];	//	����D���ƿ��ܰ���16���ƣ��������������Ϊchar����
int digitSize;
int main(){
	int A, B;
	int D;
	scanf("%d %d %d", &A, &B, &D);
	int demDigit = A+B;
	//To:��ʮ����ת��ΪD����
	transformDenNumToDNum(demDigit, D);
	//To:��ӡת��ΪD���ƵĽ�������������򱣴棬�����Ҫ���������
	for(int i = digitSize-1; i >=0; --i){
		printf("%c", digit[i]);
	}
	return 0;
}

/*
	To:��ʮ������תΪD����
	Return: �޸�ȫ�ֱ���digit����
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
