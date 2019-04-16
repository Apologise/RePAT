#include<cstdio>
#include<algorithm>

#define maxn 1000010
using namespace std;

int flag[maxn];

int main(){
	int n, m;
	scanf("%d %d", &m, &n);
	//对数组进行初始化，将其全部设置为素数
	for(int i = 0; i < maxn; ++i){
		flag[i] = 1;
	}
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 1;
	for(int i = 0; i < maxn; ++i){
		//若i为素数，则i*n都不为素数
		if(flag[i] == 1){
			for(int j = 2*i; j < maxn; j += i){
				flag[j] = 0;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < maxn; ++i){
		if(flag[i] == 1){
			cnt++;
			if(cnt >= m && cnt <= n){
				printf("%d", i);
				if((cnt-m+1)%10 == 0){
					if(n-m+1 != 10)
						printf("\n");
				}else{
					if(cnt != n){
						printf(" ");
					}
				}
			}
		}
	}
	return 0;
}