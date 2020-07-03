#ifndef _TESTBENCH_
#define _TESTBENCH_
#include"systemc.h"

SC_MODULE(Tb){
sc_out<bool> reset;
sc_out<bool> stop;
sc_out<sc_uint<2>> useq_bus;
sc_in<bool> lddir;
sc_in<sc_uint<8>> tgl_cnt;
sc_in<bool> reverse;
sc_in<bool> xz;
sc_in<bool> clk;

void test_inp_reset();
void test_c_inp();
void monitor();

SC_CTOR(Tb){
 SC_CTHREAD(test_c_inp, clk.pos());
 SC_THREAD(test_inp_reset);
 SC_CTHREAD(monitor, clk.pos());
 sensitive<< lddir << tgl_cnt << reverse << xz;
 }
};
#endif

