#include<cstdio>

bool isAnswerTrue(char *p);

int n;
int main(){
	scanf("%d", &n);
	char str[101];
	while(n--){
		scanf("%s", str);
		bool isPAT = isAnswerTrue(str);
		if(isPAT){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

/*
	TODO: 判断字符串是否满足题目要求
	Return: 返回true或false
*/
bool isAnswerTrue(char *p){
	int flag = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	while(*p != 0){
		if(!(*p == 'A' || *p == 'P' || *p == 'T')){
			return false;
		}
		if(*p == 'P'){
			if(flag!=0){
				return false;
			}
			flag = 1;
		}
		if(*p == 'A'){
			if(flag == 3){
				z++;
			}
			if(flag == 2){
				y++;
			}
			if(flag == 1){
				flag = 2;
				y++;
			}
			if(flag == 0){
				x++;
			}
		}
		if(*p == 'T'){
			if(flag == 2){
				flag = 3;
			}else{
				return false;
			}
		}
		p++;
	}
	if(flag != 3){
		return false;
	}else{
		if(z == y*x){
			return true;
		}
	}
	return false;
}