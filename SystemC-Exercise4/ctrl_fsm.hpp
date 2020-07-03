#ifndef _CTRL_FSM_
#define _CTRL_FSM_

#include<systemc.h>


SC_MODULE(Ctrl_fsm){
sc_in<bool> curr_state;
sc_in<bool> stop;
sc_in<bool> reset;
sc_out<bool> lddir;
sc_out<bool> ldinst;
sc_out<bool> toggle;
sc_out<bool> next_state;

void ctrl_main();

SC_CTOR(Ctrl_fsm){
 SC_THREAD(ctrl_main);
 sensitive << stop << reset << curr_state;
 }
};

#endif
