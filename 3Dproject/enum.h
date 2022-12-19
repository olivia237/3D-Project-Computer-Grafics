#pragma once

typedef enum
{
	WIRE_FRAME,
	FACE_FILL,
	CULLING_ON,
	CULLING_OFF,
} MenuOption;

enum
{
	NAVIGATION,
	CAMERA_MOVING,
	TRASLATING,
	ROTATING,
	SCALING
} OperationMode;

enum
{
	X,
	Y,
	Z
} WorkingAxis;
