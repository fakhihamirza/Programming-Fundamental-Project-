#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int printData();
int selection();
int hour=0,minute=0,second=0,flag=0;
	
void delay(int ms)  
{
    clock_t timeDelay = ms + clock();   
    while (timeDelay > clock());         
}
int printData(){ 

printf("____________________________\n\n");
printf("Remaining Time : 0%d:0%d:%d\t\t\tTAB TO PAUSE\n",hour,minute,second);      
printf("____________________________\n\n");
}
	typedef struct question{
		char question[200];
		char opta[100];
		char optb[100];
		char optc[100];
		char optd[100];
		char ans[2];
	}QU;
		
	typedef struct Score{
		char ID[10];
		int scr;
	}sco;
	typedef struct username{
	char id[10];/*stores id of player*/
	char name[20];/*name of player*/
}name;
	void readfile(sco *scoore,name *play){
		int i,x=0;
	FILE *ptr;
	name n;
	ptr= fopen("users.txt","r");
	if (ptr == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    } 
    while(fgetc(ptr)!=EOF){
    	if(x==0){
    		fseek(ptr,0,SEEK_SET);
    		x=1;
		}
    fread(&n,sizeof(name),1,ptr);
    if(strcmp(n.id,scoore->ID)==0){
    	strcpy(play->name,n.name);
		break;
	}
	}
	fclose(ptr);
	}
	void print(name id,char subject,char mode){
		int n=0;
		char file[200];
		sco score;
	FILE *ptr;
	switch (mode){
		case'1':
			switch(subject){
				case '1':
					strcpy(file,"chemscore.txt");	
					break;
				case '2':
					strcpy(file,"physcore.txt");	
					break;
				case '3':
					strcpy(file,"mathscore.txt");	
					break;
				case '4':
					strcpy(file,"compscore.txt");	
					break;
				case '5':
					strcpy(file,"gkscore.txt");	
					break;
			}
			break;
		case'2':
			switch(subject){
				case '1':
					strcpy(file,"chemscore2.txt");	
					break;
				case '2':
					strcpy(file,"physcore2.txt");	
					break;
				case '3':
					strcpy(file,"mathscore2.txt");	
					break;
				case '4':
					strcpy(file,"compscore2.txt");	
					break;
				case '5':
					strcpy(file,"gkscore2.txt");	
					break;
			}
			break;
			
	}
	ptr= fopen(file,"r");
	if (ptr == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    } 
    while(fgetc(ptr)!=EOF){
    	if(n==0){
    		fseek(ptr,0,SEEK_SET);
			n=-1;
    	}	
    fread(&score,sizeof(sco),1,ptr);
   
   if(strcmp(score.ID,id.id)==0){
   	readfile(&score,&id);
   	n=1;
   	printf("\n\n\n\t\t\tUSERNAME: %s\n\t\t\tNAME: %s\n\t\t\tSCORE: %d\n",score.ID,id.name,score.scr);
	}
	
    if(n==1){
    	break;
	}
	}
	if(n!=1){
		printf("\n\n\n\n\t\t\tYOU DID NOT PLAY IN THIS MODE");
	}
	fclose(ptr);
	}	
	void store(sco h_s,char subject,char mode){
	char file[200];
	FILE *p;
	switch (mode){
		case'1':
			switch(subject){
				case '1':
					strcpy(file,"chemscore.txt");	
					break;
				case '2':
					strcpy(file,"physcore.txt");	
					break;
				case '3':
					strcpy(file,"mathscore.txt");	
					break;
				case '4':
					strcpy(file,"compscore.txt");	
					break;
				case '5':
					strcpy(file,"gkscore.txt");	
					break;
			}
			break;
		case'2':
			switch(subject){
				case '1':
					strcpy(file,"chemscore2.txt");	
					break;
				case '2':
					strcpy(file,"physcore2.txt");	
					break;
				case '3':
					strcpy(file,"mathscore2.txt");	
					break;
				case '4':
					strcpy(file,"compscore2.txt");	
					break;
				case '5':
					strcpy(file,"gkscore2.txt");	
					break;
			}
			break;
			
	}
	p=fopen(file,"a");
		if (p == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    } 
	fwrite(&h_s,sizeof(sco),1,p);
	fprintf(p,"\n");	
	fclose(p);
}

void random(int x[]){
   int i,j,m=0;
   time_t t;
   srand((unsigned) time(&t));
   	for( i = 0 ; i < 60 ; i++ ) {
   		x[i]=rand()%60;
		   for(j=0;j<i;j++){
					m=0;		   	
			   if(x[j]==x[i]){
				   m=1;
				   break;
			   }
		   }
		   if(m==1){
			  i=i-1;
			}
   }  
}
char questiondisplay(int x[],int i,char subject){
	char string[1000];
	char filename[100];
	QU que;
	int line,count;
	FILE *ptr;
	switch(subject){
		case '1':
			strcpy(filename,"chemistry.txt");
			break;
		case '2':
			strcpy(filename,"physics.txt");
			break;
		case '3':
			strcpy(filename,"maths.txt");
			break;
		case '4':
			strcpy(filename,"computer.txt");
			break;
		case '5':
			strcpy(filename,"general.txt");
			break;
	}
	ptr= fopen(filename,"r");
	if (ptr == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    }
   		line=x[i];
   		count=0;
		fseek(ptr,0,SEEK_SET);
		while(fgets(string,1000,ptr)!=NULL){
			if (count==line){
				strcpy(que.question,strtok(string,"#"));
				puts(que.question);
				strcpy(que.opta,strtok(NULL,"#"));
				puts(que.opta);
				strcpy(que.optb,strtok(NULL,"#"));
				puts(que.optb);
				strcpy(que.optc,strtok(NULL,"#"));
				puts(que.optc);
				strcpy(que.optd,strtok(NULL,"#"));
				puts(que.optd);
				strcpy(que.ans,strtok(NULL,"#"));
				break;
			}else{
				count++;
			}
		}
	fclose(ptr);
	return que.ans[0];
}
int	mode1(char subject){
	
	int y,a=0;
	int x[60],m=9,score;
	char ch[2],ans;
	random(x);
	while ( m!=-1 )
    {
    	y=time(NULL);
    	while(time(NULL) <= y+60){

    	system("cls");
            if(second > 59){
            second = 0;
			++minute;
			if((minute==10)){
				break;
			}
		}
       	if(a==0){
    		score=0;
		}        
        printData();       
        ans= questiondisplay(x,a,subject);
        printf("____________________________\n\nCurrent Score : %d \n",score);
        printf("____________________________\n\nEnter Answer :");
        printf("\a");
    	if( kbhit() ){ 	
    	gets(ch);
    	a=a+1;
    	if(a==60){
    		break;
		}
    	strupr(ch);
    	if(ch[0]==9){
    		system("cls");
    		printf("\n\n\t\t\t Press 1 to exit\n\t\t\tPress 2 to Continue");
    		ch[0]=getch();
    		if(ch[0]=='1'){
    			return -2;
				
			}else {
				a=a-1;
			}
			
		}
		if(ch[0]==ans){
    		score+=10;
		}else if(ch[0]!=9){
			score-=2;
		}
		}
		delay(1000);
		second+=1;
	    }
	    if((minute==10)||(a==60)){
				break;
			}
        }
        system("cls");
        printf("\n\n\n\n\t\t\t\t YOUR SCORE\n\n\t\t\t\t   ''%d'' ",score);
        getch();
        system("cls");
        return score;
}
int mode2(char subject){
	int x[60],n,score,a=0;
	char ch[2],ans;
	random(x);
	n=5;
	printf("\n\n\n\n\t\t\tPress Enter to start");
	while(n>=0){
    		system("cls");
		if(a==0){
    		score=0;
		}
		printf("________________________________________\n\n");        
        printf("\t ARCADE MODE\t LIVES:%d\t\t\t TAB TO ESCAPE\n",n);
        printf("________________________________________\n\n");

        ans= questiondisplay(x,a,subject);
        printf("____________________________\n\nCurrent Score : %d \n",score);
        printf("____________________________\n\nEnter Answer :");
        printf("\a"); 	
    	gets(ch);
    
    	strupr(ch);
    	if(ch[0]==9){
    		system("cls");
    		printf("\n\n\t\t\t Press 1 to exit\n\t\t\tPress 2 to Continue");
    		ch[0]=getch();
    		if(ch[0]=='1'){
    			return -2;
			}else{
				n=n+1;
			}
			
		}
		if(ch[0]==ans){
    		score+=10;
    		a=a+1;
		}else if(ch[0]!=9){
			score=score-2;
			n=n-1;
			a=a+1;
		}
	}
		system("cls");
        printf("\n\n\n\n\t\t\t\t YOUR SCORE\n\n\t\t\t\t   ''%d'' ",score);
        getch();
        system("cls");
	return score;
}
int callmode(char subject,char mode){
	int x;
	switch(mode){
		case '1':
			x=mode1(subject);
			return x;
			break;
		case '2':
			x=mode2(subject);
			return x;
			break;
	}
}
void StartingScreen(){
	
	printf("\n\n\n\n\n");

	printf("\t\t\t*********************************\n\t\t\t*-------------------------------*\n\t\t\t*>>>>|MUTAAN: The Quiz Game|<<<<*\n\t\t\t*********************************\n");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t>|Press Any Key To Continue...|<\n");
	getch();
}
char MainMenu(char opt){
				printf("[Press TAB To Exit]");
			printf("\n\n\n\n\n");
	printf("\t\t\t``````````````````````````````````\n");
	printf("\t\t\t``~1.New User\t\t\t``\n\n\t\t\t``~2.Old User\t\t\t``\n\n\t\t\t``~3.Highscores\t\t\t``\n\n\t\t\t``~4.Credits\t\t\t``\n");
	printf("\t\t\t``````````````````````````````````\n");
		printf("\n\n\n\n");	
	printf("\t\t\t\t\t\t---Choose option number:");
	scanf("%c",&opt);
	fflush(stdin);
	return opt;
	}
	void Screen(name *user){//for option 1
	printf("TAB to back\n\n\n\n\t\t\t ENTER FULL NAME:");
	gets(user->name);
	if(user->name[0]==9){
		return;
	}
	printf("\n\t\t\t ENTER ID(######):");
	gets(user->id);
	fflush(stdin);
}	
	void Screen2(name *pID){//for option 2.1/3
	printf("PRESS TAB TO BACK\n\n\n\n\t\t\t ENTER ID(######):");
	gets(pID->id);
	fflush(stdin);
}	
void Instructions(){
		printf("\t\t\t<<<INSTRUCTIONS>>>");
		printf("\n~~~|Hello,User.\n~~|This game is developed to test your knowledge in different scopes.\n~~|This game contains 5 different game types to play,select any one of them.\n~~|After selecting the game type you have to select the game mode.\n~~|There are 2 game modes.(I.e: Normal & Arcade)\n~~|In Normal mode,the player have to answer all the questions,and the \n   questions are limited, and you have a time limit of 10 minutes.\n~~|In Arcade,You will have a total of 5 lives and you can answer as many questions as you can.\n~~|We hope that you enjoy this game :) \n\n\n\t\t\t\t\tPress any button to continue");
		getch();
		}
void Screenloading(char n[],char opt){//for option 2.2 AND 1.3 (IN 1.3 REMOVE "BACK")
	int i;
	for(i=0;i<=7;i++){
	if(opt=='1'){
	printf("\n\n\n\n\n\t\t\t      WELCOME\n\t\t\t     ''%s''\n\t\t\tLet's have some fun :)\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t",n);
	}else{
		printf("\n\n\n\n\n\t\t\t      WELCOME BACK\n\t\t\t     ''%s''\n\t\t\tLet's have some fun :)\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t",n);	
	}
	if (i%2!=0){
		printf("loading...");
	}
	sleep(1);
	system("cls");
}
}
char quizmodesubject(char mode,char opt){
	if(opt=='3'){
		printf("TAB To Exit\n\n\n\n\t\t\t CHOOSE QUIZ SUBJECT FOR HIGHSCORE \n\t\t\t1)Chemistry\n\t\t\t2)Physics\n\t\t\t3)Mathematics\n\t\t\t4)Computer\n\t\t\t5)General Knowledge\n");
	}else{
	printf("TAB To Exit\n\n\n\n\t\t\t Choose Quiz Subjects\n\t\t\t1)Chemistry\n\t\t\t2)Physics\n\t\t\t3)Mathematics\n\t\t\t4)Computer\n\t\t\t5)General Knowledge\n");}
	scanf("%c",&mode);
	fflush(stdin);
	if ((mode=='1')||(mode==9)||(mode=='2')||(mode=='3')||(mode=='4')||(mode=='5')){
		return mode;		
	}else{
		printf("\n\t\t\toption unavailable");
		sleep(1);
		system("cls");
		quizmodesubject(mode,opt);
}
}
void ScreenMode(char *p,char opt){//for option 2.4/1.5/3.3
	if (opt=='3'){
		printf("TAB to back\n\n\n\n\t\t\t CHOOSE MODE TO DISPLAY HIGHSCORE\n\t\t\t\t\n\t\t\t1.Normal\n\t\t\t\t\n\t\t\t2.Arcade\n\t\t\t\t\n\n\n\n\t\t\t\t\t");
	}else{
	printf("TAB to back\n\n\n\n\t\t\t CHOOSE MODE\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t\t1.Normal |10 min multiple choice questions |\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t\t2.Arcade |5 lives answer as many as you can|\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\t\t\t\t\t");
	}
	*p=getchar();
	fflush(stdin);
}
int writefile(name user){ // write new users info in file
	FILE *ptr;
	int x;
	x=filesearch(&user);
	if(x==1){
	ptr= fopen("users.txt","a");
	if (ptr == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    } 
    fwrite(&user,sizeof(name),1,ptr);
    if(fwrite==0){
    	fseek(ptr,0,SEEK_SET);
    	fwrite(&user,sizeof(name),1,ptr);
	}else{
		fprintf(ptr,"\n");
	}
	
	fclose(ptr);
	return 0;}
	else if(x==0) {
		printf("\n\n\t\t\tID exists Enter different ID");
		sleep(2);
		system("cls");
		Screen(&user);
			if((user.id[0]==9)||(user.name[0]==9)){  //to go back
						return 1;
			}
			
		writefile(user);
		system("cls");
		return 0;
	}
}
int filesearch(name *user){
	int x=0;
	name id;
	FILE *ptr;
	ptr= fopen("users.txt","r");
	if (ptr == NULL) 
    { 
        fprintf(stderr, "\nError open file\n"); 
        exit (1); 
    } 
 	fseek(ptr,0,SEEK_SET);
   while(fgetc(ptr)!=EOF){
   	if(x==0){
	   fseek(ptr,-1,SEEK_CUR);
	   x=-1;}
   	fread(&id,sizeof(name),1,ptr);
   	if(strcmp(id.id,user->id)==0){
		x=1;
		break;
	   }
   }	
   
   if(x==1){
	strcpy(user->name,id.name);
	fclose(ptr);
	return 0;}
	else{
		fclose(ptr);
	return 1;
	}
}
void Credits(){
printf("\t\t\t\t  Credits\n\t\t\t    This Game Is Made By,\n");
printf("\t\t    *******  *****   ***   *   *  *   *     *\n");
printf("\t\t       *     *   *  *      *   *  *   *   *\n");
printf("\t\t       *     * * *    *    * * *  *   * * \n");
printf("\t\t       *     *   *     *   *   *  *   *   *\n");
printf("\t\t       *     *   *   ***   *   *  *   *     *\n\n");
sleep(2);
system("cls");
printf("\t\t\t\t  Credits\n\t\t\t    This Game Is Made By,\n");//To Display This Line At Same Position Everytime With New Name
printf("\t     * *     * *  *   *   ***  *******  * * *  * * *  *******\n");
printf("\t     *  *   *  *  *   *  *        *     *   *  *      *     *\n");
printf("\t     *    *    *  *   *    *      *     * * *  * * *  * * * *\n");
printf("\t     *         *  *   *     *     *     *   *  *      *     *\n");
printf("\t     *         *  * * *   ***     *     *   *  *      *     *\n\n");
sleep(2);
system("cls");
printf("\t\t\t\t  Credits\n\t\t\t    This Game Is Made By,\n");
printf("\t\t              ***    *      *  ****   \n");
printf("\t\t             *   *   * *    *  *   *  \n");
printf("\t\t             * * *   *  *   *  *   *  \n");
printf("\t\t             *   *   *   *  *  *   *  \n");
printf("\t\t             *   *   *    * *  ****   \n\n");
sleep(2);
system("cls");
printf("\t\t\t\t  Credits\n\t\t\t    This Game Is Made By,\n");
printf("\t\t      ***   *      *  * * *   ***    ***   *     \n");
printf("\t\t     *   *  * *    *  *      *   *  *   *  *   \n");
printf("\t\t     * * *  *  *   *  * * *  * * *  * * *  *\n");
printf("\t\t     *   *  *   *  *  *      *   *  *   *  *\n");
printf("\t\t     *   *  *    * *  *      *   *  *   *  ******\n");
sleep(2);

}
int main(){
	char opt/*main menu option*/,subject/*subject choice*/,Mode/*mode choice*/;
	int x;
	sco score; //struct for score
	name user;// for storing id and name
	StartingScreen();
	while(opt !=9){
		system("cls");
		opt=MainMenu(opt);
		if(opt==9){
			return 0;}
		switch(opt){
			case '1'://if chosen option 1
				x=0;//for exception handling
				while(opt=='1'){
					system("cls");
					Instructions();
					system("cls");
					Screen(&user);
					if((user.id[0]==9)||(user.name[0]==9)){  //to go back
						break;
					}else{
						system("cls");
						x=writefile(user);
						if(x==1){
							break;
						}
						Screenloading(user.name,opt);
					}
						while(opt=='1'){
							system("cls");
							subject=quizmodesubject(subject,opt); // subject selection
							if(subject==9){
								break;
							}
							while(opt=='1'){
								system("cls");
								ScreenMode(&Mode,opt); // mode selection
								if(Mode==9){
									break;
								}
								system("cls");
								while(opt=='1'){
									x=0;
									x=callmode(subject,Mode);
									if(x!=-2){
									strcpy(score.ID,user.id);
									score.scr=x;
									store(score,subject,Mode);
									x=-2;}
									if(x==-2){
										system("cls");
										break;
									}
									break;
								}
								if(x==-2){
										break;
								}
							
							}
							if(x==-2){
							break;
							}
					}
					if(x==-2){
						break;
					}
				}
				break;
			case '2'://if chosen option 2
				x=0;//for exception
				while(opt=='2'){
					system("cls");
					Screen2(&user);
					if((user.id[0]==9)){  //to go back
						break;
					}else{
						system("cls");
							x=filesearch(&user);
							if(x==1){
								printf("\n\n\n\n\t\t\tUser not found");
								getch();
								system("cls");
							break;
							}
						Screenloading(user.name,opt); // name will be searched from file
					}
						while(opt=='2'){
							system("cls");
							subject=quizmodesubject(subject,opt); // subject selection
							if(subject==9){
								break;
							}
							while(opt=='2'){
								system("cls");
								ScreenMode(&Mode,opt); // mode selection
								if(Mode==9){
									break;
								}
								system("cls");
								while(opt=='2'){
									x=0;
									x=callmode(subject,Mode);
									if(x!=-2){
									strcpy(score.ID,user.id);
									score.scr=x;
									store(score,subject,Mode);
									x=-2;}
									if(x==-2){
										system("cls");
										break;
									}
								}
								if(x==-2){
									system("cls");
									break;
								}
							}
							if(x==-2){
								system("cls");
								break;
							}
						}
						if(x==-2){
							system("cls");
							break;
						}
				}
				break;
			case '3'://if chosen option 3
					while(opt=='3'){
					system("cls");
					Screen2(&user);
					if((user.id[0]==9)){  //to go back
						break;
					}
						while(opt=='3'){
							system("cls");
							subject=quizmodesubject(subject,opt); // subject selection
							if(subject==9){
								break;
							}
							while(opt=='3'){
								system("cls");
								ScreenMode(&Mode,opt); // mode selection
								if(Mode==9){
									break;
								}
								system("cls");
								print(user,subject,Mode);
								getch();
								break;	
							}
							break;
						}
						break;
				}
				break;
			case '4'://if chosen option 4
				system("cls");
				Credits();
				break;
			default:
				printf("\n\t\t\toption unavailable");
				sleep(1);
				system("cls");
		}
		}
}
