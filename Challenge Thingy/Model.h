#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>

struct Lesson
{
	std::string type;
	std::string competency;
};

class Model
{
	// Class Database
	std::vector<std::string> lessons_in_order;
	std::vector<std::list<std::string>> database
	{
		{ "Resp1", "Resp2", "Resp3", "Resp4", "Resp5", },
		{ "MSK1", "MSK2", "MSK3", "MSK4", "MSK5", "MSK6", },
		{ "Cardio1", "Cardio2", "Cardio3", "Cardio4", "Cardio5", },
		{ "Neuro1", "Neuro2", "Neuro3", "Neuro4", "Neuro5", "Neuro6", },
		{ "Core1", "Core2", "Core3", "Core4", "Core5", },
		{ "Gastro1", "Gastro2", "Gastro3", },
	};

	void do_order();
	void get_next();
	void do_lesson();


	// New
	std::list<std::string> new_lessons;

	// Open
	std::list<std::string> learning;
	std::list<std::string> strong;
	std::list<std::string> mature;

	std::list<std::string> lesson_plan;

public:
	void generate(int amount = 20);
};
