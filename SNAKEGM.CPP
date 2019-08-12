#include<stdlib.h>
#include <iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
struct cord
{
int x;
int y;
}fd;
int snk[10][10],snk_sz,scr=0,drc=2,dl_vl=500;
char scrc[10],p_scrc[10];
//////////////////
void st_gm_brd()
{
setviewport(11,11,519,449,0);
clearviewport();
}
/////////////
void drawboard()
{
    rectangle(10,10,530,460);
    setviewport(11,11,529,449,0);

   st_gm_brd();
}
/////////////////
 void chk_err()
{
   int err=graphresult();
      if(err!=0)
      {
      printf("%s","error!");
      printf("%s,%d",grapherrormsg(err),err);
      getch();
     exit(1);

      }


}
///
//////////
void st_scr_brd()
{
setcolor(2);
rectangle(530,10,630,450);
chk_err();
//setviewport(531,11,651,451,0);
chk_err();
//clearviewport();
chk_err();
settextstyle(4,0,3);
setcolor(4);
itoa(scr,scrc,10);
outtextxy(540,30,"SCORE");
chk_err();
setcolor(0);
outtextxy(550,50,p_scrc);
setcolor(4);
outtextxy(550,50,scrc);
setcolor(6);
settextstyle(2,0,5);
outtextxy(540,150,"PAUSE- p");
outtextxy(540,180,"instr. - i");
outtextxy(540,210,"settings- s");
outtextxy(540,240,"quit- q");
chk_err();
strcpy(p_scrc,scrc);
}

//////////////
void settings()
{
clrscr();
int  ch=0;
st_gm_brd();
cout<<"\t\t\tENTER DIFFICULTY LEVEL....";
cout<<"\n\n\n\t\t\t HARD.                                 1";
cout<<"\n\n\n\t\t\t MEDIUM.                           2";
cout<<"\n\n\n\t\t\t EASY.                                 3";
cin>>ch;
switch(ch)
{
case 1:dl_vl=200;
break;
case 2:dl_vl=500;
break;
case 3:dl_vl=1000;
break;
default:cout<<"\nWRONG CHOICE....!\nNO CHANGE IN DIFFIVULTY...";
getch();
}
clrscr();
drawboard();
st_scr_brd();
}
/////////////{
void instrc()
{ clrscr();
//st_gm_brd();
cout<<"\n\t\t\t\tINSTRUCTIONS...";
cout<<"\n 1. if you are playing this game on computer ,then you can use arrow keys for movement of snake....";
cout<<"\n 2.if you are playing on android ,then you dont have ";
cout<<" arrow keys...so in this situation ,use";
cout<<"\n 'y'-upward\n 'h'-right\n'b'-downward\n 'g'-left \n for movement...";
cout<<"..why these keys?because these keys are at one place on android keyboard....";
cout<<"\n 3.you can select difficulty level (hard,easy,medium)by pressing 's' during game....by default difficulty is medium set...";
cout<<"\n 4.for pause ,press 'p' ";
cout<<"\n 5.for instructions...press 'i' ";
cout<<"\n 6.for quit the game,press 'q' ";
cout<<"hit enter.....";
getch();
clrscr();
drawboard();
st_gm_brd();
st_scr_brd();
}
/////
/////
void gm_ovr()
{
settextstyle(4,0,5);
setcolor(2);
outtextxy(100,200,"GAME OVER");
settextstyle(6,0,3);
outtextxy(150,300,"SCORE=");
outtextxy(270,300,scrc);
getch();
exit(0);
};

//////////////
void gt_fd_pt(cord *p)
{
again:srand(time(0));
p->x=((rand()%25+1)*20);
p->y=((rand()%22+1)*20);
for(int i=0;i<snk_sz;i++)
{
if(p->x==snk[i][0]&&p->y==snk[i][1])
goto again;
}
};
///////////
void mk_food()
{
gt_fd_pt(&fd);
};


/////////////
void draw_fd()
{
setcolor(7);
setfillstyle(1,RED);
circle(fd.x,fd.y,8);
chk_err();
floodfill(fd.x,fd.y,7);
chk_err();
}
/////////
char check()
{
char rslt=0;
for(int i=4;i<snk_sz;i++)
{
if(snk[0][0]==snk[i][0]&&snk[0][1]==snk[i][1])
{
rslt='o';
gm_ovr();
break;
}
}
if(snk[0][0]==0|| snk[0][0]==520||snk[0][1]==0||snk[0][1]==460)
{
gm_ovr();
 rslt='o';
}
if(snk[0][0]==fd.x&&snk[0][1]==fd.y)
{
scr+=10;
mk_food();
snk_sz++;
st_scr_brd();
rslt='w';
}
return(rslt);
}
//////////
void pause()
{
getch();
}
//////////
void mk_snk()
{
snk[0][0]=240;
snk[0][1]=140;
snk[1][0]=220;
snk[1][1]=140;
snk[2][0]=200;
snk[2][1]=140;
snk[3][0]=180;
snk[3][1]=140;
snk_sz=4;
}
/////////
void drw_snk()
{
st_gm_brd();
for(int i=0;i<snk_sz;i++)
{
if(i==0)
{
setcolor(5);
circle(snk[i][0],snk[i][1],12);
}
else
{
setcolor(2);
}
circle(snk[i][0],snk[i][1],10);
//p_snk[i][0]=snk[i][0];
//p_snk[i][1]=snk[i][1];
}
draw_fd();
}
/////////
void movement()
{
char record=100;
delay(dl_vl);
if(kbhit()!=0)
{

record=getch();
}
switch(record)
{
case 'y':drc=1;
case 24:drc=1;
break;
case 'h':drc=2;
case 26:drc=2;
break;
case 'b':drc=3;
case 25:drc=3;
break;
case 'g':drc=4;
case 27:drc=4;
break;
case 'i':instrc();
break;
case 's':settings();
break;
case 'q': exit (0);
case 'p':pause();
break;
}
for(int i=(snk_sz-1);i>0;i--)
{
snk[i][0]=snk[i-1][0];
snk[i][1]=snk[i-1][1];
}
if(drc==1)
{
snk[0][1]-=20;
}
if(drc==2)
{
snk[0][0]+=20;
}
if(drc==3)
{
snk[0][1]+=20;
}
if(drc==4)
{
snk[0][0]-=20;
}
drw_snk();
}
/////////////////

////////////////////
void banner()
{
    char *banner1="SNAKE";
    char *banner2="BY UZAMAKI TONY";
    char *loading="LOADING...";
    settextstyle(4,0,7);
    setcolor(5);
    outtextxy(200,50,banner1);
    setcolor(2);
    settextstyle(3,0,2);
    outtextxy(340,110,banner2);
    settextstyle(7,0,4);
    outtextxy(230,200,loading);
    for(int i=0;i<10;i++)
    {
        if(i%3==0)
	{ 
 setcolor(2);
	circle(200,300,8);
	setcolor(5);
	circle(200,300,6);
	setfillstyle(1,5);
 floodfill(200,300,5);
	   delay(1000);
      setfillstyle(1,0);
      floodfill(200,300,2);
      
       }
       if(i%3==1)
        {
	         setcolor(2);
	circle(270,300,8);
	setcolor(5);
	circle(270,300,6);
	setfillstyle(1,5);
 floodfill(270,300,5);
	   delay(1000);
      setfillstyle(1,0);
      floodfill(270,300,2);
      
         }
         if(i%3==2)
         {
        setcolor(2);
	circle(340,300,8);
	setcolor(5);
	circle(340,300,6);
	setfillstyle(1,5);
 floodfill(340,300,5);
	   delay(1000);
      setfillstyle(1,0);
      floodfill(340,300,2);
      
         }
    }
}





///////////////
void main()
 {
    clrscr();
    int gd=0,gm,err;
char rslt_chk=0;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
    
    chk_err();
    banner();

    clrscr();
    cleardevice();
     drawboard();
     mk_snk();
     mk_food();
     st_scr_brd();
for(;rslt_chk!='o';)
{
movement();
rslt_chk=check();
}
    
    getch();
}