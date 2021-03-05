#include <stdio.h>
#include <Windows.h>

#define PI 3.1415926535

void $PrintRECT(const RECT *rect)
{
	printf("%li, %li, %li, %li\n", rect->left, rect->top, rect->right, rect->bottom);
}

SIZE_T FunGame$GetRECTWidth(const RECT *rect)
{ return rect->right - rect->left; }

SIZE_T FunGame$GetRECTHeight(const RECT *rect)
{ return rect->bottom - rect->top; }

int main()
{
	HWND console = GetConsoleWindow();
	HDC dc = GetDC(console);

	HBRUSH brush = CreateSolidBrush(0x0000FF);
	HBRUSH pBrush = SelectObject(dc, brush);

	while (TRUE)
	{
		if (GetAsyncKeyState('Q') & 0x8000)
			break;

		RECT consoleRect;
		GetWindowRect(console, &consoleRect);
		$PrintRECT(&consoleRect);

		//POINT verts[] =
		//{
		//	{ 5, 5 },
		//	{ FunGame$GetRECTWidth(&consoleRect) - 5, 5 },
		//	{ FunGame$GetRECTWidth(&consoleRect) - 5, FunGame$GetRECTHeight(&consoleRect) - 5 },
		//	{ 5, FunGame$GetRECTHeight(&consoleRect) - 5 },
		//};
		//Polygon(dc, verts, sizeof(verts) / sizeof(*verts));
	}

	SelectObject(dc, pBrush);
	DeleteObject(pBrush);
	ReleaseDC(console, dc);
}