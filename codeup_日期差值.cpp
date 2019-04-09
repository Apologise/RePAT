#include<cstdio>
#include<cstring>

/*
Author: apolo
Time:   2019.4.9
Info:   计算两个日期之间的差值
*/

int isLeapYear(int year){
	int flag = 0;
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0) ){
		flag = 1;
	}
	return flag;
}



//定义一个二维数组，来保存每个月的天数,第二维中0为平年，1为闰年
int month_days[13][2] = {{0,0}, {31,31},{28,29}, {31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
//平年365天，闰年366天
int main(){
	//将日期转化为整数
	int startYear, startMonth, startDay;
	int endYear, endMonth, endDay;
	int time1, time2;
	while(scanf("%d %d", &time1, &time2)!=EOF){
		
		//将小的日期赋给startTime, 大的日期赋给endTime
		/*
		if(strcmp(startTime, endTime) > 0){
			//那么就交换字符串
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
		//如果当前年份与终止年份相差了两年，那么直接跳过中间的一年，进行加速，直接从endTime的前一年份开始相加
		while(startYear+1 < endYear){
			//判断当前年份的下一年是否为闰年
			if(isLeapYear(startYear+1) == 1){
				days+= 366;
			}else{
				days+=365;
			}
			startYear++;
		}

		//从起始时间开始，进行天数累加，直到起始时间等于终止时间
		int flag = -1;	//判断当前年份是否为闰年，避免重复判断
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
			//当月份为2月时需要判断是否为闰年
			if(startDay == month_days[startMonth][flag]+1){
				//如果天数大于当前月的天数，那么月进一，天重置为一
				startMonth++;
				startDay = 1;
			}
			//如果月数大于12，那么年进一，月重置为一
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