#include <iostream>
#include <ctime>

using namespace std;

int a = 2; // Количество карт игрока
int b = 0; // Количество карт компьютера
int sumGamer = 0; // Сумма карт игрока
int sumProgramm = 0; // Сумма карт компьютера
int totalG = 0; // Общий счет игрока
int totalC = 0; // Общий счет компьютера
int game = 1; // Переменная окончания игры

int number = 0; // Номер сгенерированной карты
char mast = 0; // Масть сгенерированной карты
int pozition = 0; // Рандомная позиция в массивах, для выбора карты

int conCard[36]{ 2,2,2,2,3,3,3,3,4,4,4,4,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11 }; // Массив с колодой карт, по 4 для каждой масти
char conMast[36]{ 3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6 }; // Паралельно сложенный массив с мастями

int conCard1[36]{ 2,2,2,2,3,3,3,3,4,4,4,4,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11 }; // Колода для обновления)) Ничего пока лучше не придумал, ибо устал
char conMast1[36]{ 3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6,3,4,5,6 }; 

int gamerCard[8]{  }; // Массив для хранения номера карт игрока
char gamermas[8]{  }; // Массив для хранения мастей карт игрока
int CPUCard[8]{  }; // Массив для хранения номера карт компьютера
char CPUmas[8]{  }; // Массив для хранения мастей карт игрока

void TakeCard(int arr[], char brr[]) {
    repeat: // метка для переназначения позиции выбора карты, goto строка 37.
 
    pozition = rand() % 36;

    for (int i = 0; i < 36; i++) { // Берем значения из сгенерированной позиции и заменяем их нулями
        if (i == pozition) {
            if (conCard[i] == 0) {
                goto repeat; // Возвращаемся назад для переназначени позиции в массиве, метка строка 30.
                // Тут хотел сделать рекурсию, но она почему то всё равно выводила похожие карты или у меня уже глаза устали))
                // TakeCard(arr,brr); вместо goto хотел сделать так
            }
            else {
                number = conCard[i];
                mast = conMast[i];
                conCard[i] = 0;
                conMast[i] = 0;
                break; 
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i] == 0) { // Закидываем значения в первые нулевые ячейки и выходим из цикла
            arr[i] = number;
            brr[i] = mast;
            break;
        }
    }
}

void Null() { // Обнуляем массивы для новой раздачи
    for (int i = 0; i < 8; i++) {
        gamerCard[i] = 0;
        gamermas[i] = 0;
        CPUCard[i] = 0;
        CPUmas[i] = 0;
    }

    for (int i = 0; i < 36; i++) { // Обнавляем колоду, чтобы не заканчивалась, после нескольких раздач
        conCard[i] = conCard1[i];
        conMast[i] = conMast1[i];
    }
}

void Card(int arr[], char brr[],int n) { // функция для создания карт, n - определяет их количество
    for (int i = 0; i < n; i++) { // Карты создаются построчно, каждый цикл отвечает за свою строчку карты, количество итераций равно количеству карт
        cout << "#####\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с верхней мастью
        cout << "# "<< brr[i] << " #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с номером карты
        if (arr[i] == 10) {
            cout << "# " << arr[i] << "#\t";
        }
        else if (arr[i] == 11) {
            cout << "# T #\t";
        }
        else if (arr[i] == 2) {
            cout << "# B #\t";
        }
        else if (arr[i] == 3) {
            cout << "# D #\t";
        }
        else if (arr[i] == 4) {
            cout << "# K #\t";
        }
        else {
            cout << "# " << arr[i] << " #\t";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с нижней мастью
        cout << "# " << brr[i] << " #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#####\t";
    }
    cout << endl;
}

int Sum(int arr[], int n) { // Функция суммирования значений карт
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Значение каждой новой карты суммируются с предыдущими
    }
    return sum;
}

void CompMot() { // Автоматический ход компьютера
    
    while (Sum(CPUCard, b) < 14) {
        system("cls");
        cout << "Motion gamer: " << endl; // Отрисовка последнего хода игрока
        Card(gamerCard, gamermas, a);
        
        cout << "Summa card = " << sumGamer << endl << endl; // Вывод суммы карт игрока
      
        TakeCard(CPUCard, CPUmas); // генерируем первую карту для программы
        
        cout << "Motion programm: " << endl; // Ход компьютера
        Card(CPUCard, CPUmas, b - 1);
        
        cout << "Summa card = " << Sum(CPUCard, b) << endl;
        
        if (Sum(CPUCard, b) < 13) { // Если сумма первых двух карт меньше указанного, компьютер берет еще 1 карту
            b += 1;
        } 
        Sum(CPUCard, b);
    }
   
}

void Result() { // Функция подсчета счета и определения итогового результата игры
    if (sumProgramm > sumGamer && sumProgramm <= 21) { // Список всех возможных условий
        cout << "Vinner: Programma!" << endl;
        totalC += 1;
    }
    else if (sumProgramm < sumGamer && sumGamer <= 21) {
        cout << "Vinner: Gamer!" << endl;
        totalG += 1;
    }
    else if (sumProgramm == sumGamer) {
        cout << "Draw!" << endl;
    }
    else if (sumGamer <= 21 && sumProgramm > 21) {
        cout << "Vinner: Gamer!" << endl;
        totalG += 1;
    }
    else if (sumGamer > 21 && sumProgramm <= 21) {
        cout << "Vinner: Programm!" << endl;
        totalC += 1;
    }
    else if (sumGamer > 21 && sumProgramm > 21) {
        cout << "Draw!" << endl;
    }
    else if (sumGamer < 21 && sumProgramm < 21 && sumGamer < sumProgramm) {
        cout << "Vinner: Programm!" << endl;
        totalC += 1;
    }
    else if (sumGamer < 21 && sumProgramm < 21 && sumGamer > sumProgramm) {
        cout << "Vinner: Gamer!" << endl;
        totalG += 1;
    }
}

int main() {
    srand(time(NULL));
   
    while (game == 1) {
        system("cls");
        a = 2; // Возвращаем количество карт игроков к стартовому значению
        b = 2;
        int more = 0; // Переменная отвечает за взятие новой карты или передачи хода
        
        while (a != 0) { // Первые 2 карты генерируем по одной и закидываем в массивы игрока
            TakeCard(gamerCard, gamermas);
            a--;
        }
        a = 2;
        
        while (true) {

            Card(gamerCard, gamermas, a);
            cout << "Summa card = " << Sum(gamerCard, a) << endl;

            cout << "More - 1, Myself - 2" << endl; // предлагаем взять еще карту
            cin >> more;
            cout << endl << endl;
            if (more == 1) { // добавление еще одной карты в колоду
                a += 1;
                TakeCard(gamerCard, gamermas); // Генерируем еще карту и закидываем в массивы игрока
            }
            sumGamer = Sum(gamerCard, a);
            if (sumGamer >= 21 || more == 2) {
                break;
            }
            system("cls");
        }

        cout << "My motion" << endl;
        CompMot();
        cout << endl;

        sumProgramm = Sum(CPUCard, b);

        Result();

        cout << "Score: " << "Gamer: " << totalG << " Programma: " << totalC << endl << endl;
        cout << "More raund? 1 - yas, 0 - no ";
        cin >> game;
       
        Null();
    }
	return 0;
}