


void variables(){


struct bar{
	int x,y,w,h,col[3],hit,r,jump,pivot;
	};

bar rect[7],ball,button[4],angryball[3],speedrect[2],lifenum[3];//structure variables declared

double vel = 2,up = 10;

int num=0,gamestate=menu,game_over_flag=0,glut_key_disable=0,life_value=3,level_up=0,life_lost_flag=0,score_array[4];
int pause_rec_x=0,pause_rec_y=300,pause_rec_w=200,paise_rec_h=30;

char ss[9],score_array_int[5][100];
char pictures[10][20]={"newgame.bmp","options.bmp","instructions.bmp","highscore.bmp","exit.bmp"};//menu pictures
FILE *arrayIn;}