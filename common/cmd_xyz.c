#include <common.h> 
#include <command.h> 
#include<net.h>

int do_connect(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) 
{ 

return 0;
} 

U_BOOT_CMD( 
        connect,        1,      1,      do_connect, 
        "dgprint takes no arguments", 
        "this is just to test a function" 
); 
