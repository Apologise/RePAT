#include<cstdio>
#include<cstring>

int main(){
	long long int a, b, c;
	int T;
	scanf("%d", &T);
	getchar();
	for(int i = 0; i < T; ++i){
		char str[100];
		gets(str);
		char a[15], b[15], c[15];
		sscanf(str, "%s %s %s", a, b, c);
		printf("%s %s %s", a,b,c);
		/*
		if(a+b > c){
			printf("Case #%d: true\n",i+1);
		}else{
			printf("Case #%d: false\n",i+1);
		}
		*/
	}
	return 0;
}

