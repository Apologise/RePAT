#include<stdio.h>

/*
	������С��
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
	//1. ִ���Ե����Ͻ��е���
	/*
		1.����ǰ����Ԫ�صĽڵ��븸�ڵ���бȽϣ����С�ڸ��ڵ㣬��ô���븸�ڵ���н���
		ֱ�������Ԫ��С�ڸ��ڵ�
	*/
	int fatherIndex = (index-1)/2;
	while(fatherIndex >= 0 && heap[index] < heap[fatherIndex]){
		swapElementByIndex(index, fatherIndex);
		index = fatherIndex;
		fatherIndex = (index-1)/2;
	}
}

void deleteElement(int element){
	//1. �ҵ��ýڵ������
	int index = -1;
	for(int i = 0; i < cnt; ++i){
		if(heap[i] == element){
			index = i;
			break;
		}
	}
	if(index == -1){
		printf("û�и�Ԫ��\n");
		return;
	}
	//���ɾ���Ľڵ�Ϊ���ڵ㣬��ôֱ�ӽ����һ���ڵ��滻���ڵ㲢ɾ�����һ���ڵ㣬Ȼ��Ӹ��ڵ����½��е���
	if(index == 0){
		heap[0] = heap[cnt-1];
		cnt--;
		//�Ӹ��ڵ������ֱ�����һ���ڵ�ĸ��ڵ㼴�ж���
		while(index < cnt/2){
			int leftIndex = (index+1)*2-1;
			int rightIndex = (index+1)*2;
			int minIndex  = -1;
			//�ж��ҽڵ��Ƿ�Ϊ��
			if(rightIndex >= cnt){
				minIndex = leftIndex;
			}
			//�ҵ�ֵС�Ľڵ��±�
			minIndex = (heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex);
			//�жϸ��ڵ����С�ĺ��ӽڵ�Ƚ�
			if(heap[index] > heap[minIndex]){
				swapElementByIndex(index, minIndex);
				index = minIndex;
			}else{
				break;
			}
		}
	}else{	//���ɾ���Ĳ��Ǹ��ڵ㣬ͬ�������һ���ڵ����ɾ���Ľڵ㽻��
		//1. �ҵ��ýڵ������
		int index = -1;
		for(int i = 0; i < cnt; ++i){
			if(heap[i] == element){
				index = i;
				break;
			}
		}
		if(index == -1){
			printf("û�и�Ԫ��\n");
			return;
		}
		heap[index] = heap[cnt-1];
		cnt--;
		//���������
		//1.����������λ�õĽڵ���ں��ӽڵ㣬�����µ���
		while(index < cnt/2){
			int leftIndex = (index+1)*2-1;
			int rightIndex = (index+1)*2;
			int minIndex  = -1;
			//�ж��ҽڵ��Ƿ�Ϊ��
			if(rightIndex >= cnt){
				minIndex = leftIndex;
			}else{
			//�ҵ�ֵС�Ľڵ��±�
				minIndex = (heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex);
			}
			//�жϸ��ڵ����С�ĺ��ӽڵ�Ƚ�
			if(heap[index] > heap[minIndex]){
				swapElementByIndex(index, minIndex);
				index = minIndex;
			}else{
				break;
			}
		}
		//2.���ϵ���
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
	�ɵ�ǰ�ڵ�index����֤Ϊ��Ҷ�ӽڵ㣩���µ���������
*/
void shitDown(int index){
	int fatherIndex = index;
	while(fatherIndex < cnt/2){
		//��2�����ӽڵ������
		int leftIndex = (fatherIndex+1)*2-1;
		int rightIndex = (fatherIndex+1)*2;
		//�ҵ����н�С���ӵ�����
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
	//�ӵ�һ����Ҷ�ӽڵ㿪ʼ������ֱ�����ڵ�
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
	//ɾ�����ڵ�
	deleteElement(4);
	for(int i = 0; i < cnt; ++i){
		printf("%d ", heap[i]);
	}
	*/
	//ɾ���Ǹ��ڵ�
	/*
	deleteElement(16);
	for(int i = 0; i < cnt; ++i){
		printf("%d ", heap[i]);
	}
	*/
	
	
	return 0;
}