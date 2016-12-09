#include "StdAfx.h"
#include "MediaSourceOption.h"
#include "MediaSourceBucketizers.h"
#include "MediaSourceComparators.h"

template <typename T, unsigned S>
inline unsigned arraySize(const T(&arr)[S]) { return S; }

typedef void(*MediaSourceBucketizer)(MediaSourceOption&);
typedef bool(*MediaSourceComparator)(const MediaSourceOption&, const MediaSourceOption&);

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
	MediaSourceComparators::compareFrameHeight,
	MediaSourceComparators::compareFrameRateBucket
};

void MediaSource::addMediaSourceOption(
	unsigned int index,
	unsigned int frameWidth,
	unsigned int frameHeight,
	double frameRate,
	string encoding)
{
	MediaSourceOption mediaSourceOption(index, frameWidth, frameHeight, frameRate, encoding);
	addMediaSourceOption(mediaSourceOption);
}

void MediaSource::addMediaSourceOption(MediaSourceOption mediaSourceOption)
{
	mediaSource.push_back(mediaSourceOption);
}

// Main entry for sorting the list by individual functions
int MediaSource::sortMediaSource()
{
	// Bucketize first based on parameter criteria
	for (unsigned int i = 0; i < arraySize(mediaSourceBucketizers); i++) {
		for (MediaSourceOption &n : mediaSource) {
			mediaSourceBucketizers[i](n);
		}
	}
	// Sort second either by parameter values, and/or by bucket associations
	for (unsigned int i = 0; i < arraySize(mediaSourceComparators); i++) {
		stable_sort(mediaSource.begin(), mediaSource.end(), mediaSourceComparators[i]);
	}
	// Return the topmost media type, the best match
	return mediaSource.size() > 0 ? mediaSource.at(0).m_index : -1;
}

void MediaSource::clearMediaSource()
{
	mediaSource.empty();
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
		MediaSourceOption mediaSourceOption(atoi(record[0].c_str()), atoi(record[1].c_str()), atoi(record[2].c_str()), atof(record[3].c_str()), record[4].c_str());
		addMediaSourceOption(mediaSourceOption);
	}
	if (!infile.eof()) {
		cerr << "Error reading file!\n";
		return false;
	}
	return true;
}

// Just for debugging - remove
void MediaSource::printSortedMediaSource() 
{
	for (MediaSourceOption &n : mediaSource) {
		cout << n.m_index << "\t" << n.m_frameWidth << "\t" << n.m_frameHeight << "\t" << n.m_frameRate << "\t" << n.m_encoding << "\t" << n.m_bucketFrameRate << endl;
	}
} 
