#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ссылка на задачу: https://www.codingame.com/ide/puzzle/power-of-thor-episode-1

using namespace std;

int main()
{
    int light_x; // позиция молнии по X
    int light_y; // позиция молнии по Y
    int current_tx; // позиция Тора по X
    int current_ty; // позиция Тора по Y
    cin >> light_x >> light_y >> current_tx >> current_ty; cin.ignore();

    while (1) {
        int remaining_turns; // число оставшихся ходов
        cin >> remaining_turns; cin.ignore();

        if (current_ty - light_y > 0) // проверяем позицию по Y
        {
            cout << 'N'; // двигаемся вверх, если позиция Тора ниже позиции молнии
            current_ty -= 1; // обновляем позицию Тора по Y
        }
        else if (current_ty - light_y < 0)
        {
            cout << 'S'; // двигаемся вниз, если позиция Тора выше позиции молнии
            current_ty += 1; // обновляем позицию Тора по Y
        } // если разница позиций равна нулю, значит перемещение по Y не требуется

        if (current_tx - light_x > 0) // проверяем позицию по X
        {
            cout << 'W'; // двигаемся влево, если позиция Тора больше позиции молнии
            current_tx -= 1; // обновляем позицию Тора по X
        }
        else if (current_tx - light_x < 0)
        {
            cout << 'E'; // двигаемся вправо, если позиция Тора меньше позиции молнии
            current_tx += 1; // обновляем позицию Тора по X
        }

        // Вывод программы должен иметь следующий вид: N NE E SE S SW W или NW
        cout << endl;
    }
}