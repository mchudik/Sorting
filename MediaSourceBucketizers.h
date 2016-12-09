#pragma once
#include "MediaSource.h"

class MediaSourceBucketizers
{
public:
	MediaSourceBucketizers();
	~MediaSourceBucketizers();

	static void MediaSourceBucketizers::bucketizeResolution(MediaType& mediaType);
	static void MediaSourceBucketizers::bucketizeAspectRatio(MediaType& mediaType);
	static void MediaSourceBucketizers::bucketizeFrameRate(MediaType& mediaType);
	static void MediaSourceBucketizers::bucketizeRecompression(MediaType& mediaType);
	static void MediaSourceBucketizers::bucketizeColorConversion(MediaType& mediaType);
};

