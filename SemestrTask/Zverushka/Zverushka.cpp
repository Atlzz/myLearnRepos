#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cmath>


class Pet {
private:
    int hunger;
    int happiness;

public:
    int diff;
    Pet() : hunger(100), happiness(100) {}

    void feed() {
        system("cls");
        hunger += 20;
        if (hunger > 100) hunger = 100;
        std::cout << "Вы накормили зверушку. Радость: " << happiness << ", Сытость: " << hunger << std::endl;
    }

    void play() {
        system("cls");
        happiness += 20;
        hunger -= 10;
        if (happiness > 100) happiness = 100;
        if (hunger < 0) hunger = 0;
        std::cout << "Вы поиграли со зверушкой. Радость: " << happiness << ", Сытость: " << hunger << std::endl;
    }

    void live() {
        while (hunger > 0 && happiness > 0) {
            if (_kbhit()) {
                char ch = _getch();
                switch (ch)
                {
                case('f'):
                    feed();
                    break;
                case('F'):
                    feed();
                    break;
                case('p'):
                    play();
                    break;
                case('P'):
                    play();
                    break;
                }
            }
            else {
                std::this_thread::sleep_for(std::chrono::seconds(diff));
                hunger -= 10;
                happiness -= 10;
                if (hunger < 0) hunger = 0;
                if (happiness < 0) happiness = 0;
                system("cls");
                std::cout << "Зверушка грустнее и голоднее. Радость: " << happiness << ", Сытость: " << hunger << std::endl;

            }
        }
        std::cout << "Игра закончена." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
};


int main() {

    setlocale(LC_ALL, "Russian");
    int diff;
repeatDiff:

    std::cout << "Введите сложность от 1 до 10: " << std::endl;
    std::cin >> diff;
    if (diff < 1 || diff>10) {
        std::cout << "Неверная сложность, повторите " << std::endl;
        goto repeatDiff;
    }
    std::cout << "Игра началась!" << std::endl;
    Pet pet;
    pet.diff = diff;

    pet.live();

}