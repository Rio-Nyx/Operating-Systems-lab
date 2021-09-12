<<<<<<< HEAD
=======
/*       A
 *    B    C 
 *  D E F    G 
 *  H
 *  I
 * */

>>>>>>> 1730dfb6c8371d91f5fb9d15b2ea05a50ee5a31b
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
<<<<<<< HEAD
=======
#include <sys/wait.h>
>>>>>>> 1730dfb6c8371d91f5fb9d15b2ea05a50ee5a31b

void print(char c){
    printf("%c Child id: %d and Parent id: %d\n",c,getpid(),getppid());
}

void process_tree(){
    int pid_a, pid_b, pid_c, pid_d, pid_e, pid_f, pid_g, pid_h, pid_i;
    pid_b = fork();
    if(pid_b == 0){
        pid_d = fork();
        if(pid_d == 0){
            pid_h = fork();
            if(pid_h == 0){
                pid_i = fork();
                if(pid_i == 0){
                    print('i');
                    
                }
                else{
                    print('h');
                    
                }
            }
            else{
                print('d');
                
            }
        }
        else{
            pid_e = fork();
            if(pid_e == 0){
                print('e');
                
            }
            else{
                pid_f = fork();
                if(pid_f == 0){
                    print('f');
                    
                }
                else{
                    print('b');
                    
                }
            }
        }
    }
    else{
        pid_c = fork();
        if(pid_c == 0){
            pid_g = fork();
            if(pid_g==0){
                print('g');
                
            }
            else{
                print('c');
                
            }
        }
        else{
            print('a');
            
        }
    }
    for(int i=0; i<3; i++) 
<<<<<<< HEAD
   wait(NULL); 
=======
       wait(NULL); 
>>>>>>> 1730dfb6c8371d91f5fb9d15b2ea05a50ee5a31b
}

int main(){
    process_tree();
    return 0;
}
