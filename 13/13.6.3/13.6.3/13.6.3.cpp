

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> db(20);
    int number;
    int i = 0;
    std::cout << "input number: ";
    std::cin >> number;
    while (number != -1)
    {
        if (i == db.size()) {
            
            for (int j = 0; j < db.size() - 1; j++)
            {
                db[j] = db[j+1];
            }
            db[db.size() - 1] = number;
            i--;
        }
        else if (i < db.size()) {
            db[i] = number;
        }
        i++;
        std::cout << "input number: ";
        std::cin >> number;
    }
    for (int i = 0; i < db.size(); i++) {
        std::cout << db[i] << " ";
    }
}
