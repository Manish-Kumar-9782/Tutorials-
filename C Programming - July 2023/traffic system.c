#include<stdio.h>

void main(){

    char signal = '\0';

    printf("Enter Signal: ");
    scanf("%c", &signal);

    switch(signal){

    case 'r': // for red signal
        printf("Signal is red Please stop..\n");
        break;
    case 'g': // for green signal
        printf("Signal is green you can go...\n");
        break;
    case 'o': // for orange signal
        printf("Signal is orange please be careful, slow down..\n");
        break;
    default:
        printf("Traffic signal has been failed... call police..\n");
    }

}
