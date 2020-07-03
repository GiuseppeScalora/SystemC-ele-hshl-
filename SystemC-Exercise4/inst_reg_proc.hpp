#ifndef _INST_REG_PROC_
#define _INST_REG_PROC_

#include<systemc.h>

SC_MODULE(Inst_reg_proc){
 sc_in<sc_uint<2>> useq_bus;
 sc_in<bool> clk;
 sc_in<bool> ldinst;
 sc_out<bool> reverse;
 sc_out<bool> xz;


void reg_proc();

SC_CTOR(Inst_reg_proc){
 SC_CTHREAD(reg_proc, clk.pos());
 sensitive<<useq_bus<<ldinst;
  }
};

#endif
