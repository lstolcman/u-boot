#include <common.h> 
#include <command.h> 
#include<net.h>

int do_connect(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) 
{ 
<<<<<<< HEAD
   char sendline[1024][3];
   char recvline[1024];
   
   for(;;)
   {
      switch((int)recvline)
        {
	case 4:
	sendline[0][0]= 0x02;
	sendline[0][1]= 0x00;
	break;

        case 3:
	sendline[0][0]= 0x01;
	sendline[0][1]= 0x01;
        sendline[0][2]= 0x02;
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
=======
>>>>>>> 8a86d574bf64a686e236176e061cf3700359392f

return 0;
} 

U_BOOT_CMD( 
        connect,        1,      1,      do_connect, 
        "dgprino arguments", 
        "this is " 
); 
