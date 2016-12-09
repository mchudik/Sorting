#pragma once
#include "MediaSource.h"
class MediaSourceComparators
{
public:
	MediaSourceComparators();
	~MediaSourceComparators();

	static bool MediaSourceComparators::compareFrameRate(const MediaType& source1, const MediaType& source2);
	static bool MediaSourceComparators::compareFrameWidth(const MediaType& source1, const MediaType& source2);
	static bool MediaSourceComparators::compareFrameHeight(const MediaType& source1, const MediaType& source2);
	static bool MediaSourceComparators::compareEncoding(const MediaType& source1, const MediaType& source2);
};

