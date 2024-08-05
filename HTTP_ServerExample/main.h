//#include <stdio.h>
//#include <stdlib.h>

// Engine
#include <Engine/PXEngine.h>

// PXUltima
#include <OS/Time/PXStopWatch.h>

PXRenderable _rectangleMesh;

PXFont* _font;


PXSkyBox* _skybox;
PXShaderProgram* _worldShader = 0;

PXModel* _Objekt;

//PXGravityCube _gravityField;

PXPrivate void PXAPI OnStartUpEvent(void* const owner, PXEngine* const pxEngine);
PXPrivate void PXAPI OnShutDownEvent(void* const owner, PXEngine* const pxEngine);
PXPrivate void PXAPI OnGameUpdateEvent(void* const owner, PXEngine* const pxEngine);
PXPrivate void PXAPI OnRenderUpdateEvent(void* const owner, PXEngine* const pxEngine);
