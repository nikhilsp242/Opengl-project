#include <windows.h>
#include <random>
#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include<vector>
#include<string.h>
#include<math.h>
#define PI 3.14


float camX = 0.1, camY = 0, camZ = 0.1;
float eyeX = 0, eyeY = 0, eyeZ = 0;
float upX = 0, upY = 0, upZ = 0;
float theta = 0, phi = 0;
float zoom = 13;
int hemi = 9, cucu = 5, dia = 9;
int diaR = 0, cucuR = 0, hemiR = 0;
int dc;
float axisX = 0, axisY = 0, axisZ = 0;
float tX = 0, tY = 0, tZ = 0;
float rx = 0, ry = 0, rz = 0;
int dx = 1, dy = 1, dz = 1;
int path = 1;
float hX, hY, hZ;
float cX, cY, cZ;
float dX, dY, dZ;
int rightClicked = 0;
int mx, my;
int Mx, My;
int WINDOW_SIZE[] = { 1080,1080 };
float Rh, Gh, Bh;
float Rc, Gc, Bc;
float Rd, Gd, Bd;
int selectedObject;
int scale = 0, translateX, translateY;
int rotateX = 0, rotateY = 0, rotateZ = 0;


int obj1 = 10, obj2 = 20, obj3 = 30;


using namespace std;

//reading from obj file and converting into triangulated objects in opengl
void hemisphere() {
	/* clears window */
	vector<unsigned int> VertexIndies, NormalIndices;
	vector<vector<GLfloat>> temp_vertices;
	vector<vector<GLfloat>> temp_normals;
	FILE* fp = fopen("C:/Users/Nikhil/Documents/hemisphere.obj", "r");
	if (fp == NULL) {
		printf("File doesn't exist!");
	}
	else {
		while (1) {
			char line[128];//stores 1st word of the line
			int res = fscanf(fp, "%s", line);
			if (res == EOF)
				break;

			if (strcmp(line, "v") == 0) {
				vector<GLfloat> vertex;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				vertex.push_back(a);
				vertex.push_back(b);
				vertex.push_back(c);
				temp_vertices.push_back(vertex);
			}
			else if (strcmp(line, "vn") == 0) {
				vector<GLfloat> normal;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				normal.push_back(a);
				normal.push_back(b);
				normal.push_back(c);
				temp_normals.push_back(normal);
			}
			else if (strcmp(line, "f") == 0) {
				unsigned int vertexindex[3], normalindex[3];
				int matches = fscanf(fp, " %d//%d %d//%d %d//%d\n", &vertexindex[0], &normalindex[0], &vertexindex[1], &normalindex[1], &vertexindex[2], &normalindex[2]);
				if (matches != 6) {
					printf("File not able to read");
				}
				else {
					if (rightClicked % 2 && selectedObject != obj1)
						glColor3f(0, 0, 1);
					else if (rightClicked % 2 && selectedObject == obj1) {
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					}
					else
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					glBegin(GL_TRIANGLES);
					//glNormal3f(temp_normals[normalindex[0] - 1][0], temp_normals[normalindex[0] - 1][1], temp_normals[normalindex[0]-1][2] );
					glVertex3f(temp_vertices[vertexindex[0] - 1][0], temp_vertices[vertexindex[0] - 1][1], temp_vertices[vertexindex[0] - 1][2]);
					//glNormal3f(temp_normals[normalindex[1] - 1][0], temp_normals[normalindex[1] - 1][1], temp_normals[normalindex[1] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[1] - 1][0], temp_vertices[vertexindex[1] - 1][1], temp_vertices[vertexindex[1] - 1][2]);
					//glNormal3f(temp_normals[normalindex[2] - 1][0], temp_normals[normalindex[2] - 1][1], temp_normals[normalindex[2] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[2] - 1][0], temp_vertices[vertexindex[2] - 1][1], temp_vertices[vertexindex[2] - 1][2]);
					glEnd();
				}
			}
		}
	}
	fclose(fp);
}

void cucumber() {
	/* clears window */
	vector<unsigned int> VertexIndies, NormalIndices;
	vector<vector<GLfloat>> temp_vertices;
	vector<vector<GLfloat>> temp_normals;
	FILE* fp = fopen("C:/Users/Nikhil/Documents/cucumber.obj", "r");
	if (fp == NULL) {
		printf("File doesn't exist!");
	}
	else {
		while (1) {
			char line[128];//stores 1st word of the line
			int res = fscanf(fp, "%s", line);
			if (res == EOF)
				break;

			if (strcmp(line, "v") == 0) {
				vector<GLfloat> vertex;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				vertex.push_back(a);
				vertex.push_back(b);
				vertex.push_back(c);
				temp_vertices.push_back(vertex);
			}
			else if (strcmp(line, "vn") == 0) {
				vector<GLfloat> normal;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				normal.push_back(a);
				normal.push_back(b);
				normal.push_back(c);
				temp_normals.push_back(normal);
			}
			else if (strcmp(line, "f") == 0) {
				unsigned int vertexindex[3], normalindex[3];
				int matches = fscanf(fp, " %d//%d %d//%d %d//%d\n", &vertexindex[0], &normalindex[0], &vertexindex[1], &normalindex[1], &vertexindex[2], &normalindex[2]);
				if (matches != 6) {
					printf("File not able to read");
				}
				else {
					if (rightClicked % 2 && selectedObject != obj2)
						glColor3f(0, 1, 0);
					else if (rightClicked % 2 && selectedObject == obj2) {
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					}
					else
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					glBegin(GL_TRIANGLES);
					//glNormal3f(temp_normals[normalindex[0] - 1][0], temp_normals[normalindex[0] - 1][1], temp_normals[normalindex[0]-1][2] );
					glVertex3f(temp_vertices[vertexindex[0] - 1][0], temp_vertices[vertexindex[0] - 1][1], temp_vertices[vertexindex[0] - 1][2]);
					//glNormal3f(temp_normals[normalindex[1] - 1][0], temp_normals[normalindex[1] - 1][1], temp_normals[normalindex[1] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[1] - 1][0], temp_vertices[vertexindex[1] - 1][1], temp_vertices[vertexindex[1] - 1][2]);
					//glNormal3f(temp_normals[normalindex[2] - 1][0], temp_normals[normalindex[2] - 1][1], temp_normals[normalindex[2] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[2] - 1][0], temp_vertices[vertexindex[2] - 1][1], temp_vertices[vertexindex[2] - 1][2]);
					glEnd();

				}
			}
		}
	}
	fclose(fp);
}

void diamond() {
	/* clears window */
	vector<unsigned int> VertexIndies, NormalIndices;
	vector<vector<GLfloat>> temp_vertices;
	vector<vector<GLfloat>> temp_normals;
	FILE* fp = fopen("C:/Users/Nikhil/Documents/diamond.obj", "r");
	if (fp == NULL) {
		printf("File doesn't exist!");
	}
	else {
		while (1) {
			char line[128];//stores 1st word of the line
			int res = fscanf(fp, "%s", line);
			if (res == EOF)
				break;

			if (strcmp(line, "v") == 0) {
				vector<GLfloat> vertex;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				vertex.push_back(a);
				vertex.push_back(b);
				vertex.push_back(c);
				temp_vertices.push_back(vertex);
			}
			else if (strcmp(line, "vn") == 0) {
				vector<GLfloat> normal;
				float a, b, c;
				fscanf(fp, " %f %f %f\n", &a, &b, &c);
				normal.push_back(a);
				normal.push_back(b);
				normal.push_back(c);
				temp_normals.push_back(normal);
			}
			else if (strcmp(line, "f") == 0) {
				unsigned int vertexindex[3], normalindex[3];
				int matches = fscanf(fp, " %d//%d %d//%d %d//%d\n", &vertexindex[0], &normalindex[0], &vertexindex[1], &normalindex[1], &vertexindex[2], &normalindex[2]);
				if (matches != 6) {
					printf("File not able to read");
				}
				else {
					if (rightClicked % 2 && selectedObject != obj3)
						glColor3f(0.5, 0.5, 0.5);
					else if (rightClicked % 2 && selectedObject == obj3) {
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					}
					else
						glColor3f((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
					glBegin(GL_TRIANGLES);
					//glNormal3f(temp_normals[normalindex[0] - 1][0], temp_normals[normalindex[0] - 1][1], temp_normals[normalindex[0]-1][2] );
					glVertex3f(temp_vertices[vertexindex[0] - 1][0], temp_vertices[vertexindex[0] - 1][1], temp_vertices[vertexindex[0] - 1][2]);
					//glNormal3f(temp_normals[normalindex[1] - 1][0], temp_normals[normalindex[1] - 1][1], temp_normals[normalindex[1] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[1] - 1][0], temp_vertices[vertexindex[1] - 1][1], temp_vertices[vertexindex[1] - 1][2]);
					//glNormal3f(temp_normals[normalindex[2] - 1][0], temp_normals[normalindex[2] - 1][1], temp_normals[normalindex[2] - 1][2]);
					glVertex3f(temp_vertices[vertexindex[2] - 1][0], temp_vertices[vertexindex[2] - 1][1], temp_vertices[vertexindex[2] - 1][2]);
					glEnd();
				}
			}
		}
	}
	fclose(fp);
}



vector<GLfloat> points;


float distance() {
	float dis = sqrt(rx * rx + ry * ry + rz * rz);
	return dis;
}

// a callback function that is executed at regular intervals of time registered under 'glutIdleFunc'
void timerCallBack()
{
	// HINT: the camera is moving on a curcumference of a 2D circle 
	// the points on the circle will be the position of the camera (camx,0,camy)
	//theta++;
	float rad = theta * PI / 180;
	camX = sin(rad);
	if (Mx > My) {

		camZ = cos(rad);
	}

	else {
		rad = phi * PI / 180;
		camY = cos(rad);
		//camX = sin(rad);
	}


	if (rightClicked % 2) {
		;
	}
	else {
		hemiR++;
		cucuR++;
		diaR++;

		//for x
		if (dx == 1) {
			if (rx <= 8)
				rx += 0.01;
		}
		//change direction
		float dis1 = distance();
		if (dis1 >= 8)
			dx = -1;

		if (dx == -1) {
			if (rx >= -8)
				rx -= 0.01;
		}
		//change direction
		float dis2 = distance();
		if (dis2 >= 8)
			dx = 1;

		//for y
		if (dx == 1) {
			if (ry <= 8)
				ry += 0.01;
		}
		//change direction
		float dis3 = distance();
		if (dis3 >= 8)
			dx = -1;

		if (dx == -1) {
			if (ry >= -8)
				ry -= 0.01;
		}
		//change direction
		float dis4 = distance();
		if (dis4 >= 8)
			dx = 1;

		//for z
		if (dx == 1) {
			if (rz <= 8)
				rz += 0.01;
		}
		//change direction
		float dis5 = distance();
		if (dis5 >= 8)
			dx = -1;

		if (dx == -1) {
			if (rz >= -8)
				rz -= 0.01;
		}
		//change direction
		float dis6 = distance();
		if (dis6 >= 8)
			dx = 1;
	}



	//Sleep(10);
	//redisplay after the paramters are changed.
	glutPostRedisplay();
}



void setMaterial(float ambientR, float ambientG, float ambientB,
	float diffuseR, float diffuseG, float diffuseB,
	float specularR, float specularG, float specularB, float shine)
{
	GLfloat ambient[] = { ambientR, ambientG, ambientB };
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
	GLfloat specular[] = { specularR, specularG, specularB };

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);
}



void display()
{
	// Clear your Window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |GL_STENCIL_BUFFER_BIT);

	//selecting the Model View Matrix for making modification to the view
	glMatrixMode(GL_MODELVIEW);

	//clearing the model view matrix
	glLoadIdentity();

	//setting up the position for camara based on the calculation in timeCallBack()


	if (Mx > My) {
		gluLookAt((float)zoom * camX, camY, (float)(zoom)*camZ, 0, 0, 0, 0, 1, 0);
		//camZ = (float)(zoom)*camZ;
	}



	else {
		gluLookAt((float)zoom * camX, (float)zoom * camY, camZ, 0, 0, 0, 0, 1, 0);
		//camY = (float)zoom * camY;

	}

	//gluLookAt(13, 0, 0, 0, 0, 0, 0, 1, 0);


	//glColor3f((GLfloat)184 / 255, (GLfloat)115 / 255, (GLfloat)51 / 255);

	//set the material for the tea pot
	//paramaters: ambient (r,g,b), diffuse (r,g,b), specular (r,g,b),shineness (0-128)
	/*
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilMask(0xFF);
	*/

	hX = rx; hY = ry; hZ = rz;
	cX = rx; cY = ry; cZ = rz;
	dX = rx; dY = ry; dZ = rz;
	if (selectedObject == obj1) {

		hX += translateX;
		hY += translateY;
		//scale--;
		//rotate
		glPushMatrix();
		glTranslatef(hX, hY, hZ);
		glScalef(hemi, hemi, hemi);
		glRotatef(hemiR, rotateX, rotateY, rotateZ);
		hemisphere();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-cX, -cY, cZ);
		glScalef(5, 5, 5);
		glRotatef(cucuR, 1, 1, 1);
		cucumber();
		glPopMatrix();



		glPushMatrix();
		glTranslatef(-dX, dY, -dZ);
		glScalef(9, 9, 9);
		glRotatef(diaR, 1, 1, 1);
		diamond();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 0, 1);
		glRotatef(90, 1, 0, 0);
		glutWireSphere(9, 25, 25);
		glPopMatrix();
	}
	else if (selectedObject == obj2) {

		cX += translateX;
		cY += translateY;
		//scale--;
		//rotate
		glPushMatrix();
		glTranslatef(hX, hY, hZ);
		glScalef(9, 9, 9);
		glRotatef(hemiR, rotateX, rotateY, rotateZ);
		hemisphere();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-cX, -cY, cZ);
		glScalef(cucu, cucu, cucu);
		glRotatef(cucuR, 1, 1, 1);
		cucumber();
		glPopMatrix();



		glPushMatrix();
		glTranslatef(-dX, dY, -dZ);
		glScalef(9, 9, 9);
		glRotatef(diaR, 1, 1, 1);
		diamond();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 0, 1);
		glRotatef(90, 1, 0, 0);
		glutWireSphere(9, 25, 25);
		glPopMatrix();
	}
	else if (selectedObject == obj3) {

		dX += translateX;
		dY += translateY;

		glPushMatrix();
		glTranslatef(hX, hY, hZ);
		glScalef(9, 9, 9);
		glRotatef(hemiR, rotateX, rotateY, rotateZ);
		hemisphere();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-cX, -cY, cZ);
		glScalef(5, 5, 5);
		glRotatef(cucuR, 1, 1, 1);
		cucumber();
		glPopMatrix();



		glPushMatrix();
		glTranslatef(-dX, dY, -dZ);
		glScalef(dia, dia, dia);
		glRotatef(diaR, 1, 1, 1);
		diamond();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 0, 1);
		glRotatef(90, 1, 0, 0);
		glutWireSphere(9, 25, 25);
		glPopMatrix();
	}
	else {

		glPushMatrix();
		glTranslatef(hX, hY, hZ);
		glScalef(9, 9, 9);
		glRotatef(hemiR, 1, 1, 1);
		hemisphere();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-cX, -cY, cZ);
		glScalef(5, 5, 5);
		glRotatef(cucuR, 1, 1, 1);
		cucumber();
		glPopMatrix();



		glPushMatrix();
		glTranslatef(-dX, dY, -dZ);
		glScalef(9, 9, 9);
		glRotatef(diaR, 1, 1, 1);
		diamond();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 0, 1);
		glRotatef(90, 1, 0, 0);
		glutWireSphere(9, 25, 25);
		glPopMatrix();
	}


	// Flush the drawing routines to the window
	glutSwapBuffers();
}

void initLight()
{
	GLfloat ambient[] = { 0.3, 0.3, 0.3 };
	GLfloat diffuse[] = { 0.5, 0.5, 0.5 };
	GLfloat specular[] = { 1, 1, 1 };
	GLfloat position[] = { -2,0.5,4,1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Tell the opengl to allow us to change the colors of the material
	glEnable(GL_COLOR_MATERIAL);
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
	if (selectedObject == obj1) {
		switch (key)
		{

		case 'x': rotateX = 1; hemiR++;   break;
		case 'y': rotateY = 1; hemiR++;  break;
		case 'z': rotateZ = 1; hemiR++; break;
		case 'X': rotateY = -1; hemiR++;  break;
		case 'Y': rotateY = -1; hemiR++; break;
		case 'Z': rotateZ = -1; hemiR++; break;
		case'+': hemi++; break;
		case'-':hemi--; break;
		default:
			break;
		}
		rotateX = 0, rotateY = 0, rotateZ = 0;
	}
	else if (selectedObject == obj2) {
		switch (key)
		{

		case 'x': rotateX = 1;   break;
		case 'y': rotateY = 1;  break;
		case 'z': rotateZ = 1;  break;
		case 'X': rotateY = -1;   break;
		case 'Y': rotateY = -1;  break;
		case 'Z': rotateZ = -1;  break;
		case'+': cucu++; break;
		case'-':cucu--; break;
		default:
			break;
		}
		rotateX = 0, rotateY = 0, rotateZ = 0;
	}
	else if (selectedObject == obj3) {
		switch (key)
		{

		case 'x': rotateX = 1;   break;
		case 'y': rotateY = 1;  break;
		case 'z': rotateZ = 1;  break;
		case 'X': rotateY = -1;   break;
		case 'Y': rotateY = -1;  break;
		case 'Z': rotateZ = -1;  break;
		case'+': dia++; break;
		case'-':dia--; break;
		default:
			break;
		}
		rotateX = 0, rotateY = 0, rotateZ = 0;
	}
	else
		switch (key) {
		case '+':zoom--; break;
		case'-':zoom++; break;
		default:
			break;
		}

	glutPostRedisplay();
}

void mySpecialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: translateY++; break;
	case GLUT_KEY_DOWN: translateY--; break;
	case GLUT_KEY_RIGHT: translateX++; break;
	case GLUT_KEY_LEFT: translateX--; break;
	}
	glutPostRedisplay();
}

void myMouseFunc(int button, int state, int x, int y)
{

	// the button value can be either of the following
	// GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = x;
		my = y;
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		rightClicked++;


	// the state can be either of the following
	// GLUT_UP, GLUT_DOWN
	if (state != GLUT_DOWN) {
		return;
	}

	// click to select an object, it moves with change in cursor position, then click to drop

	GLbyte color[4];
	GLfloat depth;
	GLuint index;

	glReadPixels(x, WINDOW_SIZE[1] - y - 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
	glReadPixels(x, WINDOW_SIZE[1] - y - 1, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
	glReadPixels(x, WINDOW_SIZE[1] - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	//printf("\nClicked on pixel: (%d, %d), color: %d, depth: %f, stencil index: %u.\n", x, y, 7*color[0]+5*color[1]+3*color[2]+color[3], depth, index);
	//printf("\nClicked on pixel: (%d, %d), color: %02hhx%02hhx%02hhx%02hhx, depth: %f, stencil index: %u.\n", x, y, color[0], color[1], color[2], color[3], depth, index);
	selectedObject = abs(7 * color[0] + 5 * color[1] + 3 * color[2] + color[3]);
	printf("Color of the selected object = %d\n", selectedObject);
	if (selectedObject >= 300 && selectedObject <= 450)
		selectedObject = obj1;
	if (selectedObject >= 500 && selectedObject <= 650)
		selectedObject = obj2;
	if (selectedObject >= 900 && selectedObject <= 1050)
		selectedObject = obj3;
}



void myMouseMotion(int x, int y)
{
	int tempX = mx;
	if (mx > x) {
		theta--;
		mx = x;
		Mx = abs(mx - tempX);
		phi = theta;
	}

	else if (mx < x) {
		theta++;
		mx = x;
		Mx = abs(mx - tempX);
		phi = theta;
	}

	int tempY = my;
	if (my > y) {
		phi--;
		my = y;
		My = abs(my - tempY);
		theta = phi;
	}
	else if (my < y) {
		phi++;
		my = y;
		My = abs(my - tempY);
		theta = phi;
	}
}

int main(int argc, char* argv[])
{
	// Step1:  initialize GLUT using the command line parameters
	glutInit(&argc, argv);

	// Step2: Setup the size of the opengl window, display mode
	glutInitWindowSize(1080, 1080);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE /* | GL_STENCIL*/);

	// Step3: creating the window
	glutCreateWindow("OpenGL 3D Lighting");

	//enable the depth test
	glEnable(GL_DEPTH_TEST);
	/*
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	*/
	//Set up Lighting for the scene
	initLight();

	//set window background color
	glClearColor(0, 0, 0, 1);



	// Step4: defining a callback function for looping into the rasterizer
	glutDisplayFunc(display);

	//define a timer callback function
	glutIdleFunc(timerCallBack);

	//define callback for keyboard interactions
	glutKeyboardFunc(myKeyboardFunc);

	//define the special keyboard callback function 
	glutSpecialFunc(mySpecialFunc);

	// define a callback for mouse event
	glutMouseFunc(myMouseFunc);

	// defining callback for mouse movement
	glutMotionFunc(myMouseMotion);


	//Setup projection window
	glMatrixMode(GL_PROJECTION); // Select Projection Matrix
	glLoadIdentity();

	//ortho graphic view for 3D
	//glOrtho(-10, 10, -10, 10, -10, 10);

	//setup perspective projection
	gluPerspective(90, 1, 0.5, 1000);


	// Step5: Telling the GLUT to loop into the callback
	glutMainLoop();
}
