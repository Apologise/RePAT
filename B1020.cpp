#include<stdio.h>
#include<algorithm>
#define N 1010
using namespace std;
typedef struct{
	double own;
	double price;
	double singlePrice;
}Product;
bool cmp(Product a, Product b){
	return a.singlePrice > b.singlePrice;
}
int main(){
	int n, k;
	Product product[N];
	double sum = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%lf", &product[i].own);
	}
	for(int i = 0; i < n; ++i){
		scanf("%lf",&product[i].price);
		product[i].singlePrice = product[i].price/product[i].own;
	}
	sort(product, product+n, cmp);
	for(int i = 0; i < n; ++i){
		//1. ���������Ϊ0����ôֱ���˳�
		if(k == 0){
			break;
		}
		//1. ����������С�ڵ�ǰ������ߵ���Ʒ����ô����k��ǰ��Ʒ
		if(k < product[i].own){
			sum += k*product[i].singlePrice;
			k = 0;
		}else{
			//2. ������������ڵ�ǰ��Ʒ�Ĵ�������ô������ȫ������Ʒ��Ȼ���ȥ��ǰ���
			sum += product[i].price;
			k -= product[i].own;
		}
	}
	printf("%.2f", sum);

	return 0;
}