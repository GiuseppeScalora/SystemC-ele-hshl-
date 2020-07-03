#include "systemc.h"
#include "testbench.hpp"
#include "engine_ctrl.hpp"



int sc_main(int argc, char* argv[])
{
Engine_ctrl engine_ctrl("engine_ctrl");
Tb testbench("testbench");

sc_signal<bool> reset_sig;
sc_signal<bool> stop_sig;
sc_signal<sc_uint<2>> useq_bus_sig;
sc_signal<bool> lddir_sig;
sc_signal<sc_uint<8>> tgl_cnt_sig;
sc_signal<bool> reverse_sig;
sc_signal<bool> xz_sig;

sc_clock  clk_sig("clk_sig", 500, SC_NS);

testbench.reset(reset_sig);
engine_ctrl.ctrl_fsm.reset(reset_sig);

testbench.stop(stop_sig);
engine_ctrl.ctrl_fsm.stop(stop_sig);

testbench.lddir(lddir_sig);
engine_ctrl.ctrl_fsm.lddir(lddir_sig);

testbench.useq_bus(useq_bus_sig);
engine_ctrl.inst_reg_proc.useq_bus(useq_bus_sig);

testbench.tgl_cnt(tgl_cnt_sig);
engine_ctrl.toggle_proc.tgl_cnt(tgl_cnt_sig);

testbench.reverse(reverse_sig);
engine_ctrl.inst_reg_proc.reverse(reverse_sig);

testbench.xz(xz_sig);
engine_ctrl.inst_reg_proc.xz(xz_sig);

testbench.clk(clk_sig);
engine_ctrl.inst_reg_proc.clk(clk_sig);
engine_ctrl.toggle_proc.clk(clk_sig);
engine_ctrl.ctrl_fsm_state.clk(clk_sig);
//engine_ctrl.ctrl_fsm.clk(clk_sig);

//execute the program
//engine_ctrl.engine_ctrl_main();
 sc_start();





return 0;

}

