//
//  main.c
//  finalExam
//
//  Created by Prabhanjan Piwalatkar on 12/6/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct olympics
{
   char teamName[15];
   int gold;
   int silver;
   int bronze;
};

struct olympics team1 = {"Unified Team",45,38,29};
struct olympics team2 = {"United States",37,34,37};
struct olympics team3 = {"Germany",33,21,28};
struct olympics team4 = {"China",16,22,16};
struct olympics team5 = {"Cuba",14,6,11};
struct olympics team6 = {"Spain",13,7,2};
struct olympics team7 = {"South Korea",12,5,12};
struct olympics team8 = {"Hungary",11,12,7};
struct olympics team9 = {"France",8,5,16};
struct olympics team10 = {"Australia",7,9,11};
struct olympics team11 = {"Canada",7,4,7};
struct olympics team12 = {"Italy",6,5,8};
struct olympics team13 = {"Great Britain",5,3,12};
struct olympics team14 = {"Romania",4,6,8};
struct olympics team15 = {"Czechoslovakia",4,2,1};
struct olympics team16 = {"North Korea",4,0,5};
struct olympics team17 = {"Japan",3,8,11};
struct olympics team18 = {"Bulgaria",3,7,6};
struct olympics team19 = {"Poland",3,6,10};
struct olympics team20 = {"Netherlands",2,6,7};
struct olympics team21 = {"Kenya",2,4,2};
struct olympics team22 = {"Norway",2,4,1};
struct olympics team23 = {"Turkey",2,2,2};
struct olympics team24 = {"Indonesia",2,2,1};
struct olympics team25 = {"Brazil",2,1,0};


int main(int argc, const char * argv[]) {
    //double card = atof(argv[1]);
    int date = atoi(argv[1]);
    
    struct olympics teams[] = {team1, team2, team3, team4, team5, team6, team7, team8, team9, team10, team11, team12, team13
        ,team14, team15, team16, team17, team18, team19, team20, team21, team22, team23, team24, team25
    };
    
    int gp=0;
    int sp=0;
    int bp=0;
    
    
    
    if(date>=1908 && date <=1911){
        gp=5;
        sp=3;
        bp=1;
    }else if(date>=1912 && date <= 1923){
        gp=3;
        sp=2;
        bp=1;
    }else if(date >=1924 && date <= 1927){
        gp=10;
        sp=5;
        bp=4;
    }else if(date >= 1928 && date <= 1931){
        gp=6;
        sp=5;
        bp=4;
    }else if(date >= 1932 && date <= 2003){
        gp=10;
        sp=5;
        bp=4;
    }else if(date >= 2004 && date <=2022){
        gp=0;
        sp=0;
        bp=0;
    }else{
        gp=-1;
        sp=-1;
        bp=-1;
        printf("\nOlympics has yet to begin!\n");
    }
    
    printf("gold: %d \nsilver: %d \nbronze: %d \n", gp, sp, bp);
    
    printf("\n1992 Summer Olympics(Weighted: %d)\n", date);
    printf("------------------------------------\n");
  
    
    if(gp <= 0 && sp<=0 && bp <=0){
        int placement[25][2];
        
        for(int i=0; i<25;i++){
            placement[i][0] = teams[i].gold;
            placement[i][1] = i;
        }
        
        int tempp = 0;
        int tempi = 0;
        for(int i=0; i<25;i++){
            for(int j=i+1; j<25;j++){
                if(placement[i][0] < placement[j][0]){
                    //swap points
                    tempp = placement[i][0];
                    placement[i][0] = placement[j][0];
                    placement[j][0] = tempp;
                    
                    //swap indexes
                    tempi = placement[i][1];
                    placement[i][1] = placement[j][1];
                    placement[j][1] = tempi;
                }else if(placement[i][0] == placement[j][0]){
                    if(teams[i].silver < teams[j].silver){
                        tempp = placement[i][0];
                        placement[i][0] = placement[j][0];
                        placement[j][0] = tempp;
                        
                        //swap indexes
                        tempi = placement[i][1];
                        placement[i][1] = placement[j][1];
                        placement[j][1] = tempi;
                    }else if (teams[i].silver == teams[j].silver){
                        if(teams[i].bronze < teams[j].bronze){
                            tempp = placement[i][0];
                            placement[i][0] = placement[j][0];
                            placement[j][0] = tempp;
                            
                            //swap indexes
                            tempi = placement[i][1];
                            placement[i][1] = placement[j][1];
                            placement[j][1] = tempi;
                        }
                    }
                }
            }
        }
      
        for(int i=0; i<25;i++){
            printf("%s\n",teams[placement[i][1]].teamName);
        }
        
        printf("\n\n");
        
        
        
    }else{
        int sum=0;
        int placement[25][2];
        
        for(int i=0; i<25;i++){
            sum = (teams[i].gold * gp) + (teams[i].silver * sp) + (teams[i].bronze * bp);
            placement[i][0] = sum;
            placement[i][1] = i;
        }
        
        int tempp = 0;
        int tempi = 0;
        for(int i=0; i<25;i++){
            for(int j=i+1; j<25;j++){
                if(placement[i][0] < placement[j][0]){
                    //swap points
                    tempp = placement[i][0];
                    placement[i][0] = placement[j][0];
                    placement[j][0] = tempp;
                    
                    //swap indexes
                    tempi = placement[i][1];
                    placement[i][1] = placement[j][1];
                    placement[j][1] = tempi;
                }
            }
        }
      
        for(int i=0; i<25;i++){
            printf("%s\n",teams[placement[i][1]].teamName);
        }
        
        printf("\n\n");
    }
    
    
    return 0;
}
