// Quest.cpp : ?�?� ��?? �?�?�?�� �??�?�? "main". ?�?�? ?�?�?�?��� � ?���??���?��� �?�?????�? ��??��???.
//

#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAX_DALMATIANS 5

struct Dalmatian {
    char name[30];
    bool found;
};

struct Player {
    char name[30];
    int countDalmatinsFound;
};

struct PlaceWithDalmatian {
    char name[30];
    Dalmatian dalmatian;
    bool found = false; /*�?�?�?� ��??���??? ?? ?�?�??*/
    bool placeActive = true; /*??��? �����?? �?� �?����*/
};

struct Location {
    char name[30];
    int countDalmatins;
    Dalmatian dalmatians[MAX_DALMATIANS];
    PlaceWithDalmatian place;
};

struct Level {
    int levelNumb;
    bool levelPassed;
    Location location;
};
void dalmatianFound(Player& player, PlaceWithDalmatian& place);

void getName(char* name);

int StartPlay();

int AreYouShureExit();

int main()
{
    printf("??????? ????\n?�?��?�?: ??��� ��??���???�\n??????��?: 3\n???�??���? �?�?�?�: 1\n\n?��� ?���?� - ?�?�� ��?? �??�?????? ��??���???� ?� ?���???? ??��?��? �? �?�???�� � �??�?????? ?�?�??.\n\n??��? �??�??���? � ?�� ����?????�?! ? ?�?? ?�?���?��???? �?�? �? � ��� �??�?�� ?�������?�? � �?????? � ?�??���?????? �?�?�?����?, ?�?�? ������ ?���? �?����?? ��???? ? ��??���???�, �?�?�?? �??�� �??���?� ??��?��� ?�????�!????�? �??��? �? �????�? ��??�???�? ��? ��?�������� � �?�??�? ?��?�??? �????.\n\n???????\n? ��?�?? ??��?�� ????� �?�? ??��???�? ��??���???�. ?��� ???? - ?�?�� ��??, ?�?�? �?�??�� � �??�?????? ?���?.");
    if (StartPlay() == 1) {
        do {
            Player player;
            getName(player.name); // ?????�?? �?� �?�?��

            player.countDalmatinsFound = 0;
            // ?��??� �?�?��?�?�?�� ??��?�� � ��??���??�
            Location location;
            strcpy(location.name, "?���");
            location.countDalmatins = 1; // ?�??? � ??�??���? ��??���???� � ??��?��
            strcpy(location.dalmatians[0].name, "?��?"); // ??�?��?�?�?�� ��??���??�
            location.dalmatians[0].found = false;

            strcpy(location.place.name, "??�?��� �???����");
            location.place.dalmatian = location.dalmatians[0]; // ?��������?? ��??���??� ??��?�??????�?

            // ?��??� �?���� ��??���??�
            dalmatianFound(player, location.place);

            // ??�?� �??�??���� ?�?�????? ��??���???� �?�?��
            std::cout << "?�??? �??�??���? ?�?�????? ��??���???�: " << player.countDalmatinsFound << std::endl;

        } while (AreYouShureExit() == 0);
   }
    else  if (StartPlay() == 1) AreYouShureExit();
    else printf("��������� ����.\n");


  
    return 0;
}

void dalmatianFound(Player& player, PlaceWithDalmatian& place) {
    if (!place.dalmatian.found) {
        player.countDalmatinsFound++; // ?�??�???�? �??�??���� ?�?�????? ��??���???�
        place.dalmatian.found = true; // ?�??�???�? ����?�� ?�?�?????? ��??���??�
    }
}

void getName(char* name) {
    printf("\n?�?���? ���? �?�: ");
    scanf("%s", name);
}

int StartPlay() {
    char symbol;
    printf("?�??�? , ��?�� ?����� �?��, ��?�� ?��?��� �?��");
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
    printf("�� �������, ��� ������ ����� �� ����?");
    scanf("%3s", YesOrNo);
    if (strcmp(YesOrNo, "��") || strcmp(YesOrNo, "��")) {
        return 1;
    }
    else if (strcmp(YesOrNo, "���") || strcmp(YesOrNo, "���")) {
        return 0;
    }
    else {
        return -1;
    }
}


// ?��?�� ��??��???: CTRL+F5 �?� ???? "?�?����" > "?��?�� �?? ?�?����"
// ?�?���� ��??��???: F5 �?� ???? "?�?����" > "?��?����? ?�?���?"
// ??�?�? �? ?�?�?? ���?�? 
//   1. ? ?�?? ?�??�?���??� �?�??�? ????? �?���?��? ��??? � ?����?��? �?�.
//   2. ? ?�?? Team Explorer ????? �?��???��?�� � ����??? ?����???�� �?����?�.
//   3. ? ?�?? "????�??? ��????" ????? ��?�?�������? �???�??? ��???? ��?��� � ��??�? �??�???��.
//   4. ? ?�?? "?���?� ?���?�" ????? ��?�?�������? ?�����.
//   5. ??�??�?���????? �?�?���? �??��? ???? "?�??��" > "??�����? ??�?? ??????�", ?�?�? �??���? ��??? �?��, �?� "?�??��" > "??�����? �???���???�? ??????�", ?�?�? �?�����? � ��??�� �???���???�? ��??? �?��.
//   6. ?�?�? �??�� ?���?�? ?�?� ��??�� �????, �?�?���? �??��? ???? "?�??" > "?���?�?" > "?�??��" � �?�?���? SLN-��??.
