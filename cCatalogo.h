#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "cVideo.h"
#include "cSerie.h"
#include "cPelicula.h"
#include "cEpisodio.h"

using namespace std;

class Catalogo {
private:
	vector<Pelicula*> peliculas;
	vector<Serie*> series;

public:
	Catalogo();
	vector<Serie*>getSerie();

	vector<Pelicula*>getPelicula();
	bool findSerie(string name);

	vector<string> split(string original, string delimiter);
	vector<string> readFileToStringVector(string filename);
	Serie* getSerie(string name);

	int stringToInt(string s);
	float stringToFloat(string s);

	string toString();

	void run();
	void cat();

	void catGen();

	void catRateGen();
	void catRatePel();
	void catRateSer();

	void catGenGen();
	void catGenPel();
	void catGenSer();

	void rate();
};