#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define MAX_DALMATIANS 4

class Dalmatian;
class Cage;
class Player;
class PlaceWithDalmatian;
class Location;

class Dalmatian {
public:
    char name[30];
    bool found;
    int ALL;
public:
    Dalmatian() {
        ALL = 4;
        found = false;
    }
};
class Cage {
public:
    char inputCode[4];
    char answerCode[4];
public:
    Cage() {
        strcpy(answerCode, "17F");
    }
    int getHintForCode();
};
class Player {
public:
    char name[30];
    int countDalmatinsFound;
public:
    Player(): countDalmatinsFound(0){}
    void printCompliments();
    int StartPlay();
    void PrintRepeatInput();
    void Rules();
};

class PlaceWithDalmatian {
public:
    char name[30];
    Dalmatian dalmatian;
    bool existDalmatian;
public:
};

class Location {
public:
    char name[30];
    int countDalmatins, countPlace;
    Dalmatian dalmatians[MAX_DALMATIANS];
    PlaceWithDalmatian place[10];
    Cage code;
    Location() {

    }
    Location(bool isBethroom) {
        // Инициализация далматинцев
        strcpy(dalmatians[0].name, "Патч");
        dalmatians[0].found = false;
        strcpy(dalmatians[1].name, "Пэдди");
        dalmatians[1].found = false;
        strcpy(dalmatians[2].name, "Понго");
        dalmatians[2].found = false;
        strcpy(dalmatians[3].name, "Ролли");
        dalmatians[3].found = false;
        if (isBethroom)
        {
            strcpy(name, "Спальня");
            countDalmatins = 3;
            countPlace = 5;
            // Инициализация мест
            strcpy(place[0].name, "\n 1. Шкаф");
            place[0].existDalmatian = false;
            place[0].dalmatian = dalmatians[0];

            strcpy(place[1].name, "\n 2. Тумба");
            place[1].existDalmatian = false;
            place[1].dalmatian = dalmatians[1];

            strcpy(place[2].name, "\n 3. Кровать");
            place[2].existDalmatian = true;
            place[2].dalmatian = dalmatians[2];

            strcpy(place[3].name, "\n 4. Коробка");
            place[3].existDalmatian = true;
            place[3].dalmatian = dalmatians[2];

            strcpy(place[4].name, "\n 5. Полка");
            place[4].existDalmatian = true;
            place[4].dalmatian = dalmatians[2];
        }
        else {
            strcpy(name, "Подвал");
            // Инициализация мест
            countPlace = 3;
            strcpy(place[0].name, "\n 1. Бочка");
            place[0].existDalmatian = false;
            strcpy(place[1].name, "\n 2. Клетка");
            place[1].existDalmatian = true;
            place[1].dalmatian = dalmatians[3];
            strcpy(place[2].name, "\n 3. Шкаф");
            place[2].existDalmatian = false;
        }
    }
    int PrintLocationPlace(Location& location, Player& player);
    void dalmatianFound(Location& location, Player& player, int number);
    void CodeOfCage(Location& location, Player& player, int number);
    void ViewingFoundDalmatians(Location& location, Player& player);
    int TransferLastLocation(Location& location, Player& player);
    void Level_1(Location& location, Player& player);
    void Level_2(Location& location, Player& player);
};

int main()
{
    setlocale(LC_ALL, "RU");
    Player player;
    Cage cage;
    Location location;
    player.Rules();
    int start;
    do {
        start = player.StartPlay();
        if (start == 1) {
            while (true) {
                location = Location(true);
                char nameLocation[30];
                strcpy(nameLocation, location.name);
                printf("%s", nameLocation);
                location.Level_1(location, player);
                player.printCompliments();
                int YesOrNo;
                do {
                    YesOrNo = location.TransferLastLocation(location, player);
                    if (YesOrNo == 0) {
                        cage = Cage();
                        location = Location(false);
                        strcpy(nameLocation, location.name);
                        printf("%s", nameLocation);
                        location.Level_2(location, player);
                    }
                    else player.PrintRepeatInput();
                } while (YesOrNo != 0);
                break;
            }
        }
        else  if (start == 0)break;
        else player.PrintRepeatInput();
    } while (start < 0);
    printf("\nКонец игры\n");
    return 0;
}

void Player::Rules() {
    printf("ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой.\n");
}

void Player::printCompliments() {
    printf("\nПоздравляем! Уровень пройден!");
}

int Player::StartPlay() {
    char symbol;
    printf("\nНажмите *, чтобы начать игру\nESC, чтобы завершить игру\n");
    symbol = getch();
    if (symbol == '*') {
        return 1;
    }
    else if (symbol == 27) {
        return 0;
    }
    else {
        return -1;
    }
}

void Player::PrintRepeatInput() {
    printf("Повторите ввод.\n");
}

int Location::PrintLocationPlace(Location& location, Player& player) {
    int numberPlace;
    for (int i = 0; i < countPlace; i++) {
        printf("%s", place[i].name);
    }
    printf("\n\nВведите пункт: ");
    scanf("%d", &numberPlace);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    return numberPlace;
}
int Cage::getHintForCode() {
    printf("\nНажмите *, чтобы получить подсказку\n");
    char symbol;
    do {
        scanf(" %1c", &symbol);
    } while (symbol != '*');
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    if (symbol == '*') {
        printf("\nКод состоит из трёх символов. Чтобы найти каждый символ вам нужно:\n1) перевести число 127 в двоичную, восьмеричную и шестнадцатиричную системы счисления;\n2) каждый последний символ будет являться частью кода\nВсе буквы должны быть заглавными!\n\n");
        return 0;
    }
}

void Location::CodeOfCage(Location& location, Player& player, int number) {
    if (code.getHintForCode() == 0) {
        do {
            printf("\nВведите код:\n");
            scanf("%3s", code.inputCode);
            while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'

            if (strcmp(code.inputCode, code.answerCode) == 0) {
                printf("Ура! Вы освободили далматинца!\n");
                dalmatianFound(location, player, number);
            }
            else  player.PrintRepeatInput();
        } while (strcmp(code.inputCode, code.answerCode) != 0);
    }
    else player.PrintRepeatInput();
}
void Location::dalmatianFound(Location& location, Player& player, int number) {
    if (place[number - 1].existDalmatian == true &&
        place[number - 1].dalmatian.found == false) {
        player.countDalmatinsFound++;
        place[number - 1].dalmatian.found = true; //Далматинец найден
        place[number - 1].existDalmatian = false;

        ViewingFoundDalmatians(location, player);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}

void Location::ViewingFoundDalmatians(Location& location, Player& player) {
    printf("\nВы нашли %d/4 далматинцев:\n", player.countDalmatinsFound);
    for (int i = 0; i < player.countDalmatinsFound; i++) {
        printf("%s\n", dalmatians[i].name);
    }
}
int Location::TransferLastLocation(Location& location, Player& player) {
    char symbol;
    if (player.countDalmatinsFound == countDalmatins && player.countDalmatinsFound < dalmatians->ALL) {
        printf("\n\nНажмите *, чтобы перейти к следующей локации\n");
        symbol = getch();
    }
    if (symbol == '*') return 0;
    else return 1;
}

void Location::Level_1(Location& location, Player& player) {
    while (player.countDalmatinsFound < location.countDalmatins) {

        int number;
        number = location.PrintLocationPlace(location, player);

        switch (number) {
        case 1:
            location.dalmatianFound(location, player, number);
            break;
        case 2:
            location.dalmatianFound(location, player, number);
            break;
        case 3:
            location.dalmatianFound(location, player, number);
            break;
        case 4:
            location.dalmatianFound(location, player, number);
            break;
        case 5:
            location.dalmatianFound(location, player, number);
            break;
        default:
            player.PrintRepeatInput();
            break;
        }
    }
}
void Location::Level_2(Location& location, Player& player) {
    while (player.countDalmatinsFound < location.dalmatians->ALL) {
        int number;
        number = location.PrintLocationPlace(location, player);

        switch (number) {
        case 1:
            location.dalmatianFound(location, player, number);
            break;
        case 2:
            printf("\nО нет! Клетка закрыта на замок! Вам нужно отгадать код!\n");
            CodeOfCage(location, player, number);
            break;
        case 3:
            location.dalmatianFound(location, player, number);
            break;
        default:
            player.PrintRepeatInput();
            break;
        }
    }
}
