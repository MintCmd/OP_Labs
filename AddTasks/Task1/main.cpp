/*
Задача №1 «Грузоперевозки»

Судоходная компания предлагает два вида транспорта для перевозки сыпучих грузов. 
Грузовик первого типа может перевезти Q1 тонн груза за одну поездку. 
Разовая поездка стоит P1, и цена не зависит от уровня загрузки транспортного средства. 
Для грузовика второго типа эти значения равны Q2 и P2 соответственно.
Найдите минимальную стоимость перевозки A тонн груза.

Формат ввода
Входные данные содержат пять натуральных чисел, не превышающих тысячи: Q1, P1, Q2, P2, A. Числа разделены пробелами.

Формат вывода
Выведите одно число: минимально возможную цену.

Пример

Вход
3 20 20 100 21
Выход
120

*/

#include <iostream>

int main() {
    int Q1, P1, Q2, P2, A;
    int cost = 0;
    int min_cost = INT_MAX;
    int trips1, trips2;
    std::cout << "Input values: ";
    std::cin >> Q1;
    std::cin >> P1;
    std::cin >> Q2;
    std::cin >> P2;
    std::cin >> A;
    if(0<Q1 && Q1<=1000 && 0<P1 && P1<=1000 && 0<Q2 && Q2<=1000 && 0<P2 && P2<=1000 && 0<=A && A<=1000) {
        for(trips1=0; trips1*Q1<=A;++trips1) {
            int remaining = A - trips1*Q1;
            trips2 = 1 + (remaining-1)/Q2;
            cost = trips1*P1 + trips2*P2;
            if(min_cost > cost) {
                min_cost = cost;
            }
        }
    } 
    else {
        std::cout << "Some numbers are not natural" << std::endl;
        return -1;
    }
    
    std::cout << "Minimal cost: " << min_cost << std::endl;

    return 0;
}
