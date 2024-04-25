
#include <Windows.h>
#include <iostream> 

using namespace std;


const wchar_t* songs[] = {
    L"Blinding Lights.wav",
    L"Save Your Tears.wav",
    L"Starboy.wav",
    L"Heartless.wav",
    L"In Your Eyes.wav"
};
const wchar_t* authors[] = {
    L"The Weeknd",
    L"The Weeknd",
    L"The Weeknd",
    L"The Weeknd",
    L"The Weeknd"
};
const int numSongs = sizeof(songs) / sizeof(songs[0]);
int currentSongIndex = 0;
bool isPlaying = false;


void PlayCurrentSong(HWND hWnd);
void TogglePlayback(HWND hWnd);
void DrawUI(HWND hWnd);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MusicPlayerClass";
    RegisterClass(&wc);

    
    HWND hWnd = CreateWindowEx(0, L"MusicPlayerClass", L"Music Player", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, nullptr, nullptr, hInstance, nullptr);
    if (hWnd == nullptr) {
        MessageBox(nullptr, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    AllocConsole();
    FILE* pConsoleStream;
    freopen_s(&pConsoleStream, "CONOUT$", "w", stdout);


    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

void PlayCurrentSong(HWND hWnd) {
    if (!isPlaying) {
      
        isPlaying = true;
    }
    else {
        
        isPlaying = false;
    }

  
    DrawUI(hWnd);
}


void TogglePlayback(HWND hWnd) {
    PlayCurrentSong(hWnd);
}


void DrawUI(HWND hWnd) {
 
}