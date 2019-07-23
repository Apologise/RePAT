#include<stdio.h>

/*
	构建最小堆
*/
int heap[1000];
int cnt;
void swapElementByIndex(int indexA, int indexB){
	int temp = heap[indexA];
	heap[indexA] = heap[indexB];
	heap[indexB] = temp;
}
void insertElement(int element){
	int index = cnt;
	heap[cnt++] = element;
	//1. 执行自底向上进行调整
	/*
		1.将当前插入元素的节点与父节点进行比较，如果小于父节点，那么就与父节点进行交换
		直到插入的元素小于父节点
	*/
	int fatherIndex = (index-1)/2;
	while(fatherIndex >= 0 && heap[index] < heap[fatherIndex]){
		swapElementByIndex(index, fatherIndex);
		index = fatherIndex;
		fatherIndex = (index-1)/2;
	}
}

void deleteElement(int element){
	//1. 找到该节点的索引
	int index = -1;
	for(int i = 0; i < cnt; ++i){
		if(heap[i] == element){
			index = i;
			break;
		}
	}
	if(index == -1){
		printf("没有该元素\n");
		return;
	}
	//如果删除的节点为根节点，那么直接将最后一个节点替换根节点并删除最后一个节点，然后从根节点向下进行调整
	if(index == 0){
		heap[0] = heap[cnt-1];
		cnt--;
		//从根节点调整，直到最后一个节点的父节点即判断完
		while(index < cnt/2){
			int leftIndex = (index+1)*2-1;
			int rightIndex = (index+1)*2;
			int minIndex  = -1;
			//判断右节点是否为空
			if(rightIndex >= cnt){
				minIndex = leftIndex;
			}
			//找到值小的节点下标
			minIndex = (heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex);
			//判断父节点与较小的孩子节点比较
			if(heap[index] > heap[minIndex]){
				swapElementByIndex(index, minIndex);
				index = minIndex;
			}else{
				break;
			}
		}
	}else{	//如果删除的不是根节点，同样将最后一个节点与待删除的节点交换
		//1. 找到该节点的索引
		int index = -1;
		for(int i = 0; i < cnt; ++i){
			if(heap[i] == element){
				index = i;
				break;
			}
		}
		if(index == -1){
			printf("没有该元素\n");
			return;
		}
		heap[index] = heap[cnt-1];
		cnt--;
		//分两种情况
		//1.如果交换后该位置的节点大于孩子节点，则向下调整
		while(index < cnt/2){
			int leftIndex = (index+1)*2-1;
			int rightIndex = (index+1)*2;
			int minIndex  = -1;
			//判断右节点是否为空
			if(rightIndex >= cnt){
				minIndex = leftIndex;
			}else{
			//找到值小的节点下标
				minIndex = (heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex);
			}
			//判断父节点与较小的孩子节点比较
			if(heap[index] > heap[minIndex]){
				swapElementByIndex(index, minIndex);
				index = minIndex;
			}else{
				break;
			}
		}
		//2.向上调整
		while(index > 0){
			int fatherIndex = (index-1)/2;
			if(heap[fatherIndex] > heap[index]){
				swapElementByIndex(fatherIndex, index);
				index = fatherIndex;
			}else{
				break;
			}
		}
	}
}

/*
	由当前节点index（保证为非叶子节点）向下调整函数，
*/
void shitDown(int index){
	int fatherIndex = index;
	while(fatherIndex < cnt/2){
		//求2个孩子节点的索引
		int leftIndex = (fatherIndex+1)*2-1;
		int rightIndex = (fatherIndex+1)*2;
		//找到其中较小孩子的索引
		int minIndex = -1;
		if(rightIndex >= cnt){
			minIndex = leftIndex;
		}else{
			minIndex = (heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex);
		}
		if(heap[fatherIndex] > heap[minIndex]){
			swapElementByIndex(fatherIndex, minIndex);
		}
		fatherIndex = minIndex;
	}
}

void heapify(){
	//从第一个非叶子节点开始调整，直到根节点
	for(int i = (cnt-1)/2; i >= 0; i--){
		shitDown(i);
	}
}
int main(){
	int a[11] = {2,3,4,0,23,1,5,6,8,10,9};
	for(int i = 0; i < 11; ++i){
		heap[cnt++] = a[i];
	}
	heapify();
	for(int i = 0; i < cnt; ++i){
		printf("%d ", heap[i]);
	}
	/*
	for(int i = 0; i < 9; ++i){
		insertElement(a[i]);
	}
	
	printf("\n");
	/*
	//删除根节点
	deleteElement(4);
	for(int i = 0; i < cnt; ++i){
		printf("%d ", heap[i]);
	}
	*/
	//删除非根节点
	/*
	deleteElement(16);
	for(int i = 0; i < cnt; ++i){
		printf("%d ", heap[i]);
	}
	*/
	
	
	return 0;
}