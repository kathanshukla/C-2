#include <stdio.h>
#include <string.h>

/**
* Compile program:
*    gcc readx.c -o readx
*
* Run the program: 
*      $./readx input.txt rainy output.txt sunny
*
*/
int main (int argc, char **argv) {
   FILE *fp, *fo;
   char *compare, *replace;
   char line[246];

   if (argc <= 4){
      printf(">Missing arguments on the command line.\n");
      printf(">Be sure you run the program as\n\"./read3 input.txt compare outout.txt replace\"\n\n");
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
      return 1;  //TODO check if: return 1 because it was expected, right?
   }
   replace = argv[4];

   /*
   printf(); made to test version 2
   //printf("We are going to compare %s\n", compare);
   //printf("We are going to replace it with %s\n", replace);
   */

   printf("1st: Reads input.txt, removes '\\n' from fgets, and prints it \n");
   printf("2nd: Compares each line with 'rainy' \n");

   while( fgets (line, (sizeof line), fp)!=NULL ) {
      //$./readx input.txt rain output.txt sun
      line[strcspn(line, "\n")] = 0;
      /* strcspn :: Locate first occurrence of character in string
         after locating the first occurrence of \n, replaces it by 0.

::: https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input/28462221#28462221
      */ 

      //printf("<%s>\n", line);
      /*
      <cloudy>
      <rainy>
      <chilly>
      <rainy>
      <rainy > 
      */
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