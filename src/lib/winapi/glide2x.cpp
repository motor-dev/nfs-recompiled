#include <winapi/glide2x.h>
#include <winapi/wrapper.h>
#include <lib/library.h>
#include <lib/renderer.h>
#include <lib/gliderenderer.h>
#include <lib/window.h>
#include <cmath>


namespace win32 { namespace glide2x
{

static Renderer* s_renderer;
static GlideRenderer* s_glideRenderer;

static const x86::reg32 GR_FOG_TABLE_SIZE   = 64;
static const x86::reg32 MAX_NUM_SST         = 4;
static const x86::reg32 GLIDE_NUM_TMU       = RENDERER_NUM_TMU;

typedef x86::reg32 GrScreenResolution_t;
static const GrScreenResolution_t GR_RESOLUTION_320x200 = 0x0;
static const GrScreenResolution_t GR_RESOLUTION_320x240 = 0x1;
static const GrScreenResolution_t GR_RESOLUTION_400x256 = 0x2;
static const GrScreenResolution_t GR_RESOLUTION_512x384 = 0x3;
static const GrScreenResolution_t GR_RESOLUTION_640x200 = 0x4;
static const GrScreenResolution_t GR_RESOLUTION_640x350 = 0x5;
static const GrScreenResolution_t GR_RESOLUTION_640x400 = 0x6;
static const GrScreenResolution_t GR_RESOLUTION_640x480 = 0x7;
static const GrScreenResolution_t GR_RESOLUTION_800x600 = 0x8;
static const GrScreenResolution_t GR_RESOLUTION_960x720 = 0x9;
static const GrScreenResolution_t GR_RESOLUTION_856x480 = 0xa;
static const GrScreenResolution_t GR_RESOLUTION_512x256 = 0xb;
static const GrScreenResolution_t GR_RESOLUTION_1024x768 = 0xc;
//static const GrScreenResolution_t GR_RESOLUTION_NONE = 0xff;
//static const GrScreenResolution_t GR_RESOLUTION_MIN = GR_RESOLUTION_320x200;
//static const GrScreenResolution_t GR_RESOLUTION_MAX = GR_RESOLUTION_1024x768;


typedef x86::reg32 GrScreenRefresh_t;
/*static const GrScreenRefresh_t GR_REFRESH_60Hz  = 0x0;
static const GrScreenRefresh_t GR_REFRESH_70Hz  = 0x1;
static const GrScreenRefresh_t GR_REFRESH_72Hz  = 0x2;
static const GrScreenRefresh_t GR_REFRESH_75Hz  = 0x3;
static const GrScreenRefresh_t GR_REFRESH_80Hz  = 0x4;
static const GrScreenRefresh_t GR_REFRESH_90Hz  = 0x5;
static const GrScreenRefresh_t GR_REFRESH_100Hz = 0x6;
static const GrScreenRefresh_t GR_REFRESH_85Hz  = 0x7;
static const GrScreenRefresh_t GR_REFRESH_120Hz = 0x8;
static const GrScreenRefresh_t GR_REFRESH_NONE  = 0xff;*/


typedef x86::reg32 GrColorFormat_t;
/*static const GrColorFormat_t GR_COLORFORMAT_ARGB = 0x0;
static const GrColorFormat_t GR_COLORFORMAT_ABGR = 0x1;*/


typedef x86::reg32 GrOriginLocation_t;
/*static const GrOriginLocation_t GR_ORIGIN_UPPER_LEFT = 0x0;
static const GrOriginLocation_t GR_ORIGIN_LOWER_LEFT = 0x1;
static const GrOriginLocation_t GR_ORIGIN_ANY = 0xff;*/


typedef x86::reg32 GrChipID_t;
//static const GrChipID_t GR_TMU0 = 0x0;
//static const GrChipID_t GR_TMU1 = 0x1;
//static const GrChipID_t GR_TMU2 = 0x2;
//static const GrChipID_t GR_FBI  = 0x3;

typedef x86::reg32 GrCmpFnc_t;
//static const GrCmpFnc_t GR_CMP_NEVER    = 0x0;
//static const GrCmpFnc_t GR_CMP_LESS     = 0x1;
//static const GrCmpFnc_t GR_CMP_EQUAL    = 0x2;
static const GrCmpFnc_t GR_CMP_LEQUAL   = 0x3;
static const GrCmpFnc_t GR_CMP_GREATER  = 0x4;
//static const GrCmpFnc_t GR_CMP_NOTEQUAL = 0x5;
//static const GrCmpFnc_t GR_CMP_GEQUAL   = 0x6;
static const GrCmpFnc_t GR_CMP_ALWAYS   = 0x7;

typedef x86::reg32 GrCombineFunction_t;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_ZERO                                       = 0x0;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_NONE                                       = GR_COMBINE_FUNCTION_ZERO;
static const GrCombineFunction_t GR_COMBINE_FUNCTION_LOCAL                                      = 0x1;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_LOCAL_ALPHA                                = 0x2;
static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER                                = 0x3;
static const GrCombineFunction_t GR_COMBINE_FUNCTION_BLEND_OTHER                                = GR_COMBINE_FUNCTION_SCALE_OTHER;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL                      = 0x4;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA                = 0x5;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL                    = 0x6;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL          = 0x7;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_BLEND                                      = GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA    = 0x8;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL                = 0x9;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_BLEND_LOCAL                                = GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL;
//static const GrCombineFunction_t GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA          = 0x10;

typedef x86::reg32 GrCombineFactor_t;
static const GrCombineFactor_t GR_COMBINE_FACTOR_ZERO                       = 0x0;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_NONE                       = GR_COMBINE_FACTOR_ZERO;
static const GrCombineFactor_t GR_COMBINE_FACTOR_LOCAL                      = 0x1;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_OTHER_ALPHA                = 0x2;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_LOCAL_ALPHA                = 0x3;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_TEXTURE_ALPHA              = 0x4;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_DETAIL_FACTOR              = GR_COMBINE_FACTOR_TEXTURE_ALPHA;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_LOD_FRACTION               = 0x5;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE                        = 0x8;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_LOCAL            = 0x9;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA      = 0xa;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA      = 0xb;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA    = 0xc;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR    = GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA;
//static const GrCombineFactor_t GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION     = 0xd;

typedef x86::reg32 GrCombineLocal_t;
static const GrCombineLocal_t GR_COMBINE_LOCAL_ITERATED = 0x0;
//static const GrCombineLocal_t GR_COMBINE_LOCAL_CONSTANT = 0x1;
//static const GrCombineLocal_t GR_COMBINE_LOCAL_NONE     = GR_COMBINE_LOCAL_CONSTANT;
//static const GrCombineLocal_t GR_COMBINE_LOCAL_DEPTH    = 0x2;

typedef x86::reg32 GrCombineOther_t;
//static const GrCombineOther_t GR_COMBINE_OTHER_ITERATED = 0x0;
static const GrCombineOther_t GR_COMBINE_OTHER_TEXTURE  = 0x1;
static const GrCombineOther_t GR_COMBINE_OTHER_CONSTANT = 0x2;
static const GrCombineOther_t GR_COMBINE_OTHER_NONE     = GR_COMBINE_OTHER_CONSTANT;

typedef x86::reg32 GrTextureCombineFnc_t;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_ZERO             = 0x0;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_DECAL            = 0x1;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_OTHER            = 0x2;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_ADD              = 0x3;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_MULTIPLY         = 0x4;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_SUBTRACT         = 0x5;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_DETAIL           = 0x6;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_DETAIL_OTHER     = 0x7;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_TRILINEAR_ODD    = 0x8;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_TRILINEAR_EVEN   = 0x9;
//static const GrCombineFunction_t GR_TEXTURECOMBINE_ONE              = 0xa;

typedef x86::reg32 GrAlphaBlendFnc_t;
static const GrAlphaBlendFnc_t GR_BLEND_ZERO                = 0x0;
static const GrAlphaBlendFnc_t GR_BLEND_SRC_ALPHA           = 0x1;
//static const GrAlphaBlendFnc_t GR_BLEND_SRC_COLOR           = 0x2;
//static const GrAlphaBlendFnc_t GR_BLEND_DST_COLOR           = GR_BLEND_SRC_COLOR;
//static const GrAlphaBlendFnc_t GR_BLEND_DST_ALPHA           = 0x3;
static const GrAlphaBlendFnc_t GR_BLEND_ONE                 = 0x4;
static const GrAlphaBlendFnc_t GR_BLEND_ONE_MINUS_SRC_ALPHA = 0x5;
//static const GrAlphaBlendFnc_t GR_BLEND_ONE_MINUS_SRC_COLOR = 0x6;
//static const GrAlphaBlendFnc_t GR_BLEND_ONE_MINUS_DST_COLOR = GR_BLEND_ONE_MINUS_SRC_COLOR;
//static const GrAlphaBlendFnc_t GR_BLEND_ONE_MINUS_DST_ALPHA = 0x7;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_8          = 0x8;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_9          = 0x9;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_A          = 0xa;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_B          = 0xb;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_C          = 0xc;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_D          = 0xd;
//static const GrAlphaBlendFnc_t GR_BLEND_RESERVED_E          = 0xe;
//static const GrAlphaBlendFnc_t GR_BLEND_ALPHA_SATURATE      = 0xf;
//static const GrAlphaBlendFnc_t GR_BLEND_PREFOG_COLOR        = GR_BLEND_ALPHA_SATURATE;

typedef x86::reg32 GrTexTable_t;
//static const GrTexTable_t GR_TEXTABLE_NCC0    = 0x0;
//static const GrTexTable_t GR_TEXTABLE_NCC1    = 0x1;
//static const GrTexTable_t GR_TEXTABLE_PALETTE = 0x2;

typedef int32_t GrTextureFilterMode_t;
//static const GrTextureFilterMode_t GR_TEXTUREFILTER_POINT_SAMPLED = 0x0;
static const GrTextureFilterMode_t GR_TEXTUREFILTER_BILINEAR      = 0x1;

typedef x86::reg32 GrTextureClampMode_t;
//static const GrTextureClampMode_t GR_TEXTURECLAMP_WRAP   = 0x0;
//static const GrTextureClampMode_t GR_TEXTURECLAMP_CLAMP  = 0x1;

typedef x86::reg32 GrColor_t;
typedef x86::reg8  GrAlpha_t;
typedef x86::reg32 GrMipMapId_t;
typedef x86::reg8  GrFog_t;

typedef x86::reg32 GrBuffer_t;
//static const GrBuffer_t GR_BUFFER_FRONTBUFFER  = 0x0;
//static const GrBuffer_t GR_BUFFER_BACKBUFFER   = 0x1;
//static const GrBuffer_t GR_BUFFER_AUXBUFFER    = 0x2;
//static const GrBuffer_t GR_BUFFER_DEPTHBUFFER  = 0x3;
//static const GrBuffer_t GR_BUFFER_ALPHABUFFER  = 0x4;
//static const GrBuffer_t GR_BUFFER_TRIPLEBUFFER = 0x5;

typedef x86::reg32 GrCullMode_t;
//static const GrCullMode_t GR_CULL_DISABLE      = 0x0;
//static const GrCullMode_t GR_CULL_NEGATIVE     = 0x1;
//static const GrCullMode_t GR_CULL_POSITIVE     = 0x2;

typedef x86::reg32 GrDitherMode_t;
//static const GrDitherMode_t GR_DITHER_DISABLE  = 0x0;
//static const GrDitherMode_t GR_DITHER_2x2      = 0x1;
//static const GrDitherMode_t GR_DITHER_4x4      = 0x2;

typedef x86::reg32 GrFogMode_t;
//static const GrFogMode_t GR_FOG_DISABLE             = 0x0;
//static const GrFogMode_t GR_FOG_WITH_ITERATED_ALPHA = 0x1;
//static const GrFogMode_t GR_FOG_WITH_TABLE          = 0x2;
//static const GrFogMode_t GR_FOG_MULT2               = 0x100;
//static const GrFogMode_t GR_FOG_ADD2                = 0x200;

typedef x86::reg32 GrDepthBufferMode_t;
//static const GrDepthBufferMode_t GR_DEPTHBUFFER_DISABLE                     = 0x0;
//static const GrDepthBufferMode_t GR_DEPTHBUFFER_ZBUFFER                     = 0x1;
//static const GrDepthBufferMode_t GR_DEPTHBUFFER_WBUFFER                     = 0x2;
//static const GrDepthBufferMode_t GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS     = 0x3;
//static const GrDepthBufferMode_t GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS     = 0x4;

typedef x86::reg32 GrChromakeyMode_t;
//static const GrChromakeyMode_t GR_CHROMAKEY_DISABLE     = 0x0;
//static const GrChromakeyMode_t GR_CHROMAKEY_ENABLE      = 0x1;

typedef x86::reg32 GrLock_t;
//static const GrLock_t GR_LFB_READ_ONLY  = 0x00;
static const GrLock_t GR_LFB_WRITE_ONLY = 0x01;
//static const GrLock_t GR_LFB_IDLE       = 0x00;
//static const GrLock_t GR_LFB_NOIDLE     = 0x10;

typedef x86::reg32 GrLfbBypassMode_t;
//static const GrLfbBypassMode_t GR_LFBBYPASS_DISABLE = 0x0;
//static const GrLfbBypassMode_t GR_LFBBYPASS_ENABLE  = 0x1;

typedef x86::reg32 GrLfbWriteMode_t;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_565           = 0x0; /* RGB:RGB */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_555           = 0x1; /* RGB:RGB */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_1555          = 0x2; /* ARGB:ARGB */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED1     = 0x3;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_888           = 0x4; /* RGB */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_8888          = 0x5; /* ARGB */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED2     = 0x6;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED3     = 0x7;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED4     = 0x8;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED5     = 0x9;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED6     = 0xa;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_RESERVED7     = 0xb;
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_565_DEPTH     = 0xc; /* RGB:DEPTH */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_555_DEPTH     = 0xd; /* RGB:DEPTH */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_1555_DEPTH    = 0xe; /* ARGB:DEPTH */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_ZA16          = 0xf; /* DEPTH:DEPTH */
//static const GrLfbWriteMode_t GR_LFBWRITEMODE_ANY           = 0xff;

typedef x86::reg32 GrLfbSrcFmt_t;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_565           = 0x00;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_555           = 0x01;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_1555          = 0x02;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_888           = 0x04;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_8888          = 0x05;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_565_DEPTH     = 0x0c;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_555_DEPTH     = 0x0d;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_1555_DEPTH    = 0x0e;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_ZA16          = 0x0f;
//static const GrLfbSrcFmt_t GR_LFB_SRC_FMT_RLE16         = 0x80;

typedef x86::reg32 GrLOD_t;
//static const GrLOD_t GR_LOD_256                 = 0x0;
//static const GrLOD_t GR_LOD_128                 = 0x1;
//static const GrLOD_t GR_LOD_64                  = 0x2;
//static const GrLOD_t GR_LOD_32                  = 0x3;
//static const GrLOD_t GR_LOD_16                  = 0x4;
//static const GrLOD_t GR_LOD_8                   = 0x5;
//static const GrLOD_t GR_LOD_4                   = 0x6;
//static const GrLOD_t GR_LOD_2                   = 0x7;
//static const GrLOD_t GR_LOD_1                   = 0x8;

struct GrLfbInfo_t
{
    x86::sreg32         size;
    Packed<void>        lfbPtr;
    x86::reg32          strideInBytes;
    GrLfbWriteMode_t    writeMode;
    GrOriginLocation_t  origin;
};

typedef x86::reg32 GrMipMapMode_t;
//static const GrMipMapMode_t GR_MIPMAP_DISABLE           = 0x0; /* no mip mapping  */
//static const GrMipMapMode_t GR_MIPMAP_NEAREST           = 0x1; /* use nearest mipmap */
//static const GrMipMapMode_t GR_MIPMAP_NEAREST_DITHER    = 0x2; /* GR_MIPMAP_NEAREST + LOD dith */


typedef x86::reg32 GrAspectRatio_t;
//static const GrAspectRatio_t GR_ASPECT_8x1  = 0x0;       /* 8W x 1H */
//static const GrAspectRatio_t GR_ASPECT_4x1  = 0x1;       /* 4W x 1H */
//static const GrAspectRatio_t GR_ASPECT_2x1  = 0x2;       /* 2W x 1H */
static const GrAspectRatio_t GR_ASPECT_1x1  = 0x3;       /* 1W x 1H */
//static const GrAspectRatio_t GR_ASPECT_1x2  = 0x4;       /* 1W x 2H */
//static const GrAspectRatio_t GR_ASPECT_1x4  = 0x5;       /* 1W x 4H */
//static const GrAspectRatio_t GR_ASPECT_1x8  = 0x6;       /* 1W x 8H */

typedef x86::reg32 GrTextureFormat_t;
//static const GrTextureFormat_t GR_TEXFMT_8BIT               = 0x0;
//static const GrTextureFormat_t GR_TEXFMT_RGB_332            = GR_TEXFMT_8BIT;
//static const GrTextureFormat_t GR_TEXFMT_YIQ_422            = 0x1;
//static const GrTextureFormat_t GR_TEXFMT_ALPHA_8            = 0x2; /* (0..0xFF) alpha     */
//static const GrTextureFormat_t GR_TEXFMT_INTENSITY_8        = 0x3; /* (0..0xFF) intensity */
//static const GrTextureFormat_t GR_TEXFMT_ALPHA_INTENSITY_44 = 0x4;
//static const GrTextureFormat_t GR_TEXFMT_P_8                = 0x5; /* 8-bit palette */
//static const GrTextureFormat_t GR_TEXFMT_RSVD0              = 0x6;
//static const GrTextureFormat_t GR_TEXFMT_RSVD1              = 0x7;
//static const GrTextureFormat_t GR_TEXFMT_16BIT              = 0x8;
//static const GrTextureFormat_t GR_TEXFMT_ARGB_8332          = GR_TEXFMT_16BIT;
//static const GrTextureFormat_t GR_TEXFMT_AYIQ_8422          = 0x9;
static const GrTextureFormat_t GR_TEXFMT_RGB_565            = 0xa;
static const GrTextureFormat_t GR_TEXFMT_ARGB_1555          = 0xb;
static const GrTextureFormat_t GR_TEXFMT_ARGB_4444          = 0xc;
//static const GrTextureFormat_t GR_TEXFMT_ALPHA_INTENSITY_88 = 0xd;
//static const GrTextureFormat_t GR_TEXFMT_AP_88              = 0xe; /* 8-bit alpha 8-bit palette */
//static const GrTextureFormat_t GR_TEXFMT_RSVD2              = 0xf;

struct GrTexInfo
{
    GrLOD_t           smallLod;
    GrLOD_t           largeLod;
    GrAspectRatio_t   aspectRatio;
    GrTextureFormat_t format;
    Packed<void>      data;
};

typedef x86::reg32 GrHints_t;

typedef x86::reg32 GrSstType;

//static const GrSstType GR_SSTTYPE_VOODOO = 0;
//static const GrSstType GR_SSTTYPE_SST96 = 1;
//static const GrSstType GR_SSTTYPE_AT3D = 2;
static const GrSstType GR_SSTTYPE_Voodoo2 = 3;
//static const GrSstType GR_SSTTYPE_Banshee = 4;
//static const GrSstType GR_SSTTYPE_Voodoo3 = 5;
//static const GrSstType GR_SSTTYPE_Voodoo4 = 6;
//static const GrSstType GR_SSTTYPE_Voodoo5 = 7;

struct GrTMUConfig_t
{
    x86::reg32 tmuRev;
    x86::reg32 tmuRam;
};

struct GrHwConfiguration
{
    x86::sreg32 num_sst;
    struct SstCard_St
    {
        GrSstType type;         /* Which hardware is it? */
        x86::reg32 fbRam;       /* 1, 2, or 4 MB */
        x86::reg32 fbiRev;      /* Rev of Pixelfx chip */
        x86::reg32 nTexelfx;    /* How many texelFX chips are there? */
        x86::reg32 sli;         /* SLI interleaved support */
        GrTMUConfig_t tmuConfig[GLIDE_NUM_TMU]; /* Configuration of the Texelfx chips */
    } SSTs[MAX_NUM_SST];
};

static void grGlideInit(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    s_renderer = nullptr;
    s_glideRenderer = nullptr;
}

static void grGlideShutdown(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    if (s_glideRenderer)
    {
        app->freeResource(s_glideRenderer->getResourceIndex());
        s_glideRenderer = nullptr;
    }
    if (s_renderer)
    {
        app->freeResource(s_renderer->getResourceIndex());
        s_renderer = nullptr;
    }
}

static x86::reg32 grSstQueryHardware(WinApplication* app, x86::CPU& cpu, GrHwConfiguration *hwconfig)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    memset(hwconfig, 0, sizeof(GrHwConfiguration));
    hwconfig->num_sst = 1;
    hwconfig->SSTs[0].type = GR_SSTTYPE_Voodoo2;
    hwconfig->SSTs[0].fbRam = 16;
    hwconfig->SSTs[0].fbiRev = 222;
    hwconfig->SSTs[0].nTexelfx = 1;
    hwconfig->SSTs[0].sli = 0;
    hwconfig->SSTs[0].tmuConfig[0].tmuRev = 1;
    hwconfig->SSTs[0].tmuConfig[0].tmuRam = 16;
    return true;
}

static x86::reg32 grSstQueryBoards(WinApplication* app, x86::CPU& cpu, GrHwConfiguration *hwconfig)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    memset(hwconfig, 0, sizeof(GrHwConfiguration));
    hwconfig->num_sst = 1;
    return true;
}

static void grSstSelect(WinApplication* app, x86::CPU& cpu, x86::sreg32 sst)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(sst == 0);
}

static x86::reg32 grSstWinOpen(WinApplication* app, x86::CPU& cpu, HWND hWnd,
                               GrScreenResolution_t resolution, GrScreenRefresh_t refreshRate, GrColorFormat_t format,
                               GrOriginLocation_t origin, x86::sreg32 nColBuffers, x86::sreg32 nAuxBuffers)
{
    NFS2_USE(cpu);
    NFS2_USE(refreshRate);
    NFS2_USE(format);
    NFS2_USE(origin);
    NFS2_USE(nColBuffers);
    NFS2_USE(nAuxBuffers);

    x86::sreg32 width, height;
    switch(resolution)
    {
    case GR_RESOLUTION_320x200:
        width = 320;
        height = 200;
        break;
    case GR_RESOLUTION_320x240:
        width = 320;
        height = 240;
        break;
    case GR_RESOLUTION_400x256:
        width = 400;
        height = 256;
        break;
    case GR_RESOLUTION_512x384:
        width = 512;
        height = 384;
        break;
    case GR_RESOLUTION_640x200:
        width = 640;
        height = 200;
        break;
    case GR_RESOLUTION_640x350:
        width = 640;
        height = 350;
        break;
    case GR_RESOLUTION_640x400:
        width = 640;
        height = 400;
        break;
    case GR_RESOLUTION_640x480:
        width = 640;
        height = 480;
        break;
    case GR_RESOLUTION_800x600:
        width = 800;
        height = 600;
        break;
    case GR_RESOLUTION_960x720:
        width = 960;
        height = 720;
        break;
    case GR_RESOLUTION_856x480:
        width = 856;
        height = 480;
        break;
    case GR_RESOLUTION_512x256:
        width = 512;
        height = 256;
        break;
    case GR_RESOLUTION_1024x768:
        width = 1024;
        height = 768;
        break;
    }
    s_renderer = new Renderer(app, dynamic_cast<Window*>(app->getResource(hWnd)));
    s_renderer->setVideoMode(width, height, 16);
    app->allocateResource(s_renderer);
    s_glideRenderer = new GlideRenderer(s_renderer);
    app->allocateResource(s_glideRenderer);
    x86::reg16 data = 0xff;
    s_glideRenderer->setTextureData(0, 0, &data, 8, 8, TF_ARGB_4444);
    return true;
}

static void grSstWinClose(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    if (s_glideRenderer)
    {
        app->freeResource(s_glideRenderer->getResourceIndex());
        s_glideRenderer = nullptr;
    }
    if (s_renderer)
    {
        app->freeResource(s_renderer->getResourceIndex());
        s_renderer = nullptr;
    }
}

static x86::reg32 grSstStatus(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0x0fff03f;
}

static x86::reg32 grSstVRetraceOn(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

static void grSstIdle(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    //NFS2_ASSERT(false);
}

static void grTexCombineFunction(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, GrTextureCombineFnc_t fnc)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(fnc);
    NFS2_ASSERT(false);
}

static void grChromakeyValue(WinApplication* app, x86::CPU& cpu, GrColor_t  color)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(color);
    //NFS2_ASSERT(false);
}

static void grAlphaTestReferenceValue(WinApplication* app, x86::CPU& cpu, GrAlpha_t value)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(value);
    //NFS2_ASSERT(false);
}

static void grTexDownloadTable(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, GrTexTable_t type, void *data)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(type);
    NFS2_USE(data);
    NFS2_ASSERT(false);
}

static void grRenderBuffer(WinApplication* app, x86::CPU& cpu, GrBuffer_t buffer)
{    
    NFS2_USE(app);
    NFS2_USE(cpu);
    s_glideRenderer->render(buffer);;
}

static void grBufferClear(WinApplication* app, x86::CPU& cpu, GrColor_t color, GrAlpha_t alpha, x86::reg16 depth)
{
    //NFS2_ASSERT(color == 0);
    NFS2_ASSERT(alpha == 0);
    NFS2_ASSERT(depth == 65535);
    app->unlockContext(cpu);
    s_glideRenderer->clear(color);
    app->lockContext(cpu);
}

static void grBufferSwap(WinApplication* app, x86::CPU& cpu, x86::reg32 swapInterval)
{
    NFS2_ASSERT(swapInterval == 1);
    app->unlockContext(cpu);
    s_glideRenderer->swap();
    app->lockContext(cpu);
}

static void grSstIsBusy(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

static void grClipWindow(WinApplication* app, x86::CPU& cpu,
                         x86::reg32 minX, x86::reg32 minY, x86::reg32 maxX, x86::reg32 maxY)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(minX);
    NFS2_USE(minY);
    NFS2_USE(maxX);
    NFS2_USE(maxY);
    //NFS2_ASSERT(false);
}

static void grColorCombine(WinApplication* app, x86::CPU& cpu,
                           GrCombineFunction_t function, GrCombineFactor_t factor,
                           GrCombineLocal_t local, GrCombineOther_t other, BOOL invert)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(function == GR_COMBINE_FUNCTION_LOCAL || function == GR_COMBINE_FUNCTION_BLEND_OTHER);
    NFS2_ASSERT(factor == GR_COMBINE_FACTOR_ZERO || factor == GR_COMBINE_FACTOR_LOCAL);
    NFS2_ASSERT(local == GR_COMBINE_LOCAL_ITERATED);
    NFS2_ASSERT(other == GR_COMBINE_OTHER_NONE || other == GR_COMBINE_OTHER_TEXTURE);
    NFS2_ASSERT(!invert);
    if (factor == GR_COMBINE_FACTOR_ZERO)
    {
        s_glideRenderer->setColorFactor(0.f);
    }
    else
    {
        s_glideRenderer->setColorFactor(1.f);
    }
    if (other == GR_COMBINE_OTHER_NONE)
    {
        s_glideRenderer->setTexture(0, 0);
    }
}

static void grAlphaCombine(WinApplication* app, x86::CPU& cpu,
                           GrCombineFunction_t function, GrCombineFactor_t factor,
                           GrCombineLocal_t local, GrCombineOther_t other, BOOL invert)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(function == GR_COMBINE_FUNCTION_LOCAL || function == GR_COMBINE_FUNCTION_BLEND_OTHER);
    NFS2_ASSERT(factor == GR_COMBINE_FACTOR_ZERO || factor == GR_COMBINE_FACTOR_LOCAL);
    NFS2_ASSERT(local == GR_COMBINE_LOCAL_ITERATED);
    NFS2_ASSERT(other == GR_COMBINE_OTHER_NONE || other == GR_COMBINE_OTHER_TEXTURE);
    NFS2_ASSERT(!invert);
    if (factor == GR_COMBINE_FACTOR_ZERO)
    {
        s_glideRenderer->setAlphaFactor(0.f);
    }
    else
    {
        s_glideRenderer->setAlphaFactor(1.f);
    }
    // rely on Alpha combine to be done as Color combine
}

static void grAlphaBlendFunction(WinApplication* app, x86::CPU& cpu,
                                 GrAlphaBlendFnc_t rgb_sf, GrAlphaBlendFnc_t rgb_df,
                                 GrAlphaBlendFnc_t alpha_sf, GrAlphaBlendFnc_t alpha_df)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(rgb_sf == GR_BLEND_SRC_ALPHA);
    NFS2_ASSERT(alpha_sf == GR_BLEND_ONE);
    NFS2_ASSERT(alpha_df == GR_BLEND_ZERO);
    switch(rgb_df)
    {
    case GR_BLEND_ONE_MINUS_SRC_ALPHA:
        s_glideRenderer->setAlphaBlendDst(AB_1mSrcAlpha);
        break;
    case GR_BLEND_ONE:
        s_glideRenderer->setAlphaBlendDst(AB_1);
        break;
    default:
        NFS2_ASSERT(false);
    }
}

static void grCullMode(WinApplication* app, x86::CPU& cpu, GrCullMode_t mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(mode);
    //NFS2_ASSERT(false);
}

static void grTexFilterMode(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu,
                            GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(minfilter_mode);
    NFS2_USE(magfilter_mode);
    NFS2_ASSERT(minfilter_mode == GR_TEXTUREFILTER_BILINEAR);
    NFS2_ASSERT(magfilter_mode == GR_TEXTUREFILTER_BILINEAR);
}

static void grDitherMode(WinApplication* app, x86::CPU& cpu, GrDitherMode_t mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(mode);
    //NFS2_ASSERT(false);
}

static void grChromakeyMode(WinApplication* app, x86::CPU& cpu, GrChromakeyMode_t mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(mode);
    //NFS2_ASSERT(false);
}

static void grAlphaTestFunction(WinApplication* app, x86::CPU& cpu, GrCmpFnc_t function)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(function == GR_CMP_GREATER);
}

static void grDepthBufferMode(WinApplication* app, x86::CPU& cpu, GrDepthBufferMode_t mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(mode);
    //NFS2_ASSERT(mode == GR_DEPTHBUFFER_ZBUFFER);
}

static void grDepthBufferFunction(WinApplication* app, x86::CPU& cpu, GrCmpFnc_t function)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(function == GR_CMP_LEQUAL || function == GR_CMP_ALWAYS);
    s_glideRenderer->setZTest(function == GR_CMP_LEQUAL);
}

static void grDepthMask(WinApplication* app, x86::CPU& cpu, x86::reg32 mask)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(mask == 0 || mask == 1);
    s_glideRenderer->setZWrite(mask == 1);
}

static void grFogColorValue(WinApplication* app, x86::CPU& cpu, GrColor_t fogcolor)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(fogcolor);
    //NFS2_ASSERT(false);
}

static void grFogMode(WinApplication* app, x86::CPU& cpu, GrFogMode_t mode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(mode);
    //NFS2_ASSERT(false);
}

static void grFogTable(WinApplication* app, x86::CPU& cpu, const GrFog_t ft[GR_FOG_TABLE_SIZE])
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(ft);
    //NFS2_ASSERT(false);
}

static x86::reg32 grLfbLock(WinApplication* app, x86::CPU& cpu, GrLock_t type, GrBuffer_t buffer,
                            GrLfbWriteMode_t writeMode, GrOriginLocation_t origin, BOOL pixelPipeline, GrLfbInfo_t *info)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pixelPipeline);
    if (type == GR_LFB_WRITE_ONLY)
    {
        info->strideInBytes = s_renderer->getWidth() * 2;
        //info->size = s_renderer->getWidth() * s_renderer->getHeight() * 2;
        info->lfbPtr = Packed<void>(s_renderer->lock(buffer));
        info->origin = origin;
        info->writeMode = writeMode;
        return 1;
    }
    else
    {
        return 0;
    }
}

static x86::reg32 grLfbUnlock(WinApplication* app, x86::CPU& cpu, GrLock_t type, GrBuffer_t buffer)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (type == GR_LFB_WRITE_ONLY)
    {
        s_renderer->unlock(buffer);
        return 1;
    }
    else
    {
        return 0;
    }
}

static x86::reg32 grLfbWriteRegion(WinApplication* app, x86::CPU& cpu,
                                   GrBuffer_t dst_buffer, x86::reg32 dst_x, x86::reg32 dst_y, GrLfbSrcFmt_t src_format,
                                   x86::reg32 src_width, x86::reg32 src_height, x86::reg32 pixelPipeline, x86::reg32 src_stride, void* src_data)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dst_buffer);
    NFS2_USE(dst_x);
    NFS2_USE(dst_y);
    NFS2_USE(src_format);
    NFS2_USE(src_width);
    NFS2_USE(src_height);
    NFS2_USE(pixelPipeline);
    NFS2_USE(src_stride);
    NFS2_USE(src_data);
    NFS2_ASSERT(false);
    return 0;
}

static x86::reg32 grLfbReadRegion(WinApplication* app, x86::CPU& cpu,
                                  GrBuffer_t src_buffer, x86::reg32 src_x, x86::reg32 src_y,
                                  x86::reg32 src_width, x86::reg32 src_height, x86::reg32 dst_stride, void *dst_data)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(src_buffer);
    NFS2_USE(src_x);
    NFS2_USE(src_y);
    NFS2_USE(src_width);
    NFS2_USE(src_height);
    NFS2_USE(dst_stride);
    NFS2_USE(dst_data);
    NFS2_ASSERT(false);
    return 0;
}

static void grDrawTriangle(WinApplication* app, x86::CPU& cpu, const GrVertex* a, const GrVertex* b, const GrVertex* c)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    s_glideRenderer->drawTriangle(a, b, c);
}

static void grDrawLine(WinApplication* app, x86::CPU& cpu, const GrVertex *a, const GrVertex *b)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    float orthX = a->y - b->y;
    float orthY = b->x - a->x;
    float len = ::sqrt(orthX*orthX + orthY * orthY);
    orthX /= len / 2;
    orthY /= len / 2;
    GrVertex a1 = *a;
    a1.a = 0;
    a1.x -= orthX;
    a1.y -= orthY;
    GrVertex a2 = *a;
    GrVertex a3 = *a;
    a3.a = 0;
    a3.x += orthX;
    a3.y += orthY;
    GrVertex b1 = *b;
    b1.a = 0;
    b1.x -= orthX;
    b1.y -= orthY;
    GrVertex b2 = *b;
    GrVertex b3 = *b;
    b3.a = 0;
    b3.x += orthX;
    b3.y += orthY;
    s_glideRenderer->drawTriangle(&a1, &b1, &a2);
    s_glideRenderer->drawTriangle(&b1, &b2, &a2);
    s_glideRenderer->drawTriangle(&a2, &b2, &a3);
    s_glideRenderer->drawTriangle(&b2, &b3, &a3);
}

static void grDrawPoint(WinApplication* app, x86::CPU& cpu, const GrVertex *a)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(a);
    NFS2_ASSERT(false);
}

static void grGammaCorrectionValue(WinApplication* app, x86::CPU& cpu, float correction)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(correction);
    //NFS2_ASSERT(false);
}

static void grDepthBiasLevel(WinApplication* app, x86::CPU& cpu, x86::sreg16 bias)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(bias);
    NFS2_ASSERT(bias == 0);
}

static void grTexMipMapMode(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, GrMipMapMode_t mode, BOOL lodBlend)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(mode);
    NFS2_USE(lodBlend);
    NFS2_ASSERT(tmu == 0);
    //NFS2_ASSERT(false);
}

static void grTexCombine(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu,
                         GrCombineFunction_t rgb_function, GrCombineFactor_t rgb_factor,
                         GrCombineFunction_t alpha_function, GrCombineFactor_t alpha_factor,
                         BOOL rgb_invert, BOOL alpha_invert)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(tmu == 0);
    NFS2_ASSERT(rgb_function == GR_COMBINE_FUNCTION_LOCAL);
    NFS2_ASSERT(rgb_factor == GR_COMBINE_FACTOR_ZERO);
    NFS2_ASSERT(alpha_function == GR_COMBINE_FUNCTION_LOCAL);
    NFS2_ASSERT(alpha_factor == GR_COMBINE_FACTOR_ZERO);
    NFS2_ASSERT(!rgb_invert);
    NFS2_ASSERT(!alpha_invert);
    //NFS2_ASSERT(false);
}

static x86::reg32 grTexCalcMemRequired(WinApplication* app, x86::CPU& cpu,
                                       GrLOD_t lodmin, GrLOD_t lodmax, GrAspectRatio_t aspect, GrTextureFormat_t fmt)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(fmt);
    NFS2_ASSERT(aspect == GR_ASPECT_1x1);
    return s_glideRenderer->getTextureMemSize(256 >> lodmin, 256 >> lodmax, TF_RGB_565);
}

static void grTexDownloadMipMap(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu,
                                x86::reg32 startAddress, x86::reg32 evenOdd, GrTexInfo* info)
{
    NFS2_USE(evenOdd);
    NFS2_ASSERT(tmu == 0);
    NFS2_ASSERT(info->aspectRatio == GR_ASPECT_1x1);
    app->unlockContext(cpu);
    if (info->format == GR_TEXFMT_RGB_565)
    {
        s_glideRenderer->setTextureData(tmu, startAddress, app->getMemory<const void>(info ->data),
                                        info->largeLod, info->smallLod, TF_RGB_565);
    }
    else if (info->format == GR_TEXFMT_ARGB_1555)
    {
        s_glideRenderer->setTextureData(tmu, startAddress, app->getMemory<const void>(info ->data),
                                        info->largeLod, info->smallLod, TF_ARGB_1555);
    }
    else if (info->format == GR_TEXFMT_ARGB_4444)
    {
        s_glideRenderer->setTextureData(tmu, startAddress, app->getMemory<const void>(info ->data),
                                        info->largeLod, info->smallLod, TF_ARGB_4444);
    }
    else
    {
        NFS2_ASSERT(false);
    }
    app->lockContext(cpu);
}

static x86::reg32 grTexMinAddress(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 16*1024*1024 * tmu + s_glideRenderer->getTextureMemSize(1, 1, TF_RGB_565);
}

static x86::reg32 grTexMaxAddress(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 16*1024*1024 * (tmu+1);
}

static void grTexSource(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(startAddress);
    NFS2_USE(evenOdd);
    NFS2_USE(info);
    NFS2_ASSERT(tmu == 0);
    NFS2_ASSERT(info->aspectRatio == GR_ASPECT_1x1);
    s_glideRenderer->setTexture(tmu, startAddress);
}

static void grTexClampMode(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, GrTextureClampMode_t s_clampmode, GrTextureClampMode_t t_clampmode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(s_clampmode);
    NFS2_USE(t_clampmode);
    /*NFS2_ASSERT(s_clampmode == GR_TEXTURECLAMP_CLAMP);
    NFS2_ASSERT(t_clampmode == GR_TEXTURECLAMP_CLAMP);*/
}

static void grGlideGetVersion(WinApplication* app, x86::CPU& cpu, char* version)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(version);
    NFS2_ASSERT(false);
}

static void grAADrawTriangle(WinApplication* app, x86::CPU& cpu, const GrVertex *a, const GrVertex *b, const GrVertex *c,
                             BOOL ab_antialias, BOOL bc_antialias, BOOL ca_antialias)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(a);
    NFS2_USE(b);
    NFS2_USE(c);
    NFS2_USE(ab_antialias);
    NFS2_USE(bc_antialias);
    NFS2_USE(ca_antialias);
    NFS2_ASSERT(false);
}

static void grAADrawLine(WinApplication* app, x86::CPU& cpu, const GrVertex *a, const GrVertex *b)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(a);
    NFS2_USE(b);
    NFS2_ASSERT(false);
}

static void grHints(WinApplication* app, x86::CPU& cpu, GrHints_t type, x86::reg32 hintMask)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(type);
    NFS2_USE(hintMask);
    //NFS2_ASSERT(false);
}

static void grTexLodBiasValue(WinApplication* app, x86::CPU& cpu, GrChipID_t tmu, float bias)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(tmu);
    NFS2_USE(bias);
    //NFS2_ASSERT(false);
}

static x86::reg32 grSstScreenWidth(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return s_renderer->getWidth();
}

static x86::reg32 grSstScreenHeight(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return s_renderer->getHeight();
}

static x86::sreg32 grBufferNumPending(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

static BOOL grSstControl(WinApplication* app, x86::CPU& cpu, x86::reg32 code)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(code);
    NFS2_ASSERT(false);
    return 0;
}


Library s_glide2xLibrary = win32::Library("glide2x.dll");
Library* s_glide2xRegistry = &(s_glide2xLibrary
    .registerSymbol("_grGlideInit@0", &Wrapper<decltype(&grGlideInit), &grGlideInit>::stdcall)
    .registerSymbol("_grGlideShutdown@0", &Wrapper<decltype(&grGlideShutdown), &grGlideShutdown>::stdcall)
    .registerSymbol("_grSstQueryHardware@4", &Wrapper<decltype(&grSstQueryHardware), &grSstQueryHardware>::stdcall)
    .registerSymbol("_grSstQueryBoards@4", &Wrapper<decltype(&grSstQueryBoards), &grSstQueryBoards>::stdcall)
    .registerSymbol("_grSstSelect@4", &Wrapper<decltype(&grSstSelect), &grSstSelect>::stdcall)
    .registerSymbol("_grSstWinOpen@28", &Wrapper<decltype(&grSstWinOpen), &grSstWinOpen>::stdcall)
    .registerSymbol("_grSstWinClose@0", &Wrapper<decltype(&grSstWinClose), &grSstWinClose>::stdcall)
    .registerSymbol("_grSstStatus@0", &Wrapper<decltype(&grSstStatus), &grSstStatus>::stdcall)
    .registerSymbol("_grSstVRetraceOn@0", &Wrapper<decltype(&grSstVRetraceOn), &grSstVRetraceOn>::stdcall)
    .registerSymbol("_grSstIdle@0", &Wrapper<decltype(&grSstIdle), &grSstIdle>::stdcall)
    .registerSymbol("_grTexCombineFunction@8", &Wrapper<decltype(&grTexCombineFunction), &grTexCombineFunction>::stdcall)
    .registerSymbol("_grChromakeyValue@4", &Wrapper<decltype(&grChromakeyValue), &grChromakeyValue>::stdcall)
    .registerSymbol("_grAlphaTestReferenceValue@4", &Wrapper<decltype(&grAlphaTestReferenceValue), &grAlphaTestReferenceValue>::stdcall)
    .registerSymbol("_grTexDownloadTable@12", &Wrapper<decltype(&grTexDownloadTable), &grTexDownloadTable>::stdcall)
    .registerSymbol("_grRenderBuffer@4", &Wrapper<decltype(&grRenderBuffer), &grRenderBuffer>::stdcall)
    .registerSymbol("_grBufferClear@12", &Wrapper<decltype(&grBufferClear), &grBufferClear>::stdcall)
    .registerSymbol("_grBufferSwap@4", &Wrapper<decltype(&grBufferSwap), &grBufferSwap>::stdcall)
    .registerSymbol("_grSstIsBusy@0", &Wrapper<decltype(&grSstIsBusy), &grSstIsBusy>::stdcall)
    .registerSymbol("_grClipWindow@16", &Wrapper<decltype(&grClipWindow), &grClipWindow>::stdcall)
    .registerSymbol("_grColorCombine@20", &Wrapper<decltype(&grColorCombine), &grColorCombine>::stdcall)
    .registerSymbol("_grAlphaCombine@20", &Wrapper<decltype(&grAlphaCombine), &grAlphaCombine>::stdcall)
    .registerSymbol("_grAlphaBlendFunction@16", &Wrapper<decltype(&grAlphaBlendFunction), &grAlphaBlendFunction>::stdcall)
    .registerSymbol("_grCullMode@4", &Wrapper<decltype(&grCullMode), &grCullMode>::stdcall)
    .registerSymbol("_grTexFilterMode@12", &Wrapper<decltype(&grTexFilterMode), &grTexFilterMode>::stdcall)
    .registerSymbol("_grDitherMode@4", &Wrapper<decltype(&grDitherMode), &grDitherMode>::stdcall)
    .registerSymbol("_grChromakeyMode@4", &Wrapper<decltype(&grChromakeyMode), &grChromakeyMode>::stdcall)
    .registerSymbol("_grAlphaTestFunction@4", &Wrapper<decltype(&grAlphaTestFunction), &grAlphaTestFunction>::stdcall)
    .registerSymbol("_grDepthBufferMode@4", &Wrapper<decltype(&grDepthBufferMode), &grDepthBufferMode>::stdcall)
    .registerSymbol("_grDepthBufferFunction@4", &Wrapper<decltype(&grDepthBufferFunction), &grDepthBufferFunction>::stdcall)
    .registerSymbol("_grDepthMask@4", &Wrapper<decltype(&grDepthMask), &grDepthMask>::stdcall)
    .registerSymbol("_grFogColorValue@4", &Wrapper<decltype(&grFogColorValue), &grFogColorValue>::stdcall)
    .registerSymbol("_grFogMode@4", &Wrapper<decltype(&grFogMode), &grFogMode>::stdcall)
    .registerSymbol("_grFogTable@4", &Wrapper<decltype(&grFogTable), &grFogTable>::stdcall)
    .registerSymbol("_grLfbLock@24", &Wrapper<decltype(&grLfbLock), &grLfbLock>::stdcall)
    .registerSymbol("_grLfbUnlock@8", &Wrapper<decltype(&grLfbUnlock), &grLfbUnlock>::stdcall)
    .registerSymbol("_grLfbWriteRegion@32", &Wrapper<decltype(&grLfbWriteRegion), &grLfbWriteRegion>::stdcall)
    .registerSymbol("_grLfbReadRegion@28", &Wrapper<decltype(&grLfbReadRegion), &grLfbReadRegion>::stdcall)
    .registerSymbol("_grDrawTriangle@12", &Wrapper<decltype(&grDrawTriangle), &grDrawTriangle>::stdcall)
    .registerSymbol("_grDrawLine@8", &Wrapper<decltype(&grDrawLine), &grDrawLine>::stdcall)
    .registerSymbol("_grDrawPoint@4", &Wrapper<decltype(&grDrawPoint), &grDrawPoint>::stdcall)
    .registerSymbol("_grGammaCorrectionValue@4", &Wrapper<decltype(&grGammaCorrectionValue), &grGammaCorrectionValue>::stdcall)
    .registerSymbol("_grDepthBiasLevel@4", &Wrapper<decltype(&grDepthBiasLevel), &grDepthBiasLevel>::stdcall)
    .registerSymbol("_grTexMipMapMode@12", &Wrapper<decltype(&grTexMipMapMode), &grTexMipMapMode>::stdcall)
    .registerSymbol("_grTexCombine@28", &Wrapper<decltype(&grTexCombine), &grTexCombine>::stdcall)
    .registerSymbol("_grTexCalcMemRequired@16", &Wrapper<decltype(&grTexCalcMemRequired), &grTexCalcMemRequired>::stdcall)
    .registerSymbol("_grTexDownloadMipMap@16", &Wrapper<decltype(&grTexDownloadMipMap), &grTexDownloadMipMap>::stdcall)
    .registerSymbol("_grTexMinAddress@4", &Wrapper<decltype(&grTexMinAddress), &grTexMinAddress>::stdcall)
    .registerSymbol("_grTexMaxAddress@4", &Wrapper<decltype(&grTexMaxAddress), &grTexMaxAddress>::stdcall)
    .registerSymbol("_grTexSource@16", &Wrapper<decltype(&grTexSource), &grTexSource>::stdcall)
    .registerSymbol("_grTexClampMode@12", &Wrapper<decltype(&grTexClampMode), &grTexClampMode>::stdcall)
    .registerSymbol("_grGlideGetVersion@4", &Wrapper<decltype(&grGlideGetVersion), &grGlideGetVersion>::stdcall)
    .registerSymbol("_grAADrawTriangle@24", &Wrapper<decltype(&grAADrawTriangle), &grAADrawTriangle>::stdcall)
    .registerSymbol("_grAADrawLine@8", &Wrapper<decltype(&grAADrawLine), &grAADrawLine>::stdcall)
    .registerSymbol("_grHints@8", &Wrapper<decltype(&grHints), &grHints>::stdcall)
    .registerSymbol("_grTexLodBiasValue@8", &Wrapper<decltype(&grTexLodBiasValue), &grTexLodBiasValue>::stdcall)
    .registerSymbol("_grSstScreenWidth@0", &Wrapper<decltype(&grSstScreenWidth), &grSstScreenWidth>::stdcall)
    .registerSymbol("_grSstScreenHeight@0", &Wrapper<decltype(&grSstScreenHeight), &grSstScreenHeight>::stdcall)
    .registerSymbol("_grBufferNumPending@0", &Wrapper<decltype(&grBufferNumPending), &grBufferNumPending>::stdcall)
    .registerSymbol("_grSstControl@4", &Wrapper<decltype(&grSstControl), &grSstControl>::stdcall)
);

}}
