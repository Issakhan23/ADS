#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {1, 3, 5, 5, 5, 7, 9};
    int target = 5;

    auto lower = lower_bound(v.begin(), v.end(), target);
    auto upper = upper_bound(v.begin(), v.end(), target);

    // Способ 1: Если нужно вывести только САМИ ЗНАЧЕНИЯ (через звездочку '*')
    cout << "Значение lower_bound: " << *lower << "\n"; // Выведет 5
    cout << "Значение upper_bound: " << *upper << "\n"; // Выведет 7

    // Способ 2: Если нужны ИНДЕКСЫ, просто вычитаем v.begin()
    int lower_index = lower - v.begin();
    int upper_index = upper - v.begin();

    cout << "Индекс lower_bound: " << lower_index << "\n"; // Выведет 2
    cout << "Индекс upper_bound: " << upper_index << "\n"; // Выведет 5

    return 0;
}
//lower_bound находит нижнюю границу, т.е первое появление элемента, которого ищешь
//upper_bound находит верхнюю границу - последнее появление элемента