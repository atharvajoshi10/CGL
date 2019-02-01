#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void drawCircle(int x,int y,int r)
{
	glBegin(GL_POINTS);
		glVertex2f(x,y+r);
	glEnd();
	glFlush();
	int xk=0,yk=r;
	int P=1.25-r;
	while(xk<=yk)
	{
		xk++;
		if(P<0)
			P+=2*xk+3;	
		else
		{
			yk--;
			P+=2*xk-2*yk+5;
		}
		glBegin(GL_POINTS);
			glVertex2f(xk+x,yk+y);
			glVertex2f(yk+y,xk+x);
			glVertex2f(x-xk,y+yk);
			glVertex2f(y+yk,x-xk);
			glVertex2f(x-xk,y-yk);
			glVertex2f(y-yk,x-xk);
			glVertex2f(xk+x,y-yk);
			glVertex2f(y-yk,x+xk);
		glEnd();
		glFlush();
	}
}

void drawLine(int x1,int y1,int x2,int y2)//Draws Lines between 2 points
{
	int delX = x2-x1;
	int delY = y2-y1;
	int x=x1;
	int y=y1;
	int count =0;
	int till;
	glBegin(GL_POINTS);
		glVertex2f(abs(x1), abs(y1));
	glEnd();
	if(delX == 0)
	{
		//printf("vERTI");
		till=abs(delY);
		int inc;
		if(delY<0)
			inc = -1;
		else
			inc = +1;
		while(count<till)
		{
			y=y+inc;
			glBegin(GL_POINTS);
					glVertex2f(abs(x),abs(y));
			glEnd();
			glFlush();
			count++;
		}
	}
	else if(delY == 0)
	{
		//printf("HORI");
		till=abs(delX);
		int inc;
		if(delX<0)
			inc = -1;
		else
			inc = +1;
		while(count<till)
		{
			x=x+inc;
			glBegin(GL_POINTS);
					glVertex2f(abs(x),abs(y));
			glEnd();
			glFlush();
			count++;
		}
	}
	else
	{
		float m = delY/delX;
		float P = 2*delY-delX;
		int xinc=1,yinc=1;
		if(delX<0)
			xinc=-1;
		if(delY<0)
			yinc=-1;
		delX=abs(delX);
		delY=abs(delY);
		if(abs(m)<1)
		{
			till=abs(delX);
			while(count<till)
			{		
				x=x+xinc;
				if(P<0)
					P=P+2*delY;
				else
				{
					y=y+yinc;
					P=P+2*delY-2*delX;
				}
				glBegin(GL_POINTS);
					glVertex2f(abs(x),abs(y));
				glEnd();
				glFlush();
				count++;
			}
		}	
		else
		{
			till=abs(delY);	
			while(count<till)
			{
				y=y+yinc;
				if(P<0)
					P=P+2*delY;
				else
				{
					x=x+xinc;
					P=P+2*delY-2*delX;
				}
				glBegin(GL_POINTS);
					glVertex2f(abs(x),abs(y));
				glEnd();
				glFlush();
				count++;
			}
		}
	}
}


void getPoints(int *x,int *y,int *r)
{
	printf("Enter X-Coordinate:");
	scanf("%d",x);
	printf("Enter Y-Coordinate:");
	scanf("%d",y);
	printf("Enter Radius:");
	scanf("%d",r);
	printf("\n\n");
}

void render()
{
	printf("Enter Coordinates for Center of circle\n");
	int x,y,r;
	getPoints(&x,&y,&r);
	drawCircle(x,y,r);
	drawCircle(x,y,2*r);
	drawLine(x,y-r,x+sqrt(3)*r,y-r);
	drawLine(x,y-r,x-sqrt(3)*r,y-r);
	drawLine(x+sqrt(3)*r,y-r,x,y+(2*r));
	//drawLine(x,y+2*r,x-sqrt(3)*r,y-r);
}

int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400,500);
	glutCreateWindow("Assignment2");
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0,400,0,500);
	glutDisplayFunc(render);
	glutMainLoop();
}
