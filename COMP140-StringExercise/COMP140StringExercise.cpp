// COMP140StringExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class CharacterStats
{
public:
	CharacterStats()
	{
		Name = "Name";
		Age = 10;
		Health = 19;
		Score = 0;
	}
	~CharacterStats()
	{
		
	}

	std::string GetName()
	{
		return Name;
	}
	void SetName(std::string newName)
	{
		Name = newName;
	}

	int GetAge()
	{
		return Age;
	}
	void SetAge(int newAge)
	{
		Age = newAge;
	}

	int GetHealth()
	{
		return Health;
	}
	void SetHealth(int newHealth)
	{
		Health = newHealth;
	}

	int GetScore()
	{
		return Score;
	}
	void SetScore(int newScore)
	{
		Score = newScore;
	}

private:
	std::string Name;
	int Age;
	int Health;
	int Score;

};


int main()
{
	//Create an instance of CharacterStats
	CharacterStats stats;
	stats.SetAge(30);
	stats.SetName("Brian");
	stats.SetHealth(100);
	stats.SetScore(0);

	std::stringstream characterString;
	characterString << "Name: " << stats.GetName();
	characterString << " Age: " << std::to_string(stats.GetAge());
	characterString << " Health: " << std::to_string(stats.GetHealth());
	characterString << " Score: " << std::to_string(stats.GetScore());

	//Print out the string
	std::cout << "Character Details" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << characterString.str() << std::endl;

    return 0;
}

