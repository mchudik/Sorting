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

	vector <MediaSourceOption>& getSortedMediaSource(
		unsigned int frameWidth,
		unsigned int frameHeight,
		double frameRate,
		string encoding);

	void clearMediaSource();
	bool loadFromFile(string filePath);
	void printSortedMediaSource(vector <MediaSourceOption>& mediaSourceOption);

private:
	void addMediaSourceOption(MediaSourceOption mediaSourceOption);

	vector <MediaSourceOption> mediaSource;
};
