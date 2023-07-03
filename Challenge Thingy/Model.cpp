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
			if (!v_l_database[j].empty())
			{
				l_new_lessons.push_front(v_l_database[j].front());
				v_l_database[j].pop_front();
				b = true;
			};

		if (i < v_l_database.size())
			i++;
	};

	std::cout << "Lessons (reversed):" << std::endl;
	for (auto& i : l_new_lessons)
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
		while (l_learning.size() < 5 && !l_new_lessons.empty())
		{
			std::cout << "Adding new Lesson to 'Learning': " << l_new_lessons.back() << std::endl;

			l_learning.push_front(l_new_lessons.back());
			l_new_lessons.pop_back();
		};

		if (l_learning.empty())
			goto out_of_lessons;

		std::cout << "Pulling 'Learning' lesson: ";

		l_lesson_plan.push_back(l_learning.back());
		l_learning.pop_back();
		do_lesson();
		return;

	case 3:
		if (l_strong.empty())
			goto out_of_lessons;

		std::cout << "Pulling 'Strong' lesson: ";

		l_lesson_plan.push_back(l_strong.back());
		l_strong.pop_back();
		do_lesson();

		return;
	};

out_of_lessons:
	if (l_learning.empty() || l_strong.empty())
		std::cout << "No Lessons left" << std::endl;
	else
		get_next();
};


void Model::do_lesson()
{
	int r = rand() % 80 + 20;

	// TODO: Add a filter for recently repeated lessons

	std::cout << l_lesson_plan.back() << ": %" << r;

	if (r >= 60)
	{
		std::cout << " -> strong" << std::endl;
		l_strong.push_front(l_lesson_plan.back());
	}
	else
	{
		std::cout << " -> learning" << std::endl;
		l_learning.push_front(l_lesson_plan.back());
	};
};


void Model::generate(int amount)
{
	do_order();

	for (auto i = 0; i < amount; i++)
		get_next();

	std::cout << "Learning: ";
	for (auto& i : l_learning)
		std::cout << i << ", ";
	std::cout << std::endl;

	std::cout << "Strong: ";
	for (auto& i : l_strong)
		std::cout << i << ", ";
	std::cout << std::endl;
};
