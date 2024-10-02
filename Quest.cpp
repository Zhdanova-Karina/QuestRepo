// Quest.cpp : ?÷?÷ ýï?? ö?í?ÿ?à÷ ý??â?à? "main". ?í?ö? ?ï?à?ï?÷öô à ?ïâï??àçï?÷öô ç?ä?????à? äÿ??ÿï???.
//

#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>

#define MAX_DALMATIANS 5

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

struct Level {
    int levelNumb;
    bool levelPassed;
    Location location;
};
/*functions*/
void dalmatianFound(Player& player, Location& location, int number);
void getName(char* name);
int StartPlay();
int AreYouShureExit();
int PrintLocationPlace(Location& location);
void ViewingFoundDalmatians(Player& player, Location& location);

int main()
{
    setlocale(LC_ALL, "RU");
    printf("ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой.\n");
    if (StartPlay() == 1) {
        Player player;
        getName(player.name);

        player.countDalmatinsFound = 0;

        Location location;
        strcpy(location.name, "Спальня");
        location.countDalmatins = 3;
        location.countPlace = 5;

        strcpy(location.dalmatians[0].name, "Патч");
        location.dalmatians[0].found = false;
        strcpy(location.dalmatians[1].name, "Пэдди");
        location.dalmatians[1].found = false;
        strcpy(location.dalmatians[2].name, "Понго");
        location.dalmatians[2].found = false;

        strcpy(location.place[0].name, "\n 1. Шкаф");
        location.place[0].existDalmatian = false;
        location.place[0].dalmatian = location.dalmatians[0];
        strcpy(location.place[1].name, "\n 2. Тумба");
        location.place[1].existDalmatian = false;
        location.place[1].dalmatian = location.dalmatians[1];
        strcpy(location.place[2].name, "\n 3. Кровать");
        location.place[2].existDalmatian = true;
        location.place[2].dalmatian = location.dalmatians[2];
        strcpy(location.place[3].name, "\n 4. Коробка");
        location.place[3].existDalmatian = true;
        location.place[3].dalmatian = location.dalmatians[2];
        strcpy(location.place[4].name, "\n 5. Полка");
        location.place[4].existDalmatian = true;
        location.place[4].dalmatian = location.dalmatians[2];

        Level level[3];

        while (player.countDalmatinsFound < location.countDalmatins) {

            int number;
            number = PrintLocationPlace(location);

            switch (number) {
            case 1:
                dalmatianFound(player, location, number);
                break;
            case 2:
                dalmatianFound(player, location, number);
                break;
            case 3:
                dalmatianFound(player, location, number);
                break;
            case 4:
                dalmatianFound(player, location, number);
                break;
            case 5:
                dalmatianFound(player, location, number);
                break;
            }
        }
    }
    else  if (StartPlay() == 1) AreYouShureExit();
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
    return numberPlace;
}

void dalmatianFound(Player& player, Location& location, int number) {
    if (location.place[number - 1].existDalmatian == true &&
        location.place[number - 1].dalmatian.found == false) {
        player.countDalmatinsFound++;
        location.place[number - 1].dalmatian.found = true; //Далматинец найден
        location.place[number - 1].existDalmatian = false;
        ViewingFoundDalmatians(player, location);
    }
    else {
        printf("Увы, здесь никого нет\n");
    }
}

void ViewingFoundDalmatians(Player& player, Location& location) {
    printf("\nВы нашли %d/3 далматинцев:\n", player.countDalmatinsFound);
    for (int i = 0; i < player.countDalmatinsFound; i++) {
        printf("%s\n", &location.dalmatians[i].name);
    }
}

void getName(char* name) {
    printf("\nВведите ваше имя: ");
    scanf("%s", name);
}

int StartPlay() {
    char symbol;
    printf("\nНажмите ENTER, чтобы начать игру\nESC, чтобы завершить игру\n");
    scanf("%c", &symbol);
    if (symbol == '\n') {
        return 1;
    }
    else if (symbol == '\n') {
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
