#include "StdAfx.h"
#include "MediaType.h"

bool MediaType::loadFromFile(string filePath)
{
	ifstream infile(filePath.c_str());
	while (infile) {
		string s;
		if (!getline( infile, s )) break;

		istringstream ss( s );
		vector <string> record;
		while (ss) {
			string s;
			if (!getline( ss, s, ',' )) break;
			record.push_back( s );
		}
		mediaTypeTable.push_back( record );
	}
	if (!infile.eof()) {
		cerr << "Error reading file!\n";
		return false;
	}
	return true;
}

bool MediaType::sortColumn(int sortColumn, bool sortAscending)
{
	stable_sort(mediaTypeTable.begin(), mediaTypeTable.end(), SortTable(sortColumn, sortAscending)); 
	return true;
}

void MediaType::printResults() 
{ 
	for(vector< vector<string> >::const_iterator it_row = mediaTypeTable.begin();
		it_row != mediaTypeTable.end(); ++it_row ) {
			copy(it_row->begin(), it_row->end(), ostream_iterator<string>(cout, "\t"));
			cout << endl;
	}
} 

bool SortTable::operator()(const vector<string>& s1, const vector<string>& s2)
{
	if(stringNumeric(s1[SORT_COLUMN]) && stringNumeric(s2[SORT_COLUMN]))
		return SORT_ASCENDING ?
			atoi(s1[SORT_COLUMN].c_str()) < atoi(s2[SORT_COLUMN].c_str()) :
			atoi(s1[SORT_COLUMN].c_str()) > atoi(s2[SORT_COLUMN].c_str()) ;
	else
		return SORT_ASCENDING ? 
			stringCompare(s1[SORT_COLUMN], s2[SORT_COLUMN]) : 
			stringCompare(s2[SORT_COLUMN], s1[SORT_COLUMN]);
}

bool SortTable::stringCompare( const string &left, const string &right )
{
	for( string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
		if( tolower( *lit ) < tolower( *rit ) )
			return true;
		else if( tolower( *lit ) > tolower( *rit ) )
			return false;
	if( left.size() < right.size() )
		return true;
	return false;
}
