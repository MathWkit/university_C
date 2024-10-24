#include "Table.h"

#include <iostream>
#include <string>
#include <map>

enum Commands
{
	create_city,
	read_city,
	show_table,
	delete_city,
	change_name,
	change_population,
	change_area
};

std::map<std::string, Commands> commands_map
{
	{"create_city", create_city},
	{"read_city", read_city},
	{"show_table", show_table},
	{"delete_city", delete_city},
	{"change_name", change_name},
	{"change_population", change_population},
	{"change_area", change_area}
};

Commands get_command(const std::string& command)
{
	auto it = commands_map.find(command);
	return it->second;
}

int main()
{
	Table table;

	std::string name;
	int key, population, area;

	while (true)
	{
		std::string input_command;

		std::cout << std::endl << "Введите команду:\n" << "create_city - создать новый город\n" << "read_city - увидеть информацию о конкретном городе\n" << "show_table - увидеть всю таблицу\n" << "delete_city - удалить город по ключу\n" << "change_name - изменить название конкретного города\n" << "change_population - изменить население конкретного города\n" << "change_area - изменить площадь(км2) конкретного города\n" << std::endl;

		std::cin >> input_command;
		Commands command = get_command(input_command);

		switch (command)
		{
		case create_city:
			std::cout << "Введите название города: ";
			std::cin >> name;
			std::cout << "Введите население города: ";
			std::cin >> population;
			std::cout << "Введите площадь города (км2): ";
			std::cin >> area;
			table.create_city(name, population, area);
			break;
		case read_city:
			std::cout << "Введите ключ города: ";
			std::cin >> key;
			table.read_city(key);
			break;
		case show_table:
			table.show_table();
			break;
		case delete_city:
			std::cout << "Введите ключ города: ";
			std::cin >> key;
			table.delete_city(key);
			break;
		case change_name:
			std::cout << "Введие ключ города: ";
			std::cin >> key;
			std::cout << "Введите новое имя города: ";
			std::cin >> name;
			table.change_name(key, name);
			break;
		case change_population:
			std::cout << "Введие ключ города: ";
			std::cin >> key;
			std::cout << "Введите новое население города: ";
			std::cin >> population;
			table.change_name(key, std::to_string(population));
			break;
		case change_area:
			std::cout << "Введие ключ города: ";
			std::cin >> key;
			std::cout << "Введите новую площадь города: ";
			std::cin >> area;
			table.change_name(key, std::to_string(area));
			break;
		}
	}

	return 0;
}
