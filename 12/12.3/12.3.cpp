/*Создайте в своей программе функцию float travelTime(float distance, float speed).
Она будет находить время в пути и при этом использовать assert, чтобы отбросить нулевую и отрицательную скорость. 
Вызовите эту функцию в main. Убедитесь, что падение происходит за счёт assert. Не забудьте подключить заголовочный файл cassert.*/

#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
    assert(speed > 0);
    float time;
    time = distance / speed;
    return time;
}

int main()
{
    float distance, speed;

    std::cin >> distance >> speed;
    float time;
    time = travelTime(distance, speed);
    std::cout << time << "\n";
}

