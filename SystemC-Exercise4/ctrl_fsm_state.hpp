#ifndef _CTRL_FSM_STATE_
#define _CTRL_FSM_STATE_
#include<systemc.h>


SC_MODULE(Ctrl_fsm_state){
sc_in<bool> next_state, clk;
sc_out<bool> curr_state;


void save_state();

SC_CTOR(Ctrl_fsm_state){
  SC_CTHREAD(save_state, clk.pos());
  sensitive << next_state;
  }
};  
#endif