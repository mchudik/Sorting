// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int sortColumn = 0;
bool sortOrder = false;

bool stringNumeric(string s) { return s.find_first_not_of( "0123456789" ) == string::npos;}

bool stringCompare( const string &left, const string &right ){
	for( string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
		if( tolower( *lit ) < tolower( *rit ) )
			return true;
		else if( tolower( *lit ) > tolower( *rit ) )
			return false;
	if( left.size() < right.size() )
		return true;
	return false;
}

int compare(const vector<string>& s1, const vector<string>& s2) {
	if(stringNumeric(s1[sortColumn]) && stringNumeric(s2[sortColumn]))
		return atoi(s1[sortColumn].c_str()) > atoi(s2[sortColumn].c_str());
	else
		return stringCompare(s1[sortColumn], s2[sortColumn]);
}

void printResults(vector< vector<string> > myvector) { 
	for(vector< vector<string> >::const_iterator it_row = myvector.begin();
		it_row != myvector.end(); ++it_row ) {
			copy(it_row->begin(), it_row->end(), ostream_iterator<string>(cout, "\t"));
			cout << endl;
	}
} 

bool loadFromFile(string filePath, vector <vector <string> >& data)
{
	ifstream infile(filePath.c_str());
	while (infile)
	{
		string s;
		if (!getline( infile, s )) break;

		istringstream ss( s );
		vector <string> record;

		while (ss)
		{
			string s;
			if (!getline( ss, s, ',' )) break;
			record.push_back( s );
		}

		data.push_back( record );
	}
	if (!infile.eof())
	{
		cerr << "Error reading file!\n";
		return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector <vector <string> > data;
	string filePath( "Media-HP Webcam 3110.csv" );

	if(!loadFromFile(filePath, data))
		return 1;

	//Sort from least significant to most significant
	sortColumn = 4;	//Media Type
	sort(data.begin(), data.end(), compare); 
	sortColumn = 1; //X-Dimension
	sort(data.begin(), data.end(), compare); 
	sortColumn = 3; //Frame Rate
	stable_sort(data.begin(), data.end(), compare); 
	sortColumn = 2;	//Y-Dimension
	stable_sort(data.begin(), data.end(), compare); 

	printResults(data);
	return 0;
}

