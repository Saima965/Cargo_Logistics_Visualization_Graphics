#include<windows.h> // for MS Windows
#include<GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#define PI           3.14159265358979323846
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

bool flag = false;
bool flag1=false;
bool flag2=false;
bool flag3=false;
bool flag4=false;

///////////s1
GLfloat planePosition = 2.0f;
GLfloat planeSpeed = 0.025f;

GLfloat cloud1 = 0.0f;
GLfloat cloud1Speed1 = 0.01f;

GLfloat cloud2 = 0.0f;
GLfloat cloud1Speed2 = 0.01f;

GLfloat cloud3 = 0.0f;
GLfloat cloud1Speed3 = 0.01f;

GLfloat pickup1Position = 2.0f;
GLfloat pickup1Speed = 0.02f;

GLfloat pickup2Position = 1.0f;
GLfloat pickup2Speed = 0.02f;

GLfloat box1Position = 0.0f;
GLfloat box1Speed = 0.01f;

GLfloat truckPosition = -0.49f;
GLfloat truckSpeed = 0.013f;

GLfloat pickupReturnPosition = -0.23f;
GLfloat pickupReturnSpeed = 0.02f;

///// s2

GLfloat truckPosi = 1.8; //initial positon -main object
GLfloat truckSp = 0.02;

GLfloat truckPosi2 = -1.8; //initial positon
GLfloat truckSp2 = 0.02;

GLfloat car1Posi = 0.6; //initial positon
GLfloat car1Sp = 0.02;

GLfloat car2Posi = 0.0; //initial positon
GLfloat car2Sp = 0.02;

GLfloat vanPosi = 0.6; //initial positon
GLfloat vanSp = 0.015;

GLfloat bird1Posi = 0.0; //initial positon
GLfloat bird1Sp = 0.004;

GLfloat bird2Posi = 0.4; //initial positon
GLfloat bird2Sp = 0.004;

GLfloat cloud1Sposi = 0.14;
GLfloat cloud1Sp = 0.005;
GLfloat cloud2Sposi = -0.38;
GLfloat cloud2Sp = 0.004;
GLfloat cloud3Sposi = -1;
GLfloat cloud3Sp = 0.005;
GLfloat cloud4Sposi = -0.5;
GLfloat cloud4Sp = 0.005;
GLfloat cloud5Sposi = -1.8;
GLfloat cloud5Sp = 0.005;

//////s3

GLfloat crane1p = 0.35f;
GLfloat crane1speed = 0.03f;

GLfloat crane2p = -0.37f;
GLfloat crane2speed = 0.03f;

GLfloat cloud1p = -0.4f;
GLfloat cloud1speed = 0.012f;

GLfloat cloud2p = -0.4f; //
GLfloat cloud2speed = 0.012f;

GLfloat cloud3p = 0.7f;  //
GLfloat cloud3speed = 0.012f;


GLfloat truckposition1 = 1.4f; //thamano
GLfloat truckspeed1 = 0.03f;

GLfloat truckposition2 = 0.01f; //thamano ta move
GLfloat truckspeed2 = 0.03f;

GLfloat truckposition3 = 1.4f; //2nd truck
GLfloat truckspeed3 = 0.03f;

GLfloat boatPosiR = 1.5;
GLfloat boatSpR = 0.02;

/////s4

//wave
GLfloat wavePosition1 = -1.0f;
GLfloat wavespeed1 = 0.0022f;

//cloud move1
GLfloat cloudPosition1 = -0.4f;
GLfloat cloudspeed1 = 0.0052f;

//cloud move2
GLfloat cloudPosition2 = -0.1f;
GLfloat cloudspeed2 = 0.005f;

//cloud move3
GLfloat cloudPosition3 = -0.25f;
GLfloat cloudspeed3 = 0.006f;

//ship coming and stop
GLfloat shipPosition1 = 2.0f;
GLfloat shipSpeed1 = 0.03f;

//ship moving again
GLfloat shipPosition2 = 0.01f;
GLfloat shipSpeed2 = 0.03f;

//rope1 down
GLfloat ropePositionD1 = 0.0f;
GLfloat ropeSpeedD1 = 0.02f;

//rope2 down
GLfloat ropePositionD2 = 0.0f;
GLfloat ropeSpeedD2 = 0.02f;

//rope3 down
GLfloat ropePositionD3 = 0.0f;
GLfloat ropeSpeedD3 = 0.02f;

//rope4 down
GLfloat ropePositionD4 = 0.0f;
GLfloat ropeSpeedD4 = 0.02f;

//rope1 up
GLfloat ropePositionU1 = 0.0f;
GLfloat ropeSpeedU1 = 0.02f;

//rope2 up
GLfloat ropePositionU2= 0.0f;
GLfloat ropeSpeedU2 = 0.02f;

//rope3 up
GLfloat ropePositionU3= 0.0f;
GLfloat ropeSpeedU3 = 0.02f;

//rope4 up
GLfloat ropePositionU4= 0.0f;
GLfloat ropeSpeedU4 = 0.02f;

//container down
GLfloat containerPositionD = 0.0f;
GLfloat containerSpeedD = 0.016f;

//container remove
GLfloat containermovePosition = -0.001f;
GLfloat containermoveSpeed = 0.03f;

///////s5
GLfloat shipPositionF = 1.8;
GLfloat shipSpeedF = 0.02;

GLfloat cloud1positionF1 = -0.4f;
GLfloat cloud1speedF1 = 0.012f;

GLfloat cloud2positionF2 = -0.4f; //
GLfloat cloud2speedF2 = 0.012f;

GLfloat cloud3positionF3 = 0.7f;  //
GLfloat cloud3speedF3 = 0.012f;



///// Humayra's part///
void updatehf (int value)
{
    flag = true;

    if(planePosition < -2.5)
        planePosition = 2.5;
    planePosition -= planeSpeed;


    if(cloud1 >1.8)
        cloud1 = -0.7;
    cloud1 += cloud1Speed1;

    if(cloud3 >1.2)
        cloud3 = -1.2;
    cloud3 += cloud1Speed3;

    if(cloud2 >0.4)
        cloud2 = -2;
    cloud2 += cloud1Speed2;

    if(pickup1Position > 2)
        pickup1Position = -1.8;
    pickup1Position += pickup1Speed;

    if(pickup2Position < -0.23)
        pickup2Position = -0.23;
    pickup2Position -= pickup2Speed;


    glutPostRedisplay();
    glutTimerFunc(60, updatehf, 0);
}

void update1hf (int value)
{
    flag = true;

    if(box1Position < -2.7)
        box1Position = -2.7;
    box1Position -= box1Speed;


    glutPostRedisplay();
    glutTimerFunc(60, update1hf, 0);
}

void update2hf (int value)
{
    flag = true;

    if(truckPosition < -1.7)
        truckPosition = -1.7;
    truckPosition -= truckSpeed;


    glutPostRedisplay();
    glutTimerFunc(60, update2hf, 0);
}

void update3hf (int value)
{

    if(pickupReturnPosition > 1.2)
        pickupReturnPosition = 1.2;
    pickupReturnPosition += pickupReturnSpeed;


    glutPostRedisplay();
    glutTimerFunc(60, update3hf, 0);
}
//cover
void display0()
{
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

//page border
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.5, 0.98);
    glVertex2f(0.5, 0.98);
    glVertex2f(0.5, -0.98);
    glVertex2f(-0.5, -0.98);
    glEnd();

//uni name
    glPushMatrix();
    glTranslatef(-0.08,-0.01, 0);
    glColor3f(0,0,0);
    renderBitmapString(-0.347826713588, 0.8116267414833, 0, GLUT_BITMAP_TIMES_ROMAN_24, "American International University -Bangladesh (AIUB)");
    glPopMatrix();

//course name
    glPushMatrix();
    glTranslatef(-0.02, 0, 0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1690949430827, 0.69, 0, GLUT_BITMAP_HELVETICA_18, "Course : Computer Graphics");
    glPopMatrix();

//section
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.0707104822541, 0.6173174313468, 0, GLUT_BITMAP_9_BY_15, "Section : C");

//project name
    glPushMatrix();
    glTranslatef(-0.15, -0.07, 0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.2150076914694, 0.5402496036977, 0, GLUT_BITMAP_HELVETICA_18, "Project Name : Containerization of Shipping Containers");
    glPopMatrix();

//group number
    glColor3f(0.0,0.,0.0);
    renderBitmapString(-0.065, 0.4, 0, GLUT_BITMAP_9_BY_15, "Group : 4");

//Submitted to
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.085, 0.3, 0.0, GLUT_BITMAP_9_BY_15, "Submitted to");
    renderBitmapString(-0.084, 0.29, 0.0, GLUT_BITMAP_9_BY_15, "____________");

//MAHFUJUR RAHMAN
    glPushMatrix();
    glTranslatef(0.01, -0.15, 0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.1612865259168, 0.3559436165065, 0.0, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHMAN");
    glPopMatrix();

//ASSISTANT PROFESSOR
    glPushMatrix();
    glTranslatef(0.01, -0.15, 0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.13, 0.29, 0.0, GLUT_BITMAP_HELVETICA_12, "ASSISTANT PROFESSOR");
    glPopMatrix();

//FACULTY
    glPushMatrix();
    glTranslatef(-0.14, -0.15, 0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.07, 0.24, 0.0, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE AND TECHNOLOGY");
    glPopMatrix();

//DEPARTMENT OF COMPUTER SCIENCE
    glPushMatrix();
    glTranslatef(0.0, -0.15, 0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.19, 0.18, 0.0, GLUT_BITMAP_HELVETICA_12, "DEPARTMENT OF COMPUTER SCIENCE");
    glPopMatrix();

//Submitted by:
    glPushMatrix();
    glTranslatef(-0.01, -0.17, 0.0);
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.07, 0.13, 0.0,GLUT_BITMAP_9_BY_15, "Submitted to");
    renderBitmapString(-0.07, 0.12, 0.0, GLUT_BITMAP_9_BY_15, "____________");
    glPopMatrix();

//table
//border
    glBegin(GL_QUADS);
    glColor3f(0.22, 0.13, 0.22);
    glVertex2f(-0.4, -0.1);
    glVertex2f(0.4, -0.1);
    glVertex2f(0.4, -0.7);
    glVertex2f(-0.4, -0.7);
    glEnd();
//2nd row
    glBegin(GL_QUADS);
    glColor3f(0.91, 0.81, 0.91);
    glVertex2f(-0.4, -0.2);
    glVertex2f(0.4, -0.2);
    glVertex2f(0.4, -0.7);
    glVertex2f(-0.4, -0.7);
    glEnd();
//4th row
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.64, 0.77);
    glVertex2f(-0.4, -0.3);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.4);
    glVertex2f(-0.4, -0.4);
    glEnd();
//6th row
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.64, 0.77);
    glVertex2f(-0.4, -0.5);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.4, -0.6);
    glVertex2f(-0.4, -0.6);
    glEnd();

//serial
    glPushMatrix();
    glTranslatef(0.0,-0.244,0.0);
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.38, 0.08, 0.0, GLUT_BITMAP_HELVETICA_12, "SERIAL NO.");
    glPopMatrix();

//name
    glPushMatrix();
    glTranslatef(0.0,-0.244,0.0);
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.2, 0.08, 0.0, GLUT_BITMAP_HELVETICA_12, "NAME");
    glPopMatrix();

//id
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(0.1,-0.155, 0.0, GLUT_BITMAP_HELVETICA_12, "ID");

//Contribution
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(0.24, -0.155, 0.0, GLUT_BITMAP_HELVETICA_12, "CONTRIBUTION");

//Saima binte ahsan
//serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35, -0.26, 0.0, GLUT_BITMAP_HELVETICA_12, "25");

//name
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.26, -0.26, 0.0, GLUT_BITMAP_HELVETICA_12, "AHSAN,SAIMA BINTE");

//Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.06, -0.26, 0.0, GLUT_BITMAP_HELVETICA_12, "22-49481-3");

//contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.3, -0.26, 0.0, GLUT_BITMAP_HELVETICA_12, "20%");

//md shahariar kabir bhuiya
//serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35, -0.36, 0.0, GLUT_BITMAP_HELVETICA_12, "27");

//name
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.28, -0.36, 0.0, GLUT_BITMAP_HELVETICA_12, "BHUIYA,MD SHAHARIAR KABIR");

//Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.06, -0.36, 0.0, GLUT_BITMAP_HELVETICA_12, "22-49513-3");

//contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.3, -0.36, 0.0, GLUT_BITMAP_HELVETICA_12, "20%");

//humayra fahmida
//serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35, -0.46, 0.0, GLUT_BITMAP_HELVETICA_12, "31");

//name
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.26, -0.46, 0.0, GLUT_BITMAP_HELVETICA_12, "FAHMIDA,HUMAYRA");

//Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.06, -0.46, 0.0, GLUT_BITMAP_HELVETICA_12, "22-49582-3");

//contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.3, -0.46, 0.0, GLUT_BITMAP_HELVETICA_12, "20%");

//anika tabassum ria
//serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35, -0.56, 0.0, GLUT_BITMAP_HELVETICA_12, "32");

//name
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.26, -0.56, 0.0, GLUT_BITMAP_HELVETICA_12, "RIA,ANIKA TABASSUM");

//Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.06, -0.56, 0.0, GLUT_BITMAP_HELVETICA_12, "22-49586-3");

//contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.3, -0.56, 0.0, GLUT_BITMAP_HELVETICA_12, "20%");

//faisal ahmed
//serial
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.35,  -0.66, 0.0, GLUT_BITMAP_HELVETICA_12, "33");

//name
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.26,  -0.66, 0.0, GLUT_BITMAP_HELVETICA_12, "AHMED,FAISAL");

//Id
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.06,  -0.66, 0.0, GLUT_BITMAP_HELVETICA_12, "22-49591-3");

//contribution
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.3,  -0.66, 0.0, GLUT_BITMAP_HELVETICA_12, "20%");


//Click the ENTER button of your keyboard to continue
    renderBitmapString(-0.42, -0.85, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the RIGHT BUTTON from mouse to continue ]");

     glFlush(); // Render now
}
void display_instructions()
 {
    glClearColor(0.84f, 0.89f, 0.88f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    //Welcome
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.12, 0.5, 0, GLUT_BITMAP_HELVETICA_18, " 'W E L C O M E' ");

    //Click "1" to view page 1
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25, 0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "# To View Scene 1 - Click '1'");

    //Click "2" to view page 2
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25, 0.2, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "# To View Scene 2 - Click '2'");

    //Click "3" to view page 3
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25, 0.1, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "# To View Scene 3 - Click '3'");

    //Click "4" to view page 4
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25, 0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "# To View Scene 4 - Click '4'");

    //Click "5" to view page 5
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.25, -0.1, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "# To View Scene 5 - Click '5'");

    //Click the left button of your mouse to visit cover page
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.5, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "[ Click the LEFT BUTTON from mouse back to the Cover Page ]");

    //thanks
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.11, -0.8, 0.0, GLUT_BITMAP_8_BY_13, "[ THANK YOU ]");
    glEnd();
    glFlush(); // Render now
}
//cover end
//road part
void roadhf()
{
   glBegin(GL_QUADS);
   glColor3f(0.22, 0.23, 0.27);
   glVertex2f(-1,0.05);
   glVertex2f(1, 0.05);
   glColor3f(0.61, 0.62, 0.64);
   glVertex2f(1,0);
   glVertex2f(-1, 0);

   glEnd();

   glBegin(GL_POLYGON);
   glColor3f(0.22, 0.23, 0.27);
   glVertex2f(-1, -1);
   glVertex2f(1, -1);
   glColor3f(0.61, 0.62, 0.64);
   glVertex2f(1,0);
   glVertex2f(-1, 0);
   glEnd();

//road lane01
   glBegin(GL_QUADS);
   glColor3f(0.9, 0.91, 0.92);

   glVertex2f(-0.9098709992439, -0.3360006473802);
   glVertex2f(-0.6565, -0.334);
   glVertex2f(-0.718765, -0.37982);
   glVertex2f(-0.9724238651433, -0.3800225839226);

   glVertex2f(-0.535, -0.34);
   glVertex2f(-0.2620226977537, -0.3403721529299);
   glVertex2f(-0.306749197134, -0.3795593863466);
   glVertex2f(-0.6, -0.38);

   glVertex2f(-0.1, -0.34);
   glVertex2f(-0.1563228181402, -0.3801983204208);
   glVertex2f(0.14, -0.38);
   glVertex2f(0.19, -0.34);

   glVertex2f(0.36, -0.34);
   glVertex2f(0.32, -0.38);
   glVertex2f(0.62, -0.38);
   glVertex2f(0.66, -0.34);

   glVertex2f(0.84, -0.34);
   glVertex2f(0.8, -0.38);
   glVertex2f(1, -0.38);
   glVertex2f(1, -0.34);

//road lane02
   glVertex2f(0.96, -0.8);
   glVertex2f(0.92, -0.84);
   glVertex2f(0.6099900053137, -0.8400909879467);
   glVertex2f(0.66, -0.8);

   glVertex2f(0.49, -0.8);
   glVertex2f(0.4498618616576, -0.8400891300395);
   glVertex2f(0.1041849268059, -0.8401699366744);
   glVertex2f(0.15, -0.8);

   glVertex2f(0, -0.8);
   glVertex2f(-0.0673381683056, -0.8401699366744);
   glVertex2f(-0.48, -0.84);
   glVertex2f(-0.4, -0.8);

   glVertex2f(-0.6, -0.8);
   glVertex2f(-0.64, -0.84);
   glVertex2f(-1, -0.8391786035541);
   glVertex2f(-0.9391213379806, -0.799142018262);

  glEnd();

//Lamp 1
    glPushMatrix();
    glTranslatef(0.05,0.41,0);
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.45, 0.45);
    glVertex2f(0.2, -0.165);
    glVertex2f(0.208, -0.165);
    glVertex2f(0.208, -0.41);
    glVertex2f(0.2, -0.41);
    glEnd();
    //Light 1
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.177, -0.15);
    glVertex2f(0.197, -0.15);
    glVertex2f(0.197, -0.18);
    glVertex2f(0.177, -0.18);
    glEnd();
    //Light 3
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.229, -0.15);
    glVertex2f(0.211, -0.15);
    glVertex2f(0.211, -0.18);
    glVertex2f(0.229, -0.18);
    glEnd();
    glPopMatrix();
//Lamp 2
    glPushMatrix();
    glTranslatef(-0.5,0.41,0);
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.45, 0.45);
    glVertex2f(0.2, -0.165);
    glVertex2f(0.208, -0.165);
    glVertex2f(0.208, -0.41);
    glVertex2f(0.2, -0.41);
    glEnd();
    //Light 1
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.177, -0.15);
    glVertex2f(0.197, -0.15);
    glVertex2f(0.197, -0.18);
    glVertex2f(0.177, -0.18);
    glEnd();
    //Light 3
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.229, -0.15);
    glVertex2f(0.211, -0.15);
    glVertex2f(0.211, -0.18);
    glVertex2f(0.229, -0.18);
    glEnd();
    glPopMatrix();
//Lamp 3
    glPushMatrix();
    glTranslatef(0.76,0.41,0);
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.45, 0.45);
    glVertex2f(0.2, -0.165);
    glVertex2f(0.208, -0.165);
    glVertex2f(0.208, -0.41);
    glVertex2f(0.2, -0.41);
    glEnd();
    //Light 1
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.177, -0.15);
    glVertex2f(0.197, -0.15);
    glVertex2f(0.197, -0.18);
    glVertex2f(0.177, -0.18);
    glEnd();
    //Light 3
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.229, -0.15);
    glVertex2f(0.211, -0.15);
    glVertex2f(0.211, -0.18);
    glVertex2f(0.229, -0.18);
    glEnd();
    glPopMatrix();
//Lamp 4
    glPushMatrix();
    glTranslatef(-1.1,0.41,0);
    glBegin(GL_QUADS);
    glColor3f(0.44, 0.45, 0.45);
    glVertex2f(0.2, -0.165);
    glVertex2f(0.208, -0.165);
    glVertex2f(0.208, -0.41);
    glVertex2f(0.2, -0.41);
    glEnd();
    //Light 1
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.177, -0.15);
    glVertex2f(0.197, -0.15);
    glVertex2f(0.197, -0.18);
    glVertex2f(0.177, -0.18);
    glEnd();
    //Light 3
    glBegin(GL_QUADS);
    glColor3f(0.98f, 1.0f, 0.18f);
    glVertex2f(0.229, -0.15);
    glVertex2f(0.211, -0.15);
    glVertex2f(0.211, -0.18);
    glVertex2f(0.229, -0.18);
    glEnd();
    glPopMatrix();

}
//sky
void skyhf()
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0.46, 0.57);
    glVertex2f(-1,1);
    glVertex2f(1, 1);
    glColor3f(0.03, 0.50, 0.56);
    glVertex2f(1, 0.72);
    glVertex2f(-1, 0.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.07, 0.50, 0.56);
    glVertex2f(-1, 0.7);
    glVertex2f(1, 0.72);
    glColor3f(0.015, 0.54, 0.55);
    glVertex2f(1, 0.6);
    glVertex2f(-1, 0.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.025, 0.54, 0.55);
    glVertex2f(-1,0.6);
    glVertex2f(1, 0.6);
    glColor3f(0.035, 0.58, 0.54);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.045, 0.58, 0.54);
    glVertex2f(-1,0.3);
    glVertex2f(1, 0.3);
    glColor3f(0.055, 0.62, 0.53);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();
}
//clouds
void clouds1hf(float r, float s)
{

    glPushMatrix();
    glTranslatef(cloud1,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);
    glScalef(0.8,1,0);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}
void clouds2hf(float r, float s)
{

    glPushMatrix();
    glTranslatef(cloud2,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);
    glScalef(0.8,1,0);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}
void clouds3hf(float r, float s)
{

    glPushMatrix();
    glTranslatef(cloud3,0.0f, 0.0f);

    glTranslatef(r,s, 0.0f);
    glScalef(0.8,1,0);

    //cloud
    int i;

    GLfloat x=2.0664666559629f;
    GLfloat y=0.384679318014f;
    GLfloat radius =0.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x1=2.1249747089483f;
    GLfloat y1=0.3731062965444f;
    GLfloat radius1 =0.04f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x2=2.0086015486148f;
    GLfloat y2=0.362176220712f;
    GLfloat radius2 =0.045f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=1.9610235714619f;
    GLfloat y3=0.3512461448795f;
    GLfloat radius3 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=2.1641943928175f;
    GLfloat y4=0.3692486227212f;
    GLfloat radius4 =0.025f;
    //int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    //GLfloat twicePi = 2.0f * PI;

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

}

//house
void househf()
{
/*//house3
    glBegin(GL_POLYGON);
    glColor3f(0.85, 0.4, 0.08);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.34, 0.26);
    glVertex2f(0.3, 0.26);
    glVertex2f(0.66, 0.5);
    glVertex2f(0.98, 0.26);
    glVertex2f(0.94, 0.26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.87, 0.82, 0.81);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glVertex2f(0.36, -0.1);
    glVertex2f(0.92, -0.1);
    glVertex2f(0.9200725661641, 0.2749455753769);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.74, 0.78);
    glVertex2f(0.66, 0.44);
    glVertex2f(0.3599301824944, 0.2399999856633);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.9200725661641, 0.2749455753769);
    glVertex2f(0.92, 0.24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.28, 0.26);
    glVertex2f(0.48, 0.25);
    glVertex2f(0.48,-0.1);
    glVertex2f(0.8,-0.1);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.8, 0.25);
    glEnd();

//house box1
    //box
    glPushMatrix();

    glTranslatef(0.25,1.09,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//house box2
     //box
    glPushMatrix();

    glTranslatef(0.32,1.09,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//house box3
     //box
    glPushMatrix();

    glTranslatef(0.39,1.09,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//house box4
     //box
    glPushMatrix();

    glTranslatef(0.29,1.175,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();


//house box5
     //box
    glPushMatrix();

    glTranslatef(0.365,1.175,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//house box6
     //box
    glPushMatrix();

    glTranslatef(0.325,1.2634,0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//house 2

    glPushMatrix();

    glTranslatef(-0.45, 0, 0);
    glScalef(0.7, 0.7, 0);

    glBegin(GL_POLYGON);
    glColor3f(0, 0.16, 0.22);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.34, 0.26);
    glVertex2f(0.3, 0.26);
    glVertex2f(0.66, 0.5);
    glVertex2f(0.98, 0.26);
    glVertex2f(0.94, 0.26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.77, 0.97, 0.87);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glVertex2f(0.36, -0.1);
    glVertex2f(0.92, -0.1);
    glVertex2f(0.9200725661641, 0.2749455753769);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.62, 0.74, 0.71);
    glVertex2f(0.66, 0.44);
    glVertex2f(0.3599301824944, 0.2399999856633);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.9200725661641, 0.2749455753769);
    glVertex2f(0.92, 0.24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.74, 0.62);
    glVertex2f(0.48, 0.25);
    glVertex2f(0.48,-0.1);
    glVertex2f(0.8,-0.1);
    glVertex2f(0.8, 0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.33, 0.45, 0.45);
    glVertex2f(0.36, 0.02);
    glVertex2f(0.48, 0.02);
    glVertex2f(0.48, -0.1);
    glVertex2f(0.36, -0.1);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.33, 0.45, 0.45);
    glVertex2f(0.8, 0.02);
    glVertex2f(0.92, 0.02);
    glVertex2f(0.92, -0.1);
    glVertex2f(0.8, -0.1);
    glEnd();
//shutter
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.83, 0.81, 0.64);
    glVertex2f(0.48, 0.25);
    glVertex2f(0.8, 0.25);
    glVertex2f(0.48, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.46, 0.44, 0.3);
    glVertex2f(0.48, 0.2);
    glVertex2f(0.48,0.18);
    glVertex2f(0.8,0.18);
    glVertex2f(0.8, 0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.81, 0.64);
    glVertex2f(0.48, 0.0996965731198);
    glVertex2f(0.8, 0.1);
    glVertex2f(0.8, 0.18);
    glVertex2f(0.48, 0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.46, 0.44, 0.3);
    glVertex2f(0.48, 0.1);
    glVertex2f(0.48,0.08);
    glVertex2f(0.8,0.08);
    glVertex2f(0.8, 0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.81, 0.64);
    glVertex2f(0.48, 0.08);
    glVertex2f(0.8, 0.08);
    glVertex2f(0.8,0);
    glVertex2f(0.48, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.46, 0.44, 0.3);
    glVertex2f(0.48, -0.000040285951);
    glVertex2f(0.48,-0.02);
    glVertex2f(0.8, -0.02);
    glVertex2f(0.8, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.81, 0.64);
    glVertex2f(0.48, -0.02);
    glVertex2f(0.8, -0.02);
    glVertex2f(0.8,-0.1);
    glVertex2f(0.48, -0.1);
    glEnd();


    glPopMatrix();

//house 1

    glPushMatrix();

    glTranslatef(-1.13, -0.03, 0);
    glScalef(0.8, 0.8, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.24, 0.13);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.34, 0.26);
    glVertex2f(0.3, 0.26);
    glVertex2f(0.66, 0.5);
    glVertex2f(0.98, 0.26);
    glVertex2f(0.94, 0.26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.55);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glColor3f(0.67, 0.72, 0.85);
    glColor3f(0.11, 0.31, 0.32);
    glVertex2f(0.36, -0.1);
    glVertex2f(0.92, -0.1);

    glVertex2f(0.9200725661641, 0.2749455753769);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.31, 0.32);
    glVertex2f(0.66, 0.44);
    glVertex2f(0.3599301824944, 0.2399999856633);
    glVertex2f(0.3599233907417, 0.2730747251742);
    glVertex2f(0.66, 0.47);
    glVertex2f(0.9200725661641, 0.2749455753769);
    glVertex2f(0.92, 0.24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.49, 0.45, 0.45);
    glVertex2f(0.48, 0.25);
    glVertex2f(0.48,-0.1);
    glVertex2f(0.8,-0.1);
    glVertex2f(0.8, 0.25);
    glEnd();
//box place
    glBegin(GL_POLYGON);
    glColor3f(0.63, 0.64, 0.64);
    glVertex2f(0.6, 0.25);
    glVertex2f(0.605,0.25);
    glVertex2f(0.605,-0.1);
    glVertex2f(0.6, -0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.63, 0.64, 0.64);
    glVertex2f(0.48, 0.1);
    glVertex2f(0.48,0.08);
    glVertex2f(0.6,0.08);
    glVertex2f(0.6, 0.1);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.63, 0.64, 0.64);
    glVertex2f(0.61, 0.1);
    glVertex2f(0.61,0.08);
    glVertex2f(0.8,0.08);
    glVertex2f(0.8, 0.1);
    glEnd();

    glPopMatrix();
    //boxes1
    glPushMatrix();

    glTranslatef(-0.879, 0.872, 0);
    glScalef(0.9,0.9,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();
    //boxes2
    glPushMatrix();

    glTranslatef(-0.925, 0.872, 0);
    glScalef(0.9,0.9,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();
    //boxes3
    glPushMatrix();

    glTranslatef(-0.84, 1.08, 0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//left box1

    glPushMatrix();

    glTranslatef(-1.25, 1.1, 0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//left box2

    glPushMatrix();

    glTranslatef(-1.18, 1.1, 0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();

//left box3

    glPushMatrix();

    glTranslatef(-1.21, 1.187, 0);
    glScalef(1.2,1.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();*/

}
//truck & boxes
void truckhf()
{
    glPushMatrix();
    glTranslatef(truckPosition, 0.0, 0.0f);
    glScalef(0.5,1,1);
    //1st face
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
glEnd();
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
glEnd();
    //mid
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
glEnd();
//4th line
//box1
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
     glVertex2f(0.0699138223646, -0.7003651235768);
glEnd();

//box2
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
glEnd();
//gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
glEnd();

//box3
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
glEnd();
//bigbox violet
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();
//gaps
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.69);
    //glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.7);
    //glVertex2f(0.7, -0.69);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7, -0.69);
    glEnd();
//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();
 glPopMatrix();
}
void box1()
{
//pickups

    //box

    glPushMatrix();

    glTranslatef(box1Position, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();

    glPopMatrix();
}
void pickuphf()
{
    // pickup body
    glPushMatrix();

    glTranslatef(pickup1Position, 2, 0);
    glScalef(1.8,2.5,0);
    glBegin(GL_POLYGON);
    glColor3f(1, 0.81, 0);
    glVertex2f(0.339165193542, -0.8847715896556);
    glVertex2f(0.3297084007393, -0.8464715788044);
    glVertex2f(0.270603445722, -0.8464715788044);
    glColor3f(0.79, 0.72, 0.43);
    glVertex2f(0.2710762853621, -0.8871357878563);
    glVertex2f(0.2619747439794, -0.8873709642964);
    glVertex2f(0.2626852468196, -0.9211198492048);
    glColor3f(0.94, 0.91, 0.79);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3803022422341, -0.886190108576);

    glEnd();

// pickup window,handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.3215668412371, -0.8506717528616);
    glVertex2f(0.2765400522031, -0.8522010737076);
    glVertex2f(0.2776487297447, -0.8853694873557);
    glVertex2f(0.3295740107358, -0.8851268458557);
    glVertex2f(0.285013693269, -0.8902082638051);
    glVertex2f(0.28, -0.89);
    glVertex2f(0.2799025350623, -0.8924798896747);
    glVertex2f(0.285013693269, -0.8924798896747);

    glEnd();

// van 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.92);
    glVertex2f(0.256, -0.92);
    glVertex2f(0.256, -0.864);
    glVertex2f(0.25, -0.864);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.256, -0.91);
    glVertex2f(0.256, -0.914);
    glVertex2f(0.258, -0.914);
    glVertex2f(0.258, -0.91);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.262, -0.83);
    glVertex2f(0.262, -0.92);
    glVertex2f(0.258, -0.92);
    glVertex2f(0.258, -0.82);
    glVertex2f(0.28, -0.82);
    glVertex2f(0.28, -0.83);
    glEnd();

    //box
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.66, 0.33);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.2, -0.915);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.2, 0.21, 0.14);
    glVertex2f(0.22, -0.86);
    glVertex2f(0.22, -0.85);
    glVertex2f(0.23, -0.85);
    glVertex2f(0.23, -0.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.915);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.205, -0.85);
    glVertex2f(0.2, -0.85);
    glVertex2f(0.2, -0.855);
    glVertex2f(0.245, -0.915);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.52, 0.38);
    glVertex2f(0.25, -0.85);
    glVertex2f(0.245, -0.85);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.915);
    glVertex2f(0.205, -0.915);
    glVertex2f(0.25, -0.855);
    glEnd();


//tire1

    int i1;

    GLfloat x1=0.3580643093089f;
    GLfloat y1=-0.9211174250007f;
    GLfloat radius1 =0.02f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
    }
    glEnd();

    int i1a;

    GLfloat x1a=0.3580643093089f;
    GLfloat y1a=-0.9211174250007f;
    GLfloat radius1a =0.01f;
    int triangleAmount1a = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1a = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1a, y1a); // center of circle
    for(i1a = 0; i1a <= triangleAmount1a; i1a++)
    {
        glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                    y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
    }
    glEnd();
//tire2
    int i2;

    GLfloat x2=0.2834720472102f;
    GLfloat y2=-0.9198775399146f;
    GLfloat radius2 =0.02f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    int i2a;

    GLfloat x2a=0.2834720472102f;
    GLfloat y2a=-0.9198775399146f;
    GLfloat radius2a =0.01f;
    int triangleAmount2a = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2a = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2a, y2a); // center of circle
    for(i2a = 0; i2a <= triangleAmount2a; i2a++)
    {
        glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                    y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
    }
    glEnd();


    glPopMatrix();
}
void pickup2hf()
{
//plane
    // pickup body
    glPushMatrix();

    glTranslatef(pickup2Position, 1.55,0);

    glTranslatef(pickupReturnPosition, 0,0);


    glScalef(1.8,2.5,0);
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.74, 0.36);
    glVertex2f(0.339165193542, -0.8847715896556);
    glVertex2f(0.3297084007393, -0.8464715788044);
    glVertex2f(0.270603445722, -0.8464715788044);
    glColor3f(0.79, 0.72, 0.43);
    glVertex2f(0.2710762853621, -0.8871357878563);
    glVertex2f(0.2619747439794, -0.8873709642964);
    glVertex2f(0.2626852468196, -0.9211198492048);
    glColor3f(0.94, 0.91, 0.79);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3809839697092, -0.9228961063053);
    glVertex2f(0.3803022422341, -0.886190108576);

    glEnd();

// pickup window,handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.3215668412371, -0.8506717528616);
    glVertex2f(0.2765400522031, -0.8522010737076);
    glVertex2f(0.2776487297447, -0.8853694873557);
    glVertex2f(0.3295740107358, -0.8851268458557);

    glVertex2f(0.285013693269, -0.8902082638051);
    glVertex2f(0.28, -0.89);
    glVertex2f(0.2799025350623, -0.8924798896747);
    glVertex2f(0.285013693269, -0.8924798896747);

    glEnd();

// van 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.25, -0.91);
    glVertex2f(0.2, -0.91);
    glVertex2f(0.2, -0.92);
    glVertex2f(0.256, -0.92);
    glVertex2f(0.256, -0.864);
    glVertex2f(0.25, -0.864);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.256, -0.91);
    glVertex2f(0.256, -0.914);
    glVertex2f(0.258, -0.914);
    glVertex2f(0.258, -0.91);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.262, -0.83);
    glVertex2f(0.262, -0.92);
    glVertex2f(0.258, -0.92);
    glVertex2f(0.258, -0.82);
    glVertex2f(0.28, -0.82);
    glVertex2f(0.28, -0.83);
    glEnd();

    box1();


//tire1

    int i1;

    GLfloat x1=0.3580643093089f;
    GLfloat y1=-0.9211174250007f;
    GLfloat radius1 =0.02f;
    int triangleAmount1 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount1; i1++)
    {
        glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
    }
    glEnd();

    int i1a;

    GLfloat x1a=0.3580643093089f;
    GLfloat y1a=-0.9211174250007f;
    GLfloat radius1a =0.01f;
    int triangleAmount1a = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1a = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1a, y1a); // center of circle
    for(i1a = 0; i1a <= triangleAmount1a; i1a++)
    {
        glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                    y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
    }
    glEnd();
//tire2
    int i2;

    GLfloat x2=0.2834720472102f;
    GLfloat y2=-0.9198775399146f;
    GLfloat radius2 =0.02f;
    int triangleAmount2 = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
    }
    glEnd();

    int i2a;

    GLfloat x2a=0.2834720472102f;
    GLfloat y2a=-0.9198775399146f;
    GLfloat radius2a =0.01f;
    int triangleAmount2a = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2a = 2.0f * PI;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2a, y2a); // center of circle
    for(i2a = 0; i2a <= triangleAmount2a; i2a++)
    {
        glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                    y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
    }
    glEnd();


    glPopMatrix();
}
void planehf()
{
//buildings & window
    //Plane
    //plane body
    glPushMatrix();

    glTranslatef(planePosition,0.6, 0.0f);

    glScalef(-0.4,0.7,0);

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.53, 0.71);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.8375889660587f, 0.2912098678332f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glColor3f(1,1,1);
    glVertex2f(-0.928861465027f, 0.2556290631507f);
    glVertex2f(-0.9041096009f, 0.2378386608094f);
    glVertex2f(-0.8731697707412f, 0.2277832160078f);
    //glColor3f(0,0,0);
    glVertex2f(-0.8453239235984f, 0.2192747627141f);
    glVertex2f(-0.8143840934396f, 0.2107663094205f);
    glVertex2f(-0.7842177590348f, 0.2068988306506f);
    //glColor3f(0.53, 0.53, 0.53);
    glVertex2f(-0.7439959798284f, 0.2076723264046f);
    glVertex2f(-0.3897349245107f, 0.2092193179125f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glColor3f(0.87, 0.84, 0);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glEnd();

    //plane head
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.53, 0.71);
    glVertex2f(-0.4214482504234f, 0.2919833635872f);
    glVertex2f(-0.4043823800643f, 0.2892785841354f);
    glVertex2f(-0.3831964687035f, 0.2802549552225f);
    glVertex2f(-0.3545562551972f, 0.2671118435449f);
    glVertex2f(-0.3380783241388f, 0.2622076973966f);
    glColor3f(1,1,1);
    glVertex2f(-0.3237582173856f, 0.2573035512482f);
    glVertex2f(-0.3176770761617f, 0.2518109075621f);
    glVertex2f(-0.3121844324755f, 0.2463182638759f);
    glVertex2f(-0.31f, 0.24f);
    glVertex2f(-0.3098304423243f, 0.2357253081955f);
    //glColor3f(0,0,0);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.313753759243f, 0.2259170158989f);

    glVertex2f(-0.3204233980047f, 0.2227783623639f);
    glVertex2f(-0.3280738659961f, 0.2190512112912f);
    glVertex2f(-0.3378821582928f, 0.2157163919103f);
     //glColor3f(0.87, 0.84, 0);
    glVertex2f(-0.3500444407407f, 0.2127739042213f);
    glVertex2f(-0.3603420858598f, 0.2130867966824f);
    glEnd();

    //plane head window
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.3819451920869f, 0.2758911800548f);
    glVertex2f(-0.3881479557192f, 0.2728587178345f);
    glVertex2f(-0.3771897399688f, 0.2608667081453f);
    glVertex2f(-0.370504539165f, 0.2634167331942f);
    glVertex2f(-0.3660936850265f, 0.2658289190512f);
    glVertex2f(-0.360855795737f, 0.2696194968265f);
    glVertex2f(-0.3786950838177f, 0.2781892511995f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.398899412682f, 0.2686546224837f);
    glVertex2f(-0.4098576284324f, 0.2679654265246f);
    glVertex2f(-0.40854815611f, 0.262727537235f);
    glVertex2f(-0.4031035080328f, 0.2555598992599f);
    glVertex2f(-0.3925588098578f, 0.2561801756231f);
    glVertex2f(-0.3804978805727f, 0.2588680398638f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.39f, 0.27f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4127657925046f, 0.2602777634305f);
    glVertex2f(-0.4148377327393f, 0.2667761214393f);
    glVertex2f(-0.4317899710231f, 0.2668703005408f);
    glVertex2f(-0.432260866531f, 0.260371942532f);
    glVertex2f(-0.4296238516869f, 0.2515191069838f);
    glVertex2f(-0.4077743001211f, 0.2526492562027f);

    glEnd();

    //front door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.4540351082859f, 0.2649984619558f);
    glVertex2f(-0.4772069712714f, 0.26414811836f);
    glVertex2f(-0.4757188699787f, 0.2158911192986f);
    glVertex2f(-0.4516966633975f, 0.2156785333997f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.4695704482148f, 0.2425964533209f);
    glVertex2f(-0.4727942748017f, 0.2424499157487f);
    glVertex2f(-0.4726477372296f, 0.2379072510126f);
    glVertex2f(-0.4692773730705f, 0.2380537885847f);

    glEnd();

    //upper wing
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.5498485455822f, 0.2873423890634f);
    glVertex2f(-0.6217836507013f, 0.3770678965238f);
    glVertex2f(-0.6565909596299f, 0.3778413922778f);
    glVertex2f(-0.6488595295804f, 0.2915606660423f);

    glEnd();

    //lower wing
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8512841908058f, 0.1241487992192f);
    glVertex2f(-0.8652666039946f, 0.1246309513981f);
    glVertex2f(-0.8522484951637f, 0.1101663860304f);
    glVertex2f(-0.8291051905754f, 0.1111306903883f);
    glVertex2f(-0.5055818995018f, 0.2087134359257f);
    glVertex2f(-0.7114611649165f, 0.2078143998322f);

    glEnd();

    //lower wing back
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.847900370437f, 0.2811701757442f);
    glVertex2f(-0.9292604039938f, 0.2448081495735f);
    glVertex2f(-0.9792581899784f, 0.2452626749007f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);

    glEnd();

    //upper wing back
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.8228925467333f, 0.3035857998967f);
    glVertex2f(-0.8414564448285f, 0.3120942531904f);
    glVertex2f(-0.8561528641539f, 0.3283376640237f);
    glVertex2f(-0.9056565924079f, 0.3909908200952f);
    glVertex2f(-0.9427843885984f, 0.3894438285873f);
    glVertex2f(-0.9319554480429f, 0.2881158848174f);
    glVertex2f(-0.7617837686202f, 0.2913507696872f);
    glVertex2f(-0.7934997080824f, 0.2958508423571f);
    glVertex2f(-0.8097431189158f, 0.2989448253729f);

    glEnd();

    //back door
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.751448548532f, 0.2700941542014f);
    glVertex2f(-0.7756353075463f, 0.2687250923704f);
    glVertex2f(-0.7742662457153f, 0.2285659453279f);
    glVertex2f(-0.7496231327574f, 0.2281095913843f);

    glEnd();

    //front door handle
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7678874563725f, 0.2510951983408f);
    glVertex2f(-0.7708790248524f, 0.2509192237244f);
    glVertex2f(-0.7707910375442f, 0.2473997313951f);
    glVertex2f(-0.7677114817561f, 0.2476636933198f);

    glEnd();

    //windows from left
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7151099662305f, 0.266868589599f);
    glVertex2f(-0.714460252525f, 0.2434788962022f);
    glVertex2f(-0.6962682687719f, 0.2434788962022f);
    glVertex2f(-0.6975676961829f, 0.266868589599f);

    glVertex2f(-0.6819745672516f, 0.26816801701f);
    glVertex2f(-0.6813248535462f, 0.2441286099077f);
    glVertex2f(-0.6637825834985f, 0.2444534667604f);
    glVertex2f(-0.6641074403513f, 0.2678431601572f);

    glVertex2f(-0.6501385956837f, 0.266868589599f);
    glVertex2f(-0.6491640251255f, 0.2447783236131f);
    glVertex2f(-0.6316217550779f, 0.2444534667604f);
    glVertex2f(-0.6329211824888f, 0.2671934464518f);

    glVertex2f(-0.6196020515268f, 0.2671934464518f);
    glVertex2f(-0.6183026241158f, 0.2451031804659f);
    glVertex2f(-0.6014100677737f, 0.2447783236131f);
    glVertex2f(-0.6030343520373f, 0.266868589599f);

    glVertex2f(-0.5858169388425f, 0.2662188758936f);
    glVertex2f(-0.585167225137f, 0.2457528941713f);
    glVertex2f(-0.5702238099112f, 0.2454280373186f);
    glVertex2f(-0.5711983804694f, 0.266868589599f);

    glVertex2f(-0.5533312535691f, 0.266868589599f);
    glVertex2f(-0.5520318261581f, 0.2454280373186f);
    glVertex2f(-0.5370884109324f, 0.2447783236131f);
    glVertex2f(-0.5393624089015f, 0.266868589599f);

    glVertex2f(-0.5227947094121f, 0.2665437327463f);
    glVertex2f(-0.5208455682957f, 0.2431540393495f);
    glVertex2f(-0.5039530119536f, 0.2434788962022f);
    glVertex2f(-0.5055772962172f, 0.266868589599f);

    glEnd();
    glPopMatrix();

}
 void windowhf()//building windows
 {


 glPushMatrix();
    glTranslatef(-0.08,0.46,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.08, 0.03);
    glVertex2f(-0.08, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08,0.43,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.08, 0.03);
    glVertex2f(-0.08, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08,0.40,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.08, 0.03);
    glVertex2f(-0.08, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.24,0.30,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.08, 0.03);
    glVertex2f(-0.08, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.26,0.28,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.265,0.255,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.055, 0.03);
    glVertex2f(-0.055, 0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.40,0.4,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.08, 0.03);
    glVertex2f(-0.08, 0.04);
    glEnd();
    glTranslatef(-0.02,-0.03,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.03,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.03,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.03,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0.16,0.15,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0.12,-0.0,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
     glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0.08,0.12,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(-0.16,0.09,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();
    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.51, 0.45);
    glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.06, 0.03);
    glVertex2f(-0.06, 0.04);
    glEnd();

    glTranslatef(0,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.04,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.04,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.04,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0.12,0.3,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
      glTranslatef(0.08,0.125,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
     glTranslatef(0.4,0.15,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
     glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.02, 0.04);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.1, 0.04);
    glEnd();
    glTranslatef(0.11,0.08,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
     glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.08,0.15,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.08,0.2,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.24,0.24,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.08,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0.27,0.12,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.05,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
     glTranslatef(0.57,-0.02,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();
    glTranslatef(0,-0.06,0);
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.76, 0.79);
   glVertex2f(-0.1, 0.04);
    glVertex2f(-0.1, 0.02);
    glVertex2f(-0.13, 0.02);
    glVertex2f(-0.13, 0.04);
    glEnd();







    glPopMatrix();



 }
void buildinghf()
{

    //glPushMatrix();
    //glTranslatef(-0.5,0,0);
    //glScalef(-0.5,1.5,0);
    //glColor3f(0.7, 0.71, 0.62);

    glBegin(GL_QUADS);
    glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-1,0);
    glVertex2f(-1,0.25);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.92,0.25);
    glVertex2f(-0.92,0);
    glColor3f(0, 0, 0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.92,0);
    glVertex2f(-0.92,0.44);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.84,0.44);
    glVertex2f(-0.84,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.84,0);
    glVertex2f(-0.84,0.32);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.76,0.32);
    glVertex2f(-0.76,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.76,0);
    glVertex2f(-0.76,0.30);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.68,0.30);
    glVertex2f(-0.68,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.68,0);
    glVertex2f(-0.68,0.27);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.60,0.27);
    glVertex2f(-0.60,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.60,0);
    glVertex2f(-0.60,0.39);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.52,0.39);
    glVertex2f(-0.52,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.52,0);
    glVertex2f(-0.52,0.30);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.44,0.30);
    glVertex2f(-0.44,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.44,0);
    glVertex2f(-0.44,0.42);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.36,0.42);
    glVertex2f(-0.36,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.36,0);
    glVertex2f(-0.36,0.26);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.28,0.26);
    glVertex2f(-0.28,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.28,0);
    glVertex2f(-0.28,0.33);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.20,0.33);
    glVertex2f(-0.20,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.20,0);
    glVertex2f(-0.20,0.40);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.12,0.40);
    glVertex2f(-0.12,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(-0.12,0);
    glVertex2f(-0.12,0.24);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(-0.04,0.24);
    glVertex2f(-0.04,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.26, 0.37, 0.38);
    glVertex2f(-0.04,0);
    glVertex2f(-0.04,0.36);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.04,0.36);
    glVertex2f(0.04,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(0.04,0);
    glVertex2f(0.04,0.51);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.12,0.51);
    glVertex2f(0.12,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.26, 0.37, 0.38);
    glVertex2f(0.12,0);
    glVertex2f(0.12,0.41);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.20,0.41);
    glVertex2f(0.20,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(0.20,0);
    glVertex2f(0.20,0.22);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.28,0.22);
    glVertex2f(0.28,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(0.28,0);
    glVertex2f(0.28,0.29);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.38,0.29);
    glVertex2f(0.38,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.71, 0.62);
    glVertex2f(0.38,0);
    glVertex2f(0.38,0.48);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.48,0.48);
    glVertex2f(0.48,0);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0.26, 0.37, 0.38);
    glVertex2f(0.48,0);
    glVertex2f(0.48,0.42);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.58,0.42);
    glVertex2f(0.58,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.7, 0.71, 0.62);
    glVertex2f(0.58,0);
    glVertex2f(0.58,0.52);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.72,0.52);
    glVertex2f(0.72,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(0.72,0);
    glVertex2f(0.72,0.43);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.85,0.43);
    glVertex2f(0.85,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.7, 0.71, 0.62);
    glVertex2f(0.85,0);
    glVertex2f(0.85,0.36);
    glColor3f(0.55, 0.68, 0.66);
    glVertex2f(0.95,0.36);
    glVertex2f(0.95,0);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.26, 0.37, 0.38);
    glVertex2f(0.95,0);
    glVertex2f(0.95,0.40);
    glColor3f(0.55, 0.68, 0.65);
    glVertex2f(1,0.40);
    glVertex2f(1,0);
    glEnd();
}
void building2hf()
{
    glPushMatrix();
    glTranslatef(-1,0,0);
    glScalef(-1,1.2,0);
    //glColor3f(0.79, 0.87, 0.87);

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-1,0);
    glVertex2f(-1,0.25);
    glColor3f(1, 1, 1);
    glVertex2f(-0.92,0.25);
    glVertex2f(-0.92,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.92,0);
    glVertex2f(-0.92,0.44);
    glColor3f(1, 1, 1);
    glVertex2f(-0.84,0.44);
    glVertex2f(-0.84,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.84,0);
    glVertex2f(-0.84,0.32);
    glColor3f(1, 1, 1);
    glVertex2f(-0.76,0.32);
    glVertex2f(-0.76,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.76,0);
    glVertex2f(-0.76,0.30);
    glColor3f(1, 1, 1);
    glVertex2f(-0.68,0.30);
    glVertex2f(-0.68,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.68,0);
    glVertex2f(-0.68,0.27);
    glColor3f(1, 1, 1);
    glVertex2f(-0.60,0.27);
    glVertex2f(-0.60,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.60,0);
    glVertex2f(-0.60,0.39);
    glColor3f(1, 1, 1);
    glVertex2f(-0.52,0.39);
    glVertex2f(-0.52,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.52,0);
    glVertex2f(-0.52,0.30);
    glColor3f(1, 1, 1);
    glVertex2f(-0.44,0.30);
    glVertex2f(-0.44,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.44,0);
    glVertex2f(-0.44,0.42);
    glColor3f(1, 1, 1);
    glVertex2f(-0.36,0.42);
    glVertex2f(-0.36,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.36,0);
    glVertex2f(-0.36,0.26);
    glColor3f(1, 1, 1);
    glVertex2f(-0.28,0.26);
    glVertex2f(-0.28,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(-0.28,0);
    glVertex2f(-0.28,0.33);
    glColor3f(0, 0, 0);
    glVertex2f(-0.20,0.33);
    glVertex2f(-0.20,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(-0.20,0);
    glVertex2f(-0.20,0.40);
    glColor3f(0, 0, 0);
    glVertex2f(-0.12,0.40);
    glVertex2f(-0.12,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(-0.12,0);
    glVertex2f(-0.12,0.24);
    glColor3f(0, 0, 0);
    glVertex2f(-0.04,0.24);
    glVertex2f(-0.04,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(-0.04,0);
    glVertex2f(-0.04,0.36);
    glColor3f(0, 0, 0);
    glVertex2f(0.04,0.36);
    glVertex2f(0.04,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.04,0);
    glVertex2f(0.04,0.51);
    glColor3f(0, 0, 0);
    glVertex2f(0.12,0.51);
    glVertex2f(0.12,0);
    glEnd();
    glBegin(GL_QUADS);
    //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.12,0);
    glVertex2f(0.12,0.41);
    glColor3f(0, 0, 0);
    glVertex2f(0.20,0.41);
    glVertex2f(0.20,0);
    glEnd();
    glBegin(GL_QUADS);
    //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.20,0);
    glVertex2f(0.20,0.22);
    glColor3f(0, 0, 0);
    glVertex2f(0.28,0.22);
    glVertex2f(0.28,0);
    glEnd();
    glBegin(GL_QUADS);
     //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.28,0);
    glVertex2f(0.28,0.29);
    glColor3f(0, 0, 0);
    glVertex2f(0.38,0.29);
    glVertex2f(0.38,0);
    glEnd();
    glBegin(GL_QUADS);
    //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.38,0);
    glVertex2f(0.38,0.48);
    glColor3f(0, 0, 0);
    glVertex2f(0.48,0.48);
    glVertex2f(0.48,0);
    glEnd();
    glBegin(GL_QUADS);
   //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.48,0);
    glVertex2f(0.48,0.42);
    glColor3f(0, 0, 0);
    glVertex2f(0.58,0.42);
    glVertex2f(0.58,0);
    glEnd();
    glBegin(GL_QUADS);
     //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.58,0);
    glVertex2f(0.58,0.52);
    glColor3f(0, 0, 0);
    glVertex2f(0.72,0.52);
    glVertex2f(0.72,0);
    glEnd();
    glBegin(GL_QUADS);
     //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.72,0);
    glVertex2f(0.72,0.43);
    glColor3f(0, 0, 0);
    glVertex2f(0.85,0.43);
    glVertex2f(0.85,0);
    glEnd();
    glBegin(GL_QUADS);
     //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.85,0);
    glVertex2f(0.85,0.36);
    glColor3f(0, 0, 0);
    glVertex2f(0.95,0.36);
    glVertex2f(0.95,0);
    glEnd();
    glBegin(GL_QUADS);
     //glColor3f(1, 0.77, 0.77);
    glVertex2f(0.95,0);
    glVertex2f(0.95,0.40);
    glColor3f(0, 0, 0);
    glVertex2f(1,0.40);
    glVertex2f(1,0);
    glEnd();
    glPopMatrix();
}
void display1()
 {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to gray and opaque
	glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)
    skyhf();
    building2hf();
    buildinghf();
    windowhf();
   // building2hf();
    roadhf();
    househf();
    pickuphf();
    pickup2hf();
    truckhf();

    clouds1hf(-2.34,0.3);
    clouds2hf(-0.8,0.5);
    clouds3hf(-1.6,0.17);
    planehf();

	glFlush();  // Render now
}
void handleMouse1(int button, int state, int x, int y)
 {
	if (button == GLUT_LEFT_BUTTON)
	{
		glutDisplayFunc(display0);
	}
	if (button == GLUT_RIGHT_BUTTON)
	{

		glutDisplayFunc(display_instructions);
	}
	glutPostRedisplay();
}



///// Saimas Part /////

void updateS (int value)//update truck+car+bird
{
    flag1 = true;

    if(truckPosi < -2.0)//lower road
        truckPosi = 1.8;
    truckPosi -= truckSp;


    if(truckPosi2 > 2.0)
        truckPosi2 = -1.8;
    truckPosi2 += truckSp2;

    if(car1Posi < -2.0)//lower road
        car1Posi = 1.8;
    car1Posi -= car1Sp;

    if(car2Posi > 2.0)//upper road
        car2Posi = -1.8;
    car2Posi += car2Sp;

    if(bird1Posi > 1.2)//bird left to right
        bird1Posi = -1.2;
    bird1Posi += bird1Sp;

     if(vanPosi > 2.0)//bird left to right
        vanPosi = -1.8;
    vanPosi += vanSp;


    if(bird2Posi < -1.2)//bird right to left
        bird2Posi = 1.2;
    bird2Posi -= bird2Sp;

    glutPostRedisplay();
    glutTimerFunc(60, updateS, 0); //1000 = 1 sec
}


void update1S(int value1) {
    //update cloud
    flag1 = true;

    if(cloud1Sposi >1)
        cloud1Sposi = -1.6;
    cloud1Sposi += cloud1Sp;

    if(cloud2Sposi >1)
        cloud2Sposi = -1.2;
    cloud2Sposi += cloud2Sp;

    if(cloud3Sposi >1)
        cloud3Sposi = -1.6;
    cloud3Sposi += cloud3Sp;

    if(cloud4Sposi >1.6)
        cloud4Sposi = -1.6;
    cloud4Sposi += cloud4Sp;

    if(cloud5Sposi >1.6)
        cloud5Sposi = -1.6;
    cloud5Sposi += cloud5Sp;

    glutPostRedisplay();
	glutTimerFunc(60, update1S, 0); //0.06
}

void skyS()
{
    // Sky
    glBegin(GL_QUADS);
    glColor3ub(158, 229, 251);
    glVertex2f(-1,1); glVertex2f(1,1); glVertex2f(1,0); glVertex2f(-1,0);

    //coloring
     glBegin(GL_QUADS);
    glColor3ub(4, 135, 226);
    glVertex2f(-1,1); glVertex2f(1,1);
    glColor3ub(255, 255, 255);
    glVertex2f(1,0.3); glVertex2f(-1,0.3);
}


void cloud1S()
{
     glPushMatrix();

     glTranslatef(cloud1Sposi,0, 0.0);

    int i;
    GLfloat x = 0.5, y = 0.78, radius = .03;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(183, 235, 243);//middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.46, y = 0.77, radius = .02;//L1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.44, y = 0.76, radius = .02;//L2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.54, y = 0.77, radius = .02;//R1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.56, y = 0.765, radius = .02;//R2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    //cloud with circle
    x = 0.575, y = 0.765, radius = .02;
    GLfloat twicePi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.595, y = 0.767, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.55, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.54, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.51, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.47, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.45, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.48, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    //small clouds
    x = 0.65, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

     x = 0.67, y = 0.765, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();

}

void cloud2S()
{
     glPushMatrix();

     glScalef(1.4,1.2,0);
     glTranslatef(cloud2Sposi,-0.28, 0.0);

    int i;
    GLfloat x = 0.5, y = 0.78, radius = .03;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(215, 249, 251);//middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.46, y = 0.77, radius = .02;//L1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.44, y = 0.76, radius = .02;//L2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.54, y = 0.77, radius = .02;//R1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.56, y = 0.765, radius = .02;//R2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    //cloud with circle
    x = 0.575, y = 0.765, radius = .02;
    GLfloat twicePi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.595, y = 0.767, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.55, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.54, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.51, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.47, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.45, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.48, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();

}

void cloud3S()
{
     glPushMatrix();

     glTranslatef(cloud3Sposi,0, 0.0);

    int i;
    GLfloat x = 0.5, y = 0.78, radius = .03;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(183, 235, 243);//middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.46, y = 0.77, radius = .02;//L1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.44, y = 0.76, radius = .02;//L2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.54, y = 0.77, radius = .02;//R1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.56, y = 0.765, radius = .02;//R2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    //cloud with circle
    x = 0.575, y = 0.765, radius = .02;
    GLfloat twicePi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.595, y = 0.767, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.55, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.54, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.51, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.47, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.45, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.48, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    //small clouds
    x = 0.65, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

     x = 0.67, y = 0.765, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();

}

void cloud4S()
{
     glPushMatrix();
     glScalef(1.04,1.7,0);
     glTranslatef(cloud4Sposi,-0.307, 0.0);

    int i;
    GLfloat x = 0.5, y = 0.78, radius = .03;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(215, 249, 251);//middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.46, y = 0.77, radius = .02;//L1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.44, y = 0.76, radius = .02;//L2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.54, y = 0.77, radius = .02;//R1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.56, y = 0.765, radius = .02;//R2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    //cloud with circle
    x = 0.575, y = 0.765, radius = .02;
    GLfloat twicePi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.595, y = 0.767, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.55, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.54, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.51, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.47, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.45, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.48, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();


    glPopMatrix();

}


void cloud5S()
{
     glPushMatrix();

     glTranslatef(cloud5Sposi,0, 0.0);

    int i;
    GLfloat x = 0.5, y = 0.78, radius = .03;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(183, 235, 243);//middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.46, y = 0.77, radius = .02;//L1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.44, y = 0.76, radius = .02;//L2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.54, y = 0.77, radius = .02;//R1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.56, y = 0.765, radius = .02;//R2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    //cloud with circle
    x = 0.575, y = 0.765, radius = .02;
    GLfloat twicePi = 2*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.595, y = 0.767, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.55, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.54, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.51, y = 0.765, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.47, y = 0.77, radius = .02;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.45, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.48, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    //small clouds
    x = 0.65, y = 0.77, radius = .015;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

     x = 0.67, y = 0.765, radius = .01;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();

}

void buildingS()//front buildings
{
    //building 1
    glBegin(GL_QUADS);//whole building
    glColor3ub(135, 158, 193);
    glVertex2f(-1,0.72); glVertex2f(-0.88,0.72); glVertex2f(-0.88,0); glVertex2f(-1,0);

    glBegin(GL_QUADS);
    glColor3ub(116, 138, 195);//right potion
    glVertex2f(-0.88,0.72); glVertex2f(-0.8,0.64); glVertex2f(-0.8,0); glVertex2f(-0.88,0);

    glBegin(GL_QUADS);
    glColor3ub(77, 104, 149);//right portion inside
    glVertex2f(-0.87,0.66); glVertex2f(-0.81,0.61); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(80, 108, 148);//right portion inside
    glVertex2f(-0.87,0.60); glVertex2f(-0.81,0.61); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(89, 117, 157);//right portion inside
    glVertex2f(-0.87,0.55); glVertex2f(-0.81,0.59); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(95, 123, 163);//right portion inside
    glVertex2f(-0.87,0.50); glVertex2f(-0.81,0.58); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(100, 129, 163);//right portion inside
    glVertex2f(-0.87,0.45); glVertex2f(-0.81,0.57); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(106, 134, 173);//right portion inside
    glVertex2f(-0.87,0.40); glVertex2f(-0.81,0.57); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(121, 146, 187);//right portion inside
    glVertex2f(-0.87,0.38); glVertex2f(-0.81,0.56); glVertex2f(-0.81,0); glVertex2f(-0.87,0);

    glBegin(GL_TRIANGLES);
    glColor3ub(119, 144, 185);//right portion inside
    glVertex2f(-0.87,0.32); glVertex2f(-0.81,0.55); glVertex2f(-0.87,0);

    glBegin(GL_QUADS);
    glColor3ub(73, 100, 146);//right portion inside
    glVertex2f(-0.87,0.18); glVertex2f(-0.81,0.37); glVertex2f(-0.81,0); glVertex2f(-0.87,0);
    glEnd();

    glLineWidth(7.0f);  // window
    glBegin(GL_LINES);
    glColor3ub(96, 121, 174);
    glVertex2f(-0.96,0.72); glVertex2f(-0.96,0);glVertex2f(-0.92,0.72); glVertex2f(-0.92,0);
    glVertex2f(-0.88,0.56); glVertex2f(-1,0.56);glVertex2f(-0.88,0.41); glVertex2f(-1,0.41);glVertex2f(-0.88,0.26); glVertex2f(-1,0.26);glVertex2f(-0.88,0.11); glVertex2f(-1,0.11);

    glEnd();

        //building 2
    glBegin(GL_QUADS);//whole building
    glColor3ub(213, 240, 251);
    glVertex2f(-0.7,0); glVertex2f(-0.7,0.4); glVertex2f(-0.3,0.4); glVertex2f(-0.3,0);

    glBegin(GL_QUADS);//inside portion
    glColor3ub(169, 223, 247);
    glVertex2f(-0.6,0); glVertex2f(-0.6,0.28); glVertex2f(-0.3,0.28); glVertex2f(-0.3,0);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.65,0.4); glVertex2f(-0.6,0.43); glVertex2f(-0.55,0.43); glVertex2f(-0.55,0.4);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.5,0.4); glVertex2f(-0.5,0.42); glVertex2f(-0.45,0.42); glVertex2f(-0.45,0.4);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.35,0.4); glVertex2f(-0.35,0.45); glVertex2f(-0.32,0.45); glVertex2f(-0.32,0.4);

    glEnd();

    glLineWidth(8.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);
    glVertex2f(-0.71,0.4); glVertex2f(-0.29,0.4);
    glEnd();

    //design
    glLineWidth(3.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);
    glVertex2f(-0.7,0.16); glVertex2f(-0.3,0.16);
    glEnd();

    glLineWidth(2.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);

    glVertex2f(-0.7,0.22); glVertex2f(-0.3,0.22);glVertex2f(-0.7,0.28); glVertex2f(-0.3,0.28);glVertex2f(-0.7,0.34); glVertex2f(-0.3,0.34);
    glVertex2f(-0.7,0.16); glVertex2f(-0.7,0.4);glVertex2f(-0.65,0.16); glVertex2f(-0.65,0.4);glVertex2f(-0.6,0.16); glVertex2f(-0.6,0.4);
    glVertex2f(-0.55,0.16); glVertex2f(-0.55,0.4);glVertex2f(-0.50,0.16); glVertex2f(-0.50,0.4);glVertex2f(-0.45,0.16); glVertex2f(-0.45,0.4);
    glVertex2f(-0.40,0.16); glVertex2f(-0.40,0.4);glVertex2f(-0.35,0.16); glVertex2f(-0.35,0.4);glVertex2f(-0.30,0.16); glVertex2f(-0.30,0.4);
    glVertex2f(-0.7,0.16); glVertex2f(-0.7,0);glVertex2f(-0.6,0.16); glVertex2f(-0.6,0);glVertex2f(-0.5,0.16); glVertex2f(-0.5,0);
    glVertex2f(-0.4,0.16); glVertex2f(-0.4,0);glVertex2f(-0.3,0.16); glVertex2f(-0.3,0);
    glEnd();


    //building 3
    glBegin(GL_QUADS);//whole building
    glColor3ub(78, 119, 198);
    glVertex2f(-0.12,0); glVertex2f(-0.12,0.64); glVertex2f(0.08,0.64); glVertex2f(0.08,0);

    glBegin(GL_QUADS);
    glColor3ub(220, 237, 255);//right potion
    glVertex2f(0.08,0.64); glVertex2f(0.08,0); glVertex2f(0.12,0); glVertex2f(0.12,0.64);

    glBegin(GL_QUADS);//little box
    glColor3ub(78, 119, 198);
    glVertex2f(0.09,0.55); glVertex2f(0.11,0.55); glVertex2f(0.11,0.46); glVertex2f(0.09,0.46);

    glBegin(GL_QUADS);//box on whole building
    glColor3ub(119, 153, 214);
    glVertex2f(0.07,0); glVertex2f(0.07,0.64); glVertex2f(0.04,0.64); glVertex2f(0.04,0);
     glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(115, 147, 204);
    glVertex2f(-0.12,0); glVertex2f(-0.08,0); glVertex2f(-0.12,0.4);
    glEnd();

    glLineWidth(5.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(158, 183, 234);
    glVertex2f(-0.12,0.63); glVertex2f(0.08,0.63);glVertex2f(-0.12,0.56); glVertex2f(0.08,0.56); glVertex2f(-0.12,0.49);glVertex2f(0.08,0.49);
    glVertex2f(-0.12,0.42); glVertex2f(0.08,0.42); glVertex2f(-0.12,0.35);glVertex2f(0.08,0.35);
    glVertex2f(-0.12,0.28); glVertex2f(0.08,0.28);glVertex2f(-0.12,0.21); glVertex2f(0.08,0.21); glVertex2f(-0.12,0.14);glVertex2f(0.08,0.14);
    glVertex2f(-0.12,0.07); glVertex2f(0.08,0.07); glVertex2f(-0.12,0);glVertex2f(0.08,0);
    glEnd();

    //building 4
    glBegin(GL_QUADS);//whole building
    glColor3ub(236, 250, 253);
    glVertex2f(0.12,0.40); glVertex2f(0.22,0.40); glVertex2f(0.22,0.0); glVertex2f(0.12,0);

    glBegin(GL_QUADS);//little box
    glColor3ub(78, 119, 198);
    glVertex2f(0.14,0.37); glVertex2f(0.19,0.37); glVertex2f(0.19,0.35); glVertex2f(0.14,0.35);
    glEnd();

    glLineWidth(6.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(79, 98, 148);
    glVertex2f(0.12,0.32); glVertex2f(0.22,0.32);glVertex2f(0.12,0.28); glVertex2f(0.22,0.28); glVertex2f(0.12,0.24);glVertex2f(0.22,0.24);
    glVertex2f(0.12,0.20); glVertex2f(0.22,0.20); glVertex2f(0.12,0.16);glVertex2f(0.22,0.16);
    glVertex2f(0.12,0.12); glVertex2f(0.22,0.12);glVertex2f(0.12,0.08); glVertex2f(0.22,0.08); glVertex2f(0.12,0.04);glVertex2f(0.22,0.04);
    glVertex2f(0.12,0); glVertex2f(0.22,0);
   glEnd();

   //building 5

    glBegin(GL_QUADS);//pick3
    glColor3ub(189, 218, 248);
    glVertex2f(0.76,0.5); glVertex2f(0.64,0.5);
    glColor3ub(163, 192, 236);
    glVertex2f(0.64,0); glVertex2f(0.76,0);

    glBegin(GL_QUADS);//pick2
    glColor3ub(189, 218, 248);
    glVertex2f(0.74,0.65); glVertex2f(0.66,0.65);
    glColor3ub(163, 192, 236);
    glVertex2f(0.66,0); glVertex2f(0.74,0);

    glBegin(GL_QUADS);//pick
    glColor3ub(189, 218, 248);
    glVertex2f(0.72,0.8); glVertex2f(0.68,0.8);
    glColor3ub(163, 192, 236);
    glVertex2f(0.68,0); glVertex2f(0.72,0);
    glEnd();

      // for window
    glLineWidth(8.0f);
    glBegin(GL_LINES);

    glColor3ub(118, 138, 191);
    //vertical line
    glVertex2f(0.72,0.8); glVertex2f(0.72,0.0);glVertex2f(0.70,0.8); glVertex2f(0.70,0.0); glVertex2f(0.68,0.8);glVertex2f(0.68,0);glVertex2f(0.74,0.65);
    glVertex2f(0.74,0);glVertex2f(0.66,0.65); glVertex2f(0.66,0); glVertex2f(0.76,0.5);glVertex2f(0.76,0);glVertex2f(0.64,0.5);glVertex2f(0.64,0);
    //horizontal line
    glVertex2f(0.725,0.8); glVertex2f(0.675,0.8); glVertex2f(0.725,0.75);glVertex2f(0.675,0.75);glVertex2f(0.725,0.7);glVertex2f(0.675,0.7);

    glVertex2f(0.745,0.65);glVertex2f(0.655,0.65);glVertex2f(0.745,0.60);glVertex2f(0.655,0.60);glVertex2f(0.745,0.55);glVertex2f(0.655,0.55);

    glVertex2f(0.765,0.5);glVertex2f(0.635,0.5);glVertex2f(0.765,0.45);glVertex2f(0.635,0.45);
    glVertex2f(0.765,0.40);glVertex2f(0.635,0.40);glVertex2f(0.765,0.35);glVertex2f(0.635,0.35);
    glVertex2f(0.765,0.30);glVertex2f(0.635,0.30);glVertex2f(0.765,0.25);glVertex2f(0.635,0.25);
    glVertex2f(0.765,0.20);glVertex2f(0.635,0.20);glVertex2f(0.765,0.15);glVertex2f(0.635,0.15);
    glVertex2f(0.765,0.10);glVertex2f(0.635,0.10);glVertex2f(0.765,0.05);glVertex2f(0.635,0.05);
    glVertex2f(0.765,0);glVertex2f(0.635,0);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(115, 115, 166);
    glVertex2f(0.71,0.81);glVertex2f(0.71,0.88);

    glEnd();
}

void buildingSS()
{

     glPushMatrix();
     glTranslatef(1.2,0, 0.0);
     glScalef(0.5,1.5,0);

    glBegin(GL_QUADS);//whole building
    glColor3ub(151, 189, 255);
    glVertex2f(-0.7,0); glVertex2f(-0.7,0.4);
    glColor3ub(175, 215, 237);
    glVertex2f(-0.3,0.4); glVertex2f(-0.3,0);

    glBegin(GL_QUADS);//inside portion
    glColor3ub(52, 102, 165);
    glVertex2f(-0.6,0); glVertex2f(-0.6,0.28);
     glColor3ub(100, 143, 188);
    glVertex2f(-0.3,0.28); glVertex2f(-0.3,0);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.65,0.4); glVertex2f(-0.6,0.43); glVertex2f(-0.55,0.43); glVertex2f(-0.55,0.4);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.5,0.4); glVertex2f(-0.5,0.42); glVertex2f(-0.45,0.42); glVertex2f(-0.45,0.4);

    glBegin(GL_QUADS);//above roof
    glColor3ub(113, 158, 173);
    glVertex2f(-0.35,0.4); glVertex2f(-0.35,0.45); glVertex2f(-0.32,0.45); glVertex2f(-0.32,0.4);

    glEnd();

    glLineWidth(8.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);
    glVertex2f(-0.71,0.4); glVertex2f(-0.29,0.4);
    glEnd();

    //design
    glLineWidth(3.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);
    glVertex2f(-0.7,0.16); glVertex2f(-0.3,0.16);
    glEnd();

    glLineWidth(2.0f);  // Set line width to 5 units
    glBegin(GL_LINES);
    glColor3ub(156, 187, 207);

    glVertex2f(-0.7,0.22); glVertex2f(-0.3,0.22);glVertex2f(-0.7,0.28); glVertex2f(-0.3,0.28);glVertex2f(-0.7,0.34); glVertex2f(-0.3,0.34);
    glVertex2f(-0.7,0.16); glVertex2f(-0.7,0.4);glVertex2f(-0.65,0.16); glVertex2f(-0.65,0.4);glVertex2f(-0.6,0.16); glVertex2f(-0.6,0.4);
    glVertex2f(-0.55,0.16); glVertex2f(-0.55,0.4);glVertex2f(-0.50,0.16); glVertex2f(-0.50,0.4);glVertex2f(-0.45,0.16); glVertex2f(-0.45,0.4);
    glVertex2f(-0.40,0.16); glVertex2f(-0.40,0.4);glVertex2f(-0.35,0.16); glVertex2f(-0.35,0.4);glVertex2f(-0.30,0.16); glVertex2f(-0.30,0.4);
    glVertex2f(-0.7,0.16); glVertex2f(-0.7,0);glVertex2f(-0.6,0.16); glVertex2f(-0.6,0);glVertex2f(-0.5,0.16); glVertex2f(-0.5,0);
    glVertex2f(-0.4,0.16); glVertex2f(-0.4,0);glVertex2f(-0.3,0.16); glVertex2f(-0.3,0);
    glEnd();
    glPopMatrix();

}

void road1S()
{
    //road upper
    glBegin(GL_QUADS);
    glColor3ub(70, 85, 108);
    glVertex2f(-1,-0.4);glVertex2f(1,-0.4);
    glColor3ub(134, 167, 186);
    glVertex2f(1,-0.10);glVertex2f(-1,-0.10);
    glEnd();

     //between upper roads and buildings
    glBegin(GL_QUADS);
    glColor3ub(115, 150, 26);//background green
    glVertex2f(-1,-0.10); glVertex2f(-1,0); glVertex2f(1,0); glVertex2f(1,-0.10);
    glBegin(GL_QUADS);// background black
    glColor3ub(1, 1, 1);
    glVertex2f(-1,-0.10);glVertex2f(-1,-0.07);glVertex2f(1,-0.07);glVertex2f(1,-0.1);
    glEnd();

    glLineWidth(20.0f);//white
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.98,-0.10); glVertex2f(-0.98,-0.07);glVertex2f(-0.93,-0.10); glVertex2f(-0.93,-0.07);glVertex2f(-0.88,-0.10); glVertex2f(-0.88,-0.07);
    glVertex2f(-0.83,-0.10); glVertex2f(-0.83,-0.07);glVertex2f(-0.78,-0.10); glVertex2f(-0.78,-0.07);glVertex2f(-0.73,-0.10); glVertex2f(-0.73,-0.07);
    glVertex2f(-0.68,-0.10); glVertex2f(-0.68,-0.07);glVertex2f(-0.63,-0.10); glVertex2f(-0.63,-0.07);glVertex2f(-0.58,-0.10); glVertex2f(-0.58,-0.07);
    glVertex2f(-0.53,-0.10); glVertex2f(-0.53,-0.07);glVertex2f(-0.48,-0.10); glVertex2f(-0.48,-0.07);glVertex2f(-0.43,-0.10); glVertex2f(-0.43,-0.07);
    glVertex2f(-0.38,-0.10); glVertex2f(-0.38,-0.07);glVertex2f(-0.33,-0.10); glVertex2f(-0.33,-0.07);glVertex2f(-0.28,-0.10); glVertex2f(-0.28,-0.07);
    glVertex2f(-0.23,-0.10); glVertex2f(-0.23,-0.07);glVertex2f(-0.18,-0.10); glVertex2f(-0.18,-0.07);glVertex2f(-0.13,-0.10); glVertex2f(-0.13,-0.07);
    glVertex2f(-0.08,-0.10); glVertex2f(-0.08,-0.07);glVertex2f(-0.03,-0.10); glVertex2f(-0.03,-0.07);glVertex2f(0.02,-0.10); glVertex2f(0.02,-0.07);
    glVertex2f(0.08,-0.10); glVertex2f(0.08,-0.07);glVertex2f(0.13,-0.10); glVertex2f(0.13,-0.07);glVertex2f(0.18,-0.10); glVertex2f(0.18,-0.07);
    glVertex2f(0.23,-0.10); glVertex2f(0.23,-0.07);glVertex2f(0.28,-0.10); glVertex2f(0.28,-0.07);glVertex2f(0.33,-0.10); glVertex2f(0.33,-0.07);
    glVertex2f(0.38,-0.10); glVertex2f(0.38,-0.07);glVertex2f(0.43,-0.10); glVertex2f(0.43,-0.07);glVertex2f(0.48,-0.10); glVertex2f(0.48,-0.07);
    glVertex2f(0.53,-0.10); glVertex2f(0.53,-0.07);glVertex2f(0.58,-0.10); glVertex2f(0.58,-0.07);glVertex2f(0.63,-0.10); glVertex2f(0.63,-0.07);
    glVertex2f(0.68,-0.10); glVertex2f(0.68,-0.07);glVertex2f(0.73,-0.10); glVertex2f(0.73,-0.07);glVertex2f(0.78,-0.10); glVertex2f(0.78,-0.07);
    glVertex2f(0.83,-0.10); glVertex2f(0.83,-0.07);glVertex2f(0.88,-0.10); glVertex2f(0.88,-0.07);glVertex2f(0.93,-0.10); glVertex2f(0.93,-0.07);
    glVertex2f(0.98,-0.10); glVertex2f(0.98,-0.07);
    glEnd();



    //yellow line
     glLineWidth(8.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 171, 88);
    glVertex2f(-1,-0.28); glVertex2f(1,-0.28);glVertex2f(-1,-0.22); glVertex2f(1,-0.22);
    glEnd();
}

void road2S()
{

    //road lower
    glBegin(GL_QUADS);
    glColor3ub(70, 85, 108);
    glVertex2f(-1,-1); glVertex2f(1,-1);
    glColor3ub(134, 167, 186);
    glVertex2f(1,-0.5);glVertex2f(-1,-0.5);
    glEnd();

    //yellow line
     glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 171, 88);
    glVertex2f(-1,-0.78); glVertex2f(1,-0.78);glVertex2f(-1,-0.7); glVertex2f(1,-0.7);
    glEnd();

        //between two roads
    glBegin(GL_QUADS);// background green
    glColor3ub(115, 150, 26);
    glVertex2f(-1,-0.4);glVertex2f(1,-0.4);glVertex2f(1,-0.45);glVertex2f(-1,-0.45);
    glBegin(GL_QUADS);// background black
    glColor3ub(1, 1, 1);
    glVertex2f(-1,-0.45);glVertex2f(1,-0.45);glVertex2f(1,-0.5);glVertex2f(-1,-0.5);
    glEnd();

    glLineWidth(30.0f);//white
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.98,-0.5); glVertex2f(-0.98,-0.45);glVertex2f(-0.9,-0.5); glVertex2f(-0.9,-0.45);glVertex2f(-0.82,-0.5); glVertex2f(-0.82,-0.45);
    glVertex2f(-0.74,-0.5); glVertex2f(-0.74,-0.45);glVertex2f(-0.66,-0.5); glVertex2f(-0.66,-0.45);glVertex2f(-0.58,-0.5); glVertex2f(-0.58,-0.45);
    glVertex2f(-0.50,-0.5); glVertex2f(-0.50,-0.45);glVertex2f(-0.42,-0.5); glVertex2f(-0.42,-0.45);glVertex2f(-0.34,-0.5); glVertex2f(-0.34,-0.45);
    glVertex2f(-0.26,-0.5); glVertex2f(-0.26,-0.45);glVertex2f(-0.18,-0.5); glVertex2f(-0.18,-0.45);glVertex2f(-0.10,-0.5); glVertex2f(-0.10,-0.45);
    glVertex2f(-0.02,-0.5); glVertex2f(-0.02,-0.45);glVertex2f(0.06,-0.5); glVertex2f(0.06,-0.45);glVertex2f(0.14,-0.5); glVertex2f(0.14,-0.45);
    glVertex2f(0.22,-0.5); glVertex2f(0.22,-0.45);glVertex2f(0.3,-0.5); glVertex2f(0.3,-0.45);glVertex2f(0.38,-0.5); glVertex2f(0.38,-0.45);
    glVertex2f(0.46,-0.5); glVertex2f(0.46,-0.45);glVertex2f(0.54,-0.5); glVertex2f(0.54,-0.45);glVertex2f(0.62,-0.5); glVertex2f(0.62,-0.45);
    glVertex2f(0.70,-0.5); glVertex2f(0.70,-0.45);glVertex2f(0.78,-0.5); glVertex2f(0.78,-0.45);glVertex2f(0.86,-0.5); glVertex2f(0.86,-0.45);
    glVertex2f(0.94,-0.5); glVertex2f(0.94,-0.45);glVertex2f(1.02,-0.5); glVertex2f(1.02,-0.45);
    glEnd();




}

void leafS()
{
    int i;
    GLfloat x = 0, y = -0.45, radius = .1;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(107, 94, 6);//big_dark_green4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.4, y = -0.45, radius = .1;
    glColor3ub(106, 97, 8);//big_dark_green2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.35, y = -0.45, radius = .05;//10
    triangleAmount = 100;
    glColor3ub(180, 173, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.20, y = -0.45, radius = .06;//
    triangleAmount = 100;
    glColor3ub(180, 173, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.28, y = -0.45, radius = .09;
    glColor3ub(106, 91, 8);//big_dark_green3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.5, y = -0.45, radius = .09;
    glColor3ub(107, 94, 6);//big_dark_green5
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.55, y = -0.45, radius = .04;//1 copy
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.4, y = -0.45, radius = .12;
    glColor3ub(74, 98, 20);//big_dark_green6
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.7, y = -0.45, radius = .1;//
    triangleAmount = 100;
    glColor3ub(110, 98, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.8, y = -0.45, radius = .1;
    glColor3ub(137, 109, 8);//big_dark_green7
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.87, y = -0.45, radius = .13;//2(behind 1 & 3) big_dark_green1
    triangleAmount = 100;
    glColor3ub(106, 91, 8);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.97, y = -0.45, radius = .1;//1
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.8, y = -0.45, radius = .06;//3
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.72, y = -0.45, radius = .04;//5
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.70, y = -0.45, radius = .04;//6
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.65, y = -0.45, radius = .07;//7
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.55, y = -0.45, radius = .05;//8
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.45, y = -0.45, radius = .05;//9
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.28, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.22, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.19, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

      x = -0.15, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.08, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.05, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.0, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.1, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.05, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.04, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.09, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.13, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.23, y = -0.45, radius = .1;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.3, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.4, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.45, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.49, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.28, y = -0.45, radius = .045;//green 2 leafs inside of copy1
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.6, y = -0.45, radius = .03;// after 1 copy
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.32, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.63, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.7, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.8, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.9, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.95, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 1, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.50, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

      x = -0.75, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.83, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();
}

void LEAFS()
{
    glPushMatrix();
    glTranslatef(0,0.742, 0.0);
    glScalef(1,1.8,0);


     int i;
    GLfloat x = 0, y = -0.45, radius = .1;
    int triangleAmount = 100;
    GLfloat Pi = PI;

    glColor3ub(107, 94, 6);//big_dark_green4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.4, y = -0.45, radius = .1;
    glColor3ub(106, 97, 8);//big_dark_green2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.35, y = -0.45, radius = .05;//10
    triangleAmount = 100;
    glColor3ub(180, 173, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.20, y = -0.45, radius = .06;//
    triangleAmount = 100;
    glColor3ub(180, 173, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.28, y = -0.45, radius = .09;
    glColor3ub(106, 91, 8);//big_dark_green3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.5, y = -0.45, radius = .09;
    glColor3ub(107, 94, 6);//big_dark_green5
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.55, y = -0.45, radius = .04;//1 copy
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.4, y = -0.45, radius = .12;
    glColor3ub(74, 98, 20);//big_dark_green6
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.7, y = -0.45, radius = .1;//
    triangleAmount = 100;
    glColor3ub(110, 98, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.8, y = -0.45, radius = .1;
    glColor3ub(137, 109, 8);//big_dark_green7
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.87, y = -0.45, radius = .13;//2(behind 1 & 3) big_dark_green1
    triangleAmount = 100;
    glColor3ub(106, 91, 8);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.97, y = -0.45, radius = .1;//1
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.8, y = -0.45, radius = .06;//3
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.72, y = -0.45, radius = .04;//5
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.70, y = -0.45, radius = .04;//6
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.65, y = -0.45, radius = .07;//7
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.55, y = -0.45, radius = .05;//8
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.45, y = -0.45, radius = .05;//9
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.28, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.22, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.19, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

      x = -0.15, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.08, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = -0.05, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.0, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.1, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.05, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.04, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.09, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.13, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.23, y = -0.45, radius = .1;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.3, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.4, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.45, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.49, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.28, y = -0.45, radius = .045;//green 2 leafs inside of copy1
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.6, y = -0.45, radius = .03;// after 1 copy
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.32, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(120, 118, 23);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = 0.63, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.7, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.8, y = -0.45, radius = .03;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.9, y = -0.45, radius = .02;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 0.95, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

    x = 1, y = -0.45, radius = .07;//
    triangleAmount = 100;
    glColor3ub(170, 156, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.50, y = -0.45, radius = .05;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

      x = -0.75, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(170, 160, 20);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();

     x = -0.83, y = -0.45, radius = .04;//
    triangleAmount = 100;
    glColor3ub(136, 131, 4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    glVertex2f(x + radius * cos(i * Pi / triangleAmount), y + radius * sin(i * Pi / triangleAmount));
    glEnd();


     glPopMatrix();

}

void lightS()
{
     glPushMatrix();
    glTranslatef(0.01,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void light1S()
{
     glPushMatrix();
    glTranslatef(0.4,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void light2S()
{
     glPushMatrix();
    glTranslatef(0.79,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void light3S()
{
     glPushMatrix();
    glTranslatef(1.18,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void light4S()
{
     glPushMatrix();
    glTranslatef(1.57,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void light5S()
{
     glPushMatrix();
    glTranslatef(1.95,0,0);

    //back light
    glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.95,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.99,0.61); glVertex2f(-1.03,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.95,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.995,0.60); glVertex2f(-1.025,0.60);
    glEnd();


    glLineWidth(10.0f);//lower portion
    glBegin(GL_LINES);
    glColor3ub(55, 55, 55);
    glVertex2f(-0.9,-0.45); glVertex2f(-0.9,-0.2);
    glEnd();

    glLineWidth(8.0f);//upper portion
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(-0.9,-0.2); glVertex2f(-0.9,0.6);
    glEnd();

    //front light
     glLineWidth(3.0f);//handle where the light will be attched
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.85,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(5.0f);//bold
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.81,0.61); glVertex2f(-0.77,0.61);
    glEnd();

    glLineWidth(4.0f);//curve line
    glBegin(GL_LINES);
    glColor3ub(70, 70, 70);
    glVertex2f(-0.9,0.58); glVertex2f(-0.85,0.61);
    glEnd();

     glLineWidth(4.0f);//light
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.805,0.60); glVertex2f(-0.775,0.60);
    glEnd();

     glPopMatrix();

}

void birdS()
{
     glPushMatrix();
     glTranslatef(bird1Posi,0.35, 0.0);
     glScalef(0.3,1,0);
     glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);//back wings
    glVertex2f(-0.005,0.3);
    glVertex2f(0.02,0.35);
    glVertex2f(0,0.41);
    glVertex2f(-0.002,0.35);
    glVertex2f(-0.008,0.3);
    glEnd();

    glBegin(GL_POLYGON);//front wings
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(-0.01,0.35);
    glVertex2f(-0.08,0.42);
    glVertex2f(-0.05,0.35);
    glVertex2f(-0.01,0.3);
    glEnd();

     glBegin(GL_POLYGON);//front wings
    glColor3ub(0, 0, 0);
    glVertex2f(0.02,0.32);
    glVertex2f(-0.05,0.30);
    glVertex2f(-0.06,0.28);
    glEnd();

     glBegin(GL_POLYGON);//extra portion
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(0.01,0.33);
    glVertex2f(-0.05,0.3);
    glEnd();

     glBegin(GL_POLYGON);//extra portion for head
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(0.03,0.33);
    glVertex2f(-0.05,0.3);
    glEnd();

    glBegin(GL_POLYGON);//extra portion
    glColor3ub(0, 0, 0);
    glVertex2f(0.03,0.33);
    glVertex2f(0.03,0.298);
    glVertex2f(0.02,0.33);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0,0);
    glVertex2f(0,0.329); glVertex2f(0.03,0.329);
    glEnd();

     glPopMatrix();
}

void bird1S()
{
     glPushMatrix();
     glTranslatef(bird2Posi,0.5, 0.0);
     glScalef(-0.3,1,0);
     glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);//back wings
    glVertex2f(-0.005,0.3);
    glVertex2f(0.02,0.35);
    glVertex2f(0,0.41);
    glVertex2f(-0.002,0.35);
    glVertex2f(-0.008,0.3);
    glEnd();

    glBegin(GL_POLYGON);//front wings
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(-0.01,0.35);
    glVertex2f(-0.08,0.42);
    glVertex2f(-0.05,0.35);
    glVertex2f(-0.01,0.3);
    glEnd();

     glBegin(GL_POLYGON);//front wings
    glColor3ub(0, 0, 0);
    glVertex2f(0.02,0.32);
    glVertex2f(-0.05,0.30);
    glVertex2f(-0.06,0.28);
    glEnd();

     glBegin(GL_POLYGON);//extra portion
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(0.01,0.33);
    glVertex2f(-0.05,0.3);
    glEnd();

     glBegin(GL_POLYGON);//extra portion for head
    glColor3ub(0, 0, 0);
    glVertex2f(0.0,0.3);
    glVertex2f(0.03,0.33);
    glVertex2f(-0.05,0.3);
    glEnd();

    glBegin(GL_POLYGON);//extra portion
    glColor3ub(0, 0, 0);
    glVertex2f(0.03,0.33);
    glVertex2f(0.03,0.298);
    glVertex2f(0.02,0.33);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0,0);
    glVertex2f(0,0.329); glVertex2f(0.03,0.329);
    glEnd();

     glPopMatrix();
}


void building1S(){
     glPushMatrix();
     glScalef(-0.4,1.5,0);
     //25 Buildings
     glColor3ub(115, 210, 240);

   glBegin(GL_QUADS);
   glVertex2f(-1.00f, -0.28f);
   glVertex2f(-1.00f, 0.25f);
   glVertex2f(-0.92f, 0.25f);
   glVertex2f(-0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.92f, -0.28f);
   glVertex2f(-0.92f, 0.34f);
   glVertex2f(-0.84f, 0.34f);
   glVertex2f(-0.84f, -0.28f);
    glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.84f, -0.28f);
   glVertex2f(-0.84f, 0.22f);
   glVertex2f(-0.76f, 0.22f);
   glVertex2f(-0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.76f, -0.28f);
   glVertex2f(-0.76f, 0.30f);
   glVertex2f(-0.68f, 0.30f);
   glVertex2f(-0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.68f, -0.28f);
   glVertex2f(-0.68f, 0.27f);
   glVertex2f(-0.60f, 0.27f);
   glVertex2f(-0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.60f, -0.28f);
   glVertex2f(-0.60f, 0.39f);
   glVertex2f(-0.52f, 0.39f);
   glVertex2f(-0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.52f, -0.28f);
   glVertex2f(-0.52f, 0.30f);
   glVertex2f(-0.44f, 0.30f);
   glVertex2f(-0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.44f, -0.28f);
   glVertex2f(-0.44f, 0.42f);
   glVertex2f(-0.36f, 0.42f);
   glVertex2f(-0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.36f, -0.28f);
   glVertex2f(-0.36f, 0.26f);
   glVertex2f(-0.28f, 0.26f);
   glVertex2f(-0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.28f, -0.28f);
   glVertex2f(-0.28f, 0.33f);
   glVertex2f(-0.20f, 0.33f);
   glVertex2f(-0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.20f, -0.28f);
   glVertex2f(-0.20f, 0.40f);
   glVertex2f(-0.12f, 0.40f);
   glVertex2f(-0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.12f, -0.28f);
   glVertex2f(-0.12f, 0.24f);
   glVertex2f(-0.04f, 0.24f);
   glVertex2f(-0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.04f, -0.28f);
   glVertex2f(-0.04f, 0.36f);
   glVertex2f(0.04f, 0.36f);
   glVertex2f(0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.04f, -0.28f);
   glVertex2f(0.04f, 0.31f);
   glVertex2f(0.12f, 0.31f);
   glVertex2f(0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.12f, -0.28f);
   glVertex2f(0.12f, 0.41f);
   glVertex2f(0.20f, 0.41f);
   glVertex2f(0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.20f, -0.28f);
   glVertex2f(0.20f, 0.22f);
   glVertex2f(0.28f, 0.22f);
   glVertex2f(0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.28f, -0.28f);
   glVertex2f(0.28f, 0.29f);
   glVertex2f(0.36f, 0.29f);
   glVertex2f(0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.36f, -0.28f);
   glVertex2f(0.36f, 0.38f);
   glVertex2f(0.44f, 0.38f);
   glVertex2f(0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.44f, -0.28f);
   glVertex2f(0.44f, 0.35f);
   glVertex2f(0.52f, 0.35f);
   glVertex2f(0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.52f, -0.28f);
   glVertex2f(0.52f, 0.22f);
   glVertex2f(0.60f, 0.22f);
   glVertex2f(0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);//
   glVertex2f(0.60f, -0.28f);
   glVertex2f(0.60f, 0.30f);
   glVertex2f(0.68f, 0.30f);
   glVertex2f(0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.68f, -0.28f);
   glVertex2f(0.68f, 0.36f);
   glVertex2f(0.76f, 0.36f);
   glVertex2f(0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.76f, -0.28f);
   glVertex2f(0.76f, 0.40f);
   glVertex2f(0.84f, 0.40f);
   glVertex2f(0.84f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.84f, -0.28f);
   glVertex2f(0.84f, 0.33f);
   glVertex2f(0.92f, 0.33f);
   glVertex2f(0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.92f, -0.28f);
   glVertex2f(0.92f, 0.39f);
   glVertex2f(1.00f, 0.39f);
   glVertex2f(1.00f, -0.28f);
     glEnd();
glPopMatrix();
}



void building2S(){
     glPushMatrix();
     glTranslatef(-0.8,0, 0.0);
     glScalef(-0.4,1.5,0);

     //25 Buildings
     glColor3ub(115, 210, 240);

   glBegin(GL_QUADS);
   glVertex2f(-1.00f, -0.28f);
   glVertex2f(-1.00f, 0.25f);
   glVertex2f(-0.92f, 0.25f);
   glVertex2f(-0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.92f, -0.28f);
   glVertex2f(-0.92f, 0.34f);
   glVertex2f(-0.84f, 0.34f);
   glVertex2f(-0.84f, -0.28f);
    glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.84f, -0.28f);
   glVertex2f(-0.84f, 0.22f);
   glVertex2f(-0.76f, 0.22f);
   glVertex2f(-0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.76f, -0.28f);
   glVertex2f(-0.76f, 0.30f);
   glVertex2f(-0.68f, 0.30f);
   glVertex2f(-0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.68f, -0.28f);
   glVertex2f(-0.68f, 0.27f);
   glVertex2f(-0.60f, 0.27f);
   glVertex2f(-0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.60f, -0.28f);
   glVertex2f(-0.60f, 0.39f);
   glVertex2f(-0.52f, 0.39f);
   glVertex2f(-0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.52f, -0.28f);
   glVertex2f(-0.52f, 0.30f);
   glVertex2f(-0.44f, 0.30f);
   glVertex2f(-0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.44f, -0.28f);
   glVertex2f(-0.44f, 0.42f);
   glVertex2f(-0.36f, 0.42f);
   glVertex2f(-0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.36f, -0.28f);
   glVertex2f(-0.36f, 0.26f);
   glVertex2f(-0.28f, 0.26f);
   glVertex2f(-0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.28f, -0.28f);
   glVertex2f(-0.28f, 0.33f);
   glVertex2f(-0.20f, 0.33f);
   glVertex2f(-0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.20f, -0.28f);
   glVertex2f(-0.20f, 0.40f);
   glVertex2f(-0.12f, 0.40f);
   glVertex2f(-0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.12f, -0.28f);
   glVertex2f(-0.12f, 0.24f);
   glVertex2f(-0.04f, 0.24f);
   glVertex2f(-0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.04f, -0.28f);
   glVertex2f(-0.04f, 0.36f);
   glVertex2f(0.04f, 0.36f);
   glVertex2f(0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.04f, -0.28f);
   glVertex2f(0.04f, 0.31f);
   glVertex2f(0.12f, 0.31f);
   glVertex2f(0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.12f, -0.28f);
   glVertex2f(0.12f, 0.41f);
   glVertex2f(0.20f, 0.41f);
   glVertex2f(0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.20f, -0.28f);
   glVertex2f(0.20f, 0.22f);
   glVertex2f(0.28f, 0.22f);
   glVertex2f(0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.28f, -0.28f);
   glVertex2f(0.28f, 0.29f);
   glVertex2f(0.36f, 0.29f);
   glVertex2f(0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.36f, -0.28f);
   glVertex2f(0.36f, 0.38f);
   glVertex2f(0.44f, 0.38f);
   glVertex2f(0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.44f, -0.28f);
   glVertex2f(0.44f, 0.35f);
   glVertex2f(0.52f, 0.35f);
   glVertex2f(0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.52f, -0.28f);
   glVertex2f(0.52f, 0.22f);
   glVertex2f(0.60f, 0.22f);
   glVertex2f(0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);//
   glVertex2f(0.60f, -0.28f);
   glVertex2f(0.60f, 0.30f);
   glVertex2f(0.68f, 0.30f);
   glVertex2f(0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.68f, -0.28f);
   glVertex2f(0.68f, 0.36f);
   glVertex2f(0.76f, 0.36f);
   glVertex2f(0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.76f, -0.28f);
   glVertex2f(0.76f, 0.40f);
   glVertex2f(0.84f, 0.40f);
   glVertex2f(0.84f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.84f, -0.28f);
   glVertex2f(0.84f, 0.33f);
   glVertex2f(0.92f, 0.33f);
   glVertex2f(0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.92f, -0.28f);
   glVertex2f(0.92f, 0.39f);
   glVertex2f(1.00f, 0.39f);
   glVertex2f(1.00f, -0.28f);
     glEnd();
glPopMatrix();
}


void building3S(){
     glPushMatrix();
     glTranslatef(0.8,0, 0.0);
     glScalef(-0.4,1.5,0);

     //25 Buildings
     glColor3ub(115, 210, 240);

   glBegin(GL_QUADS);
   glVertex2f(-1.00f, -0.28f);
   glVertex2f(-1.00f, 0.25f);
   glVertex2f(-0.92f, 0.25f);
   glVertex2f(-0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.92f, -0.28f);
   glVertex2f(-0.92f, 0.34f);
   glVertex2f(-0.84f, 0.34f);
   glVertex2f(-0.84f, -0.28f);
    glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.84f, -0.28f);
   glVertex2f(-0.84f, 0.22f);
   glVertex2f(-0.76f, 0.22f);
   glVertex2f(-0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.76f, -0.28f);
   glVertex2f(-0.76f, 0.30f);
   glVertex2f(-0.68f, 0.30f);
   glVertex2f(-0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.68f, -0.28f);
   glVertex2f(-0.68f, 0.27f);
   glVertex2f(-0.60f, 0.27f);
   glVertex2f(-0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.60f, -0.28f);
   glVertex2f(-0.60f, 0.39f);
   glVertex2f(-0.52f, 0.39f);
   glVertex2f(-0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.52f, -0.28f);
   glVertex2f(-0.52f, 0.30f);
   glVertex2f(-0.44f, 0.30f);
   glVertex2f(-0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.44f, -0.28f);
   glVertex2f(-0.44f, 0.42f);
   glVertex2f(-0.36f, 0.42f);
   glVertex2f(-0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.36f, -0.28f);
   glVertex2f(-0.36f, 0.26f);
   glVertex2f(-0.28f, 0.26f);
   glVertex2f(-0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.28f, -0.28f);
   glVertex2f(-0.28f, 0.33f);
   glVertex2f(-0.20f, 0.33f);
   glVertex2f(-0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.20f, -0.28f);
   glVertex2f(-0.20f, 0.40f);
   glVertex2f(-0.12f, 0.40f);
   glVertex2f(-0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.12f, -0.28f);
   glVertex2f(-0.12f, 0.24f);
   glVertex2f(-0.04f, 0.24f);
   glVertex2f(-0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(-0.04f, -0.28f);
   glVertex2f(-0.04f, 0.36f);
   glVertex2f(0.04f, 0.36f);
   glVertex2f(0.04f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.04f, -0.28f);
   glVertex2f(0.04f, 0.31f);
   glVertex2f(0.12f, 0.31f);
   glVertex2f(0.12f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.12f, -0.28f);
   glVertex2f(0.12f, 0.41f);
   glVertex2f(0.20f, 0.41f);
   glVertex2f(0.20f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.20f, -0.28f);
   glVertex2f(0.20f, 0.22f);
   glVertex2f(0.28f, 0.22f);
   glVertex2f(0.28f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.28f, -0.28f);
   glVertex2f(0.28f, 0.29f);
   glVertex2f(0.36f, 0.29f);
   glVertex2f(0.36f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.36f, -0.28f);
   glVertex2f(0.36f, 0.38f);
   glVertex2f(0.44f, 0.38f);
   glVertex2f(0.44f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.44f, -0.28f);
   glVertex2f(0.44f, 0.35f);
   glVertex2f(0.52f, 0.35f);
   glVertex2f(0.52f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.52f, -0.28f);
   glVertex2f(0.52f, 0.22f);
   glVertex2f(0.60f, 0.22f);
   glVertex2f(0.60f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);//
   glVertex2f(0.60f, -0.28f);
   glVertex2f(0.60f, 0.30f);
   glVertex2f(0.68f, 0.30f);
   glVertex2f(0.68f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.68f, -0.28f);
   glVertex2f(0.68f, 0.36f);
   glVertex2f(0.76f, 0.36f);
   glVertex2f(0.76f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.76f, -0.28f);
   glVertex2f(0.76f, 0.40f);
   glVertex2f(0.84f, 0.40f);
   glVertex2f(0.84f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.84f, -0.28f);
   glVertex2f(0.84f, 0.33f);
   glVertex2f(0.92f, 0.33f);
   glVertex2f(0.92f, -0.28f);
     glEnd();
   glBegin(GL_QUADS);
   glVertex2f(0.92f, -0.28f);
   glVertex2f(0.92f, 0.39f);
   glVertex2f(1.00f, 0.39f);
   glVertex2f(1.00f, -0.28f);
     glEnd();
glPopMatrix();
}

void car1S()
{
 glPushMatrix();
 glTranslatef(car1Posi,-0.16, 0.0);
 glScalef(0.6,1.0,0);

   glColor3ub(254, 86, 86);
   glBegin(GL_QUADS);
   glVertex2f(-0.18, -0.38);
   glVertex2f(-0.18, -0.45);
   glVertex2f(0.40, -0.45);
   glVertex2f(0.40, -0.38);
   glEnd();

//car front portion
   glBegin(GL_POLYGON);
   glVertex2f(-0.18, -0.38);
   glVertex2f(-0.07, -0.38);
   glVertex2f(-0.07, -0.35);
    glEnd();

   glBegin(GL_POLYGON);
   glVertex2f(-0.07, -0.35);
   glVertex2f(-0.03, -0.35);
   glVertex2f(-0.03, -0.38);
   glVertex2f(-0.07, -0.38);
    glEnd();

   glBegin(GL_POLYGON);//middle portion
   glVertex2f(-0.03, -0.38);
   glVertex2f(-0.03, -0.35);
   glVertex2f(0.40, -0.35);
   glVertex2f(0.40, -0.38);
    glEnd();

   glBegin(GL_POLYGON);//upper portion
   glVertex2f(0.28, -0.28);
   glVertex2f(0.37, -0.35);
   glVertex2f(-0.03, -0.35);
   glVertex2f(0.1, -0.28);
   glEnd();

   //glass
   glBegin(GL_POLYGON);
   glColor3ub(55, 53, 64);
   glVertex2f(0.27, -0.29);
   glVertex2f(0.35, -0.35);
   glColor3ub(150, 141, 136);
   glVertex2f(0.0, -0.35);
   glVertex2f(0.11, -0.29);
   glEnd();

   //line for separating glass
    glLineWidth(6.0f);//as same as car color
    glBegin(GL_LINES);
    glColor3ub(254, 86, 86);
    glVertex2f(0.18,-0.29); glVertex2f(0.18,-0.38);
    glEnd();

    //line for handle
    glLineWidth(6.0f);//
    glBegin(GL_LINES);
    glColor3ub(80, 80, 80);
    glVertex2f(0.15,-0.37); glVertex2f(0.17,-0.37);
    glEnd();

    glLineWidth(8.0f);//gray line
    glBegin(GL_LINES);
    glColor3ub(80, 80, 80);
    glVertex2f(-0.152,-0.445); glVertex2f(0.324,-0.445);
    glEnd();

   //tire drawing
    int iS1;
    GLfloat xS1;
	GLfloat yS1;
	GLfloat radiS1;
	int triangleAmountS1 = 100; //# of lines used to draw circle

    GLfloat twicePiS1 = 2.0f * PI;
	GLfloat PiS1 =  PI;

	 xS1 = -0.1, yS1 = -0.44, radiS1 = .053;//tire 1 upper portion
    glColor3ub(80, 80, 80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * PiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * PiS1 / triangleAmountS1));
         glEnd();

     xS1 = 0.27, yS1 = -0.44, radiS1 = .053;//tire 2 upper portion
    glColor3ub(80, 80, 80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * PiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * PiS1 / triangleAmountS1));
         glEnd();

    xS1=-0.1;yS1= -0.44;radiS1 =0.044;
    glColor3ub(40, 40, 40);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire1
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

    xS1 = -0.1, yS1 = -0.44, radiS1 = .025;//inside tire1
    glColor3ub(55, 55, 55);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

    xS1 = 0.27, yS1 = -0.44, radiS1 = .044;// tire2
    glColor3ub(40, 40, 40);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire1
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

    xS1 = 0.27, yS1 = -0.44, radiS1 = .025;//inside tire2
    glColor3ub(55, 55, 55);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

   glPopMatrix();
}

void car2S()
{
  glPushMatrix();
  glTranslatef(car2Posi,0.01, 0.0);
  glScalef(-0.5,0.9,0);

   glColor3ub(64, 95, 168);
   glBegin(GL_QUADS);
   glVertex2f(-0.18, -0.38);
   glVertex2f(-0.18, -0.45);
   glVertex2f(0.40, -0.45);
   glVertex2f(0.40, -0.38);
   glEnd();

//car front portion
   glBegin(GL_POLYGON);
   glVertex2f(-0.18, -0.38);
   glVertex2f(-0.07, -0.38);
   glVertex2f(-0.07, -0.35);
    glEnd();

   glBegin(GL_POLYGON);
   glVertex2f(-0.07, -0.35);
   glVertex2f(-0.03, -0.35);
   glVertex2f(-0.03, -0.38);
   glVertex2f(-0.07, -0.38);
    glEnd();

   glBegin(GL_POLYGON);//middle portion
   glVertex2f(-0.03, -0.38);
   glVertex2f(-0.03, -0.35);
   glVertex2f(0.40, -0.35);
   glVertex2f(0.40, -0.38);
    glEnd();

   glBegin(GL_POLYGON);//upper portion
   glVertex2f(0.28, -0.28);
   glVertex2f(0.37, -0.35);
   glVertex2f(-0.03, -0.35);
   glVertex2f(0.1, -0.28);
   glEnd();

   //glass
   glBegin(GL_POLYGON);
   glColor3ub(55, 53, 64);
   glVertex2f(0.27, -0.29);
   glVertex2f(0.35, -0.35);
   glColor3ub(150, 141, 136);
   glVertex2f(0.0, -0.35);
   glVertex2f(0.11, -0.29);
   glEnd();

   //line for separating glass
    glLineWidth(6.0f);//as same as car color
    glBegin(GL_LINES);
    glColor3ub(64, 95, 168);
    glVertex2f(0.18,-0.29); glVertex2f(0.18,-0.38);
    glEnd();

    //line for handle
    glLineWidth(6.0f);//
    glBegin(GL_LINES);
    glColor3ub(80, 80, 80);
    glVertex2f(0.15,-0.37); glVertex2f(0.17,-0.37);
    glEnd();

    glLineWidth(8.0f);//gray line
    glBegin(GL_LINES);
    glColor3ub(80, 80, 80);
    glVertex2f(-0.152,-0.445); glVertex2f(0.324,-0.445);
    glEnd();

   //tire drawing
    int iS1;
    GLfloat xS1;
	GLfloat yS1;
	GLfloat radiS1;
	int triangleAmountS1 = 100; //# of lines used to draw circle

    GLfloat twicePiS1 = 2.0f * PI;
	GLfloat PiS1 =  PI;

	 xS1 = -0.1, yS1 = -0.44, radiS1 = .053;//tire 1 upper portion
    glColor3ub(80, 80, 80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * PiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * PiS1 / triangleAmountS1));
         glEnd();

     xS1 = 0.27, yS1 = -0.44, radiS1 = .053;//tire 2 upper portion
    glColor3ub(80, 80, 80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * PiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * PiS1 / triangleAmountS1));
         glEnd();

    xS1=-0.1;yS1= -0.44;radiS1 =0.044;
    glColor3ub(40, 40, 40);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire1
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

    xS1 = -0.1, yS1 = -0.44, radiS1 = .025;//inside tire1
    glColor3ub(55, 55, 55);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

    xS1 = 0.27, yS1 = -0.44, radiS1 = .044;// tire2
    glColor3ub(40, 40, 40);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire1
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

    xS1 = 0.27, yS1 = -0.44, radiS1 = .025;//inside tire2
    glColor3ub(55, 55, 55);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

   glPopMatrix();
}

void vanS()
{
    glPushMatrix();
 glTranslatef(vanPosi,0.05, 0.0);
 glScalef(0.2,.4,0);

   glColor3ub(55, 55, 55);
   glBegin(GL_QUADS);
   glVertex2f(0.1, -0.44);
   glVertex2f(0.1, -0.4);
   glVertex2f(-0.77, -0.4);
   glVertex2f(-0.77, -0.44);
   glEnd();

   glColor3ub(255, 0, 0);
   glBegin(GL_QUADS);
   glVertex2f(0.08, -0.28);
   glVertex2f(0.08, -0.4);
   glVertex2f(-0.75, -0.4);
   glVertex2f(-0.75, -0.28);
   glEnd();

   glColor3ub(255, 0, 0);
   glBegin(GL_QUADS);
   glVertex2f(0.06, -0.26);
   glVertex2f(0.06, -0.4);
   glVertex2f(-0.75, -0.4);
   glVertex2f(-0.75, -0.26);
   glEnd();

    glColor3ub(255, 0, 0);//glass frame
   glBegin(GL_QUADS);
   glVertex2f(-0.06, -0.26);
   glVertex2f(-0.4, -0.26);
   glVertex2f(-0.4, -0.1);
   glVertex2f(-0.2, -0.1);
   glEnd();


   glBegin(GL_QUADS);//glass
   glColor3ub(55, 53, 64);
   glVertex2f(-0.08, -0.26);
   glVertex2f(-0.38, -0.26);
    glColor3ub(150, 141, 136);
   glVertex2f(-0.38, -0.12);
   glVertex2f(-0.21, -0.12);
   glEnd();

    glLineWidth(2.0f);//
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.4,-0.26); glVertex2f(-0.4,-0.4);
    glEnd();

    glLineWidth(4.0f);//
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.35,-0.3); glVertex2f(-0.3,-0.3);
    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(250, 177, 1);
    glVertex2f(-0.75,-0.35); glVertex2f(-0.72,-0.35);
    glVertex2f(-0.72,-0.3); glVertex2f(-0.75,-0.3);
    glEnd();

    glLineWidth(30.0f);//front light
    glBegin(GL_QUADS);
    glColor3ub(250, 177, 1);
    glVertex2f(0.05,-0.33); glVertex2f(0.08,-0.33);
    glVertex2f(0.08,-0.29); glVertex2f(0.05,-0.29);
    glEnd();

    //tire drawing
    int iS1;
    GLfloat xS1;
	GLfloat yS1;
	GLfloat radiS1;
	int triangleAmountS1 = 100; //# of lines used to draw circle

    GLfloat twicePiS1 = 2.0f * PI;
	//GLfloat PiS1 =  PI;

	xS1 = 0.065, yS1 = -0.275, radiS1 = .015;//curving front portion
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

	 xS1 = -0.1, yS1 = -0.44, radiS1 = .07;//tire 1 upper portion
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

    xS1=-0.1;yS1= -0.44;radiS1 =0.05;
    glColor3ub(55, 55, 55);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire1
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

     xS1 = -0.1, yS1 = -0.44, radiS1 = .025;//inside tire1
    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

     xS1 = -0.57, yS1 = -0.44, radiS1 = .07;//tire 2 upper portion
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

    xS1=-0.57;yS1= -0.44;radiS1 =0.05;
    glColor3ub(55,55,55);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1); // tire2
		for(iS1 = 0; iS1 <= triangleAmountS1;iS1++)
        glVertex2f( xS1 + (radiS1 * cos(iS1 *  twicePiS1 / triangleAmountS1)),yS1 + (radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1)) );
        glEnd();

     xS1 = -0.57, yS1 = -0.44, radiS1 = .025;//inside tire2
    glColor3ub(150,150,150);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xS1, yS1);
         for(iS1 = 0; iS1 <= triangleAmountS1; iS1++)
         glVertex2f(xS1 + radiS1 * cos(iS1 * twicePiS1 / triangleAmountS1), yS1 + radiS1 * sin(iS1 * twicePiS1 / triangleAmountS1));
         glEnd();

         glPopMatrix();

}

void truckS()
{
    glPushMatrix();
    glTranslatef(truckPosi, -0.17, 0.0f);
    glScalef(0.3,0.75,1);
    //1st face
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
glEnd();
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
glEnd();
    //mid
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
glEnd();
//4th line
//box1
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
     glVertex2f(0.0699138223646, -0.7003651235768);
glEnd();

//box2
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
glEnd();
//gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
glEnd();

//box3
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
glEnd();
//bigbox violet
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();
//gaps
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.69);
    //glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.7);
    //glVertex2f(0.7, -0.69);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7, -0.69);
    glEnd();
//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();
 glPopMatrix();
}

void truck1S()
{
    glPushMatrix();
    glTranslatef(truckPosi2, 0.1, 0.0f);
    glScalef(-0.15,0.3,1);
    //1st face
    glBegin(GL_POLYGON);
    glColor3ub(218, 162, 30);//yellow
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lightyellow
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lightyellow
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lightyellow
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
    glEnd();
    //front part lower portion
    glBegin(GL_POLYGON);
    glColor3ub(218, 162, 30);//yellow
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glEnd();
    //mid
    //front part lower portion
    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
    glEnd();

//immediate lower portion of container
//box1
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
    glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
    glVertex2f(0.0699138223646, -0.7003651235768);
    glEnd();

    //box2
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
    glEnd();
   //gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glEnd();

    //box3
    glBegin(GL_QUADS);
    glColor3ub(51, 51, 51);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
    glEnd();

    //bigbox coloring
    glBegin(GL_QUADS);
    glColor3ub(239, 117, 30);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.7);
    glVertex2f(-0.5, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(218, 162, 30);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();

//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();
 glPopMatrix();
}

void display2() {


    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();

    skyS();
    glEnd();
    cloud1S();
    cloud2S();
    cloud4S();
    cloud3S();
    cloud5S();
    glEnd();

    building1S();//background buildings
    building2S();//background buildings
    building3S();//background buildings
    birdS();
    bird1S();
    buildingS();//front buildings
    buildingSS();//front building

    road1S();//upper road
    LEAFS();//between roads and buildings
    vanS();
    truck1S();
    car2S();

    lightS();
    light1S();
    light2S();
    light3S();
    light4S();
    light5S();

    road2S();//lower road
    glEnd();
    leafS();//between two roads
    car1S();
    truckS();

glEnd();
 glFlush();
}




///// Shahariar's part /////


void wavemove1(int value)
{
    flag3 = true;

    if(wavePosition1>1.0)
        wavePosition1 = -1.0f;
    wavePosition1 += wavespeed1;

	glutPostRedisplay();
	glutTimerFunc(36, wavemove1, 0);
}
//cloud move1
void cloudmove1(int value)
{
    flag3 = true;

    if(cloudPosition1>1.8)
        cloudPosition1 = -1.0f;
    cloudPosition1 += cloudspeed1;

	glutPostRedisplay();
	glutTimerFunc(36, cloudmove1, 0);
}
//cloud move2
void cloudmove2(int value) {
    flag3 = true;

    if(cloudPosition2>1.8)
        cloudPosition2 = -1.8f;
    cloudPosition2+= cloudspeed2;

	glutPostRedisplay();
	glutTimerFunc(36, cloudmove2, 0);
}
//cloud move3
void cloudmove3(int value) {
    flag3 = true;

    if(cloudPosition3>1.8)
        cloudPosition3 = -1.8f;
    cloudPosition3+= cloudspeed3;

	glutPostRedisplay();
	glutTimerFunc(36, cloudmove3, 0);
}

//ship coming and stop
void Shipcoming(int value1)
{
    flag3 = true;

    if(shipPosition1 <0.019)
        shipPosition1 = 0.019f;
    shipPosition1 -= shipSpeed1;

	glutPostRedisplay();
	glutTimerFunc(60, Shipcoming, 0);
}
//ship moving again
void shipmove(int value)
{
    flag3 = true;

    if(shipPosition2 <-2.0)
        shipPosition2 = -2.0f;
    shipPosition2 -= shipSpeed2;


	glutPostRedisplay();
	glutTimerFunc(60, shipmove, 0);
}
//rope1 down
void RopeD1(int value)
 {
     flag3 = true;

    if(ropePositionD1 < -.57)
        ropePositionD1 = -.57f;
    ropePositionD1 -= ropeSpeedD1;

	glutPostRedisplay();
	glutTimerFunc(60, RopeD1, 0);
}
//rope2 down
void RopeD2(int value)
 {
     flag3 = true;

    if(ropePositionD2 < -.42)
        ropePositionD2 = -.42f;
    ropePositionD2 -= ropeSpeedD2;

	glutPostRedisplay();
	glutTimerFunc(60, RopeD2, 0);
}
//rope3 down
/*GLfloat ropePositionD3 = 0.0f;
GLfloat ropeSpeedD3 = 0.02f;*/
void RopeD3(int value)
 {
      flag3 = true;

    if(ropePositionD3 < -.27)
        ropePositionD3 = -.27f;
    ropePositionD3 -= ropeSpeedD3;

	glutPostRedisplay();
	glutTimerFunc(60, RopeD3, 0);
}
//rope4 down
void RopeD4(int value)
 {
      flag3 = true;
    if(ropePositionD4 < -.12)
        ropePositionD4 = -.12f;
    ropePositionD4 -= ropeSpeedD4;

	glutPostRedisplay();
	glutTimerFunc(60, RopeD4, 0);
}



//rope1 up
void RopeU1(int value)
 {
      flag3 = true;

    if(ropePositionU1 >.57f)
        ropePositionU1 = 0.57f;
    ropePositionU1 += ropeSpeedU1;


	glutPostRedisplay();
	glutTimerFunc(60, RopeU1, 0);
}
//rope2 up
void RopeU2(int value)
 {
      flag3 = true;

    if(ropePositionU2 >.42f)
        ropePositionU2 = 0.42f;
    ropePositionU2 += ropeSpeedU2;


	glutPostRedisplay();
	glutTimerFunc(60, RopeU2, 0);
}
//rope3 up
void RopeU3(int value)
 {
      flag3 = true;

    if(ropePositionU3 >.27f)
        ropePositionU3 = 0.27f;
    ropePositionU3 += ropeSpeedU3;


	glutPostRedisplay();
	glutTimerFunc(60, RopeU3, 0);
}
//rope4 up
void RopeU4(int value)
 {
      flag3 = true;

    if(ropePositionU4 >.12f)
        ropePositionU4 = 0.12f;
    ropePositionU4 += ropeSpeedU4;


	glutPostRedisplay();
	glutTimerFunc(60, RopeU4, 0);
}
//container down
void containerD(int value)
 {
      flag3 = true;

    if(containerPositionD < -.455)
        containerPositionD = -.455f;
    containerPositionD -= containerSpeedD;

	glutPostRedisplay();
	glutTimerFunc(60, containerD, 0);
}
//container remove
void containermove(int value)
{
     flag3 = true;

    if(containermovePosition <-2.0)
        containermovePosition = -2.0f;
    containermovePosition -= containermoveSpeed;


	glutPostRedisplay();
	glutTimerFunc(60, containermove, 0);
}


void sky()
{
    glBegin(GL_POLYGON);
	glColor3f(0.710f, 0.890f, 0.953f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);

	glColor3f(0.957f, 0.969f, 0.875f); // White
	glVertex2f(1.0f, -0.28f);
	glVertex2f(-1.0f, -0.28f);
	glEnd();
}

void cloud()
{
    //1
    int i1;

	GLfloat x1=-0.53f; GLfloat y1=0.52f; GLfloat radius1 =.07f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	//2

int i2;
	GLfloat x2=-0.46f; GLfloat y2=0.58f; GLfloat radius2 =.07f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();
	//3
	int i3;
	GLfloat x3=-0.37f; GLfloat y3=0.51f; GLfloat radius3 =.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();
	//4
	int i4;
	GLfloat x4=-0.27f; GLfloat y4=0.5f; GLfloat radius4 =.05f;
	int triangleAmount4= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4)) );
		}
	glEnd();
	//5
	int i5;
	GLfloat x5=-0.46f; GLfloat y5=0.48f; GLfloat radius5 =.05f;
	int triangleAmount5= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f( x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
                        y5 + (1.5*radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
		}
	glEnd();

}
void cloud12()
{
    //1
    int i1;

	GLfloat x1=-0.53f; GLfloat y1=0.52f; GLfloat radius1 =.07f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	//2

int i2;
	GLfloat x2=-0.46f; GLfloat y2=0.58f; GLfloat radius2 =.07f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();
	//3
	int i3;
	GLfloat x3=-0.37f; GLfloat y3=0.51f; GLfloat radius3 =.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

	//5
	int i5;
	GLfloat x5=-0.46f; GLfloat y5=0.48f; GLfloat radius5 =.05f;
	int triangleAmount5= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f( x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
                        y5 + (1.5*radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
		}
	glEnd();


}
void containerRed()
{
  glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();


}
void containerBlue()
{
    glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();




}
void containerOrange()
{

    glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();


}
void containerWhite()
{
    glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();
}
void warehouse()
{

	glBegin(GL_POLYGON);
	glColor3ub(245,228,211);
	glVertex2f(-.41f, -.18f);
	glVertex2f(-.65f, -.18f);
	glVertex2f(-.53f, -.1f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(245,228,211);
    glVertex2f(-.43f, -.28f);
	glVertex2f(-.43f, -.18f);
	glVertex2f(-.63f, -.18f);
	glVertex2f(-.63f, -.28f);
	glEnd();

glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.435f, -.28f);
	glVertex2f(-.435f, -.18f);
	glVertex2f(-.44f, -.18f);
	glVertex2f(-.44f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.445f, -.28f);
	glVertex2f(-.445f, -.17f);
	glVertex2f(-.45f, -.16f);
	glVertex2f(-.45f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.455f, -.28f);
	glVertex2f(-.455f, -.16f);
	glVertex2f(-.46f, -.15f);
	glVertex2f(-.46f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.465f, -.28f);
	glVertex2f(-.465f, -.15f);
	glVertex2f(-.47f, -.14f);
	glVertex2f(-.47f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.475f, -.28f);
	glVertex2f(-.475f, -.14f);
	glVertex2f(-.48f, -.135f);
	glVertex2f(-.48f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.485f, -.28f);
	glVertex2f(-.485f, -.13f);
	glVertex2f(-.49f, -.125f);
	glVertex2f(-.49f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.495f, -.28f);
	glVertex2f(-.495f, -.13f);
	glVertex2f(-.5f, -.125f);
	glVertex2f(-.5f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.505f, -.28f);
	glVertex2f(-.505f, -.13f);
	glVertex2f(-.51f, -.125f);
	glVertex2f(-.51f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.515f, -.28f);
	glVertex2f(-.515f, -.12f);
	glVertex2f(-.52f, -.12f);
	glVertex2f(-.52f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.525f, -.28f);
	glVertex2f(-.525f, -.12f);
	glVertex2f(-.53f, -.12f);
	glVertex2f(-.53f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.535f, -.28f);
	glVertex2f(-.535f, -.12f);
	glVertex2f(-.54f, -.12f);
	glVertex2f(-.54f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.545f, -.28f);
	glVertex2f(-.545f, -.125f);
	glVertex2f(-.55f, -.125f);
	glVertex2f(-.55f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.555f, -.28f);
	glVertex2f(-.555f, -.125f);
	glVertex2f(-.56f, -.13f);
	glVertex2f(-.56f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.565f, -.28f);
	glVertex2f(-.565f, -.125f);
	glVertex2f(-.57f, -.13f);
	glVertex2f(-.57f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.575f, -.28f);
	glVertex2f(-.575f, -.125f);
	glVertex2f(-.58f, -.13f);
	glVertex2f(-.58f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.585f, -.28f);
	glVertex2f(-.585f, -.13f);
	glVertex2f(-.59f, -.135f);
	glVertex2f(-.59f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.595f, -.28f);
	glVertex2f(-.595f, -.14f);
	glVertex2f(-.6f, -.15f);
	glVertex2f(-.6f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.605f, -.28f);
	glVertex2f(-.605f, -.16f);
	glVertex2f(-.61f, -.17f);
	glVertex2f(-.61f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.615f, -.28f);
	glVertex2f(-.615f, -.17f);
	glVertex2f(-.62f, -.18f);
	glVertex2f(-.62f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,197,183);
    glVertex2f(-.625f, -.28f);
	glVertex2f(-.625f, -.18f);
	glVertex2f(-.63f, -.19f);
	glVertex2f(-.63f, -.28f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
    glVertex2f(-.48f, -.28f);
	glVertex2f(-.48f, -.2f);
	glVertex2f(-.58f, -.2f);
	glVertex2f(-.58f, -.28f);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);

	glColor3ub(131,135,130);
	glVertex2f(-.41f, -.18f);
	glVertex2f(-.53f, -.1f);
	glEnd();

	glBegin(GL_LINES);

	glColor3ub(131,135,130);
	glVertex2f(-.65f, -.18f);
	glVertex2f(-.53f, -.1f);
	glEnd();





}
void warehouse1()
{
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-.08f, -.28f);
	glVertex2f(-.08f, -.14f);
	glVertex2f(-.3f, -.14f);
	glVertex2f(-.3f, -.28f);
	glEnd();

	 glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-.19f, -.05f);
	glVertex2f(-.08f, -.14f);
	glVertex2f(-.3f, -.14f);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(170,207,218);
    glVertex2f(-.08f, -.28f);
	glVertex2f(-.08f, -.14f);
	glVertex2f(.2f, -.14f);
	glVertex2f(.2f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(78,142,168);
    glVertex2f(-.19f, -.05f);
	glVertex2f(-.08f, -.14f);
	glVertex2f(.2f, -.14f);
	glVertex2f(.1f, -.05f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(51,60,77);
    glVertex2f(-.107f, -.19f);
	glVertex2f(-.107f, -.28f);
	glVertex2f(-.27f, -.28f);
	glVertex2f(-.27f, -.19f);
	glEnd();


}
void building()
{
    //MIRROR
    glBegin(GL_POLYGON);
	glColor3ub(75,144,150);
    glVertex2f(-.848f, .038f);
	glVertex2f(-.847f, -.28f);
	glColor3ub(0,208,208);
	glVertex2f(-.73f, -.28f);
	glVertex2f(-.73f, .038f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(75,144,150);
    glVertex2f(-.73f, .038f);
	glVertex2f(-.73f, -.28f);
	glColor3ub(160,240,229);
	glVertex2f(-.50f, -.28f);
	glVertex2f(-.503f, .038f);
	glEnd();
	//bRICK

    glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.85f, .11f);
    glVertex2f(-.85f, .038f);
	glColor3ub(247,233,218);
	glVertex2f(-.73f, .037f);
	glVertex2f(-.73f, .11f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.85f, .0f);
	glVertex2f(-.849f, -.068f);
	glColor3ub(247,233,218);
	glVertex2f(-.73f, -.073f);
	glVertex2f(-.73f, -.001f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.85f, -.11f);
	glVertex2f(-.85f, -.17f);
	glColor3ub(247,233,218);
	glVertex2f(-.73f, -.17f);
	glVertex2f(-.73f, -.11f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.73f, .11f);
	glVertex2f(-.73f, .037f);
	//glColor3ub(247,233,218);
	glVertex2f(-.49f, .039f);
	glVertex2f(-.49f, .11f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.73f, -.0012f);
	glVertex2f(-.73f, -.07f);
	//glColor3ub(247,233,218);
	glVertex2f(-.49f, -.0695f);
	glVertex2f(-.49f, -.0007f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(234,214,195);
    glVertex2f(-.73f, -.11f);
	glVertex2f(-.73f, -.17f);
	//glColor3ub(247,233,218);
	glVertex2f(-.49f, -.17f);
	glVertex2f(-.49f, -.11f);
	glEnd();





}

void craine()
{
    glBegin(GL_POLYGON);
	glColor3ub(81,91,116);
    glVertex2f(0.1f, -.28f);
	glVertex2f(.1f, -.26f);
	glVertex2f(.2f, -.26f);
	glVertex2f(.2f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(81,91,116);
    glVertex2f(0.12f, -.26f);
	glVertex2f(.12f, -.06f);
	glVertex2f(.13f, -.06f);
	glVertex2f(.13f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(81,91,116);
    glVertex2f(0.18f, -.26f);
	glVertex2f(.18f, -.06f);
	glVertex2f(.17f, -.06f);
	glVertex2f(.17f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(81,91,116);
    glVertex2f(0.1f, -.04f);
	glVertex2f(.1f, -.07f);
	glVertex2f(.2f, -.07f);
	glVertex2f(.2f, -.04f);
	glEnd();

	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3ub(81,91,116);
	glVertex2f(0.13f, -.06f);
	glVertex2f(.17f, -.17f);
	glEnd();


	glBegin(GL_LINES);
	glColor3ub(81,91,116);
	glVertex2f(0.13f, -.26f);
	glVertex2f(.17f, -.17f);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(81,91,116);
	glVertex2f(.17f, -.26f);
	glVertex2f(0.13f, -.17f);

	glEnd();

	glBegin(GL_LINES);
	glColor3ub(81,91,116);
	glVertex2f(0.13f, -.17f);
	glVertex2f(.17f, -.06f);
	glEnd();





}
void craine1()
{
    glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.49f, -.28f);
	glVertex2f(-.41f, -.28f);
	glVertex2f(-.41f, -.26f);
	glVertex2f(-.42f, -.25f);
	glVertex2f(-.48f, -.25f);
	glVertex2f(-.49f, -.26f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, -.28f);
	glVertex2f(-.28f, -.28f);
	glVertex2f(-.28f, -.26f);
	glVertex2f(-.29f, -.25f);
	glVertex2f(-.35f, -.25f);
	glVertex2f(-.36f, -.26f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.45f, -.25f);
	glVertex2f(-.45f, -.15f);
	glVertex2f(-.44f, -.15f);
	glVertex2f(-.44f, -.25f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.32f, -.25f);
	glVertex2f(-.32f, -.15f);
	glVertex2f(-.31f, -.15f);
	glVertex2f(-.31f, -.25f);
	glEnd();


	 glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.45f, -.15f);
	glVertex2f(-.31f, -.15f);
	glVertex2f(-.31f, -.17f);
	glVertex2f(-.45f, -.17f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.44f, -.24f);
	glVertex2f(-.44f, -.25f);
	glVertex2f(-.38f, -.17f);
	glVertex2f(-.39f, -.17f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.38f, -.17f);
	glVertex2f(-.37f, -.17f);
	glVertex2f(-.32f, -.24f);
	glVertex2f(-.32f, -.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.41f, -.15f);
	glVertex2f(-.4f, -.15f);
	glVertex2f(-.4f, .26f);
	glVertex2f(-.41f, .26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, -.15f);
	glVertex2f(-.35f, -.15f);
	glVertex2f(-.35f, .26f);
	glVertex2f(-.36f, .26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, .25f);
	glVertex2f(-.41f, .25f);
	glVertex2f(-.41f, .26f);
	glVertex2f(-.36f, .26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.4f, .25f);
	glVertex2f(-.39f, .25f);
	glVertex2f(-.36f, .05f);
	glVertex2f(-.36f, .0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, .25f);
	glVertex2f(-.37f, .25f);
	glVertex2f(-.4f, .05f);
	glVertex2f(-.4f, .0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, .05f);
	glVertex2f(-.36f, .0f);
	glVertex2f(-.39f, -.15f);
	glVertex2f(-.4f, -.15f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.4f, .05f);
	glVertex2f(-.4f, .0f);
	glVertex2f(-.37f, -.15f);
	glVertex2f(-.36f, -.15f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.41f, -.048f);
	glVertex2f(-.41f, -.063f);
	glVertex2f(-.44f, -.15f);
	glVertex2f(-.45f, -.15f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, -.048f);
	glVertex2f(-.36f, -.063f);
	glVertex2f(-.32f, -.15f);
	glVertex2f(-.31f, -.15f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.41f, .25f);
	glVertex2f(-.42f, .255f);
	glVertex2f(-.42f, .33f);
	glVertex2f(-.41f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.35f, .25f);
	glVertex2f(-.34f, .255f);
	glVertex2f(-.34f, .33f);
	glVertex2f(-.35f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.44f, .34f);
	glVertex2f(-.32f, .34f);
	glVertex2f(-.32f, .33f);
	glVertex2f(-.44f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.44f, .38f);
	glVertex2f(-.43f, .38f);
	glVertex2f(-.43f, .33f);
	glVertex2f(-.44f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.32f, .38f);
	glVertex2f(-.33f, .38f);
	glVertex2f(-.33f, .33f);
	glVertex2f(-.32f, .33f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.4f, .5f);
	glVertex2f(-.41f, .5f);
	glVertex2f(-.41f, .33f);
	glVertex2f(-.4f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, .5f);
	glVertex2f(-.35f, .5f);
	glVertex2f(-.35f, .33f);
	glVertex2f(-.36f, .33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.41f, .5f);
	glVertex2f(-.35f, .5f);
	glVertex2f(-.35f, .49f);
	glVertex2f(-.41f, .49f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.36f, .33f);
	glVertex2f(-.355f, .33f);
	glVertex2f(-.4f, .5f);
	glVertex2f(-.4f, .48f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.4f, .33f);
	glVertex2f(-.405f, .33f);
	glVertex2f(-.36f, .5f);
	glVertex2f(-.36f, .48f);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.44f, .5f);
	glVertex2f(-.35f, .5f);
	glVertex2f(-.35f, .525f);
	glVertex2f(-.44f, .525f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.357f, .5f);
	glVertex2f(-.34f, .5f);
	glVertex2f(-.34f, .59f);
	glVertex2f(-.357f, .59f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,228,228);
    glVertex2f(-0.355f, .5f);
	glVertex2f(-.34f, .5f);
	glVertex2f(-.34f, .59f);
	glVertex2f(-.355f, .59f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(1,1,1);
    glVertex2f(-0.34f, .59f);
	glVertex2f(-.33f, .59f);
	glVertex2f(-.31f, .58f);
	glVertex2f(-.31f, .51f);
	glVertex2f(-.33f, .5f);
	glVertex2f(-.34f, .5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(178,214,241);
    glVertex2f(-0.338f, .588f);
	glVertex2f(-.33f, .588f);
	glVertex2f(-.312f, .578f);
	glVertex2f(-.312f, .548f);
	glVertex2f(-.338f, .548f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(178,214,241);
	glVertex2f(-.312f, .545f);
	glVertex2f(-.338f, .545f);
	glVertex2f(-.338f, .502f);
	glVertex2f(-.33f, .502f);
	glVertex2f(-.312f, .512f);
	glEnd();




	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.47f, .54f);
	glVertex2f(-.52f, .54f);
	glVertex2f(-.52f, .64f);
	glVertex2f(-.47f, .64f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-0.47f, .59f);
	glVertex2f(.01f, .59f);
	glVertex2f(.0f, .61f);
	glVertex2f(-.47f, .605f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
	glVertex2f(-.005f, .65f);
    glVertex2f(-0.003f, .61f);
	glVertex2f(.01f, .59f);
	glVertex2f(-.002f, .64f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
	glVertex2f(-.32f, .648f);
    glVertex2f(-0.325f, .63f);
	glVertex2f(.001f, .633f);
	glVertex2f(.0046f, .648f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(243,197,46);
    glVertex2f(-.32f, .648f);
    glVertex2f(-0.335f, .64f);
	glVertex2f(-.34f, .599f);
	glVertex2f(-.33f, .6f);
	glEnd();

	 glBegin(GL_POLYGON);
	glColor3ub(230,178,115);
    glVertex2f(-.28f, .59f);
    glVertex2f(-0.28f, .58f);
	glVertex2f(-.26f, .58f);
	glVertex2f(-.26f, .59f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(230,178,115);
    glVertex2f(-.3f, .58f);
    glVertex2f(-0.3f, .56f);
	glVertex2f(-.24f, .56f);
	glVertex2f(-.24f, .58f);
	glEnd();
}
//hanger
void hanger()
{
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.29f, .41f);
    glVertex2f(-0.29f, .56f);
	glVertex2f(-.28f, .56f);
	glVertex2f(-.28f, .41f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.25f, .41f);
    glVertex2f(-0.25f, .56f);
	glVertex2f(-.26f, .56f);
	glVertex2f(-.26f, .41f);
	glEnd();

glPushMatrix();
glTranslatef(0,ropePositionD1, 0 );
glTranslatef(0,ropePositionU1, 0 );

	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.29f, .41f);
    glVertex2f(-0.29f, .56f);
	glVertex2f(-.28f, .56f);
	glVertex2f(-.28f, .41f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.25f, .41f);
    glVertex2f(-0.25f, .56f);
	glVertex2f(-.26f, .56f);
	glVertex2f(-.26f, .41f);
	glEnd();

	glBegin(GL_POLYGON); //holder
	glColor3ub(230,178,115);
    glVertex2f(-.3f, .41f);
    glVertex2f(-0.3f, .37f);
	glVertex2f(-.24f, .37f);
	glVertex2f(-.24f, .41f);
	glEnd();
	glPopMatrix();

//2
	glPushMatrix();
glTranslatef(0,ropePositionD2, 0 );
glTranslatef(0,ropePositionU2, 0 );

	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.29f, .41f);
    glVertex2f(-0.29f, .56f);
	glVertex2f(-.28f, .56f);
	glVertex2f(-.28f, .41f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.25f, .41f);
    glVertex2f(-0.25f, .56f);
	glVertex2f(-.26f, .56f);
	glVertex2f(-.26f, .41f);
	glEnd();
	glPopMatrix();
//3
glPushMatrix();
glTranslatef(0,ropePositionD3, 0 );
glTranslatef(0,ropePositionU3, 0 );

	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.29f, .41f);
    glVertex2f(-0.29f, .56f);
	glVertex2f(-.28f, .56f);
	glVertex2f(-.28f, .41f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.25f, .41f);
    glVertex2f(-0.25f, .56f);
	glVertex2f(-.26f, .56f);
	glVertex2f(-.26f, .41f);
	glEnd();
	glPopMatrix();
//4
	glPushMatrix();

glTranslatef(0,ropePositionD4, 0 );
glTranslatef(0,ropePositionU4, 0 );

	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.29f, .41f);
    glVertex2f(-0.29f, .56f);
	glVertex2f(-.28f, .56f);
	glVertex2f(-.28f, .41f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,8,5);
    glVertex2f(-.25f, .41f);
    glVertex2f(-0.25f, .56f);
	glVertex2f(-.26f, .56f);
	glVertex2f(-.26f, .41f);
	glEnd();
	glPopMatrix();


}
void truck()
{
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
glEnd();
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
glEnd();
    //mid
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
glEnd();
//4th line
//box1
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
     glVertex2f(0.0699138223646, -0.7003651235768);
glEnd();

//box2
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
glEnd();
//gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
glEnd();

//box3
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
glEnd();

//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();

   // truckBoxR();
 glBegin(GL_QUADS);
    glColor3ub(195,102,60);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();
//gaps
    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.5, -0.69);
    //glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.7);
    //glVertex2f(0.7, -0.69);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7, -0.69);
    glEnd();
}


//Middle
void surface()
{

    glBegin(GL_POLYGON);
	glColor3ub(193,193,193);
    glVertex2f(-1.0f, -.28f);
	glVertex2f(1.0f, -.28f);
	glVertex2f(1.0f, -.44f);
	glVertex2f(-1.0f, -.44f);
	glEnd();
	 glBegin(GL_POLYGON);
	glColor3ub(173,173,173 );
    glVertex2f(-1.0f, -.3f);
	glVertex2f(1.0f, -.3f);
	glVertex2f(1.0f, -.34f);
	glVertex2f(-1.0f, -.34f);
	glEnd();

}
//Bottom
void sea()
{
    glBegin(GL_POLYGON);
	glColor3ub(55,137,174);
    glVertex2f(-1.0f, -.44f);
	glVertex2f(1.0f, -.44f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();
}
void ship()
{

    //red
    glBegin(GL_POLYGON);
	glColor3ub(156,22,39);
    glVertex2f(-.91f, -.38f);

	glVertex2f(-.87f, -.44f);
	glVertex2f(.388f, -.44f);
	glVertex2f(.387f, -.43f);
	glVertex2f(.38f, -.42f);
	glVertex2f(.36f, -.4f);
	glVertex2f(.36f, -.38f);
	glEnd();

	//black
	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.91f, -.38f);
    glVertex2f(.36f, -.38f);
	glVertex2f(.369f, -.38f);
	glVertex2f(.37f, -.37f);
	glVertex2f(.45f, -.35f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(-.93f, -.26f);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.53f, -.35f);
    glVertex2f(-.57f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(.1f, -.26f);
	glVertex2f(.069f, -.35f);
    glVertex2f(.45f, -.35f);
    glVertex2f(.47f, -.26f);
	glEnd();

	//in water
	glBegin(GL_POLYGON);
	glColor3ub(101,103,143);
	glVertex2f(-.87f, -.44f);
	glVertex2f(-.81f, -.54f);
    glVertex2f(.34f, -.54f);
    glVertex2f(.388f, -.44f);
	glEnd();

	//cr

	glBegin(GL_POLYGON);
	glColor3ub(206,206,206);
    glVertex2f(.16f, .2f);
    glVertex2f(.16f, -.1f);
    glVertex2f(.165f, -.1f);
    glVertex2f(.165f, .2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(206,206,206);

	glVertex2f(.11f, -.07f);
    glVertex2f(.1f, -.05f);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.26f);
    glVertex2f(.11f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(161,51,66);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(161,51,66);
    glVertex2f(.1f, .02f);
    glVertex2f(.17f, .02f);
    glVertex2f(.19f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(226,226,226);
    glVertex2f(.11f, -.26f);
    glVertex2f(.11f, -.1f);
    glVertex2f(.17f, -.1f);
    glVertex2f(.17f, -.19f);
    glVertex2f(.29f, -.19f);
     glVertex2f(.29f, -.26f);
	glEnd();





	glBegin(GL_POLYGON);
	glColor3ub(75,144,150);
	glVertex2f(.11f, -.07f);
    glVertex2f(.10f, -.045f);

    glColor3ub(160,240,229);
    glVertex2f(.211f, -.045f);
    glVertex2f(.211f, -.07f);


	glEnd();



}
void wave()
{


    glPushMatrix();
    glTranslatef(0,0.35, 0);
  //  glScalef(, 1.2, 0);
    glBegin(GL_POLYGON);
    glColor3ub(55,137,174);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.9f, -0.72f);
    glVertex2f(-0.8f, -0.70f);
    glVertex2f(-0.7f, -0.73f);
    glVertex2f(-0.6f, -0.71f);
    glVertex2f(-0.5f, -0.74f);
    glVertex2f(-0.4f, -0.72f);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.2f, -0.72f);
    glVertex2f(-0.1f, -0.74f);
    glVertex2f( 0.0f, -0.72f);
    glVertex2f( 0.1f, -0.73f);
    glVertex2f( 0.2f, -0.70f);
    glVertex2f( 0.3f, -0.72f);
    glVertex2f( 0.4f, -0.71f);
    glVertex2f( 0.5f, -0.73f);
    glVertex2f( 0.6f, -0.70f);
    glVertex2f( 0.7f, -0.72f);
    glVertex2f( 0.8f, -0.71f);
    glVertex2f( 0.9f, -0.73f);
    glVertex2f( 1.0f, -0.7f);
    glVertex2f( 1.0f, -1.0f);
    glEnd();
    glPopMatrix();
}

void display4() {
    glClearColor(0.411f, 0.411f, 0.411f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glClear(GL_COLOR_BUFFER_BIT);
//up
    sky();//sky

glPushMatrix();
glTranslatef(cloudPosition1,0.0f,0.0f);
    glScalef(.7,1,0);//left cloud
    glTranslatef(-.4f, 0.2f, 0.0f);
    cloud();
    glLoadIdentity();//end
glPushMatrix();
glTranslatef(cloudPosition2,0.0f,0.0f);
    glTranslatef(+0.8f, 0.4f, 0.0f);//up right cloud
    glScalef(.5,.7,0);
    cloud();
    glLoadIdentity();//end
glPushMatrix();
glTranslatef(cloudPosition3,0.0f,0.0f);
    glTranslatef(0.3f, -0.1f, 0.0f);//right down
    glScalef(.8,1.,0);
    cloud12();
    glLoadIdentity();//end
glPopMatrix();
    //bg craines
glTranslatef(0.7f, -0.1f, 0.0f);
    glScalef(.6,.6,0);
    craine1();
    glLoadIdentity();

    glTranslatef(-0.2f, -0.2f, 0.0f);
    glScalef(.5,.5,0);
    craine1();
    glLoadIdentity();
//uilding
    glTranslatef(0.05f, -0.04f, 0.0f);
    glScalef(1.2,1.5,0);
    building();
    glLoadIdentity();


   //Middle
surface();

//right side containers
    containerRed();

    containerBlue();

    containerOrange();

    containerWhite();

    glTranslatef(0.24f, 0.08f, 0.0f);
    containerRed();
    glLoadIdentity();



    glTranslatef(-0.24f, 0.08f, 0.0f);
    containerWhite();
    glLoadIdentity();

    glTranslatef(-0.12f, 0.16f, 0.0f);
    containerOrange();
    glLoadIdentity();

    glTranslatef(0.24f, 0.08f, 0.0f);
    containerBlue();
    glLoadIdentity();



    glTranslatef(-0.5f, -0.06f, 0.0f);
    glScalef(.8,.8,0);
    warehouse1();
    glLoadIdentity();

    glTranslatef(-0.25f, -0.06f, 0.0f);
    glScalef(.8,.8,0);
    warehouse1();
    glLoadIdentity();
//truck
glPushMatrix();
glTranslatef(cloudPosition1,0.0f,0.0f);
glTranslatef(-0.6f, -0.088f, 0.0f);
  glScalef(-.12,.22,0);
truck();
glLoadIdentity();
glPopMatrix();
//craine
    glTranslatef(0.4f, -0.056f, 0.0f);
    glScalef(.8,.8,0);
    craine1();
    glLoadIdentity();

//hanger
glTranslatef(0.4f, -0.056f, 0.0f);
    glScalef(.8,.8,0);
    hanger();
    glLoadIdentity();

glPushMatrix();
glTranslatef(0.0f,containerPositionD,0.0f);
glTranslatef(containermovePosition,0.0f,0.0f);
    glTranslatef(-0.275f, 0.44f, 0.0f);
    containerRed();
    glLoadIdentity();
glPopMatrix();

    //hanger
    //hanger();


    //end


//Bottom
  sea();

  //containers on ships
glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.635f, -0.113f, 0.0f);
    containerWhite();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.515f, -0.113f, 0.0f);
    containerRed();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.755f, -0.113f, 0.0f);
    containerBlue();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.635f, -0.113f, 0.0f);
    containerOrange();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.875f, -0.033f, 0.0f);
    containerWhite();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.875f, -0.033f, 0.0f);
    containerOrange();
    glLoadIdentity();


glPushMatrix();
glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
    glTranslatef(-0.515f, -0.033f, 0.0f);
    containerBlue();
    glLoadIdentity();

//ship
glPushMatrix();

glTranslatef(shipPosition1,.0f,0.0f);
glTranslatef(shipPosition2,0.0f,0.0f);
  glTranslatef(0.2f, -0.08f, 0.0f);
  glScalef(.8,.8,0);
  ship();
  glLoadIdentity();
glPopMatrix();

//wave
glPushMatrix();
glTranslatef(wavePosition1,.0f,0.0f);
glTranslatef(0.2f, -0.25f, 0.0f);
  glScalef(4.1,.5,0);
wave();
glLoadIdentity();
glPopMatrix();

glTranslatef(0.2f, -0.251f, 0.0f);
  glScalef(2.0,.5,0);
wave();
glLoadIdentity();
     glFlush(); // Render now
}



///// ria's part /////


void updateR(int value)
 {
     flag2 = true;

    if(crane1p < 0.03)
        crane1p = 0.03f;
    crane1p -= crane1speed;

     if(boatPosiR <-1.4)
        boatPosiR = 1.4f;
    boatPosiR -= boatSpR;


	glutPostRedisplay();
	glutTimerFunc(60, updateR, 0);
}

void update2R(int value)
 {
     flag2 = true;

    if(crane2p >0)
        crane2p = 0.0f;
    crane2p += crane2speed;


	glutPostRedisplay();
	glutTimerFunc(60, update2R, 0);
}

void update1R(int value1) {
    flag2 = true;

    if(truckposition1 <-0.4)
        truckposition1 = -0.4f;
    truckposition1 -= truckspeed1;


    if(cloud1p >1.8)
        cloud1p = -0.8f;
    cloud1p += cloud1speed;

    if(cloud2p >2)
        cloud2p = -2.0f;
    cloud2p += cloud2speed;

    if(cloud3p >1.4)
        cloud3p = -2.0f;
    cloud3p += cloud3speed;



	glutPostRedisplay();
	glutTimerFunc(60, update1R, 0); //0.06
}


void update4R(int value) {
    flag2 = true;

    if(truckposition3 <-0.4) //-1.2
        truckposition3 = -0.4f; //1.2
    truckposition3 -= truckspeed3;


	glutPostRedisplay();
	glutTimerFunc(60, update4R, 0);
}


void update3R(int value) {
    flag2 = true;

    if(truckposition2 <-1.0)
        truckposition2 = -1.0f;
    truckposition2 -= truckspeed2;


	glutPostRedisplay();
	glutTimerFunc(60, update3R, 0);
}


void ropeR()
{
    glPushMatrix();

    glTranslatef(0.00331,-0.4, 0);
    glScalef(1.01, 1.8, 0);

    glBegin(GL_QUADS);//left
    glColor3ub(17, 32, 63);
    glVertex2f(-0.5,0.51);
    glVertex2f(-0.49,0.51);
    glVertex2f(-0.49,0.29);
    glVertex2f(-0.5,0.29);
    glEnd();

    glBegin(GL_QUADS);//right
    glColor3ub(17, 32, 63);
    glVertex2f(-0.3,0.51);
    glVertex2f(-0.31,0.51);
    glVertex2f(-0.31,0.29);
    glVertex2f(-0.3,0.29);
    glEnd();

    glPopMatrix();
}
void craneRopeR()
{
    glPushMatrix();

    glTranslatef(0,crane1p, 0 );

    glTranslatef(0,crane2p, 0 );


    glBegin(GL_QUADS);//left
    glColor3ub(17, 32, 63);
    glVertex2f(-0.5,0.51);
    glVertex2f(-0.49,0.51);
    glVertex2f(-0.49,0.29);
    glVertex2f(-0.5,0.29);
    glEnd();

    glBegin(GL_QUADS);//right
    glColor3ub(17, 32, 63);
    glVertex2f(-0.3,0.51);
    glVertex2f(-0.31,0.51);
    glVertex2f(-0.31,0.29);
    glVertex2f(-0.3,0.29);
    glEnd();

    glBegin(GL_QUADS);//square left
    glColor3ub(17, 32, 63);
    glVertex2f(-0.51,0.29);
    glVertex2f(-0.51,0.27);
    glVertex2f(-0.48,0.27);
    glVertex2f(-0.48,0.29);
    glEnd();

    glBegin(GL_QUADS);//square right
    glColor3ub(17, 32, 63);
    glVertex2f(-0.29,0.29);
    glVertex2f(-0.29,0.27);
    glVertex2f(-0.32,0.27);
    glVertex2f(-0.32,0.29);
    glEnd();

    glBegin(GL_QUADS);// majher square
    glColor3ub(250, 155, 23);
    glVertex2f(-0.52,0.27);
    glVertex2f(-0.52,0.24);
    glVertex2f(-0.28,0.24);
    glVertex2f(-0.28,0.27);
    glEnd();

    glBegin(GL_QUADS);// left
    glColor3ub(250, 155, 23);
    glVertex2f(-0.52,0.24);
    glVertex2f(-0.5,0.24);
    glVertex2f(-0.52,0.21);
    glVertex2f(-0.54,0.21);
    glEnd();

    glBegin(GL_QUADS);// right
    glColor3ub(250, 155, 23);
    glVertex2f(-0.3,0.24);
    glVertex2f(-0.28,0.24);
    glVertex2f(-0.26,0.21);
    glVertex2f(-0.28,0.21);
    glEnd();

    glBegin(GL_QUADS);// again square
    glColor3ub(250, 155, 23);
    glVertex2f(-0.57,0.21);
    glVertex2f(-0.23,0.21);
    glVertex2f(-0.23,0.18);
    glVertex2f(-0.57,0.18);
    glEnd();
    glBegin(GL_QUADS);//left
    glColor3ub(250, 155, 23);
    glVertex2f(-0.57,0.22);
    glVertex2f(-0.55,0.22);
    glVertex2f(-0.55,0.15);
    glVertex2f(-0.57,0.15);
    glEnd();

    glBegin(GL_QUADS);//right
    glColor3ub(250, 155, 23);
    glVertex2f(-0.23,0.22);
    glVertex2f(-0.25,0.22);
    glVertex2f(-0.25,0.15);
    glVertex2f(-0.23,0.15);
    glEnd();


    glPopMatrix();

}

void truckBoxR(float a, float b)
{
    glPushMatrix();
    glTranslatef(truckposition1, crane2p, 0.0f);

    glTranslatef(a,b, 0.0f);
    glScalef(0.4,0.8,1);
    //bigbox violet
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.24, 0.03, 0.29);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();
//gaps
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.21, 0.51);
    glVertex2f(-0.5, -0.69);
    //glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.7);
    //glVertex2f(0.7, -0.69);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7, -0.69);
    glEnd();
    glPopMatrix();
}

void truckR()
    {

      glPushMatrix();
    glTranslatef(truckposition1,0.13,0.0f);

     glTranslatef(truckposition2,0.01,0.0f);

    glScalef(0.4,0.8,1);
    //1st face
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.03, 0.34);//lighred
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
glEnd();
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.16, 0.16);//red
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
glEnd();
    //mid
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
glEnd();
//4th line
//box1
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
     glVertex2f(0.0699138223646, -0.7003651235768);
glEnd();

//box2
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
glEnd();
//gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
glEnd();

//box3
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
glEnd();

//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();
    glPopMatrix();
   // truckBoxR();

}


//box2
void truckBox2R(float a, float b)
{
    glPushMatrix();
   glTranslatef(truckposition3, -0.37, 0.0f);

    glTranslatef(a,b, 0.0f);
    glScalef(0.4,0.8,1);
    //bigbox blue
    glBegin(GL_QUADS);
    glColor3ub(195,102,60);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.4503511197546, -0.4398175177671);
    glVertex2f(-0.4003511197546, -0.4398175177671);
    glVertex2f(-0.4, -0.66);
    glVertex2f(-0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.35, -0.44);
    glVertex2f(-0.3002177908557, -0.44);
    glVertex2f(-0.301, -0.66);
    glVertex2f(-0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.25, -0.44);
    glVertex2f(-0.2008268490549, -0.44);
    glVertex2f(-0.2, -0.66);
    glVertex2f(-0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.15, -0.44);
    glVertex2f(-0.1, -0.44);
    glVertex2f(-0.1, -0.66);
    glVertex2f(-0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.05, -0.44);
    glVertex2f(0, -0.44);
    glVertex2f(0, -0.66);
    glVertex2f(-0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.1, -0.44);
    glVertex2f(0.1, -0.66);
    glVertex2f(0.05, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.15, -0.44);
    glVertex2f(0.2, -0.44);
    glVertex2f(0.2, -0.66);
    glVertex2f(0.15, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.25, -0.44);
    glVertex2f(0.3, -0.44);
    glVertex2f(0.3, -0.66);
    glVertex2f(0.25, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.35, -0.44);
    glVertex2f(0.4, -0.44);
    glVertex2f(0.4, -0.66);
    glVertex2f(0.35, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.45, -0.44);
    glVertex2f(0.5, -0.44);
    glVertex2f(0.5, -0.66);
    glVertex2f(0.45, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.55, -0.44);
    glVertex2f(0.6, -0.44);
    glVertex2f(0.6, -0.66);
    glVertex2f(0.55, -0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(0.65, -0.44);
    glVertex2f(0.7, -0.44);
    glVertex2f(0.7, -0.66);
    glVertex2f(0.65, -0.66);
    glEnd();
//gaps
    glBegin(GL_QUADS);
    glColor3ub(221,129,86);
    glVertex2f(-0.5, -0.69);
    //glVertex2f(0.7, -0.69);
    glVertex2f(-0.5, -0.7);
    //glVertex2f(0.7, -0.69);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7, -0.69);
    glEnd();
    glPopMatrix();
}

//truck2
void truck2R()
    {

glPushMatrix();

    glTranslatef(truckposition3, 0.13, 0.0f);


    glScalef(0.4,0.8,1);
    //1st face
    glBegin(GL_POLYGON);
    glColor3ub(218, 162, 30);//red
    glVertex2f(-0.7798794336197, -0.5358750813874);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8116405758308, -0.7414301970713);
    glVertex2f(-0.56, -0.74);
    glVertex2f(-0.56, -0.536);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lighred
    glVertex2f(-0.56, -0.585);
    glVertex2f(-0.67, -0.58);
    glVertex2f(-0.67, -0.585);
    glVertex2f(-0.56, -0.58);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lighred
    glVertex2f(-0.5959, -0.59);
    glVertex2f(-0.5959, -0.74);
    glVertex2f(-0.59, -0.74);
    glVertex2f(-0.59, -0.59);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251,224,107);//lighred
    glVertex2f(-0.7, -0.6399991323492);
    glVertex2f(-0.7016, -0.7408);
    glVertex2f(-0.7, -0.7408);
    glVertex2f(-0.7016, -0.639999117532);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(0.78, 0.94, 0.94);
    glVertex2f(-0.8088174397456, -0.5745704415185);
    glVertex2f(-0.8133053826038, -0.5850423081877);
    glVertex2f(-0.824, -0.624);
    glVertex2f(-0.8261899019066, -0.639990009695);
    glVertex2f(-0.688, -0.64);
    glVertex2f(-0.6866, -0.64);
    glVertex2f(-0.67, -0.625);
    glVertex2f(-0.67, -0.572);
    glVertex2f(-0.8075464819786, -0.5720130882648);
glEnd();
    //1stdown
    glBegin(GL_POLYGON);
    glColor3ub(218, 162, 30);//red
    glVertex2f(-0.83, -0.78);
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.7502072523516, -0.8200495414093);
    glVertex2f(-0.6, -0.82);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.2401638857244, -0.7790517356562);
    glVertex2f(-0.56, -0.79);
    glVertex2f(-0.56, -0.75);
    glVertex2f(-0.812212, -0.749874);
    glVertex2f(-0.8116405758308, -0.7414301970713);
glEnd();
    //mid
    //1stdown
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.828, -0.82);
    glVertex2f(-0.82763, -0.86401);
    glVertex2f(-0.759, -0.864);
    glVertex2f(-0.7502072523516, -0.8200495414093);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.59085, -0.8638);
    glVertex2f(-0.299736, -0.864);
    glVertex2f(-0.29, -0.82);
    glVertex2f(-0.599944, -0.82);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.7004213381693, -0.7618709856827);
    glVertex2f(-0.1, -0.76);
    glVertex2f(-0.1, -0.8);
    glVertex2f(0.65, -0.8);
    glVertex2f(0.68, -0.88);
    glVertex2f(0.7, -0.88);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.3580000499988, -0.75870999975);
    glVertex2f(-0.4500012499688, -0.7582499937502);
    glVertex2f(-0.4499999952517, -0.786234590131);
    glVertex2f(-0.3579991534529, -0.7830853378748);
glEnd();
//4th line
//box1
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.5, -0.758);//
    glVertex2f(-0.19999971315881, -0.7594644321079);//
    glVertex2f(-0.2000001231353, -0.7001921992831);
glEnd();
//gap1
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(-0.2050732871536, -0.7001889490868);
    glVertex2f(-0.2049973750656, -0.7594750131247);
    glVertex2f(-0.1749981250469, -0.7596250093748);
     glVertex2f(0.0699138223646, -0.7003651235768);
glEnd();

//box2
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(-0.179580963544, -0.7002052811146);
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.3700097160634, -0.75988262523525);
    glVertex2f(-0.179580963544, -0.758);
glEnd();
//gap2
    glBegin(GL_QUADS);
    glColor3f(0.32, 0.32, 0.32);//black
    glVertex2f(0.3699966411759, -0.699670346799);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.3700097160634, -0.75988262523525);
glEnd();

//box3
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.62, 0.65);//ash
    glVertex2f(0.7, -0.7);
    glVertex2f(0.7004378793879, -0.7594644321079);
    glVertex2f(0.4000076008226, -0.758);
    glVertex2f(0.4, -0.7);
glEnd();

//tire1
int i1;

	GLfloat x1=-0.6749789219893;
	GLfloat y1= -0.8584229061304;
	GLfloat radius1 =0.09f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(0.39, 0.39, 0.38);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();

int i1a;

	GLfloat x1a=-0.6753176771763;
	GLfloat y1a=-0.8858532469138;
	GLfloat radius1a =0.09f;
	int triangleAmount1a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1a = 2.0f * PI;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1a, y1a); // center of circle
		for(i1a = 0; i1a <= triangleAmount1a;i1a++) {
			glVertex2f( x1a + (radius1a * cos(i1a *  twicePi1a / triangleAmount1a)),
                        y1a + (radius1a * sin(i1a * twicePi1a / triangleAmount1a)) );
		}
	glEnd();

int i1b;

	GLfloat x1b=-0.673992187178;
	GLfloat y1b=-0.8900676797597;
	GLfloat radius1b =0.05f;
	int triangleAmount1b = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi1b = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1b, y1b); // center of circle
		for(i1b = 0; i1b <= triangleAmount1b;i1b++) {
			glVertex2f( x1b + (radius1b * cos(i1b *  twicePi1b / triangleAmount1b)),
                        y1b + (radius1b * sin(i1b * twicePi1b / triangleAmount1b)) );
		}
	glEnd();
//tire2
int i2;

	GLfloat x2=-0.2079876827823;
	GLfloat y2=  -0.8686960330673;
	GLfloat radius2 =0.0929f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();

int i2a;

	GLfloat x2a=-0.2079876827823;
	GLfloat y2a= -0.8686960330673;
	GLfloat radius2a =0.05f;
	int triangleAmount2a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi2a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2a, y2a); // center of circle
		for(i2a = 0; i2a <= triangleAmount2a;i2a++) {
			glVertex2f( x2a + (radius2a * cos(i2a *  twicePi2a / triangleAmount2a)),
                        y2a + (radius2a * sin(i2a * twicePi2a / triangleAmount2a)) );
		}
	glEnd();
//tire3
int i3;

	GLfloat x3=0.3059749891027;
	GLfloat y3=-0.8666125645025;
	GLfloat radius3 =0.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

int i3a;

	GLfloat x3a=0.3060771177067;
	GLfloat y3a= -0.8642383512027;
	GLfloat radius3a =0.04f;
    int triangleAmount3a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi3a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3a, y3a); // center of circle
		for(i3a = 0; i3a <= triangleAmount3a;i3a++) {
			glVertex2f( x3a + (radius3a * cos(i3a *  twicePi3a / triangleAmount3a)),
                        y3a + (radius3a * sin(i3a * twicePi3a / triangleAmount3a)) );
		}
	glEnd();
//tire3
int i4;

	GLfloat x4=0.5057810033338;
	GLfloat y4=-0.8674923927978;
	GLfloat radius4 =0.09f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount3;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi3 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi3 / triangleAmount4)) );
		}
	glEnd();

int i4a;

	GLfloat x4a=0.5057930650744;
	GLfloat y4a= -0.8689081265038;
	GLfloat radius4a =0.04f;
    int triangleAmount4a = 100; //# of lines used to draw circle

	//GLfloat radius = 0.2f; //radius
	GLfloat twicePi4a = 2.0f * PI;

	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4a, y4a); // center of circle
		for(i4a = 0; i4a <= triangleAmount4a;i4a++) {
			glVertex2f( x4a + (radius4a * cos(i4a *  twicePi4a / triangleAmount4a)),
                        y4a + (radius4a * sin(i4a * twicePi4a / triangleAmount4a)) );
		}
	glEnd();
    glPopMatrix();
   // truckBoxR();

}


void BoatR()
{
 glPushMatrix();

   glTranslatef(boatPosiR,-0.08, 0.0f);

    glScalef(0.44,0.44,0);

    //blue
    glBegin(GL_POLYGON);
	glColor3ub(16,77,131);
    glVertex2f(-.91f, -.38f);

	glVertex2f(-.87f, -.44f);
	glVertex2f(.388f, -.44f);
	glVertex2f(.387f, -.43f);
	glVertex2f(.38f, -.42f);
	glVertex2f(.36f, -.4f);
	glVertex2f(.36f, -.38f);
	glEnd();

	//black
	glBegin(GL_POLYGON);
	glColor3ub(16,77,131);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.91f, -.38f);
    glVertex2f(.36f, -.38f);
	glVertex2f(.369f, -.38f);
	glVertex2f(.37f, -.37f);
	glVertex2f(.45f, -.35f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(-.93f, -.26f);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.53f, -.35f);
    glVertex2f(-.57f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(.1f, -.26f);
	glVertex2f(.069f, -.35f);
    glVertex2f(.45f, -.35f);
    glVertex2f(.47f, -.26f);
	glEnd();

	//in water
	glBegin(GL_POLYGON);
	glColor3ub(101,103,143);
	glVertex2f(-.87f, -.44f);
	glVertex2f(-.81f, -.54f);
    glVertex2f(.34f, -.54f);
    glVertex2f(.388f, -.44f);
	glEnd();

	//cr

	glBegin(GL_POLYGON);
	glColor3ub(206,206,206);

	glVertex2f(.11f, -.07f);
    glVertex2f(.1f, -.05f);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.26f);
    glVertex2f(.11f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(16,77,131);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(16,77,131);
    glVertex2f(.1f, .02f);
    glVertex2f(.17f, .02f);
    glVertex2f(.19f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(226,226,226);
    glVertex2f(.11f, -.26f);
    glVertex2f(.11f, -.1f);
    glVertex2f(.17f, -.1f);
    glVertex2f(.17f, -.19f);
    glVertex2f(.29f, -.19f);
     glVertex2f(.29f, -.26f);
	glEnd();

	//container1

glTranslatef(0.62,0.12, 0.0f);
	glScalef(-1.36,1.7,0);

	 glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();
//blue
	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();
//orange
glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();
//white
	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();

//container2

glTranslatef(1.315,0.165, 0.0f);
	glScalef(-1.16,1.3,0);

	 glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();
//blue
	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();

/*//container3

glTranslatef(1.33,0.08, 0.0f);
	glScalef(-1.006,1,0);


//orange
glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();
//white
	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();*/



glPopMatrix();

}

void cloud1R() {

    glPushMatrix();

    glTranslatef(cloud1p, 0, 0);

    int i;
    GLfloat x = -0.53f, y = 0.7f, radius = .04f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.47f; y = 0.73f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.40f; y = 0.7f; radius = .05f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.47f; y = 0.67f; radius = .03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + 1.5 * radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();
}



void cloud2R() {

     glPushMatrix();

    glTranslatef(cloud2p, 0, 0);

    int i;
    GLfloat x = 0.3f, y = 0.75f, radius = .04f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.36f; y = 0.78f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.43f; y = 0.75f; radius = .05f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = 0.36f; y = 0.72f; radius = .03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + 1.5 * radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();
}

void cloud3R() {
     glPushMatrix();

    glTranslatef(cloud3p, 0, 0);

    int i;
    GLfloat x = -0.15f, y = 0.85f, radius = .04f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.09f; y = 0.88f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.02f; y = 0.85f; radius = .05f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + radius * sin(i * twicePi / triangleAmount));
    glEnd();

    x = -0.09f; y = 0.82f; radius = .03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        glVertex2f(x + radius * cos(i * twicePi / triangleAmount), y + 1.5 * radius * sin(i * twicePi / triangleAmount));
    glEnd();

    glPopMatrix();
}

void buildingR(){
    // 25 Buildings
    glColor3ub(124, 206, 228);

    glBegin(GL_QUADS);
     glVertex2f(-1.00f, -0.28f);
     glVertex2f(-1.00f, 0.25f);
     glVertex2f(-0.92f, 0.25f);
     glVertex2f(-0.92f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.92f, -0.28f);
    glVertex2f(-0.92f, 0.34f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.84f, -0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.84f, -0.28f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.76f, 0.22f);
    glVertex2f(-0.76f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.76f, -0.28f);
      glVertex2f(-0.76f, 0.30f);
       glVertex2f(-0.68f, 0.30f);
       glVertex2f(-0.68f, -0.28f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.68f, -0.28f);
    glVertex2f(-0.68f, 0.27f);
    glVertex2f(-0.60f, 0.27f);
     glVertex2f(-0.60f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.60f, -0.28f);
     glVertex2f(-0.60f, 0.39f);
     glVertex2f(-0.52f, 0.39f);
     glVertex2f(-0.52f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.52f, -0.28f);
     glVertex2f(-0.52f, 0.30f);
     glVertex2f(-0.44f, 0.30f);
     glVertex2f(-0.44f, -0.28f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.44f, -0.28f);
     glVertex2f(-0.44f, 0.42f);
     glVertex2f(-0.36f, 0.42f);
      glVertex2f(-0.36f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.36f, -0.28f);
     glVertex2f(-0.36f, 0.26f);
      glVertex2f(-0.28f, 0.26f);
       glVertex2f(-0.28f, -0.28f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.28f, -0.28f);
     glVertex2f(-0.28f, 0.33f);
     glVertex2f(-0.20f, 0.33f);
     glVertex2f(-0.20f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.28f);
    glVertex2f(-0.20f, 0.40f);
    glVertex2f(-0.12f, 0.40f);
     glVertex2f(-0.12f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.12f, -0.28f);
     glVertex2f(-0.12f, 0.24f);
     glVertex2f(-0.04f, 0.24f);
      glVertex2f(-0.04f, -0.28f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.04f, -0.28f);
      glVertex2f(-0.04f, 0.36f);
      glVertex2f(0.04f, 0.36f);
       glVertex2f(0.04f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.04f, -0.28f);
      glVertex2f(0.04f, 0.31f);
      glVertex2f(0.12f, 0.31f);
      glVertex2f(0.12f, -0.28f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.12f, -0.28f);
     glVertex2f(0.12f, 0.41f);
      glVertex2f(0.20f, 0.41f);
       glVertex2f(0.20f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.28f);
     glVertex2f(0.20f, 0.22f);
     glVertex2f(0.28f, 0.22f);
     glVertex2f(0.28f, -0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.28f, -0.28f);
      glVertex2f(0.28f, 0.29f);
      glVertex2f(0.36f, 0.29f);
      glVertex2f(0.36f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.36f, -0.28f);
      glVertex2f(0.36f, 0.38f);
      glVertex2f(0.44f, 0.38f);
      glVertex2f(0.44f, -0.28f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.44f, -0.28f);
    glVertex2f(0.44f, 0.35f);
    glVertex2f(0.52f, 0.35f);
    glVertex2f(0.52f, -0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.52f, -0.28f);
    glVertex2f(0.52f, 0.22f);
    glVertex2f(0.60f, 0.22f);
    glVertex2f(0.60f, -0.28f);
    glEnd();
    glBegin(GL_QUADS);//
     glVertex2f(0.60f, -0.28f);
      glVertex2f(0.60f, 0.30f);
      glVertex2f(0.68f, 0.30f);
      glVertex2f(0.68f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.68f, -0.28f);
    glVertex2f(0.68f, 0.36f);
     glVertex2f(0.76f, 0.36f);
      glVertex2f(0.76f, -0.28f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.76f, -0.28f);
      glVertex2f(0.76f, 0.40f);
       glVertex2f(0.84f, 0.40f);
        glVertex2f(0.84f, -0.28f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.84f, -0.28f);
     glVertex2f(0.84f, 0.33f);
     glVertex2f(0.92f, 0.33f);
     glVertex2f(0.92f, -0.28f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.92f, -0.28f);
    glVertex2f(0.92f, 0.39f);
    glVertex2f(1.00f, 0.39f);
    glVertex2f(1.00f, -0.28f);
     glEnd();


  //smaller buildings

                  glColor3ub(107, 195, 219); // Buildings

glBegin(GL_QUADS);
glVertex2f(-1.00f, -0.28f);
 glVertex2f(-1.00f, -0.06f);
 glVertex2f(-0.93f, -0.06f);
  glVertex2f(-0.93f, -0.28f);
  glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(-0.93f, -0.28f);
 glVertex2f(-0.93f, -0.14f);
 glVertex2f(-0.86f, -0.14f);
  glVertex2f(-0.86f, -0.28f);
  glEnd(); // short-medium
glBegin(GL_QUADS);
glVertex2f(-0.86f, -0.28f);
 glVertex2f(-0.86f, -0.01f);
 glVertex2f(-0.79f, -0.01f);
  glVertex2f(-0.79f, -0.28f);
   glEnd(); // very tall
glBegin(GL_QUADS);
 glVertex2f(-0.79f, -0.28f);
  glVertex2f(-0.79f, -0.18f);
  glVertex2f(-0.72f, -0.18f);
   glVertex2f(-0.72f, -0.28f);
   glEnd(); // short
glBegin(GL_QUADS);
glVertex2f(-0.72f, -0.28f);
glVertex2f(-0.72f, -0.09f);
 glVertex2f(-0.65f, -0.09f);
 glVertex2f(-0.65f, -0.28f);
 glEnd(); // medium-tall
glBegin(GL_QUADS);
 glVertex2f(-0.65f, -0.28f);
  glVertex2f(-0.65f, -0.03f);
   glVertex2f(-0.58f, -0.03f);
    glVertex2f(-0.58f, -0.28f);
    glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(-0.58f, -0.28f);
glVertex2f(-0.58f, -0.12f);
glVertex2f(-0.51f, -0.12f);
glVertex2f(-0.51f, -0.28f);
glEnd(); // mid
glBegin(GL_QUADS);
 glVertex2f(-0.51f, -0.28f);
 glVertex2f(-0.51f, -0.05f);
 glVertex2f(-0.44f, -0.05f);
 glVertex2f(-0.44f, -0.28f);
 glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(-0.44f, -0.28f);
glVertex2f(-0.44f, -0.19f);
glVertex2f(-0.37f, -0.19f);
 glVertex2f(-0.37f, -0.28f);
  glEnd(); // short
glBegin(GL_QUADS);
glVertex2f(-0.37f, -0.28f);
glVertex2f(-0.37f, -0.10f);
glVertex2f(-0.30f, -0.10f);
glVertex2f(-0.30f, -0.28f);
glEnd(); // medium

glBegin(GL_QUADS);
 glVertex2f(-0.30f, -0.28f);
 glVertex2f(-0.30f, -0.02f);
 glVertex2f(-0.23f, -0.02f);
  glVertex2f(-0.23f, -0.28f);
  glEnd(); // very tall
glBegin(GL_QUADS);
glVertex2f(-0.23f, -0.28f);
glVertex2f(-0.23f, -0.15f);
glVertex2f(-0.16f, -0.15f);
glVertex2f(-0.16f, -0.28f);
glEnd(); // small-medium
glBegin(GL_QUADS);
glVertex2f(-0.16f, -0.28f);
glVertex2f(-0.16f, -0.08f);
 glVertex2f(-0.09f, -0.08f);
 glVertex2f(-0.09f, -0.28f);
 glEnd(); // mid
glBegin(GL_QUADS);
 glVertex2f(-0.09f, -0.28f);
  glVertex2f(-0.09f, -0.03f);
   glVertex2f(-0.02f, -0.03f);
    glVertex2f(-0.02f, -0.28f);
     glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(-0.02f, -0.28f);
glVertex2f(-0.02f, -0.11f);
glVertex2f(0.05f, -0.11f);
glVertex2f(0.05f, -0.28f);
 glEnd(); // mid
glBegin(GL_QUADS);
 glVertex2f(0.05f, -0.28f);
 glVertex2f(0.05f, -0.07f);
  glVertex2f(0.12f, -0.07f);
  glVertex2f(0.12f, -0.28f);
  glEnd(); // medium
glBegin(GL_QUADS);
glVertex2f(0.12f, -0.28f);
glVertex2f(0.12f, -0.02f);
 glVertex2f(0.19f, -0.02f);
 glVertex2f(0.19f, -0.28f);
 glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(0.19f, -0.28f);
 glVertex2f(0.19f, -0.13f);
  glVertex2f(0.26f, -0.13f);
   glVertex2f(0.26f, -0.28f);
    glEnd(); // medium

glBegin(GL_QUADS);
glVertex2f(0.26f, -0.28f);
glVertex2f(0.26f, -0.06f);
 glVertex2f(0.33f, -0.06f);
 glVertex2f(0.33f, -0.28f);
  glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(0.33f, -0.28f);
 glVertex2f(0.33f, -0.17f);
  glVertex2f(0.40f, -0.17f);
   glVertex2f(0.40f, -0.28f);
    glEnd(); // short
glBegin(GL_QUADS);
glVertex2f(0.40f, -0.28f);
glVertex2f(0.40f, -0.11f);
 glVertex2f(0.47f, -0.11f);
  glVertex2f(0.47f, -0.28f);
   glEnd(); // medium
glBegin(GL_QUADS);
 glVertex2f(0.47f, -0.28f);
 glVertex2f(0.47f, -0.03f);
 glVertex2f(0.54f, -0.03f);
 glVertex2f(0.54f, -0.28f);
 glEnd(); // very tall
glBegin(GL_QUADS);
glVertex2f(0.54f, -0.28f);
 glVertex2f(0.54f, -0.16f);
  glVertex2f(0.61f, -0.16f);
  glVertex2f(0.61f, -0.28f);
  glEnd(); // short-medium

glBegin(GL_QUADS);
glVertex2f(0.61f, -0.28f);
glVertex2f(0.61f, -0.09f);
glVertex2f(0.68f, -0.09f);
 glVertex2f(0.68f, -0.28f);
 glEnd(); // medium
glBegin(GL_QUADS);
glVertex2f(0.68f, -0.28f);
glVertex2f(0.68f, -0.02f);
glVertex2f(0.75f, -0.02f);
glVertex2f(0.75f, -0.28f);
glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(0.75f, -0.28f);
glVertex2f(0.75f, -0.20f);
glVertex2f(0.82f, -0.20f);
glVertex2f(0.82f, -0.28f);
glEnd(); // short
glBegin(GL_QUADS);
glVertex2f(0.82f, -0.28f);
 glVertex2f(0.82f, -0.08f);
 glVertex2f(0.89f, -0.08f);
  glVertex2f(0.89f, -0.28f);
  glEnd(); // medium
glBegin(GL_QUADS);
 glVertex2f(0.89f, -0.28f);
 glVertex2f(0.89f, -0.04f);
  glVertex2f(0.96f, -0.04f);
   glVertex2f(0.96f, -0.28f);
   glEnd(); // tall
glBegin(GL_QUADS);
glVertex2f(0.96f, -0.28f);
glVertex2f(0.96f, -0.15f);
glVertex2f(1.00f, -0.15f);
glVertex2f(1.00f, -0.28f);
glEnd(); // medium-short

}



void drawWindowsR() {
    glBegin(GL_QUADS);
    glVertex2f(-0.99f, 0.20f);
    glVertex2f(-0.99f, 0.23f);
    glVertex2f(-0.98f, 0.23f);
    glVertex2f(-0.98f, 0.20f);
    glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.99f, 0.15f);
      glVertex2f(-0.99f, 0.18f);
      glVertex2f(-0.98f, 0.18f);
       glVertex2f(-0.98f, 0.15f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.97f, 0.20f);
      glVertex2f(-0.97f, 0.23f);
       glVertex2f(-0.95f, 0.23f);
        glVertex2f(-0.95f, 0.20f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.97f, 0.15f);
    glVertex2f(-0.97f, 0.18f);
    glVertex2f(-0.95f, 0.18f);
    glVertex2f(-0.95f, 0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.94f, 0.20f);
    glVertex2f(-0.94f, 0.23f);
     glVertex2f(-0.93f, 0.23f);
      glVertex2f(-0.93f, 0.20f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.94f, 0.15f);
      glVertex2f(-0.94f, 0.18f);
       glVertex2f(-0.93f, 0.18f);
        glVertex2f(-0.93f, 0.15f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.91f, 0.29f);
     glVertex2f(-0.91f, 0.32f);
      glVertex2f(-0.90f, 0.32f);
      glVertex2f(-0.90f, 0.29f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.91f, 0.24f);
      glVertex2f(-0.91f, 0.27f);
      glVertex2f(-0.90f, 0.27f);
       glVertex2f(-0.90f, 0.24f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.89f, 0.29f);
      glVertex2f(-0.89f, 0.32f);
       glVertex2f(-0.87f, 0.32f);
        glVertex2f(-0.87f, 0.29f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.89f, 0.24f);
    glVertex2f(-0.89f, 0.27f);
     glVertex2f(-0.87f, 0.27f);
      glVertex2f(-0.87f, 0.24f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.86f, 0.29f);
      glVertex2f(-0.86f, 0.32f);
       glVertex2f(-0.85f, 0.32f);
        glVertex2f(-0.85f, 0.29f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.86f, 0.24f);
      glVertex2f(-0.86f, 0.27f);
       glVertex2f(-0.85f, 0.27f);
        glVertex2f(-0.85f, 0.24f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.83f, 0.17f);
      glVertex2f(-0.83f, 0.20f);
       glVertex2f(-0.82f, 0.20f);
        glVertex2f(-0.82f, 0.17f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.83f, 0.12f);
     glVertex2f(-0.83f, 0.15f);
      glVertex2f(-0.82f, 0.15f);
       glVertex2f(-0.82f, 0.12f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.81f, 0.17f);
      glVertex2f(-0.81f, 0.20f);
      glVertex2f(-0.79f, 0.20f);
      glVertex2f(-0.79f, 0.17f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.81f, 0.12f);
     glVertex2f(-0.81f, 0.15f);
      glVertex2f(-0.79f, 0.15f);
       glVertex2f(-0.79f, 0.12f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.78f, 0.17f);
      glVertex2f(-0.78f, 0.20f);
       glVertex2f(-0.77f, 0.20f);
        glVertex2f(-0.77f, 0.17f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.78f, 0.12f);
     glVertex2f(-0.78f, 0.15f);
      glVertex2f(-0.77f, 0.15f);
       glVertex2f(-0.77f, 0.12f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.75f, 0.25f);
      glVertex2f(-0.75f, 0.28f);
       glVertex2f(-0.74f, 0.28f);
        glVertex2f(-0.74f, 0.25f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.75f, 0.20f);
      glVertex2f(-0.75f, 0.23f);
       glVertex2f(-0.74f, 0.23f);
        glVertex2f(-0.74f, 0.20f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.73f, 0.25f);
     glVertex2f(-0.73f, 0.28f);
     glVertex2f(-0.71f, 0.28f);
     glVertex2f(-0.71f, 0.25f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.73f, 0.20f);
     glVertex2f(-0.73f, 0.23f);
      glVertex2f(-0.71f, 0.23f);
      glVertex2f(-0.71f, 0.20f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.70f, 0.25f);
    glVertex2f(-0.70f, 0.28f);
    glVertex2f(-0.69f, 0.28f);
     glVertex2f(-0.69f, 0.25f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.70f, 0.20f);
    glVertex2f(-0.70f, 0.23f);
     glVertex2f(-0.69f, 0.23f);
      glVertex2f(-0.69f, 0.20f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.67f, 0.22f);
      glVertex2f(-0.67f, 0.25f);
       glVertex2f(-0.66f, 0.25f);
        glVertex2f(-0.66f, 0.22f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.67f, 0.17f);
      glVertex2f(-0.67f, 0.20f);
       glVertex2f(-0.66f, 0.20f);
        glVertex2f(-0.66f, 0.17f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.65f, 0.22f);
     glVertex2f(-0.65f, 0.25f);
     glVertex2f(-0.63f, 0.25f);
     glVertex2f(-0.63f, 0.22f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.65f, 0.17f);
      glVertex2f(-0.65f, 0.20f);
       glVertex2f(-0.63f, 0.20f);
        glVertex2f(-0.63f, 0.17f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.62f, 0.22f);
    glVertex2f(-0.62f, 0.25f);
    glVertex2f(-0.61f, 0.25f);
    glVertex2f(-0.61f, 0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.62f, 0.17f);
    glVertex2f(-0.62f, 0.20f);
    glVertex2f(-0.61f, 0.20f);
     glVertex2f(-0.61f, 0.17f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.59f, 0.34f);
      glVertex2f(-0.59f, 0.37f);
      glVertex2f(-0.58f, 0.37f);
      glVertex2f(-0.58f, 0.34f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.59f, 0.29f);
    glVertex2f(-0.59f, 0.32f);
     glVertex2f(-0.58f, 0.32f);
     glVertex2f(-0.58f, 0.29f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.57f, 0.34f);
      glVertex2f(-0.57f, 0.37f);
       glVertex2f(-0.55f, 0.37f);
        glVertex2f(-0.55f, 0.34f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.57f, 0.29f);
      glVertex2f(-0.57f, 0.32f);
       glVertex2f(-0.55f, 0.32f);
        glVertex2f(-0.55f, 0.29f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.54f, 0.34f);
      glVertex2f(-0.54f, 0.37f);
       glVertex2f(-0.53f, 0.37f);
        glVertex2f(-0.53f, 0.34f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.54f, 0.29f);
    glVertex2f(-0.54f, 0.32f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.53f, 0.29f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.51f, 0.25f);
     glVertex2f(-0.51f, 0.28f);
      glVertex2f(-0.50f, 0.28f);
       glVertex2f(-0.50f, 0.25f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.51f, 0.20f);
     glVertex2f(-0.51f, 0.23f);
      glVertex2f(-0.50f, 0.23f);
      glVertex2f(-0.50f, 0.20f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.49f, 0.25f);
     glVertex2f(-0.49f, 0.28f);
     glVertex2f(-0.47f, 0.28f);
     glVertex2f(-0.47f, 0.25f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.49f, 0.20f);
      glVertex2f(-0.49f, 0.23f);
       glVertex2f(-0.47f, 0.23f);
        glVertex2f(-0.47f, 0.20f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.46f, 0.25f);
      glVertex2f(-0.46f, 0.28f);
      glVertex2f(-0.45f, 0.28f);
       glVertex2f(-0.45f, 0.25f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.46f, 0.20f);
     glVertex2f(-0.46f, 0.23f);
     glVertex2f(-0.45f, 0.23f);
      glVertex2f(-0.45f, 0.20f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.43f, 0.37f);
     glVertex2f(-0.43f, 0.40f);
     glVertex2f(-0.42f, 0.40f);
      glVertex2f(-0.42f, 0.37f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.43f, 0.32f);
     glVertex2f(-0.43f, 0.35f);
     glVertex2f(-0.42f, 0.35f);
     glVertex2f(-0.42f, 0.32f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.41f, 0.37f);
     glVertex2f(-0.41f, 0.40f);
      glVertex2f(-0.39f, 0.40f);
      glVertex2f(-0.39f, 0.37f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.41f, 0.32f);
      glVertex2f(-0.41f, 0.35f);
       glVertex2f(-0.39f, 0.35f);
        glVertex2f(-0.39f, 0.32f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.38f, 0.37f);
     glVertex2f(-0.38f, 0.40f);
     glVertex2f(-0.37f, 0.40f);
     glVertex2f(-0.37f, 0.37f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.38f, 0.32f);
    glVertex2f(-0.38f, 0.35f);
    glVertex2f(-0.37f, 0.35f);
    glVertex2f(-0.37f, 0.32f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.35f, 0.21f);
      glVertex2f(-0.35f, 0.24f);
       glVertex2f(-0.34f, 0.24f);
       glVertex2f(-0.34f, 0.21f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.35f, 0.16f);
      glVertex2f(-0.35f, 0.19f);
       glVertex2f(-0.34f, 0.19f);
        glVertex2f(-0.34f, 0.16f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, 0.21f);
     glVertex2f(-0.33f, 0.24f);
     glVertex2f(-0.31f, 0.24f);
     glVertex2f(-0.31f, 0.21f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, 0.16f);
     glVertex2f(-0.33f, 0.19f);
     glVertex2f(-0.31f, 0.19f);
      glVertex2f(-0.31f, 0.16f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.30f, 0.21f);
     glVertex2f(-0.30f, 0.24f);
     glVertex2f(-0.29f, 0.24f);
     glVertex2f(-0.29f, 0.21f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.30f, 0.16f);
      glVertex2f(-0.30f, 0.19f);
       glVertex2f(-0.29f, 0.19f);
        glVertex2f(-0.29f, 0.16f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.27f, 0.28f);
      glVertex2f(-0.27f, 0.31f);
      glVertex2f(-0.26f, 0.31f);
      glVertex2f(-0.26f, 0.28f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.27f, 0.23f);
      glVertex2f(-0.27f, 0.26f);
      glVertex2f(-0.26f, 0.26f);
      glVertex2f(-0.26f, 0.23f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.31f);
    glVertex2f(-0.23f, 0.31f);
    glVertex2f(-0.23f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.23f);
     glVertex2f(-0.25f, 0.26f);
     glVertex2f(-0.23f, 0.26f);
     glVertex2f(-0.23f, 0.23f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.22f, 0.28f);
    glVertex2f(-0.22f, 0.31f);
    glVertex2f(-0.21f, 0.31f);
     glVertex2f(-0.21f, 0.28f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.22f, 0.23f);
      glVertex2f(-0.22f, 0.26f);
      glVertex2f(-0.21f, 0.26f);
      glVertex2f(-0.21f, 0.23f);
      glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, 0.35f);
     glVertex2f(-0.19f, 0.38f);
      glVertex2f(-0.18f, 0.38f);
       glVertex2f(-0.18f, 0.35f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, 0.30f);
    glVertex2f(-0.19f, 0.33f);
    glVertex2f(-0.18f, 0.33f);
     glVertex2f(-0.18f, 0.30f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.17f, 0.35f);
     glVertex2f(-0.17f, 0.38f);
      glVertex2f(-0.15f, 0.38f);
       glVertex2f(-0.15f, 0.35f);
       glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.17f, 0.30f);
     glVertex2f(-0.17f, 0.33f);
      glVertex2f(-0.15f, 0.33f);
       glVertex2f(-0.15f, 0.30f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.14f, 0.35f);
     glVertex2f(-0.14f, 0.38f);
      glVertex2f(-0.13f, 0.38f);
       glVertex2f(-0.13f, 0.35f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.14f, 0.30f);
    glVertex2f(-0.14f, 0.33f);
    glVertex2f(-0.13f, 0.33f);
     glVertex2f(-0.13f, 0.30f);
     glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.11f, 0.19f);
      glVertex2f(-0.11f, 0.22f);
      glVertex2f(-0.10f, 0.22f);
      glVertex2f(-0.10f, 0.19f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.11f, 0.14f);
      glVertex2f(-0.11f, 0.17f);
       glVertex2f(-0.10f, 0.17f);
        glVertex2f(-0.10f, 0.14f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.09f, 0.19f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.07f, 0.22f);
    glVertex2f(-0.07f, 0.19f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.09f, 0.14f);
    glVertex2f(-0.09f, 0.17f);
     glVertex2f(-0.07f, 0.17f);
     glVertex2f(-0.07f, 0.14f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.06f, 0.19f);
     glVertex2f(-0.06f, 0.22f);
      glVertex2f(-0.05f, 0.22f);
       glVertex2f(-0.05f, 0.19f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.06f, 0.14f);
      glVertex2f(-0.06f, 0.17f);
       glVertex2f(-0.05f, 0.17f);
        glVertex2f(-0.05f, 0.14f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.03f, 0.31f);
     glVertex2f(-0.03f, 0.34f);
     glVertex2f(-0.02f, 0.34f);
     glVertex2f(-0.02f, 0.31f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.03f, 0.26f);
     glVertex2f(-0.03f, 0.29f);
      glVertex2f(-0.02f, 0.29f);
       glVertex2f(-0.02f, 0.26f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.01f, 0.31f);
      glVertex2f(-0.01f, 0.34f);
       glVertex2f(0.01f, 0.34f);
        glVertex2f(0.01f, 0.31f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.01f, 0.29f);
    glVertex2f(0.01f, 0.29f);
     glVertex2f(0.01f, 0.26f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.02f, 0.31f);
      glVertex2f(0.02f, 0.34f);
       glVertex2f(0.03f, 0.34f);
        glVertex2f(0.03f, 0.31f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.02f, 0.26f);
      glVertex2f(0.02f, 0.29f);
       glVertex2f(0.03f, 0.29f);
        glVertex2f(0.03f, 0.26f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.05f, 0.26f);
      glVertex2f(0.05f, 0.29f);
       glVertex2f(0.06f, 0.29f);
        glVertex2f(0.06f, 0.26f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.05f, 0.21f);
      glVertex2f(0.05f, 0.24f);
       glVertex2f(0.06f, 0.24f);
        glVertex2f(0.06f, 0.21f);
         glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.07f, 0.26f);
    glVertex2f(0.07f, 0.29f);
    glVertex2f(0.09f, 0.29f);
    glVertex2f(0.09f, 0.26f);
    glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.07f, 0.21f);
      glVertex2f(0.07f, 0.24f);
       glVertex2f(0.09f, 0.24f);
        glVertex2f(0.09f, 0.21f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.10f, 0.26f);
      glVertex2f(0.10f, 0.29f);
       glVertex2f(0.11f, 0.29f);
        glVertex2f(0.11f, 0.26f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.10f, 0.21f);
      glVertex2f(0.10f, 0.24f);
       glVertex2f(0.11f, 0.24f);
        glVertex2f(0.11f, 0.21f);
        glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.13f, 0.36f);
    glVertex2f(0.13f, 0.39f);
    glVertex2f(0.14f, 0.39f);
    glVertex2f(0.14f, 0.36f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.13f, 0.31f);
     glVertex2f(0.13f, 0.34f);
     glVertex2f(0.14f, 0.34f);
     glVertex2f(0.14f, 0.31f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.36f);
     glVertex2f(0.15f, 0.39f);
      glVertex2f(0.17f, 0.39f);
       glVertex2f(0.17f, 0.36f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.15f, 0.31f);
      glVertex2f(0.15f, 0.34f);
       glVertex2f(0.17f, 0.34f);
       glVertex2f(0.17f, 0.31f);
       glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.18f, 0.36f);
      glVertex2f(0.18f, 0.39f);
       glVertex2f(0.19f, 0.39f);
        glVertex2f(0.19f, 0.36f);
         glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.18f, 0.31f);
      glVertex2f(0.18f, 0.34f);
       glVertex2f(0.19f, 0.34f);
        glVertex2f(0.19f, 0.31f);
        glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.21f, 0.17f);
      glVertex2f(0.21f, 0.20f);
      glVertex2f(0.22f, 0.20f);
      glVertex2f(0.22f, 0.17f);
      glEnd();
    glBegin(GL_QUADS);
     glVertex2f(0.21f, 0.12f);
      glVertex2f(0.21f, 0.15f);
       glVertex2f(0.22f, 0.15f);
        glVertex2f(0.22f, 0.12f);
         glEnd();
    glBegin(GL_QUADS); glVertex2f(0.23f, 0.17f); glVertex2f(0.23f, 0.20f); glVertex2f(0.25f, 0.20f); glVertex2f(0.25f, 0.17f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.23f, 0.12f); glVertex2f(0.23f, 0.15f); glVertex2f(0.25f, 0.15f); glVertex2f(0.25f, 0.12f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.26f, 0.17f); glVertex2f(0.26f, 0.20f); glVertex2f(0.27f, 0.20f); glVertex2f(0.27f, 0.17f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.26f, 0.12f); glVertex2f(0.26f, 0.15f); glVertex2f(0.27f, 0.15f); glVertex2f(0.27f, 0.12f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.29f, 0.24f); glVertex2f(0.29f, 0.27f); glVertex2f(0.30f, 0.27f); glVertex2f(0.30f, 0.24f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.29f, 0.19f); glVertex2f(0.29f, 0.22f); glVertex2f(0.30f, 0.22f); glVertex2f(0.30f, 0.19f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.31f, 0.24f); glVertex2f(0.31f, 0.27f); glVertex2f(0.33f, 0.27f); glVertex2f(0.33f, 0.24f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.31f, 0.19f); glVertex2f(0.31f, 0.22f); glVertex2f(0.33f, 0.22f); glVertex2f(0.33f, 0.19f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.34f, 0.24f); glVertex2f(0.34f, 0.27f); glVertex2f(0.35f, 0.27f); glVertex2f(0.35f, 0.24f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.34f, 0.19f); glVertex2f(0.34f, 0.22f); glVertex2f(0.35f, 0.22f); glVertex2f(0.35f, 0.19f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.37f, 0.33f); glVertex2f(0.37f, 0.36f); glVertex2f(0.38f, 0.36f); glVertex2f(0.38f, 0.33f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.37f, 0.28f); glVertex2f(0.37f, 0.31f); glVertex2f(0.38f, 0.31f); glVertex2f(0.38f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.39f, 0.33f); glVertex2f(0.39f, 0.36f); glVertex2f(0.41f, 0.36f); glVertex2f(0.41f, 0.33f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.39f, 0.28f); glVertex2f(0.39f, 0.31f); glVertex2f(0.41f, 0.31f); glVertex2f(0.41f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.42f, 0.33f); glVertex2f(0.42f, 0.36f); glVertex2f(0.43f, 0.36f); glVertex2f(0.43f, 0.33f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.42f, 0.28f); glVertex2f(0.42f, 0.31f); glVertex2f(0.43f, 0.31f); glVertex2f(0.43f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.45f, 0.30f); glVertex2f(0.45f, 0.33f); glVertex2f(0.46f, 0.33f); glVertex2f(0.46f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.45f, 0.25f); glVertex2f(0.45f, 0.28f); glVertex2f(0.46f, 0.28f); glVertex2f(0.46f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.47f, 0.30f); glVertex2f(0.47f, 0.33f); glVertex2f(0.49f, 0.33f); glVertex2f(0.49f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.47f, 0.25f); glVertex2f(0.47f, 0.28f); glVertex2f(0.49f, 0.28f); glVertex2f(0.49f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.50f, 0.30f); glVertex2f(0.50f, 0.33f); glVertex2f(0.51f, 0.33f); glVertex2f(0.51f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.50f, 0.25f); glVertex2f(0.50f, 0.28f); glVertex2f(0.51f, 0.28f); glVertex2f(0.51f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.53f, 0.17f); glVertex2f(0.53f, 0.20f); glVertex2f(0.54f, 0.20f); glVertex2f(0.54f, 0.17f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.53f, 0.12f); glVertex2f(0.53f, 0.15f); glVertex2f(0.54f, 0.15f); glVertex2f(0.54f, 0.12f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.55f, 0.17f); glVertex2f(0.55f, 0.20f); glVertex2f(0.57f, 0.20f); glVertex2f(0.57f, 0.17f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.55f, 0.12f); glVertex2f(0.55f, 0.15f); glVertex2f(0.57f, 0.15f); glVertex2f(0.57f, 0.12f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.58f, 0.17f); glVertex2f(0.58f, 0.20f); glVertex2f(0.59f, 0.20f); glVertex2f(0.59f, 0.17f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.58f, 0.12f); glVertex2f(0.58f, 0.15f); glVertex2f(0.59f, 0.15f); glVertex2f(0.59f, 0.12f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.61f, 0.25f); glVertex2f(0.61f, 0.28f); glVertex2f(0.62f, 0.28f); glVertex2f(0.62f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.61f, 0.20f); glVertex2f(0.61f, 0.23f); glVertex2f(0.62f, 0.23f); glVertex2f(0.62f, 0.20f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.63f, 0.25f); glVertex2f(0.63f, 0.28f); glVertex2f(0.65f, 0.28f); glVertex2f(0.65f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.63f, 0.20f); glVertex2f(0.63f, 0.23f); glVertex2f(0.65f, 0.23f); glVertex2f(0.65f, 0.20f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.66f, 0.25f); glVertex2f(0.66f, 0.28f); glVertex2f(0.67f, 0.28f); glVertex2f(0.67f, 0.25f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.66f, 0.20f); glVertex2f(0.66f, 0.23f); glVertex2f(0.67f, 0.23f); glVertex2f(0.67f, 0.20f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.69f, 0.31f); glVertex2f(0.69f, 0.34f); glVertex2f(0.70f, 0.34f); glVertex2f(0.70f, 0.31f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.69f, 0.26f); glVertex2f(0.69f, 0.29f); glVertex2f(0.70f, 0.29f); glVertex2f(0.70f, 0.26f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.71f, 0.31f); glVertex2f(0.71f, 0.34f); glVertex2f(0.73f, 0.34f); glVertex2f(0.73f, 0.31f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.71f, 0.26f); glVertex2f(0.71f, 0.29f); glVertex2f(0.73f, 0.29f); glVertex2f(0.73f, 0.26f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.74f, 0.31f); glVertex2f(0.74f, 0.34f); glVertex2f(0.75f, 0.34f); glVertex2f(0.75f, 0.31f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.74f, 0.26f); glVertex2f(0.74f, 0.29f); glVertex2f(0.75f, 0.29f); glVertex2f(0.75f, 0.26f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.77f, 0.35f); glVertex2f(0.77f, 0.38f); glVertex2f(0.78f, 0.38f); glVertex2f(0.78f, 0.35f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.77f, 0.30f); glVertex2f(0.77f, 0.33f); glVertex2f(0.78f, 0.33f); glVertex2f(0.78f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.79f, 0.35f); glVertex2f(0.79f, 0.38f); glVertex2f(0.81f, 0.38f); glVertex2f(0.81f, 0.35f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.79f, 0.30f); glVertex2f(0.79f, 0.33f); glVertex2f(0.81f, 0.33f); glVertex2f(0.81f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.82f, 0.35f); glVertex2f(0.82f, 0.38f); glVertex2f(0.83f, 0.38f); glVertex2f(0.83f, 0.35f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.82f, 0.30f); glVertex2f(0.82f, 0.33f); glVertex2f(0.83f, 0.33f); glVertex2f(0.83f, 0.30f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.85f, 0.28f); glVertex2f(0.85f, 0.31f); glVertex2f(0.86f, 0.31f); glVertex2f(0.86f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.85f, 0.23f); glVertex2f(0.85f, 0.26f); glVertex2f(0.86f, 0.26f); glVertex2f(0.86f, 0.23f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.87f, 0.28f); glVertex2f(0.87f, 0.31f); glVertex2f(0.89f, 0.31f); glVertex2f(0.89f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.87f, 0.23f); glVertex2f(0.87f, 0.26f); glVertex2f(0.89f, 0.26f); glVertex2f(0.89f, 0.23f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.90f, 0.28f); glVertex2f(0.90f, 0.31f); glVertex2f(0.91f, 0.31f); glVertex2f(0.91f, 0.28f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.90f, 0.23f); glVertex2f(0.90f, 0.26f); glVertex2f(0.91f, 0.26f); glVertex2f(0.91f, 0.23f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.93f, 0.34f); glVertex2f(0.93f, 0.37f); glVertex2f(0.94f, 0.37f); glVertex2f(0.94f, 0.34f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.93f, 0.29f); glVertex2f(0.93f, 0.32f); glVertex2f(0.94f, 0.32f); glVertex2f(0.94f, 0.29f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.95f, 0.34f); glVertex2f(0.95f, 0.37f); glVertex2f(0.97f, 0.37f); glVertex2f(0.97f, 0.34f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.95f, 0.29f); glVertex2f(0.95f, 0.32f); glVertex2f(0.97f, 0.32f); glVertex2f(0.97f, 0.29f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.98f, 0.34f); glVertex2f(0.98f, 0.37f); glVertex2f(0.99f, 0.37f); glVertex2f(0.99f, 0.34f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.98f, 0.29f); glVertex2f(0.98f, 0.32f); glVertex2f(0.99f, 0.32f); glVertex2f(0.99f, 0.29f); glEnd();
} // end of drawWindows()



void containerRedR()
{
    glPushMatrix();

    glTranslatef(-1.53,0.17, 0.0f);

    glScalef(1.26,1.8,0);

  glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();


}
void containerBlueR()
{
    glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();




}
void containerOrangeR()
{

    glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();


}
void containerWhiteR()
{
    glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();
glPopMatrix();
}
void containerRed1R()
{
    glPushMatrix();

    glTranslatef(-1.60,0.31, 0.0f);

    glScalef(1.26,1.8,0);

  glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();


}
void containerBlue1R()
{
    glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();




}
void containerOrange1R()
{

    glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();


}
void containerWhite1R()
{
    glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();
glPopMatrix();
}
void containerRed2R()
{
    glPushMatrix();

    glTranslatef(-1.61,0.455, 0.0f);

    glScalef(1.26,1.8,0);

  glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();


}
void containerBlue2R()
{
    glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();




}
void containerOrange2R()
{

    glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();

glPopMatrix();
}
void containerOrange3R()
{
    glPushMatrix();

    glTranslatef(-1.82,0.60, 0.0f);

    glScalef(1.26,1.8,0);

    glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();


}
void containerWhite3R()
{
    glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();
glPopMatrix();
}
void containerBlue4R()
{
    glPushMatrix();

    glTranslatef(-1.63,0.74, 0.0f);

    glScalef(1.26,1.8,0);

    glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();
glPopMatrix();



}
//crane rope
void roadmiddleR()
{

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-1,-0.71);
    glVertex2f(1,-0.71);
     glVertex2f(1,-0.8);
     glVertex2f(-1,-0.8);
    glEnd();

}

void craneBaseR()
{
    // Crane Base
    glBegin(GL_QUADS);
    glColor3ub(154, 144, 137);
    glVertex2f(-1,-0.32);
    glVertex2f(0.06,-0.34);
     glVertex2f(0.06,-0.5);
     glVertex2f(-1,-0.5);
    glEnd();

   //Crane base lining

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-1,-0.37);
    glVertex2f(0.06,-0.37);
    glVertex2f(0.06,-0.4);
    glVertex2f(-1,-0.4);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.95,-0.4);
    glVertex2f(-0.93,-0.4);
    glVertex2f(-0.93,-0.5);
    glVertex2f(-0.95,-0.5);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.87,-0.4);
    glVertex2f(-0.85,-0.4);
    glVertex2f(-0.85,-0.5);
    glVertex2f(-0.87,-0.5);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.79,-0.4);
    glVertex2f(-0.77,-0.4);
    glVertex2f(-0.77,-0.5);
    glVertex2f(-0.79,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.71,-0.4);
    glVertex2f(-0.69,-0.4);
    glVertex2f(-0.69,-0.5);
    glVertex2f(-0.71,-0.5);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.63,-0.4);
    glVertex2f(-0.61,-0.4);
    glVertex2f(-0.61,-0.5);
    glVertex2f(-0.63,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.57,-0.4);
    glVertex2f(-0.55,-0.4);
    glVertex2f(-0.55,-0.5);
    glVertex2f(-0.57,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.49,-0.4);
    glVertex2f(-0.47,-0.4);
    glVertex2f(-0.47,-0.5);
    glVertex2f(-0.49,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.41,-0.4);
    glVertex2f(-0.39,-0.4);
    glVertex2f(-0.39,-0.5);
    glVertex2f(-0.41,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.33,-0.4);
    glVertex2f(-0.31,-0.4);
    glVertex2f(-0.31,-0.5);
    glVertex2f(-0.33,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.25,-0.4);
    glVertex2f(-0.23,-0.4);
    glVertex2f(-0.23,-0.5);
    glVertex2f(-0.25,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.17,-0.4);
    glVertex2f(-0.15,-0.4);
    glVertex2f(-0.15,-0.5);
    glVertex2f(-0.17,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(-0.09,-0.4);
    glVertex2f(-0.07,-0.4);
    glVertex2f(-0.07,-0.5);
    glVertex2f(-0.09,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 119, 117);
    glVertex2f(0.0,-0.4);
    glVertex2f(0.02,-0.4);
    glVertex2f(0.02,-0.5);
    glVertex2f(0.0,-0.5);
    glEnd();

    //crane spreader

    glBegin(GL_QUADS);
    glColor3ub(45, 117, 199);
    glVertex2f(-0.84,-0.34);
    glVertex2f(-0.84,-0.24);
    glVertex2f(-0.68,-0.24);
    glVertex2f(-0.68,-0.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(45, 117, 199);
    glVertex2f(-0.1,-0.34);
    glVertex2f(-0.1,-0.24);
    glVertex2f(0.04,-0.24);
    glVertex2f(0.04,-0.34);
    glEnd();



}

void craneLowerR()
{
    //crane lower two part

    glBegin(GL_QUADS);
    glColor3ub(24, 81, 152);
    glVertex2f(-0.84,-0.34);
    glVertex2f(-0.84,-0.28);
    glVertex2f(-0.68,-0.28);
    glVertex2f(-0.68,-0.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(24, 81, 152);
    glVertex2f(-0.12,-0.34);
    glVertex2f(-0.12,-0.28);
    glVertex2f(0.04,-0.28);
    glVertex2f(0.04,-0.34);
    glEnd();
//crane  left
    glBegin(GL_QUADS);
    glColor3ub(45, 117, 199);
    glVertex2f(-0.8,-0.28);
    glVertex2f(-0.8,0.6);
    glVertex2f(-0.72,0.6);
    glVertex2f(-0.76,-0.28);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(26, 77, 143);
    glVertex2f(-0.76,-0.28);
    glVertex2f(-0.72,0.6);
    glVertex2f(-0.7,0.6);
    glVertex2f(-0.74,-0.28);
    glEnd();

   // crane right
    glBegin(GL_QUADS);
    glColor3ub(45, 117, 199);
    glVertex2f(0,-0.28);
    glVertex2f(0,0.6);
    glVertex2f(-0.08,0.6);
    glVertex2f(-0.04,-0.28);
    glEnd();

glBegin(GL_QUADS);
    glColor3ub(26, 77, 143);
    glVertex2f(-0.04,-0.28);
    glVertex2f(-0.08,0.6);
    glVertex2f(-0.1,0.6);
    glVertex2f(-0.06,-0.28);
    glEnd();

    //crane upper
     glBegin(GL_QUADS);
    glColor3ub(45, 117, 199);
    glVertex2f(-0.86,0.7);
    glVertex2f(0.06,0.7);
    glVertex2f(0.06,0.6);
    glVertex2f(-0.86,0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(26, 77, 143);
    glVertex2f(-0.8,0.56);
    glVertex2f(-0.8,0.6);
    glVertex2f(0.0,0.6);
    glVertex2f(0.0,0.56);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(20, 57, 114);
    glVertex2f(-0.55,0.56);
    glVertex2f(-0.25,0.56);
    glVertex2f(-0.27,0.51);
    glVertex2f(-0.53,0.51);
    glEnd();
}

void skyR()
{
    // Sky
    glBegin(GL_QUADS);
    glColor3ub(176,216, 242);
    glVertex2f(-1,1);
     glVertex2f(1,1);
      glColor3f(0.957f, 0.969f, 0.875f);
     glVertex2f(1,-0.5);
     glVertex2f(-1,-0.5);
    glEnd();

}

void RoadR()
{
     // Road
    glBegin(GL_QUADS);
    glColor3ub(115, 118, 133);
    glVertex2f(-1,-0.5); glVertex2f(1,-0.5); glVertex2f(1,-1); glVertex2f(-1,-1);
    glEnd();

}

void waterR()
{
    // Water
    glBegin(GL_QUADS);
    glColor3ub(44, 161, 222);
    glVertex2f(-1,-0.27); glVertex2f(1,-0.27); glVertex2f(1,-0.5); glVertex2f(-1,-0.5);
    glEnd();

}


void display3() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


     skyR();
     RoadR();
     waterR();
    // Clouds
     craneBaseR();
    cloud1R();
    cloud2R();
    cloud3R();

    buildingR();
    drawWindowsR();
    BoatR();
    containerRedR();
    containerBlueR();
    containerOrangeR();
    containerWhiteR();
    containerRed1R();
    containerBlue1R();
    containerOrange1R();
    containerWhite1R();
    containerRed2R();
    containerBlue2R();
    containerOrange2R();
    containerOrange3R();
    containerWhite3R();
    containerBlue4R();

     craneLowerR();
     ropeR();

     craneRopeR();

    roadmiddleR();
    truckR();
    truckBoxR(0,0.5);

    truck2R();
    truckBox2R(0, 0.5);

    //ropeR();

    glFlush();
}



////Faisal's Part////

void updateF(int value)
 {
     flag4 = true;

     if(shipPositionF <-1.6)
        shipPositionF = 1.6f;
    shipPositionF -= shipSpeedF;

    if(cloud1positionF1 >1.8)
        cloud1positionF1 = -0.8f;
    cloud1positionF1 += cloud1speedF1;

    if(cloud2positionF2 >2)
        cloud2positionF2 = -2.0f;
    cloud2positionF2 += cloud2speedF2;

    if(cloud3positionF3 >1.4)
        cloud3positionF3 = -2.0f;
    cloud3positionF3 += cloud3speedF3;



	glutPostRedisplay();
	glutTimerFunc(60, updateF, 0);
}

void skyF()
{

    glBegin(GL_POLYGON);
    glColor3f(0.537f, 0.858f, 1.0f);
    glVertex2f(-1.0f, -0.387f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.387f);
    glEnd();
}
void seaF()
{
	glBegin(GL_POLYGON);
    glColor3ub(33, 150, 243);
    glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,-0.0387f);
	glVertex2f(1.0f,-0.0387f);
	glVertex2f(1.0f,-1.0f);
	glEnd();
}

void mountain()
{
    glBegin(GL_POLYGON);
    glColor3f(0.50f,0.705f,0.415f);
    glVertex2f(-1.0f,-0.387f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(1.0f,-0.387f);
	glEnd();
}

void cloudF()
{
    //1
    int i1;

	GLfloat x1=-0.53f; GLfloat y1=0.52f; GLfloat radius1 =.07f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	//2

int i2;
	GLfloat x2=-0.46f; GLfloat y2=0.58f; GLfloat radius2 =.07f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();
	//3
	int i3;
	GLfloat x3=-0.37f; GLfloat y3=0.51f; GLfloat radius3 =.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();
	//4
	int i4;
	GLfloat x4=-0.27f; GLfloat y4=0.5f; GLfloat radius4 =.05f;
	int triangleAmount4= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
                        y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4)) );
		}
	glEnd();
	//5
	int i5;
	GLfloat x5=-0.46f; GLfloat y5=0.48f; GLfloat radius5 =.05f;
	int triangleAmount5= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f( x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
                        y5 + (1.5*radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
		}
	glEnd();

}
void cloud1F()
{
    //1

    int i1;

	GLfloat x1=-0.53f; GLfloat y1=0.52f; GLfloat radius1 =.07f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
	glEnd();
	//2

int i2;
	GLfloat x2=-0.46f; GLfloat y2=0.58f; GLfloat radius2 =.07f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
	glEnd();
	//3
	int i3;
	GLfloat x3=-0.37f; GLfloat y3=0.51f; GLfloat radius3 =.09f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
	glEnd();

	//5
	int i5;
	GLfloat x5=-0.46f; GLfloat y5=0.48f; GLfloat radius5 =.05f;
	int triangleAmount5= 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f( x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
                        y5 + (1.5*radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
		}
	glEnd();

}

void shipF()
{
    glPushMatrix();

   glTranslatef(shipPositionF,0.05, 0.0f);

    glScalef(0.8,0.78,0);

    //blue
    glBegin(GL_POLYGON);
	glColor3ub(156,22,39);
    glVertex2f(-.91f, -.38f);

	glVertex2f(-.87f, -.44f);
	glVertex2f(.388f, -.44f);
	glVertex2f(.387f, -.43f);
	glVertex2f(.38f, -.42f);
	glVertex2f(.36f, -.4f);
	glVertex2f(.36f, -.38f);
	glEnd();

	//black
	glBegin(GL_POLYGON);
	glColor3ub(156,22,39);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.91f, -.38f);
    glVertex2f(.36f, -.38f);
	glVertex2f(.369f, -.38f);
	glVertex2f(.37f, -.37f);
	glVertex2f(.45f, -.35f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(-.93f, -.26f);
	glVertex2f(-.92f, -.35f);
    glVertex2f(-.53f, -.35f);
    glVertex2f(-.57f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(52,42,56);
	glVertex2f(.1f, -.26f);
	glVertex2f(.069f, -.35f);
    glVertex2f(.45f, -.35f);
    glVertex2f(.47f, -.26f);
	glEnd();

	//in water
	glBegin(GL_POLYGON);
	glColor3ub(101,103,143);
	glVertex2f(-.87f, -.44f);
	glVertex2f(-.81f, -.54f);
    glVertex2f(.34f, -.54f);
    glVertex2f(.388f, -.44f);
	glEnd();

	//cr

	glBegin(GL_POLYGON);
	glColor3ub(206,206,206);

	glVertex2f(.11f, -.07f);
    glVertex2f(.1f, -.05f);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.26f);
    glVertex2f(.11f, -.26f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(156,22,39);
    glVertex2f(.1f, -.03f);
    glVertex2f(.27f, -.03f);
    glVertex2f(.27f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(156,22,39);
    glVertex2f(.1f, .02f);
    glVertex2f(.17f, .02f);
    glVertex2f(.19f, -.0f);
    glVertex2f(.1f, -.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(226,226,226);
    glVertex2f(.11f, -.26f);
    glVertex2f(.11f, -.1f);
    glVertex2f(.17f, -.1f);
    glVertex2f(.17f, -.19f);
    glVertex2f(.29f, -.19f);
     glVertex2f(.29f, -.26f);
	glEnd();

	//container1

    glTranslatef(0.62,0.12, 0.0f);
	glScalef(-1.36,1.7,0);

	 glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();
//blue
	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();
//orange
glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();
//white
	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();

//container2

glTranslatef(1.315,0.165, 0.0f);
	glScalef(-1.16,1.3,0);

	 glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
	 glVertex2f(0.4f, -.2f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.405f, -.21f);
	glVertex2f(0.405f, -.277f);
	glVertex2f(0.41f, -.277f);
	glVertex2f(.41f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
	 glVertex2f(0.415f, -.21f);
	glVertex2f(0.415f, -.277f);
	glVertex2f(0.42f, -.277f);
	glVertex2f(.42f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.425f, -.21f);
	glVertex2f(0.425f, -.277f);
	glVertex2f(0.43f, -.277f);
	glVertex2f(.43f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.435f, -.21f);
	glVertex2f(0.435f, -.277f);
	glVertex2f(0.44f, -.277f);
	glVertex2f(.44f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.445f, -.21f);
	glVertex2f(0.445f, -.277f);
	glVertex2f(0.45f, -.277f);
	glVertex2f(.45f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.455f, -.21f);
	glVertex2f(0.455f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.46f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.465f, -.21f);
	glVertex2f(0.465f, -.277f);
	glVertex2f(0.47f, -.277f);
	glVertex2f(.47f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.475f, -.21f);
	glVertex2f(0.475f, -.277f);
	glVertex2f(0.48f, -.277f);
	glVertex2f(.48f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.485f, -.21f);
	glVertex2f(0.485f, -.277f);
	glVertex2f(0.49f, -.277f);
	glVertex2f(.49f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.495f, -.21f);
	glVertex2f(0.495f, -.277f);
	glVertex2f(0.5f, -.277f);
	glVertex2f(.5f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.505f, -.21f);
	glVertex2f(0.505f, -.277f);
	glVertex2f(0.51f, -.277f);
	glVertex2f(.51f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(202,64,84);
    glVertex2f(0.515f, -.21f);
	glVertex2f(0.515f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.52f, -.2f);
	glEnd();
//blue
	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.405f, -.28f);
	glVertex2f(0.4f, -.277f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(.455f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(179,44,61);
    glVertex2f(0.465f, -.28f);
	glVertex2f(0.46f, -.277f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(.515f, -.28f);
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.52f, -.2f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.525f, -.21f);
	glVertex2f(0.525f, -.277f);
	glVertex2f(0.53f, -.277f);
	glVertex2f(.53f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.535f, -.21f);
	glVertex2f(0.535f, -.277f);
	glVertex2f(0.54f, -.277f);
	glVertex2f(.54f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.545f, -.21f);
	glVertex2f(0.545f, -.277f);
	glVertex2f(0.55f, -.277f);
	glVertex2f(.55f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.555f, -.21f);
	glVertex2f(0.555f, -.277f);
	glVertex2f(0.56f, -.277f);
	glVertex2f(.56f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.565f, -.21f);
	glVertex2f(0.565f, -.277f);
	glVertex2f(0.57f, -.277f);
	glVertex2f(.57f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.575f, -.21f);
	glVertex2f(0.575f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.58f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.585f, -.21f);
	glVertex2f(0.585f, -.277f);
	glVertex2f(0.59f, -.277f);
	glVertex2f(.59f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.595f, -.21f);
	glVertex2f(0.595f, -.277f);
	glVertex2f(0.6f, -.277f);
	glVertex2f(.6f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.605f, -.21f);
	glVertex2f(0.605f, -.277f);
	glVertex2f(0.61f, -.277f);
	glVertex2f(.61f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.615f, -.21f);
	glVertex2f(0.615f, -.277f);
	glVertex2f(0.62f, -.277f);
	glVertex2f(.62f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.625f, -.21f);
	glVertex2f(0.625f, -.277f);
	glVertex2f(0.63f, -.277f);
	glVertex2f(.63f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(85,120,207);
    glVertex2f(0.635f, -.21f);
	glVertex2f(0.635f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.64f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.525f, -.28f);
	glVertex2f(0.52f, -.277f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(.575f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(66,96,175);
    glVertex2f(0.585f, -.28f);
	glVertex2f(0.58f, -.277f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(.635f, -.28f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();

//container3

glTranslatef(1.33,0.08, 0.0f);
	glScalef(-1.006,1,0);


//orange
glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.64f, -.2f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.645f, -.21f);
	glVertex2f(0.645f, -.277f);
	glVertex2f(0.65f, -.277f);
	glVertex2f(.65f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.655f, -.21f);
	glVertex2f(0.655f, -.277f);
	glVertex2f(0.66f, -.277f);
	glVertex2f(.66f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.665f, -.21f);
	glVertex2f(0.665f, -.277f);
	glVertex2f(0.67f, -.277f);
	glVertex2f(.67f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.675f, -.21f);
	glVertex2f(0.675f, -.277f);
	glVertex2f(0.68f, -.277f);
	glVertex2f(.68f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.685f, -.21f);
	glVertex2f(0.685f, -.277f);
	glVertex2f(0.69f, -.277f);
	glVertex2f(.69f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.695f, -.21f);
	glVertex2f(0.695f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.7f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.705f, -.21f);
	glVertex2f(0.705f, -.277f);
	glVertex2f(0.71f, -.277f);
	glVertex2f(.71f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.715f, -.21f);
	glVertex2f(0.715f, -.277f);
	glVertex2f(0.72f, -.277f);
	glVertex2f(.72f, -.2f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.725f, -.21f);
	glVertex2f(0.725f, -.277f);
	glVertex2f(0.73f, -.277f);
	glVertex2f(.73f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.735f, -.21f);
	glVertex2f(0.735f, -.277f);
	glVertex2f(0.74f, -.277f);
	glVertex2f(.74f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.745f, -.21f);
	glVertex2f(0.745f, -.277f);
	glVertex2f(0.75f, -.277f);
	glVertex2f(.75f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(221,129,86);
    glVertex2f(0.755f, -.21f);
	glVertex2f(0.755f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.76f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.645f, -.28f);
	glVertex2f(0.64f, -.277f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(.695f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(195,102,60);
    glVertex2f(0.705f, -.28f);
	glVertex2f(0.7f, -.277f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(.755f, -.28f);
	glEnd();
//white
	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.76f, -.2f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.765f, -.21f);
	glVertex2f(0.765f, -.277f);
	glVertex2f(0.77f, -.277f);
	glVertex2f(.77f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.775f, -.21f);
	glVertex2f(0.775f, -.277f);
	glVertex2f(0.78f, -.277f);
	glVertex2f(.78f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.785f, -.21f);
	glVertex2f(0.785f, -.277f);
	glVertex2f(0.79f, -.277f);
	glVertex2f(.79f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.795f, -.21f);
	glVertex2f(0.795f, -.277f);
	glVertex2f(0.8f, -.277f);
	glVertex2f(.8f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.805f, -.21f);
	glVertex2f(0.805f, -.277f);
	glVertex2f(0.81f, -.277f);
	glVertex2f(.81f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.815f, -.21f);
	glVertex2f(0.815f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.82f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.825f, -.21f);
	glVertex2f(0.825f, -.277f);
	glVertex2f(0.83f, -.277f);
	glVertex2f(.83f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.835f, -.21f);
	glVertex2f(0.835f, -.277f);
	glVertex2f(0.84f, -.277f);
	glVertex2f(.84f, -.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.845f, -.21f);
	glVertex2f(0.845f, -.277f);
	glVertex2f(0.85f, -.277f);
	glVertex2f(.85f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.855f, -.21f);
	glVertex2f(0.855f, -.277f);
	glVertex2f(0.86f, -.277f);
	glVertex2f(.86f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.865f, -.21f);
	glVertex2f(0.865f, -.277f);
	glVertex2f(0.87f, -.277f);
	glVertex2f(.87f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(228,227,230);
    glVertex2f(0.875f, -.21f);
	glVertex2f(0.875f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.88f, -.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.765f, -.28f);
	glVertex2f(0.76f, -.277f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(.815f, -.28f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(201,204,207);
    glVertex2f(0.825f, -.28f);
	glVertex2f(0.82f, -.277f);
	glVertex2f(0.88f, -.277f);
	glVertex2f(.875f, -.28f);
	glEnd();

    glPopMatrix();


}

void Hill()

{
glPushMatrix();

    glTranslatef(-0.12,0, 0);

    glScalef(1.0, 1.2, 0);
    glBegin(GL_POLYGON);
    glColor3ub(43, 132, 62);
    glVertex2f(-1.00f, 0.0f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.90f, 0.08f);
    glVertex2f(-0.85f, 0.10f);
    glVertex2f(-0.80f, 0.12f);
    glVertex2f(-0.75f, 0.14f);
    glVertex2f(-0.70f, 0.17f);
    glVertex2f(-0.65f, 0.19f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-0.55f, 0.23f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.45f, 0.26f);
    glVertex2f(-0.40f, 0.27f);
    glVertex2f(-0.35f, 0.26f);
    glVertex2f(-0.30f, 0.25f);
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.20f, 0.22f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.10f, 0.20f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f( 0.00f, 0.16f);
    glVertex2f( 0.05f, 0.14f);
    glVertex2f( 0.10f, 0.13f);
    glVertex2f( 0.15f, 0.11f);
    glVertex2f( 0.20f, 0.09f);
    glVertex2f( 0.25f, 0.07f);
    glVertex2f( 0.30f, 0.06f);
    glVertex2f( 0.35f, 0.05f);
    glVertex2f( 0.40f, 0.03f);
    glVertex2f( 0.45f, 0.02f);
    glVertex2f( 0.50f, 0.01f);
    glVertex2f( 0.55f, 0.005f);
    glVertex2f( 0.60f, 0.003f);
    glVertex2f( 0.65f, 0.002f);
    glVertex2f( 0.70f, 0.001f);
    glVertex2f( 0.75f, 0.0f);
    glVertex2f( 0.80f, 0.0f);
    glVertex2f( 0.85f, 0.0f);
    glVertex2f( 0.90f, 0.0f);
    glVertex2f( 0.95f, 0.0f);
    glVertex2f( 1.00f, 0.0f);
    glEnd();
    glPopMatrix();

}
void Hill2()

{
glPushMatrix();

    glTranslatef(1.02,0, 0);

    glScalef(1.0, 1, 0);

    glBegin(GL_POLYGON);
    glColor3ub(43, 132, 62);
    glVertex2f(-1.00f, 0.0f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.90f, 0.08f);
    glVertex2f(-0.85f, 0.10f);
    glVertex2f(-0.80f, 0.12f);
    glVertex2f(-0.75f, 0.14f);
    glVertex2f(-0.70f, 0.17f);
    glVertex2f(-0.65f, 0.19f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-0.55f, 0.23f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.45f, 0.26f);
    glVertex2f(-0.40f, 0.27f);
    glVertex2f(-0.35f, 0.26f);
    glVertex2f(-0.30f, 0.25f);
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.20f, 0.22f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.10f, 0.20f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f( 0.00f, 0.16f);
    glVertex2f( 0.05f, 0.14f);
    glVertex2f( 0.10f, 0.13f);
    glVertex2f( 0.15f, 0.11f);
    glVertex2f( 0.20f, 0.09f);
    glVertex2f( 0.25f, 0.07f);
    glVertex2f( 0.30f, 0.06f);
    glVertex2f( 0.35f, 0.05f);
    glVertex2f( 0.40f, 0.03f);
    glVertex2f( 0.45f, 0.02f);
    glVertex2f( 0.50f, 0.01f);
    glVertex2f( 0.55f, 0.005f);
    glVertex2f( 0.60f, 0.003f);
    glVertex2f( 0.65f, 0.002f);
    glVertex2f( 0.70f, 0.001f);
    glVertex2f( 0.75f, 0.0f);
    glVertex2f( 0.80f, 0.0f);
    glVertex2f( 0.85f, 0.0f);
    glVertex2f( 0.90f, 0.0f);
    glVertex2f( 0.95f, 0.0f);
    glVertex2f( 1.00f, 0.0f);
    glEnd();
    glPopMatrix();

}
void Hill3()

{
    glPushMatrix();

    glTranslatef(0.40,0, 0);

    glScalef(0.90, 1.2, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.305f, 0.705f, 0.752f);
    glVertex2f(-1.00f, 0.0f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.90f, 0.08f);
    glVertex2f(-0.85f, 0.10f);
    glVertex2f(-0.80f, 0.12f);
    glVertex2f(-0.75f, 0.14f);
    glVertex2f(-0.70f, 0.17f);
    glVertex2f(-0.65f, 0.19f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-0.55f, 0.23f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.45f, 0.26f);
    glVertex2f(-0.40f, 0.27f);
    glVertex2f(-0.35f, 0.26f);
    glVertex2f(-0.30f, 0.25f);
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.20f, 0.22f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.10f, 0.20f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f( 0.00f, 0.16f);
    glVertex2f( 0.05f, 0.14f);
    glVertex2f( 0.10f, 0.13f);
    glVertex2f( 0.15f, 0.11f);
    glVertex2f( 0.20f, 0.09f);
    glVertex2f( 0.25f, 0.07f);
    glVertex2f( 0.30f, 0.06f);
    glVertex2f( 0.35f, 0.05f);
    glVertex2f( 0.40f, 0.03f);
    glVertex2f( 0.45f, 0.02f);
    glVertex2f( 0.50f, 0.01f);
    glVertex2f( 0.55f, 0.005f);
    glVertex2f( 0.60f, 0.003f);
    glVertex2f( 0.65f, 0.002f);
    glVertex2f( 0.70f, 0.001f);
    glVertex2f( 0.75f, 0.0f);
    glVertex2f( 0.80f, 0.0f);
    glVertex2f( 0.85f, 0.0f);
    glVertex2f( 0.90f, 0.0f);
    glVertex2f( 0.95f, 0.0f);
    glVertex2f( 1.00f, 0.0f);
    glEnd();
    glPopMatrix();

}
void Hill4()//left most hill

{
    glPushMatrix();

    glTranslatef(-0.6,0.0, 0);

    glScalef(0.90, 1.2, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.305f, 0.705f, 0.752f);
    glVertex2f(-1.00f, 0.0f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.90f, 0.08f);
    glVertex2f(-0.85f, 0.10f);
    glVertex2f(-0.80f, 0.12f);
    glVertex2f(-0.75f, 0.14f);
    glVertex2f(-0.70f, 0.17f);
    glVertex2f(-0.65f, 0.19f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-0.55f, 0.23f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.45f, 0.26f);
    glVertex2f(-0.40f, 0.27f);
    glVertex2f(-0.35f, 0.26f);
    glVertex2f(-0.30f, 0.25f);
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.20f, 0.22f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.10f, 0.20f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f( 0.00f, 0.16f);
    glVertex2f( 0.05f, 0.14f);
    glVertex2f( 0.10f, 0.13f);
    glVertex2f( 0.15f, 0.11f);
    glVertex2f( 0.20f, 0.09f);
    glVertex2f( 0.25f, 0.07f);
    glVertex2f( 0.30f, 0.06f);
    glVertex2f( 0.35f, 0.05f);
    glVertex2f( 0.40f, 0.03f);
    glVertex2f( 0.45f, 0.02f);
    glVertex2f( 0.50f, 0.01f);
    glVertex2f( 0.55f, 0.005f);
    glVertex2f( 0.60f, 0.003f);
    glVertex2f( 0.65f, 0.002f);
    glVertex2f( 0.70f, 0.001f);
    glVertex2f( 0.75f, 0.0f);
    glVertex2f( 0.80f, 0.0f);
    glVertex2f( 0.85f, 0.0f);
    glVertex2f( 0.90f, 0.0f);
    glVertex2f( 0.95f, 0.0f);
    glVertex2f( 1.00f, 0.0f);
    glEnd();
    glPopMatrix();

}
void Hill5()//right most hill

{
    glPushMatrix();

    glTranslatef(1.07,0.1, 0);

    glScalef(0.90, 1.2, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.305f, 0.705f, 0.752f);
    glVertex2f(-1.00f, 0.0f);
    glVertex2f(-0.95f, 0.05f);
    glVertex2f(-0.90f, 0.08f);
    glVertex2f(-0.85f, 0.10f);
    glVertex2f(-0.80f, 0.12f);
    glVertex2f(-0.75f, 0.14f);
    glVertex2f(-0.70f, 0.17f);
    glVertex2f(-0.65f, 0.19f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-0.55f, 0.23f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.45f, 0.26f);
    glVertex2f(-0.40f, 0.27f);
    glVertex2f(-0.35f, 0.26f);
    glVertex2f(-0.30f, 0.25f);
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.20f, 0.22f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.10f, 0.20f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f( 0.00f, 0.16f);
    glVertex2f( 0.05f, 0.14f);
    glVertex2f( 0.10f, 0.13f);
    glVertex2f( 0.15f, 0.11f);
    glVertex2f( 0.20f, 0.09f);
    glVertex2f( 0.25f, 0.07f);
    glVertex2f( 0.30f, 0.06f);
    glVertex2f( 0.35f, 0.05f);
    glVertex2f( 0.40f, 0.03f);
    glVertex2f( 0.45f, 0.02f);
    glVertex2f( 0.50f, 0.01f);
    glVertex2f( 0.55f, 0.005f);
    glVertex2f( 0.60f, 0.003f);
    glVertex2f( 0.65f, 0.002f);
    glVertex2f( 0.70f, 0.001f);
    glVertex2f( 0.75f, 0.0f);
    glVertex2f( 0.80f, 0.0f);
    glVertex2f( 0.85f, 0.0f);
    glVertex2f( 0.90f, 0.0f);
    glVertex2f( 0.95f, 0.0f);
    glVertex2f( 1.00f, 0.0f);
    glEnd();
    glPopMatrix();

}

void waveF()
{
    glPushMatrix();
    glTranslatef(0,0.35, 0);
  //  glScalef(, 1.2, 0);
    glBegin(GL_POLYGON);
    glColor3ub(33, 150, 243);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.9f, -0.72f);
    glVertex2f(-0.8f, -0.70f);
    glVertex2f(-0.7f, -0.73f);
    glVertex2f(-0.6f, -0.71f);
    glVertex2f(-0.5f, -0.74f);
    glVertex2f(-0.4f, -0.72f);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.2f, -0.72f);
    glVertex2f(-0.1f, -0.74f);
    glVertex2f( 0.0f, -0.72f);
    glVertex2f( 0.1f, -0.73f);
    glVertex2f( 0.2f, -0.70f);
    glVertex2f( 0.3f, -0.72f);
    glVertex2f( 0.4f, -0.71f);
    glVertex2f( 0.5f, -0.73f);
    glVertex2f( 0.6f, -0.70f);
    glVertex2f( 0.7f, -0.72f);
    glVertex2f( 0.8f, -0.71f);
    glVertex2f( 0.9f, -0.73f);
    glVertex2f( 1.0f, -0.7f);
    glVertex2f( 1.0f, -1.0f);
    glEnd();
    glPopMatrix();
}


void display5() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    skyF();

    //left cloud
    glScalef(0.6,1.0,0.0);
    glTranslatef(cloud1positionF1, 0.3f, 0.0f);
    cloudF();
    glLoadIdentity();//end

    //right cloud
    glTranslatef(cloud3positionF3, 0.3f, 0.0f);
    glScalef(.8,.9,0);
    cloudF();
    glLoadIdentity();//end

    //middle cloud
    glTranslatef(cloud2positionF2, 0.1f, 0.0f);
    glScalef(0.9,0.9,0);
    cloud1F();
    glLoadIdentity();//end

    mountain();
    seaF();
    Hill4();
	Hill5();
	Hill3();
	Hill();
	Hill2();

	shipF();
    waveF();
    glFlush();

}



void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{
	     case '1':
        if(!flag)
        {
        glutTimerFunc(500, updatehf, 0);
        glutTimerFunc(5000, update1hf, 0);
        glutTimerFunc(6000, update2hf, 0);
        glutTimerFunc(9000, update3hf, 0);
        //glutDisplayFunc(display_humayra);
        }
        PlaySound("s1.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display1);
        break;


	    case '2':
        if(!flag1)
        {
    //Saima
    glutTimerFunc(500, updateS, 0);
    glutTimerFunc(500, update1S, 0);
        }
        PlaySound("s2.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display2);
        break;





         case '3':
        if(!flag2)
        {

//Ria
glutTimerFunc(5000, updateR, 0);
    glutTimerFunc(6500, update2R, 0);
    glutTimerFunc(8500, update3R, 0);
    glutTimerFunc(10500, update4R, 0);
    glutTimerFunc(500, update1R, 0);

        }
        PlaySound("s3.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display3);
        break;


        case '4':
        if(!flag3)
        {

    glutTimerFunc(0, wavemove1, 0);
    glutTimerFunc(0, cloudmove1, 0);
    glutTimerFunc(0, cloudmove2, 0);
    glutTimerFunc(0, cloudmove3, 0);
    glutTimerFunc(4000, RopeD1, 0);
    glutTimerFunc(4000, RopeD2, 0);
    glutTimerFunc(4000, RopeD3, 0);
    glutTimerFunc(4000, RopeD4, 0);

    glutTimerFunc(4000, containerD, 0);
     glutTimerFunc(8000, RopeU1, 0);
     glutTimerFunc(8000, RopeU2, 0);
     glutTimerFunc(8000, RopeU3, 0);
      glutTimerFunc(8000, RopeU4, 0);
glutTimerFunc(11000, shipmove, 0);
glutTimerFunc(11000, containermove, 0);
     glutTimerFunc(500, Shipcoming, 0);

        }
        PlaySound("s4.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display4);
        break;


            case '5':
        if(!flag4)
        {
        glutTimerFunc(500, updateF, 0);
        //glutDisplayFunc(display_humayra);
        }
        PlaySound("s5.wav", NULL, SND_ASYNC|SND_LOOP);
        glutDisplayFunc(display5);
        break;


        glutPostRedisplay();
	}
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(960, 540); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

     glutDisplayFunc(display0);


    glutKeyboardFunc(handleKeypress);glutMouseFunc(handleMouse1);


    glutMainLoop(); // Enter the event-processing loop
    return 0;
}

