#include"testbench.hpp"
#include<iomanip>
#include<iostream>

void Tb::monitor(){
std::cout << std::setw(4)<<"lddir: ";
std::cout << std::setw(3)<<"tgl_counter: ";
std::cout << std::setw(3)<<"XZ: ";
std::cout << std::setw(3)<<"reverse: ";
std::cout << std::setw(3)<<"reset: ";
std::cout << std::setw(3)<<"stop: ";
std::cout << std::setw(3)<<"useq_bus: "<<"\n";

for(;;){
    std::cout<<std::setw(4)<<lddir.read();
    std::cout<<std::setw(3)<<tgl_cnt.read();
    std::cout<<std::setw(3)<<xz.read();
    std::cout<<std::setw(3)<<reverse.read();
    std::cout<<std::setw(3)<<reset.read();
    std::cout<<std::setw(3)<<stop.read();
    std::cout<<std::setw(3)<<useq_bus.read()<<"\n";
    wait(20, SC_NS);
    }
} 

void Tb::test_inp_reset(){
  for(int i=0;i<128;i++)
   {
    if (i>0 && i<50)
     { 
       reset.write(0);
       stop.write(0);
    }
       else if (i > 50 && i < 100)
       {
        stop.write(0);
        reset.write(1);
       }
        else if (i>100 && i < 128)
        {
        reset.write(0);
        stop.write(1);
        }
   wait(20, SC_NS);   

   }
 
}

void Tb::test_c_inp(){
   for(int i=0;i<128;i++)
   {
    if (i>0 && i<32)
     { 
       useq_bus.write(0);
    }
       else if (i > 32 && i < 64)
       {
        useq_bus.write(1);
       }
        else if (i > 64 && i < 96)
        {
         useq_bus.write(2);
        
        }

        else if (i > 96 && i < 128)
		{useq_bus.write(3);}
    wait();   

   }
    
}
