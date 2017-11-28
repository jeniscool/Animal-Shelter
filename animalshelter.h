/* File: animalshelter.h
 * Course: CS216-00x
 * Project: Lab 11
 * Purpose: the declaration for the AnimalShelter class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class AnimalShelter 
{
    public:
        // add a new dog breed in the animal shelter
        // if the key (breed) exists, add the set of dognames to the values of the breed
        // otherwise add the key and the set of dognames to the map
        // breed is the new dog breed
        // dognames are the set of dog names of the breed
        void insert(string breed, set<string> dognames);

        // person: the name of the person who wants to adopt a dog of breed
        // breed: the breed of the dog a person whats to adopt
        // if such breed exists, display the message: person is adopting <a dog's name> (breed)
        // and then delete the dog from the map
        // otherwise, display the message: person CANNOT adopt a breed.
        void validAdoption(string person, string breed);

        // check if the animal shelter is empty
        // return true if it is 
        // otherwise return false
        bool empty() const;

        // display all the animals currently in the shelter like this:
        // breed: [ dog_name1 dog_name2 ... ]
        void print() const;

    private:
        map<string, set<string> > BreedToNames; // a map from dog breed to names. 
        //Each dog breed is a key, and its values are set of dogs (their names) available of that breed 
};
#endif  /* ANIMALSHELTER_H */
