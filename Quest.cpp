#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define MAX_DALMATIANS 4

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

class Player {
public:
    char name[30];
    int countDalmatinsFound;
public:
    Player() : countDalmatinsFound(0) {
        getName(name);
    }
    void getName(char* name);
    void printCompliments();
    int StartPlay();
    int AreYouShureExit();
};

class PlaceWithDalmatian {
public:
    char name[30];
    Dalmatian dalmatian;
    bool existDalmatian;
};

class Location {
public:
    char name[30];
    int countDalmatins, countPlace;
    Dalmatian dalmatians[MAX_DALMATIANS];
    PlaceWithDalmatian place[10];
    Player player;
    Location() : countDalmatins(3), countPlace(5), name("Спальня") {

        // Инициализация далматинцев
        strcpy(dalmatians[0].name, "Патч");
        dalmatians[0].found = false;
        strcpy(dalmatians[1].name, "Пэдди");
        dalmatians[1].found = false;
        strcpy(dalmatians[2].name, "Понго");
        dalmatians[2].found = false;
        strcpy(dalmatians[3].name, "Ролли");
        dalmatians[3].found = false;

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
    Location() : name("Подвал") {
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
    int PrintLocationPlace(Location& location);
    void dalmatianFound(Location& location, int number);
};

class Cage {
private:
    char inputCode[4];
    char answerCode[4];
public:
    Cage() {
        strcpy(answerCode, "17F");
    }
    int getHintForCode();

    void CodeOfCage(Cage& cage);
};

void Player :: printCompliments() {
    printf("\nПоздравляем! Уровень пройден!");
}
void Player :: getName(char* name) {
    printf("\nВведите ваше имя: ");
    scanf("%19s", name);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'

}

int Player :: StartPlay() {
    char symbol;
    printf("\nНажмите *, чтобы начать игру\nESC, чтобы завершить игру\n");
    scanf(" %1c", &symbol);
    while (getchar() != '\n');
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

int Player :: AreYouShureExit() {
    char YesOrNo[3];
    printf("Вы уверены, что хотите выйти из игры?");
    scanf("%3s", YesOrNo);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    if (strcmp(YesOrNo, "да") || strcmp(YesOrNo, "Да")) {
        return 1;
    }
    else if (strcmp(YesOrNo, "нет") || strcmp(YesOrNo, "Нет")) {
        return 0;
    }
    else {
        return -1;
    }
}

int Location :: PrintLocationPlace(Location& location) {
    int numberPlace;
    for (int i = 0; i < location.countPlace; i++) {
        printf("%s", location.place[i].name);
    }
    printf("\n\nВведите пункт: ");
    scanf("%d", &numberPlace);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    return numberPlace;
}
int Cage :: getHintForCode() {
    printf("\nНажмите *, чтобы получить подсказку\n");
    char symbol;
    do {
        scanf(" %1c", &symbol);
    } while (symbol != '*');
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    if (symbol == '*') {
        printf("\nКод состоит из трёх символов. Чтобы найти каждый символ вам нужно:\n1) перевести число 127 в двоичную, восьмеричную и шестнадцатиричную системы счисления;\n2) каждый последний символ будет являться частью кода\n\n");
        return 0;
    }
}

void Cage :: CodeOfCage(Cage& cage) {
    if (getHintForCode() == 0) {
        printf("\nВведите код:\n");
        scanf("%3s", cage.inputCode);
        while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'

        if (strcmp(cage.inputCode, cage.answerCode) == 0) {
            printf("Ура! Вы освободили далматинца!\n");
           //dalmatianFound(player, location, printDogs, number);
        }
    }
    //else PrintRepeatInput();
}
void Location :: dalmatianFound(Location& location, int number) {
    if (location.place[number - 1].existDalmatian == true &&
        location.place[number - 1].dalmatian.found == false) {
        location.player.countDalmatinsFound++;
        location.place[number - 1].dalmatian.found = true; //Далматинец найден
        location.place[number - 1].existDalmatian = false;

       // ViewingFoundDalmatians(player, printDogs);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}


// ?ïä?öâ äÿ??ÿï???: CTRL+F5 à?à ???? "?÷?ïíâï" > "?ïä?öâ æ?? ?÷?ïíâà"
// ?÷?ïíâï äÿ??ÿï???: F5 à?à ???? "?÷?ïíâï" > "?ïä?ö÷à÷? ?÷?ïíâ?"
// ??ç?÷? ä? ?ï?ï?? ÿïæ?÷? 
//   1. ? ?â?? ?æ??ÿ?çï÷??ô ÿ?ð??à? ????? í?æïç?ô÷? ýï??? à ?äÿïç?ô÷? à?à.
//   2. ? ?â?? Team Explorer ????? ä?íâ???à÷?öô â öàö÷??? ?äÿïç???àô ç?ÿöàô?à.
//   3. ? ?â?? "????í??? íï????" ????? äÿ?ö?ï÷ÿàçï÷? ç???í??? íï???? öæ?ÿâà à íÿ??à? ö??æ???àô.
//   4. ? ?â?? "?äàö?â ?ðàæ?â" ????? äÿ?ö?ï÷ÿàçï÷? ?ðàæâà.
//   5. ??ö??í?çï÷????? ç?æ?ÿà÷? ä??â÷? ???? "?ÿ??â÷" > "??æïçà÷? ??ç?? ??????÷", ?÷?æ? ö??íï÷? ýï??? â?íï, à?à "?ÿ??â÷" > "??æïçà÷? ö???ö÷ç???à? ??????÷", ?÷?æ? í?æïçà÷? ç äÿ??â÷ ö???ö÷ç???à? ýï??? â?íï.
//   6. ?÷?æ? ö??çï ?÷âÿ?÷? ?÷?÷ äÿ??â÷ ä????, ç?æ?ÿà÷? ä??â÷? ???? "?ï??" > "?÷âÿ?÷?" > "?ÿ??â÷" à ç?æ?ÿà÷? SLN-ýï??.
