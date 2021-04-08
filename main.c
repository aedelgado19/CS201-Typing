/* Author: Allison Delgado
   Class: CS201 Spring 2021
   This program is a typing game that tests the user's
   typing speed. They are to type out the sentence,
   "The quick brown fox jumps over the lazy dog"
   (in a randomized word order), then the computer
   prints out how long it took them.

   Last updated: April 7, 2021
 */


#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9 //there are 9 words in the array

//function prototypes
void setUp(char* arr[SIZE]);
void gamePlay(char* arr[SIZE]);

//main prompts the user to begin and calls setUp() function
int main(void){
  char input[64];
  
  //fill array with words
  char *arr[SIZE];
  arr[0] = "the";
  arr[1] = "quick";
  arr[2] = "brown";
  arr[3] = "fox";
  arr[4] = "jumps";
  arr[5] = "over";
  arr[6] = "the";
  arr[7] = "lazy";
  arr[8] = "dog";

  //print welcome messages and prompt user to begin game
  printf("Welcome to Speed Typing.\n");
  printf("Type 'ready' to begin!\n");
  scanf("%s", input);
  
  if(strncmp(input, "ready", strlen(input)) == 0){
    setUp(arr);
  }
  return 0;
}

/* the setUp function uses Fisher-Yates shuffle to
   randomize the array, then sends this new array to gamePlay();
 */
void setUp(char* arr[SIZE]){
  int randIndex = 0;

  //use srand with the seed as get time of day
  struct timeval time;
  gettimeofday(&time, NULL); 
  srand((time.tv_sec * 1000) + (time.tv_sec / 1000));

  //select a random number for the index
  //uses Fisher-Yates Shuffle
  for(int i = 8; i > 0; i--){
    randIndex = rand() % (i+1);
    //swap arr[i] and arr[randIndex]
    char* temp = arr[i];
    arr[i] = arr[randIndex];
    arr[randIndex] = temp;    
  }
  gamePlay(arr);
}

/* gamePlay prints out words, checks the user input,
   then reprints the word if incorrect input is typed. 
   it also contains a timer for how long the user takes to win.
 */
void gamePlay(char* arr[SIZE]){
  char input[64];
  char c;

  //set timer
  struct timeval begin;
  struct timeval finish;
  struct timeval elapsed;
  gettimeofday(&begin, NULL); //store time of day in begin
  
  for(int i = 0; i < SIZE; i++){
    while(strncmp(input, arr[i], 10) != 0){ //10 is a max word length
      printf("Word #%d is '%s': ", i+1, arr[i]);
      scanf("%s", input);
      while((c = getchar()) != '\n' && c != EOF) //flush the rest of the line
	;
    }
  }
  //end timer here
  gettimeofday(&finish, NULL); //store time of day in finish
  timersub(&finish, &begin, &elapsed); //timersub(a - b into c)
  printf("Nice work! You took: %ld seconds and %d microseconds\n", elapsed.tv_sec, elapsed.tv_usec);
}
