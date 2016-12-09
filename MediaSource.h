#pragma once
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy
#include <sstream>
#include <fstream>
#include <string>
#include "MediaType.h"

using namespace std;

class MediaSource
{
public:
	MediaSource(void) {};
	~MediaSource(void) {};

	void AddMediaType(MediaType mediaType);
	int sortMediaTypes();
	void ClearMediaTypeList();
	bool loadFromFile(string filePath);
	void printSortedMediaTypes();

private:
	vector <MediaType> mediaTypeList;
};
