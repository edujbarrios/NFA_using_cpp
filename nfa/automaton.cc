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

#include "automaton.h"
///Command This is a pointer used for pointing the object for which the member function is called.
automaton::automaton(int state_identifier, bool acceptance_state){
    this->State_identifier = state_identifier;
    this->Acceptance_state = acceptance_state;
    Number_of_states=0;
}

void automaton::Set_transitions(char c, int destination){
    std::pair<char,int> p = std::make_pair(c, destination);
    transitions.push_back(p);
    Number_of_states ++;
}