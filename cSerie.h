#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "cEpisodio.h"	

using namespace std;

class Serie{
protected:
	string name;
	float rating;
	Episodio* episodio;
	vector<Episodio*> episodios;

public:
	Serie(string _name);
	Serie(vector<Episodio*> _episodios, string _name);
	float getRating();
	string getName();
	vector<Episodio*> getEpisodios();
	void setSerie(string _name);
	void addEpisodio(Episodio* e);
	string toString();
	float operator+(const Serie&);
	string inRating(float min, float max);
};