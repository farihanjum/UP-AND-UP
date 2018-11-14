void init()
{

	struct bar{
	int x,y,w,h,col[3],hit,r,jump,pivot;
	};
	bar rect[6],ball,button[4],angryball[3],speedrect[2],lifenum[3];
	

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