#include<stdio.h>
#include <stdlib.h>

int main () {
    int d1,d2,d3,d4,d5,d6,player_hp = 100,dragon_hp = 100;
    while(player_hp>0 && dragon_hp>0){
        scanf("%d %d %d %d %d %d",&d1,&d2,&d3,&d4,&d5,&d6);
        if((d1+d2+d3)%2 == 0){ //dragon attacks
            if(abs(d5-d4)>d6){
                player_hp -= 15;//critical hit 15pt
                continue;
            }
            if((d4+d5)!=d6){
                player_hp -= 5;//normal attack 5pt
                continue;
            }
        }
        else{ //player attacks
            if(d6>d5&&d5>d4){
                dragon_hp -= 25;//critical hit (25pt)
                continue;
            }
            if(d4%2 == d5%2 || d5%2 == d6%2){
                dragon_hp -= 5;//normal hit 5pt
                continue;
            }
        }
    }
    if(player_hp > dragon_hp) printf("Player wins");
    else printf("Dragon wins");
    return 0;
}
