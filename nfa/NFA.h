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

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "automaton.h"

class NFA{
public:

  /// Constructor for NFA. Creates the NFA and initializes the data
    NFA();
  /// Frees the memory allocated for the automatum
    ~NFA();
   /// Funciton to add a automaton to the NFA. Pass the new automaton node to the funciton to 
    ///add it to the NFA
    void Add_automatum (automaton* node);
   /// Set the initial state of the NFA
    void Set_start_point(int initial_identifier);
   /// Funciton to consume the string and return if the string was rejected or accepted by the NFA
    bool Consume_string(std::string s);

private:
   
   /// the set up of the seeker that look up for the initial identifier
    int Initial_identifier;
    ///The NFA map holding the data
    std::map<int, automaton*> nfa;

};

#endif //NFA_H