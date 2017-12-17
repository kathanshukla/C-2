#include <stdio.h>
#include <string.h>

/**
* Compile program:
*    gcc read5.c -o read5
*
* Run the program: 
*      $./read5 input.txt rain output.txt sun
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

   /* opening file for reading */
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


   while( fgets (line, (sizeof line), fp)!=NULL ) {

      /* remove \n from at the end of the str buffer*/   
      char * pos;
      if ((pos = strchr(line, '\n')) != NULL)
         *pos = '\0';

      /* print str enclosed in <> so we can see what str actually contains */
      //printf("Inside the loop, got the string: %s\n", line);

      //printing the strings with defined delimiters
      printf("<%s>\n", line);

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