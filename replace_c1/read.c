#include <stdio.h>
#include <string.h>

/**
* How to compile program:
*    gcc read.c -o read
*
* How to run the program: 
*      .> ./read input.txt rainy output.txt sunny
* (On Windows MinGW compiler, simply: 
*      .> read input.txt rainy output.txt sunny - without ./)
*
*/
int main (int argc, char **argv) {
   FILE *fp, *fo;
   char *compare, *replace;
   char line[246];

   if (argc <= 4){
      printf(">Missing arguments on the command line.\n");
      printf(">Be sure you run the program as\n\"./read input.txt compare outout.txt replace\"\n\n");
   }

   /* Opening files for reading */
   fp = fopen(argv[1] , "r");
   if(fp == NULL){
      perror("Error opening input file");
      return 1;
   }
   compare = argv[2];

   fo = fopen(argv[3], "w");
   if(fo == NULL){
      perror("Error opening output file");
      return 1; 
   }
   replace = argv[4];

   while( fgets (line, (sizeof line), fp)!=NULL ) {
      line[strcspn(line, "\n")] = 0;
       if(strcmp(compare, line) == 0){
         printf("Found it! %s \n", line);
         fprintf(fo, "%s\n", replace);
      }
      else{
         fprintf(fo, "%s\n", line);
      } 
   }
   fclose(fp);
   fclose(fo);
   return 0;
}

/* 
Important info

strcspn :: 
Locate first occurrence of character in string, 
after locating the first occurrence of \n, replaces it by 0.
   

Sources::
https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input/28462221#28462221

Used to debug:
.>printf("1st: Reads input.txt, removes '\\n' from fgets, and prints it \n");
.>printf("2nd: Compares each line with 'rainy' \n");


.>printf("<%s>\n", line);

*/