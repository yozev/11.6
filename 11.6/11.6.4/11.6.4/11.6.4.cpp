
#include <iostream>

int correct_input(std::string str) 
{
    int correct;
    if (str.length() != 3)
    {
        return correct = 0;
        
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'X' || str[i] == 'O' || str[i] == '.')
        {
            correct = 1;
        }
        else
        {
            correct = 0;
        }
    }
        return correct;
}

int correct_symbols(std::string str1, std::string str2, std::string str3)
{
    int X = 0, O = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == 'X')
            X++;
        if (str1[i] == 'O')
            O++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (str2[i] == 'X')
            X++;
        if (str2[i] == 'O')
            O++;
    }
    for (int i = 0; i < str3.length(); i++)
    {
        if (str3[i] == 'X')
            X++;
        if (str3[i] == 'O')
            O++;
    }
    if (X - O == 1 || X - O == 0)
    {
        if (X == O)
            return 3;
        if (X >= 3)
            return 1;
        else
            return 2;
    }
    else
        return 0;
  
}

std::string winer_line(std::string str)
{
    std::string winner = "";
    if (str[0] == str[1] && str[2] == str[1] && str[1] != '.')
        winner += str[0];
    return winner;
}

int who_is_winner(std::string str1, std::string str2, std::string str3)
{
    std::string column1 = "", column2 = "", column3 = "", diagonal1 = "", diagonal2 = "";
    //str1 
    //str2
    //str3
    column1 += str1[0];
        column1 += str2[0];
            column1 += str3[0];
    column2 += str1[1];
        column2 += str2[1];
            column2 += str3[1];
    column3 = str1[2];
        column3 += str2[2];
            column3 += str3[2];
    diagonal1 += str1[0];
        diagonal1 += str2[1];
            diagonal1 += str3[2];
    diagonal2 += str1[2];
        diagonal2 += str2[1];
            diagonal2 += str3[0];

    //std::string winner = "";
    winner += winer_line(str1);
    winner += winer_line(str2);
    winner += winer_line(str3);
    winner += winer_line(column1);
    winner += winer_line(column2);
    winner += winer_line(column3);
    winner += winer_line(diagonal1);
    winner += winer_line(diagonal2);
    if (winner == "X")
        return 1;
    else if (winner == "O")
        return 2;
    else if (winner.length() > 1)
        return 3;
    else
        return 0;
}

int main()
{

    std::string str1 = "", str2 = "", str3 = "";
    int winner = 0;

    std::cout << "input game result:\n";
    std::cin >> str1 >> str2 >> str3;
    //std::cout << str1 + "  " << str2 + "  " << str3 + "  " << "\n";
    
    int correct;
    correct = correct_input(str1);
    if (correct == 1)
        correct = correct_input(str2);
    if (correct == 1)
        correct = correct_input(str3);
    if (correct == 1)
        correct = correct_symbols(str1, str2, str3);
    if (correct == 1 || correct == 3)
    {
        winner = who_is_winner(str1, str2, str3);
        if (winner == 1 && correct != 3)
            std::cout << "Petya winner\n";
        else if (winner == 2)
            std::cout << "Vanya winner\n";
        else if (winner == 3)
            std::cout << "incorrect\n";
        else if (winner == 0)
            std::cout << "nobody\n";
        else
            std::cout << "incorrect\n"; //крестики победили, X и O одинаково
    }
    else
    {
        if (correct == 2)
            std::cout << "nobody\n";
        else
            std::cout << "incorrect\n";
    }
}

