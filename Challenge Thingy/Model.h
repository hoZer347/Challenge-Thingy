#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>


// Generates an Itinerary for VOSCE studying sessions
// Guide for member variables:
// l_: list of strings
// v_: vector of strings
// v_l_: vector of lists of strings
class Model final
{
	// Class Database
	std::vector<std::string> v_lessons_in_order;
	std::vector<std::list<std::string>> v_l_database
	{
		{ "Resp1", "Resp2", "Resp3", "Resp4", "Resp5", },
		{ "MSK1", "MSK2", "MSK3", "MSK4", "MSK5", "MSK6", },
		{ "Cardio1", "Cardio2", "Cardio3", "Cardio4", "Cardio5", },
		{ "Neuro1", "Neuro2", "Neuro3", "Neuro4", "Neuro5", "Neuro6", },
		{ "Core1", "Core2", "Core3", "Core4", "Core5", },
		{ "Gastro1", "Gastro2", "Gastro3", },
	};

	// Helper function that sets up the lessons in order
	void do_order();

	// Gets the next item that should be studied, based on the current state
	void get_next();

	// Simulates the execution of a lesson, assigning a random grade and putting it into the correct category
	void do_lesson();


	// New
	std::list<std::string> l_new_lessons;	// Lessons have not been introduced yet

	// Open
	std::list<std::string> l_learning;		// Lessons that the student is unfamiliar with, either brand new, or they got a bad score on it
	std::list<std::string> l_strong;		// Lessons on which the student has gotten a good score
	std::list<std::string> l_mature;		// TODO: Implement this

	// Result
	std::list<std::string> l_lesson_plan;	// The final lesson plan the student should use for studying

public:

	// Generates a set number of training sessions to do
	void generate(int amount = 20);
};
