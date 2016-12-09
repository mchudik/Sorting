#include "StdAfx.h"
#include "MediaType.h"
#include "MediaSourceBucketizers.h"
#include "MediaSourceComparators.h"

template <typename T, unsigned S>
inline unsigned arraySize(const T(&arr)[S]) { return S; }

typedef void(*MediaSourceBucketizer)(MediaType&);
typedef bool(*MediaSourceComparator)(const MediaType&, const MediaType&);

// This list defines order of processing individual bucketizers
static MediaSourceBucketizer mediaSourceBucketizers[] = {
	MediaSourceBucketizers::bucketizeResolution,
	MediaSourceBucketizers::bucketizeAspectRatio,
	MediaSourceBucketizers::bucketizeFrameRate,
	MediaSourceBucketizers::bucketizeRecompression,
	MediaSourceBucketizers::bucketizeColorConversion
};

// This list defines order of processing individual comparators
static MediaSourceComparator mediaSourceComparators[] = {
	MediaSourceComparators::compareEncoding,
	MediaSourceComparators::compareFrameRate,
	MediaSourceComparators::compareFrameWidth,
	MediaSourceComparators::compareFrameHeight
};

void MediaSource::AddMediaType(MediaType mediaType)
{
	mediaTypeList.push_back(mediaType);
}

// Main entry for sorting the list by individual functions
int MediaSource::sortMediaTypes()
{
	// Bucketize first based on parameter criteria
	for (unsigned int i = 0; i < arraySize(mediaSourceBucketizers); i++) {
		for (MediaType &n : mediaTypeList) {
			mediaSourceBucketizers[i](n);
		}
	}
	// Sort second either by parameter values, and/or by bucket associations
	for (unsigned int i = 0; i < arraySize(mediaSourceComparators); i++) {
		stable_sort(mediaTypeList.begin(), mediaTypeList.end(), mediaSourceComparators[i]);
	}
	return mediaTypeList.size() > 0 ? mediaTypeList.at(0).m_typeIndex : -1;
}

void MediaSource::ClearMediaTypeList()
{
	mediaTypeList.empty();
}

// Just for testing - remove
bool MediaSource::loadFromFile(string filePath)
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
		MediaType mediaType(atoi(record[0].c_str()), atoi(record[1].c_str()), atoi(record[2].c_str()), atof(record[3].c_str()), record[4].c_str());
		AddMediaType(mediaType);
	}
	if (!infile.eof()) {
		cerr << "Error reading file!\n";
		return false;
	}
	return true;
}

// Just for debugging - remove
void MediaSource::printSortedMediaTypes() 
{
	for (MediaType &n : mediaTypeList) {
		cout << n.m_typeIndex << "\t" << n.m_frameWidth << "\t" << n.m_frameHeight << "\t" << n.m_frameRate << "\t" << n.m_encoding << "\t" << n.m_bucketFrameRate << endl;
	}
} 
