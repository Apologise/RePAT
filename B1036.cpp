#include<cstdio>

/*
Author: apolo
Time:   2019.4.9
info:   打印图形，输入N，输出一个正方形的图形
*/

int main(){
	int n;
	char ch;
	int cols, rows;
	scanf("%d %c", &n, &ch);
	cols = n, rows = n*1.0/2+0.5;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			//如果行为0或rows-1,那么直接打印该字符
			if(i == 0 || i == rows-1){
				printf("%c", ch);
			}else{
				if(j == 0 || j == cols -1){
					printf("%c", ch);
				}else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}