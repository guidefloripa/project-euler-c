/*

Created on 03/2014

Author: guidefloripa

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <stdio.h>

static int isLeapYear(int year) {
	return (year%4==0 && year%100!=0) || (year%100==0 && year%400==0) ? 1 : 0;
}

int main(int argc, char** argv)
{
	int y, m, d;
	int number_md;
	int week_day = 1;
	int count_sunday = 0;

	for (y=1900; y<=2000; y++) {
		for (m=1; m<=12; m++) {
			switch (m) {
				case 4:
				case 6:
				case 9:
				case 11:
					number_md = 30;
					break;

				case 2:
					number_md = isLeapYear(y) ? 29 : 28;
					break;

				default:
					number_md = 31;
					break;
			}
			for (d=1; d<=number_md; d++) {
				if (week_day==0) {
					if (y>1900 && d==1) {
						count_sunday++;
					}
				}

				week_day++;
				if (week_day==7) week_day = 0;
			}
		}
	}

	fprintf(stderr, "[Problem 19] %d\n", count_sunday);
	return 0;
}

