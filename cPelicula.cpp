#include "cPelicula.h"

Pelicula::Pelicula(int _id, string _name, string _type, int _length, string _genre, float _rating, int _raters) :Video(_id, _name, _type, _length, _genre, _rating, _raters) {
	id = _id;
	name = _name;
	type = _type;
	length = _length;
	genre = _genre;
	rating = _rating;
	raters = _raters;
};

string Pelicula::toString() {
	string str = Video::toString();
	return str;
}