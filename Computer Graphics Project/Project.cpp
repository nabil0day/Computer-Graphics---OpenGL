//Computer-Graphics
#include<bits/stdc++.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<Mmsystem.h>
#define PI 3.14159265358979323846

void displayMor();

GLfloat position = -0.5f; //cloud1
GLfloat position1 = 0.5f; //cloud2
GLfloat speed = 0.02f;
//GLfloat speed1 = 0.02f;
GLfloat x, y, radius, twicePi;
int triangleAmount; //sun
int rval = 0;
char play = '1';

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void automated_mor(int val){
    glutDisplayFunc(displayMor);
}

GLfloat positionBridgeCar1 = -5.0f;
GLfloat speedBridgeCar1 = 0.08f;
void updateBridgeCar1(int value){ //2

    if(positionBridgeCar1 > 4.0)
        positionBridgeCar1 = -8.2f;

    positionBridgeCar1 += speedBridgeCar1;
	glutPostRedisplay();
	glutTimerFunc(100, updateBridgeCar1, 0);
}

GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.08f;
void updateTruck(int value){ //5
    if(truckPosition > 1.45)
    {
        truckPosition = -0.4f;
    }
    truckPosition += truckSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTruck, 0);
}

GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.02f;
void updateBoat(int value) {

    if(boatPosition > 1.45)
        {
            boatPosition = 0;
        }
    boatPosition += boatSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateBoat, 0);
}

GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
void updateCar(int value){ //car utso
    if(carPosition < - 1.0)
    {
        carPosition = 0.6f;
    }
    carPosition -= carSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateCar, 0);
}


void bridgeCar1(int val){ ////brizcarbody
    glPushMatrix();
    glTranslatef(positionBridgeCar1,0.0f, 0.0f);

   glBegin(GL_POLYGON);
      glColor3f(1.0f, .0f, 0.0f);
      glVertex2f(-0.1f, 0.3f);
      glVertex2f(0.4f, 0.3f);
      glVertex2f(0.5f, 0.2f);
      glVertex2f(0.7f, 0.2f);
      glVertex2f(0.7f, 0.0f);
      glVertex2f(-0.3f, 0.0f);
      glVertex2f(-0.3f, 0.2f);
      glVertex2f(-0.2f, 0.2f);
   glEnd();

   glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.1f, 0.28f);
      glVertex2f(0.4f, 0.28f);
      glVertex2f(0.45f, 0.22f);
      glVertex2f(0.1f, 0.22f);
    glEnd();

    glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.1f, 0.28f);
      glVertex2f(0.05f, 0.28f);
      glVertex2f(0.05f, 0.22f);
      glVertex2f(-0.15f, 0.22f);
    glEnd();

     glBegin(GL_POLYGON);       //tube light
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.6f, 0.15f);
      glVertex2f(0.7f, 0.15f);
      glVertex2f(0.7f, 0.1f);
      glVertex2f(0.6f, 0.1f);
    glEnd();

    float t1_angle;        //tire 1
    float t1_radius = 0.1;
    float t1_x,t1_y, t1_p, t1_q;

    t1_x = -0.1f;
    t1_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(t1_x, t1_y);
    for(t1_angle = 0.0f; t1_angle<360.0f; t1_angle++){
        t1_p = t1_x+sin(t1_angle)*t1_radius;
        t1_q = t1_y+cos(t1_angle)*t1_radius;

        glVertex2f(t1_p,t1_q);
    }
    glEnd();

    float i1_angle;        //tire 1 inside
    float i1_radius = 0.07;
    float i1_x,i1_y, i1_p, i1_q;

    i1_x = -0.1f;
    i1_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i1_x,i1_y);
    for(i1_angle = 0.0f; i1_angle<360.0f; i1_angle++){
        i1_p = i1_x+sin(i1_angle)*i1_radius;
        i1_q = i1_y+cos(i1_angle)*i1_radius;

        glVertex2f(i1_p,i1_q);
    }
    glEnd();

    float t2_angle;        //tire 2
    float t2_radius = 0.1;
    float t2_x,t2_y, t2_p, t2_q;

    t2_x = 0.4f;
    t2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(t2_x,t2_y);
    for(t2_angle = 0.0f; t2_angle<360.0f; t2_angle++){
        t2_p = t2_x+sin(t2_angle)*t2_radius;
        t2_q = t2_y+cos(t2_angle)*t2_radius;
        glVertex2f(t2_p,t2_q);
    }
    glEnd();

    float i2_angle;        //tire 2 inside
    float i2_radius = 0.07;
    float i2_x,i2_y, i2_p, i2_q;

    i2_x = 0.4f;
    i2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i2_x,i2_y);
    for(i2_angle = 0.0f; i2_angle<360.0f; i2_angle++){
        i2_p = i2_x+sin(i2_angle)*i2_radius;
        i2_q = i2_y+cos(i2_angle)*i2_radius;

        glVertex2f(i2_p,i2_q);
    }
    glEnd();
    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(0.95f,  0.2f);
      glVertex2f(0.69f,  0.12f);
      glVertex2f(0.95f,  -0.03f);
    glEnd();
   }
    glPopMatrix();
}

void circleSolid(float x, float y, float radius){
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}

void vehicleTruck(int val){//This is the truck
    glPushMatrix();
    glTranslatef(truckPosition,0.0f, 0.0f);

   //body
    glColor3ub(0,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();

    //base of the truck
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();

    //front
    glColor3ub(240,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();

    //wheels
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);

    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();

    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.4f, -0.9f);
      glVertex2f(-0.4f,  -0.8f);
      glVertex2f(-0.58f, -0.85f);
    glEnd();
    }

    glPopMatrix();
}

void vehicleCar(int val){//This is the car(utso)
    glPushMatrix();
    glTranslatef(carPosition,0.0f, 0.0f);
    //body
    glColor3ub(199, 0, 57 );
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3ub(103,13,124);
    circleSolid(0.07,-0.938,0.035);
    circleSolid(0.2,-0.938,0.035);
    //
    glColor3ub(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.15f, -0.84f);
      glVertex2f(-0.15f,  -0.93f);
      glVertex2f(0.018f, -0.90f);
    glEnd();
    }

    glPopMatrix();
}

void boat(int vehicle){
    glPushMatrix();
    glTranslatef(boatPosition,0.0f, 0.0f);
    if (vehicle == 1)
        glColor3ub(255,110,0);
    if (vehicle == 2)
        glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.30f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.73f, -0.24f);
    glEnd();

    //stick
    glColor3ub(160,82,35);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.65,-0.24);
    glVertex2f(-0.65,-0.1);
    glEnd();

    glColor3ub(0,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.655,-0.13);
    glVertex2f(-0.655,-0.24);
    glVertex2f(-0.71,-0.24);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.645,-0.13);
    glVertex2f(-0.645,-0.24);
    glVertex2f(-0.580,-0.24);
    glEnd();

    glPopMatrix();
}

void cloud2(int value){

    if(position1 > 1.0)
        position1 = -1.0f;

    position1 += speed;

	glutPostRedisplay();


	glutTimerFunc(100, cloud2, 0);
}

void sun(int sval){
	x=-0.8f; y=0.85f; radius =0.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	if(sval==1)
        glColor3ub(255, 224, 102);
    if(sval==8)
        glColor3ub(226, 148, 13);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void cloud(int val){

    // cloud 2
    glPushMatrix();
	glTranslatef(position1,0.0f, 0.0f);
	x=0.0f; y=0.9f; radius =.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1)
        glColor3ub(255, 255, 255);

    if(val==9)
        glColor3ub(110, 113, 115);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.1f; y=0.9f; radius =.07f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1)
        glColor3ub(255, 255, 255);

    if(val==9)
        glColor3ub(110, 113, 115);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();
}

int frameNumber = 0; //windmill
void doFrame(int v){ //windmill rotate
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void hill(int val){

    glBegin(GL_POLYGON);      //Hill_back

    if(val==1)
        glColor3f(0.0f, 0.3f, 0.0f);

    if(val==9)
        glColor3f(0.03f, 0.23f, 0.02f);

        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.7f, 0.73f);
        glVertex2f(-0.4f, 0.78f);
        glVertex2f(-0.1f, 0.86f);
        glVertex2f(0.5f, 0.65f);
        glVertex2f(0.9f, 0.73f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(1.0f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);      //Hill_second_left

    if(val==1)
        glColor3f(0.0f, 0.5f, 0.0f);

    if(val==9)
        glColor3f(0.04f, 0.29f, 0.02f);

        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f(-0.15f, 0.55f);
        glVertex2f(0.0f, 0.50f);
        glVertex2f(0.15f, 0.53f);
        glVertex2f(0.3f, 0.4f);

    glEnd();
}

void hill3rd(int val){
    glBegin(GL_POLYGON);      //Hill_third_right

    if(val==1)
        glColor3f(0.0f, 0.5f, 0.0f);

    if(val==9)
       glColor3f(0.04f, 0.29f, 0.02f);


        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(.83f, 0.49f);
        glVertex2f(1.0f, 0.4f);


    glEnd();

    glBegin(GL_POLYGON);      //Hill_third_right_shadow

    if(val==1)
        glColor3f(0.0f, 0.7f, 0.0f);

    if(val==9)
        glColor3f(0.0f, 0.52f, 0.0f);


        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(0.6f, 0.58f);
        glVertex2f(0.5f, 0.56f);
        glVertex2f(0.55f, 0.5f);
        glVertex2f(0.57f, 0.45f);
        glVertex2f(0.59f, 0.4f);

    glEnd();
}

void sky(int val){ //change color

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glBegin(GL_POLYGON);        //sky

    if(val==1){
        glColor3ub(0,0,255);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(138, 105, 14);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(138, 67, 46);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(235, 158, 59);
        glVertex2f(-1.0f, 0.5f);
    }

    if(val==8){
        glColor3ub(193, 214, 58);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(214, 170, 24);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(27, 191, 164);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(94, 190, 209);
        glVertex2f(-1.0f, 0.5f);
    }

    if(val==9){
        glColor3ub(28,142,255);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(18,8,54);
        glVertex2f(-1.0f, 0.5f);
    }

    glEnd();
}

void windmill(int val){ //change
    int i;

    if(val==1)
        glColor3f(0.8f, 0.8f, 0.9f);

    if(val==9)
        glColor3f(0.40f, 0.45f, 0.53f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);

	if(val==1)
        glColor3f(0.4f, 0.4f, 0.8f);

    if(val==9)
        glColor3f(0.16f, 0.12f, 0.30f);

	for (i = 0; i < 3; i++)
        {
            glRotated(120, 0, 0, 1);
            glBegin(GL_POLYGON);
            glVertex2f(0,0);
            glVertex2f(0.5f, 0.1f);
            glVertex2f(1.5f,0);
            glVertex2f(0.5f, -0.1f);
            glEnd();
        }
}

void bridgeTop(){ //briz top
    glBegin(GL_POLYGON);
    glColor3ub (150, 161, 177);
        glVertex2f(0.60f, -0.10f);
        glVertex2f(0.60f, -0.15f);

        glColor3ub (70,87,112);
        glVertex2f(-1.2f, 0.15f);
        glVertex2f(-1.2f, 0.20f);
    glEnd();
}

void bridgeSupport(){ //briz suport
    glBegin(GL_POLYGON);
    glColor3ub (70,87,112);
        glVertex2f(-1.0f, 0.15f);
        glVertex2f(-1.0f, 0.12f);
        glVertex2f(-0.835f, 0.042f);
        glVertex2f(-0.785f, 0.042f);
        glVertex2f(-0.6f, 0.043f);
        glVertex2f(-0.6f, 0.075f);
    glEnd();
}

void bridgePillers(){//brizpiller
    glBegin(GL_QUADS);
    glColor3ub (40,58,84);
        glVertex2f(-0.835f,  0.042f);
        glVertex2f(-0.835f, -0.275f);
        glVertex2f(-0.810f, -0.300f);
        glVertex2f(-0.810f,  0.042f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub (50,75,111);
        glVertex2f(-0.810f,  0.042f);
        glVertex2f(-0.810f, -0.300f);
        glVertex2f(-0.785f, -0.275f);
        glVertex2f(-0.785f,  0.042f);
    glEnd();
}

void bridge(){
    bridgeTop();

    glPushMatrix();//brizpiller remove
    glTranslatef(0.0f,0.005f,0.0f);
    bridgeSupport();
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,-0.069f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.011f,0.0f);
    glScaled(1,0.79,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f,-0.145f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.019f,0.0f);
    glScaled(1,0.58,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1994f,-0.22f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.026f,0.0f);
    glScaled(1,0.38,1);
    bridgePillers();
    glPopMatrix();

}


void lampPost_panelRoad(int val){


//main panel

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.025f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(-0.025f, -0.9f);

    glEnd();

    //////////////////////////

//right panel shadow

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(0.0f, -0.9f);

    glEnd();

    ////////////////////////////
    ///////////////////////////


//joint

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.1f, 0.3f);

    glEnd();

    /////////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.1f, 0.3f);

    glEnd();

    ////////////////////////////////////////

//tube_holder

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.25f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.55f, 0.3f);
        glVertex2f(-0.55f, 0.25f);

    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.25f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.55f, 0.3f);
        glVertex2f(0.55f, 0.25f);

    glEnd();

//tube

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f(-0.15f, 0.25f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.15f, 0.25f);

    glEnd();
    ////////////////////////////////

    //solar panel

    //////////////////////

    if(val == 9){
        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(0.6f, 0.2f);
            glVertex2f(0.1f, 0.2f);
            glVertex2f(0.15f, 0.15f);
            glVertex2f(0.55f, 0.15f);

        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(-0.6f, 0.2f);
            glVertex2f(-0.1f, 0.2f);
            glVertex2f(-0.15f, 0.15f);
            glVertex2f(-0.55f, 0.15f);
        glEnd();
    }
}
void roadriver(int val){
    glBegin(GL_POLYGON); //river

    if(val==9)
        glColor3f(0,0,128);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0,0,128);
        glVertex2f( 1.0f, 0.295f);

    if(val==1)
        glColor3f(0,0,128);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0,0,128);
        glVertex2f( 1.0f, 0.295f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.30f, 0.50f, 0.35f);
        glVertex2f(-1.0f, -0.35f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f( 1.0f, -0.30f);
        glVertex2f(-1.0f, -0.30f);
    glEnd();

    glBegin(GL_POLYGON); //road
    glColor3f(0.4f, 0.4f, 0.5f);

        glVertex2f(-1.0f, -0.35f);
        glVertex2f(1.0f, -0.35f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    glBegin(GL_QUADS); //divider
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.3f,-0.63f);
        glVertex2f( 0.3f, -0.63f);
        glVertex2f( 0.35f, -0.57f);
        glVertex2f(-0.25f,-0.57f);

        glVertex2f( 0.4f, -0.63f);
        glVertex2f( 1.0f, -0.63f);
        glVertex2f( 1.0f, -0.57f);
        glVertex2f( 0.45f,- 0.57f);

        glVertex2f(-0.45f, -0.63f);
        glVertex2f(-1.0f, -0.63f);
        glVertex2f(-1.0f, -0.57f);
        glVertex2f(-0.4f,- 0.57f);
    glEnd();
}

void tree(){

    glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.55f, 0.0f);
        glVertex2f(-0.05f, -0.7f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(0.05f, -0.7f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(0.05f, -0.02f);

        glColor3f(0.34f, 0.22f, 0.09f);
        glVertex2f(-0.05f, -0.02f);
    glEnd();


    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(-0.4f, -0.4f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.4f, -0.4f);

        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(0.0f, -0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(-0.3f, -0.3f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.3f, -0.3f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(-0.3f, -0.2f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.3f, -0.2f);

        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(0.0f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.27f, 0.44f, 0.03f);
        glVertex2f(-0.2f, -0.1f);

        glColor3f(0.16f, 0.44f, 0.05f);
        glVertex2f(0.2f, -0.1f);

        glColor3f(0.0f, 0.55f, 0.0f);
        glVertex2f(0.0f, 0.0f);
    glEnd();
}

void displayMor(){
    int val = 1;

    sky(val);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.37f,0.043f,0.0f);
    glScaled(0.5,0.8,1);
    sun(val);
    glPopMatrix();
    cloud(val);
    glPushMatrix();
    glTranslatef(0.0f,-0.15f,0.0f);
    glScalef(1.0f,1.15f,0.0f);
    hill(val);
    glPopMatrix();

	glPopMatrix();
	glPushMatrix(); //Windmill 3
	glTranslated(-0.35,0.40,0);
	glScaled(0.13,0.12,1);
	windmill(val);
	glPopMatrix();
	glPushMatrix(); //Windmill 4
	glTranslated(-0.60,0.31,0);
	glScaled(0.13,0.15,1);
	windmill(val);
	glPopMatrix();

	glPushMatrix();//bridge
    glTranslatef(-0.055f,0.55f,0.0f);
	glScaled(1.4,0.9,1);
	glRotated(50, 0,1,0);
	bridge();
    glPopMatrix();

    glPushMatrix();//bridgeCar2
    glTranslated(0,0.53,0);
	glScaled(0.13,0.18,0);
	glRotatef(-8,0.8f,0.0f,1.0f);
    bridgeCar1(val);
    glPopMatrix();

    glPushMatrix(); //hill part
    glTranslatef(0.0f,-0.15f,0.0f);
    glScaled(1,1.15,1);
    hill3rd(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.741f,0.32f,0.0f);
    glScaled(0.3,0.25,1);

    glPopMatrix();

    roadriver(val);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f,0.40f,0.0f);
    glScaled(1.8,1.5,1);
    boat(2); //2
    glPopMatrix();

    //lights road
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(0.0f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();
    glPushMatrix();//lampost
    glLineWidth(1);
    glTranslatef(-0.7f,-0.08f,0.0f);
	glScaled(0.3,0.3,1);
	lampPost_panelRoad(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.33f,0.14f,0.0f);
    glScaled(0.4,0.7,1);
    tree();
    glTranslatef(1.73f,0.0f,0.0f);
    tree();
    glPopMatrix();

    //vehicles road
    glPushMatrix();
    glTranslatef(0.0f,0.80f,0.0f);
    glScaled(1.5,1.4,1);
    vehicleTruck(val);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.30f,0.0f);
    glScaled(1.5,1.2,1);
    vehicleCar(val);
    glPopMatrix();

    if(rval == 1){
        glPushMatrix();
        glPointSize(2.0);
//        rain();
        glPopMatrix();
    }

    glFlush();
    glutTimerFunc(2500,automated_mor,0);
}

void info(){
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);

    glEnd();

glFlush();

}

void handleKeypress(unsigned char key, int x, int y){
	switch (key)
	{
	    case 'x':
        case 'X':
            glutDisplayFunc(displayMor);
            break;
        case '0':
            speedBridgeCar1 = 0.0f;
            truckSpeed = 0.0f;
            carSpeed = 0.0f;
            boatSpeed = 0.0f;
            break;
        case '1':
            speedBridgeCar1 = 0.20f;
            break;
        case '2':
            carSpeed = 0.05f;
            break;

            break;
        case '3':
            truckSpeed = 0.05f;
            break;
        case '4':
            boatSpeed = 0.01f;
            break;

        case 'M':
        case 'm':
            glutDisplayFunc(displayMor);
            break;
        glutPostRedisplay();
	}
}


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1600,900);
   glutInitWindowPosition(150,80);
   glutCreateWindow("Graphics Project");
   gluOrtho2D(-2, 2, -1, 1);
    glutDisplayFunc(displayMor);
   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, updateBridgeCar1, 0);
   glutTimerFunc(100, updateBoat, 0);
   glutTimerFunc(100, updateTruck, 0);
   glutTimerFunc(100, updateCar, 0);
   glutTimerFunc(200, cloud2, 0);
   glutTimerFunc(200, doFrame,0);
   initGL();
   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
}
