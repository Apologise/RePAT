#include<cstdio>
#include<cstring>

int sumAllDigitFromStr(char* str);
void transformNumToString(int num);

char str[101];
char answerStr[100];
const char *p[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	scanf("%s", str);
	int sumAnswer = sumAllDigitFromStr(str);
	transformNumToString(sumAnswer);
	printf("%s", answerStr);
	return 0;
}

/*
	TODO: ͳ���ַ��������ֵĸ���λ��֮��
	Return:���ν��֮��
*/

int sumAllDigitFromStr(char *p){
	int ans = 0;
	/*
		�ܽ᣺while��ѭ����������дp!=NULL����Ϊpָ�����һ��100���ռ�����飬��˵�ַ����ΪNULL
		�ַ����Ľ�������Ӧ��Ϊ��\0����0
	*/
	while(*p!=0){
		int temp = *p-'0';
		ans += temp;
		p++;
	}
	return ans;
}

/*
	TODO: ������תΪ�ַ���
	Return: �޸�ȫ�ֱ���answerStr
*/
void transformNumToString(int num){
	int strMap[10];
	int cnt = 0;
	while(num!=0){
		int temp = num%10;
		strMap[cnt++] = temp;
		num = num/10;
	}
	//��strMapͨ��*p����תΪ�ַ���
	for(int i = cnt-1; i >=0; --i){
		if(i != cnt-1){
			strcat(answerStr, " ");
		}
		strcat(answerStr, p[strMap[i]]);
	}
}


