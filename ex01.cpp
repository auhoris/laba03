#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <ostream>

class Hero
{
private:
	typedef struct s_item
	{
		std::string	name;
		int			weight;
		int			price;
	}				t_item;
	std::vector<t_item>	item;

public:
	void	take(std::string name, int weight, int price)
	{
		t_item	temp;

		temp.name = name;
		temp.price = price;
		temp.weight = weight;
		this->item.push_back(temp);
	}
};

int main(void)
{
	Hero		hero;
	std::string	name;
	int			weight;
	int			price;

	hero.take("sword", 90, 100);
	hero.take("potion", 90, 10);
	hero.take("wand", 90, 10);
	hero.take("garbage", 90, 100);
	return (0);
}
