#ifndef LIB_AUDIO_H_
#define LIB_AUDIO_H_
#include <lib/winapp.h>
#include <lib/memmap.h>
#include <SDL3/SDL.h>


namespace win32
{

class AudioBuffer;

class AudioDevice : public GenericResource
{
public:
    AudioDevice();
    ~AudioDevice();

    void play(AudioBuffer* buffer);
    void stop(AudioBuffer* buffer);
    SDL_AudioStream* stream() const { return m_stream; }

private:
    static void audioCallback22050(void *userdata, SDL_AudioStream *stream, int additional_amount, int total_amount);

private:
    SDL_AudioStream*            m_stream;
    std::vector<AudioBuffer*>   m_playingBuffers;
};

class AudioBuffer : public GenericResource
{
    friend class AudioDevice;
public:
    AudioBuffer(AudioDevice* device, WinApplication* app, x86::reg32 bufferSize);
    ~AudioBuffer();

    x86::reg32 bufferSize() const;
    void play();
    void stop();
    x86::reg32 lock();
    void unlock(x86::reg32 bufferWritten);
    x86::reg32 playStart() const        { return m_playStart; }
    x86::reg32 playStop() const         { return m_playStop; }
    x86::reg32 getBackBuffer() const    { return m_bufferMap->getBlockStart(); }
    bool primary() const                { return m_primary; }

private:
    void audioCallback22050(x86::reg8* stream, int len);

private:
    AudioDevice*    m_device;
    x86::reg32      m_bufferSize;
    MemMap*         m_memmap;
    MemMap*         m_bufferMap;
    x86::sreg16*    m_buffer;
    x86::reg32      m_playStart;
    x86::reg32      m_playStop;
    bool            m_primary;
};

}

#endif /*!LIB_AUDIO_H_*/
