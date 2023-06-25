#include <iostream>
#include "curses.h"
#include "panel.h"

int main() {
    // Инициализация библиотеки curses
    initscr();

    // Печать текста в окне
    printw("Привет, мир!");

    // Обновление окна
    refresh();

    // Ожидание пользовательского ввода
    getch();

    // Завершение работы с библиотекой curses
    endwin();




    return 0;
}
