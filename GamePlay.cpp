//
// Created by Mohammad Sadegh Salehi.
//
#include "GamePlay.h"
#include <string>
#include <ctime>
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/QApplication>
using namespace std;


GamePlay::GamePlay(int height, int width, QWidget *parent) {
    this -> setGeometry( width ,  height , width, height);
    QPalette palette1 = palette();
    palette1.setColor(QPalette::Background, Qt::darkBlue);
    this->setAutoFillBackground(true);
    this->setPalette(palette1);

    cpuScore=new QLabel(str1,this);
    cpuScore->setGeometry(50,10,120,40);
    cpuScore->setStyleSheet("background-color: gray;border-radius:10px;");
    cpuScore->setAlignment(Qt::AlignCenter);
    playerScore=new QLabel(str2,this);
    playerScore->setGeometry(330,10,120,40);
    playerScore->setStyleSheet("background-color: gray;border-radius:10px;");
    playerScore->setAlignment(Qt::AlignCenter);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            piece[i][j]= new QPushButton(this);
            piece[i][j]->setGeometry(50+(j*50),100+(50*i),50,50);
            piece[i][j]->setStyleSheet("background-color: green;border: 0.5px solid black;");

            plate[i][j]= new QLabel(this);
            //plate[i][j]->setGeometry(52+(j*50),102+(50*i),46,46);
            plate[i][j]->setStyleSheet("background-color: rgba(0,0,0,0%);border-radius:25px;");

            handler[i][j]=-1;
            temp[i][j]=-1;
        }
    }
    plate[3][3]->setGeometry(52+(3*50),102+(50*3),46,46);plate[4][3]->setGeometry(52+(3*50),102+(50*4),46,46);
    plate[3][4]->setGeometry(52+(4*50),102+(50*3),46,46);plate[4][4]->setGeometry(52+(4*50),102+(50*4),46,46);
    plate[3][3]->setStyleSheet("background-color: white;border-radius:23px;");handler[3][3]=0;
    plate[4][3]->setStyleSheet("background-color: black;border-radius:23px;");handler[4][3]=1;
    plate[3][4]->setStyleSheet("background-color: black;border-radius:23px;");handler[3][4]=1;
    plate[4][4]->setStyleSheet("background-color: white;border-radius:23px;");handler[4][4]=0;

    connect(piece[0][0], SIGNAL(clicked()), this, SLOT(click00()));
    connect(piece[1][0], SIGNAL(clicked()), this, SLOT(click10()));
    connect(piece[2][0], SIGNAL(clicked()), this, SLOT(click20()));
    connect(piece[3][0], SIGNAL(clicked()), this, SLOT(click30()));
    connect(piece[4][0], SIGNAL(clicked()), this, SLOT(click40()));
    connect(piece[5][0], SIGNAL(clicked()), this, SLOT(click50()));
    connect(piece[6][0], SIGNAL(clicked()), this, SLOT(click60()));
    connect(piece[7][0], SIGNAL(clicked()), this, SLOT(click70()));
    connect(piece[0][1], SIGNAL(clicked()), this, SLOT(click01()));
    connect(piece[1][1], SIGNAL(clicked()), this, SLOT(click11()));
    connect(piece[2][1], SIGNAL(clicked()), this, SLOT(click21()));
    connect(piece[3][1], SIGNAL(clicked()), this, SLOT(click31()));
    connect(piece[4][1], SIGNAL(clicked()), this, SLOT(click41()));
    connect(piece[5][1], SIGNAL(clicked()), this, SLOT(click51()));
    connect(piece[6][1], SIGNAL(clicked()), this, SLOT(click61()));
    connect(piece[7][1], SIGNAL(clicked()), this, SLOT(click71()));
    connect(piece[0][2], SIGNAL(clicked()), this, SLOT(click02()));
    connect(piece[1][2], SIGNAL(clicked()), this, SLOT(click12()));
    connect(piece[2][2], SIGNAL(clicked()), this, SLOT(click22()));
    connect(piece[3][2], SIGNAL(clicked()), this, SLOT(click32()));
    connect(piece[4][2], SIGNAL(clicked()), this, SLOT(click42()));
    connect(piece[5][2], SIGNAL(clicked()), this, SLOT(click52()));
    connect(piece[6][2], SIGNAL(clicked()), this, SLOT(click62()));
    connect(piece[7][2], SIGNAL(clicked()), this, SLOT(click72()));
    connect(piece[0][3], SIGNAL(clicked()), this, SLOT(click03()));
    connect(piece[1][3], SIGNAL(clicked()), this, SLOT(click13()));
    connect(piece[2][3], SIGNAL(clicked()), this, SLOT(click23()));
    connect(piece[3][3], SIGNAL(clicked()), this, SLOT(click33()));
    connect(piece[4][3], SIGNAL(clicked()), this, SLOT(click43()));
    connect(piece[5][3], SIGNAL(clicked()), this, SLOT(click53()));
    connect(piece[6][3], SIGNAL(clicked()), this, SLOT(click63()));
    connect(piece[7][3], SIGNAL(clicked()), this, SLOT(click73()));
    connect(piece[0][4], SIGNAL(clicked()), this, SLOT(click04()));
    connect(piece[1][4], SIGNAL(clicked()), this, SLOT(click14()));
    connect(piece[2][4], SIGNAL(clicked()), this, SLOT(click24()));
    connect(piece[3][4], SIGNAL(clicked()), this, SLOT(click34()));
    connect(piece[4][4], SIGNAL(clicked()), this, SLOT(click44()));
    connect(piece[5][4], SIGNAL(clicked()), this, SLOT(click54()));
    connect(piece[6][4], SIGNAL(clicked()), this, SLOT(click64()));
    connect(piece[7][4], SIGNAL(clicked()), this, SLOT(click74()));
    connect(piece[0][5], SIGNAL(clicked()), this, SLOT(click05()));
    connect(piece[1][5], SIGNAL(clicked()), this, SLOT(click15()));
    connect(piece[2][5], SIGNAL(clicked()), this, SLOT(click25()));
    connect(piece[3][5], SIGNAL(clicked()), this, SLOT(click35()));
    connect(piece[4][5], SIGNAL(clicked()), this, SLOT(click45()));
    connect(piece[5][5], SIGNAL(clicked()), this, SLOT(click55()));
    connect(piece[6][5], SIGNAL(clicked()), this, SLOT(click65()));
    connect(piece[7][5], SIGNAL(clicked()), this, SLOT(click75()));
    connect(piece[0][6], SIGNAL(clicked()), this, SLOT(click06()));
    connect(piece[1][6], SIGNAL(clicked()), this, SLOT(click16()));
    connect(piece[2][6], SIGNAL(clicked()), this, SLOT(click26()));
    connect(piece[3][6], SIGNAL(clicked()), this, SLOT(click36()));
    connect(piece[4][6], SIGNAL(clicked()), this, SLOT(click46()));
    connect(piece[5][6], SIGNAL(clicked()), this, SLOT(click56()));
    connect(piece[6][6], SIGNAL(clicked()), this, SLOT(click66()));
    connect(piece[7][6], SIGNAL(clicked()), this, SLOT(click76()));
    connect(piece[0][7], SIGNAL(clicked()), this, SLOT(click07()));
    connect(piece[1][7], SIGNAL(clicked()), this, SLOT(click17()));
    connect(piece[2][7], SIGNAL(clicked()), this, SLOT(click27()));
    connect(piece[3][7], SIGNAL(clicked()), this, SLOT(click37()));
    connect(piece[4][7], SIGNAL(clicked()), this, SLOT(click47()));
    connect(piece[5][7], SIGNAL(clicked()), this, SLOT(click57()));
    connect(piece[6][7], SIGNAL(clicked()), this, SLOT(click67()));
    connect(piece[7][7], SIGNAL(clicked()), this, SLOT(click77()));

    run();
}


GamePlay::~GamePlay() {

}

void GamePlay::checkValid() {
    int x=0,y=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(handler[i][j]==1)
            {   x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    x++;
                    if(handler[x][y]==0&&x<7&&y<8&&handler[++x][y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    x--;
                    if(handler[x][y]==0&&x>0&&y>=0&&handler[--x][y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y++;
                    if(handler[x][y]==0&&x<8&&y<7&&handler[x][++y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y--;
                    if(handler[x][y]==0&&x>=0&&y>0&&handler[x][--y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y--;x--;
                    if(handler[x][y]==0&&x>0&&y>0&&handler[--x][--y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y++;x++;
                    if(handler[x][y]==0&&x<7&&y<7&&handler[++x][++y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y++;x--;
                    if(handler[x][y]==0&&x>0&&y<7&&handler[--x][++y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x<8&&y<8&&x>=0&&y>=0)
                {
                    y--;x++;
                    if(handler[x][y]==0&&x<7&&y>0&&handler[++x][--y]==-1)
                    {
                        temp[x][y]=1;
                    }
                }
            }
        }
    }
    }

void GamePlay::paint() {
    cScore=0;pScore=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(handler[i][j]==0)
            {
                cScore++;
                plate[i][j]->setGeometry(52+(j*50),102+(50*i),46,46);
                plate[i][j]->setStyleSheet("background-color: white;border-radius:23px;");
            }
            else if(handler[i][j]==1)
            {
                pScore++;
                plate[i][j]->setGeometry(52+(j*50),102+(50*i),46,46);
                plate[i][j]->setStyleSheet("background-color: black;border-radius:23px;");
            }
        }
    }
    if(cScore>9)
    {
        cScored2=(cScore%10)+48;
        cScored1=(cScore/10)+48;
    }
    else{
    cScored1='0';cScored2=cScore+48;
    }
    if(pScore>9)
    {
        pScored2=(pScore%10)+48;
        pScored1=(pScore/10)+48;
    }
    else{
        pScored1='0';pScored2=pScore+48;
    }
    str1= "cpu score: ";str2="player score: ";
    cS1=cScored1;cS2=cScored2;pS1=pScored1;pS2=pScored2;
    str1=str1+cS1;str1=str1+cS2;
    str2=str2+pS1;str2=str2+pS2;
    cpuScore->setText(str1);
    playerScore->setText(str2);
}

void GamePlay::changeB(int x,int y) {
    int i=x;int j=y;int count=0;
    i++;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v1= true;break;}

        i++;
    }
    i=x;j=y;i++;
    while (count!=0&&v1)
    {
        handler[i][j]=1;
        count--;
        i++;
    }
    i=x;j=y;count=0;
    i--;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v2= true;break;}
        i--;
    }
    i=x;j=y;i--;
    while (count!=0&&v2)
    {
        handler[i][j]=1;
        count--;
        i--;
    }
    i=x;j=y;
    j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v3= true;break;}
        j--;
    }
    i=x;j=y;j--;
    while (count!=0&&v3)
    {
        handler[i][j]=1;
        count--;
        j--;
    }
    i=x;j=y;
    j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v4= true;break;}
        j++;
    }
    i=x;j=y;j++;
    while (count!=0&&v4)
    {
        handler[i][j]=1;
        count--;
        j++;
    }
    i=x;j=y;
    i--;j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v5= true;break;}
        i--;j--;
    }
    i=x;j=y;i--;j--;
    while (count!=0&&v5)
    {
        handler[i][j]=1;
        count--;
        i--;j--;
    }
    i=x;j=y;
    i++;j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v6= true;break;}
        i++;j++;
    }
    i=x;j=y;i++;j++;
    while (count!=0&&v6)
    {
        handler[i][j]=1;
        count--;
        i++;j++;
    }
    i=x;j=y;
    i--;j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v7= true;break;}
        i--;j++;
    }
    i=x;j=y;i--;j++;
    while (count!=0&&v7)
    {
        handler[i][j]=1;
        count--;
        i--;j++;
    }
    i=x;j=y;
    i++;j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==1)
        { break;count--;}
        else if(handler[i][j]==1)
        { v8= true;break;}
        i++;j--;
    }
    i=x;j=y;i++;j--;
    while (count!=0&&v8)
    {
        handler[i][j]=1;
        count--;
        i++;j--;
    }
    v1=0;v2=0;v3=0;v4=0;v5=0;v6=0;v7=0;v8=0;
}

void GamePlay::changeW(int x, int y) {
    int i=x;int j=y;int count=0;
    i++;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v1= true;break;}

        i++;
    }
    i=x;j=y;i++;
    while (count!=0&&v1)
    {
        handler[i][j]=0;
        count--;
        i++;
    }
    i=x;j=y;count=0;
    i--;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v2= true;break;}
        i--;
    }
    i=x;j=y;i--;
    while (count!=0&&v2)
    {
        handler[i][j]=0;
        count--;
        i--;
    }
    i=x;j=y;
    j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v3= true;break;}
        j--;
    }
    i=x;j=y;j--;
    while (count!=0&&v3)
    {
        handler[i][j]=0;
        count--;
        j--;
    }
    i=x;j=y;
    j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v4= true;break;}
        j++;
    }
    i=x;j=y;j++;
    while (count!=0&&v4)
    {
        handler[i][j]=0;
        count--;
        j++;
    }
    i=x;j=y;
    i--;j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v5= true;break;}
        i--;j--;
    }
    i=x;j=y;i--;j--;
    while (count!=0&&v5)
    {
        handler[i][j]=0;
        count--;
        i--;j--;
    }
    i=x;j=y;
    i++;j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v6= true;break;}
        i++;j++;
    }
    i=x;j=y;i++;j++;
    while (count!=0&&v6)
    {
        handler[i][j]=0;
        count--;
        i++;j++;
    }
    i=x;j=y;
    i--;j++;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v7= true;break;}
        i--;j++;
    }
    i=x;j=y;i--;j++;
    while (count!=0&&v7)
    {
        handler[i][j]=0;
        count--;
        i--;j++;
    }
    i=x;j=y;
    i++;j--;count=0;
    while((handler[i][j]==0||handler[i][j]==1)&&i<8&&j<8&&i>=0&&j>=0)
    {
        count++;
        if(count==1&&handler[i][j]==0)
        { break;count--;}
        else if(handler[i][j]==0)
        { v8= true;break;}
        i++;j--;
    }
    i=x;j=y;i++;j--;
    while (count!=0&&v8)
    {
        handler[i][j]=0;
        count--;
        i++;j--;
    }
    v1=0;v2=0;v3=0;v4=0;v5=0;v6=0;v7=0;v8=0;
}

void GamePlay::hint() {
    bool nothing=true;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(temp[i][j]==1) {
                piece[i][j]->setStyleSheet("background-color: blue;");
                nothing= false;
            }
        }
    }
    if(nothing)
    {
        cpu();
    }
}

void GamePlay::reset(int x,int y) {
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(temp[i][j]==1) {
                piece[i][j]->setStyleSheet("background-color: green;border: 0.5px solid black;");
            }
            temp[i][j]=-1;
        }
    }
    v1=0;v2=0;v3=0;v4=0;v5=0;v6=0;v7=0;v8=0;
}
void GamePlay::cpu() {
    if(cScore+pScore<64) {
        checkValidCpu();

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(temp[i][j]==0)
                {

                    handler[i][j]=0;
                    changeW(i,j);
                    reset(i,j);
                    break;
                }
            }
        }
        counter++;
        paint();
        run();
    }
    else
    {
        QMessageBox msgBox;
        if(pScore>cScore) {
            msgBox.setText("               You won              ");
        } else if(pScore<cScore){
            msgBox.setText("               CPU won              ");
        } else{
            msgBox.setText("               Draw              ");
        }
        msgBox.exec();
    }
}
void GamePlay::run() {

    checkValid();
    hint();
    bool va=false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(temp[i][j]==1)
            {
               va= true;
            }
        }
    }
    if(!va)
    {
        reset(0,0);
        cpu();
    }

}

void GamePlay::checkValidCpu() {
    int x=0,y=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(handler[i][j]==0)
            {   x=i;y=j;
                while(handler[x][y]!=-1&&x<8)
                {
                    x++;
                    if(handler[x][y]==1&&x<7&&y<8&&handler[++x][y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&x>=0)
                {
                    x--;
                    if(handler[x][y]==1&&x>0&&y>=0&&handler[--x][y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y<8)
                {
                    y++;
                    if(handler[x][y]==1&&x<8&&y<7&&handler[x][++y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y>=0)
                {
                    y--;
                    if(handler[x][y]==1&&x>=0&&y>0&&handler[x][--y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y>=0&&x>=0)
                {
                    y--;x--;
                    if(handler[x][y]==1&&x>0&&y>0&&handler[--x][--y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y<8&&x<8)
                {
                    y++;x++;
                    if(handler[x][y]==1&&x<7&&y<7&&handler[++x][++y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y<8&&x>=0)
                {
                    y++;x--;
                    if(handler[x][y]==1&&x>0&&y<7&&handler[--x][++y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
                x=i;y=j;
                while(handler[x][y]!=-1&&y>=0&&x<8)
                {
                    y--;x++;
                    if(handler[x][y]==1&&x<7&&y>0&&handler[++x][--y]==-1)
                    {
                        temp[x][y]=0;
                    }
                }
            }
        }
    }
}

void GamePlay::click00() {
if (temp[0][0]==1)
{
    handler[0][0]=1;
    changeB(0,0);
    paint();
    reset(0,0);
    counter++;
    cpu();
}
}

void GamePlay::click10() {
    if (temp[1][0]==1)
    {
        handler[1][0]=1;
        changeB(1,0);
        paint();
        reset(1,0);
        counter++;
        cpu();
    }
}

void GamePlay::click20() {
    if (temp[2][0]==1)
    {
        handler[2][0]=1;
        changeB(2,0);
        paint();
        reset(2,0);
        counter++;
        cpu();
    }
}

void GamePlay::click30() {
    if (temp[3][0]==1)
    {
        handler[3][0]=1;
        changeB(3,0);
        paint();
        reset(3,0);
        counter++;
        cpu();
    }
}

void GamePlay::click40() {
    if (temp[4][0]==1)
    {
        handler[4][0]=1;
        changeB(4,0);
        paint();
        reset(4,0);
        counter++;
        cpu();
    }
}

void GamePlay::click50() {
    if (temp[5][0]==1)
    {
        handler[5][0]=1;
        changeB(5,0);
        paint();
        reset(5,0);
        counter++;
        cpu();
    }
}

void GamePlay::click60() {
    if (temp[6][0]==1)
    {
        handler[6][0]=1;
        changeB(6,0);
        paint();
        reset(6,0);
        counter++;
        cpu();
    }
}

void GamePlay::click70() {
    if (temp[7][0]==1)
    {
        handler[7][0]=1;
        changeB(7,0);
        paint();
        reset(7,0);
        counter++;
        cpu();
    }
}

void GamePlay::click01() {
    if (temp[0][1]==1)
    {
        handler[0][1]=1;
        changeB(0,1);
        paint();
        reset(0,1);
        counter++;
        cpu();
    }
}

void GamePlay::click11() {
    if (temp[1][1]==1)
    {
        handler[1][1]=1;
        changeB(1,1);
        paint();
        reset(1,1);
        counter++;
        cpu();
    }
}

void GamePlay::click21() {
    if (temp[2][1]==1)
    {
        handler[2][1]=1;
        changeB(2,1);
        paint();
        reset(2,1);
        counter++;
        cpu();
    }
}

void GamePlay::click31() {
    if (temp[3][1]==1)
    {
        handler[3][1]=1;
        changeB(3,1);
        paint();
        reset(3,1);
        counter++;
        cpu();
    }
}

void GamePlay::click41() {
    if (temp[4][1]==1)
    {
        handler[4][1]=1;
        changeB(4,1);
        paint();
        reset(4,1);
        counter++;
        cpu();
    }
}

void GamePlay::click51() {
    if (temp[5][1]==1)
    {
        handler[5][1]=1;
        changeB(5,1);
        paint();
        reset(5,1);
        counter++;
        cpu();
    }
}

void GamePlay::click61() {
    if (temp[6][1]==1)
    {
        handler[6][1]=1;
        changeB(6,1);
        paint();
        reset(6,1);
        counter++;
        cpu();
    }
}

void GamePlay::click71() {
    if (temp[7][1]==1)
    {
        handler[7][1]=1;
        changeB(7,1);
        paint();
        reset(7,1);
        counter++;
        cpu();
    }
}

void GamePlay::click02() {
    if (temp[0][2]==1)
    {
        handler[0][2]=1;
        changeB(0,2);
        paint();
        reset(0,2);
        counter++;
        cpu();
    }
}

void GamePlay::click12() {
    if (temp[1][2]==1)
    {
        handler[1][2]=1;
        changeB(1,2);
        paint();
        reset(1,2);
        counter++;
        cpu();
    }
}

void GamePlay::click22() {
    if (temp[2][2]==1)
    {
        handler[2][2]=1;
        changeB(2,2);
        paint();
        reset(2,2);
        counter++;
        cpu();
    }
}

void GamePlay::click32() {
    if (temp[3][2]==1)
    {
        handler[3][2]=1;
        changeB(3,2);
        paint();
        reset(3,2);
        counter++;
        cpu();
    }
}

void GamePlay::click42() {
    if (temp[4][2]==1)
    {
        handler[4][2]=1;
        changeB(4,2);
        paint();
        reset(4,2);
        counter++;
        cpu();
    }
}

void GamePlay::click52() {
    if (temp[5][2]==1)
    {
        handler[5][2]=1;
        changeB(5,2);
        paint();
        reset(5,2);
        counter++;
        cpu();
    }
}

void GamePlay::click62() {
    if (temp[6][2]==1)
    {
        handler[6][2]=1;
        changeB(6,2);
        paint();
        reset(6,2);
        counter++;
        cpu();
    }
}

void GamePlay::click72() {
    if (temp[7][2]==1)
    {
        handler[7][2]=1;
        changeB(7,2);
        paint();
        reset(7,2);
        counter++;
        cpu();
    }
}

void GamePlay::click03() {
    if (temp[0][3]==1)
    {
        handler[0][3]=1;
        changeB(0,3);
        paint();
        reset(0,3);
        counter++;
        cpu();
    }
}

void GamePlay::click13() {
    if (temp[1][3]==1)
    {
        handler[1][3]=1;
        changeB(1,3);
        paint();
        reset(1,3);
        counter++;
        cpu();
    }
}

void GamePlay::click23() {
    if (temp[2][3]==1)
    {
        handler[2][3]=1;
        changeB(2,3);
        paint();
        reset(2,3);
        counter++;
        cpu();
    }
}

void GamePlay::click33() {
    if (temp[3][3]==1)
    {
        handler[3][3]=1;
        changeB(3,3);
        paint();
        reset(3,3);
        counter++;
        cpu();
    }
}

void GamePlay::click43() {
    if (temp[4][3]==1)
    {
        handler[4][3]=1;
        changeB(4,3);
        paint();
        reset(4,3);
        counter++;
        cpu();
    }
}

void GamePlay::click53() {
    if (temp[5][3]==1)
    {
        handler[5][3]=1;
        changeB(5,3);
        paint();
        reset(5,3);
        counter++;
        cpu();
    }
}

void GamePlay::click63() {
    if (temp[6][3]==1)
    {
        handler[6][3]=1;
        changeB(6,3);
        paint();
        reset(6,3);
        counter++;
        cpu();
    }
}

void GamePlay::click73() {
    if (temp[7][3]==1)
    {
        handler[7][3]=1;
        changeB(7,3);
        paint();
        reset(7,3);
        counter++;
        cpu();
    }
}

void GamePlay::click04() {
    if (temp[0][4]==1)
    {
        handler[0][4]=1;
        changeB(0,4);
        paint();
        reset(0,4);
        counter++;
        cpu();
    }
}

void GamePlay::click14() {
    if (temp[1][4]==1)
    {
        handler[1][4]=1;
        changeB(1,4);
        paint();
        reset(1,4);
        counter++;
        cpu();
    }
}

void GamePlay::click24() {
    if (temp[2][4]==1)
    {
        handler[2][4]=1;
        changeB(2,4);
        paint();
        reset(2,4);
        counter++;
        cpu();
    }
}

void GamePlay::click34() {
    if (temp[3][4]==1)
    {
        handler[3][4]=1;
        changeB(3,4);
        paint();
        reset(3,4);
        counter++;
        cpu();
    }
}

void GamePlay::click44() {
    if (temp[4][4]==1)
    {
        handler[4][4]=1;
        changeB(4,4);
        paint();
        reset(4,4);
        counter++;
        cpu();
    }
}

void GamePlay::click54() {
    if (temp[5][4]==1)
    {
        handler[5][4]=1;
        changeB(5,4);
        paint();
        reset(5,4);
        counter++;
        cpu();
    }
}

void GamePlay::click64() {
    if (temp[6][4]==1)
    {
        handler[6][4]=1;
        changeB(6,4);
        paint();
        reset(6,4);
        counter++;
        cpu();
    }
}

void GamePlay::click74() {
    if (temp[7][4]==1)
    {
        handler[7][4]=1;
        changeB(7,4);
        paint();
        reset(7,4);
        counter++;
        cpu();
    }
}

void GamePlay::click05() {
    if (temp[0][5]==1)
    {
        handler[0][5]=1;
        changeB(0,5);
        paint();
        reset(0,5);
        counter++;
        cpu();
    }
}

void GamePlay::click15() {
    if (temp[1][5]==1)
    {
        handler[1][5]=1;
        changeB(1,5);
        paint();
        reset(1,5);
        counter++;
        cpu();
    }
}

void GamePlay::click25() {
    if (temp[2][5]==1)
    {
        handler[2][5]=1;
        changeB(2,5);
        paint();
        reset(2,5);
        counter++;
        cpu();
    }
}

void GamePlay::click35() {
    if (temp[3][5]==1)
    {
        handler[3][5]=1;
        changeB(3,5);
        paint();
        reset(3,5);
        counter++;
        cpu();
    }
}

void GamePlay::click45() {
    if (temp[4][5]==1)
    {
        handler[4][5]=1;
        changeB(4,5);
        paint();
        reset(4,5);
        counter++;
        cpu();
    }
}

void GamePlay::click55() {
    if (temp[5][5]==1)
    {
        handler[5][5]=1;
        changeB(5,5);
        paint();
        reset(5,5);
        counter++;
        cpu();
    }
}

void GamePlay::click65() {
    if (temp[6][5]==1)
    {
        handler[6][5]=1;
        changeB(6,5);
        paint();
        reset(6,5);
        counter++;
        cpu();
    }
}

void GamePlay::click75() {
    if (temp[7][5]==1)
    {
        handler[7][5]=1;
        changeB(7,5);
        paint();
        reset(7,5);
        counter++;
        cpu();
    }
}

void GamePlay::click06() {
    if (temp[0][6]==1)
    {
        handler[0][6]=1;
        changeB(0,6);
        paint();
        reset(0,6);
        counter++;
        cpu();
    }
}

void GamePlay::click16() {
    if (temp[1][6]==1)
    {
        handler[1][6]=1;
        changeB(1,6);
        paint();
        reset(1,6);
        counter++;
        cpu();
    }
}

void GamePlay::click26() {
    if (temp[2][6]==1)
    {
        handler[2][6]=1;
        changeB(2,6);
        paint();
        reset(2,6);
        counter++;
        cpu();
    }
}

void GamePlay::click36() {
    if (temp[3][6]==1)
    {
        handler[3][6]=1;
        changeB(3,6);
        paint();
        reset(3,6);
        counter++;
        cpu();
    }
}

void GamePlay::click46() {
    if (temp[4][6]==1)
    {
        handler[4][6]=1;
        changeB(4,6);
        paint();
        reset(4,6);
        counter++;
        cpu();
    }
}

void GamePlay::click56() {
    if (temp[5][6]==1)
    {
        handler[5][6]=1;
        changeB(5,6);
        paint();
        reset(5,6);
        counter++;
        cpu();
    }
}

void GamePlay::click66() {
    if (temp[6][6]==1)
    {
        handler[6][6]=1;
        changeB(6,6);
        paint();
        reset(6,6);
        counter++;
        cpu();
    }
}

void GamePlay::click76() {
    if (temp[7][6]==1)
    {
        handler[7][6]=1;
        changeB(7,6);
        paint();
        reset(7,6);
        counter++;
        cpu();
    }
}

void GamePlay::click07() {
    if (temp[0][7]==1)
    {
        handler[0][7]=1;
        changeB(0,7);
        paint();
        reset(0,7);
        counter++;
        cpu();
    }
}

void GamePlay::click17() {
    if (temp[1][7]==1)
    {
        handler[1][7]=1;
        changeB(1,7);
        paint();
        reset(1,7);
        counter++;
        cpu();
    }
}

void GamePlay::click27() {
    if (temp[2][7]==1)
    {
        handler[2][7]=1;
        changeB(2,7);
        paint();
        reset(2,7);
        counter++;
        cpu();
    }
}

void GamePlay::click37() {
    if (temp[3][7]==1)
    {
        handler[3][7]=1;
        changeB(3,7);
        paint();
        reset(3,7);
        counter++;
        cpu();
    }
}

void GamePlay::click47() {
    if (temp[4][7]==1)
    {
        handler[4][7]=1;
        changeB(4,7);
        paint();
        reset(4,7);
        counter++;
        cpu();
    }
}

void GamePlay::click57() {
    if (temp[5][7]==1)
    {
        handler[5][7]=1;
        changeB(5,7);
        paint();
        reset(5,7);
        counter++;
        cpu();
    }
}

void GamePlay::click67() {
    if (temp[6][7]==1)
    {
        handler[6][7]=1;
        changeB(6,7);
        paint();
        reset(6,7);
        counter++;
        cpu();
    }
}

void GamePlay::click77() {
    if (temp[7][7]==1)
    {
        handler[7][7]=1;
        changeB(7,7);
        paint();
        reset(7,7);
        counter++;
        cpu();
    }
}



