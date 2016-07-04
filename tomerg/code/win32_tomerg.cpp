/*=========================
$File: $
$Date: $
$Revision: $
$Creator: $Tomer Shaim
================================*/

#include <windows.h>

#define internal_f static
#define local_persist static
#define global_varaible static

global_varaible bool running;

internal void ResizeDIBSection(int width, int height) {
  /* code */
}

internal void updateWindow(HDC devcon, int x,int y, int width, int height){
  StretchDIBits(devcon, x,y,width,height,
                        x,y,width,height,
                      );
}

LRESULT CALLBACK MainWindowCallback(
  HWND   window,
  UINT   message,
  WPARAM wParam,
  LPARAM lParam)
  {
    LRESULT answer = 0;

    switch(message)
    {
      case WM_PAINT:
      {
        PAINTSTRUCT paint;
        HDC devcon = BeginPaint(window,&paint);
        int x = paint.rcPaint.left;
        int y = paint.rcPaint.top;
        int w = paint.rcPaint.right-x;
        int h = paint.rcPaint.bottom-y;
        updateWindow(devcon,x,y,w,h);

        EndPaint(window,&paint);
      }
      break;
      case WM_SIZE:
        RECT clientrect
        GetClientRect(window,&clientrect);
        int width = clientrect.right - clientrect.left;
        int height = clientrect.bottom - clientrect.top;
        ResizeDIBSection(width,height);
      break;
      case WM_DESTROY:
      running = false;
      break;
      case WM_CLOSE:
      running = false;

      //DefWindowProc(window,message,wParam,lParam);
      break;
      case WM_ACTIVATEAPP:
      OutputDebugStringA("WM_ACTIVATEAPP\n");
      break;
      default:
      OutputDebugStringA("default\n");
      answer = DefWindowProc(window,message,wParam,lParam);
      break;
      return answer;

    }
  }
  int CALLBACK WinMain(
    HINSTANCE Instance,
    HINSTANCE PrevInstance,
    LPSTR     CmdLine,
    int       nCmdShow)
    {

      WNDCLASS WindowClass = {};

      //TODO HREDRAW
      WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;     // The style of the window
      WindowClass.lpfnWndProc = MainWindowCallback;  // The pointer to theevent handler
      WindowClass.hInstance = Instance;    //who set the instance
      //WindowClass.hIcon;        //Icon
      //WindowClass.hCursor;      // cursor
      WindowClass.lpszClassName = "TomerGClass";   //name

      if (RegisterClass(&WindowClass)) {
        HWND WindowHandle = CreateWindowEx(0,WindowClass.lpszClassName,"Tomer wut",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,0,0,Instance,0);

        if(WindowHandle){

          running = true;
          while(running){
            MSG message;
            if(GetMessage(&message,0,0,0)>0) {
              TranslateMessage(&message); //Translating a message to something more useful
              DispatchMessage(&message);
            }
          }
        }
        else{
          //TODO logging
        }
      } else {
        //TODO logging
      }


      return(0);
    }
