#include<stdio.h>

int digit[10];
int ans[50];
int main(){
	for(int i = 0; i < 10; ++i){
		scanf("%d", &digit[i]);
	}
	int cnt = 0;
	//��һ���ҷ�����С����
	for(int i = 1; i < 10; ++i){
		if(digit[i]){
			ans[cnt++] = i;
			digit[i]--;
			break;
		}
	}
	//�ҵ���С����
	for(int i = 0; i < 10; ){
		if(digit[i] > 0){
			ans[cnt++] = i;
			digit[i]--;
		}else{
			//�����ǰû�����֣���ô�ͱ��������ָ���Ϊ0
			i++;
		}
	}

	for(int i = 0; i < cnt; ++i){
		printf("%d", ans[i]);
	}
	return 0;
}




