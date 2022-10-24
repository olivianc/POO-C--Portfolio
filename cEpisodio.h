#pragma once
#include "cVideo.h"


using namespace std;

class Episodio : public Video {
private:
	string title;
	int season;

public:
	Episodio();
	Episodio(int _id, string _name, string _type, int _length, string _genre, string _title, int _season, float _rating, int _raters);
	float getRating();
	string toString();
};