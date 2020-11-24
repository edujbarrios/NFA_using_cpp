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

#include "NFA.h"

///constructor
NFA::NFA(){
    ///setting up the initial identifier up to the value -1 to make possible a 'return false'
    ///just in case this value appears
    Initial_identifier = -1;
}
///frees the memory
NFA::~NFA(){
}
void NFA::Add_automatum (automaton* node){
    const int curr_identifier = node->State_identifier;
    nfa[curr_identifier] = node;
}
///Setting the start point of the NFA, identifying the initial element
void NFA::Set_start_point(int initial_identifier){
    this->Initial_identifier = initial_identifier;
}

bool NFA::Consume_string(std::string s){

   std::vector<int> possible_automaton;

    if (Initial_identifier == -1) return false;

    possible_automaton.push_back(Initial_identifier);

    for (int counter=0; counter<s.size(); counter++){
        char c = s[counter];
/// where ~ is the empty element, if character == empty space return a break
        if(c == '~'){
            break;
        }
        ///declaration of possible number of automaton per character is equal to the possible size
        int no_of_possible_automaton_per_char = possible_automaton.size();

        for (int j=0; j<no_of_possible_automaton_per_char; j++){
            int current_identifier = possible_automaton[0];

            automaton* current_automatum = nfa[current_identifier];

            for (int k=0; k<current_automatum->Number_of_states; k++){
                if ( ((current_automatum->transitions)[k]).first == c ){
                    int taken = ((current_automatum->transitions)[k]).second; 
                    possible_automaton.push_back( taken );
                }
            }

            possible_automaton.erase( possible_automaton.begin() );
        }

    }

    int final_size = possible_automaton.size();
    if ( final_size == 0 ){
        return false;
    }else{
        for (int counter1=0; counter1<final_size; counter1++){
            int curr_identifier = possible_automaton[counter1];
            if ( nfa[curr_identifier]->Acceptance_state == true ){
                return true;
            }
        }
        return false;
    }
}