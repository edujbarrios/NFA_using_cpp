/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Eduardo José Barrios García
 * @date 20 Nov 2020
 * @brief Implementation of the non deterministic finite automata using oop's and C++ Language
 
**/

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class automaton{

public:
    /*
    Funciton to create an automaton. This creates and initializes the automaton
    with the the provided state identifier and acceptance level. State identifier
    is the unique identifier for each node. Acceptance state: 0 - For no acceptance
    1 - For acceptance.  
    */
    automaton(int state_identifier, bool acceptance_state);


    ///Function to add transitions to the automaton. 
   /// Input: char c: Character to which the transistion will be done
         ///  int destination: The state it will move once char c is encountered
    //This function is used  whenever to add a state transition to the automaton.
    void Set_transitions(char c, int destination);
    
    /*
    Unique state identifier
    */
    int State_identifier;


   /// Acceptance state of the automaton
    bool Acceptance_state;

    ///Number of transitions in the automaton
    int Number_of_states;

    /*
    List of transitions of the automaton
    */
    std::vector< std::pair<char, int> > transitions;
};

#endif //AUTOMATON_H