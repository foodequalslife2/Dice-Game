#include <stdio.h>
#include <stdlib.h>  // for rand
#include <time.h>


/*   
 *  Chua Edric Jarvis
 *  11913991
 *	S19
 */ 

/*
this function checks the prize count 


if all prizes are taken that means the game is over so it returns one
if all other prize except first prize is claimed that means that its waithing for a first prize contender or a first prize nWinner to take first prize and return 2
if there are all prizes it returns 0 to signal to continue the loop

*/

int noPriceChecker(int nFirst, int nSecond , int nThird , int nFourth , int nFifth , int nSixth)
{
	
	
	if(nFirst == 0 && nSecond == 0 && nThird == 0 && nFourth == 0 && nFifth == 0 && nSixth == 0)
   		return 1;
   	else if(nFirst == 1 && nSecond == 0 && nThird == 0 && nFourth == 0 && nFifth == 0 && nSixth == 0)
   		return 2;
 	else 
		return 0;
}

/*
this function comapers for the first prize rolls and prints who won the first prize the game. This function only activates if there are no more prizes to be claimed

int nWinner 				checks whether there is a Winner,if nWinner is 1, it means that the winning player that rolled the highest is now playing, meaning the game should end and there are no prizes left.
int nPair4  				checks if there is a 4 of the same number in the dice rolls;
int nPair5  				checks if there is a 5 of the same number in the dice rolls; 
int nWinningcnt1			the current kicker  of a 4 pair  	previous roll 4 4 4 4 3 3 <-- 3+3= 6 								current roll  4 4 4 4 5 5 <-- 5+5= 10 is what is inside nWinningcnt1	  
int nWinningcnt2			the previous kicker of a 4 pair 	previous roll 4 4 4 4 3 3 <-- 3+3= 6 is what is inside nWinningcnt2
int nWinningcnt1prt2		the current kicker  of a 5 pair  	previous roll 4 4 4 4 4 3 											current roll 4 4 4 4 4 5 <-- 5 is what is inside nWinningcnt1prt2  
int nWinningcnt2prt2		the previous kicker of a 5 pair 	previous roll 4 4 4 4 4 3 <-- 3 is what is inside nWinningcnt2prt2 
int nWinningplyr			the player that is winning

int *winningcon 
*/


void winning(int nWinner, int nPair4, int nPair5, int nWinningcnt2, int nWinningcnt1, int nWinningcnt2prt2, int nWinningcnt1prt2, int nWinningplyr ){
	
	if(nWinner==1)
	{
		if(nPair4 == 1 || nPair5 == 2)
    	{
			if(nPair4 > nPair5)
	      	{
				if(nWinningcnt2 > nWinningcnt1)
	        	{
		     		printf("All prizes have the claimed. \nPlayer:%d wins, for Tsiong Wan Tai %d.",nWinningplyr ,nWinningcnt2); 	
	        	}	
	      	}	
	      	
	      	else if(nPair4 < nPair5)
	      	{
	        	if(nWinningcnt2prt2 > nWinningcnt1prt2)
	        	{
		     		printf("All prizes have the claimed. \nPlayer:%d wins, for Ngo-Tsi Tai %d.",nWinningplyr ,nWinningcnt2prt2); 
	        	}	
	      	}
		}
   	}
}


	

/*
This function determines the dice rolls and tallies all the rolls

int ndie is the dice getting rolled 6 times
int ndietotal is used for getting the total amount of all the dice rolls, used for the nWinningcnt1prt2 calculation
int ndie5pair is used to see what kind of 5 pair it is, used in the nWinningcnt1prt2 calculation
int nDiecnt is used to count how many times a dice is rolled 


pointers: 
int *d1, *d2, *d3, *d4, *d5, *d6 is called with each an initial value of 0 and returns 1 if the dice roll is the numebers 1 2 3 4 5 6
int *nRulecnt is called with an inital value of 0 and if there are 3 pairs of the same number such as 111 222 333 444 555 666, 1 is added to it's value, then returns the value,used in the calculation for the half and half rule.  

int *nOthers1 is called with an inital value of 0 and if the die is 1, 1 is added to its value then returns the value. Used in the calculation of *nOtherscnt,ndiepair,  4pair, 5pair, 4th prize, 2nd prize, 1st prize: 5pair, 6pair
int *nOthers2 is called with an inital value of 0 and if the die is 2, 1 is added to its value then returns the value. Used in the calculation of *nOtherscnt, ndiepair, 4pair, 5pair, 4th prize, 2nd prize, 1st prize: 5pair, 6pair			
int *nOthers3 is called with an inital value of 0 and if the die is 3, 1 is added to its value then returns the value. Used in the calculation of *nOtherscnt, ndiepair, 4pair, 5pair, 4th prize, 2nd prize, 1st prize: 5pair, 6pair	
int *nFrs	  is called with an inital value of 0 and if the die is 4, 1 is added to its value then returns the value. Used in the calculation of  ndiepair, 4pair, 5pair, 6th prize, 5th prize, 3rd prize, 2nd prize, 1st prize: 4,pair, 5pair, 6pair
int *nOthers5 is called with an inital value of 0 and if the die is 5, 1 is added to its value then returns the value. Used in the calculation of *nOtherscnt, ndiepair, 4pair, 5pair, 4th prize, 2nd prize, 1st prize: 5pair, 6pair
int *nOthers6 is called with an inital value of 0 and if the die is 6, 1 is added to its value then returns the value. Used in the calculation of *nOtherscnt, ndiepair, 4pair, 5pair, 4th prize, 2nd prize, 1st prize: 5pair, 6pair
 
int *nOtherscnt is called with an inital value of 0, adds all the values nOthers1-nOthers6 and nFrs / 5, then returns the value.  Logic int can't read fractions so it rounds down so the only answer would be 1 or 0, 1 if there is a 5 pair 0 for not. Used in the calculation for 5pair 

int *nWinningcnt1  		is called with an inital value of 0 then if the result of the dice roll is not 4, then it adds whatever value the die is to its own value ndietotal += ndie then returns the value. Used for comparing 4 pairs.
int *nWinningcnt1prt2	is called with an inital value of 0 then if *nOtherscnt equals to 1, then it subtracts ndietotal with (ndiepair * 5) to get the kicker for the 5 pair, Logic if //6+5+5+5+5+5 31-25 = 6 kicker , then returns the value. Used for comparing 5 pairs. 
			
*/
void ndicerolls(int *d1, int *d2, int *d3, int *d4, int *d5, int *d6, int *nRulecnt, int *nOthers1, int *nOthers2, int *nOthers3 , int *nOthers5, int *nOthers6, int *nFrs, int *nWinningcnt1, int *nOtherscnt, int *nWinningcnt1prt2, int *tempchecker, int *rules)
{
	int ndie; 
  	int ndietotal = 0 ;
  	int ndie5pair = 0; 
  	int nDiecnt; 

	for (nDiecnt = 1; nDiecnt <= 6; nDiecnt++)
  	{ 

  	// randomizer 
  	ndie = 1+rand()%9;
//  
//if(*tempchecker>2 && (*rules==3 || *rules ==4)){
//
//	if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 1;
//		}
//		if(nDiecnt==6){
//			ndie = 1;
//		}	
//	}
//
//
//if(*tempchecker>5){
//		if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 5;
//		}
//		if(nDiecnt==6){
//			ndie = 5;
//		}	
//}
//
//
//// for the first two turns tsiong wan to check if winningcnt2==0< winningcnt1==4 
////check if dice roll is a four pair of 4's while golden flower rule is on, while kicker is 2 and or the current kicker is higher than the previous kicker .
//   
//  if((*tempchecker>2 && *tempchecker<= 5) && (*rules==1 || *rules ==2)) {
//		if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 1;
//		}
//		if(nDiecnt==6){
//			ndie = 1;
//		}
//	
//}
//
//// for the first two turns tsiong wan to check if winningcnt2==0< winningcnt1==4
//if(*tempchecker<3){
//		if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 2;
//		}
//		if(nDiecnt==6){
//			ndie = 2;
//		}
//	
//	
//}
//
//// check if dice roll is a four pair of 4's while golden flower rule is on while current kicker is lower than the previous kicker 
//if(*tempchecker==3){
//		if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 1;
//		}
//		if(nDiecnt==6){
//			ndie = 2;
//		}
//	
//	
//}
//
////check if dice roll is a four pair of 4's while golden flower rule is on while kicker is any number than 2 and current kicker is higher than the previous kicker .
//
//if(*tempchecker==2){
//		if(nDiecnt==1){
//			ndie = 4;
//		}
//		if(nDiecnt==2){
//			ndie = 4;
//		}
//		if(nDiecnt==3){
//			ndie = 4;
//		}
//		if(nDiecnt==4){
//			ndie = 4;
//		}
//		if(nDiecnt==5){
//			ndie = 6;
//		}
//		if(nDiecnt==6){
//			ndie = 6;
//		}
//	
//	
//}
//
//// lets say that it returns to normal dice rolls
//	if(*tempchecker>12){
//		ndie = 1+rand()%6; // +1 because we cant have a 0 in a dice, rand() generates a random number from 0 - 32767 , %6 because thats how many sides a dice has 1 - 6. ;
//}
//
//// then at turn 31st then only Ngo tsi will it change the 1st prize contender 
//// check if dice roll is a four pair of 4's while golden flower rule is on while the  previous roll's tier is lower than the current tier.
//		if(*tempchecker>20){
//		if(nDiecnt==1){
//			ndie = 6;
//		}
//		if(nDiecnt==2){
//			ndie = 6;
//		}
//		if(nDiecnt==3){
//			ndie = 6;
//		}
//		if(nDiecnt==4){
//			ndie = 6;
//		}
//		if(nDiecnt==5){
//			ndie = 6;
//		}
//		if(nDiecnt==6){
//			ndie =1; 
//		} 
//		
//}
//
//		if(*tempchecker>25){
//		if(nDiecnt==1){
//			ndie = 6;
//		}
//		if(nDiecnt==2){
//			ndie = 6;
//		}
//		if(nDiecnt==3){
//			ndie = 6;
//		}
//		if(nDiecnt==4){
//			ndie = 6;
//		}
//		if(nDiecnt==5){
//			ndie = 6;
//		}
//		if(nDiecnt==6){
//		ndie = 1+rand()%5;
//		} 	
//		
//}
//
//	if(*tempchecker>35){
//		ndie = 1+rand()%6;
//	}


  
  
		//ndie = 1+rand()%6; // +1 because we cant have a 0 in a dice, rand() generates a random number from 0 - 32767 , %6 because thats how many sides a dice has 1 - 6. ;

          printf("%d \t",ndie);
         
            //if dice is 4
            if(ndie == 4)
            {
              *nFrs = *nFrs +  1; // number of fours
              *d4 = 1;// used to determine the 2nd prize 

              if(*nFrs == 3) // used for the rule of half and half 
              {
                *nRulecnt = *nRulecnt + 1;
              }

              if(*nFrs == 5)   // sets the what is the 5 pair to later used for comparing 5 pairs this is not for kicker
              {
                ndie5pair = 4;
              }    
            }

            //if dice is 1
            else if(ndie == 1)
            {    
              *nOthers1 = *nOthers1 + 1; // number of other numbers that is a 4 pair
              *d1 = 1;	

              // half half
              if(*nOthers1 == 3)
              {
                *nRulecnt = *nRulecnt + 1;
              }

              //what is the 5 pair
              if(*nOthers1 == 5)
              {
                ndie5pair = 1;
              }    

            }	

            // if dice is 2
            else if(ndie == 2)
            {
              *nOthers2 = *nOthers2 + 1;
              *d2 = 1;	

              // half half
              if(*nOthers2 == 3)
              {
                 *nRulecnt= *nRulecnt + 1;
              }

              //what is the 5 pair
               if(*nOthers2 == 5)
              {
                ndie5pair = 2;
              }   
            }	

            // if dice is 3 
            else if(ndie == 3)
            {
              *nOthers3 = *nOthers3 + 1;
              *d3 = 1;

              // half half
              if(*nOthers3 == 3)
              {
                 *nRulecnt= *nRulecnt + 1;
              }
              //what is the 5 pair
              if(*nOthers3 == 5)
              {
                ndie5pair = 3;
              }    
            }	

            // if dice is 5 
            else if(ndie == 5)
            {
              *nOthers5 = *nOthers5 + 1;
              *d5 = 1;

              // half half
              if(*nOthers5 == 3)
              {
                *nRulecnt= *nRulecnt + 1;
              }
              // what is the 5 pair
              if(*nOthers5 == 5)
              {
                ndie5pair = 5;
              }    
            }	
            //if the dice is 6 
            else if(ndie == 6)
            {
              *nOthers6 = *nOthers6 + 1;
              *d6 = 1;
           
              // half half
              if(*nOthers6 == 3)
              {
                 *nRulecnt= *nRulecnt + 1;
              }

              // what is the 5 pair 
              if(*nOthers6 == 5)
              {
                ndie5pair = 6;  // sets the what is the 5 pair later used for comparing 5 pairs this is not for kicker
              }    
            }	


            //grabs for the kicker for 4's 4 pairs  //4 4 4 4 5 5 == 10
            if(ndie != 4)
            {
              *nWinningcnt1 += ndie;	
            }

            *nOtherscnt = *nOthers1 / 5 + *nOthers2 / 5 + *nOthers3 / 5 + *nFrs / 5 + *nOthers5 / 5 + *nOthers6 / 5; // int cant do fractions so if there is a 1 there is a 5 pair 
            
            ndietotal += ndie; // sums the dice
              
            
            if(*nOtherscnt == 1 )
            {
              *nWinningcnt1prt2 = ndietotal - ndie5pair *5 ; //6+5+5+5+5+5 31-25 = 6 kicker 3+4+3+3+3+3 19-15 =4 kicker thats the logic
            }

        } // End of Dice loop  
          nDiecnt = 1;
          ndietotal = 0;
}





/*
This function is the game, it determines which nPlayers gets what prizes. 

int nPlaycnt is the max amount of Players.
int rules   are the rules of the game, whether golden flower and half and half is on of off, represented by the numbers 1-4.

int nSixth, nFifth, nFourth, nThird, nSecond, nFirst are the prizes, amounting to 32 for 6th prize ,16 for 5th pirze ,8 for 4th prize, 4 for 3rd prize,2 for 2nd prize , 1 for 1st prize.


int nPlayers 											is the amount of nPlayers

char dump; 												is a dump whether an enter key is pressed, basically it just pauses the game for a sec and waits for the input of the user

int lastRoundComplete 									checker for all the checking if statments, it's like a switch that tells the rest of the code if it should run or not
int nOtherscnt 											sums all of the nOthers later used in the function ->ndicerolls

int nWin 												is set as 0 and loop around till a winner is picked

int nPair4												determines if there is a 4 pair rolled
int nPair5 												determines if there is a 5 pair rolled

int nWinningcnt1 										checks the last fifth die and the sixth die rolls, it gets the kicker
int nWinningcnt2 										holds the last fifth die and the sixth die rolls from the last player, it saves the highest kicker
int nWinningcnt1prt2 									checks for only the last roll, it gets the kicker
int nWinningcnt2prt2    								holds for only the last roll, it saves the highest kicker
int nFrs 												holds the amount of how much '4' was rolled ie. 4 4 3 1 2 5 <-- nFrs=2;
int nOthers1, nOthers2 , nOthers3, nOthers, nOthers6	holds the amount any other number aside form four 
int nRulecnt											hold the amount of 3 paired rolls for half and half rule
int d1,d2,d3,d4,d5,d6   								if every single one is equal to one that means that the dice roll was 1 2 3 4 5 6 2nd prize
int nothing 											determines if a player won nothing
int nWinner												determines if the game is over or not
int nFstprize											prints the player who got a 4 pair or above in the there are still prizes left screen		
int nTsiang												prints the player who got tsiang or 6 pair	


*/

void Game(int nPlaycnt , int rules){	
// prize amount 
	int nSixth  = 32;
	int nFifth  = 16;
	int nFourth = 8;
	int nThird  = 4;
	int nSecond = 2;
	int nFirst  = 1;
  //amount player 
	int nPlayers;
  //dump
	char dump;
	int lastRoundComplete = 0;
  	int nOtherscnt=0; 
	int nWinningplyr = 0; // saves the winning nPlayers number 
	int nWin;// condition to get out the while loop
	int nPair4 = 0; // 4 pair with kicker
	int nPair5 = 0; // 5 pair with kicker 
	int nWinningcnt1 = 0; // checks the last fifth die and the sixth die rolls //meaning gets the kicker
	int nWinningcnt2 = 0; //holds the last fifth die and the sixth die rolls from the last player //meaining saves the highest kicker
	int nWinningcnt1prt2 = 0; //winningcntprt2 checks for only the last roll //meaning gets the kicker
	int nWinningcnt2prt2 = 0; //winningcntprt2 holds for only the last roll //meaning saves the highest kicker
	int nFrs = 0; // dice rolls number if fours
	int nOthers1 = 0, nOthers2 = 0, nOthers3 = 0, nOthers5 = 0, nOthers6 = 0; // dice rolls other numbers than four 
	int nRulecnt = 0; // this is for the half and half rule
	int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0; 
  	int nothing = 1; // it is one/true because it will be on till a prize is selcted then it will turn off 
  	int nWinner=0;
   	int nFstprize=0;
   	int nTsiang=0;
   	int tempchecker=1;
	srand(time(NULL)); // this uses the internal clock of my computer to control seed generation 
//	printf(" this is the rules :  %d \n",rules);
	while(nWin!=1)	
	{
		for(nPlayers = 1; nPlayers <= nPlaycnt; nPlayers++)
	  	{  
	    	if(nPlayers == nWinningplyr && noPriceChecker(nFirst, nSecond, nThird, nFourth, nFifth, nSixth) == 2)
	      	{
		        nWin = 1;
		        nFirst = nFirst - 1;
		        lastRoundComplete =1;
		        nothing = 0;
		  		nWinner=1;
		  		nPlayers = nPlaycnt+1;
		  		winning(nWinner, nPair4, nPair5, nWinningcnt2, nWinningcnt1, nWinningcnt2prt2, nWinningcnt1prt2, nWinningplyr);
	      	}

    	if(lastRoundComplete == 0 && (noPriceChecker(nFirst, nSecond, nThird, nFourth, nFifth, nSixth) == 0 || noPriceChecker(nFirst, nSecond, nThird, nFourth, nFifth, nSixth) == 2))
	    {
	    	
	    // calling function for the dice rolls 
        ndicerolls( &d1, &d2, &d3, &d4, &d5, &d6, &nRulecnt,  &nOthers1,  &nOthers2,  &nOthers3 ,  &nOthers5,  &nOthers6,  &nFrs, &nWinningcnt1, &nOtherscnt, &nWinningcnt1prt2, &tempchecker, &rules);
     	tempchecker++;
	
		
   	
        printf("\n\n");
        printf("________________________________________________________________________________________________________________________\n");
        // First Prize (6 pairs of anything)
        if(nFrs == 6 || nOthers6 == 6 || nOthers5 == 6 || nFrs == 6 || nOthers3 == 6 || nOthers2==6 || nOthers1==6)
        {
          printf("\nPlayer:%d wins for Tsiang, you get all the prizes\n", nPlayers);
          
	        nWin    = 1;
	        nFirst  = 0;
	       	nWinningplyr=nPlayers;
	        nPlayers = nPlaycnt+1;
	        nSecond = 0;
	        nThird  = 0;
	        nFourth = 0;
	        nFifth  = 0;
	        nSixth  = 0;  
	        nothing = 0;
	    	nTsiang=1;
         	nFstprize=1;
        }

        else if(nOtherscnt == 1) // checks if there is a 5 pair 
        {
          //  frist prize 5 pairs 
            if(nWinningcnt1prt2 >= nWinningcnt2prt2) 
            {    
             	printf("\nPlayer: %d got for Ngo-Tsi Tai %d. You are the highest 1st prize contender \n\n\n\n\n\n\n\n\n\n",nPlayers ,nWinningcnt1prt2);
              	nWinningplyr = nPlayers;
              	nWinningcnt2prt2 = nWinningcnt1prt2;
              	nPair5 = 2;
              	nothing = 0;
              	nFstprize =1;
            }
            else if(nWinningcnt1prt2 < nWinningcnt2prt2)
            {
              printf("\nPlayer:%d got for Ngo-Tsi Tai %d. However you are not the highest, You do not get the 1st prized. \n\n\n\n\n\n\n\n\n\n", nPlayers, nWinningcnt1prt2);	
              nothing = 0;
            } 
        }

        	// 2nd Prize 
          else if(d1 == 1 && d2 == 1 && d3 == 1 && d4 == 1 && d5 == 1 && d6== 1)
          {
            if (nSecond == 0)
			{
            	printf("player:%d got 2nd Tui-Teng, there are no more 2nd prizes left\n",nPlayers);
              	nothing = 0;
			}
             
            else 
            {
                printf("player:%d won 2nd prize Tui-Teng, There are still %d prize left, please claim 1\n", nPlayers ,nSecond );
                nSecond = nSecond - 1;	// 2nd prize
                nothing = 0;
            }
          }
          
        	// 3rd Prize
        else if(nFrs == 3 && (rules==2 || rules==4))
          {
            if (nThird == 0)
            {
              printf("player:%d got 3rd Sam-Hong, there are no more 3rd prizes left \n", nPlayers);
              nothing = 0;
            }
            else 
            {
              printf("player:%d won 3rd Sam-Hong, There are still %d prize left, please claim 1 \n", nPlayers, nThird );	
              nThird = nThird - 1;	// 3rd prize	
              nothing = 0;
            }
          }
          
          // 4th prize
          else if (nOthers1 == 4  || nOthers2 == 4 || nOthers3 == 4 || nOthers5 == 4 || nOthers6 == 4)
          {
            if (nFourth == 0)
            {
              printf("player:%d got 4th Si-Jin, there are no 4th more prizes\n",nPlayers);
              nothing = 0;
            }
            else 
            {
              printf("player:%d won 4th Si-Jin, There are still %d prizes left, please claim 1\n", nPlayers,nFourth );
              nFourth = nFourth - 1;	//4th prize     
              nothing = 0;
            }
          }
          
          // 5th prize
          else if (nFrs == 2)
          {
            if (nFifth == 0)
            {
              printf("player:%d got 5th Di-ku, there are no more 5th prizes left\n",nPlayers);
              nothing = 0;
            }
            else
            {   
              printf("player:%d won 5th prize Di-ku, There are still %d prizes left, please claim 1 \n", nPlayers, nFifth);
              nFifth = nFifth - 1;	// 5th prize    
			  nothing = 0;  
            }	
          }
          
          // 6th prize
          else if (nFrs == 1)
          {
            if(nSixth == 0 )
            {
              printf("player:%d got 6th It-siu, there are no more 6th prizes left\n",nPlayers);
              nothing = 0;
            } 
            else 
            {
              printf("player:%d won 6th prize It-siu, There are still %d prizes left, please claim 1\n", nPlayers, nSixth);
              nSixth = nSixth - 1;	       
              nothing = 0;
            } 
          }
          
          
          	// if rule is on conditions 
            else if(rules == 1 || rules == 2)
            {
	            // rules set 2nd prize
		        if(rules == 1)
				{
		      		if(nRulecnt == 2) // nRulecnt must be eqauls to two to know if we have 2 pairs of the same number
		            {
		                if (nSecond == 0){
		                	printf("player:%d got 2nd Tui-Teng, there are no more 2nd prizes left\n",nPlayers);
		                	nothing = 0;
						}
		                
		                else 
		                {
		                	printf("player:%d got 2nd Tui-Teng, There are still %d prize left, please claim 1 \t  \n",nPlayers,  nSecond); 
		                	nSecond = nSecond - 1;	// 2nd prize
		                	nothing = 0;
		                }
		            }
		            
					// 3rd Prize if half and half is on cause 444333 conflicts with 2nd and 3rd prize 2nd prize must be first if this is the case
					else if(nFrs == 3)
						{
						    if (nThird == 0)
						    {
						    	printf("player:%d got 3rd Sam-Hong, there are no more 3rd prizes left \n", nPlayers);
						        nothing = 0;
						    }
						        else 
						        {
						        printf("player:%d won 3rd Sam-Hong, There are still %d prize left, please claim 1 \n", nPlayers, nThird );	
						        nThird = nThird - 1;	// 3rd prize	
						        nothing = 0;
						        }
						}
				}
				
				
				
				if(nPair5 <= nPair4)
				{		
		            if(nFrs == 4) 
		            {
		            	if(nWinningcnt1 == 2) // kicker last 2 dice that is not 4's
		              	{
		                	printf("\nPlayer: %d got for Tsiong Wan Tai %d. You are the highest 1st prize contender \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",nPlayers ,nWinningcnt1);
		                	nWinningplyr = nPlayers;
		                	nWinningcnt2 = nWinningcnt1; 
		                	nPair4 = 1;
		                	nothing = 0;
		                	nFstprize=1;
		              	}		
		               	else if(nWinningcnt1 >= nWinningcnt2 && (nWinningcnt2 != 2 || nWinningcnt1==2)) 
		              	{
		            		printf("\nPlayer: %d got for Tsiong Wan Tai %d. You are the highest 1st prize contender \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",nPlayers ,nWinningcnt1);
		                	nWinningplyr = nPlayers;
		                	nWinningcnt2 = nWinningcnt1; 
		                	nPair4 = 1;
		                	nFstprize=1;
		                	nothing = 0;
		              	}      
		              	else 
		              	{
		                	printf("\nPlayer:%d got for Tsiong Wan Tai %d. However you are not the highest, You do not get the 1st prized. \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nPlayers, nWinningcnt1);	
		                	nothing = 0;
		              	}
		        	}
		            
		        	
	        	}
	        	else 
	            {
	              if(nFrs == 4) 
	                {
	                    printf("\nPlayer:%d got for Tsiong Wan Tai %d. However you are not the highest, You do not get the 1st prized. \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nPlayers, nWinningcnt1);	
	                    nothing = 0;
	                }
	                
           		}
           		 
       			if(nothing ==1)
				{
		            printf("player:%d won nothing \n", nPlayers);
			   	}
		            
          	}
        // First Prize (Four pairs of Four) 
        else if(rules == 3 || rules == 4)
        {
        	if(rules == 3)
			{    
		      	if(nRulecnt == 2) // nRulecnt must be eqauls to two to know if we have 2 pairs of the same number
		        {
		        	if (nSecond == 0)
					{
		           	printf("player:%d got 2nd Tui-Teng, there are no more 2nd prizes left\n",nPlayers);
		            nothing = 0;
					}
		            else 
		            {
		                printf("player:%d got 2nd Tuiteng, There are still %d prize left, please claim 1 \t  \n",nPlayers  , nSecond); 
		                nothing = 0;
		               	nSecond = nSecond - 1;	// 2nd prize
		            }
		        }
		        
		        // 3rd Prize if half and half is on cause 444333 conflicts with 2nd and 3rd prize 2nd prize must be first if this is the case
		        else if(nFrs == 3)
				{
					if (nThird == 0)
					{
					    printf("player:%d got 3rd Sam-Hong, there are no more 3rd prizes left \n", nPlayers);
					    nothing = 0;
					}
					    else 
					    {
					    printf("player:%d won 3rd Sam-Hong, There are still %d prize left, please claim 1 \n", nPlayers, nThird );	
					    nThird = nThird - 1;	//	
					    nothing = 0;
					    }
				}        
		    }
		   
		   
		    
        	if(nPair5 <= nPair4)
			{
		        if(nFrs == 4) 
		        {
		            if(nWinningcnt1 >= nWinningcnt2) // kicker last 2 dice that is not 4's
		            {
		                printf("\nPlayer: %d got for Tsiong Wan Tai %d. You are the highest 1st prize contender \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",nPlayers ,nWinningcnt1);
		                nWinningplyr = nPlayers;
		                nWinningcnt2 = nWinningcnt1; 
		                nPair4 = 1;
		                nothing = 0;
		                nFstprize=1;
		            }		
		            else if(nWinningcnt1 < nWinningcnt2)
		            {
		                printf("\nPlayer:%d got for Tsiong Wan Tai %d. However you are not the highest, You do not get the 1st prized. \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nPlayers, nWinningcnt1);
						nothing = 0;	
		            }
		        }
		       	
			}
			  else 
		      {
	            if(nFrs == 4) 
	                {
	                    printf("\nPlayer:%d got for Tsiong Wan Tai %d. However you are not the highest, You do not get the 1st prized. \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nPlayers, nWinningcnt1);	
	                    nothing = 0;
	                      
	                }
            }
			if(nothing ==1)
			{
       		
		        printf("player:%d won nothing \n", nPlayers);
			}
        }

        
          	printf("Please Press Any Key to Continue");
          	scanf("%c" , &dump); // make code pause for a sec
          	printf("\n");
          			
      		nothing  = 1;
        	nFrs     = 0;
        	nOthers1 = 0;
        	nOthers2 = 0;
        	nOthers3 = 0;
        	nOthers5 = 0;
        	nOthers6 = 0;
        	nRulecnt  = 0;
        	nWinningcnt1 = 0;
        	nWinningcnt1prt2 = 0;
           
        	d1 = 0;
        	d2 = 0;
        	d3 = 0;
        	d4 = 0;
        	d5 = 0;
        	d6 = 0;
        	
        	printf("There are still \n");
        	printf("6th prize: %d \n5th prize: %d\n4th prize: %d\n3th prize: %d\n2nd prize: %d\n" , nSixth, nFifth, nFourth, nThird, nSecond);
        	
        	if(nFstprize==0){
        		printf("1st prize: NONE\n");	
			}
			
        	else if(nFstprize==1){
        	 if(nTsiang==1)
        		printf("1st prize: Tsiang by player %d \n",nWinningplyr);
        	 else if(nPair4==1 && nPair5<nPair4) 
        		printf("1st prize: Tsiong Wan Tai %d by player %d \n", nWinningcnt2,nWinningplyr);
        	 else if(nPair5==2 && nPair5>nPair4)
			 	printf("1st prize: Ngo Tsi Tai %d by player %d \n", nWinningcnt2prt2,nWinningplyr);
			}
			printf("________________________________________________________________________________________________________________________\n");
  			printf("\n");
        
          
      	} // end of last round complete 
    } // End of Player Loop	
		
  }		 // End of while loop 	
}   	   
 // End of function









/*
This fuction determines amount of Players in a game

returns PNum, the amount of Players

*/
int Players()
{	
	int nPNum = 0;
  	char dump;
  	while(nPNum < 2)
  {
    printf("How many Players? \n");
    scanf("%d", &nPNum);  
    scanf("%c" , &dump); //for no duplication of enter key 
    if(nPNum < 2)
    	printf("Invalid amount at least 2 Players are required \n");
  }

	
    return nPNum; // returns numbers of Players this goes to in main
}





/*
This fuction determines the rules of the game

returns 1, 2, 3 or 4 to determine what is on or off

1 <-- means Yes and Yes  for gold flower rule and half and half
2 <-- means Yes and No   for gold flower rule and half and half
3 <-- means No  and Yes  for gold flower rule and half and half
4 <-- means No  and No   for gold flower rule and half and half

*/

int Rules() // RULES
{ 

	char cGold, cHalf, dump; 
 	int nGold = 0;  
  	int nHalf = 0;
  	int nChoicesChecker1 = 0;
  	int nChoicesChecker2 = 0;
  	int RuleSet;

  	printf("Will the Golder Flower Tsiong Wan Rule be observed(y/n) \n");
  	scanf("%c", &cGold);
  	scanf("%c", &dump);

while(nChoicesChecker1 != 1)
  	{
    switch(cGold)
    {
    	case 'y':
	    case 'Y':
        nChoicesChecker1 = 1;
        nGold = 1;
        break;

      	case 'n':
	    case 'N':
        nChoicesChecker1 = 1;
        break;

    	default:
        printf("invalid input \n");
        printf("Will the Golder Flower Tsiong Wan Rule be observed(y/n) \n");
        scanf("%c", &cGold);
        scanf("%c" , &dump);
    }
  }

	printf("Will the half-and-half Tui Teng be observed(y/n)  \n");
	scanf("%c", &cHalf);
	scanf("%c", &dump);
	
while(nChoicesChecker2 != 1)
  {
    switch(cHalf)
    {
    case 'y':
	case 'Y':
    nChoicesChecker2 = 1;
    nHalf = 1;
    break;

	case 'n':
	case 'N':
    nChoicesChecker2 = 1;
    break;

    default:
    printf("invalid input \n");
    printf("Will the half-and-half Tui Teng be observed(y/n)  \n");
    scanf("%c", &cHalf);
    scanf("%c" , &dump);
    }
  }

  if(nGold == 1 && nHalf == 1) // used for setting up the rules in Game
  {  
    RuleSet = 1;
  }
  else if(nGold == 1 && nHalf == 0)
  {
    RuleSet = 2;
  }    
  else if(nGold == 0 && nHalf == 1)
  {
    RuleSet = 3;
  }    
  else if(nGold == 0 && nHalf == 0)
  {
    RuleSet = 4;
  }    
  return RuleSet;
}


int main()
{
	int nTotalPlayers; 
  	nTotalPlayers = Players(); // This Ask for the Number of Players
	int nYesOrNO;
	nYesOrNO = Rules() ;
	Game(nTotalPlayers, nYesOrNO); 
	
	return 0;
}
