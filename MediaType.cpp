#include "stdafx.h"
#include "MediaSource.h"


MediaType::MediaType(
	unsigned int typeIndex,
	unsigned int frameWidth,
	unsigned int frameHeight,
	double frameRate,
	string encoding
) :
	m_typeIndex(typeIndex),
	m_frameWidth(frameWidth),
	m_frameHeight(frameHeight),
	m_frameRate(frameRate),
	m_encoding(encoding)
{
}


MediaType::~MediaType()
{
}
