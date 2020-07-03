#ifndef _TOGGLE_PROC_
#define _TOGGLE_PROC_

#include"systemc.h"


SC_MODULE(Toggle_proc){
sc_in<bool> clk;
sc_in<bool> toggle;
sc_out<sc_uint<8>> tgl_cnt;


void tgl_counter();

SC_CTOR(Toggle_proc)
{ 
 SC_CTHREAD(tgl_counter, clk.pos());

 sensitive << toggle;
}
  
};  
#endif

