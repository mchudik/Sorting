#pragma once
#include <string>
using namespace std;

template <typename T, unsigned S>
inline unsigned arraySize(const T(&arr)[S]) { return S; }

class SortUtils
{
public:
	SortUtils() {};
	~SortUtils() {};

	static bool stringCompare(const string &left, const string &right);
};

