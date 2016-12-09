#pragma once
#include <iostream>     
#include <iterator>     
#include <vector>       
#include <algorithm>    
#include <sstream>
#include <fstream>
#include <string>
#include "MediaSourceOption.h"

using namespace std;

class MediaSource
{
public:
	MediaSource(void) {};
	~MediaSource(void) {};

	void addMediaSourceOption(
		unsigned int index,
		unsigned int frameWidth,
		unsigned int frameHeight,
		double frameRate,
		string encoding);
	void addMediaSourceOption(MediaSourceOption mediaSourceOption);
	int  sortMediaSource();
	void clearMediaSource();
	bool loadFromFile(string filePath);
	void printSortedMediaSource();

private:
	vector <MediaSourceOption> mediaSource;
};
