// Skillbox 11.6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

std::string encrypt_caesar(std::string str, int num)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] += num;
            while (str[i] < 'a' || str[i] > 'z')
            {
                if (str[i] > 'z')
                {
                    str[i] -= 26;
                }
                else
                {
                    str[i] += 26;
                }
            }
        }
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += num;
            while (str[i] < 'A' || str[i] > 'Z')
            {
                if (str[i] > 'Z')
                {
                    str[i] -= 26;
                }
                else
                {
                    str[i] += 26;
                }
            }
        }
    }
    return str;
}

std::string decrypt_caesar(std::string str, int num)
{

    num = -1 * num;
    str = encrypt_caesar(str, num); //добавил возможность реальзации через вызов функции
    /*for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] -= num;
            while (str[i] < 'a' || str[i] > 'z')
            {
                if (str[i] > 'z')
                {
                    str[i] -= 26;
                }
                else
                {
                    str[i] += 26;
                }
            }
        }
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] -= num;
            while (str[i] < 'A' || str[i] > 'Z')
            {
                if (str[i] > 'Z')
                {
                    str[i] -= 26;
                }
                else
                {
                    str[i] += 26;
                }
            }
        }
    }*/
    return str;
}

int main()
{
    std::string str;
    int num;
    std::cout << "input string: \n";
    std::getline(std::cin, str);
    std::cout << "input number: \n";
    std::cin >> num;
    str = encrypt_caesar(str, num);
    std::cout << str << '\n';
    str = decrypt_caesar(str, num);
    std::cout << str;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
