// Quest.cpp : ?÷?÷ ýï?? ö?í?ÿ?à÷ ý??â?à? "main". ?í?ö? ?ï?à?ï?÷öô à ?ïâï??àçï?÷öô ç?ä?????à? äÿ??ÿï???.
//

#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define MAX_DALMATIANS 4
struct Dalmatian {
    char name[30];
    bool found = false;
};

struct Player {
    char name[30];
    int countDalmatinsFound;
};

struct PlaceWithDalmatian {
    char name[30];
    Dalmatian dalmatian;
    bool existDalmatian; 
};

struct Location {
    char name[30];
    int countDalmatins, countPlace;
    Dalmatian dalmatians[MAX_DALMATIANS];
    PlaceWithDalmatian place[10];
};

/*functions*/
void dalmatianFound(Player& player, Location& location, Location& printDogs, int number);
void getName(char* name);
int StartPlay();
int AreYouShureExit();
int PrintLocationPlace(Location& location);
void Level_1(Player& player, Location& location, Location& printDogs);
void Level_2(Player& player, Location& location, Location& printDogs, int countALLdalmatins);
void ViewingFoundDalmatians(Player& player, Location& printDogs);
int TransferLastLocation(Player& player, Location& location, Location& printDogs, int countALLdalmatins);
void CodeOfCage(Player& player, Location& location, Location& printDogs, int number);
int getHint();

int main()
{
    setlocale(LC_ALL, "RU");
    printf("ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой.\n");
    if (StartPlay() == 1) {
        Player player;
        getName(player.name);

        int countALLdalmatins = 4;

        player.countDalmatinsFound = 0;
        
        Location location[2];
        location[0].countDalmatins = 3;

        strcpy(location[0].name, "Спальня");
        location[0].countPlace = 5;

        strcpy(location[0].dalmatians[0].name, "Патч");
        location[0].dalmatians[0].found = false;
        strcpy(location[0].dalmatians[1].name, "Пэдди");
        location[0].dalmatians[1].found = false;
        strcpy(location[0].dalmatians[2].name, "Понго");
        location[0].dalmatians[2].found = false;
        strcpy(location[0].dalmatians[3].name, "Ролли");
        location[0].dalmatians[3].found = false;

        strcpy(location[0].place[0].name, "\n 1. Шкаф");
        location[0].place[0].existDalmatian = false;
        location[0].place[0].dalmatian = location[0].dalmatians[0];
        strcpy(location[0].place[1].name, "\n 2. Тумба");
        location[0].place[1].existDalmatian = false;
        location[0].place[1].dalmatian = location[0].dalmatians[1];
        strcpy(location[0].place[2].name, "\n 3. Кровать");
        location[0].place[2].existDalmatian = true;
        location[0].place[2].dalmatian = location[0].dalmatians[2];
        strcpy(location[0].place[3].name, "\n 4. Коробка");
        location[0].place[3].existDalmatian = true;
        location[0].place[3].dalmatian = location[0].dalmatians[2];
        strcpy(location[0].place[4].name, "\n 5. Полка");
        location[0].place[4].existDalmatian = true;
        location[0].place[4].dalmatian = location[0].dalmatians[2];

        Level_1(player, location[0],location[0]);
        
       

        int YesOrNo = TransferLastLocation(player, location[0], location[0], countALLdalmatins);
        if (YesOrNo == 0) {
            strcpy(location[1].name, "Подвал");
            location[1].countPlace = 3;


            strcpy(location[1].place[0].name, "\n 1. Бочка");
            location[1].place[0].existDalmatian = false;
            strcpy(location[1].place[1].name, "\n 2. Клетка");
            location[1].place[1].existDalmatian = true;
            location[1].place[1].dalmatian = location[0].dalmatians[3];
            strcpy(location[1].place[2].name, "\n 3. Шкаф");
            location[1].place[2].existDalmatian = false;

            Level_2(player, location[1], location[0], countALLdalmatins);
        }
        else if (YesOrNo == 1) AreYouShureExit();
        else printf("Повторите ввод.\n");
    printf("\nКонец игры\n");
    }
    else  if (StartPlay() == 0) AreYouShureExit();
    else printf("Повторите ввод.\n");
    return 0;
}

int PrintLocationPlace(Location& location) {
    int numberPlace;
    for (int i = 0; i < location.countPlace; i++) {
        printf("%s", location.place[i].name);
    }
    printf("\n\nВведите пункт: ");
    scanf("%d", &numberPlace);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    return numberPlace;
}
void Level_1(Player& player, Location& location, Location& printDogs) {
    while (player.countDalmatinsFound < location.countDalmatins) {

        int number;
        number = PrintLocationPlace(location);

        switch (number) {
        case 1:
            dalmatianFound(player, location, printDogs, number);
            break;
        case 2:
            dalmatianFound(player, location, printDogs, number);
            break;
        case 3:
            dalmatianFound(player, location, printDogs, number);
            break;
        case 4:
            dalmatianFound(player, location, printDogs, number);
            break;
        case 5:
            dalmatianFound(player, location, printDogs, number);
            break;
        default: 
            printf("Повторите ввод.\n");
            break;
        }
    }
}

void Level_2(Player& player, Location& location, Location& printDogs, int countALLdalmatins) {
    while (player.countDalmatinsFound < location.countDalmatins || player.countDalmatinsFound < countALLdalmatins) {
        int number;
        number = PrintLocationPlace(location);

        switch (number) {
        case 1:
            dalmatianFound(player, location, printDogs, number);
            break;
        case 2:
            printf("\nО нет! Клетка закрыта на замок! Вам нужно отгадать код!\n");
            CodeOfCage(player, location, printDogs, number);
            break;
        case 3:
            dalmatianFound(player, location, printDogs, number);
            break;
        default: 
            printf("Повторите ввод.\n");
            break;
        }
    }
}

int TransferLastLocation(Player& player, Location& location, Location& printDogs, int countALLdalmatins) {
    char symbol;
    if (player.countDalmatinsFound == location.countDalmatins && player.countDalmatinsFound < countALLdalmatins) {
        printf("\n\nНажмите *, чтобы перейти к следующей локации\nНажмите ESC, чтобы выйти из игры\n");
        do {
            scanf("%c", &symbol);
        } while (symbol != '*');
        while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    }
    if (symbol == '*') return 0;
    else if (symbol == 27) return 1;
    else return -1;
}

int getHint() {
    printf("\nНажмите *, чтобы получить подсказку\n");
    char symbol;
    do {
        scanf("%c", &symbol);
    } while (symbol != '*');
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    if (symbol == '*') {
        printf("\nКод состоит из трёх символов. Чтобы найти каждый символ вам нужно:\n1) перевести число 127 в двоичную, восьмеричную и шестнадцатиричную системы счисления;\n2) каждый последний символ будет являться частью кода\n\n");
        return 0;
    }
}

 void CodeOfCage(Player& player, Location& location, Location& printDogs, int number) {
    char code[4];
    if (getHint() == 0) {
        printf("\nВведите код:\n");
        scanf("%3s", code);
        while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'
    }
    if (strcmp(code, "17F") == 0) {
        printf("Ура! Вы освободили далматинца!\n");
        dalmatianFound(player, location, printDogs, number);
    }
    else printf("Код неверен. Повторите ввод.\n");
}

// Функция для обработки найденного далматинца
void dalmatianFound(Player& player, Location& location, Location& printDogs, int number) {
    if (location.place[number - 1].existDalmatian == true &&
        location.place[number - 1].dalmatian.found == false) {
        player.countDalmatinsFound++;
        location.place[number - 1].dalmatian.found = true; // Далматинец найден
        location.place[number - 1].existDalmatian = false;

        ViewingFoundDalmatians(player, printDogs);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}

// Функция для вывода найденных далматинцев
void ViewingFoundDalmatians(Player& player, Location& printDogs) {
    printf("\nВы нашли %d/4 далматинцев:\n", player.countDalmatinsFound);
    for (int i = 0; i < player.countDalmatinsFound; i++) {
        printf("%s\n", printDogs.dalmatians[i].name);
    }
}

void printCompliments() {
    printf("\nПоздравляем! Уровень пройден!");
}
void getName(char* name) {
    printf("\nВведите ваше имя: ");
    scanf("%s", name);
    while (getchar() != '\n'); // Очищаем буфер ввода от символов до '\n'

}

int StartPlay() {
    char symbol;
    printf("\nНажмите ENTER, чтобы начать игру\nESC, чтобы завершить игру\n");
    scanf("%c", &symbol);

    if (symbol == '\n') {
        return 1;
    }
    else if (symbol == 27) {
        return 0;
    }
    else {
        return -1;
    }
}

int AreYouShureExit() {
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

// ?ïä?öâ äÿ??ÿï???: CTRL+F5 à?à ???? "?÷?ïíâï" > "?ïä?öâ æ?? ?÷?ïíâà"
// ?÷?ïíâï äÿ??ÿï???: F5 à?à ???? "?÷?ïíâï" > "?ïä?ö÷à÷? ?÷?ïíâ?"
// ??ç?÷? ä? ?ï?ï?? ÿïæ?÷? 
//   1. ? ?â?? ?æ??ÿ?çï÷??ô ÿ?ð??à? ????? í?æïç?ô÷? ýï??? à ?äÿïç?ô÷? à?à.
//   2. ? ?â?? Team Explorer ????? ä?íâ???à÷?öô â öàö÷??? ?äÿïç???àô ç?ÿöàô?à.
//   3. ? ?â?? "????í??? íï????" ????? äÿ?ö?ï÷ÿàçï÷? ç???í??? íï???? öæ?ÿâà à íÿ??à? ö??æ???àô.
//   4. ? ?â?? "?äàö?â ?ðàæ?â" ????? äÿ?ö?ï÷ÿàçï÷? ?ðàæâà.
//   5. ??ö??í?çï÷????? ç?æ?ÿà÷? ä??â÷? ???? "?ÿ??â÷" > "??æïçà÷? ??ç?? ??????÷", ?÷?æ? ö??íï÷? ýï??? â?íï, à?à "?ÿ??â÷" > "??æïçà÷? ö???ö÷ç???à? ??????÷", ?÷?æ? í?æïçà÷? ç äÿ??â÷ ö???ö÷ç???à? ýï??? â?íï.
//   6. ?÷?æ? ö??çï ?÷âÿ?÷? ?÷?÷ äÿ??â÷ ä????, ç?æ?ÿà÷? ä??â÷? ???? "?ï??" > "?÷âÿ?÷?" > "?ÿ??â÷" à ç?æ?ÿà÷? SLN-ýï??.
