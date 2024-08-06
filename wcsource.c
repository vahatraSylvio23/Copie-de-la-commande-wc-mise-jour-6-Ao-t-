#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wcheader.h"
int main(int argc , char* argv[])
{
    FILE *file;
    file=NULL;
    int i;
    tot *total;
    total = (tot*)malloc(sizeof(tot)*argc);

        if(argc == 1)
        {
            wc_no_opt(file);
            }
            
        else if(strcmp(argv[1] , "-c") == 0)
        {
            for(i = 1 ; i<argc-1 ; i++)
            {    
            open(file , argv[i+1]);
            wc_option_c(file , argv[i+1] ,total);
            if(file != NULL)
            {
                fclose(file);
                }
            }
            if(argc > 3)
            print_total_c(total ,argc);
        }
        else if(strcmp(argv[1] , "-l") == 0)
        {
            for(i = 1 ; i<argc-1 ; i++)
            {   
            open(file , argv[i+1]);
            wc_option_l(file , argv[i+1] ,total);
            if(file != NULL)
            {
                fclose(file);
                }    
            }    
            if(argc > 3)
            print_total_l(total ,argc);
            }
        else if(strcmp(argv[1] , "-w") == 0)
        {
            for(i = 1 ; i<argc-1 ; i++)
            {    
            open(file , argv[i+1]);
            wc_option_w(file , argv[i+1] ,total);
            if(file != NULL)
            {
                fclose(file);
                }
            }

            if(argc > 3)
            print_total_w(total ,argc);
            }
        
        else if(strcmp(argv[1] , "-L") == 0)
        {
            for(i = 1 ; i<argc-1 ; i++)
            {    
            open(file , argv[i+1]);
            wc_option_L(file , argv[i]);
            if(file != NULL)
            {
                fclose(file);
                }  
            }
            }
            
        else if(strcmp(argv[1] , "--help") == 0)
        {
            wc_help(file);
            }
            
        else if(strcmp(argv[1] , "-c") != 0 || strcmp(argv[1] , "-w") != 0 || strcmp(argv[1] , "-l") != 0  ||   strcmp(argv[1] , "-L") != 0  ||  strcmp(argv[1] , "--help") != 0)
        {
            for(i = 1 ; i<argc ; i++)
            {
            open(file , argv[i]);
            word_count(file , argv[i] ,total);
            }
            if(argc > 2)
            print_total(total ,argc);
        }
}












