#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wcheader.h"

/*--------------------------------------------------------------------------------------*/
void open(FILE* file , char* argv)
{
    file=fopen(argv ,"r");
	if(file == NULL)
	{
			printf("unable to open the file\n");		
    }
    else
    {

    }
}

/*--------------------------------------------------------------------------------------*/
/*allocation for the structure*/
void alloc(tot *total ,int argc)
{
    total=NULL;
    total=(tot*)malloc(sizeof(tot)*argc);
    if(total == NULL)
    {
        //printf("erreur d'allocation !!");
    }
}


/*--------------------------------------------------------------------------------------*/
/*the wc command without option*/
void word_count(FILE* file , char *argv ,tot *total)
{   
    file=fopen(argv ,"r");
    char car[100000];
    int i=0;
    int characters=0 ,lines=0 ,words=0;

        while(feof(file) != 1)
        {
            fscanf(file , "%s" ,car);
            words++;
        }
            total[i].word += words;
            i++;        
            rewind(file);
        while(feof(file) != 1)
        {
            fgets(car , 255 , file);
            lines ++ ;
        }
            total[i].line += lines;
            i++;
        rewind(file);
        while(feof(file) != 1)
        {    
            fgetc(file);
            characters ++ ;
        }
            total[i].car += characters ;
            i++;        
            rewind(file);
    printf("There are :\n%d characters %d words %d lines in %s\n",characters-1  ,words-1 ,lines-1 ,argv);
}


/*--------------------------------------------------------------------------------------*/
/*with the -c option */
void wc_option_c(FILE *file , char *argv ,tot *total)
{    
    file=fopen(argv ,"r");
    char car[100000];
    char *cara;
    int i=0;
    int characters=0 ,lines=0 ,words=0;

        while(feof(file) != 1)
        {
            fscanf(file , "%s" ,car);
            words++;
        }
            total[i].word += words;
            i++;        
            rewind(file);
        while(feof(file) != 1)
        {
            fgets(car , 255 , file);
            lines ++ ;
        }
            total[i].line += lines;
            i++;
        rewind(file);
        while(feof(file) != 1)
        {    
            fgetc(file);
            characters ++ ;
        }
            total[i].car += characters ;
            i++;        
            rewind(file);
        printf("There are :\n%d characters in %s\n",characters-1 , argv);
    
}
/*--------------------------------------------------------------------------------------*/
/*with the -w option*/
void wc_option_w(FILE *file , char *argv ,tot *total)
{    
    file=fopen(argv ,"r");
    char car[100000];
    char *cara;
    int i=0;
    int characters=0 ,lines=0 ,words=0;

        while(feof(file) != 1)
        {
            fscanf(file , "%s" ,car);
            words++;
        }
            total[i].word += words;
            i++;        
            rewind(file);
        while(feof(file) != 1)
        {
            fgets(car , 255 , file);
            lines ++ ;
        }
            total[i].line += lines;
            i++;
        rewind(file);
        while(feof(file) != 1)
        {    
            fgetc(file);
            characters ++ ;
        }
            total[i].car += characters ;
            i++;        
            rewind(file);
        printf("There are :\n%d words in  %s \n",words-1 ,argv);
}

/*--------------------------------------------------------------------------------------*/
/*with the -l option */
void wc_option_l(FILE *file , char *argv ,tot *total)
{
    file=fopen(argv ,"r");
    char car[100000];
    int i=0;
    int characters=0 ,lines=0 ,words=0;

        while(feof(file) != 1)
        {
            fscanf(file , "%s" ,car);
            words++;
        }
            total[i].word += words;
            i++;        
            rewind(file);
        while(feof(file) != 1)
        {
            fgets(car , 255 , file);
            lines ++ ;
        }
            total[i].line += lines;
            i++;
        rewind(file);
        while(feof(file) != 1)
        {    
            fgetc(file);
            characters ++ ;
        }
            total[i].car += characters ;
            i++;        
            rewind(file);
        printf("There are :\n%d lines in %s\n",lines-1 , argv);
}


/*--------------------------------------------------------------------------------------*/
/*showing the total numbers of characters */
void print_total_c(tot *total , int argc)
{
    int i;
    int totcar=0,totwor=0 ,totlin=0;
    for(i=0 ; i<argc ; i++)
    {
        totcar += total[i].car;
        totwor += total[i].word;
        totlin += total[i].line;
    }
        printf("total : %d characters\n",totcar-argc+2) ;

}



/*--------------------------------------------------------------------------------------*/
/*showing the total numbers of words */
void print_total_w(tot *total , int argc)
{
    int i;
    int totcar=0,totwor=0 ,totlin=0;
    for(i=0 ; i<argc ; i++)
    {
        totcar += total[i].car;
        totwor += total[i].word;
        totlin += total[i].line;
    }
        printf("total :%d words\n",totwor-argc+2) ;

}



/*--------------------------------------------------------------------------------------*/
/*showing the total numbers of words*/
void print_total_l(tot *total , int argc)
{
    int i;
    int totcar=0,totwor=0 ,totlin=0;
    for(i=0 ; i<argc ; i++)
    {
        totcar += total[i].car;
        totwor += total[i].word;
        totlin += total[i].line;
    }
        printf("total : %d lines \n",totlin-argc+2) ;
}


/*--------------------------------------------------------------------------------------*/
/*showing the total numbers of characters words and lines  with no option*/
void print_total(tot *total , int argc)
{
    int i;
    int totcar=0,totwor=0 ,totlin=0;
    for(i=0 ; i<argc ; i++)
    {
        totcar += total[i].car;
        totwor += total[i].word;
        totlin += total[i].line;
    }
        printf("total : %d characters %d words %d lines \n",totcar-argc+1,totwor-argc+1,totlin - argc+1) ;
}


/*--------------------------------------------------------------------------------------*/
/*the option -L that shows the maximum length*/
void wc_option_L(FILE *file , char *argv)
{
    file=fopen(argv , "r");
    char chaine[100000];
    char maximum[100000000];
    typedef struct max_length
    {
        char max[100000000];
    }len;
    len str[100000000];
    int i=0 , j , k ;
    while(feof(file) != 1)
    {
        fgets(chaine , 255 , file);
        strcpy(str[i].max , chaine);
        i++;
        }
        for(j=0 ; j < i  ; j++ )
        {
            for(k=j+1 ; k<i ; k++)
            {
                if(strlen(str[j].max) > strlen(str[k].max))
                strcpy(maximum ,str[k].max) ; 
                }
        }
    printf("the longest string is  : \n%s",maximum);
    }
  
    
/*--------------------------------------------------------------------------------------*/
/*if no option is typed*/ 
void wc_no_opt(FILE *file)
{
            fprintf(stderr , "Usage wc [opt] <filename>\n");
            exit(EXIT_SUCCESS);  
    }
    
    void wc_help(FILE *file)
    {
        fprintf(stderr , "usage : wc [option] [path to file]\n option : \n -c print the numbers of characters \n -w print the numbers of words\n -l print the number of lines\n -L print the longest lines width  ");
        
        exit(EXIT_SUCCESS); 
        }