#include<cstdio>

/*
Author: apolo
Time:   2019.4.9
info:   ��ӡͼ�Σ�����N�����һ�������ε�ͼ��
*/

int main(){
	int n;
	char ch;
	int cols, rows;
	scanf("%d %c", &n, &ch);
	cols = n, rows = n*1.0/2+0.5;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			//�����Ϊ0��rows-1,��ôֱ�Ӵ�ӡ���ַ�
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