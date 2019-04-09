#include<cstdio>
#include<cstring>

/*
Author: apolo
Time:   2019.4.9
Info:   ������������֮��Ĳ�ֵ
*/

int isLeapYear(int year){
	int flag = 0;
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0) ){
		flag = 1;
	}
	return flag;
}



//����һ����ά���飬������ÿ���µ�����,�ڶ�ά��0Ϊƽ�꣬1Ϊ����
int month_days[13][2] = {{0,0}, {31,31},{28,29}, {31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
//ƽ��365�죬����366��
int main(){
	//������ת��Ϊ����
	int startYear, startMonth, startDay;
	int endYear, endMonth, endDay;
	int time1, time2;
	while(scanf("%d %d", &time1, &time2)!=EOF){
		
		//��С�����ڸ���startTime, ������ڸ���endTime
		/*
		if(strcmp(startTime, endTime) > 0){
			//��ô�ͽ����ַ���
			char temp[10];
			strcpy(temp, startTime);
			strcpy(startTime, endTime);
			strcpy(endTime, temp);
		}
		
		sscanf(startTime, "%4d %2d %2d", &startYear, &startMonth, &startDay);
		sscanf(endTime, "%4d %2d %2d", &endYear, &endMonth, &endDay);
		*/
		if(time1 > time2){
			int temp = time1;
			time1 = time2;
			time2 = temp;
		}
		startYear = time1/1000, startMonth = time1%1000/100; startDay = time1%100;
		endYear = time2/1000, endMonth = time2%1000/100; endDay = time2%100;
		int days = 1;
		//�����ǰ�������ֹ�����������꣬��ôֱ�������м��һ�꣬���м��٣�ֱ�Ӵ�endTime��ǰһ��ݿ�ʼ���
		while(startYear+1 < endYear){
			//�жϵ�ǰ��ݵ���һ���Ƿ�Ϊ����
			if(isLeapYear(startYear+1) == 1){
				days+= 366;
			}else{
				days+=365;
			}
			startYear++;
		}

		//����ʼʱ�俪ʼ�����������ۼӣ�ֱ����ʼʱ�������ֹʱ��
		int flag = -1;	//�жϵ�ǰ����Ƿ�Ϊ���꣬�����ظ��ж�
		while(startYear != endYear || startMonth != endMonth || startDay != endDay){
			if(flag == -1){
				if(isLeapYear(startYear) == 1){
					flag = 1;
				}else{
					flag = 0;
				}
			}
			startDay++;
			days++;
			//���·�Ϊ2��ʱ��Ҫ�ж��Ƿ�Ϊ����
			if(startDay == month_days[startMonth][flag]+1){
				//����������ڵ�ǰ�µ���������ô�½�һ��������Ϊһ
				startMonth++;
				startDay = 1;
			}
			//�����������12����ô���һ��������Ϊһ
			if(startMonth == 13){
				startYear++;
				startMonth = 1;
				flag = -1;
			}
		}
		printf("%d\n", days);
	}
	return 0;
}