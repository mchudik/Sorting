#pragma once
#include "MediaSource.h"

typedef void(*MediaSourceBucketizer)(MediaSourceOption&);
extern MediaSourceBucketizer mediaSourceBucketizers[];

class MediaSourceBucketizers
{
public:
	MediaSourceBucketizers() {};
	~MediaSourceBucketizers() {};

	static void MediaSourceBucketizers::bucketizeResolution(MediaSourceOption& mediaSourceOption);
	static void MediaSourceBucketizers::bucketizeAspectRatio(MediaSourceOption& mediaSourceOption);
	static void MediaSourceBucketizers::bucketizeFrameRate(MediaSourceOption& mediaSourceOption);
	static void MediaSourceBucketizers::bucketizeRecompression(MediaSourceOption& mediaSourceOption);
	static void MediaSourceBucketizers::bucketizeColorConversion(MediaSourceOption& mediaSourceOption);
};

