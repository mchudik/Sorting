#pragma once
#include "MediaSource.h"

class MediaSourceComparators
{
public:
	MediaSourceComparators() {};
	~MediaSourceComparators() {};

	static bool MediaSourceComparators::compareFrameRate(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);
	static bool MediaSourceComparators::compareFrameWidth(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);
	static bool MediaSourceComparators::compareFrameHeight(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);
	static bool MediaSourceComparators::compareEncoding(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);
	static bool MediaSourceComparators::compareFrameRateBucket(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2);
};

