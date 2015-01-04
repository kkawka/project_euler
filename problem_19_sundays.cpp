#include <vector>
#include <string>
#include <assert.h>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <time.h>   

using namespace std;

typedef vector<int> v_i;
typedef v_i::iterator it_v_i;

v_i months;
v_i monthsNormal;
v_i monthsLeap;


bool isLeapYear(int y)
{
	return (y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0));
}

int dInYear(int y)
{
	return isLeapYear(y) ? 366 : 365;
}

bool isTFOTM(int y, int d)
{
	return isLeapYear(y) 
		? binary_search(monthsLeap.begin(), monthsLeap.end(), d) 
		: binary_search(monthsNormal.begin(), monthsNormal.end(), d);
}

static int daysSum = 0;

int dSum(int n)
{
	return daysSum += n;
}


void initMonths()
{
	months.reserve(12);
	monthsNormal.resize(12);
	monthsLeap.resize(12);

	months.push_back(1);  // START
	months.push_back(31); // JAN
	months.push_back(28); // FEB
	months.push_back(31); // MAR
	months.push_back(30); // APR
	months.push_back(31); // MAY
	months.push_back(30); // JUN
	months.push_back(31); // JUL
	months.push_back(31); // AUG
	months.push_back(30); // SEP
	months.push_back(31); // OCT
	months.push_back(30); // NOV

	std::transform (months.begin(), months.end() , monthsNormal.begin(), dSum);

	daysSum = 0;
	months[2] = 29;
	std::transform (months.begin(), months.end() , monthsLeap.begin(), dSum);
}

void test()
{
	assert(!isLeapYear(1900));
	assert(!isLeapYear(1901));
	assert(!isLeapYear(1902));
	assert(!isLeapYear(1903));
	assert(isLeapYear(1904));
	assert(isLeapYear(1908));
	assert(isLeapYear(1912));
	assert(isLeapYear(2000));
}

int main()
{
	clock_t t;
	t = clock();
	
	test();
	initMonths();
	
	int res = 0;
	int day = 7; // 1900, Jan 7 - Sunday
	int daysInYear;
	
	day += 7 * 52 - 365; // move to the first Sunday in 1900
	
	for (int i = 1901; i < 2001; ++i)
	{
		daysInYear = dInYear(i);
		while (day <= daysInYear)
		{
			if (isTFOTM(i, day))
			{
				++res;
			}
			day += 7;
		}
		day -= daysInYear;
	}
	
	t = clock() - t;
	cout << "Result :" << res  << endl;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
