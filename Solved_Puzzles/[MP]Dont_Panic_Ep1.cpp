#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ссылка на задачу: https://www.codingame.com/ide/puzzle/don't-panic-episode-1

using namespace std;

int main()
{
    int nb_floors; // число этажей
    int width; // ширина участка, перемещаться можно в пределах 0 и (width - 1)
    int nb_rounds; // максимальное число ходов
    int exit_floor; // этаж, на котором расположен выход
    int exit_pos; // позиция выхода на этом этаже (задается в пределах width)
    int nb_total_clones; // число доступных клонов
    int nb_additional_elevators; // в этом задании разрешается игнорировать (всегда равно 0), т.е. дополнительных лифтов нет
    int nb_elevators; // число лифтов
	
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();
	
    vector<int> elevators; // вектор для записи координат лифтов на этажах в формате (позиция = elevators[этаж])
	elevators.reserve(nb_elevators + 1); // выделяем достаточное количество памяти для записи (nb_elevators + 1) чисел в векторе
	// технически, выход также является лифтом, завершающим выполнение задания, поэтому выделяем на 1 место для чисел больше
	
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // этаж, на котором расположен следующий лифт
        int elevator_pos; // позиция лифта на этом этаже
        cin >> elevator_floor >> elevator_pos; cin.ignore();
        elevators[elevator_floor] = elevator_pos; // записываем позицию лифта в вектор по нужному индексу (этажу)
    }
	elevators[exit_floor] = exit_pos; // записываем позицию выхода в вектор. При этом если бы на этом этаже также был бы лифт, мы бы его игнорировали и шли именно к выходу, т.к. выход для нас важнее

    while (1) {
        int clone_floor; // этаж ведущего клона
        int clone_pos; // позиция ведущего клона на этом этаже
        string direction; // направление ведущего клона, может принимать значения: LEFT or RIGHT
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();
        if (clone_pos > elevators[clone_floor] && direction == "RIGHT") // проверяем, что клон продолжает двигаться вправо при условии, что его позиция уже правее лифта на этом этаже
        {
			cout << "BLOCK" << endl; // останавливаем ведущего клона, чтобы он поворачивал последующих клонов в другую сторону
            continue;
        }
        if (clone_pos < elevators[clone_floor] && direction == "LEFT") // проверяем, что клон продолжает двигаться влево при условии, что его позиция уже левее лифта на этом этаже
        {
            cout << "BLOCK" << endl; // останавливаем ведущего клона, чтобы он поворачивал последующих клонов в другую сторону
            continue;
        }
        cout << "WAIT" << endl; // если ведущий клон движется в верном направлении, ожидаем
		// после того, как ведущий клон выполняет команду BLOCK, ведущим клоном становится следующий за ним
    }
}