//
//  main.c
//  VendingMachine
//
//  Created by Prabhanjan Piwalatkar, Alana Traylor, Luong Luu, Kevin C
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    double card = atof(argv[1]);
    char pick[2];
        
    char vending[10][4][30] = {

           {"Cheetos", "K3", "$","1.95"},

           {"Beef Jerky", "J7", "$","2.50"},

           {"BBQ Lays", "R3", "$","1.50"},

           {"King Size Reeses", "T2", "$","3.50"},
        
           {"1 M&M", "A1", "$","0.50"},
        
           {"Caffeine-Free Cherry Coke", "C5", "$","1.75"},
        
           {"Bottle of Ketchup", "K2", "$","2.00"},
        
           {"Glazier Gatorade", "G5", "$","2.50"},
        
           {"AA Duracell", "Y2", "$","6.00"},
        
           {"Band-aids", "B2", "$","0.75"}

       };
    
    printf("\n$%0.2f\n\n", card);
    printf("%s %s %s%s\n",vending[0][1],vending[0][0],vending[0][2],vending[0][3]);
    printf("%s %s %s%s\n",vending[1][1],vending[1][0],vending[1][2],vending[1][3]);
    printf("%s %s %s%s\n",vending[2][1],vending[2][0],vending[2][2],vending[2][3]);
    printf("%s %s %s%s\n",vending[3][1],vending[3][0],vending[3][2],vending[3][3]);
    printf("%s %s %s%s\n",vending[4][1],vending[4][0],vending[4][2],vending[4][3]);
    printf("%s %s %s%s\n",vending[5][1],vending[5][0],vending[5][2],vending[5][3]);
    printf("%s %s %s%s\n",vending[6][1],vending[6][0],vending[6][2],vending[6][3]);
    printf("%s %s %s%s\n",vending[7][1],vending[7][0],vending[7][2],vending[7][3]);
    printf("%s %s %s%s\n",vending[8][1],vending[8][0],vending[8][2],vending[8][3]);
    printf("%s %s %s%s\n",vending[9][1],vending[9][0],vending[9][2],vending[9][3]);
    
    
    /*
    printf("\nPick: ");
    scanf("%s",pick);
    printf("\n");
    
    
    if (strcmp(pick, "K3") == 0)
    {
        printf("%s %s %s%s\n",vending[0][1],vending[0][0],vending[0][2],vending[0][3]);
        card = card - atof(vending[0][3]);
    }
    else if (strcmp(pick, "J7") == 0)
    {
        printf("%s %s %s%s\n",vending[1][1],vending[1][0],vending[1][2],vending[1][3]);
        card = card - atof(vending[1][3]);
    }else if (strcmp(pick, "R3") == 0)
    {
        printf("%s %s %s%s\n",vending[2][1],vending[2][0],vending[2][2],vending[2][3]);
        card = card - atof(vending[2][3]);
    }else if (strcmp(pick, "T2") == 0)
    {
        printf("%s %s %s%s\n",vending[3][1],vending[3][0],vending[3][2],vending[3][3]);
        card = card - atof(vending[3][3]);
    }else if (strcmp(pick, "A1") == 0)
    {
        printf("%s %s %s%s\n",vending[4][1],vending[4][0],vending[4][2],vending[4][3]);
        card = card - atof(vending[4][3]);
    }else if (strcmp(pick, "C5") == 0)
    {
        printf("%s %s %s%s\n",vending[5][1],vending[5][0],vending[5][2],vending[5][3]);
        card = card - atof(vending[5][3]);
    }else if (strcmp(pick, "K2") == 0)
    {
        printf("%s %s %s%s\n",vending[6][1],vending[6][0],vending[6][2],vending[6][3]);
        card = card - atof(vending[6][3]);
    }else if (strcmp(pick, "G5") == 0)
    {
        printf("%s %s %s%s\n",vending[7][1],vending[7][0],vending[7][2],vending[7][3]);
        card = card - atof(vending[7][3]);
    }else if (strcmp(pick, "Y2") == 0)
    {
        printf("%s %s %s%s\n",vending[8][1],vending[8][0],vending[8][2],vending[8][3]);
        card = card - atof(vending[8][3]);
    }else if (strcmp(pick, "B2") == 0)
    {
        printf("%s %s %s%s\n",vending[9][1],vending[9][0],vending[9][2],vending[9][3]);
        card = card - atof(vending[9][3]);
    }
    
    printf("\n\n");
    
    printf("\nPick: ");
    scanf("%s",pick);
    printf("\n");
    
    
    if (strcmp(pick, "K3") == 0)
    {
        printf("%s %s %s%s\n",vending[0][1],vending[0][0],vending[0][2],vending[0][3]);
        card = card - atof(vending[0][3]);
    }
    else if (strcmp(pick, "J7") == 0)
    {
        printf("%s %s %s%s\n",vending[1][1],vending[1][0],vending[1][2],vending[1][3]);
        card = card - atof(vending[1][3]);
    }else if (strcmp(pick, "R3") == 0)
    {
        printf("%s %s %s%s\n",vending[2][1],vending[2][0],vending[2][2],vending[2][3]);
        card = card - atof(vending[2][3]);
    }else if (strcmp(pick, "T2") == 0)
    {
        printf("%s %s %s%s\n",vending[3][1],vending[3][0],vending[3][2],vending[3][3]);
        card = card - atof(vending[3][3]);
    }else if (strcmp(pick, "A1") == 0)
    {
        printf("%s %s %s%s\n",vending[4][1],vending[4][0],vending[4][2],vending[4][3]);
        card = card - atof(vending[4][3]);
    }else if (strcmp(pick, "C5") == 0)
    {
        printf("%s %s %s%s\n",vending[5][1],vending[5][0],vending[5][2],vending[5][3]);
        card = card - atof(vending[5][3]);
    }else if (strcmp(pick, "K2") == 0)
    {
        printf("%s %s %s%s\n",vending[6][1],vending[6][0],vending[6][2],vending[6][3]);
        card = card - atof(vending[6][3]);
    }else if (strcmp(pick, "G5") == 0)
    {
        printf("%s %s %s%s\n",vending[7][1],vending[7][0],vending[7][2],vending[7][3]);
        card = card - atof(vending[7][3]);
    }else if (strcmp(pick, "Y2") == 0)
    {
        printf("%s %s %s%s\n",vending[8][1],vending[8][0],vending[8][2],vending[8][3]);
        card = card - atof(vending[8][3]);
    }else if (strcmp(pick, "B2") == 0)
    {
        printf("%s %s %s%s\n",vending[9][1],vending[9][0],vending[9][2],vending[9][3]);
        card = card - atof(vending[9][3]);
    }
    
    printf("\n\n");
    
    
    printf("\nPick: ");
    scanf("%s",pick);
    printf("\n");
    
    
    if (strcmp(pick, "K3") == 0)
    {
        printf("%s %s %s%s\n",vending[0][1],vending[0][0],vending[0][2],vending[0][3]);
        card = card - atof(vending[0][3]);
    }
    else if (strcmp(pick, "J7") == 0)
    {
        printf("%s %s %s%s\n",vending[1][1],vending[1][0],vending[1][2],vending[1][3]);
        card = card - atof(vending[1][3]);
    }else if (strcmp(pick, "R3") == 0)
    {
        printf("%s %s %s%s\n",vending[2][1],vending[2][0],vending[2][2],vending[2][3]);
        card = card - atof(vending[2][3]);
    }else if (strcmp(pick, "T2") == 0)
    {
        printf("%s %s %s%s\n",vending[3][1],vending[3][0],vending[3][2],vending[3][3]);
        card = card - atof(vending[3][3]);
    }else if (strcmp(pick, "A1") == 0)
    {
        printf("%s %s %s%s\n",vending[4][1],vending[4][0],vending[4][2],vending[4][3]);
        card = card - atof(vending[4][3]);
    }else if (strcmp(pick, "C5") == 0)
    {
        printf("%s %s %s%s\n",vending[5][1],vending[5][0],vending[5][2],vending[5][3]);
        card = card - atof(vending[5][3]);
    }else if (strcmp(pick, "K2") == 0)
    {
        printf("%s %s %s%s\n",vending[6][1],vending[6][0],vending[6][2],vending[6][3]);
        card = card - atof(vending[6][3]);
    }else if (strcmp(pick, "G5") == 0)
    {
        printf("%s %s %s%s\n",vending[7][1],vending[7][0],vending[7][2],vending[7][3]);
        card = card - atof(vending[7][3]);
    }else if (strcmp(pick, "Y2") == 0)
    {
        printf("%s %s %s%s\n",vending[8][1],vending[8][0],vending[8][2],vending[8][3]);
        card = card - atof(vending[8][3]);
    }else if (strcmp(pick, "B2") == 0)
    {
        printf("%s %s %s%s\n",vending[9][1],vending[9][0],vending[9][2],vending[9][3]);
        card = card - atof(vending[9][3]);
    }
    */
    
    int repeat = 1;
    char sure[4];
    char item[3][30];
    
    printf("\nSelect 3 options: \n");
    while(repeat < 4){
        printf("\nPick item %d: ", repeat);
        scanf("%s",pick);
        
        if (strcmp(pick, "K3") == 0)
        {
            printf("Price: %s%s\n",vending[0][2],vending[0][3]);
        }
        else if (strcmp(pick, "J7") == 0)
        {
            printf("Price: %s%s\n",vending[1][2],vending[1][3]);
        }else if (strcmp(pick, "R3") == 0)
        {
            printf("Price: %s%s\n",vending[2][2],vending[2][3]);
        }else if (strcmp(pick, "T2") == 0)
        {
            printf("Price: %s%s\n",vending[3][2],vending[3][3]);
        }else if (strcmp(pick, "A1") == 0)
        {
            printf("Price: %s%s\n",vending[4][2],vending[4][3]);
            card = card - atof(vending[4][3]);
        }else if (strcmp(pick, "C5") == 0)
        {
            printf("Price: %s%s\n",vending[5][2],vending[5][3]);
        }else if (strcmp(pick, "K2") == 0)
        {
            printf("Price: %s%s\n",vending[6][2],vending[6][3]);
        }else if (strcmp(pick, "G5") == 0)
        {
            printf("Price: %s%s\n",vending[7][2],vending[7][3]);
        }else if (strcmp(pick, "Y2") == 0)
        {
            printf("Price: %s%s\n",vending[8][2],vending[8][3]);
        }else if (strcmp(pick, "B2") == 0)
        {
            printf("Price: %s%s\n",vending[9][2],vending[9][3]);
        }
        
        
        printf("Are you sure?(Y/N): ");
        scanf("%s", sure);
        
        if(strcmp(sure, "Y") == 0){
            if (strcmp(pick, "K3") == 0)
            {
                strcpy(item[repeat-1], vending[0][0]);
                card = card - atof(vending[0][3]);
            }
            else if (strcmp(pick, "J7") == 0)
            {
                strcpy(item[repeat-1], vending[1][0]);
                card = card - atof(vending[1][3]);
            }else if (strcmp(pick, "R3") == 0)
            {
                strcpy(item[repeat-1], vending[2][0]);
                card = card - atof(vending[2][3]);
            }else if (strcmp(pick, "T2") == 0)
            {
                strcpy(item[repeat-1], vending[3][0]);
                card = card - atof(vending[3][3]);
            }else if (strcmp(pick, "A1") == 0)
            {
                strcpy(item[repeat-1], vending[4][0]);
                card = card - atof(vending[4][3]);
            }else if (strcmp(pick, "C5") == 0)
            {
                strcpy(item[repeat-1], vending[5][0]);
                card = card - atof(vending[5][3]);
            }else if (strcmp(pick, "K2") == 0)
            {
                strcpy(item[repeat-1], vending[6][0]);
                card = card - atof(vending[6][3]);
            }else if (strcmp(pick, "G5") == 0)
            {
                strcpy(item[repeat-1], vending[7][0]);
                card = card - atof(vending[7][3]);
            }else if (strcmp(pick, "Y2") == 0)
            {
                strcpy(item[repeat-1], vending[8][0]);
                card = card - atof(vending[8][3]);
            }else if (strcmp(pick, "B2") == 0)
            {
                strcpy(item[repeat-1], vending[9][0]);
                card = card - atof(vending[9][3]);
            }
            repeat += 1;
        }
        
    }
    printf("$%0.2f\n", card);
    printf("\nYou selected %s, %s, and %s. Remaining Balance: $%.2f\n\n", item[0], item[1], item[2], card);
    
}
