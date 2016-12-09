// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MediaSource.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MediaSource mediaSource;
	if(!mediaSource.loadFromFile("Media-HP Webcam 3110.csv"))
		return 1;

	int bestIndex = mediaSource.sortMediaSource();
	mediaSource.printSortedMediaSource();
	cout << endl << "Best Media Type match from Media Source is at index " << bestIndex << endl << endl;
 
	return 0;
}

