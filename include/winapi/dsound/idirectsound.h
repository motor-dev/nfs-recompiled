#ifndef DSOUND_IDIRECTSOUND_H_
#define DSOUND_IDIRECTSOUND_H_

#include "winapi/com.h"

namespace win32 { namespace dsound
{

class IDirectSoundBuffer;
struct WAVEFORMATEX;
struct DSBUFFERDESC
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwBufferBytes;
    DWORD dwReserved;
    Packed<WAVEFORMATEX> lpwfxFormat;
    //GUID guid3DAlgorithm;
};

struct DSCAPS;
typedef IDirectSoundBuffer* LPDIRECTSOUNDBUFFER;
typedef Packed<IDirectSoundBuffer>* LPLPDIRECTSOUNDBUFFER;
typedef const DSBUFFERDESC* LPCDSBUFFERDESC;
typedef DSCAPS* LPDSCAPS;

class IDirectSound : public com::IUnknown
{
    friend class IDirectSoundBuffer;
public:
    IDirectSound();

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    HRESULT CreateSoundBuffer(WinApplication* app, x86::CPU& cpu,
                              LPCDSBUFFERDESC lpcDSBufferDesc, LPLPDIRECTSOUNDBUFFER lplpDirectSoundBuffer, IUnknown *pUnkOuter);
    HRESULT GetCaps(WinApplication* app, x86::CPU& cpu, LPDSCAPS lpDSCaps);
    HRESULT DuplicateSoundBuffer(WinApplication* app, x86::CPU& cpu, LPDIRECTSOUNDBUFFER lpDsbOriginal, LPLPDIRECTSOUNDBUFFER lplpDsbDuplicate);
    HRESULT SetCooperativeLevel(WinApplication* app, x86::CPU& cpu, HWND hwnd, DWORD dwLevel);
    HRESULT Compact(WinApplication* app, x86::CPU& cpu);
    HRESULT GetSpeakerConfig(WinApplication* app, x86::CPU& cpu, LPDWORD lpdwSpeakerConfig);
    HRESULT SetSpeakerConfig(WinApplication* app, x86::CPU& cpu, DWORD dwSpeakerConfig);
    HRESULT Initialize(WinApplication* app, x86::CPU& cpu, const GUID* lpcGuid);

private:
    static x86::reg32 s_iDirectSoundVtable;
};

}}

#endif /*!DSOUND_IDIRECTSOUND_H_*/
