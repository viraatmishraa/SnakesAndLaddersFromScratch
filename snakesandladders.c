//press alt+z for better readibility (works in vs code)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int move(int,int);
void printGrid();
typedef struct playerpos
{
int x,y,position;
char previousA, previousB;

}player;
player p1;
player p2;


void clear (void)
{
    while ( getchar() != '\n' );
}
void printDieClear(FILE *);
void printGrid();
int diceRoll();//requires stdlib and time
int SkeletalAlgorithm();
int Snake99_19();
int Snake66_17();
int Snake49_31();
int Ladder73_94();
int Ladder25_63();
int Ladder6_53(),playerFlag=1;
int animation(int);
void printDie(FILE *);
int snakeandladdercheck(player*);

// player * p1=NULL;
// player * p2=NULL;

char grid[31][61]=
{
"-------------------------------------------------------------",
"|100  |M  99|   98|   97|   96|   95|   94|   93|   92|   91|",
"|    (' ')  |     |     |     |     |  \\-\\|     |     |     |",
"------\\ \\-------------------------------\\-\\------------------",
"| 81  /0/ 82|   83|   84|   85|   86|  84\\-\\  88|   89|   90|",
"|     \\ \\   |     |     |     |     |     \\-\\   |     |     |",
"------/0/----------------------------------\\-\\---------------",
"| 80  \\ \\ 79|   78|   77|   76|   75|  74 | \\-73|   72|   71|",
"|     /0/   |     |     |     |     |     |     |     |     |",
"----- \\ \\ ---------------------------------------------------",
"| 61  /0/ 62|   63|   64|   65|   66|   67|   68|   69|   70|",
"|     \\ \\   |   \\-\\     |     |  M  |     |     |     |     |",
"------/0/--------\\-\\-----------(^ ^)-------------------------",
"| 60  \\ \\ 59|   58\\-\\57 |   56|/ /  |   54| 53  |   52|   51|",
"|     /0/   |     |\\-\\  |     ( ) 55|     |  /-/|     |     |",
"------\\ \\-----------\\-\\------/ /------------/-/--------------",
"| 41  /0/ 42|   43|  \\-\\|45 ( )   46|   47|/-/48|49  M|   50|",
"|     \\ \\   |     | 44\\-\\  / /|     |     /-/   |  [' ']    |",
"------/0/--------------\\-\\( )------------/-/--------\\ \\------",
"| 40  \\ \\ 39|   38|   37\\/ /36|   35| 34/-/   33|  32\\ \\  31|",
"|     /0/   |     |     ( )\\  |     |  /-/|     |     \\     |",
"------\\ \\--------------/ /\\-\\---------/-/--------------------",
"| 21  /0/ 22|   23| 22( )25\\-\\|   26|/-/27|   28|   29|   30|",
"|     \\ \\   |     |  / /|     |     /-/   |     |     |     |",
"------/0/-----------( )------------/-/-----------------------",
"| 20  \\ \\ 19|   18|   17|   16|15 /-/   14|   13|   12|   11|",
"|     |     |     |     |     |  /-/|     |     |     |     |",
"--------------------------------/-/--------------------------",
"|    1|    2|    3|    4|    5|/-/ 6|    7|    8|    9|   10|",
"|p1 p2|     |     |     |     |     |     |     |     |     |",
"-------------------------------------------------------------"
};
int moderP1=1,moderP2=1;
int dieResult=1;

int main()
{
p1.position=1;
p2.position=1;
p1.y=29;
p1.x=1;
p1.previousA=' ';//common mistake: string written in place of a character 
p1.previousB=' ';
p2.y=29;
p2.x=4;
p2.previousA=' ';
p2.previousB=' ';
SkeletalAlgorithm();
}


//instead of calling movement function once, and no. of steps as a parameter, i will call movement function n times which intern help me to reduce work for animation and also makes the alternating row direction problem a lot simple
int move(int player,int dodgeSnLflag)
{
if(player==1)
    {
    if(p1.position%10==0/*we want to change y,  cause pointer at 10 or 1*/)
        {
        // we will change the x-coordinate modification symbol by multiplying -1 to the mod-er
        moderP1*=-1;
       
        // we want to unprint from last location i.e position before modification
        grid[p1.y][p1.x]=p1.previousA; // y is horizontal movement)
        grid[p1.y][p1.x+1]=p1.previousB;
        // we will move y one up (y-3 in this case),
        p1.y=p1.y-3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p1.previousA=grid[p1.y-3][p1.x];   //
        p1.previousB=grid[p1.y-3][p1.x+1];   //
       
        
        // we want to print to mod location, moving player 1
        grid[p1.y][p1.x]='p';
        grid[p1.y][p1.x+1]='1';
        
        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        //return
        if(dodgeSnLflag=1)
        snakeandladdercheck(&p1);
        return 1;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p1.y][p1.x]=p1.previousA;
        grid[p1.y][p1.x+1]=p1.previousB;
        
    // we want to store what is in the next block in the previous A & B of the structure
    p1.previousA=grid[p1.y][p1.x+(moderP1*6)];
    p1.previousB=grid[p1.y][(p1.x+(moderP1*6))+1];
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p1.x=p1.x+(moderP1*6);// this line decides the direction of insertion for' p1' and updates x coordinate accordingly
        
        // we want to print to mod location, moving player 1
        grid[p1.y][p1.x]='p';
        grid[p1.y][p1.x+1]='1';

        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        
        
        //return
        if(dodgeSnLflag=1)
        
        snakeandladdercheck(&p1);
        return 1;
        }}
else 
{
  ////









//optimization idea- make a pointer to the structure and instead of writing the code 2 times just assing p1 or p2 to the struct and go on with a common variable
if(player==-1)// this line executes algo for player two when the flag is -1, which means it will be flippable
    if(p2.position%10==0/*we want to change y,  cause pointer at 10 or 1*/)
        {
        // we will change the x-coordinate modification symbol by multiplying -1 to the mod-er
        moderP2*=-1;
       
        // we want to unprint from last location i.e position before modification
        grid[p2.y][p2.x]=p2.previousA;
        grid[p2.y][p2.x+1]=p2.previousB;
       
        
        // we will move y one up (y-3 in this case),
        p2.y=p2.y-3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.y][p2.x];
        p2.previousB=grid[p2.y][p2.x+1];

        // we want to print to mod location, moving player 1
        grid[p2.y][p2.x]='p';
        grid[p2.y][p2.x+1]='2';
      
        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p2.y][p2.x]=p2.previousA;
        grid[p2.y][p2.x+1]=p2.previousB;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.y][p2.x+(moderP2*6)];
        p2.previousB=grid[p2.y][(p2.x+(moderP2*6))+1];
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p2.x=p2.x+(moderP2*6);// this line decides the direction of insertion for' p2' and updates x coordinate accordingly
            
        
        // we want to print to mod location, moving player 1
        grid[p2.y][p2.x]='p';
        grid[p2.y][p2.x+1]='2';

        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    }}




int SkeletalAlgorithm() {
  printf("press enter to start");
  while (p1.position <= 99 || p2.position <= 99) {
    clear();
    printGrid();
    int dieResult = diceRoll();
    animation(dieResult);




    if (dieResult == 6) {
      // move(playerFlag);
      move(playerFlag,0), move(playerFlag,0), move(playerFlag,0), move(playerFlag,0),
          move(playerFlag,0), move(playerFlag,1);
      continue;
      
      


    } else 
    {
      if (dieResult == 1)
        move(playerFlag,1);
      if (dieResult == 2) {
        move(playerFlag,0);
        move(playerFlag,1);
      }
      if (dieResult == 3) {
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,1);
      }
      if (dieResult == 4) {
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,1);
      }
      if (dieResult == 5) {
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,0);
        move(playerFlag,1);
      }
      playerFlag *= -1;
    }
  }
}
/* 
this from project snake:

int printMatrix() {
    // usleep(1000000);

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 32; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
  printf("          ****your current score=%d*****", len);
}

Has been modified to :
*/

void printGrid() 
{
  usleep(100000);
    printf("\033[H");
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 61; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}


void printGridFaster() 
{
    printf("\033[H");
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 61; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

/* this from project snake:

int createRand(int num) {
  int random;
  if (first_c == 'w') {
    srand(time(NULL));

    random = rand();
    random = (random % num) + 1;
  } // srand is basically feeding a seed value to the pseudo
  // // random function rand() on the basis of time
  else if (first_c == 'a') {
    n++;
    srand(len + n);
  }
  //   ///this line makes this version of snake , speedrunable, as its
  //   predictable with exactlty same pattern everytime

  random = rand();
  random = (random % num) + 1;

  return random;
}
has been modified to:*/



int diceRoll() 
{
    
    srand(time(NULL));

    int random = rand();
    random = (random % 6) + 1;
   // srand is basically feeding a seed value to the pseudo
   // random function rand() on the basis of time
  


  return random;
}

int snakeandladdercheck(player *p)
{
if(p->position==99)
Snake99_19(p);
if(p->position==66)
Snake66_17(p);
if(p->position==49)
Snake49_31(p);
if(p->position==73)
Ladder73_94(p);
if(p->position==25)
Ladder25_63(p);
if(p->position==6)
Ladder6_53(p);
}


int Snake99_19(player *p)//straight down x7 y2=> x7 y26
{
  
for(int i=0;i<=23;i++)
{
  char next=grid[1+p->y][p->x];
  grid[++p->y][p->x]='p';
  grid[p->y-1][p->x]=next;

printGrid();
}
char temp=grid[2][8];
p->position=19;
p->x=7;
p->y=26;
grid[26][7]='p';
}



int Snake66_17(player *p)// down and left
{
 p->x=p->x+3;
for(int i=0;i<13;i++)
{
  grid[++p->y][--p->x]='p';
  grid[p->y-1][p->x+1]=' ';

printGrid();
}
p->position=17;
p->x=19;
p->y=26;
grid[26][19]='p';
moderP1*=-1;//will have to know the payer else this will fail

}

int Snake49_31(player *p)// down and right
{
 p->x=p->x+3;

for(int i=0;i<3;i++)
{
  grid[++p->y][++p->x]='p';
  grid[p->y-1][p->x-1]=' ';

printGrid();
}
p->position=31;
p->x=55;
p->y=20;
grid[20][55]='p';
moderP1*=-1;


}
int Ladder73_94(player *p)// up and left
{
   p->x=p->x+3;
  for(int i=0;i<6;i++)
{

  grid[--p->y][--p->x]='p';
  grid[p->y+1][p->x+1]='-';

printGrid();
}
p->position=63;
p->x=37;
p->y=2;
grid[2][37]='p';

}

int Ladder25_63(player *p)// up and left
{
  p->x=p->x+4;
  for(int i=0;i<12;i++)
{

  grid[--p->y][--p->x]='p';
  grid[p->y+1][p->x+1]='-';

printGrid();
}
p->position=63;
p->x=13;
p->y=11;
grid[11][13]='p';
// moderP1*=-1;

}



int Ladder6_53(player *p)// up and right
{
  // p->x=p->x+3;
for(int i=0;i<15;i++)
{

  grid[--p->y][++p->x]='p';
  grid[p->y+1][p->x-1]='-';

printGrid();
}
p->position=53;
p->x=43;
p->y=14;
grid[20][55]='p';
moderP1*=-1;

}



int animation(int dieFlag)
{
    FILE *fh;
  
    fh=fopen("frame1.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame2.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame3.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame4.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame5.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame6.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame7.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame8.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frame1.txt","r");
    printDie(fh);
    fh=fopen("frameClear.txt","r");
      printDieClear(fh);
    fh=fopen("frameClear.txt","r");
    printDieClear(fh);
    if(dieFlag==1)
    { 
            fh=fopen("frame_1onD.txt","r");
      printDie(fh);
    }
    if(dieFlag==2)
    {
      
      fh=fopen("frame_2onD.txt","r");
      printDie(fh);
    }
    if(dieFlag==3)
    {
      
      fh=fopen("frame_3onD.txt","r");
      printDie(fh);
    }
    if(dieFlag==4)
    {
      
      fh=fopen("frame_4onD.txt","r");
      printDie(fh);
    }
    if(dieFlag==5)
    {
      
      fh=fopen("frame_5onD.txt","r");
      printDie(fh);
    }
    if(dieFlag==6)
    {
      
      fh=fopen("frame_6onD.txt","r");
      printDie(fh);
    }

}


void printDie(FILE *fh)
{
  printGridFaster();
  if(fh!=NULL)
  {
    char c;
    while((c=fgetc(fh))!=EOF)
    putchar(c);
    fclose(fh);
    usleep(100000);
  }else
  {
    printf("error opening file");
  }
    return;
}


void printDieClear(FILE *fh)
{
  printGridFaster();
  if(fh!=NULL)
  {
    char c;
    while((c=fgetc(fh))!=EOF)
    putchar(c);
    fclose(fh);
  }else
  {
    printf("error opening file");
  }
    return;
}
