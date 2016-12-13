#include "stdafx.h"
#include "MediaSourceComparators.h"
#include "SortUtils.h"

// This list defines order of processing individual comparators
static MediaSourceComparator mediaSourceComparators[] = {
	MediaSourceComparators::compareEncoding,
	MediaSourceComparators::compareFrameRate,
	MediaSourceComparators::compareFrameWidth,
	MediaSourceComparators::compareFrameHeight,
	MediaSourceComparators::compareFrameRateBucket
};

bool MediaSourceComparators::operator()(const MediaSourceOption& mediaSourceOption1, const MediaSourceOption& mediaSourceOption2)
{
	return mediaSourceComparators[COMPARATOR](mediaSourceOption1, mediaSourceOption2, INPUT_PARAMETERS, COMPARATOR);
}

// Comparisons can be based on value of original mediaSourceOption parameters (m_frameWidth, m_frameHeight, m_frameRate, m_encoding),
// as well as comparing already generated curent bucket assignments (m_bucketResolution, m_bucketAspectRatio, m_bucketFrameRate, m_bucketRecompression, m_bucketColorConversion),
// as well as using any requested input parameters for comparison (inputParameters.m_frameWidth, inputParameters.m_frameHeight, inputParameters.m_frameRate, inputParameters.m_encoding)

bool MediaSourceComparators::compareFrameRate(
	const MediaSourceOption& mediaSourceOption1, 
	const MediaSourceOption& mediaSourceOption2, 
	const MediaSourceOption& inputParameters,
	const int comparator) {
	// implementation example sorting in descending mode and considering input parameters
	return (mediaSourceOption1.m_frameRate > mediaSourceOption2.m_frameRate) && inputParameters.m_frameHeight < 640;
}

bool MediaSourceComparators::compareFrameRateBucket(
	const MediaSourceOption& mediaSourceOption1, 
	const MediaSourceOption& mediaSourceOption2, 
	const MediaSourceOption& inputParameters,
	const int comparator) {
	// implementation example sorting in descending mode comparing bucket values
	return mediaSourceOption1.m_bucketFrameRate < mediaSourceOption2.m_bucketFrameRate;
}

bool MediaSourceComparators::compareFrameWidth(
	const MediaSourceOption& mediaSourceOption1, 
	const MediaSourceOption& mediaSourceOption2, 
	const MediaSourceOption& inputParameters,
	const int comparator) {
	// implementation example - ascending
	return mediaSourceOption1.m_frameWidth < mediaSourceOption2.m_frameWidth;
}

bool MediaSourceComparators::compareFrameHeight(
	const MediaSourceOption& mediaSourceOption1, 
	const MediaSourceOption& mediaSourceOption2, 
	const MediaSourceOption& inputParameters,
	const int comparator) {
	// implementation example - ascending
	return mediaSourceOption1.m_frameHeight < mediaSourceOption2.m_frameHeight;
}

bool MediaSourceComparators::compareEncoding(
	const MediaSourceOption& mediaSourceOption1, 
	const MediaSourceOption& mediaSourceOption2, 
	const MediaSourceOption& inputParameters,
	const int comparator) {
	// implementation example - ascending
	return SortUtils::stringCompare(mediaSourceOption1.m_encoding, mediaSourceOption2.m_encoding);
}
