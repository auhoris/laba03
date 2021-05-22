#include <iostream>
#include <string>
#include <ostream>
#include <vector>

class Thing
{
private:
	std::string	name;
	int			weight;
	int			price;
public:
	Thing()
	{
		this->name = "";
		this->weight = -1;
		this->price = -1;
	}
	Thing&	operator=(const Thing &other)
	{
		if (&other == this)
			return (*this);
		this->name = other.name;
		this->weight = other.weight;
		this->price = other.price;
		return (*this);
	}
	// copy constructor
	Thing(const Thing &other)
	{
		this->name = other.name;
		this->weight = other.weight;
		this->price = other.price;
	}
	void		use(std::string name);
	void		set_thing(std::string name, int weight, int price)
	{
		this->name = name;
		this->weight = weight;
		this->price = price;
	}
	void		show_item()
	{
		std::cout << "Название: " << this->name << std::endl;
		std::cout << "Вес: " << this->weight << std::endl;
		std::cout << "Цена: " << this->price << std::endl;
	}
	std::string	get_name()
	{
		return (this->name);
	}
};

class Hero
{
private:
	Thing	*item;
	int		inv_size;
public:
	 Hero()
	{
		this->item = nullptr;
		this->inv_size = 0;
	}
	 
	void	take(std::string name, int weight, int price)
	{
		Thing	*temp;

		if (this->item == nullptr)
		{
			this->item = new Thing[2];
			this->item->set_thing(name, weight, price);
			this->inv_size++;
		}
		else
		{
			temp = new Thing[this->inv_size + 2];
			for (int i = 0; i < this->inv_size; i++)
				temp[i] = this->item[i];
			delete [] this->item;
			temp[this->inv_size].set_thing(name, weight, price);
			this->item = temp;
			this->inv_size++;
		}
	}
	void	sack()
	{
		std::cout << "Размер инвентаря: " << this->inv_size << std::endl;
		for (int i = 0; i < this->inv_size; i++)
			this->item[i].show_item();
	}
	Thing	lose(std::string name)
	{
		Thing	temp;

		for (int i = 0; i < this->inv_size; i++)
			if (item[i].get_name() == name)
				return (item[i]);
		return (temp);
	}
};

int main(void)
{
	Hero		hero;
	Thing		thing;
	std::string	name;
	int			weight;
	int			price;

	hero.take("sword", 90, 10);
	hero.take("potion", 90, 10);
	hero.take("wand", 90, 10);
	hero.take("garbage", 90, 10);
	thing = hero.lose("wand");
	thing.show_item();
	// hero.sack();
	return (0);
}
