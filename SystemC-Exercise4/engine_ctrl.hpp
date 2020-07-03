#ifndef _ENGINE_CTRL_
#define _ENGINE_CTRL_

#include<systemc.h>
#include"ctrl_fsm.hpp"
#include"ctrl_fsm_state.hpp"
#include"toggle_proc.hpp"
#include"inst_reg_proc.hpp"

SC_MODULE(Engine_ctrl)
{
 Ctrl_fsm ctrl_fsm;
 Toggle_proc toggle_proc;
 Inst_reg_proc inst_reg_proc;
 Ctrl_fsm_state ctrl_fsm_state;

 sc_signal<bool> ldinst_sig;
 sc_signal<bool> toggle_sig;
 sc_signal<bool> next_state_sig;
 sc_signal<bool> curr_state_sig;


 //void engine_ctrl_main();


 SC_CTOR(Engine_ctrl)

    :  ctrl_fsm("ctrl_fsm")
    ,  toggle_proc("toggle_proc")
    , inst_reg_proc("inst_reg_proc")
    , ctrl_fsm_state("ctrl_fsm_state")

	{
 	//SC_THREAD(engine_ctrl_main);
 	ctrl_fsm.ldinst(ldinst_sig);
 	ctrl_fsm.toggle(toggle_sig);
 	ctrl_fsm.next_state(next_state_sig);
 	ctrl_fsm.curr_state(curr_state_sig);
 
 	ctrl_fsm_state.next_state(next_state_sig);
	ctrl_fsm_state.curr_state(curr_state_sig);

 	toggle_proc.toggle(toggle_sig);

 	inst_reg_proc.ldinst(ldinst_sig);

	}

};

#endif
