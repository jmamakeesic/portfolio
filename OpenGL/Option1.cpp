#include "option1.h"

int main(int argc,char** argv){
  // general setup
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH|GLUT_MULTISAMPLE);
  glutInitWindowSize(800,600);
  glutCreateWindow("3D Object Modeling Demo");
  //glewInit();
  glClearColor(0,0,0,1);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  // setup perspective
  glMatrixMode(GL_PROJECTION);
  glFrustum(-2,2, -1.5,1.5, 3,25);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0,0,4, 0,0,0, 0,1,0);
  glViewport(0,0,800,600);
  // setup textures
  glEnable(GL_TEXTURE_2D);
  glGenTextures(2,textures);
  // setup fog effect
  glEnable(GL_FOG);
  glFogfv(GL_FOG_COLOR,fogColor);
  glFogf(GL_FOG_DENSITY,0.03);
  // setup lighting
  glNormal3f(0,0,1);
  glEnable (GL_LIGHTING);
  glLightfv(GL_LIGHT0,GL_POSITION,pos0 );
  glLightfv(GL_LIGHT0,GL_DIFFUSE ,grey );
  glLightfv(GL_LIGHT0,GL_SPECULAR,none );
  glEnable (GL_LIGHT0);
  glLightfv(GL_LIGHT1,GL_POSITION,pos1 );
  glLightfv(GL_LIGHT1,GL_DIFFUSE ,gold );
  glLightfv(GL_LIGHT1,GL_SPECULAR,gold );
  glEnable (GL_LIGHT1);
  glLightfv(GL_LIGHT2,GL_POSITION,pos2 );
  glLightfv(GL_LIGHT2,GL_DIFFUSE ,ambGreen);
  glLightfv(GL_LIGHT2,GL_SPECULAR,none );
  glEnable (GL_LIGHT2);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
  glEnable(GL_COLOR_MATERIAL);
  // render scene
  glutDisplayFunc(render);
  cout<<glGetError();
  glutMainLoop();
  delete textures;
}
void render(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  //glEnableClientState(GL_VERTEX_ARRAY);
  // background image
  loadTex(textures[0],(char*)"bg.bmp",800,600);
  glBegin(GL_QUADS);
    glNormal3f(0,1,0);
    glTexCoord2d(0.0,0.0); glVertex3f(-8.0,-6.0,-8.0);
    glTexCoord2d(0.0,1.0); glVertex3f(-8.0, 6.0,-8.0);
    glTexCoord2d(1.0,1.0); glVertex3f( 8.0, 6.0,-8.0);
    glTexCoord2d(1.0,0.0); glVertex3f( 8.0,-6.0,-8.0);
  glEnd();
  // objects
  loadTex(textures[1],(char*)"metal.bmp",300,300);
  factory(-2,-4.5,-6);
  sign(3.1,-3.5,-6);
  blimp(-3,.5,-6);
  plane(20,20,25, 2.8, 0  ,-2.5);
  plane(20,10,30, 3.5,-0.5,-2.0);
  plane(20, 0,40, 3.8,-1.0,-4.0);
  tree( 2.2,0 ,-2);
  tree( 2.8,.5,-2);
  tree(-2.2,0 ,-2);
  tree(-2.8,.5,-2);
  glBindTexture(GL_TEXTURE_2D,0);
  glFlush();
}
void loadTex(GLuint id,char* filename,GLint width,GLint height){
  FILE *file = fopen(filename,"r");
  GLubyte *buf = new GLubyte [width*height*3];
  fseek(file,54,0); // seek past BMP header (54 bytes)
  fread(buf,3,width*height,file);
  fclose(file);
  
  glBindTexture(GL_TEXTURE_2D,id);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D,3,width,height,GL_BGR,GL_UNSIGNED_BYTE,buf);
}
void factory(GLfloat x,GLfloat y,GLfloat z){
  glMaterialf(GL_FRONT,GL_SHININESS,50);
  glMaterialfv(GL_FRONT,GL_SPECULAR,gold);
  glPushMatrix();
    glTranslatef(x,y,z);
    glRotated(30,0,1,0);
    glScalef(3,1,2);
    glutSolidCube(.3);
    glTranslatef(0,.3,0);
    glScalef(.7,1,1);
    glutSolidCube(.3);
    glTranslatef(0,.3,0);
    glScalef(.8,1,1);
    glRotated(90,1,0,0);
    glTranslatef(-.1,-.1,0);
    glutSolidCylinder(.04,.5,16,16);
    glTranslatef(.1,0,0);
    glutSolidCylinder(.04,.5,16,16);
    glTranslatef(.1,0,0);
    glutSolidCylinder(.04,.5,16,16);
  glPopMatrix();
}
void sign(GLfloat x,GLfloat y,GLfloat z){
  glMaterialf(GL_FRONT,GL_SHININESS,50);
  glMaterialfv(GL_FRONT,GL_SPECULAR,gold);
  glPushMatrix();
    glTranslatef(x,y,z);
    glRotated(90,1,0,0);
    glRotated(10,0,0,1);
    glutSolidCylinder(.04,.2,16,16);
    glTranslatef(.15,0,0);
    glutSolidCylinder(.04,.2,16,16);
    glTranslatef(.15,0,0);
    glutSolidCylinder(.04,.2,16,16);
    glTranslatef(.15,0,0);
    glutSolidCylinder(.04,.2,16,16);
    glTranslatef(-.25,0,-.2);
    glScalef(6,1,4);
    glutSolidCube(.12);
  glPopMatrix();
}
void blimp(GLfloat x,GLfloat y,GLfloat z){
  #define BV blimpVertices
  glMaterialf(GL_FRONT,GL_SHININESS,50);
  glMaterialfv(GL_FRONT,GL_SPECULAR,white);
  glPushMatrix();
    glTranslatef(x,y,z);
    glPushMatrix();
      glScalef(3,1,1);
      glRotatef(90,0,1,0);
      glShadeModel(GL_FLAT);
      glColor3fv(white);
      glutSolidSphere(.3,24,16); // body
      glColor3fv(grey);
      glRotatef(-90,0,1,0);
      glShadeModel(GL_SMOOTH);
      glTranslatef(.15,-.25,0);
      glutSolidCube(.1); // car
    glPopMatrix();
    // fins
    for(GLint* q:blimpQuads){
      glNormal3fv(calcNormal(BV[q[0]],BV[q[1]],BV[q[2]]));
      glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0); glVertex3fv(BV[q[0]]);
        glTexCoord2d(0.0,1.0); glVertex3fv(BV[q[1]]);
        glTexCoord2d(1.0,1.0); glVertex3fv(BV[q[2]]);
        glTexCoord2d(1.0,0.0); glVertex3fv(BV[q[3]]);
      glEnd();
    }
  glPopMatrix();
}
void plane(GLint i,GLint j,GLint k,GLfloat x,GLfloat y,GLfloat z){
  #define PV planeVertices
  glMaterialf(GL_FRONT,GL_SHININESS,100);
  glMaterialfv(GL_FRONT,GL_SPECULAR,white);
  glPushMatrix();
    glRotated(k,0,0,1);
    glRotated(j,0,1,0);
    glRotated(i,1,0,0);
    glTranslatef(x,y,z);
    for(GLint* q:planeQuads){
      glNormal3fv(calcNormal(PV[q[0]],PV[q[1]],PV[q[2]]));
      glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0); glVertex3fv(PV[q[0]]);
        glTexCoord2d(0.0,1.0); glVertex3fv(PV[q[1]]);
        glTexCoord2d(1.0,1.0); glVertex3fv(PV[q[2]]);
        glTexCoord2d(1.0,0.0); glVertex3fv(PV[q[3]]);
      glEnd();
    }
  glPopMatrix();
}
void tree(GLfloat x,GLfloat y,GLfloat z){
  glColor3f(.3,.4,.2),
  glPushMatrix();
    glRotated(-100,1,0,0);
    glTranslated(x,y,z);  glutSolidCone(.1,3,32,32);
    glTranslated(0,0,.4); glutSolidCone(.6,.8,32,32);
    glTranslated(0,0,.4); glutSolidCone(.3,.8,32,32);
    glTranslated(0,0,.4); glutSolidCone(.4,.8,32,32);
    glTranslated(0,0,.4); glutSolidCone(.2,.8,32,32);
    glTranslated(0,0,.4); glutSolidCone(.2,.8,32,32);
    glTranslated(0,0,.4); glutSolidCone(.1,.8,32,32);
  glPopMatrix();
}
GLfloat* calcNormal(GLfloat* a,GLfloat* b,GLfloat* c){
  // define target plane
  GLfloat u[] = {b[0]-a[0], b[1]-a[1], b[2]-a[2]};
  GLfloat v[] = {c[0]-a[0], c[1]-a[1], c[2]-a[2]};
  // calculate cross product
  cp[0] = u[1]*v[2] - u[2]*v[1];
  cp[1] = u[2]*v[0] - u[0]*v[2];
  cp[2] = u[0]*v[1] - u[1]*v[0];
  // normalize
  GLfloat length = sqrt(cp[0]*cp[0] + cp[1]*cp[1] + cp[2]*cp[2]);
  for(int i=0;i<3;i++) cp[i] /= -length;
  return cp;
}