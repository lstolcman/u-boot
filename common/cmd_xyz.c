#include <common.h> 
<<<<<<< HEAD
#include <command.h> 
#include<net.h>


int do_connect(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) 
{ 
   char sendline[1024][3];
   int i;
   net_init()


   i = net_send_udp_packet(sendline, 10.0.0.1, 8080 , 9090, 1024);
   sendline[0][0] = 0x01;
   sendline[0][1] = 0x02;
   semdline[0][1] = 0x01;
   


   while (1)
   {

      net_process_received_packet(uchar *in_packet, int len)
      switch((int)recvline)
        {
	case 4:
	sendline[0][0]= 0x02
	sendline[0][1]= 0x00
        i = net_send_udp_packet(sendline, 10.0.0.1, 8080 , 9090, 1024);
	break;

        case 3:
	sendline[0][0]= 0x01
	sendline[0][1]= 0x01
        sendline[0][2]= 0x02
        i = net_send_udp_packet(sendline, 10.0.0.1, 8080 , 9090, 1024);
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

return 0;
} 

U_BOOT_CMD( 
        connect,        1,      1,      do_connect, 
        "dgprint takes no arguments", 
        "this is just to test a function" 
); 
