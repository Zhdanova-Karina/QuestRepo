#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>


#define MAX_DALMATIANS 4

class Dalmatian;
class Cage;
class Game;
class PlaceWithDalmatian;
class Level;

class Cage {
private:
    char *answerCode;
public:
    Cage() {
        answerCode = (char*)malloc(sizeof(char));
        strcpy(answerCode, "17F");
    }
    int getHintForCode();
    void CodeOfCage(Level& level, Game& player, int number);

    const char* getAnswerCode() const { return answerCode; }

};

class Game {
private:
    int countDalmatinsFound;
public:
    Game() : countDalmatinsFound(0) {}

    int getCountDalmatins() { return countDalmatinsFound; }
    void setCountDalmatins() { countDalmatinsFound++; }

    void printCompliments();
    int StartPlay();
    void PrintRepeatInput();
    void Rules();

};

class Dalmatian {
private:
    char *name;
public:
    Dalmatian() {}
    Dalmatian(const char* dogName) {
        name = (char*)malloc(sizeof(char));
        strcpy(name, dogName);
    }

    const char* getName() const { return name; }

};

class PlaceWithDalmatian {
private:
    char *name;
    bool existDalmatian;
public:
    Dalmatian dalmatian;

    PlaceWithDalmatian() {}
    // Конструктор
    PlaceWithDalmatian(const char* placeName, Dalmatian dalmatian, bool trueORfalse) : existDalmatian(trueORfalse) {
        name = (char*)malloc(sizeof(char));
        strcpy(name, placeName);
    }

    const char* getName() const { return name; }

    bool getExistDalmatian() { return existDalmatian; }
    void setExistDalmatian(bool trueORfalse) { existDalmatian = trueORfalse; }

};

class Level {
private:
    char *name;
    int countDalmatins, countPlace;

public:
    Dalmatian *dalmatians;
    
    PlaceWithDalmatian *place;
    Cage cage;
    Level() {}

    Level(bool isBedroom) {
        // Инициализация далматинцев
        dalmatians = (Dalmatian*)calloc(MAX_DALMATIANS, sizeof(Dalmatian));
        dalmatians[0] = Dalmatian("Патч");
        dalmatians[1] = Dalmatian("Пэдди");
        dalmatians[2] = Dalmatian("Понго");
        dalmatians[3] = Dalmatian("Ролли");

        // Инициализация места
        if (isBedroom) {
            name = (char*)malloc(sizeof(char));
            strcpy(name, "Спальня");
            countDalmatins = 3;
            place = (PlaceWithDalmatian*)calloc(5, sizeof(PlaceWithDalmatian));
            place[0] = PlaceWithDalmatian("\n 1. Шкаф", dalmatians[0], false);
            place[1] = PlaceWithDalmatian("\n 2. Тумба", dalmatians[0], false);
            place[2] = PlaceWithDalmatian("\n 3. Кровать", dalmatians[0], true);
            place[3] = PlaceWithDalmatian("\n 4. Коробка", dalmatians[1], true);
            place[4] = PlaceWithDalmatian("\n 5. Полка", dalmatians[2], true);
        }
        else {
            name = (char*)malloc(sizeof(char));
            strcpy(name, "Подвал");
            countDalmatins = 1;
            place = (PlaceWithDalmatian*)calloc(3, sizeof(PlaceWithDalmatian));
            place[0] = PlaceWithDalmatian("\n 1. Бочка", dalmatians[3], false);
            place[1] = PlaceWithDalmatian("\n 2. Клетка", dalmatians[3], true);
            place[2] = PlaceWithDalmatian("\n 3. Шкаф", dalmatians[3], false);
        }
    }
    int getCountDalmatins() { return countDalmatins; }
    const char* getName() const { return name; }

     int PrintLocationPlace(Level& level, int countPlace);
     void dalmatianFound(Level& level, Game& player, int number);
     void ViewingFoundDalmatians(Level& level, Game& player);
     int TransferLastLocation(Level& level, Game& player);
     void Level_1(Level& level, Game& player);
     void Level_2(Level& level, Game& player);

};

int main() {
    setlocale(LC_ALL, "RU");
    Game player;
    Dalmatian();
    player.Rules();
    int start;
    do {
        start = player.StartPlay();
        if (start == 1) {
            while (true) {
                Level level(true);
                printf("%s", level.getName());
                level.Level_1(level, player);
                player.printCompliments();
                int YesOrNo;
                do {
                    YesOrNo = level.TransferLastLocation(level, player);
                    if (YesOrNo == 0) {
                        level = Level(false);
                        Cage();
                        printf("%s", level.getName());
                        level.Level_2(level, player);
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

void Game::Rules() {
    printf("ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой.\n");
}

void Game::printCompliments() {
    printf("\nПоздравляем! Уровень пройден!");
}

int Game::StartPlay() {
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

void Game::PrintRepeatInput() {
    printf("Повторите ввод.\n");
}

int Level::PrintLocationPlace(Level& level, int countPlace) {
    int numberPlace;
    for (int i = 0; i < countPlace; i++) {
        printf("%s", level.place[i].getName());
    }
    printf("\n\nВведите пункт: ");
    scanf("%d", &numberPlace);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    return numberPlace;
}

void Level::ViewingFoundDalmatians(Level& level, Game& player) {
    printf("\nВы нашли %d/4 далматинцев:\n", player.getCountDalmatins());
    for (int i = 0; i < player.getCountDalmatins(); i++) {
        printf("%s\n", level.dalmatians[i].getName());
    }
}

void Level::dalmatianFound(Level& level, Game& player, int number) {
    if (level.place[number - 1].getExistDalmatian() == true) {
        player.setCountDalmatins();
        level.place[number - 1].setExistDalmatian(false);

        ViewingFoundDalmatians(level, player);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}
int Level::TransferLastLocation(Level& level, Game& player) {
    char symbol;
    if (player.getCountDalmatins() == level.getCountDalmatins() && player.getCountDalmatins() < MAX_DALMATIANS) {
        printf("\n\nНажмите *, чтобы перейти к следующей локации\n");
        symbol = getch();
    }
    if (symbol == '*') return 0;
    else return 1;
}
void Level::Level_1(Level& level, Game& player) {
    while (player.getCountDalmatins() < level.getCountDalmatins()) {
        int number;
        number = PrintLocationPlace(level, 5);

        switch (number) {
        case 1:
            dalmatianFound(level, player, number);
            break;
        case 2:
            dalmatianFound(level, player, number);
            break;
        case 3:
            dalmatianFound(level, player, number);
            break;
        case 4:
            dalmatianFound(level, player, number);
            break;
        case 5:
            dalmatianFound(level, player, number);
            break;
        default:
            player.PrintRepeatInput();
            break;
        }
    }
}
void Level::Level_2(Level& level, Game& player) {
    while (player.getCountDalmatins() < MAX_DALMATIANS) {
        int number;
        number = PrintLocationPlace(level, 3);

        switch (number) {
        case 1:
            dalmatianFound(level, player, number);
            break;
        case 2:
            printf("\nО нет! Клетка закрыта на замок! Вам нужно отгадать код!\n");
            cage.CodeOfCage(level, player, number);
            break;
        case 3:
            dalmatianFound(level, player, number);
            break;
        default:
            player.PrintRepeatInput();
            break;
        }
    }
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

void Cage::CodeOfCage(Level& level, Game& player, int number) {
    char input[4];
    if (getHintForCode() == 0) {
        do {
            printf("\nВведите код:\n");
            scanf("%3s", &input);
            while (getchar() != '\n');
            if (strcmp(input, level.cage.getAnswerCode()) == 0) {
                printf("Ура! Вы освободили далматинца!\n");
                level.dalmatianFound(level, player, number);
            }
            else  player.PrintRepeatInput();
        } while (strcmp(input, level.cage.getAnswerCode()) != 0);
    }
    else player.PrintRepeatInput();
}
