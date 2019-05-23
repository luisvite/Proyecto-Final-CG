//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Func�on creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Func�on creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text, GLuint text1);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void rollercoaster(GLuint text1, GLuint text2, GLuint text3, GLuint text4);
	void riel1(GLuint text1);
	void riel2(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text1);
	void riel3(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text1);
	void riel4(GLuint text1);
	void JM1(GLuint rojo, GLuint paredamarilla, GLuint parednaranja, GLuint n, GLuint text2, GLuint paredgris2, GLuint t_ESFERA2, int rot1);
	void JM2(GLuint paredgris1, GLuint paredgris2, GLuint tasas, GLuint rojo, GLuint paredamarilla, GLuint n, int rot, int rot2);
	void JM3(GLuint t_MADERA2, GLuint paredamarilla, GLuint tasas, GLuint paredgris1, GLuint circo, int rot1, int rot2);
	void JM4(GLuint n, GLuint parednaranja, GLuint circo, GLuint paredgris1, GLuint rojo, GLuint paredamarilla, GLuint paredgris2, int rot);
	void Fortuna(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text1, GLuint text2, GLuint text3, int rot);
	void Car(GLuint text1, GLuint text2, int rot);
	void Banca(GLuint text1, GLuint text2);
	void lampara(GLuint text1, GLuint text2);
	void bote(GLuint text1);
	void botes(GLuint text1, GLuint text2, GLuint text3);

};
