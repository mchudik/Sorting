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

	unsigned int m_typeIndex;
	unsigned int m_frameWidth;
	unsigned int m_frameHeight;
	double m_frameRate;
	string m_encoding;
};
