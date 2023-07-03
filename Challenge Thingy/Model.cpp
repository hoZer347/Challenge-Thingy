#include "Model.h"

#include <random>

void Model::do_order()
{
	srand(time(NULL));

	int i = 1;
	bool b = true;
	while (b)
	{
		b = false;
		for (auto j = 0; j < i; j++)
			if (!database[j].empty())
			{
				new_lessons.push_front(database[j].front());
				database[j].pop_front();
				b = true;
			};

		if (i < database.size())
			i++;
	};

	std::cout << "Lessons (reversed):" << std::endl;
	for (auto& i : new_lessons)
		std::cout << i <<", ";

	std::cout << std::endl;
};


void Model::get_next()
{
	static uint64_t counter;

	switch (counter++ % 4)
	{
	case 0:
	case 1:
	case 2:
		while (learning.size() < 5 && !new_lessons.empty())
		{
			std::cout << "Adding new Lesson to 'Learning': " << new_lessons.back() << std::endl;

			learning.push_front(new_lessons.back());
			new_lessons.pop_back();
		};

		if (learning.empty())
			goto out_of_lessons;

		std::cout << "Pulling 'Learning' lesson: ";

		lesson_plan.push_back(learning.back());
		learning.pop_back();
		do_lesson();
		return;

	case 3:
		if (strong.empty())
			goto out_of_lessons;

		std::cout << "Pulling 'Strong' lesson: ";

		lesson_plan.push_back(strong.back());
		strong.pop_back();
		do_lesson();

		return;
	};

out_of_lessons:
	if (learning.empty() || strong.empty())
		std::cout << "No Lessons left" << std::endl;
	else
		get_next();
};


void Model::do_lesson()
{
	int r = rand() % 80 + 20;

	// TODO: Add a filter for recently repeated lessons

	std::cout << lesson_plan.back() << ": %" << r;

	if (r >= 60)
	{
		std::cout << " -> strong" << std::endl;
		strong.push_front(lesson_plan.back());
	}
	else
	{
		std::cout << " -> learning" << std::endl;
		learning.push_front(lesson_plan.back());
	};
};


void Model::generate(int amount)
{
	do_order();

	for (auto i = 0; i < amount; i++)
		get_next();

	std::cout << "Learning: ";
	for (auto& i : learning)
		std::cout << i << ", ";
	std::cout << std::endl;

	std::cout << "Strong: ";
	for (auto& i : strong)
		std::cout << i << ", ";
	std::cout << std::endl;
};
