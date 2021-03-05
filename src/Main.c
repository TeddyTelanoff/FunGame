#include <Windows.h>

#define PI 3.1415926535



int main()
{
	HWND console = GetConsoleWindow();
	HDC dc = GetDC(console);

	RECT consoleRect;
	GetWindowRect(console, &consoleRect);
	for (UINT32 y = 0; y < consoleRect.right; y++)
		for (UINT32 x = 0; x < consoleRect.bottom; x++)
			SetPixel(dc, x, y, 0x00FF00);

    ReleaseDC(console, dc);


}