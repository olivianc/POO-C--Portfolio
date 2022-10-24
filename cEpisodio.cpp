#include "cEpisodio.h"

Episodio::Episodio() : Episodio(0, "DEF", "DEF", 0, "DEF", "DEF", 0, 0.f, 0) {

}

Episodio::Episodio(int _id, string _name, string _type, int _length, string _genre, string _title, int _season, float _rating, int _raters) :Video(_id, _name, _type, _length, _genre, _rating, _raters) {
	title = _title;
	season = _season;
};

float Episodio::getRating()
{
	return rating;
}

string Episodio::toString() {
	string str = Video::toString()+"\n";
	str += "TITLE:" + title;
	str += "\nSEASON: " + to_string(season)+"\n";
	return str;
}
