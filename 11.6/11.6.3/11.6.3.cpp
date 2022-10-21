#include <iostream>

int correct_symbols(std::string str)
{
	int correct = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
			correct = 1;
		else 
		{
			correct = 0;
			break;
		}
	}
	return correct;
}

int correct_dots(std::string str)
{
	int dots = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dots++;
	}
	if (dots == 3)
		return 1;
	else
		return 0;
}

std::string get_address_part(std::string str, int number)
{
	std::string str_part = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (number == 0 && str[0] == '.')
		{
			str_part = "0";
			break;
		}
		if (str[i] == '.')
		{
			number--;
			i++;
		}
		while (number == 0 && i <str.length() && str[i] != '.' )
		{
			str_part += str[i];
			i++;
		}
		if (number == 0)
			break;
	}
	return str_part;
}

int correct_zeroes(std::string str1, std::string str2, std::string str3, std::string str4)
{
	int corr = 1;
	if (str1[0] == '0' && str1.length() > 1 || str1.length() == 0)
		corr = 0;
	if (str2[0] == '0' && str2.length() > 1 || str2.length() == 0)
		corr = 0;
	if (str3[0] == '0' && str3.length() > 1 || str3.length() == 0)
		corr = 0;
	if (str4[0] == '0' && str4.length() > 1 || str4.length() == 0)
		corr = 0;

	return corr;
}


int get_number_from_string(std::string str)
{	
	int number = 0;
	int ex = 1;
	int i = str.length()-1;
	for (i; i >= 0; i--)
	{
		number += (str[i] - 48) * ex;
		ex *= 10;
	}
	return number;
}

int correct_numbers(std::string str1, std::string str2, std::string str3, std::string str4)
{
	int correct = 0;
	int str_num1, str_num2, str_num3, str_num4;
	str_num1 = get_number_from_string(str1);
	str_num2 = get_number_from_string(str2);
	str_num3 = get_number_from_string(str3);
	str_num4 = get_number_from_string(str4);
	if (str_num1 >= 0 && str_num1 <= 255)
	{
		if (str_num2 >= 0 && str_num2 <= 255)
		{
			if (str_num3 >= 0 && str_num3 <= 255)
			{
				if (str_num4 >= 0 && str_num4 <= 255) {
					//correct = 1;
					correct = correct_zeroes(str1, str2, str3, str4);
				}
			}
		}
	}


	return correct;

}

int main()
{
	std::string str, str1 = "", str2 = "", str3 = "", str4 = "";

	std::cout << "input string:\n";
	std::cin >> str;
	int cor = correct_symbols(str);
	if (cor == 1)
		cor = correct_dots(str);
	if (cor == 1)
	{
		str1 = get_address_part(str, 0);
		str2 = get_address_part(str, 1);
		str3 = get_address_part(str, 2);
		str4 = get_address_part(str, 3);

		cor = correct_numbers(str1, str2, str3, str4);
		
	}
	if (cor == 1)
		std::cout << "Valid" << "\n";
	else
		std::cout << "Invalid\n";
}