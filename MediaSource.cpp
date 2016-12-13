#include "StdAfx.h"
#include "MediaSourceOption.h"
#include "MediaSourceBucketizers.h"
#include "MediaSourceComparators.h"
#include "SortUtils.h"

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

vector <MediaSourceOption>& MediaSource::getSortedMediaSource(
	unsigned int frameWidth,
	unsigned int frameHeight,
	double frameRate,
	string encoding)
{
	MediaSourceOption inputParameters(0, frameWidth, frameHeight, frameRate, encoding);

	// Bucketize first based on parameter criteria
	for (unsigned int i = 0; i < arraySize(mediaSourceBucketizers); i++) {
		for (MediaSourceOption &n : mediaSource) {
			mediaSourceBucketizers[i](n);
		}
	}
	// Sort second either by parameter values, and/or by bucket associations, and/or by input parameter values
	for (unsigned int i = 0; i < arraySize(mediaSourceComparators); i++) {
		stable_sort(mediaSource.begin(), mediaSource.end(), MediaSourceComparators(inputParameters, i));
	}
	return mediaSource;
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
void MediaSource::printSortedMediaSource(vector <MediaSourceOption>& mediaSourceOption)
{
	for (MediaSourceOption &n : mediaSourceOption) {
		cout << n.m_index << "\t" << n.m_frameWidth << "\t" << n.m_frameHeight << "\t" << n.m_frameRate << "\t" << n.m_encoding << "\t" << n.m_bucketFrameRate << endl;
	}
} 
