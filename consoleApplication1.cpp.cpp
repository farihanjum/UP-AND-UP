# include "iGraphics.h"
#include "level_header.h"
#include "life_lost.h"
#include "pausebackground.h"
//#include "ball_ract_init.h"
#define menu 0
#define START "LET'S START THE GAME!"
#define font GLUT_BITMAP_TIMES_ROMAN_24
#define show iShowBMP
#define recx rect[i].x
#define recy rect[i].y
#define paused 4
#define help 3
#define gamepage 1
#define gameover 2

struct bar{
	int x,y,w,h,col[3],hit,r,jump,pivot;
	};


bar rect[7],ball,button[4],angryball[3],speedrect[2],lifenum[3];//structure variables declared

double vel = 2,up = 10;

int num,gamestate=menu,game_over_flag=0,glut_key_disable=0,life_value=3,level_up=0,life_lost_flag=0,score_array[6]={0};
int pause_rec_x=0,pause_rec_y=300,pause_rec_w=200,paise_rec_h=30;
char ss[9];
char pictures[10][20]={"newgame.bmp","options.bmp","instructions.bmp","exit.bmp",};//menu pictures
FILE *fin;



void check_level(){

level_up=leveled_up(num);

}



void init(){

	ball.x = 100;
	ball.r = 10;
	ball.y =30;
		//ball.r;
	ball.pivot = ball.hit = 0;
	ball.jump = 0;
	ball.col[0] = 29, ball.col[1] = 29, ball.col[2] = 29;

	rect[0].x = rand()%50;
	rect[0].y = 600;
	rect[0].w = 70;
	rect[0].h = 10;
	rect[0].hit = 0;
	rect[0].col[0] = 200, rect[0].col[1] = 100, rect[0].col[2] = 100;

	rect[1].x = 100 + rand()%50;
	rect[1].y = 800;
	rect[1].w = 70;
	rect[1].h = 10;
	rect[1].hit = 0;
	rect[1].col[0] = 00, rect[1].col[1] = 00, rect[1].col[2] = 100;

	rect[2].x = 200 + rand()%50;
	rect[2].y = 700;
	rect[2].w = 70;
	rect[2].h = 10;
	rect[2].hit = 0;
	rect[2].col[0] = 100, rect[2].col[1] = 0, rect[2].col[2] = 100 ;

	rect[3].x = 300 + rand()%50;
	rect[3].y = 1000;
	rect[3].w = 70;
	rect[3].h = 10;
	rect[3].hit = 0;
	rect[3].col[0] = 100, rect[3].col[1] = 110, rect[3].col[2] = 0;

	rect[4].x = 400 + rand()%50;
	rect[4].y = 900;
	rect[4].w = 70;
	rect[4].h = 10;
	rect[4].hit = 0;
	rect[4].col[0] = 0, rect[4].col[1] = 100, rect[4].col[2] = 100;

	rect[5].x = 500 + rand()%50;
	rect[5].y = 1100;
	rect[5].w = 70;
	rect[5].h = 10;
	rect[5].hit = 0;
	rect[5].col[0] = 0, rect[5].col[1] = 100, rect[5].col[2] = 0 ;

	rect[6].x = 500 + rand()%50;
	rect[6].y = 600;
	rect[6].w = 100;
	rect[6].h = 10;
	rect[6].hit = 0;
	rect[6].col[0] = 0, rect[6].col[1] = 150, rect[6].col[2] = 300 ;

	angryball[0].x=rand()%250;
	angryball[0].y=600;
	angryball[0].r=20;

	angryball[1].x=(rand()%250)+250;
	angryball[1].y =800;
	angryball[1].r=20;

	lifenum[0].x=500;
	lifenum[0].y=530;
	lifenum[0].r=10;
	lifenum[1].x=540;
	lifenum[1].y=530;
	lifenum[1].r=10;
	lifenum[2].x=580;
	lifenum[2].y=530;
	lifenum[2].r=10;



}
void ballchange1()
{

glut_key_disable=0;
		ball.y+=2;//ballchange
	if(level_up==0)
		//&& gamestate!=paused)
	{
		num+=1;}
	else if(level_up==1 )
		//&& gamestate!=paused)
	{
		num+=3;}



}

void collDetect(){//collision Detection

	for(int i = 0; i<=6 ; i++){
		if(ball.x>=rect[i].x-ball.r && ball.x<=rect[i].w+ball.r+rect[i].x && abs(-ball.y+rect[i].y+ball.r+rect[i].h)<=5)
		{
			ball.y = rect[i].y+rect[i].h;

		}
	}

}


void rectChange()
	{

		if(level_up==0){
		for(int i = 0;i<6;i++)
		{
			rect[i].y -= 3;
			if( rect[i].y < 0) rect[i].y = 600, rect[i].x = 100*i +  rand()%50 ;
		}
			collDetect();
			//if(ball.y <= ball.r) ball.y = ball.r,up = 10,ball.jump = 0;

		}

		if(level_up==1){
		for(int i = 0;i<=6;i++)
		{

			rect[i].y -= 5;
			if( rect[i].y < 0) rect[i].y = 600, rect[i].x = 100*i +  rand()%50 ;
		}
			collDetect();
			//if(ball.y <= ball.r) ball.y = ball.r,up = 10,ball.jump = 0;


	}
}



void angryball_change()
{
	for(int i=0;i<2;i++)
	{
		angryball[i].y-=1;
		if(angryball[i].y<=20)
		{
			angryball[i].x=(rand()%250)+250*i+30;
			angryball[i].y=600;
			angryball[i].y-=1;
		}
	}
}


void angryball_touches_ball()
{
	int i;
	for(i=0;i<2;i++)
	{
		if(ball.y>=angryball[i].y  && ball.y<=angryball[i].y+20   &&  ball.x>=angryball[i].x   &&   ball.y<=angryball[i].x+30)
		{
			num=num-20;
			num++;
		}
	}
}


void speedrecto(){
		speedrect[0].x=200;
		speedrect[0].y=000;
		speedrect[0].col[0]=192,speedrect[0].col[1]=192,speedrect[0].col[2]=192;
		speedrect[0].w=70;
		speedrect[0].h=10;

		speedrect[1].x=500;
		speedrect[1].y=600;
		speedrect[1].col[0]=192,speedrect[1].col[1]=192,speedrect[1].col[2]=192;
		speedrect[1].w=70;
		speedrect[1].h=10;


}
void speedRectoChange()
{
	int i;
	for(i=0;i<2;i++){
	speedrect[i].y-=8;
	if(speedrect[i].y<=0)
	{
		speedrect[i].y=600;
	}
	}
}

void score_sort()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(num>score_array[i])
		{
			for(j=3;j>i;j--)
			{
				score_array[j]=score_array[j-1];score_array[i]=num;
			}

			break;
		}
	}
}




void life()
{
	if((ball.y>590 || ball.y<=20 || ball.x<10 || ball.x>590 )&& life_value>1)
	{
		life_value-=1;//one life decreases;

		//gamestate=paused;num=num;ball.y+=0;
		gamestate=gamepage;
		life_lost_flag=1;
		ball.y=30,ball.x=100;glut_key_disable=0;

	}if(num==1000)
		{
			life_value=3;
		}
}


void functionGameover()
{
	if((ball.y>590 || ball.y<=20 || ball.x<10 || ball.x>590) && life_value==1)//where the game is over(the ball touches the border of the window)
	{
		score_sort();
		gamestate=gameover;num=0;ball.y=30,ball.x=100;glut_key_disable=0;

	}

	if(gamestate==gameover)
	{
		game_over_flag=1;
	}


}






/*void speedrectoDraw(){
			for(int i = 0;i<1;i++)
			{
			//speedo rectangle drawing
				iSetColor(speedrect[i].col[0] , speedrect[i].col[1] , speedrect[i].col[2]);
				iFilledRectangle( speedrect[i].x , speedrect[i].y , speedrect[i].w, speedrect[i].h);
				//printf( "%d %d %d %d\n", rect[i].x , rect[i].y , rect[i].w, rect[i].h);
			}

speedRectoChange();
}*/


void fastrect_ball_collision()
{
	int i;
	for(i=0;i<2;i++)
	{
		if(ball.x>=speedrect[i].x && ball.x<=speedrect[i].x+speedrect[i].w+ball.r && ball.y>=speedrect[i].y  && ball.y<=speedrect[i].y+speedrect[i].h+ball.r)
		{
			ball.y=speedrect[i].h+speedrect[i].y;
			ball.y-=8;
			glut_key_disable=1;
		}

}


}
void move()
{
	if(life_lost_flag==1)
	{
		pause_rec_x+=2;
		if(pause_rec_x>600)
		{
			pause_rec_x=20;
			life_lost_flag=0;
		}

	}
}




















void writeScoreInFile()//************************************************************************************************************************
{
	int i;
   fin = fopen("array_save.txt", "w");
   for(i=0;i<4;i++)
   {

       fprintf(fin, "%d\n", score_array[i]);
	   fprintf(fin,"%d\n",num);


   }    fclose(fin);

}




void iDraw()
{
	iClear();
	/*if(gamestate==paused)//------------paused Background
	{
			pausegame_background_draw();itoa(num,ss,10);
			iSetColor(255,255,255);
			iText(500,560,ss,font);}
	*/
	if(gamestate==gamepage)
	{

		/*if(level_up==1)
		{
			iSetColor(0,0,0);
			iText(400,500,"LEVEL : Easy ",GLUT_BITMAP_TIMES_ROMAN_10);
		}*/ //show level
		show(0,0,"gameback.bmp");


		//iFilledRectangle(0,0,600,600);
		if(level_up==0){
		for(int i = 0;i<6;i++)
			{
			//rectangle drawing
				iSetColor(rect[i].col[0] , rect[i].col[1] , rect[i].col[2]);
				iFilledRectangle( rect[i].x , rect[i].y , rect[i].w, rect[i].h);
				//printf( "%d %d %d %d\n", rect[i].x , rect[i].y , rect[i].w, rect[i].h);
		}}writeScoreInFile();
		if(level_up==1){for(int i = 0;i<=6;i++)
			{
			//rectangle drawing
				iSetColor(rect[i].col[0] , rect[i].col[1] , rect[i].col[2]);
				iFilledRectangle( rect[i].x , rect[i].y , rect[i].w, rect[i].h);
				//printf( "%d %d %d %d\n", rect[i].x , rect[i].y , rect[i].w, rect[i].h);
		}
		}


		for(int i=0;i<2;i++)
				//angryball drawing
			{
					iFilledCircle(angryball[i].x, angryball[i].y, 20);
					if(level_up==0 ){
						show(angryball[i].x-20,angryball[i].y-20,"angry.bmp");}
					else if(level_up==1)
					{						show(angryball[i].x-20,angryball[i].y-20,"angry.bmp");}

					}



		for(int i = 0;i<2;i++)
			{
			//speedo rectangle drawing
				iSetColor(speedrect[i].col[0] , speedrect[i].col[1] , speedrect[i].col[2]);
				iFilledRectangle( speedrect[i].x , speedrect[i].y , speedrect[i].w, speedrect[i].h);
				show(speedrect[i].x,speedrect[i].y,"speedorect.bmp");
				show(speedrect[i].x,speedrect[i].y,"fire.bmp");
				//printf( "%d %d %d %d\n", rect[i].x , rect[i].y , rect[i].w, rect[i].h);
			}



			iSetColor( ball.col[0] , ball.col[1] , ball.col[2] );


			iFilledCircle(ball.x , ball.y, ball.r,6);

			iSetColor(1,1,1);

			iText(500,580,"score:",font);
			itoa(num,ss,10);
			iText(500,560,ss,font);

			//drawing life
				if(	life_lost_flag==1)
				{
					lifeLost(pause_rec_x,pause_rec_y,pause_rec_w,paise_rec_h);
				}




			for(int i=0;i<life_value;i++)
			{
				iSetColor(1,1,1);
			iFilledCircle(lifenum[i].x,lifenum[i].y,lifenum[i].r);
			show(lifenum[i].x-10,lifenum[i].y-10,"life.bmp");
			}

	}
//	pausegame_background_draw();

	else if(gamestate ==gameover && game_over_flag==1)
	{
		show(0,0,"game-over.bmp");
		//show(500,40,"menuback.bmp");
		show(230,85,"sad.bmp");
		iSetColor(100000,100000,10000);

		iText(190,210," Your score:",font);
		iText(340,210,ss,font);
		iText(150,50,"Press the END key to play again",GLUT_BITMAP_HELVETICA_18);
	}



	else if(gamestate==help)
	{	iText(100,500,"USE the ARROW keys to MOVE left and right.",font);
		iText(100,450,"DON'T touch the WINDOW.",font);
		iText(100,400,"AVOID angry apples.",font);
		iText(100,350,"DON'T touch the SQUARED boxes.",font);
		iText(100,300," -It will DISABLE the ball's movement.",font);
		show(70,100,"goback.bmp");
	}


	else if(gamestate==menu && game_over_flag==0){show(0,0,"9().bmp");


		show(50,400,pictures[0]);
		show(50,300,pictures[1]);
		show(50,200,pictures[2]);
		show(50,100,pictures[3]);
		//show(400,280,"menuapple.bmp");
		iText(420,210,START,GLUT_BITMAP_HELVETICA_10);


	}
  }












void iMouseMove(int mx, int my)
{
	//place your codes here
}



/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=50 && mx<=250 && my>=400 && my<=436 && gamestate==menu)
		{
			gamestate=gamepage;
		}
		else if(mx>=50 && mx<=250 && my>=100 && my<=136 && gamestate==menu)
		{
			exit(0);}
		else if(mx>=50 && mx<=250 && my>=200 && my<=236 && gamestate==menu)
		{
			gamestate=help;//help
		}

	else if(gamestate==gameover && mx>=500 && mx<=600 && my>=40 && my<=81 && game_over_flag==1 && glut_key_disable==0)
		{
		gamestate=menu;
		}
		else if(mx>70 && mx<170 && my>100 && my<150 && gamestate==help)
		{
			gamestate=menu;
		}



	}



	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}


void iKeyboard(unsigned char key)
{

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END && gamestate==gameover)	{
		gamestate=gamepage;
		life_value=3;num=0;
	}
	if(key == GLUT_KEY_RIGHT && gamestate==gamepage && glut_key_disable==0)
	{
			ball.x += 10;
	}

	if(key == GLUT_KEY_UP && gamestate== paused )
	{
		gamestate=gamepage;
	}

	if(key == GLUT_KEY_UP)
	{
				}


	if(key == GLUT_KEY_LEFT && gamestate==gamepage && glut_key_disable==0)
	{
			ball.x -= 10;
	}



}

int main()
{
	init();
	speedrecto();
	iSetTimer(10,rectChange);
	iSetTimer(10,ballchange1);
	iSetTimer(10,angryball_change);
	iSetTimer(10,speedRectoChange);

	iSetTimer(10, angryball_touches_ball);
	 iSetTimer(10,fastrect_ball_collision);
	 iSetTimer(10,life);
	iSetTimer(100,functionGameover) ;
	iSetTimer(10,check_level);

iSetTimer(10,move);
	iInitialize(600, 600, "UP AND UP");
	return 0;
}
