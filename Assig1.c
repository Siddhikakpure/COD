#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int myNum, userNum;
    srand(time(NULL));
    myNum=rand()%10;

    printf("I have a number in mind (0-9). Can you guess it? \n");

    while(myNum!=userNum){
    printf("Enter your Guess:");
    scanf("%d",&userNum);

        if(myNum==userNum){
            printf("yes you got it!");
            break;
        }else if(myNum>userNum){
            printf("My number is greater than %d. Try Again!\n\n",userNum);
        }else{
            printf("My number is smaller than %d. Try Again!\n\n",userNum);
        }
    }

    return 0;
}