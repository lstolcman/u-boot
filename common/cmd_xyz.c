#include <common.h> 
#include <command.h> 
#include<net.h>

int do_connect(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) 
{ 
   char sendline[1024][3];
   int i;
   
   for(;;)
   {
      switch((int)recvline)
        {
	case 4:
	sendline[0][0]= 0x02
	sendline[0][1]= 0x00
	break;

        case 3:
	sendline[0][0]= 0x01
	sendline[0][1]= 0x01
        sendline[0][2]= 0x02
	goto change_status;
	break;
			
        case 2:
	printf("Server response");
        break;

        default:
        printf("Incorrect message");
	break;
        }	
   }

   change_status: 

return 0;
} 

U_BOOT_CMD( 
        connect,        1,      1,      do_connect, 
        "dgprino arguments", 
        "this is " 
); 
