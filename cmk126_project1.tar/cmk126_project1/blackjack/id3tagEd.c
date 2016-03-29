#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(FILE *file);
void parse_command(char** argv , int argc);

void usage(){
  printf("Usage: ./id3tagEd FILENAME -Field Value for any number of field value pairs.");
  exit(0);
}

struct mp3{
  char tag[3];
  char song_title[30];
  char artist[30];
  char album[30];
  char year[4];
  char comment[28];
  char zero_byte;
  char track_number;
  char genre;
} m;

int main(int argc, char* argv[]){
  if(argc < 2){
    usage();
  }
  FILE* file = fopen(argv[1], "r+b");
  if(file == NULL){
    printf("Your file does not exist.  Please try again and enter a proper filename.");
    usage();
  }
  fseek(file, -128, SEEK_END);
  fread(&m, sizeof(struct mp3), 1, file);
  parse_command(argv, argc);
  if(strncmp(m.tag, "TAG", 3) ==0){
    //printf("Tag ID: %s \n", m.tag);
    printf("Song title: %s \n", m.song_title);
    printf("Artist name: %s \n", m.artist);
    printf("Album name: %s \n", m.album);
    printf("Year: %c%c%c%c \n", m.year[0], m.year[1], m.year[2], m.year[3]);
    printf("Comment: %s \n", m.comment);
    printf("zero byte: %d \n", m.zero_byte);
    printf("Track number: %d \n", m.track_number);
    printf("Genre: %c \n", m.genre);

    save(file);
  }
  else{
    printf("There is no tag.");
  }
}

void parse_command(char** argv , int argc) {
    int i;
    for(i=2; i < argc; i+=2){
        if(strcmp(argv[i], "-title" ) == 0) {
            char title[30];
            if(i+1 > argc) {
                usage();
                exit(0);
            }
            strcpy(m.song_title, argv[i+1]);
        }
        else if(strcmp(argv[i], "-artist" ) == 0){
            char artist[30];
            if(i+1 > argc){
                usage();
                exit(0);
            }
            strcpy(m.artist, argv[i+1]);

        }
        else if(strcmp(argv[i], "-album")==0){
            char album[30];
            if(i+1 > argc){
                usage();
                exit(0);
            }
            strcpy(m.album, argv[i+1]);
        }
        else if(strcmp(argv[i], "-year")==0){
            char year[4];
            if(i+1 > argc){
                usage();
                exit(0);
            }
            m.year[0] = argv[i+1][0];
            m.year[1] = argv[i+1][1];
            m.year[2] = argv[i+1][2];
            m.year[3] = argv[i+1][3];

            strcpy(m.year, argv[i+1]);
        }
        else if(strcmp(argv[i], "-comment")==0){
            char comment[28];
            if(i+1 > argc){
                usage();
                exit(0);
            }
            strcpy(m.comment, argv[i+1]);
        }
        else if(strcmp(argv[i], "-track")==0) {
            m.track_number = (char) atoi(argv[i+1]);
        }
        else{
            usage();
            exit(0);
        }
    }
}

void save(FILE *file){
    fseek(file, -128, SEEK_END);
    fwrite(&m, sizeof(struct mp3), 1, file);
}
/*
tag.m{
  fseek(id3tag, -128L, SEEK_END);
  fread(tag, 3, 128, id3tag);
  printf('Enter new title; \n');
  fwrite(tag, 3, 128, id3tag);
}*/
/*
//m.tag = "whatever";
strcpy(m.tag, "whatever");
//m.song_title = "whatever";
printf("What would you like to change in the mp3?  Options are:
title, artist, album, year, comment or track.  Use exactly those options.");
scanf("%s", option);

if(strcmp(option, "title") ==0){
  printf("What is the new title?");
  scanf("%s", title);
  strcpy(m.song_title, title);
  }
else if(strcmp(option, "artist") ==0){
  printf("What is the new artist name?");
  scanf("%s", artist);
  strcpy(m.artist, artist);
  }
else if(strcmp(option, "year") ==0){
  printf("What is the year?");
  scanf("%d", year);
  strcpy(m.year, year);
}
else if(strcmp(option, "album") ==0){
  printf("What is the album?");
  scanf("%s", album);
  strcpy(m.artist, artist);
  }
*/
