#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ссылка на задачу: https://www.codingame.com/ide/puzzle/the-descent

using namespace std;

int main()
{
    while (1) {
        int mountain = 0; // индекс горы, по которой необходимо стрелять
        int h = 0; // максимальная высота горы на текущий момент
        for (int i = 0; i < 8; i++) {
            int mountain_h; // значение высоты i-горы
            cin >> mountain_h; cin.ignore();
            if (mountain_h > h) // сравниваем максимальную высоту с высотой текущей горы
            {
                h = mountain_h; // если высота горы больше, записываем ее в переменную
                mountain = i; // и сохраняем индекс горы с максимальной высотой
            }
        }

        cout << mountain << endl; // индекс горы, по которой необходимо стрелять
    }
}