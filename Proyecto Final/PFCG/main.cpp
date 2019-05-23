//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Angeles Lopez Michael Josefh		******//
//*************		Luis Enrique Vite Aquino			******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

CCamera objCamera;  //Creramos un objeto de tipo camara
GLfloat g_lookupdown = 0.0f; 
int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//Declaracion de texturas
CTexture text1; //Cielo
CTexture text2; //Suelo (pasto)
CTexture text3; //Base metalica 1
CTexture text4; //Base metalica 2
CTexture text5; //Base metalica 3
CTexture text6; //Base metalica para montaña
CTexture text7; //Base metalica para rueda fortuna
CTexture text8; //metal rojo
CTexture text9; //material purpura
CTexture text10; //Metal negro
CTexture text11; //madera para las bancas
CTexture text12; //Metal para la lampara
CTexture text13; //esfera de la lampara
CTexture text14; //Metal para bote gris

CTexture t_ESFERA1;
CTexture t_MADERA2;
CTexture t_ESFERA2;
CTexture t_ESFERA3;
CTexture n;
CTexture circo;
CTexture paredamarilla;
CTexture parednaranja;
CTexture tasas;
CTexture paredgris1;
CTexture paredgris2;
CTexture rojo;
CTexture verde;
CTexture verdeclaro;

//Declaracion de figuras utilizadas
CFiguras fig1; //figura para crear el cielo
CFiguras fig2; //fig para crar juego giratorio
CFiguras fig3; //fig para crear segundo juego giratorio
CFiguras fig4; //fig para crear el tercer juego
CFiguras fig5; //fig para crear cuarto juego
CFiguras Banca;
CFiguras Lampara;
CFiguras Botes;
CFiguras fortuna;
CFiguras mountain; //fig para crear la montaña rusa
CFiguras car;

// Variables usadas para calcular frames por segundo: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime_1 = 0;
DWORD dwLastUpdateTime2 = 0;
DWORD dwLastUpdateTime2_2 = 0;
DWORD dwLastUpdateTime3 = 0;
DWORD dwLastUpdateTime3_2 = 0;
DWORD dwLastUpdateTime4 = 0;
DWORD dwLastUpdateTime5 = 0;
DWORD dwLastUpdateTime6 = 0;
DWORD dwLastUpdateTime7 = 0;
DWORD dwLastUpdateTime8 = 0;
DWORD dwElapsedTime_1 = 0;
DWORD dwElapsedTime2 = 0;
DWORD dwElapsedTime2_2 = 0;
DWORD dwElapsedTime3 = 0;
DWORD dwElapsedTime3_2 = 0;
DWORD dwElapsedTime4 = 0;
DWORD dwElapsedTime5 = 0;
DWORD dwElapsedTime6 = 0;
DWORD dwElapsedTime7 = 0;
DWORD dwElapsedTime8 = 0;

//Variables usadas para crear el movimiento
int rot1_1 = 0, rot2 = 0, rot2_2 = 0, rot3 = 0, rot3_2 = 0, rot4 = 0, rot5 = 0, rot6 = 0;
int aux1_1 = 0, aux2_1 = 0, aux3_1 = 0, aux4_1 = 0, aux5_1=0;
int anim1 = 0, anim2 = 0, anim3 = 0, anim4 = 0, anim5 = 0, anim6 = 0, anim7 = 0, anim8 = 0;
int t = 0;

void InitGL(GLvoid) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("cielo.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();
	
	text2.LoadTGA("textura/grass.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("textura/metal1.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("textura/metal2.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("textura/metal3.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("textura/metal_blue.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	text7.LoadTGA("textura/metal_green.tga");
	text7.BuildGLTexture();
	text7.ReleaseImage();

	text8.LoadTGA("textura/metal_red.tga");
	text8.BuildGLTexture();
	text8.ReleaseImage();

	text9.LoadTGA("textura/mat_purple.tga");
	text9.BuildGLTexture();
	text9.ReleaseImage();

	text10.LoadTGA("textura/metal_black.tga");
	text10.BuildGLTexture();
	text10.ReleaseImage();

	text11.LoadTGA("textura/madera_banca.tga");
	text11.BuildGLTexture();
	text11.ReleaseImage();

	text12.LoadTGA("textura/verde.tga");
	text12.BuildGLTexture();
	text12.ReleaseImage();

	text13.LoadTGA("textura/blanco.tga");
	text13.BuildGLTexture();
	text13.ReleaseImage();
	
	text14.LoadTGA("textura/grey.tga");
	text14.BuildGLTexture();
	text14.ReleaseImage();

	t_ESFERA1.LoadTGA("textura/ESFERA1.tga");
	t_ESFERA1.BuildGLTexture();
	t_ESFERA1.ReleaseImage();

	t_MADERA2.LoadTGA("textura/MADERA2.tga");
	t_MADERA2.BuildGLTexture();
	t_MADERA2.ReleaseImage();

	t_ESFERA2.LoadTGA("textura/ESFERA2.tga");
	t_ESFERA2.BuildGLTexture();
	t_ESFERA2.ReleaseImage();

	t_ESFERA3.LoadTGA("textura/ESFERA3.tga");
	t_ESFERA3.BuildGLTexture();
	t_ESFERA3.ReleaseImage();

	n.LoadTGA("textura/n.tga");
	n.BuildGLTexture();
	n.ReleaseImage();

	circo.LoadTGA("textura/circo.tga");
	circo.BuildGLTexture();
	circo.ReleaseImage();

	paredamarilla.LoadTGA("textura/paredamarilla.tga");
	paredamarilla.BuildGLTexture();
	paredamarilla.ReleaseImage();

	parednaranja.LoadTGA("textura/parednaranja.tga");
	parednaranja.BuildGLTexture();
	parednaranja.ReleaseImage();

	paredgris1.LoadTGA("textura/paredgris1.tga");
	paredgris1.BuildGLTexture();
	paredgris1.ReleaseImage();

	paredgris2.LoadTGA("textura/paredgris2.tga");
	paredgris2.BuildGLTexture();
	paredgris2.ReleaseImage();

	tasas.LoadTGA("textura/tasas.tga");
	tasas.BuildGLTexture();
	tasas.ReleaseImage();

	rojo.LoadTGA("textura/rojo.tga");
	rojo.BuildGLTexture();
	rojo.ReleaseImage();

	verde.LoadTGA("textura/verde.tga");
	verde.BuildGLTexture();
	verde.ReleaseImage();

	verdeclaro.LoadTGA("textura/verdeclaro.tga");
	verdeclaro.BuildGLTexture();
	verdeclaro.ReleaseImage();

	objCamera.Position_Camera(0, 2.5f, 60, 0, 2.5f, 55, 0, 1, 0);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
		glRotatef(g_lookupdown, 1.0f, 0, 0);

		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

		glPushMatrix(); //Creamos cielo y suelo
			glDisable(GL_LIGHTING);
			glTranslatef(0, 50, 0);
			fig1.skybox(130.0, 100.0, 130.0, text1.GLindex, text2.GLindex); //altura, largo, profundidad
			glEnable(GL_LIGHTING);
		glPopMatrix();
		//Dibujando primer juego mecanico
		glPushMatrix();
			glTranslatef(-75.0, 0.0, -50.0);
			fig2.JM1(rojo.GLindex, paredamarilla.GLindex, parednaranja.GLindex, n.GLindex, text2.GLindex, paredgris2.GLindex, t_ESFERA2.GLindex,rot1_1);
		glPopMatrix();
		//Dibujando segundo juego mecanico
		glPushMatrix();
			glTranslatef(-20.0, 0.0, 10.0);
			fig3.JM2(paredgris1.GLindex, paredgris2.GLindex,tasas.GLindex, rojo.GLindex, paredamarilla.GLindex, n.GLindex, rot2, rot2_2);
		glPopMatrix();
		//Dibujando tercer juego mecanico
		glPushMatrix();
			glTranslatef(40.0, 0.0, 30.0);
			fig4.JM3(t_MADERA2.GLindex, paredamarilla.GLindex, tasas.GLindex, paredgris1.GLindex, circo.GLindex, rot3, rot3_2);
		glPopMatrix();
		//Dibujando cuarto juego mecanico
		glPushMatrix();
			glTranslatef(-20.0, 0.0, 35.0);
			glRotatef(135, 0,1,0);
			fig5.JM4(n.GLindex, parednaranja.GLindex, circo.GLindex, paredgris1.GLindex, rojo.GLindex, paredamarilla.GLindex, paredgris1.GLindex, rot4);
		glPopMatrix();
		//Dibujando rueda fortuna
		glPushMatrix();
			glTranslatef(40.0, 0.0, 20.0);
			fortuna.Fortuna(10,9.5,10,10, text7.GLindex, text3.GLindex, text4.GLindex, rot5);
		glPopMatrix();
		//Dibujando Montaña Rusa
		glPushMatrix();
			glTranslatef(10.0, 0.0,-15.0);
			mountain.rollercoaster(text3.GLindex, text4.GLindex, text5.GLindex, text6.GLindex);
		glPopMatrix();
		//dibujando car de la montaña rusa
		glPushMatrix();
			glTranslatef(10.0, 0.65, -17.2);
			car.Car(text8.GLindex, text9.GLindex, rot6);
		glPopMatrix();
		//Dibujando Bancas
		glPushMatrix();
			glTranslatef(-1,0,-5);
			Banca.Banca(text10.GLindex, text11.GLindex);
		glPopMatrix();
		//Dibujando lamparas
		glPushMatrix();
			glTranslatef(2.2, 0, -5);
			Lampara.lampara(text12.GLindex, text13.GLindex);
		glPopMatrix();
		//Dibujando Botes de basuratext 10,13 y 14
		glPushMatrix();
			glTranslatef(-3.0,0,-5);
			Botes.botes(text10.GLindex, text12.GLindex, text14.GLindex);
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime_1 = dwCurrentTime - dwLastUpdateTime_1;
	dwElapsedTime2 = dwCurrentTime - dwLastUpdateTime2;
	dwElapsedTime2_2 = dwCurrentTime - dwLastUpdateTime2_2;
	dwElapsedTime3 = dwCurrentTime - dwLastUpdateTime3;
	dwElapsedTime3_2 = dwCurrentTime - dwLastUpdateTime3_2;
	dwElapsedTime4 = dwCurrentTime - dwLastUpdateTime4;
	dwElapsedTime5 = dwCurrentTime - dwLastUpdateTime5;
	dwElapsedTime6 = dwCurrentTime - dwLastUpdateTime6;
	
	//animacion 1
	if (anim1 == 1)
	{
		//giro interno
		if (dwElapsedTime_1 >= 40)
		{
			if (rot1_1 <= 358 && aux1_1 < 4) {
				rot1_1 = (rot1_1 + 2) % 360;
				dwLastUpdateTime_1 = dwCurrentTime;
				if (rot1_1 == 0) {
					aux1_1 = aux1_1 + 1;
				}
			}else {
				anim1 = 0;
				aux1_1 = 0;
			}
		}
	}

	//animacion 2
	if (anim2 == 1)
	{
		if (dwElapsedTime2 >= 50)
		{
			rot2 = (rot2 + 4) % 360;
			dwLastUpdateTime2 = dwCurrentTime;
		}
		if (dwElapsedTime2_2 >= 50)
		{
			if (rot2_2 <= 356 && aux2_1 < 3){
				rot2_2 = (rot2_2 + 4) % 360;
				dwLastUpdateTime2_2 = dwCurrentTime;
				if (rot2_2 == 0) {
					aux2_1 = aux2_1+1;
				}
			}
			else {
				anim2 = 0;
				aux2_1 = 0;
			}
		}
	}

	//animacion 3
	if (anim3 == 1)
	{
		if (dwElapsedTime3 >= 50)
		{
			rot3 = (rot3 + 4) % 360;
			dwLastUpdateTime3 = dwCurrentTime;
		}
		if (dwElapsedTime3_2 >= 50)
		{
			if (rot3_2 <= 356 && aux3_1 < 3) {
				rot3_2 = (rot3_2 + 4) % 360;
				dwLastUpdateTime3_2 = dwCurrentTime;
				if (rot3_2 == 0) {
					aux3_1 = aux3_1 + 1;
				}
			}
			else {
				anim3 = 0;
				aux3_1 = 0;
			}
		}
	}

	//animacion 4
	if (anim4 == 1)
	{
		if (dwElapsedTime4 >= 50)
		{
			if (rot4 <= 356 && aux4_1 < 5) {
				rot4 = (rot4 + 4) % 360;
				dwLastUpdateTime4 = dwCurrentTime;
				if (rot4 == 0) {
					aux4_1 = aux4_1 + 1;
				}
			}
			else {
				anim4 = 0;
				aux4_1 = 0;
			}
		}
	}

	//animacion 5
	if (anim5 == 1)
	{
		if (dwElapsedTime5 >= 80)
		{
			if (rot5 <= 357 && aux5_1 < 3) {
				rot5 = (rot5 + 3) % 360;
				dwLastUpdateTime5 = dwCurrentTime;
				if (rot5 == 0) {
					aux5_1 = aux5_1 + 1;
				}
			}else{
				anim5 = 0;
				aux5_1 = 0;
			}
		}
	}
	
	//animacion 6
	if (anim6 == 1)
	{
		if (dwElapsedTime6 >= 10)
		{
			rot6 = (rot6 + 10) % 360;
			dwLastUpdateTime6 = dwCurrentTime;
		}
	}
	
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0){ //Prevenimos division por cero
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 500.0);
	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera(CAMERASPEED + 0.1);
			break;
		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED + 0.1));
			break;
		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED + 0.1));
			break;
		case 'd':
		case 'D':
			objCamera.Strafe_Camera(CAMERASPEED + 0.1);
			break;
		case '1':
			if (anim1 == 0)
			{
				anim1 = 1;
			}
			else {
				anim1 = 0;
			}
			break;
		case '2':
			if (anim2 == 0)
			{
				anim2 = 1;
			}
			else {
				anim2 = 0;
			}
			break;
		case '3':
			if (anim3 == 0)
			{
				anim3 = 1;
			}
			else {
				anim3 = 0;
			}
			break;
		case '4':
			if (anim4 == 0)
			{
				anim4 = 1;
			}
			else {
				anim4 = 0;
			}
			break;
		case '5':
			if (anim5 == 0)
			{
				anim5 = 1;
			}
			else {
				anim5 = 0;
			}
			break;
		case '6':
			if (anim6 == 0)
			{
				anim6 = 1;
			}
			else {
				anim6 = 0;
			}
			break;
		case 27:        // Cuando Esc es presionado...
			exit(0);   // Salimos del programa
			break;
		default:        // Cualquier otra
			break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
		case GLUT_KEY_PAGE_UP:
			objCamera.UpDown_Camera(CAMERASPEED);
			break;
		case GLUT_KEY_PAGE_DOWN:
			objCamera.UpDown_Camera(-CAMERASPEED);
			break;
		case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
			g_lookupdown -= 1.0f;
			break;
		case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
			g_lookupdown += 1.0f;
			break;
		case GLUT_KEY_LEFT:
			objCamera.Rotate_View(-CAMERASPEED);
			break;
		case GLUT_KEY_RIGHT:
			objCamera.Rotate_View(CAMERASPEED);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("PFCG"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);	//animacion

	glutMainLoop();          // 

	return 0;
}