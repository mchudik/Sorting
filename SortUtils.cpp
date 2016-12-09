#include "stdafx.h"
#include "SortUtils.h"


bool SortUtils::stringCompare(const string &left, const string &right)
{
	for (string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit)
		if (tolower(*lit) < tolower(*rit))
			return true;
		else if (tolower(*lit) > tolower(*rit))
			return false;
	if (left.size() < right.size())
		return true;
	return false;
}

