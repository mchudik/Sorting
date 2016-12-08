// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MediaType.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MediaType mediaType;
	if(!mediaType.loadFromFile("Media-HP Webcam 3110.csv"))
		return 1;

	mediaType.sortColumn(4, true);	//Media Type	/ ascending
	mediaType.sortColumn(1, false);	//X-Dimension	/ descending
	mediaType.sortColumn(2, false);	//Frame Rate	/ descending
	mediaType.sortColumn(3, false);	//Y-Dimension	/ descending
	mediaType.printResults();

	return 0;
}

