#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <string>

struct City {
	std::string name;
	int population{};
	int area{};

	City() = default;
	City(std::string name, int population, int area) :
		name(name), population(population), area(area) {}
};

class Table
{
private:
	int key{};
	std::map<int, City> cities;
public:
	void create_city(std::string name, int population, int area);

	void read_city(int key) const;

	void show_table() const;

	void delete_city(int key);

	void change_name(int key, std::string new_name);

	void change_population(int key, int new_population);

	void change_area(int key, int new_area);
};

#endif
