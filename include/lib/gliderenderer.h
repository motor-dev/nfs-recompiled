#ifndef LIB_GLIDERENDERER_H_
#define LIB_GLIDERENDERER_H_

#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32
{

class Renderer;
class GlideTMU;

enum TextureFormat
{
    TF_RGB_565,
    TF_ARGB_1555,
    TF_ARGB_4444,
};

enum AlphaBlend
{
    AB_1mSrcAlpha,
    AB_1
};

static const x86::reg32 RENDERER_NUM_TMU    = 2;

struct GrTmuVertex
{
    float  sow;
    float  tow;
    float  oow;
};

struct GrVertex
{
    float x, y, z;
    float r, g, b;
    float ooz;
    float a;
    float oow;
    GrTmuVertex  tmuvtx[RENDERER_NUM_TMU];
};

struct GlVertex;

struct DrawCall
{
    x86::reg32 lastTriangle;
    bool zTest;
    bool zBuffer;
    bool alphaBlend;
};

class GlideRenderer: public GenericResource
{
public:
    GlideRenderer(Renderer* renderer);
    ~GlideRenderer();

    void clear(x86::reg32 color);
    void swap();
    void render(x86::reg32 buffer);
    x86::reg32 textureMemStart(x86::reg32 tmu);
    x86::reg32 textureMemEnd(x86::reg32 tmu);
    x86::reg32 getTextureMemSize(x86::reg32 tmu, x86::reg32 largeMipmapSize, TextureFormat format);
    void setZWrite(bool enable);
    void setZTest(bool enable);
    void setAlphaBlendDst(AlphaBlend method);
    void setColorFactor(float colorFactor);
    void setAlphaFactor(float alphaFactor);
    void setTexture(x86::reg32 tmu, x86::reg32 address);
    void setTextureData(x86::reg32 tmu, x86::reg32 address, const void* data,
                        x86::reg32 largeMipmap, x86::reg32 smallMimmap, TextureFormat format);
    void drawTriangle(const GrVertex* a, const GrVertex* b, const GrVertex* c);
    
private:
    void compileShaders();
    void flush();

private:
    Renderer*               m_renderer;
    unsigned int            m_depthBuffer;
    unsigned int            m_framebuffer;
    GlVertex*               m_vertices;
    x86::reg32              m_vertexCount;
    std::vector<DrawCall>   m_drawCalls;
    unsigned int            m_vertexBuffer;
    unsigned int            m_vertexArray;
    unsigned int            m_shaderProgram;
    unsigned int            m_atlas;
    int                     m_attributes[5];
    int                     m_transform;
    //int                     m_textureBind;
    x86::reg32              m_textureOffsetX;
    x86::reg32              m_textureOffsetY;
    x86::reg32              m_textureOffsetW;
    float                   m_colorFactor;
    float                   m_alphaFactor;
    bool                    m_zBuffer;
    bool                    m_zTest;
    bool                    m_alphaBlend;
    GlideTMU*               m_tmus[2];
};

}

#endif
