#include "stdafx.h"
#include "MediaSourceComparators.h"
#include "SortUtils.h"

// comparisons can be based on value of original mediaType parameters (m_frameWidth, m_frameHeight, m_frameRate, m_encoding)
// as well as comparing already generated curent bucket assignments between the two mediatypes
// Buckets are: 
//			m_bucketResolution;
//			m_bucketAspectRatio;
//			m_bucketFrameRate;
//			m_bucketRecompression;
//			m_bucketColorConversion;

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
