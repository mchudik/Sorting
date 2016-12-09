#pragma once
#include <string>
using namespace std;

class MediaType
{
public:
	MediaType(
		unsigned int typeIndex,
		unsigned int frameWidth,
		unsigned int frameHeight,
		double frameRate,
		string encoding);

	~MediaType();

	//Properies
	unsigned int m_typeIndex;
	unsigned int m_frameWidth;
	unsigned int m_frameHeight;
	double m_frameRate;
	string m_encoding;

	//Buckets
	unsigned int m_bucketResolution;
	unsigned int m_bucketAspectRatio;
	unsigned int m_bucketFrameRate;
	unsigned int m_bucketRecompression;
	unsigned int m_bucketColorConversion;
};
