#include <cstdint>
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
	void		use(const std::string &name)
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
		std::cout << "Прочность: " << this->durability << std::endl;
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
	std::vector<Hero>	freinds;
	std::string			hero_name;
public:
	Hero(std::string hero_name = "unknown")
	{
		this->hero_name = hero_name;
	}
	void	take(std::string name, int weight, int price, int durability)
	{
		Thing	temp;

		temp.set_thing(name, weight, price, durability);
		this->item.push_back(temp);
	}
	void	take(Thing thing)
	{
		this->item.push_back(thing);
	}
	void	sack()
	{
		int	i;

		i = 0;
		std::cout << "\n\n<======= Инвентарь героя " << this->hero_name << "======>" << std::endl;
		std::cout << "---Размер инвентаря: " << this->item.size() << " ---"<< std::endl;
		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
		{
			i++;
			it->show_item();
			std::cout << i << ")"<< "----------------------------------------" << std::endl;
		}
	}
	void	use(const std::string &name)
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
	void	add_friend(Hero &hero)
	{
		this->freinds.push_back(hero);
		hero.freinds.push_back(*this);
		// Добавляем возможность использовать инвентарь друга
		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
		{
			if (hero.has_item(*it) == false)
				hero.item.push_back(*it);
		}
		for (std::vector<Thing>::iterator it = hero.item.begin(); it != hero.item.end(); it++)
		{
			if (this->has_item(*it) == false)
				this->item.push_back(*it);
		}

	}
	bool	has_item(Thing thing)
	{
		for (std::vector<Thing>::iterator it = this->item.begin(); it != this->item.end(); it++)
		{
			if (it->get_name() == thing.get_name())
				return (true);
		}
		return (false);
	}
	void	friends()
	{
		int	i;

		i = 0;
		std::cout << "Список друзей героя " << this->hero_name << ":" << std::endl;
		for (std::vector<Hero>::iterator it = this->freinds.begin(); it != this->freinds.end(); it++)
		{
			i++;
			std::cout << i << ": "<< it->hero_name << std::endl;
		}
	}
	Thing	lose(const std::string &name)
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
	Hero		hero1("hero1");
	Hero		hero2("hero2");
	Hero		hero3("hero3");
	Hero		hero4("hero4");
	Thing		thing;

	hero1.take("sword", 90, 10, 15);
	hero1.take("wand", 10, 5, 5);
	hero2.take("something", 12, 12, 11);
	hero3.take("dirt", 15, 0, 1);
	hero4.take("shield", 15, 150, 1000);
	hero1.add_friend(hero2);
	hero1.add_friend(hero4);
	hero1.friends();
	hero1.sack();
	hero2.sack();
	hero4.sack();
	return (0);
}
