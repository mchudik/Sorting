#pragma once
#include <string>
using namespace std;

class MediaSourceOption
{
public:
	MediaSourceOption(
		unsigned int index,
		unsigned int frameWidth,
		unsigned int frameHeight,
		double frameRate,
		string encoding);

	~MediaSourceOption();

	//Properies
	unsigned int m_index;
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
