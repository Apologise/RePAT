#include<cstdio>

struct Student{
	char name[11];
	char no[11];
	int score;
}students[1010];

int n;

bool cmp(Student a, Student b){
	return a.score > b.score;
}
int main(){
	scanf("%d", &n);
	int cnt = 0;
	int maxIndex = 0, minIndex = 0;
	while(cnt < n){

		scanf( "%s %s %d", students[cnt].name, 
			students[cnt].no, &students[cnt].score);
		if(students[cnt].score > students[maxIndex].score){
			maxIndex = cnt;
		}
		if(students[cnt].score < students[minIndex].score){
			minIndex = cnt;
		}
		cnt++;
	}
	printf("%s %s\n", students[maxIndex].name, students[maxIndex].no);
	printf("%s %s", students[minIndex].name, students[minIndex].no);
	return 0;
}