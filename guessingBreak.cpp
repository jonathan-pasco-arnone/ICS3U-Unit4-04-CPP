// Copyright (c) 2020 Jonathan Pasco-Arnone all rights reserved
//
// Created by Jonathan Pasco-Arnone
// Created on December 2020
// This program generates a random number and makes the user
// keep guessing until they get it

#include <iostream>
#include <random>

int main() {
    // This function generates a random number and makes the user
    // keep guessing until they get it

    std::string numberStr;
    int number;
    int generatedNumber;

    std::cout << "" << std::endl;
    std::cout << "This program generates a number, from 0 to 9, and makes the"
          " user guess it over and over until they get it" << std::endl;
    std::cout << "" << std::endl;

    // Random number code
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    generatedNumber = idist(rgen);

    while (true) {
        std::cout << "What is your guess: ";
        std::cin >> numberStr;
        try {
            number = std::stoi(numberStr);
            if (generatedNumber == number) {
                std::cout << "That Guessed Correctly" << std::endl;
                break;
            } else {
                std::cout << "Sorry, Try Again" << std::endl;
            }
        } catch (std::invalid_argument) {
        std::cout << "Invalid Input, Try Again";
        std::cout << "" << std::endl;
        }
        std::cout << "" << std::endl;
    }
}
