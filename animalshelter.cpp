/* File: animalshelter.cpp
 * Course: CS216-004
 * Project: Lab 11
 * Purpose:
 *
 * Author: Jen Lee
 */

#include <iostream>
#include "animalshelter.h"
#include <set>
#include <map>
#include <iomanip>

using namespace std;

// add a new dog breed in the animal shelter
// if the key (breed) exists, add the set of dognames to the values of the breed
// otherwise add the key and the set of dognames to the map
// breed is the new dog breed
// dognames are the set of dog names of the breed
void AnimalShelter::insert(string breed, set<string> dognames)
{
	BreedToNames[breed].insert(dognames.begin(), dognames.end());
	return;
}

// person: the name of the person who wants to adopt a dog of breed
// breed: the breed of the dog a person whats to adopt
// if such breed exists, display the message: person is adopting <a dog's name> (breed)
// and then delete the dog from the map
// otherwise, display the message: person CANNOT adopt a breed.
void AnimalShelter::validAdoption(string person, string breed)
{
	map<string, set<string> >::iterator i = BreedToNames.find(breed);
	if (i->first == breed)
	{
		cout << person << " is adopting " << *i->second.begin() << " ( " << breed << " )" << endl;
		// if it's the last dog, remove breed
		if (i->second.size() == 1)
			BreedToNames.erase(i->first);
		else
			BreedToNames[breed].erase(*i->second.begin());
	}
	else
		cout << person << " CANNOT adopt a " << breed << endl;
}
	
// check if the animal shelter is empty
// return true if it is 
// otherwise return false
bool AnimalShelter::empty() const
{
	if (BreedToNames.empty())
		return true;
	else
		return false;
}

// display all the animals currently in the shelter like this:
// breed: [ dog_name1 dog_name2 ... ]
void AnimalShelter::print() const
{
if (BreedToNames.empty()) 
	cout << "Currently no animal is in the shelter" << endl << endl;
// else, isn't empty
else
{
	map<string, set<string> >::const_iterator i;
	for (i = BreedToNames.begin(); i != BreedToNames.end(); i++)
	{
		cout << i->first << ": [ ";
		set<string>::const_iterator j;
		for (j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << *j << " ";
		}
		cout << "]" << endl;
	}
}
}
			
			
