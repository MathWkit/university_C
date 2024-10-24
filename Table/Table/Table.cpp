#include "Table.h"

#include <iostream>
#include <map>

void Table::create_city(std::string name, int population, int area)
{
	City city(name, population, area);

	cities[key] = city;
	++key;
}

void Table::read_city(int key) const
{
	auto city = cities.find(key);

	if (city != cities.cend()) {
		std::cout << "Название города: " << cities.at(key).name << std::endl << "Население: " << cities.at(key).population << std::endl << "Площадь: " << cities.at(key).area << std::endl;
	}
}

void Table::show_table() const
{
	for (auto& pair : cities) {
		const auto& key = pair.first;
		const auto& city = pair.second;
		std::cout << key << " | " << city.name << " | " << city.population << " | " << city.area << std::endl;
	}
}

void Table::delete_city(int key)
{
	auto city = cities.find(key);

	if (city != cities.cend()) {
		cities.erase(key);
		std::cout << "Город удален";
	}
	else {
		std::cout << "Такой город не существует" << std::endl;
	}
}

void Table::change_name(int key, std::string new_name)
{
	auto city = cities.find(key);

	if (city != cities.cend()) {
		city->second.name = new_name;
		std::cout << "Название изменено" << std::endl;
	}
	else {
		std::cout << "Такой город не существует";
	}
}

void Table::change_population(int key, int new_population)
{
	auto city = cities.find(key);

	if (city != cities.cend()) {
		city->second.population = new_population;
		std::cout << "Население изменено" << std::endl;
	}
	else {
		std::cout << "Такой город не существует";
	}
}

void Table::change_area(int key, int new_area)
{
	auto city = cities.find(key);

	if (city != cities.cend()) {
		city->second.area = new_area;
		std::cout << "Площадь изменена";
	}
	else {
		std::cout << "Такой города не существует";
	}
}