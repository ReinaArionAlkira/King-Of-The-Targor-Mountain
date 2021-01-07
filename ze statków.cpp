//#include <iostream>
//#include <random>
//#include <iomanip>
//
//using namespace std;
//
//int board[10][10]{};
//
//bool canPlaceShip(int x, int y) {
//    return (board[x][y] > 0);
//}
//
//int main() {
//
//    int ships[10] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
//
//    random_device device;
//    mt19937 generator(device());
//    uniform_int_distribution<int> coordinate(0, 9);
//    // 0 - pionowo, 1 - poziomo
//    uniform_int_distribution<int> theWay(0, 1);
//
//    for (int ship = 0; ship < 10; ship++) {
//
//        // D³ugoœæ statku jest jednoczeœnie jego oznaczeniem - 4-masztowiec to "4444" czyli jego oznaczeniem jest 4 
//        int shipLength = ships[ship];
//        // Zmienna kontrolna do zweryfikowania, czy statek mo¿e byæ postawiony
//        bool isGood = 0;
//        while (!isGood) {
//
//            int direction = theWay(generator);
//            // wspó³rzêdna której kierunek zosta³ wylosowany, poziom - y, pion - x
//            uniform_int_distribution<int> dirCoordinate(0, 9 - shipLength);
//
//            //jeœli idziemy pionowo
//            if (direction == 0) {
//
//                int y = coordinate(generator);
//                int x = dirCoordinate(generator);
//                isGood = 1;
//                // sprawdzanie wylosowanych zmiennych
//                // cout << "x " << x << "y " << y << endl;
//                // jeœli nie przylega do górnej œciany to sprawdŸ pola nad
//                if (x != 0) {
//                    for (int i = -1; i <= shipLength; i++) {
//                        if ((canPlaceShip(x + i, y + 1)) || (canPlaceShip(x + i, y)) || (canPlaceShip(x + i, y - 1))) {
//                            isGood = 0;
//                            break;
//                        }
//                    }
//                }
//                else {
//                    for (int i = 0; i <= shipLength; i++) {
//                        if ((canPlaceShip(x + i, y + 1)) || (canPlaceShip(x + i, y)) || (canPlaceShip(x + i, y - 1))) {
//                            isGood = 0;
//                            break;
//                        }
//                    }
//                }
//
//                // Jeœli nie da siê ustawiæ statku (isGood == false) to wróæ do nowego losowania
//                if (isGood == 0) continue;
//                // Stawianie w pionie
//                for (int i = 0; i < shipLength; i++) {
//
//                    if (i == 0 && x != 0)   board[x - 1][y] = -1;
//                    // czy nie przylega do prawej œciany
//                    if ((y != 9) && (x != 0)) {
//                        board[x - 1][y + 1] = -1;
//                        board[x][y + 1] = -1;
//                        board[x + 1][y + 1] = -1;
//                    }
//                    // czy nie przylega do lewej œciany
//                    if ((y != 0) && (x != 0)) {
//                        board[x - 1][y - 1] = -1;
//                        board[x][y - 1] = -1;
//                        board[x + 1][y - 1] = -1;
//                    }
//
//                    board[x][y] = shipLength;
//                    x++;
//                    // czy ostatnie pole statku nie przylega do dolnej œciany, jeœli nie, wstawia pod statek pole -1
//                    if ((i == (shipLength - 1)) && (x != 10))    board[x][y] = -1;
//
//                    // funkcja wypisuj¹ca planszê po ka¿dym zape³nieniu pola statku
//                    /*for (int i = 0; i < 10; i++) {
//                        for (int j = 0; j < 10; j++) {
//                           cout << setw(4) << board[i][j];
//                        }
//                        cout << endl;
//                    }
//                    cout << endl;*/
//                }
//
//            }
//            // Poziomo
//            if (direction == 1) {
//
//                int x = coordinate(generator);
//                int y = dirCoordinate(generator);
//
//                isGood = true;
//                // jeœli nie przylega do prawej œciany to sprawdŸ pola nad
//                if (y != 0) {
//                    for (int i = -1; i <= shipLength; i++) {
//                        if ((canPlaceShip(x + 1, y + i)) || (canPlaceShip(x, y + i)) || (canPlaceShip(x - 1, y + i))) {
//                            isGood = 0;
//                            break;
//                        }
//                    }
//                }
//                else {
//                    for (int i = 0; i <= shipLength; i++) {
//                        if ((canPlaceShip(x + 1, y + i)) || (canPlaceShip(x, y + i)) || (canPlaceShip(x - 1, y + i))) {
//                            isGood = 0;
//                            break;
//                        }
//                    }
//                }
//
//                if (!isGood) continue;
//                // stawianie poziome
//                for (int i = 0; i < shipLength; i++) {
//
//                    // czy pierwszy element statku nie przylega do lewej œciany
//                    if ((y != 0) && (i == 0))   board[x][y - 1] = -1;
//
//                    // czy nie przylega do dolnej lub lewej œciany
//                    if ((x != 9) && (y != 0)) {
//                        board[x + 1][y - 1] = -1;
//                        board[x + 1][y] = -1;
//                        board[x + 1][y + 1] = -1;
//                    }
//                    // czy nie przylega do górnej lub lewej œciany
//                    if ((x != 0) && (y != 0)) {
//                        board[x - 1][y - 1] = -1;
//                        board[x - 1][y] = -1;
//                        board[x - 1][y + 1] = -1;
//                    }
//
//                    board[x][y] = shipLength;
//                    y++;
//
//                    // czy nie przylega do prawej œciany
//                    if ((i == (shipLength - 1)) && (y != 10))    board[x][y] = -1;
//                }
//            }
//        }
//    }
//    // wypisanie planszy z bazowymi oznaczeniami
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << setw(3) << board[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    // wypisywanie planszy ze statkami jako 'x' i pustymi polami jako '-'
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//
//            if (board[i][j] > 0)     cout << setw(3) << 'x';
//            else    cout << setw(3) << '-';
//        }
//        cout << endl;
//    }
//    system("Pause");
//}