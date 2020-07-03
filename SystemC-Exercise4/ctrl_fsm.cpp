#include"ctrl_fsm.hpp"

void Ctrl_fsm::ctrl_main()
{ 
 for(;;)
{
  if (reset.read()){
     lddir.write(0);
     
     toggle.write(0);
     
     ldinst.write(0);
     
     next_state.write(0);
     
     }
     
  else if (curr_state.read())
 	{
          toggle.write(1);
 	  
 	  ldinst.write(1);
 	  
 	  lddir.write(1);
 	 
	  next_state.write(1);
          
        }
  	else if (stop.read())
     		{
      		  toggle.write(0);
     		}
     wait(20, SC_NS);
   }
}

