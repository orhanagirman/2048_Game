#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int score;
int matris[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
void  moveup(int matris[4][4]);
void  movedown(int matris[4][4]);
void  moveright(int matris[4][4]);
void  moveleft(int matris[4][4]);
void  sumup(int matris[4][4]);
void  sumdown(int matris[4][4]);
void  sumright(int matris[4][4]);
void  sumleft(int matris[4][4]);
void  findrandompalace();
void  print();

int main(){
	printf("\t\t\t\t\t\t~~LET'S PLAY 2048 GAME!!!~~\n");
	char move,temp=0;
	findrandompalace();
	findrandompalace();
	print(matris);
	printf("Please press W for move up,press S for move down,press A for move left,press D for move right:");
	
	while(temp==0){
		scanf("%c",&move);
		if(move=='w'|| move=='W'){
			moveup(matris);
			sumup(matris);
			moveup(matris);
			findrandompalace();
			findrandompalace();
			print(matris);
			printf("SCORE:%d\n",score);
			printf("Please press W for move up,press S for move down,press A for move left,press D for move right:");	
		}
		else if(move=='s'|| move=='S'){
			movedown(matris);
			sumdown(matris);
			movedown(matris);
			findrandompalace();
			findrandompalace();
			print(matris);
			printf("SCORE:%d\n",score);
			printf("Please press W for move up,press S for move down,press A for move left,press D for move right:");
		}
		else if(move=='a'|| move=='A'){
			moveleft(matris);
			sumleft(matris);
			moveleft(matris);
			findrandompalace();
			findrandompalace();
			print(matris);
			printf("SCORE:%d\n",score);
			printf("Please press W for move up,press S for move down,press A for move left,press D for move right:");
		}
		else if(move=='d'|| move=='D'){
			moveright(matris);
			sumright(matris);
			moveright(matris);
			findrandompalace();
			findrandompalace();
			print(matris);
			printf("SCORE:%d\n",score);
			printf("Please press W for move up,press S for move down,press A for move left,press D for move right:");
		}
	}
}

void findrandompalace(){
	int i,j,temp=0;
	while(temp==0){
		i=rand()%4;
		j=rand()%4;
		if(matris[i][j]==0){
			matris[i][j]=2;
			break;
		}
	}	
}
void print(int matris[4][4]){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("\t%d",matris[i][j]);
		}
		printf("\n");
		printf("\n");
	}	
}
void moveleft(int matris[4][4]){
	int i,j,k,temp;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=1;k<4;k++){
				if(matris[i][k-1]==0){
				  temp=matris[i][k];
				  matris[i][k]=matris[i][k-1];
				  matris[i][k-1]=temp;
			    }	    
			}	
	}	
  }
  printf("\a");
}
void movedown(int matris[4][4]){
	int i,j,k,temp,rotate[4][4];
	for(i=0;i<4;i++){
		rotate[i][0]=matris[3][i];
		rotate[i][1]=matris[2][i];
		rotate[i][2]=matris[1][i];
		rotate[i][3]=matris[0][i];
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=1;k<4;k++){
				if(rotate[i][k-1]==0){
				  temp=rotate[i][k];
				  rotate[i][k]=rotate[i][k-1];
				  rotate[i][k-1]=temp;	
			    }
			}	
		}
	}
	for(i=0;i<4;i++){
		matris[3][i]=rotate[i][0];
		matris[2][i]=rotate[i][1];
		matris[1][i]=rotate[i][2];
		matris[0][i]=rotate[i][3];
	}	
	printf("\a");
}
void moveright(int matris[4][4]){
	int i,j,k,temp,rotate[4][4],rotate1[4][4];
	for(i=0;i<4;i++){
		rotate[i][0]=matris[3][i];
		rotate[i][1]=matris[2][i];
		rotate[i][2]=matris[1][i];
		rotate[i][3]=matris[0][i];
	}
	for(i=0;i<4;i++){
		rotate1[i][0]=rotate[3][i];
		rotate1[i][1]=rotate[2][i];
		rotate1[i][2]=rotate[1][i];
		rotate1[i][3]=rotate[0][i];
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=1;k<4;k++){
				if(rotate1[i][k-1]==0){
				   temp=rotate1[i][k];
				   rotate1[i][k]=rotate1[i][k-1];
				   rotate1[i][k-1]=temp;	
			    }
			}	
		}
	}
	for(i=0;i<4;i++){
		rotate[3][i]=rotate1[i][0];
		rotate[2][i]=rotate1[i][1];
		rotate[1][i]=rotate1[i][2];
		rotate[0][i]=rotate1[i][3];
	}
	for(i=0;i<4;i++){
		matris[0][i]=rotate[i][3];
		matris[1][i]=rotate[i][2];
		matris[2][i]=rotate[i][1];
		matris[3][i]=rotate[i][0];
	}
	printf("\a");	
}
void moveup(int matris[4][4]){
	int i,j,k,temp,rotate[4][4];
	for(i=0;i<4;i++){
		rotate[3-i][0]=matris[0][i];
		rotate[3-i][1]=matris[1][i];
		rotate[3-i][2]=matris[2][i];
		rotate[3-i][3]=matris[3][i];
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=1;k<4;k++){
				if(rotate[i][k-1]==0){
				  temp=rotate[i][k];
				  rotate[i][k]=rotate[i][k-1];
				  rotate[i][k-1]=temp;	
			    }
			}
		}
	}
	for(i=0;i<4;i++){
		matris[0][i]=rotate[3-i][0];
		matris[1][i]=rotate[3-i][1];
		matris[2][i]=rotate[3-i][2];
		matris[3][i]=rotate[3-i][3];
	}
	printf("\a");	
}
void sumup(int matris[4][4]){
	int i,j,temp,rotate[4][4];
	for(i=0;i<4;i++){
		rotate[3-i][0]=matris[0][i];
		rotate[3-i][1]=matris[1][i];
		rotate[3-i][2]=matris[2][i];
		rotate[3-i][3]=matris[3][i];
	}
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(rotate[i][j]==rotate[i][j-1]){
				rotate[i][j-1]=2*rotate[i][j-1];
				rotate[i][j]=0;	
			    score+=rotate[i][j-1];
			}	
		}
	}
	for(i=0;i<4;i++){
		matris[0][i]=rotate[3-i][0];
		matris[1][i]=rotate[3-i][1];
		matris[2][i]=rotate[3-i][2];
		matris[3][i]=rotate[3-i][3];
	}	
}
void sumdown(int matris[4][4]){
	int i,j,temp,rotate[4][4];
	for(i=0;i<4;i++){
		rotate[i][0]=matris[3][i];
		rotate[i][1]=matris[2][i];
		rotate[i][2]=matris[1][i];
		rotate[i][3]=matris[0][i];
	}
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(rotate[i][j]==rotate[i][j-1]){
				rotate[i][j-1]=2*rotate[i][j-1];
				rotate[i][j]=0;	
				score+=rotate[i][j-1];
			}	
		}
	}
	for(i=0;i<4;i++){
		matris[3][i]=rotate[i][0];
		matris[2][i]=rotate[i][1];
		matris[1][i]=rotate[i][2];
		matris[0][i]=rotate[i][3];
	}	
}
void sumright(int matris[4][4]){
	int i,j,temp,rotate[4][4],rotate1[4][4];
	for(i=0;i<4;i++){
		rotate[i][0]=matris[3][i];
		rotate[i][1]=matris[2][i];
		rotate[i][2]=matris[1][i];
		rotate[i][3]=matris[0][i];
	}
	for(i=0;i<4;i++){
		rotate1[i][0]=rotate[3][i];
		rotate1[i][1]=rotate[2][i];
		rotate1[i][2]=rotate[1][i];
		rotate1[i][3]=rotate[0][i];
	}
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(rotate1[i][j]==rotate1[i][j-1]){
				rotate1[i][j-1]=2*rotate1[i][j-1];
				rotate1[i][j]=0;
				score+=rotate1[i][j-1];	
			}	
		}
	}
	for(i=0;i<4;i++){
		rotate[3][i]=rotate1[i][0];
		rotate[2][i]=rotate1[i][1];
		rotate[1][i]=rotate1[i][2];
		rotate[0][i]=rotate1[i][3];
	}
	for(i=0;i<4;i++){
		matris[0][i]=rotate[i][3];
		matris[1][i]=rotate[i][2];
		matris[2][i]=rotate[i][1];
		matris[3][i]=rotate[i][0];
	}
}
void sumleft(int matris[4][4]){
	int i,j;
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(matris[i][j]==matris[i][j-1]){
				matris[i][j-1]=2*matris[i][j-1];
				matris[i][j]=0;
				score+=matris[i][j-1];
			}		
		}
	}
}

	
	
	




	

