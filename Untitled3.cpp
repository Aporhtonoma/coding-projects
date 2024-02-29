 #include <gl/glut.h> 
 #include <stdio.h>
 #define GLUT_DISABLE_ATEXIT_HACK
//Clipping window limits 
float xwmin=-50, xwmax=50, ywmin=-50, ywmax=50; 
//Application window dimensions 
int windowWidth=500, windowHeight=500; 
GLfloat xw1,yw1,xw2,yw2; 
int targettracker=0,targetx,targety;
void display() 
{ 
 glClearColor(1,1,1,0); 
 glClear(GL_COLOR_BUFFER_BIT); 
 glRectf(xw1,yw1,xw2,yw2); 
 
 glFlush(); 
} 
void mouseButtonClicked(int button,int state,int x, int y) 
{ 
if(state==GLUT_DOWN) 
 { 
 
 
if (targettracker == 0)
{
targetx=100;
targety=200;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{
		targettracker ++;
		printf("hit\n");
}
}
if (targettracker == 1)
{
targetx=80; 
targety=160;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{
		targettracker ++;
		printf("hit\n");
}
}
if (targettracker == 2)
{
targetx=120; 
targety=220;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{
		targettracker ++;
		printf("hit\n");
}
}
if (targettracker == 3)
{
targetx=300; 
targety=300;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{
		targettracker ++;
		printf("hit\n");
}
}
if (targettracker == 4)
{
targetx=400; 
targety=450;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{
		targettracker ++;
		printf("hit\n");
}
}
if (targettracker == 5)
{
targetx=50; 
targety=50;
xw1=(float)(xwmin+(float)(targetx)*(xwmax-xwmin)/(float)(windowWidth));
yw1=(float)(ywmin+(float)(windowHeight-targety)*(ywmax-ywmin)/(float)(windowHeight)); 
xw2=xw1+10; 
yw2=yw1+10;
	if (targetx <= x && targetx + 50 >= x && targety >= y && targety - 50 <= y )
{	
		targettracker= 0;
		printf("hit\n");
}
}

} 
 
 if (button==GLUT_LEFT_BUTTON) 
 glColor3f(1,0,0); 
//Generate a display event 
 glutPostRedisplay(); 
 } 

int main(int argc, char** argv) 
{ 
 glutInit(&argc,argv); 
 glutInitWindowPosition(50,50);
 glutInitWindowSize(windowWidth,windowHeight); 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutCreateWindow("Σκοποβολή"); 
 glMatrixMode(GL_PROJECTION); 
 gluOrtho2D(xwmin,xwmax,ywmin,ywmax); 
 glutDisplayFunc(display); 
 glutMouseFunc(mouseButtonClicked); 
 glutMainLoop(); 
return 0; 
}
