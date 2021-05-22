#include <cstddef>
#include <iostream>
#include <string>
#include <ostream>

typedef struct s_item
{
	std::string	name;
	int			weight;
	int			price;
}				t_item;

class Hero
{
private:
	t_item	*item;
	int		inv_size;
public:
	Hero()
	{
		t_item	*item;
		item = nullptr;
		this->inv_size = 0;
	}
	void	take(std::string name, int weight, int price)
	{
		t_item	*temp;

		if (this->item == nullptr)
		{
			this->item = new t_item[2];
			this->item[this->inv_size].name = name;
			this->item[this->inv_size].weight = weight;
			this->item[this->inv_size].price = price;
			this->inv_size++;
		}
		else
		{
			temp = new t_item[this->inv_size + 2];
			for (int i = 0; i < this->inv_size; i++)
				temp[i] = this->item[i];
			delete [] this->item;
			temp[this->inv_size].name = name;
			temp[this->inv_size].weight = weight;
			temp[this->inv_size].price = price;
			this->item = temp;
			this->inv_size++;
		}
	}
};

int main(void)
{
	Hero		hero;
	std::string	name;
	int			weight;
	int			price;

	std::cout << "Введите название предмета: ";
	std::cin >> name;
	std::cout << "Введите вес предмета: ";
	std::cin >> weight;
	std::cout << "Введите цену предмета: ";
	std::cin >> price;
	hero.take(name, weight, price);
	std::cout << "Введите название предмета: ";
	std::cin >> name;
	std::cout << "Введите вес предмета: ";
	std::cin >> weight;
	std::cout << "Введите цену предмета: ";
	std::cin >> price;
	hero.take(name, weight, price);
	return (0);
}
