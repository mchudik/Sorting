#include "stdafx.h"
#include "MediaSource.h"


MediaSourceOption::MediaSourceOption(
	unsigned int index,
	unsigned int frameWidth,
	unsigned int frameHeight,
	double frameRate,
	string encoding
) :
	m_index(index),
	m_frameWidth(frameWidth),
	m_frameHeight(frameHeight),
	m_frameRate(frameRate),
	m_encoding(encoding)
{
}


MediaSourceOption::~MediaSourceOption()
{
}
