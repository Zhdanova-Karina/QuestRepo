#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define MAX_DALMATIANS 4
#define MAX_LOCATIONS 2

class Dalmatian;

class Dalmatian {
private:
    char name[30];
public:
    Dalmatian() {
    }

    Dalmatian(const char* dogName) {
        strcpy(name, dogName);
    }

    const char* getName() const { return name; }
};

class Location {
private:
    char name[30];
    int countDalmatins;

public:
    Dalmatian* dalmatians; // Динамический массив Dalmatian
    int countPlace;

    Location() : countDalmatins(MAX_DALMATIANS), dalmatians(nullptr) {
        // Инициализация памяти для массива далматинцев
        dalmatians = new Dalmatian[MAX_DALMATIANS];
        // Инициализация далматинцев
        dalmatians[0] = Dalmatian("Патч");
        dalmatians[1] = Dalmatian("Пэдди");
        dalmatians[2] = Dalmatian("Понго");
        dalmatians[3] = Dalmatian("Ролли");
    }

    ~Location() {
        // Освобождение динамической памяти
        delete[] dalmatians;
    }

    int getCountDalmatins() const { return countDalmatins; }
    const char* getName() const { return name; }
};

int main() {
    setlocale(LC_ALL, "RU");

    printf("\nДинамический массив объектов класса Location\n");
    /* Динамический массив объектов класса Location */
    Location* myLocation = new Location();

    // Вывод далматинцев
    for (int i = 0; i < myLocation->getCountDalmatins(); ++i) {
        printf("%s\n", myLocation->dalmatians[i].getName());
    }

    delete myLocation; // Удаление массива объектов Location

    printf("\nДинамический массив указателей на объекты класса Location\n");
    /* Динамический массив указателей на объекты класса Location */
    Location** myLocations = new Location * [MAX_DALMATIANS];
    
    // Создание новых объектов
    for (int i = 0; i < MAX_LOCATIONS; ++i) {
        myLocations[i] = new Location();
    }

    // Работы с динамическими объектами
    for (int i = 0; i < MAX_LOCATIONS; ++i) {
        printf("Location %d:\n", i + 1); // Печать номера локации
        for (int j = 0; j < myLocations[i]->getCountDalmatins(); ++j) {
            printf("%s\n", myLocations[i]->dalmatians[j].getName()); // Печать имен далматинцев
        }
    }

    // Удаление динамических объектов
    for (int i = 0; i < MAX_DALMATIANS; ++i) {
        delete myLocations[i]; // Удаление отдельных объектов
    }
    delete[] myLocations; // Удаление массива указателей

    return 0;
}
