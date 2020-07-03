#include"ctrl_fsm_state.hpp"


void Ctrl_fsm_state::save_state(){
 for(;;)
{  
 bool saved_state;

 saved_state = next_state.read();
 curr_state.write(saved_state);
 wait();
 }
 
 }
