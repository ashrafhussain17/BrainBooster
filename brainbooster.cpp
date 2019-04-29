#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<windows.h>
#include<MMSystem.h>
#include<math.h>
#include<ctime>
void load();
void menu();
void settings();
void Instructions();
void leaderboard();
void credits();
void exit();
void play();
void level(int);
#include"level1.h"
#include"arrow.h"
int main()
{
    load();
    menu();
    return 0;
}

void load()
{
    int x=900,y=700,i,l=594,t=605,r=744,b=620;
    initwindow(x,y,"Brain Booster");
    readimagefile("Data/image/ld.jpg",0,0,x,y);
    delay(100);
    readimagefile("Data/image/ld1.jpg",0,0,x,y);
    mciSendString("play Data/Audio/load.wav",0,0,0);
    setcolor(BLACK);
    rectangle(l,t,r,b);
    rectangle(l-1,t-1,r+1,b+1);
    setcolor(RED);
    for(i=1; i<=148; ++i)
    {
        rectangle(l+i,t+1,l+i+1,b-1);
        delay(5);
    }
    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(getpixel(594,622));
    readimagefile("Data/image/complete.jpg",594,625,794,675);
    delay(1000);
    while(1)
    {
        readimagefile("Data/image/ld.jpg",0,0,x,y);
        delay(400);
        mciSendString("play Data/Audio/beep.wav",0,0,0);
        readimagefile("Data/image/ld2.jpg",0,0,x,y);
        delay(400);
        if(kbhit())
            break;
    }
    readimagefile("Data/image/wlc1.jpg",0,0,x,y);
    mciSendString("play Data/Audio/wlc.mp3",0,0,0);
    delay(2000);
    while(1)
    {
        readimagefile("Data/image/wlc2.jpg",0,0,x,y);
        int cx,cy;
        cx=mousex();
        cy=mousey();
        getmouseclick(WM_LBUTTONDOWN,cx,cy);
        if(cx>=678 && cy>=575 && cx<=853 && cy<=663)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            menu();
        }
    }
}
void menu()
{
    int x,y;
    mciSendString("play Data/Audio/1.wav",0,0,0);
    while(1)
    {
        int z=0;
        readimagefile("Data/image/menu.jpg",0,0,900,700);
        //Selecting option
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=215 && y>= 210 && x<=424 && y<=252)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            play();
        }

        else if(x>=215 && y>= 295 && x<=424 && y<=329)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            Instructions();
        }

        else if(x>=215 && y>= 379 && x<=424 && y<=423)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            leaderboard();
        }

        else if(x>=215 && y>= 465 && x<=424 && y<=511)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            credits();
        }
        else if(x>=215 && y>= 550 && x<=424 && y<=595)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            exit();
        }
    }
}
void exit()
{
    while(1)
    {
        readimagefile("Data/image/exit.jpg",0,0,900,700);
        int x,y;
        x=mousex();
        y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=187 && y>=255 && x<=325 && y<=306)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            exit(0);
        }
        if(x>=418 && y>=255 && x<=555 && y<=308)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            menu();
        }
    }
}
void credits()
{
    mciSendString("stop Data/Audio/1.wav",0,0,0);
    mciSendString("play Data/Audio/cr.wav",0,0,0);
    readimagefile("Data/image/c1.jpg",0,0,900,700);
    delay(3000);
    readimagefile("Data/image/c2.jpg",0,0,900,700);
    delay(3000);
    readimagefile("Data/image/c3.jpg",0,0,900,700);
    delay(3000);
    readimagefile("Data/image/c4.jpg",0,0,900,700);
    delay(7000);
    menu();
}
void settings()
{
    readimagefile("Data/image/settings.jpg",0,0,900,700);
    delay(3000);
    mciSendString("stop Data/Audio/1.wav",0,0,0);
    menu();
}
void play()
{
    while(1)
    {
        readimagefile("Data/image/ngm.jpg",0,0,900,700);
        int x,y;
        x=mousex();
        y=mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=57 && y>=151 && x<=218 && y<=207)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            mciSendString("stop Data/Audio/1.wav",0,0,0);
            level1(1);
        }
        if(x>=667 && y>=153 && x<=831 && y<=205)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            mciSendString("stop Data/Audio/1.wav",0,0,0);
            arrow();
        }
        if(x>=57 && y>=351 && x<=218 && y<=404)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            mciSendString("stop Data/Audio/1.wav",0,0,0);
            level1(2);
        }
        if(x>=667 && y>=348 && x<=831 && y<=406)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            mciSendString("stop Data/Audio/1.wav",0,0,0);
            menu();
        }

    }

}
void Instructions()
{
    while(1)
    {
        readimagefile("Data/image/instr.jpg",0,0,900,700);
        while(ismouseclick(WM_LBUTTONDOWN))
        {
            int x,y;
            x=mousex();
            y=mousey();
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=712 && y>=614 && x<=899 && y<=685)
            {
                mciSendString("play Data/Audio/sct.wav",0,0,0);
                menu();
            }
        }
    }
}
void leaderboard()
{
    while(1)
    {
        setbkcolor(BLACK);
        char c;
        readimagefile("Data/image/score.jpg",0,0,900,700);
        setcolor(WHITE);
        settextstyle(6,HORIZ_DIR,5);
        FILE *in=fopen("scorefile.txt","r");
        char age[50],pore[50];
        fscanf(in,"%s %s",age,pore);
        fclose(in);
        outtextxy(376,206,pore);
        outtextxy(690,206,age);
        FILE *leader1, *leader2;
        int i,val,val2;
        char name[30], vals[60], names[40], name2[30], vals2[60], names2[40];
        sprintf(names,"%s",name);
        sprintf(vals,"%d",val);

        leader2=fopen("scorefile2.txt","r");
        fscanf(leader2,"%d %s",&val2,&name2);
        sprintf(names2,"%s",name2);
        sprintf(vals2,"%d",val2);
        outtextxy(376,306,names2);
        outtextxy(690,306,vals2);

        fclose(leader2);
        c=getch();


        if(c==27)
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            mciSendString("stop Data/Audio/1.wav",0,0,0);
            menu();
        }
    }


}
