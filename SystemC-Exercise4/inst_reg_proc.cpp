#include"inst_reg_proc.hpp"

void Inst_reg_proc::reg_proc()
{
while(1)
   {
    ldinst.read();
 	if (ldinst == 1)
   		{ 
    		int useq_bus1 = useq_bus.read();
    		switch(useq_bus1)
    			{
    				case 0:
      				xz.write(0);
      				reverse.write(0);
      				break;
     
     				case 1:
      				xz.write(0);
      				reverse.write(1);
      				break;
    
     				case 2:
      				xz.write(1);
      				reverse.write(0);
      				break;
     
     				case 3:
      				xz.write(1);
      				reverse.write(1);
      				break;
     
    			}
   		} 
  	wait();
   }
}
