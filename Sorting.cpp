// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MediaSource.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MediaSource mediaSource;
	if(!mediaSource.loadFromFile("Media-HP Webcam 3110.csv"))
		return 1;

	vector <MediaSourceOption> sortedMediaSource = mediaSource.getSortedMediaSource(640, 480, 25, "YUY2");
	mediaSource.printSortedMediaSource(sortedMediaSource);
	cout << endl << "Best Media Type match from Media Source is at index " << sortedMediaSource[0].m_index << endl;
 
	return 0;
}

