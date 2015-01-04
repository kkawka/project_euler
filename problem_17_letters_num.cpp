#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctype.h>

using namespace std;


typedef long long int llint;

typedef map<int, string> m_i_str;
typedef m_i_str::iterator it_m_i_str;

m_i_str translationMap;

void initMap()
{
	translationMap[0]="";
	translationMap[1]="one";
	translationMap[2]="two";
	translationMap[3]="three";
	translationMap[4]="four";
	translationMap[5]="five";
	translationMap[6]="six";
	translationMap[7]="seven";
	translationMap[8]="eight";
	translationMap[9]="nine";
	translationMap[10]="ten";
	translationMap[11]="eleven";
	translationMap[12]="twelve";
	translationMap[13]="thirteen";
	translationMap[14]="fourteen";
	translationMap[15]="fifteen";
	translationMap[16]="sixteen";
	translationMap[17]="seventeen";
	translationMap[18]="eighteen";
	translationMap[19]="nineteen";

	//
	translationMap[20]="twenty";
	translationMap[30]="thirty";
	translationMap[40]="forty";
	translationMap[50]="fifty";
	translationMap[60]="sixty";
	translationMap[70]="seventy";
	translationMap[80]="eighty";
	translationMap[90]="ninety";
	translationMap[100]="hundred";
	//
	translationMap[1000]="onethousand";

}

string numToString(int i)
{
	if (translationMap.find(i) != translationMap.end())
	{
		if (i == 100) // HACK HACK
		{
			return translationMap[1]+translationMap[i];
		}
		return translationMap[i];
	}
	else
	{
		string res;
		if (i > 100)
		{
			res += translationMap[i/100];
			res += translationMap[100];
			i %= 100;
			if (i > 0)
			{
				res += "and";
			}
		}
		if (translationMap.find(i) != translationMap.end()) // e.g 115
		{
			res += translationMap[i];
		}
		else // e.g 342
		{
			res += translationMap[(i/10) * 10];
			i %= 10;
			res += translationMap[i];
		}
		return res;
	}
}

void testNumToStr()
{
	cout << "BEGIN TEST" << endl;
	cout << numToString(0) << ' ' << (numToString(0)).size() << endl;
	cout << numToString(1) << ' ' << (numToString(1)).size() << endl;
	cout << numToString(2) << ' ' << (numToString(2)).size() << endl;
	cout << numToString(3) << ' ' << (numToString(3)).size() << endl;
	cout << numToString(4) << ' ' << (numToString(4)).size() << endl;
	cout << numToString(5) << ' ' << (numToString(5)).size() << endl;
	cout << numToString(6) << ' ' << (numToString(6)).size() << endl;
	cout << numToString(7) << ' ' << (numToString(7)).size() << endl;
	cout << numToString(8) << ' ' << (numToString(8)).size() << endl;
	cout << numToString(9) << ' ' << (numToString(9)).size() << endl;
	//
	cout << numToString(10) << ' ' << (numToString(10)).size() << endl;
	cout << numToString(11) << ' ' << (numToString(11)).size() << endl;
	cout << numToString(12) << ' ' << (numToString(12)).size() << endl;
	cout << numToString(13) << ' ' << (numToString(13)).size() << endl;
	cout << numToString(14) << ' ' << (numToString(14)).size() << endl;
	cout << numToString(15) << ' ' << (numToString(15)).size() << endl;
	cout << numToString(16) << ' ' << (numToString(16)).size() << endl;
	cout << numToString(17) << ' ' << (numToString(17)).size() << endl;
	cout << numToString(18) << ' ' << (numToString(18)).size() << endl;
	cout << numToString(19) << ' ' << (numToString(19)).size() << endl;
	cout << numToString(20) << ' ' << (numToString(20)).size() << endl;
	//
	cout << numToString(30) << ' ' << (numToString(30)).size() << endl;
	cout << numToString(40) << ' ' << (numToString(40)).size() << endl;
	cout << numToString(50) << ' ' << (numToString(50)).size() << endl;
	cout << numToString(60) << ' ' << (numToString(60)).size() << endl;
	cout << numToString(70) << ' ' << (numToString(70)).size() << endl;
	cout << numToString(80) << ' ' << (numToString(80)).size() << endl;
	cout << numToString(90) << ' ' << (numToString(90)).size() << endl;
	cout << numToString(100) << ' ' << (numToString(100)).size() << endl;
	cout << numToString(200) << ' ' << (numToString(200)).size() << endl;
	cout << numToString(300) << ' ' << (numToString(300)).size() << endl;
	cout << numToString(1000) << ' ' << (numToString(1000)).size() << endl;
	//
	cout << numToString(342) << ' ' << (numToString(342)).size() << endl;
	cout << numToString(115) << ' ' << (numToString(115)).size() << endl;
	cout << "END TEST" << endl;

}

int main()
{
	llint res = 0;

	initMap();
	testNumToStr();

	for (int i = 1; i <= 1000; ++i)
	{
		res += (numToString(i)).size();
	}

	cout << res << endl;
	return 0;
};
