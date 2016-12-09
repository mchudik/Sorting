#include "stdafx.h"
#include "MediaSourceComparators.h"
#include "SortUtils.h"


MediaSourceComparators::MediaSourceComparators()
{
}


MediaSourceComparators::~MediaSourceComparators()
{
}

bool MediaSourceComparators::compareFrameRate(const MediaType& source1, const MediaType& source2) {
	// implementation example sorting in descending mode
	return source1.m_frameRate > source2.m_frameRate;
}
bool MediaSourceComparators::compareFrameWidth(const MediaType& source1, const MediaType& source2) {
	// implementation example - ascending
	return source1.m_frameWidth < source2.m_frameWidth;
}

bool MediaSourceComparators::compareFrameHeight(const MediaType& source1, const MediaType& source2) {
	// implementation example - ascending
	return source1.m_frameHeight < source2.m_frameHeight;
}

bool MediaSourceComparators::compareEncoding(const MediaType& source1, const MediaType& source2) {
	// implementation example - ascending
	return SortUtils::stringCompare(source1.m_encoding, source2.m_encoding);
}
