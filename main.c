
//  main.c
//  practice
//
//  Created by CHIRAG on 02/03/19.
//  Copyright © 2019 CHIRAG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choice;
void Hangingman(int a);
void getchoice()
{

    printf("\nEnter:\n 0 to guess the letters.\n 1 to get first clue.\n 2 to get second clue.\n 3 to exit the game.\n");
    scanf("%d",&choice);
    
}
int main()
{
    char movie1[100]="inception",genre1[100]="sci-fi action movie",clue1[100]="Christopher Nolan", tempWord[100],clue2[100]="Leonardo DiCaprio",name[100];
    char Output[100];
    int matchFound = 0;
    
    int counter = 0 , position = 0, winner,score=0, length , i;
    char alphabetUser;
    int wrongTry=7;
    length = strlen(movie1);
    
    printf("\n !!!!!!Welcome to the HANGMAN GAME!!!!!!!\n");
    printf("\nYou will get 7 chances to guess the right word. 5 points for each right guess and -1 for every wrong guess or for quitting in the middle");
    printf("\n\n So help the Man and Get.Set.GO!!!!");
    
    getchar();
    printf("\nEnter the player name:\n");
    scanf("%s",name);
    
    printf("\n\n\tHIT >>ENTER<< to start");
    
    getchar();
    printf("\n\nThe genre of the movie is:\t%s",genre1);
    printf("\n\nThe movie has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        Output[i] = '_';
        Output[length] = '\0';
    }
    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",Output[i]);
        
    }
    
    getchoice();
    while(wrongTry!=0 && choice!=3)
    {
            switch(choice)
        {
            case 0:
            {
            
                    matchFound = 0;
                    fflush(stdin);
                    
                    printf("\nEnter the alphabet in small letters\n");
                getchar();
                    scanf("%c",&alphabetUser);
                
                    if(alphabetUser < 'a' || alphabetUser > 'z')
                    {
                        system("cls");
                        printf("\n\n\t Wrong input TRY AGAIN ");
                        matchFound = 2;
                        fflush(stdin);
                    }
                    
                    
                    else if (matchFound != 2)
                    {
                        for(counter=0;counter<length;counter++)
                        {
                            if(alphabetUser==movie1[counter])
                            {
                                matchFound = 1;
                                score+=5;
                                
                            }
                        }
                        
                        if(matchFound == 0)
                        {
                            printf("\n\t :( You have %d tries left ",--wrongTry);
                            score--;
                            getchar();
                            Hangingman(wrongTry);
                            getchar();
                        }
                        
                        else
                        {
                            for(counter = 0; counter < length; counter++)
                            {
                                matchFound = 0;
                                if(alphabetUser == movie1[counter])
                                {
                                    position = counter ;
                                    matchFound = 1;
                                }
                                if(matchFound == 1)
                                {
                                    for(i = 0 ; i < length ; i++)
                                    {
                                        if( i == position)
                                        {
                                            Output[i] = alphabetUser;
                                        }
                                        else if( Output[i] >= 'a' && Output[i] <= 'z' )
                                    
                                            
                                        {
                                            continue;
                                        }
                                        
                                        else
                                        {
                                            Output[i] = '_';
                                        }
                                    }
                                    tempWord[position] = alphabetUser;
                                    tempWord[length] = '\0';
                                    winner = strcmp(tempWord,movie1);
                                    
                                    if(winner == 0)
                                    {
                                        
                                        printf("\n\n\t \t !!!!! You are the WINNER !!!!!");
                                        printf("\n\n\t The movie was %s ",movie1);
                                        printf("\n\nPlayer:\t%s\nYour score is:\t%d",name,score);
                                        printf("\n\n\t\tCONGRATS!!YOU GOT IT RIGHT\n\n");
                                        
                                        return 0;
                                        
                                    }
                                    
                                }
                            }
                        }
                    
                    printf("\n\n\t");
                    for(i = 0 ; i < length ; i++)
                    {
                        printf(" ");
                        printf("%c",Output[i]);
                    }
                    
                    getchar();
                }
                
                if(wrongTry <= 0)
                {
                    printf("\n\n\t The Movie was %s\n",movie1);
                    printf("\n\n\t The man is DEAD!!!!!");
                    printf("\nYour score is:\t%d",score);
                    printf("\n\n\t Better luck next time!!!");
                    
                    
                }
            
        
    
                break;
            }
            case 1:
            {
                wrongTry--;
                printf("\nThe first clue is:\t%s\n",clue1);

                break;
            }
            case 2:
            {
                wrongTry--;
                printf("\nThe second clue is:\t%s\n",clue2);

                break;
            }
            default:
            {
                printf("\nInvalid choice\n");
                
            }
        }
        getchoice();
      
      
    }
  
  
    return 0;
}

void Hangingman(int a)

{
    
    switch(a)
    {
            
        case 0:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||   / %c",'\\');
            printf("\n\t||      ");
            break;
        case 1:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||     %c",'\\');
            printf("\n\t||      ");
            break;
        case 2:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 3:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 4:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO ",'\\');
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 5:
            system("cls");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||    O ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
    }
    return;
}


