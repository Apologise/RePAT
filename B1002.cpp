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
	TODO: 统计字符串中数字的各个位数之和
	Return:整形结果之和
*/

int sumAllDigitFromStr(char *p){
	int ans = 0;
	/*
		总结：while的循环条件不能写p!=NULL，因为p指向的是一个100个空间的数组，因此地址都不为NULL
		字符串的结束条件应该为‘\0’或0
	*/
	while(*p!=0){
		int temp = *p-'0';
		ans += temp;
		p++;
	}
	return ans;
}

/*
	TODO: 将数字转为字符串
	Return: 修改全局变量answerStr
*/
void transformNumToString(int num){
	int strMap[10];
	int cnt = 0;
	while(num!=0){
		int temp = num%10;
		strMap[cnt++] = temp;
		num = num/10;
	}
	//将strMap通过*p数组转为字符串
	for(int i = cnt-1; i >=0; --i){
		if(i != cnt-1){
			strcat(answerStr, " ");
		}
		strcat(answerStr, p[strMap[i]]);
	}
}


