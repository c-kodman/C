//Craig Kodman cmk126
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(FILE *file);

void usage(){//error message and ends program
  printf("Usage: ./MyStrings filename");
  exit(0);
}

int main(int argc, char* argv[]){
  if(argc < 2){//if not given full information to start program send to error message
    usage();
  }
  FILE* file = fopen(argv[1], "rb");//
  if(file == NULL){
    printf("Your file does not exist.  Please try again and enter a proper filename.");
    usage();
  }
  while(!feof(file)){//
      int count = 0;
      char character = fgetc(file);
      char c_array [4];
      while(32 < character && character < 126){//is character valid ascii? then place in array and grab another character
          c_array[count] = character;
          count++;
          character = fgetc(file);
          if(count==4){//once array has 4 valid ascii print.
              printf("%c%c%c%c", c_array[0], c_array[1], c_array[2], c_array[3]);
              count=0;
              while(32 < character && character < 126){//if after 4 characters, still grabbing valid characters, print
                  printf("%c", character);
                  character = fgetc(file);
              }
              printf("\n");
          }
      }

  }
  fclose(file);
 }
