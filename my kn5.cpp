#include <iostream>

using namespace std;

const int ROW = 8; // Строки игрового поля
const int COL = 14; // Колонки игрового поля

int x = 0; // Координата позиции по горизонтали
int y = 0; // Координата позиции по вертикали
int counter = 0; // Счетчик ходов

bool gameOwer = false;
bool mot = true;
bool vinner = false;

char motion[ROW][COL]{ // Массив, содержащий игровое полу
{' ',' ',' ','1',' ',' ',' ','2',' ',' ',' ','3',' ',' '},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'1','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'2','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'3','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'}, };

char motion1[ROW][COL]{ // Массив, для обновления игрового поля
{' ',' ',' ','1',' ',' ',' ','2',' ',' ',' ','3',' ',' '},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'1','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'2','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'},
{'3','|',' ','.',' ','|',' ','.',' ','|',' ','.',' ','|'},
{' ','-','-','-','-','-','-','-','-','-','-','-','-','-'}, };

int Navigation() { // Выбор клетки для установки знака, выровнено для большего удобства пользователя
	if (x == 1) {
		x = 2;
	}
	else if (x == 2) {
		x = 4;
	}
	else if (x == 3) {
		x = 6;
	}
	if (y == 1) {
		y = 3;
	}
	else if (y == 2) {
		y = 7;
	}
	else if (y == 3) {
		y = 11;
	}
	return x, y;
}

void GameOwer() { // Варианты завершения игры
	if (motion[2][3] == motion[2][7] && motion[2][3] == motion[2][11]) {
		if (motion[2][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[2][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[4][3] == motion[4][7] && motion[4][3] == motion[4][11]) {
		if (motion[4][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[4][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[6][3] == motion[6][7] && motion[6][3] == motion[6][11]) {
		if (motion[6][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[6][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[2][3] == motion[4][3] && motion[2][3] == motion[6][3]) {
		if (motion[2][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[2][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[2][7] == motion[4][7] && motion[2][7] == motion[6][7]) {
		if (motion[2][7] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[2][7] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[2][11] == motion[4][11] && motion[2][11] == motion[6][11]) {
		if (motion[2][11] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[2][11] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[2][3] == motion[4][7] && motion[2][3] == motion[6][11]) {
		if (motion[2][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[2][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	else if (motion[6][3] == motion[4][7] && motion[6][3] == motion[2][11]) {
		if (motion[6][3] == 'X') {
			cout << "Game Ower! Vinner Gamer X" << endl;
			gameOwer = true;
			vinner = true;
		}
		else if (motion[6][3] == 'O') {
			cout << "Game Ower! Vinner Gamer O" << endl;
			gameOwer = true;
			vinner = true;
		}
	}
	if (counter == 9 && /*vinner == false*/) { // Вариант с ничьей
		gameOwer = true;
		cout << "Game Ower! Draw" << endl;
	}
}

void Draw() { // Отрисовка игрового поля
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << motion[i][j];
		}
		cout << endl;
	}
}

void Motion() { // Переключение ходов

	if (mot == true) {
		cout << "Motion gamer X" << endl;
	}
	else if (mot == false) {
		cout << "Motion gamer O" << endl;
	}
	
	cout << "Input position col: ";
	cin >> y;

	cout << "Input position row: ";
	cin >> x;
	
	Navigation(); // Переоформление введенных значений под ячейка массива
	
	if (mot == true && motion[x][y] == '.') {
		motion[x][y] = 'X';
		mot = false;
		counter = counter + 1;
	}
	else if (mot == false && motion[x][y] == '.') {
		motion[x][y] = 'O';
		mot = true;
		counter = counter + 1;
	}
	else if (motion[x][y] != '.') { // Проверка на невозможный ход
		cout << "Error! The field is occupied" << endl;
		system("pause");
	}
}

int main() {
	int repeat = 1; // Переменная отвечающая за новую игру
	while (repeat == 1) {
		while (gameOwer == false) {
			system("cls");
			Draw();
			Motion();
			system("cls");
			Draw();
			GameOwer();
		}
		cout << "Repeat game? 1 - yas, 0 - no ";
		cin >> repeat;
		if (repeat == 1) { // Если игрок хочет сыграть еще, переключаем переменную gameOwer и обновляем игровое поле
			gameOwer = false;
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					motion[i][j] = motion1[i][j];
				}
			}
		}
	}
	return 0;
}
