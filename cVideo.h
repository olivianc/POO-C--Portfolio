#pragma once 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Video {
protected:
	int id;
	string name;
	string type;
	int length;
	string genre;
	float rating;
	int raters;

public:
	Video();
	Video(int _id, string _name, string _type, int _length, string _genre, float _rating, int _raters);
	int getID();
	string getName();
	string getType();
	int getLength();
	string getGenre();
	float getRating();
	int getRaters();
	float operator+(const Video &);
	virtual string toString() = 0;
};
