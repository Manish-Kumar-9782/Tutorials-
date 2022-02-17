#include<stdio.h>
#include<math.h>


void main()
{
    int i , j, size;
    int granite_value;
    char granite_name[20];

    printf("Enter Granite Name: ");
    gets(granite_name);

    printf("Enter Granite Value per feet: ");
    scanf("%d", &granite_value);

    printf("Enter the total number of input values: ");
    scanf("%d", &size);

    int inch_value[size][2];
    float feet1, feet2;
    float total_feet = 0.0;

    printf("Enter your all values.\n");

    for(i=0; i<size; i++){

        for(j=0; j<2; j++)
            scanf("%d", &inch_value[i][j]);
    }


    printf("S.N.\t inch x inch  =>  feet x feet  =>  square feet\n");
    printf("\n_____________________________________________________________\n");
    for(i=0; i<size; i++){

        feet1 = (float)(inch_value[i][0])/12;
        feet2 = (float)(inch_value[i][1])/12;

        total_feet += feet1*feet2; 
        printf("%d------>%d x %d  =>  %.2f x %.2f  => %.2f\n",i+1, inch_value[i][0], inch_value[i][1], feet1, feet2, feet1*feet2 );

    }


    printf("\n_____________________________________________________________\n");
    printf("Total Square Feet : %.2f", total_feet);
    printf("\n_____________________________________________________________\n");
    printf("Total Value of %s : %.2f", granite_name, granite_value*total_feet);
    printf("\n_____________________________________________________________\n");
}