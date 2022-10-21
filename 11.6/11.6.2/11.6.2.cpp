// 11.6.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

std::string first_part(std::string str)
{
    std::string str1;

    for (int i = 0; i < str.length(); i++)
    {
        while (i < str.length() && str[i] != '@')
        {
            str1 += str[i];
            i++;
        }
        if (str[i] == '@')
            break;
    }
    return str1;
}

std::string second_part(std::string str)
{
    std::string str2;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '@')
        {
            i++;
            while (i < str.length() && str[i] != '@')
            {
                str2 += str[i];
                i++;
            }
            break;
        }
    }
    return str2;
}



int correct_string(std::string str)
{
    int correct = 0;
    std::string symbols = "!#$%&'*+-/=?^_`{|}~QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    int dots = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < symbols.length(); j++)
        {
            if (symbols[j] == str[i])
            {
                correct = 1;
                //std::cout << i <<"find correct symbol\n";
                break;
            }
            else
            {
               correct = 0;
            }
        }
        if (str[0] == '.')
            return correct = 0;
        else if (i >= 2 && str[i] == '.' && str[i - 1] == '.')
        {
            return correct = 0;
        }
        else if (str[str.length() - 1] == '.')
            return correct = 0;
    }
    return correct;
}

int correct_string_second(std::string str)
{
    int correct = 0;
    std::string symbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    int dots = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < symbols.length(); j++)
        {
            if (symbols[j] == str[i])
            {
                correct = 1;
                //std::cout << i << "find correct symbol\n";
                break;
            }
            else
            {
                correct = 0;
            }
        }
        if (str[0] == '.')
            return correct = 0;
        else if (i >= 2 && str[i] == '.' && str[i - 1] == '.')
        {
            return correct = 0;
        }
        else if (str[str.length() - 1] == '.')
            return correct = 0;
    }
    return correct;
}

int main()
{

    std::string str, str1, str2;
    int correct = 0;
    std::cout << "input string\n";
    std::cin >> str;
    str1 = first_part(str);
    str2 = second_part(str);
    //std::cout << str1 << '\n';
    //std::cout << str2 << '\n';
    correct = correct_string(str1);
    if (correct == 1)
        correct = correct_string_second(str2);

    if (str1.length() + str2.length() != str.length() - 1)
    {
        correct = 0;
    }
    else if (str1.length() == 0 || str1.length() > 64)
        correct = 0;
    else if (str2.length() == 0 || str2.length() > 63)
        correct = 0;

    if (correct == 1)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

