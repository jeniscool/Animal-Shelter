/*
//course: CS216-00x
//Project: Lab 11
//Purpose: to simulate adoptions of dogs at Lexington Animal Shelter
//         also provide example code for command line arguments, 
//         file input/output and parsing tokens seperated by semi-colon and comma
//         and test how to use map and set classes to define your own class
//Author: (your name)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "animalshelter.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Check whether the number of command line arguments is exactly one 
    if (argc != 2)
    {
        cout << "Warning: need exactly one command line argument." << endl;
        cout << "Usage: " << argv[0] << " <inputfile_name>" << endl;
        return 1;
    }

    ifstream in_file;
    in_file.open(argv[1]);
    // Check whether the input file can be open successfully or not
    if (!in_file.good())
    {
        cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        return 2;
    }
    // Read data from the input file: each line contains a breed:, then followed by dog names of this breed seperated by comma
    // store the data into AnimalShelter object
    AnimalShelter Lexington_AS;
    string line;
    while (getline(in_file, line))
    {
        string breed, dogName;
        istringstream iss(line);
        getline(iss, breed,':');
        // Extract extra white space
        iss>>ws;

        // create a new set of dog names associated with breed
        set<string> dogs_of_breed;
        
        while (getline(iss, dogName, ','))
        {
            dogs_of_breed.insert(dogName);
            // extract white space 
            iss>>ws;
        }
        
        // add the <breed, set of dog names> to the AnimalShelter object
        Lexington_AS.insert(breed, dogs_of_breed);

    }
    // close the input file
    in_file.close();

    // display the data from the AnimalShelter object
    cout << endl << "Here are the dogs currently at the Lexington Animal Shelter (sorted by breed): " << endl;
    Lexington_AS.print();

    // ask the user to type the adoptee file name
    cout << endl << "Please enter adoptee file name: ";
    string filename;
    getline(cin, filename);

    ifstream adoptionfile;
    adoptionfile.open(filename.c_str());
    // Check whether the adoption file can be open successfully or not
    if (!adoptionfile.good())
    {
        cout << "Warning: cannot open file named " << filename << "!" << endl;
        return 3;
    }

    // Read data from the adoption file: each line contains a person's name, then followed by breed seperated by semi-colon
    // check if the shelter can provide the available breed for adoption
    while (getline(adoptionfile, line))
    {
        string person, breed;
        istringstream iss(line);
        getline(iss, person, ';');
        iss>>ws;
        getline(iss, breed);

        Lexington_AS.validAdoption(person, breed);
    }
    // display the data from the AnimalShelter object after adoption
    cout << endl << endl << "Here are the dogs currently at the Lexington Animal Shelter (sorted by breed): " << endl;
    Lexington_AS.print();

    // close the adoption file
    adoptionfile.close();
    return 0;
}
