#pragma once
#include <string>
using namespace std;

class SortUtils
{
public:
	SortUtils() {};
	~SortUtils() {};

	static bool stringCompare(const string &left, const string &right);
	static bool stringNumeric(const string s) { return s.find_first_not_of("0123456789") == string::npos; };
};

