#include "splashscreen.h"
#include "cprocessing.h"

CP_Image logo;
CP_Color col;
int i = 0;

void splash_screen_init(void)
{
	logo = CP_Image_Load("./Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);

	CP_System_SetWindowSize(CP_Image_GetWidth(logo), CP_Image_GetHeight(logo));

	//initialize ball
	CP_Color red = CP_Color_Create(255, 0, 0, 255);
	CP_Settings_Fill(red);

}

void splash_screen_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(logo, 0.f, 0.f, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo), i += 150*CP_System_GetDt());
	if (i > 255)
	{
		i = 0;
	}
	CP_Vector pos = CP_Vector_Set(CP_Input_GetMouseX(),CP_Input_GetMouseY());
	CP_Graphics_DrawCircle(pos.x, pos.y, 50);
	if (CP_Input_KeyDown(KEY_Q))
	{
		CP_Engine_Terminate();
	}
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}