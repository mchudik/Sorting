#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class SortTable
{
public:
	SortTable(const int sort_column = 0, const bool sort_ascending = false) :
	  SORT_COLUMN(sort_column),
	  SORT_ASCENDING(sort_ascending) {}

	bool operator()(const vector<string>& s1, const vector<string>& s2);

private:
    const int SORT_COLUMN;
    const bool SORT_ASCENDING;

	bool stringCompare(const string &left, const string &right);
	bool stringNumeric(const string s) { return s.find_first_not_of( "0123456789" ) == string::npos;};
};

class MediaType
{
public:
	MediaType(void) {};
	~MediaType(void) {};

	bool sortColumn(int sortColumn, bool sortAscending);
	bool loadFromFile(string filePath);
	void printResults();

private:
	vector <vector <string> > mediaTypeTable;
};
