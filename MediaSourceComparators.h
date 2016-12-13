#pragma once
#include "MediaSource.h"

typedef bool(*MediaSourceComparator)(const MediaSourceOption&, const MediaSourceOption&, const MediaSourceOption&, const int);
extern MediaSourceComparator mediaSourceComparators[];

class MediaSourceComparators
{
public:
	MediaSourceComparators(const MediaSourceOption& inputParameters, const int comparator) :
	COMPARATOR(comparator), 
	INPUT_PARAMETERS(inputParameters) {};
	~MediaSourceComparators() {};

	bool operator()(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);

	static bool MediaSourceComparators::compareFrameRate(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2, const MediaSourceOption& inputParameters, const int comparator);
	static bool MediaSourceComparators::compareFrameWidth(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2, const MediaSourceOption& inputParameters, const int comparator);
	static bool MediaSourceComparators::compareFrameHeight(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2, const MediaSourceOption& inputParameters, const int comparator);
	static bool MediaSourceComparators::compareEncoding(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2, const MediaSourceOption& inputParameters, const int comparator);
	static bool MediaSourceComparators::compareFrameRateBucket(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2, const MediaSourceOption& inputParameters, const int comparator);

private:
	const int COMPARATOR;
	MediaSourceOption INPUT_PARAMETERS;
};

