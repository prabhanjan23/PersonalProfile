//
//  dealer.c
//  Car_Dealership
//
//  Created by Prabhanjan Piwalatkar on 10/26/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vehicle
{
   char manufacturer[15];
   char make[15];
   char model[22];
   double price;
};

struct vehicle vehicle1 = {"Toyota","Toyota","Corolla",21550};
struct vehicle vehicle2 = {"Toyota","Toyota","Camry",25945};
struct vehicle vehicle3 = {"Toyota","Toyota","Avalon",36825};
struct vehicle vehicle4 = {"Toyota","Toyota","Mirai",49500};
struct vehicle vehicle5 = {"Toyota","Toyota","Sequoia",58300};
struct vehicle vehicle6 = {"Toyota","Toyota","Tacoma",27250};
struct vehicle vehicle7 = {"Toyota","Toyota","Tundra",36965};
struct vehicle vehicle8 = {"Toyota","Lexus","IS",40585};
struct vehicle vehicle9 = {"Toyota","Lexus","ES",42490};
struct vehicle vehicle10 = {"Toyota","Lexus","GX",57575};
struct vehicle vehicle11 = {"Chevrolet","Chevy","Trailblazer",22100};
struct vehicle vehicle12 = {"Chevrolet","Chevy","Camaro",26100};
struct vehicle vehicle13 = {"Chevrolet","Chevy","Equinox",26600};
struct vehicle vehicle14 = {"Chevrolet","Chevy","Traverse",34520};
struct vehicle vehicle15 = {"Chevrolet","Chevy","Tahoe",54200};
struct vehicle vehicle16 = {"Chevrolet","Chevy","Suburban",56900};
struct vehicle vehicle17 = {"Chevrolet","Chevy","Corvette",64500};
struct vehicle vehicle18 = {"Chevrolet","Chevy","Spark",13600};
struct vehicle vehicle19 = {"Chevrolet","Chevy","Trax",21700};
struct vehicle vehicle20 = {"Chevrolet","Chevy","Malibu",23400};
struct vehicle vehicle21 = {"Nissan","Nissan","Versa",18990};
struct vehicle vehicle22 = {"Nissan","Nissan","Sentra",22700};
struct vehicle vehicle23 = {"Nissan","Nissan","Altima",35385};
struct vehicle vehicle24 = {"Nissan","Nissan","Maxima",43300};
struct vehicle vehicle25 = {"Nissan","Nissan","Pathfinder",50660};
struct vehicle vehicle26 = {"Nissan","Nissan","Rogue",38640};
struct vehicle vehicle27 = {"Nissan","Nissan","Murano",46910};
struct vehicle vehicle28 = {"Nissan","Infiniti","Q50",42650};
struct vehicle vehicle29 = {"Nissan","Infiniti","QX55",49150};
struct vehicle vehicle30 = {"Nissan","Infiniti","QX80",72700};
struct vehicle vehicle31 = {"BMW","BMW","2 Series Coupe",38050};
struct vehicle vehicle32 = {"BMW","BMW","3 Series Sedan",48220};
struct vehicle vehicle33 = {"BMW","BMW","4 Series Convertible",59320};
struct vehicle vehicle34 = {"BMW","BMW","5 Series Sedan",55175};
struct vehicle vehicle35 = {"BMW","BMW","7 Series Sedan",93400};
struct vehicle vehicle36 = {"BMW","BMW","X1",39700};
struct vehicle vehicle37 = {"BMW","BMW","X3",46050};
struct vehicle vehicle38 = {"BMW","BMW","X4",54050};
struct vehicle vehicle39 = {"BMW","BMW","X5",75400};
struct vehicle vehicle40 = {"BMW","BMW","X7",77850};
struct vehicle vehicle41 = {"Volkswagen","VW","Jetta",18995};
struct vehicle vehicle42 = {"Volkswagen","VW","Passat",23995};
struct vehicle vehicle43 = {"Volkswagen","VW","Arteon",36995};
struct vehicle vehicle44 = {"Volkswagen","Audi","Q5",43500};
struct vehicle vehicle45 = {"Volkswagen","Audi","Q3",38700};
struct vehicle vehicle46 = {"Volkswagen","Audi","S6",72700};
struct vehicle vehicle47 = {"Volkswagen","Audi","A6",55900};
struct vehicle vehicle48 = {"Volkswagen","Porsche","Panamera",132760};
struct vehicle vehicle49 = {"Volkswagen","Porsche","Macan",69480};
struct vehicle vehicle50 = {"Volkswagen","Porsche","Cayenne",92960};


int main(int argc, const char * argv[]) {
    double salary = atof(argv[1]);
    
    double interest;
    double downpay;
    int rate = 5;
    double max;
    double principle;
    
    double monthly_pay;
    
    
    if(salary <= 45000){
        interest = .1328;
    }else if (salary > 45000 && salary <= 80000){
        interest = .0949;
    }else if(salary > 80000 && salary <= 125000){
        interest = .0655;
    }else{
        interest = .0479;
    }
    
    printf("Enter Down Payment: ");
    scanf("%lf", &downpay);


    struct vehicle car_Toyota[] = {vehicle1, vehicle2, vehicle3, vehicle4, vehicle5, vehicle6, vehicle7, vehicle8, vehicle9,vehicle10};
    struct vehicle car_Chevy[] = {vehicle11, vehicle12, vehicle13, vehicle14, vehicle15, vehicle16, vehicle17,vehicle18, vehicle9,vehicle20};
    struct vehicle car_Nissan[] = {vehicle21, vehicle22, vehicle23, vehicle24, vehicle25, vehicle26, vehicle27, vehicle28, vehicle29,vehicle30};
    struct vehicle car_BMW[] = {vehicle31, vehicle32, vehicle33, vehicle34, vehicle35, vehicle36, vehicle37, vehicle38, vehicle39,vehicle40};
    struct vehicle car_Volk[] = {vehicle41, vehicle42, vehicle43, vehicle44, vehicle45, vehicle46, vehicle47, vehicle48, vehicle49,vehicle50};
    
    max = (salary/12) * .15;
    
    
    struct vehicle toyotacar[10];
    
    int number = 1;
    int choices[5];
    int indexT = 0;
    printf("\nAvailable Manufacturers: \n");
    
    // Toyota---------------------------------
    for (int i = 0; i < sizeof(car_Toyota)/sizeof(vehicle1); i++) {
        principle = car_Toyota[i].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        if(max > monthly_pay){
            toyotacar[indexT] = car_Toyota[i];
            indexT++;
        }
    }
    
    int valid1 = 0;
    int valid2 = 0;
    if(indexT > 0){
        for(int i = 0; i < indexT; i++){
            if((strcmp(toyotacar[i].make,"Toyota") == 0) && (valid1 == 0)){
                valid1 = 1;
            }
            if((strcmp(toyotacar[i].make,"Lexus") == 0) && (valid2 == 0)){
                valid2 = 1;
            }
        }
        choices[0] = number;
    }
    
    
    if(valid1 == 1 && valid2 == 1){
        printf("%d)Toyota ", number);
        number++;
    }else if (valid2 == 1){
        printf("%d)Lexus Group ", number);
        number++;
    }else if (valid1 == 1){
        printf("%d)Toyota ", number);
        number++;
    }
    
    
    // Chevrolet---------------------------------
    struct vehicle chevycar[10];
    int indexC = 0;
    for (int i = 0; i < sizeof(car_Chevy)/sizeof(vehicle1); i++) {
        principle = car_Chevy[i].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        if(max > monthly_pay){
            chevycar[indexC] = car_Chevy[i];
            indexC++;
        }
    }
    
    if(indexC > 0){
        printf("%d)Chevrolet ", number);
        choices[1] = number;
        number++;
    }
    
    
    
    
    // Nissan---------------------------------
    struct vehicle nissancar[10];
    int indexN = 0;
    for (int i = 0; i < sizeof(car_Nissan)/sizeof(vehicle1); i++) {
        principle = car_Nissan[i].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        if(max > monthly_pay){
            nissancar[indexN] = car_Nissan[i];
            indexN++;
        }
    }
    
    valid1 = 0;
    valid2 = 0;
    if(indexN > 0){
        for(int i = 0; i < indexN; i++){
            if((strcmp(nissancar[i].make,"Nissan") == 0) && (valid1 == 0)){
                valid1 = 1;
            }
            if((strcmp(nissancar[i].make,"Infiniti") == 0) && (valid2 == 0)){
                valid2 = 1;
            }
        }
        choices[2] = number;
    }
    
    
    if(valid1 == 1 && valid2 == 1){
        printf("%d)Nissan ", number);
        number++;
    }else if (valid2 == 1){
        printf("%d)Infiniti Group ", number);
        number++;
    }else if (valid1 == 1){
        printf("%d)Nissan ", number);
        number++;
    }
    
    
    // BMW---------------------------------
    struct vehicle bmwcar[10];
    int indexB = 0;
    for (int i = 0; i < sizeof(car_BMW)/sizeof(vehicle1); i++) {
        principle = car_BMW[i].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        if(max > monthly_pay){
            bmwcar[indexB] = car_BMW[i];
            indexB++;
        }
    }

    if(indexB > 0){
        printf("%d)BMW ", number);
        choices[3] = number;
        number++;
    }
    
    
    
    // Volkswagen---------------------------------
    struct vehicle volkcar[10];
    int indexV = 0;
    for (int i = 0; i < sizeof(car_Volk)/sizeof(vehicle1); i++) {
        principle = car_Volk[i].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        if(max > monthly_pay){
            volkcar[indexV] = car_Volk[i];
            indexV++;
        }
    }
    
    valid1 = 0;
    valid2 = 0;
    int valid3 = 0;
    if(indexV > 0){
        for(int i = 0; i < indexV; i++){
            if((strcmp(volkcar[i].make,"VW") == 0) && (valid1 == 0)){
                valid1 = 1;
            }
            if((strcmp(volkcar[i].make,"Audi") == 0) && (valid2 == 0)){
                valid2 = 1;
            }
            if((strcmp(volkcar[i].make,"Porsche") == 0) && (valid3 == 0)){
                valid3 = 1;
            }

        }
        choices[4] = number;
    }
    
    
    if(valid1 == 1 && valid2 == 1 && valid3 == 1){
        printf("%d) Volkswagen ", number);
        number++;
    }else if (valid1 == 1 && valid2 == 1){
        printf("%d)VW and Audi Group ", number);
        number++;
    }else if (valid1 == 1 && valid2 == 3){
        printf("%d)VW and Porsche Group ", number);
        number++;
    }else if (valid1 == 2 && valid2 == 3){
        printf("%d)Audi and Porsche Group ", number);
        number++;
    }else if (valid3 == 1){
        printf("%d)Porsche Group ", number);
        number++;
    }else if (valid2 == 1){
        printf("%d)Audi Group ", number);
        number++;
    }else if (valid1 == 1){
        printf("%d)VW Group ", number);
        number++;
    }
    
    int select = 0;
    int manufacturer;
    printf("\n\nSelect Manufacturer: ");
    scanf("%d",&manufacturer);
    
    for(int i = 0; i < 5; i++){
        if(choices[i] == manufacturer){
            select = i+1;
        }
    }
    
    printf("Available Make/Model: \n");
    if (select == 1) {
        for(int i = 0; i < indexT; i++){
            printf("%d) %s %s - $%.2f\n", (i+1), toyotacar[i].make, toyotacar[i].model, toyotacar[i].price);
        }
    }else if (select == 2){
        for(int i = 0; i < indexC; i++){
            printf("%d) %s %s - $%.2f\n", (i+1), chevycar[i].make, chevycar[i].model, chevycar[i].price);
        }
    }else if (select == 3){
        for(int i = 0; i < indexN; i++){
            printf("%d) %s %s - $%.2f\n", (i+1), nissancar[i].make, nissancar[i].model, nissancar[i].price);
        }
    }else if (select == 4){
        for(int i = 0; i < indexB; i++){
            printf("%d) %s %s - $%.2f\n", (i+1), bmwcar[i].make, bmwcar[i].model, bmwcar[i].price);
        }
    }else if (select == 5){
        for(int i = 0; i < indexV; i++){
            printf("%d) %s %s - $%.2f\n", (i+1), volkcar[i].make, volkcar[i].model, volkcar[i].price);
        }
    }
    
    int final;
    printf("\nSelect Make/Model: ");
    scanf("%d", &final);
    
    if (select == 1) {
        principle = toyotacar[final-1].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        printf("You selected the %s %s. Your monthly payment is $%.2f.", toyotacar[final-1].make, toyotacar[final-1].model, monthly_pay);
    }else if (select == 2){
        principle = chevycar[final-1].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        printf("You selected the %s %s. Your monthly payment is $%.2f.", chevycar[final-1].make, chevycar[final-1].model, monthly_pay);
    }else if (select == 3){
        principle = nissancar[final-1].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        printf("You selected the %s %s. Your monthly payment is $%.2f.", nissancar[final-1].make, nissancar[final-1].model, monthly_pay);
    }else if (select == 4){
        principle = bmwcar[final-1].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        printf("You selected the %s %s. Your monthly payment is $%.2f.", bmwcar[final-1].make, bmwcar[final-1].model, monthly_pay);
    }else if (select == 5){
        principle = volkcar[final-1].price - downpay;
        monthly_pay = (principle + ((principle * interest) * rate))/(rate * 12);
        printf("You selected the %s %s. Your monthly payment is $%.2f.", volkcar[final-1].make, volkcar[final-1].model, monthly_pay);
    }
    
    printf("\n-----------------------------------------------------");
    
    printf("\n\n");
    return 0;
}

