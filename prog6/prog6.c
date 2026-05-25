#include<stdio.h>
#include<string.h>

#define rows 20
#define colm 50

void intialize(char buffer[rows][colm]);
int  iscircle(int x,int y,int centerx,int centery,int radius);
void drawcircle(char buffer[rows][colm],int  centerx,int centery,int radius);
void printcircle(char buffer[rows][colm]);


int main()
{
    char buffer[rows][colm];

    int centerx=25;
    int centery=12;
    int radius=10;

    intialize( buffer);
    drawcircle( buffer,  centerx, centery,radius);
    printcircle( buffer);

    return 0;


}
void intialize(char buffer[rows][colm]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<colm;j++)
        {
            buffer[i][j]=' ';
        }
    }
}
int  iscircle(int x,int y,int centerx,int centery,int radius)
{
    float dx;
    float dy;
    float distancesqure;

    dx=x-centerx;
    dy=(y-centery)*2;

  distancesqure=dx*dx+dy*dy;

  if(distancesqure>=radius*radius-radius && distancesqure<=radius*radius+radius)
  {
    return 1;
  }
  return 0;

}
void drawcircle(char buffer[rows][colm],int  centerx,int centery,int radius){
    for(int y=0;y<rows;y++)
    {
        for(int x=0;x<colm;x++)
        {
            if(iscircle( x, y, centerx, centery, radius))
            {
                buffer[y][x]='*';
            }
        }
    }
}
void printcircle(char buffer[rows][colm]){
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<colm;j++)
        {
            printf("%c",buffer[i][j]);
        }printf("\n");

    }
}