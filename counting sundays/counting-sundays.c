#include<stdlib.h>
#include<stdio.h>

// days of week
#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

//months
#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

typedef struct sdate tdate;
struct sdate{
	int day;
	int month;
	int year;
	int day_of_week;
	int is_leap_year;
};

int is_leap_year(int year){
	if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
		return 1;
	return 0;
}

tdate* init_date(int day, int month, int year, int day_of_week, int is_leap_year){
	tdate* date = (tdate*) malloc(sizeof(tdate));
	date->day = day;
	date->month = month;
	date->year = year;
	date->day_of_week = day_of_week;
	date->is_leap_year = is_leap_year;

	return date;
}

tdate* add_one_day(tdate* date){
	if(date->month == SEPTEMBER || date->month == APRIL || date->month == JUNE || date->month == NOVEMBER){
		if(date->day == 30){
			date->day = 1;
			date->month += 1;
		}else{
			date->day += 1;
		}
	}else if(date->month == FEBRUARY){
		if(date->is_leap_year == 1){
			if(date->day == 29){
				date->day = 1;
				date->month += 1;
			}else{
				date->day += 1;
			}
		}else{
			if(date->day == 28){
				date->day = 1;
				date->month += 1;
			}else{
				date->day += 1;
			}
		}
	}else{
		if(date->month == DECEMBER){
			if(date->day == 31){
				date->day = 1;
				date->month = JANUARY;
				date->year += 1;
				date->is_leap_year = is_leap_year(date->year);
			}else{
				date->day += 1;
			}
		}else{
			if(date->day == 31){
				date->day = 1;
				date->month += 1;
			}else{
				date->day += 1;
			}
		}
	}

	if(date->day_of_week == SATURDAY){
		date->day_of_week = SUNDAY;
	}else{
		date->day_of_week += 1;
	}
}

void print_date(tdate* date){
	switch(date->month){
		case JANUARY:
			printf("January, ");
			break;
		case FEBRUARY:
			printf("February, ");
			break;
		case MARCH:
			printf("March, ");
			break;
		case APRIL:
			printf("April, ");
			break;
		case MAY:
			printf("May, ");
			break;
		case JUNE:
			printf("June, ");
			break;
		case JULY:
			printf("July, ");
			break;
		case AUGUST:
			printf("August, ");
			break;
		case SEPTEMBER:
			printf("September, ");
			break;
		case OCTOBER:
			printf("October, ");
			break;
		case NOVEMBER:
			printf("November, ");
			break;
		case DECEMBER:
			printf("December, ");
			break;
	}

	printf("%i, %i, ", date->day, date->year);

	switch(date->day_of_week){
		case MONDAY:
			printf("Monday");
			break;
		case TUESDAY:
			printf("Tuesday");
			break;
		case WEDNESDAY:
			printf("Wednesday");
			break;
		case THURSDAY:
			printf("Thursday");
			break;
		case FRIDAY:
			printf("Friday");
			break;
		case SATURDAY:
			printf("Saturday");
			break;
		case SUNDAY:
			printf("Sunday");
			break;
		}
		printf("\n");
}

int main(){
	//another way I though is to increment 7 in days when sunday is reached, but logic would be more complex to handle the days, months and years
	tdate* date = init_date(1, JANUARY, 1900, MONDAY, is_leap_year(1900));
	int sundaysFirstMonthCounter = 0;
	while(date->year < 2001){
		if(date->year >= 1901 && date->day == 1 && date->day_of_week == SUNDAY){
			sundaysFirstMonthCounter++;
		}
		date = add_one_day(date);
	}
	printf("answer = %i", sundaysFirstMonthCounter);
}
