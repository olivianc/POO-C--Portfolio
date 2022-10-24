#include "cCatalogo.h"

Catalogo::Catalogo() {
	
}

void Catalogo::rate() {
	int idrate = 0;
	string typerate = "";
	
	system("clear");


	cout << endl;
	catGen();
	cout << endl;

	cout << "Introduce el tipo del elemento a evaluar (Serie o Pelicula): ";
	cin >> typerate;
	while (typerate != "Serie" && typerate != "Pelicula") {
		cout << "\nTipo erroneo, intentelo de nuevo: ";
		cin >> typerate;
	}

	cout << "Introduce el ID del elemento a evaluar: ";
	cin >> idrate;
	while (idrate < 1 || idrate>50) {
		cout << "\nID erroneo, intentelo de nuevo: ";
		cin >> idrate;
	}
}

void Catalogo::catGen() {
	cout << toString() << endl;
}


void Catalogo::catRateGen() {
	float rmin = 0.0f, rmax = 0.0f;
	cout << "Ingresa el rango de busqueda de calificación";
	cout << "\nRango mínimo: ";
	cin >> rmin;
	while (rmin < 0 || rmin>5) {
		cout << "\nRango minimo erroneo, intentelo de nuevo: ";
		cin >> rmin;
	}

	cout << "\nRango máximo: ";
	cin >> rmax;
	while (rmax < 0 || rmax>5) {
		cout << "\nRango máximo erroneo, intentelo de nuevo: ";
		cin >> rmax;
	}

	string str = "CATALOGO GENERAL CALIFICACIÓN: \n";
	vector<Serie*>::iterator its;
	vector<Episodio*>::iterator ite;
	vector<Pelicula*>::iterator itp;
	vector<Episodio*> echcat2;

	for (its = series.begin(); its != series.end(); ++its) {
		echcat2.clear();
		echcat2 = (*its)->getEpisodios();
		

		for(ite = echcat2.begin(); ite != echcat2.end(); ++ite)
			if((*ite) -> getRating() >= rmin && rmax >= (*ite) -> getRating())
				str += (*ite) -> toString() + "\n";
	}

	for (itp = peliculas.begin(); itp != peliculas.end(); ++itp) {
		if ((*itp)->getRating() >= rmin && rmax >= (*itp)->getRating())
		str += (*itp)->toString() + "\n";
	}

	cout << str;
}

void Catalogo::catRatePel() {
	float rmin = 0.0f, rmax = 0.0f;
	cout << "Ingresa el rango de busqueda de calificación";
	cout << "\nRango mínimo: ";
	cin >> rmin;
	while (rmin < 0 || rmin>5) {
		cout << "\nRango minimo erroneo, intentelo de nuevo: ";
		cin >> rmin;
	}

	cout << "\nRango máximo: ";
	cin >> rmax;
	while (rmax < 0 || rmax>5) {
		cout << "\nRango máximo erroneo, intentelo de nuevo: ";
		cin >> rmax;
	}

	string str = "CATALOGO PELICULA CALIFICACIÓN: \n";

	vector<Pelicula*>::iterator itp;

	for (itp = peliculas.begin(); itp != peliculas.end(); ++itp) {
		if ((*itp)->getRating() >= rmin && rmax >= (*itp)->getRating())
			str += (*itp)->toString() + "\n";
	}

	cout << str;
}

void Catalogo::catRateSer() {
	float rmin = 0.0f, rmax = 0.0f;
	cout << "Ingresa el rango de busqueda de calificación";
	cout << "\nRango mínimo: ";
	cin >> rmin;
	while (rmin < 0 || rmin>5) {
		cout << "\nRango minimo erroneo, intentelo de nuevo: ";
		cin >> rmin;
	}

	cout << "\nRango máximo: ";
	cin >> rmax;
	while (rmax < 0 || rmax>5) {
		cout << "\nRango máximo erroneo, intentelo de nuevo: ";
		cin >> rmax;
	}

	string str = "CATALOGO SERIE CALIFICACIÓN: \n";

	vector<Serie*>::iterator its;
	vector<Episodio*>::iterator ite;
	vector<Episodio*> echcat2;

	for (its = series.begin(); its != series.end(); ++its) {
		echcat2.clear();
		echcat2 = (*its)->getEpisodios();


		for (ite = echcat2.begin(); ite != echcat2.end(); ++ite)
			if ((*ite)->getRating() >= rmin && rmax >= (*ite)->getRating())
				str += (*ite)->toString() + "\n";
	}

	cout << str;
}

void Catalogo::catGenGen() {
	string gen = "";
	cout << "Ingresa el genero de busqueda: ";
	cin >> gen;

	string str = "CATALOGO GENERAL GENERO: \n";
	vector<Serie*>::iterator its;
	vector<Episodio*>::iterator ite;
	vector<Pelicula*>::iterator itp;
	vector<Episodio*> echcat2;

	for (its = series.begin(); its != series.end(); ++its) {
		echcat2.clear();
		echcat2 = (*its)->getEpisodios();


		for (ite = echcat2.begin(); ite != echcat2.end(); ++ite)
			if ((*ite)->getGenre() == gen)
				str += (*ite)->toString() + "\n";
	}

	for (itp = peliculas.begin(); itp != peliculas.end(); ++itp) {
		if ((*itp)->getGenre() == gen)
			str += (*itp)->toString() + "\n";
	}

	cout << str;
}


void Catalogo::catGenPel() {
	string gen = "";
	cout << "Ingresa el genero de busqueda: ";
	cin >> gen;

	string str = "CATALOGO PELICULAS GENERO: \n";
	vector<Pelicula*>::iterator itp;

	for (itp = peliculas.begin(); itp != peliculas.end(); ++itp) {
		if ((*itp)->getGenre() == gen)
			str += (*itp)->toString() + "\n";
	}

	cout << str;
}

void Catalogo::catGenSer() {
	string gen = "";
	cout << "Ingresa el genero de busqueda: ";
	cin >> gen;

	string str = "CATALOGO SERIES GENERO: \n";
	vector<Serie*>::iterator its;
	vector<Episodio*>::iterator ite;
	vector<Episodio*> echcat2;

	for (its = series.begin(); its != series.end(); ++its) {
		echcat2.clear();
		echcat2 = (*its)->getEpisodios();


		for (ite = echcat2.begin(); ite != echcat2.end(); ++ite)
			if ((*ite)->getGenre() == gen)
				str += (*ite)->toString() + "\n";
	}

	cout << str;
}


void Catalogo::cat() {
	vector<string> lines = readFileToStringVector("Catalogo.csv");
	cout << "READ FILE SUCCESSFUL :)" << endl;
	cout << "READ " << to_string(lines.size()) << " LINES." << endl;

	vector<string>::iterator it;
	for (it = lines.begin(); it != lines.end(); it++) {
		string line = (*it);
		vector<string> parts = split(line, ",");
		if (parts.size() > 8) {
			int id = stringToInt(parts[0]);
			string name = parts[1];
			string type = parts[2];
			int length = stringToInt(parts[3]);
			string genre = parts[4];
			string title = parts[5];
			int season = stringToInt(parts[6]);
			float rating = stringToFloat(parts[7]);
			int raters = stringToInt(parts[8]);

			if (type == "Serie") {


				if (findSerie(name) == true){
					Serie* s = getSerie(name);
					series.push_back(s);
					Episodio* e = new Episodio(id, name, type, length, genre, title, season, rating, raters);
					s->addEpisodio(e);
				}

				else
				{
					Serie* s = new Serie(name);
					series.push_back(s);
					Episodio* e = new Episodio(id, name, type, length, genre, title, season, rating, raters);
					s->addEpisodio(e);
				}
			}

			if (type == "Pelicula") {
				Pelicula* p = new Pelicula(id, name, type, length, genre, rating, raters);
				peliculas.push_back(p);
			}

			for (int i = 0; i < parts.size(); i++) {
				cout << parts[i] << "\t";
			}
			cout << endl;
		}
	}
	cout<< endl << endl;
}

void Catalogo::run() {
	cat();
	
	int op;
	do {
		cout << "Menu principal\n";
		cout << "\n1) Ver catalogo general de videos";

		cout << "\n2) Ver catalogo de videos con cierto rango de calificación";
		cout << "\n3) Ver catalogo de peliculas con cierto rango de calificación";
		cout << "\n4) Ver catalogo de series con cierto rango de calificación";

		cout << "\n5) Ver catalogo de videos con cierto género";
		cout << "\n6) Ver catalogo de peliculas con cierto género";
		cout << "\n7) Ver catalogo de series con cierto género";

		cout << "\n8) Evaluar video";

		cout << "\n9) Salir\n";

		cin >> op;

		while (op < 1 or op>9) {
			cout << "Error, por favor ingresa una opción valida del 1-6.";
		}

		switch (op) {
		case 1:
			catGen();
			system("pause");
			system("cls");
			break;

		case 2:
			catRateGen();
			system("pause");
			system("cls");
			break;

		case 3:
			catRatePel();
			system("pause");
			system("cls");
			break;

		case 4:
			catRateSer();
			system("pause");
			system("cls");
			break;

		case 5:
			catGenGen();
			system("pause");
			system("cls");
			break;

		case 6:
			catGenPel();
			system("pause");
			system("cls");
			break;

		case 7:
			catGenSer();
			system("pause");
			system("cls");
			break;
			
		case 8:
			rate();
			system("pause");
			system("cls");
			break;

		case 9:
			cout << "Gracias por su atención.";
			break;

		default:
			cout << "Opcion invalida, intentelo de nuevo.";
			break;
		}
	} while (op != 9);
	system("CLS");
}

vector<string> Catalogo::split(string original, string delimiter) {
	vector<string> splitted;
	size_t pos = 0;
	string token;
	while ((pos = original.find(delimiter)) != string::npos)
	{
		token = original.substr(0, pos);
		//cout << "TOKEN: " << token << endl;
		splitted.push_back(token);
		original.erase(0, pos + delimiter.length());
	}
	splitted.push_back(original);
	return splitted;
}

vector<string> Catalogo::readFileToStringVector(string filename) {
	vector<string> lines;
	fstream theFile;
	theFile.open(filename, ios::in);
	if (theFile.is_open())
	{
		string line;
		while (getline(theFile, line))
		{
			lines.push_back(line);
		}
	}
	theFile.close();
	return lines;
}

int Catalogo::stringToInt(string s) {
	int n = 0;
	stringstream ssn;
	ssn << s;
	ssn >> n;

	return n;
}

float Catalogo::stringToFloat(string s) {
	float n = 0;
	stringstream ssn;
	ssn << s;
	ssn >> n;

	return n;
}

vector<Pelicula*>Catalogo::getPelicula()
{
	return peliculas;
}

vector<Serie*>Catalogo::getSerie()
{
	return series;
}


bool Catalogo::findSerie(string name){
	vector<Serie*>::iterator it;
	for (it=series.begin();it!=series.end();++it){
		if (name.compare((*it)->getName())== 0){
			return true;
		}
	}
	return false;
}

Serie* Catalogo::getSerie(string name){
	vector<Serie*>::iterator it;
	for(it = series.begin(); it != series.end(); ++it)
	{
		if(name.compare((*it)->getName())==0)
		{
			return (*it);
		}
	}
	return NULL;
}


string Catalogo::toString() {
	string str = "CATALOGO: \n";
	vector<Serie*>::iterator its;
	vector<Pelicula*>::iterator itp;

	for (its = series.begin(); its != series.end(); ++its) {
		str += (*its)->toString() + "\n";
	}

	for (itp = peliculas.begin(); itp != peliculas.end(); ++itp) {
		str += (*itp)->toString() + "\n";
	}
	return str;
}
