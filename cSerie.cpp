#include "cSerie.h"

Serie::Serie(string _name) {
    name = _name;
}

Serie::Serie(vector<Episodio*> _episodios, string _name){
    episodios = _episodios;
    name = _name;
}

void Serie::setSerie(string _name){

}

string Serie::getName() {
    return name;
}

float Serie::getRating()
{
   Episodio* e = new Episodio();
   vector<Episodio*>::iterator it;
   for(it = episodios.begin(); it != episodios.end(); ++it)
   {
       *e+*(*it);
   }
   return e->getRating() / episodios.size();
}

void Serie::addEpisodio(Episodio* e)
{
    episodios.push_back(e);
}

string Serie::inRating(float min, float max) {
    string str = "";
    vector<Episodio*>::iterator it;
    for (it = episodios.begin(); it != episodios.end(); ++it) {
        if ((*it)->getRating() >= min && (*it)->getRating() <= max) {
            str += (*it)->toString();
        }
    }
    return str;
}

string Serie::toString(){
    string str;
    vector<Episodio*>::iterator it;
    for (it = episodios.begin(); it != episodios.end(); ++it) {
        str += (*it)->toString();
    }
    return str;
}

float Serie::operator +(const Serie& v) {
    rating += v.rating;
    return rating;
}

vector<Episodio*> Serie::getEpisodios()
{
    return episodios;
}
