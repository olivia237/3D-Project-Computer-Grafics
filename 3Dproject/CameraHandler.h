#pragma once
#include "Lib.h"
#include "Strutture.h"
#include "Enum.h"

extern int selected_obj;
extern float cameraSpeed;
extern bool visualizzaAncora;
extern vec3 asse;
extern string Operazione;
extern string stringa_asse;
extern vector<Mesh> Scena;
extern vector<vector<MeshObj>> ScenaObj;


bool checkCollision(vec4 pos){
	
	//collisioni su asse x
	for (int i = 1; i < Scena.size(); i++)
	{
		vec4 boundGlobT = Scena[i].ModelM * vec4(Scena[i].boundingBoxMax, 1.0);
		vec4 boundGlobB = Scena[i].ModelM * vec4(Scena[i].boundingBoxMin, 1.0);
		
		//collisione asse x
		bool collisionX =	boundGlobB.x <= pos.x  &&
							boundGlobT.x >= pos.x;

		//collisione asse y
		bool collisionY =	boundGlobB.y <= pos.y  &&
							boundGlobT.y >= pos.y;
		//collisione asse z
		bool collisionZ =	boundGlobB.z <= pos.z  &&
							boundGlobT.z >= pos.z;
		
		//se ho una collisione fermo esco
		if (collisionX && collisionY && collisionZ) 
		{
			return true;
		}
	}	
	for (int j = 0; j < ScenaObj.size(); j++)
	{
		for (int k = 0; k < ScenaObj[j].size(); k++)
		{
			vec4 boundGlobT = ScenaObj[j][k].ModelM * vec4(ScenaObj[j][k].boundingBoxMax, 1.0);
			vec4 boundGlobB = ScenaObj[j][k].ModelM * vec4(ScenaObj[j][k].boundingBoxMin, 1.0);

			//collisione asse x
			bool collisionX = boundGlobB.x <= pos.x &&
				boundGlobT.x >= pos.x;

			//collisione asse y
			bool collisionY = boundGlobB.y <= pos.y &&
				boundGlobT.y >= pos.y;
			//collisione asse z
			bool collisionZ = boundGlobB.z <= pos.z &&
				boundGlobT.z >= pos.z;

			//se ho una collisione fermo esco
			if (collisionX && collisionY && collisionZ) 
			{
				return true;
			}

		}
	}

	return false;
}

void modifyModelMatrix(vec3 translation_vector, vec3 rotation_vector, GLfloat angle, GLfloat scale_factor)
{
	// ricordare che mat4(1) costruisce una matrice identità di ordine 4
	mat4 traslation = translate(mat4(1), translation_vector);
	mat4 scales = scale(mat4(1), vec3(scale_factor, scale_factor, scale_factor));
	mat4 rotation = rotate(mat4(1), angle, rotation_vector);

	// Modifica la matrice di Modellazione dell'oggetto della scena selezionato postmolitplicando per le matrici scale*rotarion*traslation
	Scena[selected_obj].ModelM = Scena[selected_obj].ModelM * scales * rotation * traslation;

	glutPostRedisplay();
}

void moveCameraForward()
{
	ViewSetup.direction = ViewSetup.target - ViewSetup.position;
	vec4 pos = ViewSetup.position + ViewSetup.direction * cameraSpeed;
	if (!checkCollision(pos)) {
		ViewSetup.position = pos;
	}
}

void moveCameraBack()
{
	ViewSetup.direction = ViewSetup.target - ViewSetup.position;
	vec4 pos = ViewSetup.position - ViewSetup.direction * cameraSpeed;
	if (!checkCollision(pos)) {
		ViewSetup.position = pos;
	}
}

void moveCameraLeft()
{
	// Calcolo la direzione perpendicolare alla direzione della camera e l'alto della camera
	// e muovo la camera a sinistra lungo questa direzione
	ViewSetup.direction = ViewSetup.target - ViewSetup.position;
	vec3 direzione_scorrimento = cross(vec3(ViewSetup.direction), vec3(ViewSetup.upVector));
	vec4 pos = ViewSetup.position - vec4((direzione_scorrimento), .0) * cameraSpeed;
	if (!checkCollision(pos)) {
		ViewSetup.position = pos;
		ViewSetup.target -= vec4((direzione_scorrimento), .0) * cameraSpeed;
	}
}

void moveCameraRight()
{
	// Calcolo la direzione perpendicolare alla direzione della camera e l'alto della camera
	// e muovo la camera a destra lungo questa direzione
	ViewSetup.direction = ViewSetup.target - ViewSetup.position;
	vec3 direzione_scorrimento = cross(vec3(ViewSetup.direction), vec3(ViewSetup.upVector)) * cameraSpeed;	
	vec4 pos = ViewSetup.position + vec4(direzione_scorrimento, 0);
	if (!checkCollision(pos)) {
		ViewSetup.position = pos;
		ViewSetup.target += vec4(direzione_scorrimento, 0);
		
	}

}

void moveCameraUp()
{
	ViewSetup.direction = ViewSetup.target - ViewSetup.position; // Direzione lungo cui si sposta la telecamera in coordinate del mondo
	vec3 direzione_scorrimento = normalize(cross(vec3(ViewSetup.direction), vec3(ViewSetup.upVector)));
	vec3 upDirection = cross(vec3(ViewSetup.direction), direzione_scorrimento) * cameraSpeed;
	vec4 pos = ViewSetup.position - vec4(upDirection, 0.0);
	
	if (!checkCollision(pos)) {
		ViewSetup.target -= vec4(upDirection, 0.0);
		ViewSetup.position = pos;
	}
}

void moveCameraDown()
{
	ViewSetup.direction = ViewSetup.target - ViewSetup.position;
	vec3 direzione_scorrimento = normalize(cross(vec3(ViewSetup.direction), vec3(ViewSetup.upVector)));
	vec3 upDirection = cross(vec3(ViewSetup.direction), direzione_scorrimento) * cameraSpeed;
	vec4 pos = ViewSetup.position + vec4(upDirection, 0.0);
	
	if (!checkCollision(pos)) {
		ViewSetup.target += vec4(upDirection, 0.0);
		ViewSetup.position = pos;
	}
}

// Gestione eventi tastiera per il movimento della telecamera
void keyboardPressedEvent(unsigned char key, int x, int y)
{
	char *intStr;
	string str;
	switch (key)
	{
	// Ortogonal movemente
	case 'a':
		moveCameraLeft();
		break;
	case 'd':
		moveCameraRight();
		break;
	case 'w':
		moveCameraForward();
		break;
	case 's':
		moveCameraBack();
		break;

	// Up and Down
	case 'q':
		moveCameraUp();
		break;
	case 'e':
		moveCameraDown();
		break;

	// Visualizzazione ancora
	case 'v':
		visualizzaAncora = TRUE;
		break;

	// Si entra in modalit� di operazione traslazione
	case 'i':
		OperationMode = TRASLATING;
		Operazione = "TRASLAZIONE";
		break;
	// Si entra in modalit� di operazione rotazione
	case 'o':
		OperationMode = ROTATING;
		Operazione = "ROTAZIONE";
		break;
	// Si entra in modalit� di operazione scalatura
	case 'p':
		OperationMode = SCALING;
		Operazione = "SCALATURA";
		break;

	// Exit GUI
	case 27:
		glutLeaveMainLoop();
		break;

	// Seleziona l'asse X come asse lungo cui effettuare l'operazione selezionata (tra traslazione, rotazione, scalatura)
	case 'x':
		WorkingAxis = X;
		stringa_asse = " Asse X";
		break;
	// Seleziona l'asse Y come asse lungo cui effettuare l'operazione selezionata (tra traslazione, rotazione, scalatura)
	case 'y':
		WorkingAxis = Y;
		stringa_asse = " Asse Y";
		break;
	// Seleziona l'asse Z come asse lungo cui effettuare l'operazione selezionata (tra traslazione, rotazione, scalatura)
	case 'z':
		WorkingAxis = Z;
		stringa_asse = " Asse Z";
		break;
	default:
		break;
	}

	// Selezione dell'asse per le trasformazioni
	switch (WorkingAxis)
	{
	case X:
		asse = vec3(1.0, 0.0, 0.0);
		break;
	case Y:
		asse = vec3(0.0, 1.0, 0.0);
		break;
	case Z:
		asse = vec3(0.0, 0.0, 1.0);
		break;
	default:
		break;
	}

	// I tasti + e -  aggiornano lo spostamento a destra o a sinistra,
	// la rotazione in segno antiorario o in senso orario, la scalatura come
	// amplificazione o diminuizione delle dimensioni
	float amount = .01;
	if (key == 'm')
	{
		amount *= 1;
	}

	if (key == 'n')
	{
		amount *= -1;
	}

	switch (OperationMode)
	{

	// la funzione modifyModelMatrix() definisce la matrice di modellazione che si vuole postmoltiplicare
	//  alla matrice di modellazione dell'oggetto selezionato, per poterlo traslare, ruotare scalare.
	case TRASLATING:
		// si passa angle 0 e scale factor =1,
		modifyModelMatrix(asse * amount, asse, 0.0f, 1.0f);
		break;
	case ROTATING:
		// Si mette a zero il vettore di traslazione (vec3(0) e ad 1 il fattore di scale
		modifyModelMatrix(glm::vec3(0), asse, amount * 2.0f, 1.0f);
		break;
	case SCALING:
		// Si mette a zero il vettore di traslazione (vec3(0), angolo di rotazione a 0 e ad 1 il fattore di scala 1+amount.
		modifyModelMatrix(glm::vec3(0), asse, 0.0f, 1.0f + amount);
		break;
	}

	glutPostRedisplay();
}
