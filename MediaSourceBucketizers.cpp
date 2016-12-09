#include "stdafx.h"
#include "MediaSourceBucketizers.h"


void MediaSourceBucketizers::bucketizeResolution(MediaType& mediaType)
{
	// Resolution (Height)-4 buckets, 1080 - 720 - 480 – 240, Indicating median of a range
}

void MediaSourceBucketizers::bucketizeAspectRatio(MediaType& mediaType)
{
	// Aspect ratio - 2 buckets, 16:9 (1080, 720) - 4:3 (480, 240), In order of preference
}

void MediaSourceBucketizers::bucketizeFrameRate(MediaType& mediaType)
{
	// Frame Rate - 5 buckets, >30, 30-24, 23-15, 14-10, 10>, Inclination is to higher within the group
	if (mediaType.m_frameRate > 30)
		mediaType.m_bucketFrameRate = 0;
	else if (mediaType.m_frameRate > 23)
		mediaType.m_bucketFrameRate = 1;
	else if (mediaType.m_frameRate > 14)
		mediaType.m_bucketFrameRate = 2;
	else if (mediaType.m_frameRate > 9)
		mediaType.m_bucketFrameRate = 3;
	else
		mediaType.m_bucketFrameRate = 4;
}

void MediaSourceBucketizers::bucketizeRecompression(MediaType& mediaType)
{
	// Recompression - 2 buckets, H264 will be kept compressed,  MJPG will be recompressed to MP4
}

void MediaSourceBucketizers::bucketizeColorConversion(MediaType& mediaType)
{
	// Color conversion - 2 buckets, Yes - No, The I420, IYUV, NV12, YUY2, YV12 do not require conversion as they are accepted on the H264 encoder input
}
