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
		//1. 如果需求量为0，那么直接退出
		if(k == 0){
			break;
		}
		//1. 如果最大需求小于当前单价最高的商品，那么购买k当前商品
		if(k < product[i].own){
			sum += k*product[i].singlePrice;
			k = 0;
		}else{
			//2. 如果需求量大于当前商品的存量，那么先买下全部的商品，然后减去当前库存
			sum += product[i].price;
			k -= product[i].own;
		}
	}
	printf("%.2f", sum);

	return 0;
}