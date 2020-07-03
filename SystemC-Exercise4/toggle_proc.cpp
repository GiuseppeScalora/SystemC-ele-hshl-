#include"toggle_proc.hpp"

void Toggle_proc::tgl_counter()
{


 int tgl_cnt1 = 0;
while(true)
 {
 toggle.read();
 if (toggle == 1)
    {
     tgl_cnt1++;
     tgl_cnt = tgl_cnt1;
     cout<<"@"<<sc_time_stamp()<<"the toggle counter is: "<< tgl_cnt << endl;
     if (tgl_cnt.read() > 255)
         tgl_cnt1 = 0;
    }
    wait();}

}
