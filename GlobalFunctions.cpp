#include "GlobalFunctions.h"

void readFile(string f) {
	string line;
	system("cls");
	ifstream file("text_files/" + f);
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