/*
 * main.cpp
 *
 *  Created on: 12 Jan 2024
 *      Author: Shadoo
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

enum class Strategy
{
	neverSwitch,
	switchAtEnd,
	alwaysSwitch,
	randomSwitch,
	randomSwitchButNotAtEnd,
	randomSwitchButAlwaysAtEnd,
};

struct Door {
    bool isOpen;
    bool isChosen;
    bool isWin;

    Door(): isOpen(false), isChosen(false), isWin(false){}
};

bool montyHall(int numDoors, Strategy strat)
{
	/*Setting up the seeds and range for the RNG for the doors and boolean.
	 * NOTE: the function below is not assigning the number itself to the doors
	 * But rather generating the index to access the vector storing the doors*/

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distDoors(0, numDoors-1);
	std::uniform_int_distribution<> distBool(0, 1);

	//the winning door and initial chosen door are randomly chosen
	std::vector<Door> doors(numDoors);
	int winningDoor = distDoors(gen);
	doors[winningDoor].isWin = true;
	int chosenDoor = distDoors(gen);
	doors[chosenDoor].isChosen = true;
	int revealedDoor;
	int newChosenDoor;
	bool shouldSwitch = false;

	for(int rounds = 0; rounds < numDoors-2; rounds++)
	{

		do{

		revealedDoor = distDoors(gen);
		} while(revealedDoor == chosenDoor || revealedDoor == winningDoor || doors[revealedDoor].isOpen);
		//making sure that the revealed door is not the winning door, the contestant's chosen door or the doors that have opened before
		doors[revealedDoor].isOpen = true;


		switch (strat) {
			case Strategy::neverSwitch:
				shouldSwitch = false;
				break;
			case Strategy::switchAtEnd:
				if(rounds == numDoors -3){
					shouldSwitch = true;}
				else{
					shouldSwitch = false;
				}
				break;
			case Strategy::alwaysSwitch:
				shouldSwitch = true;
				break;
			case Strategy::randomSwitch:
				shouldSwitch = distBool(gen);
				break;
			case Strategy::randomSwitchButNotAtEnd:
			    if(rounds != numDoors -3){
			    	shouldSwitch = distBool(gen);
			    }
			    else{
			    	shouldSwitch = false;
			    }
			    break;
			case Strategy::randomSwitchButAlwaysAtEnd:
				if(rounds != numDoors -3){
					shouldSwitch = distBool(gen);
				}
				else{
					shouldSwitch = true;
				}
			    break;
		}

		if(shouldSwitch){
			do{
				newChosenDoor = distDoors(gen);
			} while(newChosenDoor == revealedDoor || doors[newChosenDoor].isChosen || doors[newChosenDoor].isOpen);
			//making sure that the new chosen door is not the door that has been revealed before

			doors[chosenDoor].isChosen = false;
			chosenDoor = newChosenDoor;
			doors[chosenDoor].isChosen = true;

		}
	}

	return chosenDoor == winningDoor;
}

int main()
{
	int numDoors, numSims;

	std::cout << "Enter the amount of Doors for this simulation:" << std::endl;
	std::cin >> numDoors;

	std::cout << "Enter the amount of Simulations for this Program:" << std::endl;
	std::cin >> numSims;

	std::vector<Strategy> strats = {Strategy::neverSwitch, Strategy::switchAtEnd, Strategy::alwaysSwitch, Strategy::randomSwitch, Strategy::randomSwitchButNotAtEnd, Strategy::randomSwitchButAlwaysAtEnd};
	std::vector<std::string> stratNames = {"Never Switch", "Only Switch at the End", "Always Switch every Time", "Randomly choosing to Switch at every Step", "Randomly choosing to Switch but Stay at the End", "Randomly choosing to Switch but always Switch at the End"};
	std::cout << std::left << std::setw(70) << "Strategy" << std::setw(20) << "Number of Wins" << std::setw(20) << "Win Percentages" << std::endl;
	std::cout << std::setw(110) << std::setfill('-') << '-' << std::endl;

	for(size_t i=0; i<strats.size(); i++)
	{
		int wins = 0;
		for(int j=0; j<numSims; j++)
		{
			if(montyHall(numDoors, strats[i])){
				wins++;

			}
		}
		double winPercentage = static_cast<double>(wins) * 100 / numSims;
		std::cout << std::left << std::setfill(' ') << std::setw(70) << stratNames[i] << std::setw(20) << wins << winPercentage << "%" << std::endl;

	}
	std::cout << std::endl;
	system("pause");
}
