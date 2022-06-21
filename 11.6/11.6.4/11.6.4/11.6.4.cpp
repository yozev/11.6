
#include <iostream>

int correct_input(std::string str) 
{
    int correct = 0;
    if (str.length() != 3)
    {
        std::cout << "zero 1\n";
        return 0;
        
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'X' || str[i] == 'O' || str[i] == '.')
        {
            
            correct = 1;
        }
        else
            std::cout << "zero 2\n";
            correct = 0;
    }
        return correct;
}

int correct_symbols(std::string str1, std::string str2, std::string str3)
{
    int X = 0, O = 0, dots = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == 'X')
            X++;
        if (str1[i] == 'O')
            O++;
        if (str1[i] == '.')
            dots++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (str2[i] == 'X')
            X++;
        if (str2[i] == 'O')
            O++;
        if (str2[i] == '.')
            dots++;
    }
    for (int i = 0; i < str3.length(); i++)
    {
        if (str3[i] == 'X')
            X++;
        if (str3[i] == 'O')
            O++;
        if (str3[i] == '.')
            dots++;
    }
    if (X >= O)
    {
        if (X >= 3)
            return 1;
        else
            return 2;
    }
    else
        return 0;
  
}

/*char get_symbol(std::string str1, std::string str2, std::string str3, int x, int y)
{

}*/

std::string winer_line(std::string str)
{
    std::string winner = "";
    if (str[0] == str[1] && str[2] == str[1])
        winner += str[0];
    return winner;
}

int who_is_winner(std::string str1, std::string str2, std::string str3)
{
    std::string column1 = "", column2 = "", column3 = "", diagonal1 = "", diagonal2 = "";
    //str1 
    //str2
    //str3
    column1 = str1[0] + str2[0] + str3[0];
    column2 = str1[1] + str2[1] + str3[1];
    column3 = str1[2] + str2[2] + str3[2];
    diagonal1 = str1[0] + str2[1] + str3[2];
    diagonal2 = str1[2] + str2[1] + str3[0];
    std::string winner = "";
    winner += winer_line(str1);
    winner += winer_line(str2);
    winner += winer_line(str3);
    winner += winer_line(column1);
    winner += winer_line(column2);
    winner += winer_line(column3);
    winner += winer_line(diagonal1);
    winner += winer_line(diagonal2);
    std::cout << "winner_line\n";
    if (winner == "X")
        return 1;
    else if (winner == "O")
        return 2;
    else
        return 0;
}

int main()
{

    std::string str1 = "", str2 = "", str3 = "";
    int winner = 0;

    std::cout << "input game result:\n";
    std::cin >> str1 >> str2 >> str3;
    std::cout << str1 << str2 << str3;
    
    int correct = correct_input(str1);
    std::cout << correct << "\n";
    correct = correct_input(str2);
    std::cout << correct << "\n";
    correct = correct_input(str3);
    std::cout << correct << "\n";
    if (correct == 1)
    {
        winner = who_is_winner(str1, str2, str3);
        if (winner == 1)
            std::cout << "P winner\n";
        else if (winner == 2)
            std::cout << "V winner\n";
        else
            std::cout << "nobody\n";
    }
}

