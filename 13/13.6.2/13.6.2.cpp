
#include <iostream>
#include <vector>

int main()
{
	std::vector<float> prices {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> items {0,1,2,6};
	float sum = 0;
	int issue = 0;
	for (int i = 0; i < items.size(); i++) {
		if (items[i] < prices.size()) {
			sum += prices[items[i]];
		}
		else {
			std::cout << "error (items index issues) in " << items[i] << " in " << i << " index" << std::endl;
			issue++;
		}
	}
	if (issue == 0)
		std::cout << "summ is: " << sum << "size is " << prices.size();

}
