#include <iostream>

#include "state_machine.h"


// FSM logic implementation
void stateMachine::process() {
    switch (currentState) {
        case Start:
            if (input.read() == 'G') currentState = G;
            else if(input.read() == 'A' || input.read() == 'C' || input.read() == 'T') currentState==Start;
            break;
        case G:
            if (input.read() == 'A') currentState = GA;
            else if (input.read() == 'G') currentState = G;
            else if(input.read() == 'T' || input.read() == 'C') currentState = Start;
            break;
        case GA:
            if (input.read() == 'A') currentState = GAA;
            else if (input.read() == 'G') currentState = G;
            else if(input.read() == 'T' || input.read() == 'C') currentState = Start;
            break;
        case GAA:
            if (input.read() == 'G') {
                currentState = GAAG;
                std::cout << "GAAG sequence detected!" << std::endl;
            }
            else if( input.read() == 'A' || input.read() == 'T' || input.read() == 'C') currentState = Start;
            break;
        case GAAG:
            if (input.read() == 'G') currentState = G;
            else if(input.read() == 'A' || input.read() == 'C' || input.read() == 'T') currentState==Start;
            break;
        default:
            currentState = Start; // Fallback to Start state in case of an undefined state
            break;
    }
}
