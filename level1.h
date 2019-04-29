struct xycord
{
    int l,t,r,b;
};
struct xycord data[48];
struct numpop
{
    int l,t,r,b,n;
};
struct numpop rect[48];
void makecorddata();
void sortpos(struct numpop rect[48], int s);
int position(int num);
void showlevel(int);
void showattempt(int);
void showscore(int );
void gameover();
void scores(int);
int l;
void level1(int n)
{
    l=n;
    initwindow(900,700,"Level1");
    readimagefile("Data/image/nummenu.jpg",0,0,900,700);
    int num,i,h,level,fi,tp,score=0,attempt=4;
    makecorddata();
    for(level=3; level<=48; level++)
    {
        char msg[3],lev[5];
        readimagefile("Data/image/nummenu.jpg",0,0,900,700);
        showlevel(level);
        showattempt(attempt);
        showscore(score);
        position(level);
        for(num=0; num<level; num++)
        {
            delay(500);
            readimagefile("Data/image/numb.jpg",rect[num].l,rect[num].t,rect[num].r,rect[num].b);
            if(l==2)
            {
                sprintf(msg,"%c",rect[num].n);
            }
            else    sprintf(msg,"%d",rect[num].n);
            setbkcolor(getpixel(rect[num].l+10,rect[num].t+10));
            setcolor(BLACK);
            settextstyle(6,HORIZ_DIR,4);
            if(rect[num].n<10)
            {
                tp=rect[num].l+12;
            }
            else tp=rect[num].l+3;
            mciSendString("play Data/Audio/pop.wav",0,0,0);
            outtextxy(tp,rect[num].t+15,msg);
        }
        delay(1000);
        for(num=0; num<level; num++)
        {
            readimagefile("Data/image/numbw.jpg",rect[num].l,rect[num].t,rect[num].r,rect[num].b);
        }
        sortpos(rect,level);
        int flag1,rp,nc=0;
        while(1)
        {
            if(ismouseclick((WM_LBUTTONDOWN)))
            {
                int x,y;
                getmouseclick(WM_LBUTTONDOWN,x,y);
                if(x>753 && x<899 && y>627 &&y<687)
                {
                    mciSendString("play Data/Audio/sct.wav",0,0,0);
                    play();
                }

                else
                {
                    for(fi=0; fi<level; fi++)
                    {
                        if(x>=rect[fi].l && x<=rect[fi].r && y>=rect[fi].t && y<=rect[fi].b)
                        {
                            flag1=1;
                            rp=fi;
                        }
                    }
                    if(flag1==1)
                    {
                        if(x>=rect[nc].l && x<=rect[nc].r && y>=rect[nc].t && y<=rect[nc].b)
                        {
                            mciSendString("stop Data/Audio/correct.wav",0,0,0);
                            readimagefile("Data/image/numg.jpg",rect[nc].l,rect[nc].t,rect[nc].r,rect[nc].b);
                            mciSendString("play Data/Audio/correct.wav",0,0,0);
                            if(l==2)
                            {
                                sprintf(msg,"%c",rect[nc].n);
                            }
                            else    sprintf(msg,"%d",rect[nc].n);
                            setbkcolor(getpixel(rect[nc].l+10,rect[nc].t+10));
                            setcolor(BLACK);
                            if(rect[nc].n<10)
                            {
                                tp=rect[nc].l+12;
                            }
                            else tp=rect[nc].l+3;
                            outtextxy(tp,rect[nc].t+15,msg);
                            nc++;
                            flag1=0;
                            clearmouseclick(WM_LBUTTONDOWN);
                        }
                        else
                        {
                            readimagefile("Data/image/numr.jpg",rect[rp].l,rect[rp].t,rect[rp].r,rect[rp].b);
                            mciSendString("play Data/Audio/fail.wav",0,0,0);
                            delay(1000);
                            readimagefile("Data/image/nummenu.jpg",0,0,900,700);
                            showlevel(level);
                            showattempt(attempt);
                            showscore(score);
                            readimagefile("Data/image/sorry.jpg",220,260,550,460);
                            delay(1000);
                            level--;
                            attempt--;
                            flag1=0;
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                    if(nc==level)
                    {
                        delay(500);
                        score=score+(level*2);
                        readimagefile("Data/image/nummenu.jpg",0,0,900,700);
                        showlevel(level);
                        showattempt(attempt);
                        showscore(score);
                        readimagefile("Data/image/good.jpg",220,260,550,460);
                        delay(1000);
                        break;
                    }
                }
            }
        }
        if(attempt==0)
            scores(score);
    }
}
void makecorddata()
{
    int g=120,h=190,id=0,i,j;
    for( i=0; i<8; i++)
    {
        for( j=0; j<6; j++)
        {
            data[id].l=g;
            data[id].t=h;
            data[id].r=g+50;
            data[id].b=h+60;
            h+=70;
            id++;
        }
        h=190;
        g+=60;
    }
}
int position(int num)
{
    int n,nnum,i,j,a[num],flag,arr[num];
    for(i=0; i<num; i++)
    {
        if(l==1)
        {
            nnum=rand()%19;
        }
        else nnum=65+rand()%26;
        for(j=0; j<=i; j++)
        {
            if(nnum==arr[j])
            {
                flag=1;
                i--;
                break;
            }
            else flag=0;
        }
        if (flag==0)
        {
            arr[i]=nnum;
        }
    }
    for(i=0; i<num; i++)
    {
        n=rand()%48;
        for(j=0; j<=i; j++)
        {
            if(n==a[j])
            {
                flag=1;
                i--;
                break;
            }
            else flag=0;
        }
        if (flag==0)
        {
            a[i]=n;
        }
    }
    n=0;
    while(n<num)
    {
        rect[n].l=data[a[n]].l;
        rect[n].t=data[a[n]].t;
        rect[n].r=data[a[n]].r;
        rect[n].b=data[a[n]].b;
        rect[n].n=arr[n];
        n++;
    }
    n=0;
}
void sortpos(struct numpop rect[48], int s)
{
    int i, j;
    struct numpop temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (rect[j].n > rect[j + 1].n)
            {
                temp = rect[j];
                rect[j] = rect[j + 1];
                rect[j + 1] = temp;
            }
        }
    }
}
void showlevel(int n)
{
    char lev[5];
    sprintf(lev,"%d",n-2);
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(getpixel(297,39));
    setcolor(getpixel(256,48));
    outtextxy(305,11,lev);
}
void showattempt(int n)
{
    char atm[5];
    sprintf(atm,"%d",n);
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(getpixel(821,23));
    setcolor(BLACK);
    outtextxy(823,20,atm);
}
void showscore(int n)
{
    char score[5];
    sprintf(score,"%d",n);
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(getpixel(486,110));
    setcolor(BLACK);
    outtextxy(486,100,score);
}
void showscore2(int n)
{
    char score[5];
    sprintf(score,"%d",n);
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(getpixel(486,110));
    setcolor(BLACK);
    outtextxy(550,277,score);
}
void scores(int n)
{
    if(l==1)
    {
        readimagefile("Data/image/gamesc.jpg",0,0,900,700);
        struct score
        {
            int val;
            char name[20];
        };
        struct score entry[10],temp;
        setcolor(BLACK);
        settextstyle(6,HORIZ_DIR,4);
        outtextxy(150,337,"Enter Your Name :");
        int a=0;
        char write[25];
        write[0]='\0';
        while(kbhit()) getch();
        while(1)
        {
            char c=getch();
            if(c==13)
                break;
            else if(c==8)
                a-=2;
            else
                write[a]=c;
            a++;
            write[a]='\0';
            bar(535,330,880,375);
            setbkcolor(WHITE);
            outtextxy(540,337,write);
        }
        int j,k;
        FILE *in,*fp,*wr1;
        in = fopen("scorefile.txt","a");
        fprintf(in,"%d %s\n",n,write);
        fclose(in);


        fp=fopen("scorefile.txt","r");
        for(k=0; k<10; k++)
            fscanf(fp,"%d %s",&entry[k].val,&entry[k].name);
        fclose(fp);


        for(j=9; j>0; j--)
            if(entry[j].val>entry[j-1].val)
            {
                temp=entry[j];
                entry[j]=entry[j-1];
                entry[j-1]=temp;
            }
        wr1=fopen("scorefile.txt","w");
        for(j=0; j<9; j++)
            fprintf(wr1,"%d %s\n",entry[j].val,entry[j].name);
        fclose(wr1);
        char highscores[10];
        readimagefile("Data/image/gamessc.jpg",0,0,900,700);
        char scores[10];
        int s=n,hs=entry[0].val;
        sprintf(scores,"%d",s);
        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(getpixel(300,300));
        setcolor(BLACK);
        outtextxy(522,313,scores);
        sprintf(highscores,"%d",hs);

        setbkcolor(getpixel(300,300));
        settextstyle(6,HORIZ_DIR,6);
        setcolor(BLACK);
        outtextxy(521,433,highscores);
        if(s>=entry[0].val)
        {
            setcolor(BLACK);
            settextstyle(6,HORIZ_DIR,4);
            setbkcolor(getpixel(300,300));
            mciSendString("play Data/Audio/high.wav",0,0,0);
            outtextxy(70,593,"Congrats!! You made a new high score!!");

        }

        delay(4000);
        gameover();
    }
    else
    {
        readimagefile("Data/image/gamesc.jpg",0,0,900,700);
        struct score
        {
            int val;
            char name[20];
        };
        struct score entry[10],temp;
        setcolor(BLACK);
        settextstyle(6,HORIZ_DIR,4);
        outtextxy(150,337,"Enter Your Name :");
        int a=0;
        char write[25];
        write[0]='\0';
        while(kbhit()) getch();
        while(1)
        {
            char c=getch();
            if(c==13)
                break;
            else if(c==8)
                a-=2;
            else
                write[a]=c;
            a++;
            write[a]='\0';
            bar(535,330,880,375);
            setbkcolor(WHITE);
            outtextxy(540,337,write);
        }
        int j,k;
        FILE *in,*fp,*wr1;
        in = fopen("scorefile2.txt","a");
        fprintf(in,"%d %s\n",n,write);
        fclose(in);


        fp=fopen("scorefile2.txt","r");
        for(k=0; k<10; k++)
            fscanf(fp,"%d %s",&entry[k].val,&entry[k].name);
        fclose(fp);


        for(j=9; j>0; j--)
            if(entry[j].val>entry[j-1].val)
            {
                temp=entry[j];
                entry[j]=entry[j-1];
                entry[j-1]=temp;
            }
        wr1=fopen("scorefile2.txt","w");
        for(j=0; j<9; j++)
            fprintf(wr1,"%d %s\n",entry[j].val,entry[j].name);
        fclose(wr1);
        char highscores[10];
        readimagefile("Data/image/gamessc.jpg",0,0,900,700);
        char scores[10];
        int s=n,hs=entry[0].val;
        sprintf(scores,"%d",s);
        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(getpixel(300,300));
        setcolor(BLACK);
        outtextxy(522,313,scores);
        sprintf(highscores,"%d",hs);

        setbkcolor(getpixel(300,300));
        settextstyle(6,HORIZ_DIR,6);
        setcolor(BLACK);
        outtextxy(521,433,highscores);
        if(s>=entry[0].val)
        {
            setcolor(BLACK);
            settextstyle(6,HORIZ_DIR,4);
            setbkcolor(getpixel(300,300));
            mciSendString("play Data/Audio/high.wav",0,0,0);
            outtextxy(70,593,"Congrats!! You made a new high score!!");

        }

        delay(4000);
        gameover();
    }
}
void gameover()
{
    readimagefile("Data/image/gameover.jpg",0,0,900,700);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        int x,y;
        x= mousex();
        y= mousey();
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(x>=155 && y>=317 && x<=429 && y<=394 )
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            play();
        }
        else if(x>=477 && y>=316 && x<=759 && y<=392 )
        {
            mciSendString("play Data/Audio/sct.wav",0,0,0);
            menu();
        }

    }
}
