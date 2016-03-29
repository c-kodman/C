//Craig Kodman cmk126

#include <stdio.h>

//int card_number(void);//generates that random card
int card_number();//generates the random cards used in the game


int main(int argc, char** argv){

	srand((unsigned int)time(NULL));
	int x =0;
	char string[10];

	int player_cards[13];
	int dealer_cards[13];
	int player_aces = 0;
	int dealer_aces = 0;
	int dealer_count;
	int player_count;
	int blackjack();//prints win statement when player gets blackjack
	int dBusted = 0;
	void end();//ends program

	player_cards[0] = card_number();//the random card for the player/dealer next 4 lines
	dealer_cards[1] = card_number();
	player_cards[1] = card_number();
	dealer_cards[0] = card_number();

	int player_total = player_cards[0] + player_cards[1];
	int dealer_total = dealer_cards[0] + dealer_cards[1];
	if(player_total > 21){//determines that both cards are aces.
		player_cards[0] = 1;
	}
	if(dealer_total > 21){
		dealer_cards[0] = 1;
	}
	player_total = player_cards[0] + player_cards[1];
	dealer_total = dealer_cards[0] + dealer_cards[1];
	printf("The dealer:\n");
	printf("? + %d\n\n", dealer_cards[0], dealer_cards[1]);
	printf("You:\n");
	printf("%d + %d = %d\n\n", player_cards[0], player_cards[1], player_total);
	dealer_count = 2;
	player_count = 2;
	if(player_total == 21){
		blackjack();
		return 0;
	}
	int i;
	for(i = 0; i<player_count; i++){
		if(player_cards[i] == 11 || player_cards[i]==1){
			player_aces++;
			//printf("number of player aces is %d\n", player_aces);
		}
	}

	do{//the body of the program where the extra cards are drawn and conclusions are made for the blackjack
		int j;
		for(j = 0; j<dealer_count; j++){
			if(dealer_cards[j] == 11 || dealer_cards[j]==1){
				dealer_aces++;
				//printf("number of dealer aces is %d\n", dealer_aces);
			}
		}

		printf("Would you like to \"hit\" or \"stand\"?   ");
		scanf( "%s" , string );

		if(strcmp(string,"hit")==0){
			player_cards[player_count] = card_number();
			player_count++;
			if(player_cards[player_count-1]==11 || player_cards[player_count -1]==1){
				player_aces++;
			}

			player_total = player_total + player_cards[player_count-1];

			if(player_total>21 && player_aces>0){
				player_total= player_total-10;
				player_aces--;
			}

			printf("You:\n");
			x=1;
			int h;
				if(player_total>21){
				for(h=0; h<player_count;h++){
					if(player_cards[h]==11 || player_cards[h]==1){
						printf("%c", 'A');
						if(h!= player_count - 1){
							printf(" + ");
						}
					}
					else{
					printf("%d", player_cards[h]);
					if(h!= player_count - 1){
						printf(" + ");
						}
					}
				}
				printf(" = %d BUSTED! You lost!\n\n", player_total);
				x=0;
				}
			else{
				for(h=0; h<player_count;h++){
					if(player_cards[h]==11 || player_cards[h]==1){
						printf("%c", 'A');
					}
					else{
						printf("%d", player_cards[h]);
					}
					if(h!= player_count - 1){
						printf(" + ");
					}

				}printf(" = %d\n\n", player_total);
			}
	}
		else if(strcmp(string, "stand")==0){
			x =0;
			printf("The dealer:\n");
			printf("%d + %d\n\n", dealer_cards[0], dealer_cards[1]);
			if(dealer_total<17){
				do{
					dealer_cards[dealer_count] = card_number();//dealer_card();
					dealer_total = dealer_total + dealer_cards[dealer_count];
					dealer_count++;

					if(dealer_total>21 && dealer_aces==0){
						x=0;
						int k = 0;
						while(k< dealer_count){
							printf("%d", dealer_cards[k]);
							k++;
							if(k!=dealer_count){
								printf(" + ");
							}
							else{
								printf(" = %d\n", dealer_total);
							}
						}
						printf("Dealer Busted!\n");
						printf("You have won!\n");
						dBusted = 1;
						break;
					}
					else if(dealer_total>21 && dealer_aces>0){
						dealer_total = dealer_total - 10;
						dealer_aces--;
					}

					printf("The dealer:\n");
					int count=0;
					while(count< dealer_count){
						printf("%d", dealer_cards[count]);
						count++;
						if(count!=dealer_count){
							printf(" + ");
						}
						else{
							printf(" = %d\n", dealer_total);
						}
					}
				}while(dealer_total<17);
			}
			else{
				printf("The dealer:\n");
				printf("%d \n\n", dealer_total); //, dealer_crd, dealer_total_new);
			}
			if(dealer_total >= player_total && dBusted==0){
				printf("You have lost.\n\n");
			}
			else if (dealer_total < player_total){
				printf("You have won!.\n\n");
			}
		}

		player_aces = 0;
		dealer_aces = 0;
	}while(x == 1);

}
//@param NULL
//@return card_value
//prints out when player gets blackjack.
int blackjack(){
	printf("Congrats! You have black jack and win!\n\n");

}
int card_number(){
	int high = 14;
	int low = 2; // was 1...is 1 correct?
	int value = rand() % (high - low + 1) + low;
	int card_value = value;
	if(value >10 && value <14){
		card_value = 10;
	}
	else if(value ==14){
		card_value = 11;
	}
	return card_value;
}

//ends program
void end(){

}
/*int hit(){
	int high = 14;
	int low = 2;// was 1 - is 1 correct?
	int value = rand() % (high - low + 1) + low;
	int card_value = value;
	if(value >10 && value <14){
		card_value = 10;
	}
	else if(value ==14){
		card_value = 11;
		//number_of_aces++;
	}
	return card_value;
}*/
