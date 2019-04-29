void showattempt1(int);
arrow()
{
    char str[3];
    char str1[3];
    char str2[3];
    char atmp[10];

    srand(time(NULL));
    initwindow(900,700,"Level1");

    int atm=5;

    for(int x=0; x<10; x++)
    {
        int g=0;

        readimagefile("Data/image/nummenu.jpg",0,0,900,700);
        str[0]=(x+1)+'0';
        str[1]=NULL;
        settextstyle(10,0,5);
        outtextxy(310,20,str);
        str1[0]=3+'0';
        str1[1]=NULL;
        settextstyle(6,HORIZ_DIR,4);
        showattempt1(atm);

        str2[0]=(x)+'0';
        str2[1]=NULL;
        settextstyle(10,0,5);
        outtextxy(520,110,str2);


        rectangle(200,500,270,570);
        rectangle(300,500,370,570);
        rectangle(400,500,470,570);
        rectangle(500,500,570,570);
        readimagefile("Data/image/pro1.jpg",200,500,270,570);
        readimagefile("Data/image/pro2.jpg",300,500,370,570);
        readimagefile("Data/image/pro3.jpg",400,500,470,570);
        readimagefile("Data/image/pro4.jpg",500,500,570,570);



        rectangle(200,250,270,320);
        rectangle(300,250,370,320);
        rectangle(400,250,470,320);
        rectangle(500,250,570,320);


        char arr[60];
        int arr1[4];
        arr1[0]=rand()%4;
        sprintf(arr,"Data/image/pro%d.jpg",arr1[0]+1);
        readimagefile(arr,200,250,270,320);

        arr1[1]=rand()%4;
        sprintf(arr,"Data/image/pro%d.jpg",arr1[1]+1);
        readimagefile(arr,300,250,370,320);

        arr1[2]=rand()%4;
        sprintf(arr,"Data/image/pro%d.jpg",arr1[2]+1);
        readimagefile(arr,400,250,470,320);

        arr1[3]=rand()%4;
        sprintf(arr,"Data/image/pro%d.jpg",arr1[3]+1);
        readimagefile(arr,500,250,570,320);
        int k=0;
        int flag=0;
        char TIME[100];
        int time1,time2,time;
        time1 = clock();
        time = 0;

        for(int i=0; i<4; i++)
        {


            while(1)
            {

                if(ismouseclick((WM_LBUTTONDOWN)))
                {

                    int x,y;
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    printf("%d %d\n",x,y);
                    if(x>753 && x<899 && y>627 &&y<687)
                    {
                        mciSendString("play Data/Audio/sct.wav",0,0,0);
                        play();
                    }
                    if(x>=200 && x<=270 && y>=500 && y<=570)
                    {

                        k=0;


                        break;
                    }
                    if(x>=300 && x<=370 && y>=500 && y<=570)
                    {
                        k=1;


                        break;
                    }
                    if(x>=400 && x<=470 && y>=500 && y<=570)
                    {
                        k=2;

                        break;
                    }
                    if(x>=500 && x<=570 && y>=500 && y<=570)
                    {
                        k=3;


                        break;
                    }
                }
                time2=clock();
                if(time!=(time2-time1)/CLOCKS_PER_SEC)
                {
                    time = (time2-time1)/CLOCKS_PER_SEC;

                    if(time>4)
                    {
                        flag=-1;
                        break;
                    }
                    else
                    {
                        sprintf(TIME,"%d:%d", time/60,time%60);
                        outtextxy(380,410,TIME);
                    }
                }
            }
            if(arr1[i]!=k)
            {
                g=1;
                atm-=1;
                break;
            }
            else
            {
                if(i==0)
                    readimagefile("Data/image/images.jpg",200,250,270,320);
                else if(i==1)
                    readimagefile("Data/image/images.jpg",300,250,370,320);
                else if(i==2)
                    readimagefile("Data/image/images.jpg",400,250,470,320);
                else
                    readimagefile("Data/image/images.jpg",500,250,570,320);
                str2[0]++;


            }
        }
        if(g)
            x--;
        str1[0]--;
        if (atm==0)
        {
            gameover();
        }
        else if(str1[0]==0)
            break;
    }
}
void showattempt1(int n)
{
    char atm[5];
    sprintf(atm,"%d",n);
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(getpixel(821,23));
    setcolor(BLACK);
    outtextxy(823,20,atm);
}
