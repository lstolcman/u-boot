#include <common.h> 
 #include <command.h> 


int do_dgprint(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) 
{ 
        printf("Hi this is a test\n"); 
        return 0; 
} 

U_BOOT_CMD( 
        dgprint,        1,      1,      do_dgprint, 
        "dgprint takes no arguments", 
        "this is just to test a function" 
); 