/* $Id: kill.c,v 1.1 2005/09/19 10:36:44 adx Exp $ */

#include <windows.h>
#include "setup.h"

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        LPSTR lpCmdLine, int nCmdShow)
{
  HWND wndhandle = FindWindow(PACKAGE_NAME, NULL);

  if (!wndhandle)
  {
    MessageBox(NULL, "ircd-hybrid is not running", NULL, MB_OK | MB_ICONERROR);
    return 1;
  }

  PostMessage(wndhandle, WM_CLOSE, 0, 0);
}
