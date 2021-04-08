#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 9

//function prototypes
void setUp();
void gamePlay(char* randomizedArray[SIZE]);
void swap(int *i, int *j);

int main(){
  char input[64];
  printf("Welcome to Speed Typing.\n");
  printf("Type 'ready' to begin!\n");
  scanf("%s", input);
  
  if(strncmp(input, "ready", strlen(input)) == 0){
    setUp();
  }
  return 0;
}

void setUp(){
  bool used = true; //ensures that no word is used twice
  int randIndex = 0;
  const char *randomizedArray[SIZE]; //holds randomized output
  int usedIndices[SIZE]; //holds already used indices
  srand(time(NULL));
  
  //fill array with words
  const char *arr[SIZE];
  arr[0] = "the";
  arr[1] = "quick";
  arr[2] = "brown";
  arr[3] = "fox";
  arr[4] = "jumps";
  arr[5] = "over";
  arr[6] = "the";
  arr[7] = "lazy";
  arr[8] = "dog";

  //select a random number for the index
  for(int i = 8; i > 0; i--){
    randIndex = rand()%i+1;
    swap(&i, &randIndex);
    strncpy(randomizedArray[i], arr[randIndex], SIZE);
    printf("randomizedArray[i] = %s\n", randomizedArray[i]);
  }

  gamePlay(randomizedArray);
}

void swap(int *i, int *j){
  int temp = 0;
  temp = *i;
  *i = *j;
  *j = temp;
}

void gamePlay(char* randomizedArray[SIZE]){
  char input[64];
  //start timer here
  for(int i = 0; i < SIZE; i++){
    while(strncmp(input, randomizedArray[i], SIZE) != 0){
      printf("Word #%d is: %c", i, randomizedArray[i]);
      scanf("%c", input);
    }
  }
  //end timer here
  
}
