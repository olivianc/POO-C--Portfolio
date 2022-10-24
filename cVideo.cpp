#include "cVideo.h"

Video::Video() {

};

Video::Video(int _id, string _name, string _type, int _length, string _genre, float _rating, int _raters) {
	id = _id;
	name = _name;
	type = _type;
	length = _length;
	genre = _genre;
	rating = _rating;
	raters = _raters;
};

int Video::getID(){
	return id;
}
string Video::getName(){
	return name;
}
string Video::getType(){
	return type;
}
int Video::getLength(){
	return length;
}
string Video::getGenre(){
	return genre;
}
float Video::getRating(){
	return rating;
}
int Video::getRaters(){
	return raters;
}

float Video::operator +(const Video & v){
	rating += v.rating;
	return rating;
}

string Video::toString(){
	string info = "";
	info += "\nID: " + to_string(id) + 
	+ "\nNAME: " + name + 
	+ "\nTYPE: "+ type +
	+ "\nLENGHT: " + to_string(length) +
	+ "\nGENRE: " + genre +
	+ "\nRATING: "+ to_string(rating) +
	+ "\nRATERS: " +to_string(raters);
	return info;
}



