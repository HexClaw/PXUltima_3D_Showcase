#pragma check_stack(off)

int _fltused = 0;

#include "main.h"

#include <OS/Console/PXConsole.h>
#include <OS/Memory/PXMemory.h>

#if !defined(_DEBUG) && defined(OSWindowsE)
#include <windows.h>
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
#else
int main(int amountOFParameters, char** parameter)
#endif
{
    PXEngine pxEngine;

    // Start
    {
        PXEngineStartInfo pxEngineStartInfo;
        PXClear(PXEngineStartInfo, &pxEngineStartInfo);
        pxEngineStartInfo.Mode = PXGraphicInitializeModeWindowfull;
        pxEngineStartInfo.System = PXGraphicSystemOpenGL;
        pxEngineStartInfo.OnStartUp = OnStartUpEvent;
        pxEngineStartInfo.OnShutDown = OnShutDownEvent;
   //     pxEngineStartInfo.OnUserUpdate = OnIntereact;
        pxEngineStartInfo.OnGameUpdate = OnGameUpdateEvent;
        pxEngineStartInfo.OnRenderUpdate = OnRenderUpdateEvent;
        pxEngineStartInfo.Name = "Model Example";
        pxEngineStartInfo.Owner = PXNull;
        pxEngineStartInfo.UseMouseInput = PXTrue;

        const PXActionResult startResult = PXEngineStart(&pxEngine, &pxEngineStartInfo);

        if (PXActionSuccessful != startResult)
        {
            return EXIT_FAILURE;
        }
    }

    while (PXEngineIsRunning(&pxEngine))
    {
        PXEngineUpdate(&pxEngine);
    }

    PXEngineStop(&pxEngine);

    return EXIT_SUCCESS;
}

void PXAPI OnIntereact(void* const owner, PXEngine* const pxEngine)
{
  /*if (!pxDialogBox.IsLocked)
    {
        pxDialogBox.IsLocked = PXTrue;

        PXEngineDialogBoxOpen(pxEngine, &pxDialogBox, _pxDialogMessagePage, 4);
    }
    else
    {
        PXEngineDialogBoxPageNext(pxEngine, &pxDialogBox);
    }

    */
}

void PXAPI OnStartUpEvent(void* const owner, PXEngine* const pxEngine)
{
    PXResourceCreateInfo pxResourceCreateInfo;

    PXGraphic* const pxGraphicContext = &pxEngine->Graphic;

    //PXWindowCursorCaptureMode(&bitFireEngine->WindowMain, PXWindowCursorLockAndHide);


    //-----------------------------------------------------
    // Object Shader
    //-----------------------------------------------------
    {
        PXClear(PXResourceCreateInfo, &pxResourceCreateInfo);
        pxResourceCreateInfo.Type = PXResourceTypeShaderProgram;
        pxResourceCreateInfo.ObjectReference = &_worldShader;
        pxResourceCreateInfo.ShaderProgram.ShaderVertexFilePath = "Shader/Object_Vertex.glsl";
        pxResourceCreateInfo.ShaderProgram.ShaderPixelFilePath = "Shader/Object_Fragment.glsl";

        PXEngineResourceCreate(pxEngine, &pxResourceCreateInfo);
    }

    //-----------------------------------------------------
    // SkyBox
    //-----------------------------------------------------
    {
        PXClear(PXResourceCreateInfo, &pxResourceCreateInfo);
        pxResourceCreateInfo.Type = PXResourceTypeSkybox;
        pxResourceCreateInfo.SpawnEnabled = PXTrue;
        pxResourceCreateInfo.ObjectReference = &_skybox;
        pxResourceCreateInfo.SkyBox.ShaderProgramCreateInfo.ShaderVertexFilePath = "Shader/SkyBox_Vertex.glsl";
        pxResourceCreateInfo.SkyBox.ShaderProgramCreateInfo.ShaderPixelFilePath = "Shader/SkyBox_Fragment.glsl";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureA = "Texture/SkyBox_Side.png";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureB = "Texture/SkyBox_Bottom.png";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureC = "Texture/SkyBox_Side.png";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureD = "Texture/SkyBox_Side.png";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureE = "Texture/SkyBox_Side.png";
        pxResourceCreateInfo.SkyBox.SkyBoxTextureF = "Texture/SkyBox_Top.png";

        PXEngineResourceCreate(pxEngine, &pxResourceCreateInfo);
    }

    //-----------------------------------------------------
    // Load Object
    //-----------------------------------------------------
    {
        PXClear(PXResourceCreateInfo, &pxResourceCreateInfo);
        pxResourceCreateInfo.Type = PXResourceTypeModel;
        pxResourceCreateInfo.ObjectReference = &_Objekt;
        pxResourceCreateInfo.FilePath = "Modelle/Milenia.obj";
        //pxResourceCreateInfo.FilePath = "Modelle/Tiger.obj";
        pxResourceCreateInfo.Model.ShaderProgramReference = _worldShader;
        pxResourceCreateInfo.Model.Scale = 1.0f;
        pxResourceCreateInfo.SpawnEnabled = PXTrue;

        PXEngineResourceCreate(pxEngine, &pxResourceCreateInfo);
    }
}

void PXAPI OnShutDownEvent(void* const owner, PXEngine* const pxEngine)
{

}

void PXAPI OnGameUpdateEvent(void* const owner, PXEngine* const pxEngine)
{
    //PXCameraFollow(pxEngine->CameraCurrent, pxEngine->TimeData.CounterTimeDelta);
}

void PXAPI OnRenderUpdateEvent(void* const owner, PXEngine* const pxEngine)
{

    //pxEngine->ResourceManager
}