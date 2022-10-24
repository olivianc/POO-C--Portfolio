#pragma once
#include "cVideo.h"

using namespace std;

class Pelicula : public Video {
private:
	double calificacion;
public:
	Pelicula(int _id, string _name, string _type, int _length, string _genre, float _rating, int _raters);
	string toString();
};