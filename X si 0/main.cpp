#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<winbgim.h>
#include<stdlib.h>

using namespace std;

void meniu(){
    initwindow(600,600,"Meniul principal");
    setbkcolor(BLACK);
    setcolor(YELLOW);

    int font = 10;
    int direction = 0;
    int font_size = 10;
    settextstyle(font, direction, font_size);
    outtextxy(10,100," X si 0");
    font = 8;
    direction = 0;
    font_size = 5;
    settextstyle(font, direction, font_size);
    rectangle(210, 340, 380, 400);
    outtextxy(230,350,"JOACA");
    rectangle(120,420, 490, 480);
    outtextxy(140,430,"CUM SE JOACA?");
    rectangle(210,500, 390, 560);
    outtextxy(220,510,"IESIRE");

}

void patrat(int x, int y, int l){
    line(x,y,x+l,y);
    line(x,y,x,y+l);
    line(x+l,y,x+l,y+l);
    line(x+l,y+l,x,y+l);
}

void tabla_de_joc(){
    initwindow(600,600,"X si 0");
    setbkcolor(BLACK);
    setcolor(YELLOW);
    int x=51, y=51, l=166;
    for(int i=0; i<498; i+=166){
        for(int j=0; j<498; j+=166){
            patrat(x+i, y+j, l);
        }
    }
    //getch();
    //closegraph();
}

void reguli(){
    initwindow(600,600,"Reguli");
    setbkcolor(BLACK);
    setcolor(YELLOW);
    int font = 8;
    int direction = 0;
    int font_size = 6;
    settextstyle(font, direction, font_size);
    outtextxy(30,50,"REGULILE JOCULUI");
    font_size=3;
    settextstyle(font, direction, font_size);
    outtextxy(30,150,"Se joaca in 2 jucatori.");
    outtextxy(30,200,"Jucatorul 1 este cel cu simbolul 'X'.");
    outtextxy(30,225,"Jucatorul 2 este cel cu simbolul '0'.");
    outtextxy(30,250,"Scopul jocului este ca unul dintre");
    outtextxy(5,275,"jucatori sa reuseasca sa obtina o linie,");
    outtextxy(5,300,"o diagonala sau o coloana marcata cu");
    outtextxy(5,325,"simbolul propriu( X sau 0 ).");
    outtextxy(30,350,"Daca unul dintre jucatori reuseste");
    outtextxy(5,375,"acest lucru, acesta va fi castigatorul.");
    outtextxy(30,400,"Daca niciunul nu va reusi sa obtina 3");
    outtextxy(5,425,"simboluri intr-o linie, coloana sau");
    outtextxy(5,450,"diagonala, jocul nu va avea castigator.");
    setcolor(RED);
    outtextxy(30,500,"Apasati tasta M pentru a reveni la");
    outtextxy(5,525,"meniul principal.");
    getch();
    closegraph();
}

void iesire(){
    initwindow(600,200,"Iesire");
    setcolor(YELLOW);
    int font = 4;
    int direction = 0;
    int font_size = 3;
    settextstyle(font, direction, font_size);
    outtextxy(20,40,"Esti sigur ca vrei sa parasesti jocul?");
    outtextxy(20, 70, "Apasa:");
    rectangle(40, 100, 250, 150);
    outtextxy(50,115,"D pentru DA");
    rectangle(350, 100, 565, 150);
    outtextxy(360,115,"N pentru NU");

    getch();
    closegraph();

}

void o(int x,int y){
    setcolor(YELLOW);
    for(int i=0; i<=4; i++)
        circle(x,y,50+i);
}

void x(int x,int y){
    setcolor(YELLOW);
    for(int i=0; i<=5; i++)
        line(x-50+i,y-50,x+50,y+50-i);
    for(int i=0; i<=4; i++)
        line(x+50-i,y-50,x-50,y+50+i);
}

void pune(int turn, int p){
    switch(p)
    {
        case 1:
            if(turn==1)
                x(134,134);
            else
                o(134,134);
            break;
        case 2:
            if(turn==1)
                x(300,134);
            else
                o(300,134);
            break;
        case 3:
            if(turn==1)
                x(466,134);
            else
                o(466,134);
            break;
        case 4:
            if(turn==1)
                x(134,300);
            else
                o(134,300);
            break;
        case 5:
            if(turn==1)
                x(300,300);
            else
                o(300,300);
            break;
        case 6:
            if(turn==1)
                x(466,300);
            else
                o(466,300);
            break;
        case 7:
            if(turn==1)
                x(134,466);
            else
                o(134,466);
            break;
        case 8:
            if(turn==1)
                x(300,466);
            else
                o(300,466);
            break;
        case 9:
            if(turn==1)
                x(466,466);
            else
                o(466,466);
            break;

    }


}

int verificare(char *a){
    // returnez  0 nimeni nu castiga || 1 castiga jucatorul 1 || 2 castiga jucatorul 2

    //diagonala
    if((a[0]==a[4] && a[0]==a[8] && a[0]=='X') || (a[2]==a[4] && a[2]==a[6] && a[2]=='X'))
        return 1;
    else if((a[0]==a[4] && a[0]==a[8] && a[0]=='O') || (a[2]==a[4] && a[2]==a[6] && a[2]=='O'))
        return 2;

    // orizontala
    if((a[0]==a[1] && a[1]==a[2] && a[0]=='X') || (a[3]==a[4] && a[4]==a[5] && a[3]=='X') || (a[6]==a[7] && a[7]==a[8] && a[6]=='X'))
        return 1;
    else if((a[0]==a[1] && a[1]==a[2] && a[0]=='O') || (a[3]==a[4] && a[4]==a[5] && a[3]=='O') || (a[6]==a[7] && a[7]==a[8] && a[6]=='O'))
        return 2;

    //verticala
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='X') || (a[1]==a[4] && a[4]==a[7] && a[1]=='X') || (a[2]==a[5] && a[5]==a[8] && a[2]=='X'))
        return 1;
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='O') || (a[1]==a[4] && a[4]==a[7] && a[1]=='O') || (a[2]==a[5] && a[5]==a[8] && a[2]=='O'))
        return 2;

    return 0;
}

void castigator(int x){
    if(x==1){
        initwindow(600,600,"Castigator1");
        readimagefile("cupa.jpg", 100, 200, 500, 500);
        settextstyle(8, 0, 6);
        setcolor(YELLOW);
        outtextxy(140,50,"CASTIGATOR");
        outtextxy(125,100,"JUCATORUL 1");
        settextstyle(8,0,3);
        setcolor(RED);
        outtextxy(30,525,"Apasati tasta M pentru a reveni la");
        outtextxy(30,550,"meniul principal.");
    }
    else if(x==2){
        initwindow(600,600,"Castigator2");
        readimagefile("cupa.jpg", 100, 200, 500, 500);
        settextstyle(8, 0, 6);
        setcolor(YELLOW);
        outtextxy(140,50,"CASTIGATOR");
        outtextxy(125,100,"JUCATORUL 2");
        settextstyle(8,0,3);
        setcolor(RED);
        outtextxy(30,525,"Apasati tasta M pentru a reveni la");
        outtextxy(30,550,"meniul principal.");
    }
    else if(x==0){
        initwindow(600,600,"NOCastigator");
        readimagefile("sad.jpg", 100, 200, 500, 500);
        settextstyle(8, 0, 6);
        setcolor(YELLOW);
        outtextxy(120,50,"NICIUNUL NU");
        outtextxy(135,100,"A CASTIGAT");
        settextstyle(8,0,3);
        setcolor(RED);
        outtextxy(30,525,"Apasati tasta M pentru a reveni la");
        outtextxy(30,550,"meniul principal.");

    }
}

int main()
{
    char b[9];
    for(int i=0;i<9;i++)
        b[i]=0;
    int x=0;
    int tura=1;
    int mov=0;

    deaici:

    x=0;
    tura=1;
    mov=0;
    for(int i=0;i<9;i++)
        b[i]=0;

    meniu();
    POINT mouse;
    while(1){
        GetCursorPos(&mouse);
        long x=mousex();
        long y=mousey();
        if(GetAsyncKeyState(VK_LBUTTON)){
            if((x>210 && x<380) && (y>340 && y<400)){
                closegraph();
                tabla_de_joc();
                delay(200);
                break;
            }
            if((x>120 && x<490) && (y>420 && y<480)){
                closegraph();
                reguli();
                if (GetKeyState('M') < 0) // daca am apasat M
                    goto deaici;
            }
            if((x>210 && x<390) && (y>500 && y<560)){
                iesire();
                if (GetKeyState('D') < 0)
                    exit(0);
                if (GetKeyState('N') < 0)
                    goto deaici;
            }
        }
    }

    while(x==0 && mov<=9){
        if(GetAsyncKeyState(VK_RBUTTON))
        {
            GetCursorPos(&mouse);
            long X=mousex();
            long Y=mousey();
                if(X>51 && X<217 && Y>51 && Y<217 && b[0]==0)     //0
                {
                    pune(tura,1);
                    mov++;
                    if(tura==1)
                        b[0]='X';
                    else
                        b[0]='O';
                }
                else if(X>217 && X<383 && Y>51 && Y<217 && b[1]==0)     //1
                {
                    pune(tura,2);
                    mov++;
                    if(tura==1)
                        b[1]='X';
                    else
                        b[1]='O';
                }
                else if(X>383 && X<549 && Y>51 && Y<217 && b[2]==0)     //2
                {
                    pune(tura,3);
                    mov++;
                    if(tura==1)
                        b[2]='X';
                    else
                        b[2]='O';
                }
                else if(X>51 && X<217 && Y>217 && Y<383 && b[3]==0)     //3
                {
                    pune(tura,4);
                    mov++;
                    if(tura==1)
                        b[3]='X';
                    else
                        b[3]='O';
                }
                else if(X>217 && X<383 && Y>217 && Y<383 && b[4]==0)     //4
                {
                    pune(tura,5);
                    mov++;
                    if(tura==1)
                        b[4]='X';
                    else
                        b[4]='O';
                }
                else if(X>383 && X<549 && Y>217 && Y<383 && b[5]==0)     //5
                {
                    pune(tura,6);
                    mov++;
                    if(tura==1)
                        b[5]='X';
                    else
                        b[5]='O';
                }
                else if(X>51 && X<217 && Y>383 && Y<549 && b[6]==0)     //6
                {
                    pune(tura,7);
                    mov++;
                    if(tura==1)
                        b[6]='X';
                    else
                        b[6]='O';
                }
                else if(X>217 && X<383 && Y>383 && Y<549 && b[7]==0)     //7
                {
                    pune(tura,8);
                    mov++;
                    if(tura==1)
                        b[7]='X';
                    else
                        b[7]='O';
                }
                else if(X>383 && X<549 && Y>383 && Y<549 && b[8]==0)     //8
                {
                    pune(tura,9);
                    mov++;
                    if(tura==1)
                        b[8]='X';
                    else
                        b[8]='O';
                }
            if(mov){
                if(mov%2==0)
                    tura=1;
                else
                    tura=0;

            x=verificare(b);
            delay(200);
            if(x!=0 || mov>=9){
                closegraph();
                if(x==1 || x==2 || x==0){
                    castigator(x);
                    getch();
                    if (GetKeyState('M') < 0){ // daca am apasat M
                        closegraph();
                        goto deaici;
                    }
                }
            }
            }
        }
    }
    getch();

    return 0;
}
