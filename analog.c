#include <graphics.h>
#include<math.h>
#include<ctime>

#define S_N_L (radius-10)              // Second Needle Length
#define S_N_C RED                     // Second needle Color
#define M_N_L (radius-20)            // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))  // Hour Needle Length
#define H_N_C CYAN                // Hour Needle Color

float cx,cy;
float radius=100;

void draw_face(float radius);
void get_time(int &h,int &m,int &s);
void second_needle(int s);
void minute_needle(int m,int s);
void hour_needle(int h,int m,int s);

int main(void)
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,NULL);

outtextxy(200,100,"Analog Clock");

cx=getmaxx()/2.0; 
cy=getmaxy()/2.0; 

float x,y;
int hour,minute,second;
draw_face(radius);

while(1){
circle(cx,cy,2);
get_time(hour,minute,second);
second_needle(second);
minute_needle(minute,second);
hour_needle(hour,minute,second);
}

getch();
closegraph();
return 0;
}

void draw_face(float radius)
{
int theta=0;
float x,y;

circle(cx,cy,radius+24);
circle(cx,cy,radius+23);
circle(cx,cy,2);

int i=0,num=0,cl;
char* array[12]={"3","4","5","6","7","8","9","10","11","12","1","2"};
do{
x=cx+radius*cos(theta*M_PI/180);
y=cy+radius*sin(theta*M_PI/180);

outtextxy(x,y,array[num]);
theta+=30;
num++;
i++;
}while(i!=12);

}

void get_time(int &h,int &m,int &s)
{
time_t rawtime;
struct tm *t;
time(&rawtime);
t = localtime(&rawtime);
h=t->tm_hour;
m=t->tm_min;
s=t->tm_sec;
}

void second_needle(int s)
{
float angle=-90;
float sx,sy;
setcolor(0);
sx=cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
sy=cy+S_N_L*sin((angle+s*6-6)*M_PI/180);

line(cx,cy,sx,sy);
setcolor(S_N_C);

sx=cx+S_N_L*cos((angle+s*6)*M_PI/180);
sy=cy+S_N_L*sin((angle+s*6)*M_PI/180);

line(cx,cy,sx,sy);
}

void minute_needle(int m,int s)
{
float angle=-90;

float sx,sy;
setcolor(0);

sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);

line(cx,cy,sx,sy);
setcolor(M_N_C);

sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);

line(cx,cy,sx,sy);
}

void hour_needle(int h,int m,int s)
{
float angle=-90;
float sx,sy;

setcolor(0);
sx=cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);

line(cx,cy,sx,sy);
setcolor(H_N_C);

sx=cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);

line(cx,cy,sx,sy);
}
