#include "stdafx.h"
#include "MediaSourceComparators.h"
#include "SortUtils.h"

// comparisons can be based on value of original mediaSourceOption parameters (m_frameWidth, m_frameHeight, m_frameRate, m_encoding)
// as well as comparing already generated curent bucket assignments between the two mediaSourceOptions
// Buckets are: 
//			m_bucketResolution;
//			m_bucketAspectRatio;
//			m_bucketFrameRate;
//			m_bucketRecompression;
//			m_bucketColorConversion;

bool MediaSourceComparators::compareFrameRate(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2) {
	// implementation example sorting in descending mode
	return mediaSourceOption1.m_frameRate > mediaSourceOption2.m_frameRate;
}
bool MediaSourceComparators::compareFrameRateBucket(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2) {
	// implementation example sorting in descending mode
	return mediaSourceOption1.m_bucketFrameRate < mediaSourceOption2.m_bucketFrameRate;
}

bool MediaSourceComparators::compareFrameWidth(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2) {
	// implementation example - ascending
	return mediaSourceOption1.m_frameWidth < mediaSourceOption2.m_frameWidth;
}

bool MediaSourceComparators::compareFrameHeight(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2) {
	// implementation example - ascending
	return mediaSourceOption1.m_frameHeight < mediaSourceOption2.m_frameHeight;
}

bool MediaSourceComparators::compareEncoding(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2) {
	// implementation example - ascending
	return SortUtils::stringCompare(mediaSourceOption1.m_encoding, mediaSourceOption2.m_encoding);
}
