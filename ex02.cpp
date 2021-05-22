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
	int			durability;

public:
	Thing()
	{
		this->name = "";
		this->weight = -1;
		this->price = -1;
		this->durability = -1;
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
		this->durability = other.durability;
	}
	void		decrease_durability()
	{
		this->durability--;
	}
	int			get_durability()
	{
		return (this->durability);
	}
	void		use(std::string name)
	{
		std::cout << "Hero used " << name << " item" << std::endl;
	}
	void		set_thing(std::string name, int weight, int price, int durability)
	{
		this->name = name;
		this->weight = weight;
		this->price = price;
		this->durability = durability;
	}
	void		show_item()
	{
		std::cout << "Название: " << this->name << std::endl;
		std::cout << "Вес: " << this->weight << std::endl;
		std::cout << "Цена: " << this->price << std::endl;
		std::cout << "Цена: " << this->durability << std::endl;
	}
	std::string	get_name()
	{
		return (this->name);
	}
};

class Hero
{
private:
	std::vector<Thing>	item;
public:
	void	take(std::string name, int weight, int price, int durability)
	{
		Thing	temp;

		temp.set_thing(name, weight, price, durability);
		this->item.push_back(temp);
	}
	void	sack()
	{
		std::cout << "Размер инвентаря: " << this->item.size() << std::endl;
		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
			it->show_item();
	}
	void	use(std::string name)
	{
		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
		{
			if (it->get_name() == name)
			{
				it->use(name);
				it->decrease_durability();
				std::cout << it->get_durability() << std::endl;
				if (it->get_durability() < 1)
					this->item.erase(it);
				return ;
			}
		}
	}
	Thing	lose(std::string name)
	{
		Thing	thing;

		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
		{
			if (it->get_name() == name)
			{
				thing = *it;
				this->item.erase(it);
				break ;
			}
		}
		return (thing);
	}
};

int main(void)
{
	Hero		hero;
	Thing		thing;

	hero.take("sword", 90, 10, 10);
	hero.take("potion", 90, 10, 1);
	hero.take("wand", 90, 10, 5);
	hero.take("garbage", 90, 10, 10);
	hero.use("potion");
	hero.lose("sword");
	hero.lose("wand");
	hero.lose("garbage");
	hero.sack();
	return (0);
}
