#include "GlobalFunctions.h"

void GlobalFunctions::option(string f) {
	string line;
	system("cls");
	ifstream file("pliki_tekstowe/" + f);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			cout << line << endl;
		}
	}
	else {
		cout << "Nie mozna otworzyc pliku!" << endl;
	}
	file.close();
}