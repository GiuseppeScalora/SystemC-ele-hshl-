# SystemC-ele-hshl-
Contained in this repository there is the program, written with the aid of the SystemC library for C++, that it is suppose to control a car engine and make it 
drive forward, backward, left and right with a simple 2-bit instruction. 
With this said, I will briefly explain what I did. I worked alongside with my colleague Adam Sulak, who helped me with the installation and the setup of the library in a linux WSL,
so the program is run on a Linux (ubuntu) terminal. Taking inputs from the structure diagram and the FSM given, I thought of creating a whole system that would contain the testbench
and the engine controller, which by consequence contains every single subsystem such as the "ctrl_fsm", "toggle_proc", "inst_reg_proc", "ctrl_fsm_state". These last mentioned subsystems
are simply the hardware components that form the whole engine controller ("engine_ctrl"). This last one, has a list of inputs and outputs that for testbenching purposes will be connected
to the respective inputs and outputs of the testbench in order to generate some random inputs to test the behaviour of the machine. (I attached a diagram to understand better what I 
am talking about).
It took me quite a few days, I will not lie, and I still did not manage to obtain the correct output from the testbench even if I managed to compile every single header file and .cpp file 
without errors. Due to the examination period I could not completely focus on it, but I am sure that if I had more time I could solve the problem. I am sorry if I did not manage to solve
the task in time.
