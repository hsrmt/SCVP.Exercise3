#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

SC_MODULE(stateMachine) {
public:
    sc_in<char> input; // DNA base input
    sc_in<bool> clk;  // Clock input

    // Constructor
    SC_CTOR(stateMachine){
        SC_METHOD(process);
        sensitive << clk.pos();
        dont_initialize();
    }

    // State enumeration
    enum base {Start, G, GA, GAA, GAAG};

private:
    void process(); // FSM logic

    // Current state variable
    base currentState;
};

#endif // STATE_MACHINE_H
