#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <ctype.h>

using namespace std;


typedef long long int llint;

typedef vector<bool> v_b;
typedef v_b::iterator it_v_b;
typedef vector<int> v_i;
typedef v_i::iterator it_v_i;
typedef set<int> s_i;
typedef s_i::iterator it_s_i;
typedef list<int> l_i;
typedef l_i::iterator it_l_i;
typedef vector<string> v_str;
typedef v_str::iterator it_v_str;
typedef pair<string, string> pair_ss;
typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;


string sumStrings(const v_str &lines)
{
	char buff [100];
	int sum = 0;
	int i = 0;
	for (; i < 50; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			sum += lines[j].c_str()[49-i] - '0';
		}
		buff[i] = '0' + sum % 10;
		sum /= 10;
	}
	while (sum > 0)
	{
		buff[i++] = '0' + sum % 10;
		sum /= 10;
	}
	
	buff[i++] = '\0' ;
	return &buff[i-11];

}


int main()
{
	ifstream infile;
	infile.open("problem_13_data.txt");
	v_str lines(100);
	string sLine;
	int i = 0;
	
	while(!infile.eof())
	{
		getline(infile, sLine);
		lines[i++] = sLine;
	}
	
	string res = sumStrings(lines);
	
	cout << string(res.rbegin(), res.rend()) << endl;
	
	return 0;
};
