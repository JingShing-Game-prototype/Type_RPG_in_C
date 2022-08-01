#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int player_blood = 100;
int enemies_blood[10] = {50, 50, 50, 50, 50, 50, 100, 100, 100, 10000};
int enemies_fight = 7;

int coin = 6;
int blood_up = 5;
int player_fight = 5;
int beef = 1;
int armor = 0;
int bag_max = 5;
char *bag_things[] = {};
int player_strength;
int player_degree_of_hunger = 100;

void fight_system();
void find_enemies();
int select_main();
void shop();
void work();
void attribute();
void dined();
int F_number_questions();

int main(){
 select_main();
}

void fight_system(){
 int select;
 srand(time(NULL));
 int w = rand() % 3;
 int s = rand() % 10;
 int Player_fight = player_fight;
 int Enemies_blood = enemies_blood[s];
 printf("\n********************************Enter combat mode*********** ****************************\n");
 printf("Your current blood volume is: %d", player_blood);
 while(player_blood > 0 && Enemies_blood >0 && player_degree_of_hunger >30){
 printf("\nPlease choose the next step (f1 is for fighting; f2 is for returning blood; f3 is for fleeing, and f4 is for replenishing hunger): ");
 select = F_number_questions() - 1;
 if (select == 0){
player_blood -= (enemies_fight - armor);
Enemies_blood -= Player_fight;
 printf("\n****************************You chose to fight************* ****************************");
 printf("\nYour current HP is: %d\nThe enemy's HP is: %d\n", player_blood,Enemies_blood);
 printf("\nReduced hunger by 3 points\n");
            player_degree_of_hunger -= 3;
 printf("Your current hunger value is: %d\n\n", player_degree_of_hunger);
}
 else if (select == 1 && blood_up > 0){
blood_up -= 1;
player_blood += 10;
 printf("\n\n********************************You have chosen to return blood********* ********************************\n");
 printf("\nYour current blood volume is: %d", player_blood);
}
 else if (select == 1 && blood_up == 0){
 printf("************************************************ ************************************\n");
 printf("******************************** Insufficient blood recovery package! ************* ****************************\n");
 printf("************************************************ ************************************\n");
}
 else if (select == 2){
 printf("************************************************ ************************************\n");
 printf("******************************** has left the battle! ************* ****************************\n");
 printf("************************************************ ************************************\n\n\n");
 break;
 select_main();
}
 else if (select == 3 && beef > 0){
 printf("************************************************ ************************************\n");
 printf("************************************ eaten!********** ********************************\n");
 printf("************************************************ ************************************\n\n\n");
            player_degree_of_hunger += 30;
            beef -= 1;
 printf("The current hunger value is: %d\n\n\n", player_degree_of_hunger);
}
 else if(select ==3 && beef <= 0){
 printf("************************************************ ************************************\n");
 printf("**************************** Ready-to-eat beef is not enough! Please go to the store to buy it first! ************ ****************\n");
 printf("************************************************ ************************************\n\n\n");
    }
}
 printf("The battle is over! Returning~\n\n\n");
    coin += 20;
 printf("The current amount of money is: %d\n\n\n", coin);
 select_main();
}

void find_enemies()
{
 srand(time(NULL));
 int o = rand() % 10;
 if(o%2 == 0){
 fight_system();
    }
}

int select_main(){
 int iselect;
 printf("\n\n[f1] going out (battle) [f2] eating [f3] trading [f4] working [f5] checking character attributes\n");
 printf("Please choose your next action: ");
 iselect = F_number_questions() - 1;
 while(1){
 switch(iselect){
 case 0:
 find_enemies();
 break;
 case 1:
    dined();
     break;
 case 2:
     shop();
     break;
 case 3:
     work();
     break;
 case 4:
     attribute();
     break;
        }
    }
}

void shop(){
 int shop_select;//Declare shop selection
 printf("****************************************Enter the store******** ****************************");
 printf("\n\n[f1]Exit[f2]Blood Pack[f3]Weapon[f4]Instant Beef[f5]Buy Armor[f6](To be determined)\n\n\n\nPlease select what you want to buy Commodity (requires 3coin): ");
shop_select = 1;
 while(shop_select != 0 && coin >= 3){
 shop_select = F_number_questions() - 1;
 switch(shop_select){
 case 1:
                blood_up += 1;
                printf("\n\nBlood packs have been purchased! The current number of blood packs is: %d\n", blood_up);
                coin -= 3;
                 printf("The current remaining amount of money is: %d\n", coin);
                 printf("\nPlease continue to choose: ");
                 break;
 case 2:
                printf("\n\nYou bought a weapon\n\n");
                player_fight += 1;
                printf("Current attack power is: %d\n", player_fight);
                coin -= 3;
                printf("The current remaining amount of money is: %d\n", coin);
                bag_max += 1;
                 bag_things[bag_max - 1] = "Weapons";
                 printf("\nPlease continue to choose: ");
                 break;
 case 3:
                beef += 1;
                printf("\nThe ready-to-eat beef has been purchased! The current quantity of ready-to-eat beef is: %d\n", beef);
                coin -= 3;
                 printf("The current remaining amount of money is: %d\n", coin);
                 printf("\nPlease continue to choose: ");
                 break;
 case 4:
                if (armor < 5 && coin > 100){
                    armor += 1;
                    coin -= 100;
                 printf("\n\n******************************** Armor has been purchased!****** ***************************\n");
                 printf("The current armor value is: %d", armor);
                 printf("\n\nPlease continue to choose: ");
                }
                else{
                 printf("\n\n********************************You don't have enough money!****** ****************************");
                 printf("\n\nPlease continue to choose: ");
                }
                break;
 case 5:
                break;
 case 0:
                 printf("Exited the store!\n\n\n");
                 break;
                        }
                    }
                 select_main();
}

void work(){
 int work_rand;
    work_rand = rand() % 3;
 if (work_rand == 0 && player_degree_of_hunger > 10){
 printf("You found a good job!\n");
 printf("You got 5 coins!\n\n");
 printf("10 hunger points lost!\n\n");
        coin += 5;
        player_degree_of_hunger -= 10;
    }
 else if (work_rand == 1 && player_blood > 10 && player_degree_of_hunger > 20){
        printf("You found a well-paid job, but lost 10 HP due to overwork~\n");
        printf("You got 10 coins!\n\n");
        player_blood -= 10;
         printf("The current blood volume is: %d\n\n\n\n",player_blood);
         printf("20 hunger points lost!\n\n");
        coin += 10;
        player_degree_of_hunger -= 20;
    }
 else if (work_rand == 2 && player_degree_of_hunger > 5){
 printf("You found a job with a low salary\n");
 printf("You got 1 coin!\n\n");
 printf("Lost 5 hunger points!\n\n");
        coin += 1;
        player_degree_of_hunger -= 5;
}
 else printf("\n\nSorry! Your hunger or HP is too low, please replenish food first!\n\n");
 printf("The current coin is: %d\n\n\n", coin);
 select_main();
}

void attribute()
{
 printf("\nYour current property is:\n\n");
 printf("HP: %d\n", player_blood);
 printf("Hunger value: %d\n", player_degree_of_hunger);
 printf("The number of coins is: %d\n",coin);
 printf("Armor value: %d\n",armor);
 select_main();
}

void dined()
{
 if(coin >= 3 && player_degree_of_hunger < 200){
 printf("\nYou spent 3 coins! Restore 20 hunger!\n");
        player_degree_of_hunger += 20;
        coin -= 3;
 printf("\nYour current hunger value is %d \n", player_degree_of_hunger);
        player_blood += 10;
 printf("\nYour current HP is: %d\n", player_blood);
 printf("\nYour current remaining money is: %d\n\n", coin);
 select_main();
    }
 else if (player_degree_of_hunger >= 200){
 printf("\n\n****************************************Hunger value Limit reached!********************************************\n");
 select_main();
}
 else if (coin <= 3){
 printf("\n\n****************************************The amount of money Not enough!********************************************\n");
 select_main();
    }
}

int F_number_questions(){
    int return_value=0;
     while(return_value==0){
        if(GetAsyncKeyState(VK_F1) != 0){
            return_value=1;
        }
        else if(GetAsyncKeyState(VK_F2) != 0){
            return_value=2;
        }
        else if(GetAsyncKeyState(VK_F3) != 0){
            return_value=3;
        }
        else if(GetAsyncKeyState(VK_F4) != 0){
            return_value=4;
        }
        else if(GetAsyncKeyState(VK_F5) != 0){
            return_value=5;
        }
        else if(GetAsyncKeyState(VK_F6) != 0){
            return_value=6;
        }
        else if(GetAsyncKeyState(VK_F7) != 0){
            return_value=7;
        }
        else if(GetAsyncKeyState(VK_F8) != 0){
            return_value=8;
        }
        else if(GetAsyncKeyState(VK_F9) != 0){
            return_value=9;
        }
        else if(GetAsyncKeyState(VK_F10) != 0){
            return_value=10;
        }
        else if(GetAsyncKeyState(VK_F11) != 0){
            return_value=11;
        }
        else if(GetAsyncKeyState(VK_F12) != 0){
            return_value=12;
        }
    }
    Sleep(500);
    return return_value;
}
