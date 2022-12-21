

#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <GL/glut.h>

void shape(int w, int h)
{
    // Select a part of the window
    glViewport(0, 0, 700, 800);

    // Set the projection
    //sets a point to be 4*4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //left,right,bottom,top,near,far
    // perspective view
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    //glOrtho  (-1.0, 1.0, -1.0,  1.0, 2.0, 20.0); // orthographic view

    // Set the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(6.0, 2.0, -6.0,        // - eye point
              0.0, 0.0, 0.0,        // - center point
              0.0, 1.0, 0.0);       // - up axis

}

void displayHouse()
{
    //clears the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable( GL_CULL_FACE );
    glCullFace ( GL_BACK );

    //sets front wall to blue color
    glColor3f( 0.4, 0.4, 0.9 );
    glFrontFace ( GL_CCW );
    glPolygonMode( GL_FRONT, GL_FILL );
    //glPolygonMode( GL_BACK, GL_LINE );

    //right wall
    glBegin( GL_POLYGON );
    glVertex3i( -1, 0, -2);
    glVertex3i( -1, 1, -2);
    glVertex3i( 1, 1, -2);
    glVertex3i( 1, 0, -2);
    glEnd();

    //sets wall color to light blue
    glColor3f( 0.4, 0.8, 1.0 );

    glFrontFace ( GL_CCW );

    //back wall
    glBegin( GL_POLYGON );
    glVertex3i( -1, 0, 1);
    glVertex3i( -1, 1, 1);
    glVertex3i( -1, 1, -2);
    glVertex3i( -1, 0, -2);
    glEnd();
    //blue

    glFrontFace ( GL_CW );
    glPolygonMode( GL_FRONT, GL_FILL );
    //sets color to light purple
    glColor3f( 0.5, 0.4, 0.9 );
    //left wall
    glBegin( GL_POLYGON );
    glVertex3i( -1, 0, 1);
    glVertex3i( -1, 1, 1);
    glVertex3i( 1, 1, 1);
    glVertex3i( 1, 0, 1);
    glEnd();

    //sets front wall color to light green
    glColor3f( 0.5, 0.9, 0.6 );
    //front wall
    glBegin( GL_POLYGON );
    glVertex3i( 1, 0, 1);
    glVertex3i( 1, 1, 1);
    glVertex3i( 1, 1, -2);
    glVertex3i( 1, 0, -2);
    glEnd();

    //deep saffron
    glColor3f(1.0, 0.6, 0.2 );
    glBegin( GL_TRIANGLES );
    //left roof
    glVertex3i(-1, 1, 1);
    glVertex3f( 0, 1.5, 0.5);
    glVertex3i( 1, 1, 1);


    //right roof
    glVertex3i( 1, 1, -2);
    glVertex3f( 0, 1.5, -1.5);
    glVertex3i( -1, 1, -2);
    glEnd();

    //sets part of roof color to dark brown
    glColor3f( 0.5,0.2,0.0 );
    //front roof
    glBegin( GL_POLYGON );
    glVertex3i( 1,1,1);
    glVertex3f( 0, 1.5, 0.5);
    glVertex3f( 0, 1.5, -1.5);
    glVertex3i( 1, 1, -2);
    glEnd();

    //sets back roof to color light brown
    glColor3f( 0.5,0.3,0.1 );
    //back roof
    glBegin( GL_POLYGON );
    glVertex3i( -1,1,1);
    glVertex3i( -1,1,-2);
    glVertex3f( 0, 1.5, -1.5);
    glVertex3f( 0,1.5,0.5);
    glEnd();

    //door
    //sets chocolate color to door
    glColor3f( 0.3,0.15,0 );
    glBegin( GL_POLYGON );
    glVertex3f( 1, 0, 0.8);
    glVertex3f( 1, 0.8, 0.8);
    glVertex3f( 1, 0.8, 0.4);
    glVertex3f( 1, 0, 0.4);
    glEnd();

    //front wall window
    //sets the color of door to light green
    glColor3f( 0.7,0.5,0.1 );
    glBegin( GL_POLYGON );
    glVertex3f( 1, 0.4, -0.8);
    glVertex3f( 1, 0.7, -0.8);
    glVertex3f( 1, 0.7, -1.5);
    glVertex3f( 1, 0.4, -1.5);
    glEnd();

    //left wall window
    //sets left wall window to color white
    glColor3f( 1.0,1.0,1.0 );
    glBegin( GL_POLYGON );
    glVertex3f( -0.8, 0.4, 1);
    glVertex3f( -0.8, 0.7, 1);
    glVertex3f( -0.3, 0.7, 1);
    glVertex3f( -0.3, 0.4, 1);
    glEnd();


    glDisable( GL_CULL_FACE );

    // Single buffered, so needs a flush.
    //sends all outputs to display
    glFlush();
}






int main(int argc, char **argv)
{
    //to initialize the toolkit
    glutInit(&argc, argv);

    //sets the display mode
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    //sets the starting position for the window
    glutInitWindowPosition(200,100);

    //sets the window size
    glutInitWindowSize(800, 600);

    //creates window and sets the title
    glutCreateWindow("My 3D House");

    glutDisplayFunc(displayHouse);

    glutReshapeFunc(shape);

    //go into a loop until event occurs
    glutMainLoop();
    return 0;
}
