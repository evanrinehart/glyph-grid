#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define TITLE_BUFFER_SIZE 256

static struct option longopts[] = {
  {"window",     required_argument, NULL, 'w'},
  {"dimensions", required_argument, NULL, 'd'},
  {"fullscreen", no_argument,       NULL, 'f'},
  {"font-size",  required_argument, NULL, 's'},
  {"resizable",  no_argument,       NULL, 'r'},
  {"title",      required_argument, NULL, 't'},
  {NULL,         0,                 NULL,   0}
};

enum Mode {WINDOWED, FULLSCREEN, DIMENSIONED};

struct Config {
  enum Mode mode;
  int windowW;
  int windowH;
  int rows;
  int cols;
  int fullscreen;
  int resizable;
  int fontSize;
  char title[TITLE_BUFFER_SIZE];
};

static const char* showMode(enum Mode mode){
  switch(mode){
    case WINDOWED: return "WINDOWED";
    case DIMENSIONED: return "DIMENSIONED";
    case FULLSCREEN: return "FULLSCREEN";
    default: return "BAD MODE";
  }
}

struct Config parseOptions(int argc, char* argv[]){
  int opt;
  struct Config out = {DIMENSIONED, 0, 0, 25, 80, 0, 0, 12, "Glyph Grid"};

  for(;;){
    opt = getopt_long(argc, argv, "", longopts, NULL);
    if(opt == -1) break;
    else if(opt == 'w'){
      sscanf(optarg, "%dx%d", &out.windowW, &out.windowH);
      out.mode = WINDOWED;
    }
    else if(opt == 'd'){
      sscanf(optarg, "%dx%d", &out.rows, &out.cols);
      out.mode = DIMENSIONED;
    }
    else if(opt == 'f'){
      out.fullscreen = 1;
      out.mode = FULLSCREEN;
    }
    else if(opt == 's'){
      out.fontSize = atoi(optarg);
    }
    else if(opt == 'r'){
      out.resizable = 1;
    }
    else if(opt == 't'){
      strncpy(out.title, optarg, TITLE_BUFFER_SIZE);
    }
    else{
      exit(-1);
    }
  }

  return out;
}

/*
int main(int argc, char* argv[]){

  struct Config config = parseOptions(argc, argv);

  printf("title = %s\n", config.title);
  printf("resizable = %d\n", config.resizable);
  printf("fontSize = %d\n", config.fontSize);
  printf("mode = %s\n", showMode(config.mode));
  switch(config.mode){
    case WINDOWED:
      printf("windowW = %d\n", config.windowW);
      printf("windowH = %d\n", config.windowH);
      break;
    case DIMENSIONED:
      printf("rows = %d\n", config.rows);
      printf("cols = %d\n", config.cols);
      break;
    case FULLSCREEN:
      break;
  }

  return 0;
}
*/
