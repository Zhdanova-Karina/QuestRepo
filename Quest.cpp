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

class Cage {
private:
    char inputCode[4];
    char answerCode[4];
public:
    Cage() {
        strcpy(answerCode, "17F");
    }
    int getHintForCode();
};

class Player {
private:
    int countDalmatinsFound;
public:
    Player(): countDalmatinsFound(0) {}

    int getCountDalmatins() { return countDalmatinsFound; }
    void setCountDalmatins() { countDalmatinsFound++; }

    void printCompliments();
    int StartPlay();
    void PrintRepeatInput();
    void Rules();

    friend int PrintLocationPlace(Location& location, Player& player, PlaceWithDalmatian& place);
    friend void CodeOfCage(Location& location, Player& player, PlaceWithDalmatian& place, Dalmatian& dalmatians, int number);

};

class Dalmatian {
private:
    char name[30];
public:
    Dalmatian() {}
    Dalmatian(const char* dogName) {
        strcpy(name, dogName);
    }
    
    const char* getName() const { return name; }

    friend int PrintLocationPlace(Location& location, Player& player, PlaceWithDalmatian& place);

};

class PlaceWithDalmatian {
private:
    char name[30];
    bool existDalmatian;
public:
    Dalmatian dalmatian;

    PlaceWithDalmatian() {}
    // Конструктор
    PlaceWithDalmatian(const char* placeName, Dalmatian dalmatian, bool trueORfalse) : existDalmatian(trueORfalse) {
        strcpy(name, placeName);
    }

    const char* getName() const { return name; } 

    bool getExistDalmatian() {return existDalmatian;}
    void setExistDalmatian(bool trueORfalse) { existDalmatian = trueORfalse; }

    friend int PrintLocationPlace(Location& location, Player& player, PlaceWithDalmatian& place);
    friend void CodeOfCage(Location& location, Player& player, PlaceWithDalmatian& place, Dalmatian& dalmatians, int number);
};

class Location {
private:
    char name[30];
    int countDalmatins, countPlace;

public:
    Dalmatian dalmatians[MAX_DALMATIANS];
    PlaceWithDalmatian place[10];
    Player player;
    Location() {}

    Location(bool isBethroom) {
        // Инициализация далматинцев
        dalmatians[0] = Dalmatian("Патч");
        dalmatians[1] = Dalmatian("Пэдди");
        dalmatians[2] = Dalmatian("Понго");
        dalmatians[3] = Dalmatian("Ролли");

        // Инициализация места
        if (isBethroom) {
            strcpy(name, "Спальня");
            countDalmatins = 3;
            place[0] = PlaceWithDalmatian("\n 1. Шкаф", dalmatians[0], false);
            place[1] = PlaceWithDalmatian("\n 2. Тумба", dalmatians[0], false);
            place[2] = PlaceWithDalmatian("\n 3. Кровать", dalmatians[0], true);
            place[3] = PlaceWithDalmatian("\n 4. Коробка", dalmatians[1], true);
            place[4] = PlaceWithDalmatian("\n 5. Полка", dalmatians[2], true);
        }
        else {
            strcpy(name, "Подвал");
            countDalmatins = 1;
            place[0] = PlaceWithDalmatian("\n 1. Бочка", dalmatians[3], false);
            place[1] = PlaceWithDalmatian("\n 2. Клетка", dalmatians[3], true);
            place[2] = PlaceWithDalmatian("\n 3. Шкаф", dalmatians[3], false);
        }
    }
    int getCountDalmatins() { return countDalmatins; }

    friend int PrintLocationPlace(Location& location, int countPlace);
    friend void dalmatianFound(Location& location, int number);
    friend void CodeOfCage(Location& location, int countDalmatins, PlaceWithDalmatian& place, Dalmatian& dalmatians, int number);
    friend void ViewingFoundDalmatians(Location& location);
    friend int TransferLastLocation(Location& location, int countDalmatins);
    friend void Level_1(Location& location);
    friend void Level_2(Location& location);

};

int main() {
    setlocale(LC_ALL, "RU");
    Location location(true);
    Player player;
    player.Rules();
   // int start = player.StartPlay();
    Level_1(location);
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

int PrintLocationPlace(Location& location, int countPlace) {
    int numberPlace;
    for (int i = 0; i < countPlace; i++) {
        printf("%s", location.place[i].getName());
    }
    printf("\n\nВведите пункт: ");
    scanf("%d", &numberPlace);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    return numberPlace;
}

void ViewingFoundDalmatians(Location& location) {
    printf("\nВы нашли %d/4 далматинцев:\n", location.player.getCountDalmatins());
    for (int i = 0; i < location.player.getCountDalmatins(); i++) {
        printf("%s\n", location.dalmatians[i].getName());
    }
}

void dalmatianFound(Location& location, int number) {
    if (location.place[number - 1].getExistDalmatian() == true) {
        location.player.setCountDalmatins();
        location.place[number - 1].setExistDalmatian(false);

        ViewingFoundDalmatians(location);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}
void Level_1(Location& location) {
    while (location.player.getCountDalmatins() < location.getCountDalmatins()) {
        int number;
        number = PrintLocationPlace(location, 5);

        switch (number) {
        case 1:
            dalmatianFound(location, number);
            break;
        case 2:
            dalmatianFound(location, number);
            break;
        case 3:
            dalmatianFound(location, number);
            break;
        case 4:
            dalmatianFound(location, number);
            break;
        case 5:
            dalmatianFound(location, number);
            break;
        default:
            location.player.PrintRepeatInput();
            break;
        }
    }
}
