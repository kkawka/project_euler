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
#include <time.h>   

using namespace std;


typedef long long int llint;

typedef vector<string> v_str;
typedef v_str::iterator it_v_str;
typedef pair<string, string> pair_ss;
typedef vector< pair_ss > v_pair_ss;
typedef v_pair_ss::iterator it_v_pair_ss;

int letterValue(int sum, int letter)
{
	return sum + (letter - 'A' + 1);
}

int calcValue(const string &name)
{
	int init = 0;
	return accumulate(name.begin(), name.end(), init, letterValue);
}

int main()
{
	clock_t t;
	t = clock();
	
	ifstream infile("problem_22_data.txt");
	v_str *names = new v_str();
	llint res = 0;
	int size = 0;
	size_t pos = 0;
	string sep = ",";
	string fileStr = "";

	names->reserve(6000);

	while(!infile.eof())
	{
		infile >> fileStr;
	}

	while((pos = fileStr.find('"')) != string::npos)
	{
		fileStr.erase(pos,1);
	}

	while((pos = fileStr.find(sep)) != string::npos)
	{
		names->push_back(fileStr.substr(0,pos));
		fileStr.erase(0, pos + sep.length());
	}
	
	names->push_back(fileStr);

	sort(names->begin(), names->end());
	size = names->size();
	
	for (int i = 0; i < size; ++i)
	{
		res += (i+1)*calcValue(names->at(i));
	}
	
	t = clock() - t;
	cout << "DONE in clicks " << t << "(" << ((float)t)/CLOCKS_PER_SEC << " seconds)" <<endl;
	
	return 0;
};
