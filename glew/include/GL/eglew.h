/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2008-2017, Nigel Stewart <nigels[]users sourceforge net>
** Copyright (C) 2002-2008, Milan Ikits <milan ikits[]ieee org>
** Copyright (C) 2002-2008, Marcelo E. Magallon <mmagallo[]debian org>
** Copyright (C) 2002, Lev Povalahev
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without 
** modification, are permitted provided that the following conditions are met:
** 
** * Redistributions of source code must retain the above copyright notice, 
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice, 
**   this list of conditions and the following disclaimer in the documentation 
**   and/or other materials provided with the distribution.
** * The name of the author may be used to endorse or promote products 
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * Mesa 3-D graphics library
 * Version:  7.0
 *
 * Copyright (C) 1999-2007  Brian Paul   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
** Copyright (c) 2007 The Khronos Group Inc.
** 
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
** 
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
** 
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

#ifndef __eglew_h__
#define __eglew_h__
#define __EGLEW_H__

#ifdef __eglext_h_
#error eglext.h included before eglew.h
#endif

#if defined(__egl_h_)
#error egl.h included before eglew.h
#endif

#define __eglext_h_

#define __egl_h_

#ifndef EGLAPIENTRY
#define EGLAPIENTRY
#endif
#ifndef EGLAPI
#define EGLAPI extern
#endif

/* EGL Types */
#include <sys/types.h>

#include <KHR/khrplatform.h>
#include <EGL/eglplatform.h>

#include <GL/glew.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t EGLint;

typedef unsigned int EGLBoolean;
typedef void *EGLDisplay;
typedef void *EGLConfig;
typedef void *EGLSurface;
typedef void *EGLContext;
typedef void (*__eglMustCastToProperFunctionPointerType)(void);

typedef unsigned int EGLenum;
typedef void *EGLClientBuffer;

typedef void *EGLSync;
typedef intptr_t EGLAttrib;
typedef khronos_utime_nanoseconds_t EGLTime;
typedef void *EGLImage;

typedef void *EGLSyncKHR;
typedef intptr_t EGLAttribKHR;
typedef void *EGLLabelKHR;
typedef void *EGLObjectKHR;
typedef void (EGLAPIENTRY  *EGLDEBUGPROCKHR)(EGLenum error,const char *command,EGLint messageType,EGLLabelKHR threadLabel,EGLLabelKHR objectLabel,const char* message);
typedef khronos_utime_nanoseconds_t EGLTimeKHR;
typedef void *EGLImageKHR;
typedef void *EGLStreamKHR;
typedef khronos_uint64_t EGLuint64KHR;
typedef int EGLNativeFileDescriptorKHR;
typedef khronos_ssize_t EGLsizeiANDROID;
typedef void (*EGLSetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, const void *value, EGLsizeiANDROID valueSize);
typedef EGLsizeiANDROID (*EGLGetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, void *value, EGLsizeiANDROID valueSize);
typedef void *EGLDeviceEXT;
typedef void *EGLOutputLayerEXT;
typedef void *EGLOutputPortEXT;
typedef void *EGLSyncNV;
typedef khronos_utime_nanoseconds_t EGLTimeNV;
typedef khronos_utime_nanoseconds_t EGLuint64NV;
typedef khronos_stime_nanoseconds_t EGLnsecsANDROID;

struct EGLClientPixmapHI;

#define EGL_DONT_CARE                     ((EGLint)-1)

#define EGL_NO_CONTEXT                    ((EGLContext)0)
#define EGL_NO_DISPLAY                    ((EGLDisplay)0)
#define EGL_NO_IMAGE                      ((EGLImage)0)
#define EGL_NO_SURFACE                    ((EGLSurface)0)
#define EGL_NO_SYNC                       ((EGLSync)0)

#define EGL_UNKNOWN                       ((EGLint)-1)

#define EGL_DEFAULT_DISPLAY               ((EGLNativeDisplayType)0)

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress (const char *procname);
/* ---------------------------- EGL_VERSION_1_0 --------------------------- */

#ifndef EGL_VERSION_1_0
#define EGL_VERSION_1_0 1

#define EGLEW_VERSION_1_0 EGLEW_GET_VAR(__EGLEW_VERSION_1_0)

#endif /* EGL_VERSION_1_0 */

/* ---------------------------- EGL_VERSION_1_1 --------------------------- */

#ifndef EGL_VERSION_1_1
#define EGL_VERSION_1_1 1

#define EGLEW_VERSION_1_1 EGLEW_GET_VAR(__EGLEW_VERSION_1_1)

#endif /* EGL_VERSION_1_1 */

/* ---------------------------- EGL_VERSION_1_2 --------------------------- */

#ifndef EGL_VERSION_1_2
#define EGL_VERSION_1_2 1

#define EGLEW_VERSION_1_2 EGLEW_GET_VAR(__EGLEW_VERSION_1_2)

#endif /* EGL_VERSION_1_2 */

/* ---------------------------- EGL_VERSION_1_3 --------------------------- */

#ifndef EGL_VERSION_1_3
#define EGL_VERSION_1_3 1

#define EGLEW_VERSION_1_3 EGLEW_GET_VAR(__EGLEW_VERSION_1_3)

#endif /* EGL_VERSION_1_3 */

/* ---------------------------- EGL_VERSION_1_4 --------------------------- */

#ifndef EGL_VERSION_1_4
#define EGL_VERSION_1_4 1

#define EGLEW_VERSION_1_4 EGLEW_GET_VAR(__EGLEW_VERSION_1_4)

#endif /* EGL_VERSION_1_4 */

/* ---------------------------- EGL_VERSION_1_5 --------------------------- */

#ifndef EGL_VERSION_1_5
#define EGL_VERSION_1_5 1

#define EGLEW_VERSION_1_5 EGLEW_GET_VAR(__EGLEW_VERSION_1_5)

#endif /* EGL_VERSION_1_5 */

/* ------------------------ EGL_ANDROID_blob_cache ------------------------ */

#ifndef EGL_ANDROID_blob_cache
#define EGL_ANDROID_blob_cache 1

#define EGLEW_ANDROID_blob_cache EGLEW_GET_VAR(__EGLEW_ANDROID_blob_cache)

#endif /* EGL_ANDROID_blob_cache */

/* ---------------- EGL_ANDROID_create_native_client_buffer --------------- */

#ifndef EGL_ANDROID_create_native_client_buffer
#define EGL_ANDROID_create_native_client_buffer 1

#define EGLEW_ANDROID_create_native_client_buffer EGLEW_GET_VAR(__EGLEW_ANDROID_create_native_client_buffer)

#endif /* EGL_ANDROID_create_native_client_buffer */

/* -------------------- EGL_ANDROID_framebuffer_target -------------------- */

#ifndef EGL_ANDROID_framebuffer_target
#define EGL_ANDROID_framebuffer_target 1

#define EGLEW_ANDROID_framebuffer_target EGLEW_GET_VAR(__EGLEW_ANDROID_framebuffer_target)

#endif /* EGL_ANDROID_framebuffer_target */

/* ----------------- EGL_ANDROID_front_buffer_auto_refresh ---------------- */

#ifndef EGL_ANDROID_front_buffer_auto_refresh
#define EGL_ANDROID_front_buffer_auto_refresh 1

#define EGLEW_ANDROID_front_buffer_auto_refresh EGLEW_GET_VAR(__EGLEW_ANDROID_front_buffer_auto_refresh)

#endif /* EGL_ANDROID_front_buffer_auto_refresh */

/* -------------------- EGL_ANDROID_image_native_buffer ------------------- */

#ifndef EGL_ANDROID_image_native_buffer
#define EGL_ANDROID_image_native_buffer 1

#define EGLEW_ANDROID_image_native_buffer EGLEW_GET_VAR(__EGLEW_ANDROID_image_native_buffer)

#endif /* EGL_ANDROID_image_native_buffer */

/* --------------------- EGL_ANDROID_native_fence_sync -------------------- */

#ifndef EGL_ANDROID_native_fence_sync
#define EGL_ANDROID_native_fence_sync 1

#define EGLEW_ANDROID_native_fence_sync EGLEW_GET_VAR(__EGLEW_ANDROID_native_fence_sync)

#endif /* EGL_ANDROID_native_fence_sync */

/* --------------------- EGL_ANDROID_presentation_time -------------------- */

#ifndef EGL_ANDROID_presentation_time
#define EGL_ANDROID_presentation_time 1

#define EGLEW_ANDROID_presentation_time EGLEW_GET_VAR(__EGLEW_ANDROID_presentation_time)

#endif /* EGL_ANDROID_presentation_time */

/* ------------------------ EGL_ANDROID_recordable ------------------------ */

#ifndef EGL_ANDROID_recordable
#define EGL_ANDROID_recordable 1

#define EGLEW_ANDROID_recordable EGLEW_GET_VAR(__EGLEW_ANDROID_recordable)

#endif /* EGL_ANDROID_recordable */

/* --------------- EGL_ANGLE_d3d_share_handle_client_buffer --------------- */

#ifndef EGL_ANGLE_d3d_share_handle_client_buffer
#define EGL_ANGLE_d3d_share_handle_client_buffer 1

#define EGLEW_ANGLE_d3d_share_handle_client_buffer EGLEW_GET_VAR(__EGLEW_ANGLE_d3d_share_handle_client_buffer)

#endif /* EGL_ANGLE_d3d_share_handle_client_buffer */

/* ------------------------- EGL_ANGLE_device_d3d ------------------------- */

#ifndef EGL_ANGLE_device_d3d
#define EGL_ANGLE_device_d3d 1

#define EGLEW_ANGLE_device_d3d EGLEW_GET_VAR(__EGLEW_ANGLE_device_d3d)

#endif /* EGL_ANGLE_device_d3d */

/* -------------------- EGL_ANGLE_query_surface_pointer ------------------- */

#ifndef EGL_ANGLE_query_surface_pointer
#define EGL_ANGLE_query_surface_pointer 1

#define EGLEW_ANGLE_query_surface_pointer EGLEW_GET_VAR(__EGLEW_ANGLE_query_surface_pointer)

#endif /* EGL_ANGLE_query_surface_pointer */

/* ------------- EGL_ANGLE_surface_d3d_texture_2d_share_handle ------------ */

#ifndef EGL_ANGLE_surface_d3d_texture_2d_share_handle
#define EGL_ANGLE_surface_d3d_texture_2d_share_handle 1

#define EGLEW_ANGLE_surface_d3d_texture_2d_share_handle EGLEW_GET_VAR(__EGLEW_ANGLE_surface_d3d_texture_2d_share_handle)

#endif /* EGL_ANGLE_surface_d3d_texture_2d_share_handle */

/* ---------------------- EGL_ANGLE_window_fixed_size --------------------- */

#ifndef EGL_ANGLE_window_fixed_size
#define EGL_ANGLE_window_fixed_size 1

#define EGLEW_ANGLE_window_fixed_size EGLEW_GET_VAR(__EGLEW_ANGLE_window_fixed_size)

#endif /* EGL_ANGLE_window_fixed_size */

/* -------------------- EGL_ARM_implicit_external_sync -------------------- */

#ifndef EGL_ARM_implicit_external_sync
#define EGL_ARM_implicit_external_sync 1

#define EGLEW_ARM_implicit_external_sync EGLEW_GET_VAR(__EGLEW_ARM_implicit_external_sync)

#endif /* EGL_ARM_implicit_external_sync */

/* ------------------ EGL_ARM_pixmap_multisample_discard ------------------ */

#ifndef EGL_ARM_pixmap_multisample_discard
#define EGL_ARM_pixmap_multisample_discard 1

#define EGLEW_ARM_pixmap_multisample_discard EGLEW_GET_VAR(__EGLEW_ARM_pixmap_multisample_discard)

#endif /* EGL_ARM_pixmap_multisample_discard */

/* -------------------------- EGL_EXT_buffer_age -------------------------- */

#ifndef EGL_EXT_buffer_age
#define EGL_EXT_buffer_age 1

#define EGLEW_EXT_buffer_age EGLEW_GET_VAR(__EGLEW_EXT_buffer_age)

#endif /* EGL_EXT_buffer_age */

/* ----------------------- EGL_EXT_client_extensions ---------------------- */

#ifndef EGL_EXT_client_extensions
#define EGL_EXT_client_extensions 1

#define EGLEW_EXT_client_extensions EGLEW_GET_VAR(__EGLEW_EXT_client_extensions)

#endif /* EGL_EXT_client_extensions */

/* ------------------- EGL_EXT_create_context_robustness ------------------ */

#ifndef EGL_EXT_create_context_robustness
#define EGL_EXT_create_context_robustness 1

#define EGLEW_EXT_create_context_robustness EGLEW_GET_VAR(__EGLEW_EXT_create_context_robustness)

#endif /* EGL_EXT_create_context_robustness */

/* -------------------------- EGL_EXT_device_base ------------------------- */

#ifndef EGL_EXT_device_base
#define EGL_EXT_device_base 1

#define EGLEW_EXT_device_base EGLEW_GET_VAR(__EGLEW_EXT_device_base)

#endif /* EGL_EXT_device_base */

/* -------------------------- EGL_EXT_device_drm -------------------------- */

#ifndef EGL_EXT_device_drm
#define EGL_EXT_device_drm 1

#define EGLEW_EXT_device_drm EGLEW_GET_VAR(__EGLEW_EXT_device_drm)

#endif /* EGL_EXT_device_drm */

/* ---------------------- EGL_EXT_device_enumeration ---------------------- */

#ifndef EGL_EXT_device_enumeration
#define EGL_EXT_device_enumeration 1

#define EGLEW_EXT_device_enumeration EGLEW_GET_VAR(__EGLEW_EXT_device_enumeration)

#endif /* EGL_EXT_device_enumeration */

/* ------------------------- EGL_EXT_device_openwf ------------------------ */

#ifndef EGL_EXT_device_openwf
#define EGL_EXT_device_openwf 1

#define EGLEW_EXT_device_openwf EGLEW_GET_VAR(__EGLEW_EXT_device_openwf)

#endif /* EGL_EXT_device_openwf */

/* ------------------------- EGL_EXT_device_query ------------------------- */

#ifndef EGL_EXT_device_query
#define EGL_EXT_device_query 1

#define EGLEW_EXT_device_query EGLEW_GET_VAR(__EGLEW_EXT_device_query)

#endif /* EGL_EXT_device_query */

/* ------------------ EGL_EXT_gl_colorspace_bt2020_linear ----------------- */

#ifndef EGL_EXT_gl_colorspace_bt2020_linear
#define EGL_EXT_gl_colorspace_bt2020_linear 1

#define EGLEW_EXT_gl_colorspace_bt2020_linear EGLEW_GET_VAR(__EGLEW_EXT_gl_colorspace_bt2020_linear)

#endif /* EGL_EXT_gl_colorspace_bt2020_linear */

/* -------------------- EGL_EXT_gl_colorspace_bt2020_pq ------------------- */

#ifndef EGL_EXT_gl_colorspace_bt2020_pq
#define EGL_EXT_gl_colorspace_bt2020_pq 1

#define EGLEW_EXT_gl_colorspace_bt2020_pq EGLEW_GET_VAR(__EGLEW_EXT_gl_colorspace_bt2020_pq)

#endif /* EGL_EXT_gl_colorspace_bt2020_pq */

/* ------------------ EGL_EXT_gl_colorspace_scrgb_linear ------------------ */

#ifndef EGL_EXT_gl_colorspace_scrgb_linear
#define EGL_EXT_gl_colorspace_scrgb_linear 1

#define EGLEW_EXT_gl_colorspace_scrgb_linear EGLEW_GET_VAR(__EGLEW_EXT_gl_colorspace_scrgb_linear)

#endif /* EGL_EXT_gl_colorspace_scrgb_linear */

/* --------------------- EGL_EXT_image_dma_buf_import --------------------- */

#ifndef EGL_EXT_image_dma_buf_import
#define EGL_EXT_image_dma_buf_import 1

#define EGLEW_EXT_image_dma_buf_import EGLEW_GET_VAR(__EGLEW_EXT_image_dma_buf_import)

#endif /* EGL_EXT_image_dma_buf_import */

/* ---------------- EGL_EXT_image_dma_buf_import_modifiers ---------------- */

#ifndef EGL_EXT_image_dma_buf_import_modifiers
#define EGL_EXT_image_dma_buf_import_modifiers 1

#define EGLEW_EXT_image_dma_buf_import_modifiers EGLEW_GET_VAR(__EGLEW_EXT_image_dma_buf_import_modifiers)

#endif /* EGL_EXT_image_dma_buf_import_modifiers */

/* ----------------------- EGL_EXT_multiview_window ----------------------- */

#ifndef EGL_EXT_multiview_window
#define EGL_EXT_multiview_window 1

#define EGLEW_EXT_multiview_window EGLEW_GET_VAR(__EGLEW_EXT_multiview_window)

#endif /* EGL_EXT_multiview_window */

/* -------------------------- EGL_EXT_output_base ------------------------- */

#ifndef EGL_EXT_output_base
#define EGL_EXT_output_base 1

#define EGLEW_EXT_output_base EGLEW_GET_VAR(__EGLEW_EXT_output_base)

#endif /* EGL_EXT_output_base */

/* -------------------------- EGL_EXT_output_drm -------------------------- */

#ifndef EGL_EXT_output_drm
#define EGL_EXT_output_drm 1

#define EGLEW_EXT_output_drm EGLEW_GET_VAR(__EGLEW_EXT_output_drm)

#endif /* EGL_EXT_output_drm */

/* ------------------------- EGL_EXT_output_openwf ------------------------ */

#ifndef EGL_EXT_output_openwf
#define EGL_EXT_output_openwf 1

#define EGLEW_EXT_output_openwf EGLEW_GET_VAR(__EGLEW_EXT_output_openwf)

#endif /* EGL_EXT_output_openwf */

/* ---------------------- EGL_EXT_pixel_format_float ---------------------- */

#ifndef EGL_EXT_pixel_format_float
#define EGL_EXT_pixel_format_float 1

#define EGLEW_EXT_pixel_format_float EGLEW_GET_VAR(__EGLEW_EXT_pixel_format_float)

#endif /* EGL_EXT_pixel_format_float */

/* ------------------------- EGL_EXT_platform_base ------------------------ */

#ifndef EGL_EXT_platform_base
#define EGL_EXT_platform_base 1

#define EGLEW_EXT_platform_base EGLEW_GET_VAR(__EGLEW_EXT_platform_base)

#endif /* EGL_EXT_platform_base */

/* ------------------------ EGL_EXT_platform_device ----------------------- */

#ifndef EGL_EXT_platform_device
#define EGL_EXT_platform_device 1

#define EGLEW_EXT_platform_device EGLEW_GET_VAR(__EGLEW_EXT_platform_device)

#endif /* EGL_EXT_platform_device */

/* ----------------------- EGL_EXT_platform_wayland ----------------------- */

#ifndef EGL_EXT_platform_wayland
#define EGL_EXT_platform_wayland 1

#define EGLEW_EXT_platform_wayland EGLEW_GET_VAR(__EGLEW_EXT_platform_wayland)

#endif /* EGL_EXT_platform_wayland */

/* ------------------------- EGL_EXT_platform_x11 ------------------------- */

#ifndef EGL_EXT_platform_x11
#define EGL_EXT_platform_x11 1

#define EGLEW_EXT_platform_x11 EGLEW_GET_VAR(__EGLEW_EXT_platform_x11)

#endif /* EGL_EXT_platform_x11 */

/* ----------------------- EGL_EXT_protected_content ---------------------- */

#ifndef EGL_EXT_protected_content
#define EGL_EXT_protected_content 1

#define EGLEW_EXT_protected_content EGLEW_GET_VAR(__EGLEW_EXT_protected_content)

#endif /* EGL_EXT_protected_content */

/* ----------------------- EGL_EXT_protected_surface ---------------------- */

#ifndef EGL_EXT_protected_surface
#define EGL_EXT_protected_surface 1

#define EGLEW_EXT_protected_surface EGLEW_GET_VAR(__EGLEW_EXT_protected_surface)

#endif /* EGL_EXT_protected_surface */

/* ------------------- EGL_EXT_stream_consumer_egloutput ------------------ */

#ifndef EGL_EXT_stream_consumer_egloutput
#define EGL_EXT_stream_consumer_egloutput 1

#define EGLEW_EXT_stream_consumer_egloutput EGLEW_GET_VAR(__EGLEW_EXT_stream_consumer_egloutput)

#endif /* EGL_EXT_stream_consumer_egloutput */

/* ------------------ EGL_EXT_surface_SMPTE2086_metadata ------------------ */

#ifndef EGL_EXT_surface_SMPTE2086_metadata
#define EGL_EXT_surface_SMPTE2086_metadata 1

#define EGLEW_EXT_surface_SMPTE2086_metadata EGLEW_GET_VAR(__EGLEW_EXT_surface_SMPTE2086_metadata)

#endif /* EGL_EXT_surface_SMPTE2086_metadata */

/* ------------------- EGL_EXT_swap_buffers_with_damage ------------------- */

#ifndef EGL_EXT_swap_buffers_with_damage
#define EGL_EXT_swap_buffers_with_damage 1

#define EGLEW_EXT_swap_buffers_with_damage EGLEW_GET_VAR(__EGLEW_EXT_swap_buffers_with_damage)

#endif /* EGL_EXT_swap_buffers_with_damage */

/* -------------------------- EGL_EXT_yuv_surface ------------------------- */

#ifndef EGL_EXT_yuv_surface
#define EGL_EXT_yuv_surface 1

#define EGLEW_EXT_yuv_surface EGLEW_GET_VAR(__EGLEW_EXT_yuv_surface)

#endif /* EGL_EXT_yuv_surface */

/* -------------------------- EGL_HI_clientpixmap ------------------------- */

#ifndef EGL_HI_clientpixmap
#define EGL_HI_clientpixmap 1

#define EGLEW_HI_clientpixmap EGLEW_GET_VAR(__EGLEW_HI_clientpixmap)

#endif /* EGL_HI_clientpixmap */

/* -------------------------- EGL_HI_colorformats ------------------------- */

#ifndef EGL_HI_colorformats
#define EGL_HI_colorformats 1

#define EGLEW_HI_colorformats EGLEW_GET_VAR(__EGLEW_HI_colorformats)

#endif /* EGL_HI_colorformats */

/* ----------------------- EGL_IMG_context_priority ----------------------- */

#ifndef EGL_IMG_context_priority
#define EGL_IMG_context_priority 1

#define EGLEW_IMG_context_priority EGLEW_GET_VAR(__EGLEW_IMG_context_priority)

#endif /* EGL_IMG_context_priority */

/* ---------------------- EGL_IMG_image_plane_attribs --------------------- */

#ifndef EGL_IMG_image_plane_attribs
#define EGL_IMG_image_plane_attribs 1

#define EGLEW_IMG_image_plane_attribs EGLEW_GET_VAR(__EGLEW_IMG_image_plane_attribs)

#endif /* EGL_IMG_image_plane_attribs */

/* --------------------------- EGL_KHR_cl_event --------------------------- */

#ifndef EGL_KHR_cl_event
#define EGL_KHR_cl_event 1

#define EGLEW_KHR_cl_event EGLEW_GET_VAR(__EGLEW_KHR_cl_event)

#endif /* EGL_KHR_cl_event */

/* --------------------------- EGL_KHR_cl_event2 -------------------------- */

#ifndef EGL_KHR_cl_event2
#define EGL_KHR_cl_event2 1

#define EGLEW_KHR_cl_event2 EGLEW_GET_VAR(__EGLEW_KHR_cl_event2)

#endif /* EGL_KHR_cl_event2 */

/* ----------------- EGL_KHR_client_get_all_proc_addresses ---------------- */

#ifndef EGL_KHR_client_get_all_proc_addresses
#define EGL_KHR_client_get_all_proc_addresses 1

#define EGLEW_KHR_client_get_all_proc_addresses EGLEW_GET_VAR(__EGLEW_KHR_client_get_all_proc_addresses)

#endif /* EGL_KHR_client_get_all_proc_addresses */

/* ------------------------ EGL_KHR_config_attribs ------------------------ */

#ifndef EGL_KHR_config_attribs
#define EGL_KHR_config_attribs 1

#define EGLEW_KHR_config_attribs EGLEW_GET_VAR(__EGLEW_KHR_config_attribs)

#endif /* EGL_KHR_config_attribs */

/* --------------------- EGL_KHR_context_flush_control -------------------- */

#ifndef EGL_KHR_context_flush_control
#define EGL_KHR_context_flush_control 1

#define EGLEW_KHR_context_flush_control EGLEW_GET_VAR(__EGLEW_KHR_context_flush_control)

#endif /* EGL_KHR_context_flush_control */

/* ------------------------ EGL_KHR_create_context ------------------------ */

#ifndef EGL_KHR_create_context
#define EGL_KHR_create_context 1

#define EGLEW_KHR_create_context EGLEW_GET_VAR(__EGLEW_KHR_create_context)

#endif /* EGL_KHR_create_context */

/* -------------------- EGL_KHR_create_context_no_error ------------------- */

#ifndef EGL_KHR_create_context_no_error
#define EGL_KHR_create_context_no_error 1

#define EGLEW_KHR_create_context_no_error EGLEW_GET_VAR(__EGLEW_KHR_create_context_no_error)

#endif /* EGL_KHR_create_context_no_error */

/* ----------------------------- EGL_KHR_debug ---------------------------- */

#ifndef EGL_KHR_debug
#define EGL_KHR_debug 1

#define EGLEW_KHR_debug EGLEW_GET_VAR(__EGLEW_KHR_debug)

#endif /* EGL_KHR_debug */

/* -------------------------- EGL_KHR_fence_sync -------------------------- */

#ifndef EGL_KHR_fence_sync
#define EGL_KHR_fence_sync 1

#define EGLEW_KHR_fence_sync EGLEW_GET_VAR(__EGLEW_KHR_fence_sync)

#endif /* EGL_KHR_fence_sync */

/* -------------------- EGL_KHR_get_all_proc_addresses -------------------- */

#ifndef EGL_KHR_get_all_proc_addresses
#define EGL_KHR_get_all_proc_addresses 1

#define EGLEW_KHR_get_all_proc_addresses EGLEW_GET_VAR(__EGLEW_KHR_get_all_proc_addresses)

#endif /* EGL_KHR_get_all_proc_addresses */

/* ------------------------- EGL_KHR_gl_colorspace ------------------------ */

#ifndef EGL_KHR_gl_colorspace
#define EGL_KHR_gl_colorspace 1

#define EGLEW_KHR_gl_colorspace EGLEW_GET_VAR(__EGLEW_KHR_gl_colorspace)

#endif /* EGL_KHR_gl_colorspace */

/* --------------------- EGL_KHR_gl_renderbuffer_image -------------------- */

#ifndef EGL_KHR_gl_renderbuffer_image
#define EGL_KHR_gl_renderbuffer_image 1

#define EGLEW_KHR_gl_renderbuffer_image EGLEW_GET_VAR(__EGLEW_KHR_gl_renderbuffer_image)

#endif /* EGL_KHR_gl_renderbuffer_image */

/* ---------------------- EGL_KHR_gl_texture_2D_image --------------------- */

#ifndef EGL_KHR_gl_texture_2D_image
#define EGL_KHR_gl_texture_2D_image 1

#define EGLEW_KHR_gl_texture_2D_image EGLEW_GET_VAR(__EGLEW_KHR_gl_texture_2D_image)

#endif /* EGL_KHR_gl_texture_2D_image */

/* ---------------------- EGL_KHR_gl_texture_3D_image --------------------- */

#ifndef EGL_KHR_gl_texture_3D_image
#define EGL_KHR_gl_texture_3D_image 1

#define EGLEW_KHR_gl_texture_3D_image EGLEW_GET_VAR(__EGLEW_KHR_gl_texture_3D_image)

#endif /* EGL_KHR_gl_texture_3D_image */

/* ------------------- EGL_KHR_gl_texture_cubemap_image ------------------- */

#ifndef EGL_KHR_gl_texture_cubemap_image
#define EGL_KHR_gl_texture_cubemap_image 1

#define EGLEW_KHR_gl_texture_cubemap_image EGLEW_GET_VAR(__EGLEW_KHR_gl_texture_cubemap_image)

#endif /* EGL_KHR_gl_texture_cubemap_image */

/* ----------------------------- EGL_KHR_image ---------------------------- */

#ifndef EGL_KHR_image
#define EGL_KHR_image 1

#define EGLEW_KHR_image EGLEW_GET_VAR(__EGLEW_KHR_image)

#endif /* EGL_KHR_image */

/* -------------------------- EGL_KHR_image_base -------------------------- */

#ifndef EGL_KHR_image_base
#define EGL_KHR_image_base 1

#define EGLEW_KHR_image_base EGLEW_GET_VAR(__EGLEW_KHR_image_base)

#endif /* EGL_KHR_image_base */

/* ------------------------- EGL_KHR_image_pixmap ------------------------- */

#ifndef EGL_KHR_image_pixmap
#define EGL_KHR_image_pixmap 1

#define EGLEW_KHR_image_pixmap EGLEW_GET_VAR(__EGLEW_KHR_image_pixmap)

#endif /* EGL_KHR_image_pixmap */

/* ------------------------- EGL_KHR_lock_surface ------------------------- */

#ifndef EGL_KHR_lock_surface
#define EGL_KHR_lock_surface 1

#define EGLEW_KHR_lock_surface EGLEW_GET_VAR(__EGLEW_KHR_lock_surface)

#endif /* EGL_KHR_lock_surface */

/* ------------------------- EGL_KHR_lock_surface2 ------------------------ */

#ifndef EGL_KHR_lock_surface2
#define EGL_KHR_lock_surface2 1

#define EGLEW_KHR_lock_surface2 EGLEW_GET_VAR(__EGLEW_KHR_lock_surface2)

#endif /* EGL_KHR_lock_surface2 */

/* ------------------------- EGL_KHR_lock_surface3 ------------------------ */

#ifndef EGL_KHR_lock_surface3
#define EGL_KHR_lock_surface3 1

#define EGLEW_KHR_lock_surface3 EGLEW_GET_VAR(__EGLEW_KHR_lock_surface3)

#endif /* EGL_KHR_lock_surface3 */

/* --------------------- EGL_KHR_mutable_render_buffer -------------------- */

#ifndef EGL_KHR_mutable_render_buffer
#define EGL_KHR_mutable_render_buffer 1

#define EGLEW_KHR_mutable_render_buffer EGLEW_GET_VAR(__EGLEW_KHR_mutable_render_buffer)

#endif /* EGL_KHR_mutable_render_buffer */

/* ----------------------- EGL_KHR_no_config_context ---------------------- */

#ifndef EGL_KHR_no_config_context
#define EGL_KHR_no_config_context 1

#define EGLEW_KHR_no_config_context EGLEW_GET_VAR(__EGLEW_KHR_no_config_context)

#endif /* EGL_KHR_no_config_context */

/* ------------------------ EGL_KHR_partial_update ------------------------ */

#ifndef EGL_KHR_partial_update
#define EGL_KHR_partial_update 1

#define EGLEW_KHR_partial_update EGLEW_GET_VAR(__EGLEW_KHR_partial_update)

#endif /* EGL_KHR_partial_update */

/* ----------------------- EGL_KHR_platform_android ----------------------- */

#ifndef EGL_KHR_platform_android
#define EGL_KHR_platform_android 1

#define EGLEW_KHR_platform_android EGLEW_GET_VAR(__EGLEW_KHR_platform_android)

#endif /* EGL_KHR_platform_android */

/* ------------------------- EGL_KHR_platform_gbm ------------------------- */

#ifndef EGL_KHR_platform_gbm
#define EGL_KHR_platform_gbm 1

#define EGLEW_KHR_platform_gbm EGLEW_GET_VAR(__EGLEW_KHR_platform_gbm)

#endif /* EGL_KHR_platform_gbm */

/* ----------------------- EGL_KHR_platform_wayland ----------------------- */

#ifndef EGL_KHR_platform_wayland
#define EGL_KHR_platform_wayland 1

#define EGLEW_KHR_platform_wayland EGLEW_GET_VAR(__EGLEW_KHR_platform_wayland)

#endif /* EGL_KHR_platform_wayland */

/* ------------------------- EGL_KHR_platform_x11 ------------------------- */

#ifndef EGL_KHR_platform_x11
#define EGL_KHR_platform_x11 1

#define EGLEW_KHR_platform_x11 EGLEW_GET_VAR(__EGLEW_KHR_platform_x11)

#endif /* EGL_KHR_platform_x11 */

/* ------------------------- EGL_KHR_reusable_sync ------------------------ */

#ifndef EGL_KHR_reusable_sync
#define EGL_KHR_reusable_sync 1

#define EGLEW_KHR_reusable_sync EGLEW_GET_VAR(__EGLEW_KHR_reusable_sync)

#endif /* EGL_KHR_reusable_sync */

/* ---------------------------- EGL_KHR_stream ---------------------------- */

#ifndef EGL_KHR_stream
#define EGL_KHR_stream 1

#define EGLEW_KHR_stream EGLEW_GET_VAR(__EGLEW_KHR_stream)

#endif /* EGL_KHR_stream */

/* ------------------------- EGL_KHR_stream_attrib ------------------------ */

#ifndef EGL_KHR_stream_attrib
#define EGL_KHR_stream_attrib 1

#define EGLEW_KHR_stream_attrib EGLEW_GET_VAR(__EGLEW_KHR_stream_attrib)

#endif /* EGL_KHR_stream_attrib */

/* ------------------- EGL_KHR_stream_consumer_gltexture ------------------ */

#ifndef EGL_KHR_stream_consumer_gltexture
#define EGL_KHR_stream_consumer_gltexture 1

#define EGLEW_KHR_stream_consumer_gltexture EGLEW_GET_VAR(__EGLEW_KHR_stream_consumer_gltexture)

#endif /* EGL_KHR_stream_consumer_gltexture */

/* -------------------- EGL_KHR_stream_cross_process_fd ------------------- */

#ifndef EGL_KHR_stream_cross_process_fd
#define EGL_KHR_stream_cross_process_fd 1

#define EGLEW_KHR_stream_cross_process_fd EGLEW_GET_VAR(__EGLEW_KHR_stream_cross_process_fd)

#endif /* EGL_KHR_stream_cross_process_fd */

/* -------------------------- EGL_KHR_stream_fifo ------------------------- */

#ifndef EGL_KHR_stream_fifo
#define EGL_KHR_stream_fifo 1

#define EGLEW_KHR_stream_fifo EGLEW_GET_VAR(__EGLEW_KHR_stream_fifo)

#endif /* EGL_KHR_stream_fifo */

/* ----------------- EGL_KHR_stream_producer_aldatalocator ---------------- */

#ifndef EGL_KHR_stream_producer_aldatalocator
#define EGL_KHR_stream_producer_aldatalocator 1

#define EGLEW_KHR_stream_producer_aldatalocator EGLEW_GET_VAR(__EGLEW_KHR_stream_producer_aldatalocator)

#endif /* EGL_KHR_stream_producer_aldatalocator */

/* ------------------ EGL_KHR_stream_producer_eglsurface ------------------ */

#ifndef EGL_KHR_stream_producer_eglsurface
#define EGL_KHR_stream_producer_eglsurface 1

#define EGLEW_KHR_stream_producer_eglsurface EGLEW_GET_VAR(__EGLEW_KHR_stream_producer_eglsurface)

#endif /* EGL_KHR_stream_producer_eglsurface */

/* ---------------------- EGL_KHR_surfaceless_context --------------------- */

#ifndef EGL_KHR_surfaceless_context
#define EGL_KHR_surfaceless_context 1

#define EGLEW_KHR_surfaceless_context EGLEW_GET_VAR(__EGLEW_KHR_surfaceless_context)

#endif /* EGL_KHR_surfaceless_context */

/* ------------------- EGL_KHR_swap_buffers_with_damage ------------------- */

#ifndef EGL_KHR_swap_buffers_with_damage
#define EGL_KHR_swap_buffers_with_damage 1

#define EGLEW_KHR_swap_buffers_with_damage EGLEW_GET_VAR(__EGLEW_KHR_swap_buffers_with_damage)

#endif /* EGL_KHR_swap_buffers_with_damage */

/* ------------------------ EGL_KHR_vg_parent_image ----------------------- */

#ifndef EGL_KHR_vg_parent_image
#define EGL_KHR_vg_parent_image 1

#define EGLEW_KHR_vg_parent_image EGLEW_GET_VAR(__EGLEW_KHR_vg_parent_image)

#endif /* EGL_KHR_vg_parent_image */

/* --------------------------- EGL_KHR_wait_sync -------------------------- */

#ifndef EGL_KHR_wait_sync
#define EGL_KHR_wait_sync 1

#define EGLEW_KHR_wait_sync EGLEW_GET_VAR(__EGLEW_KHR_wait_sync)

#endif /* EGL_KHR_wait_sync */

/* -------------------------- EGL_MESA_drm_image -------------------------- */

#ifndef EGL_MESA_drm_image
#define EGL_MESA_drm_image 1

#define EGLEW_MESA_drm_image EGLEW_GET_VAR(__EGLEW_MESA_drm_image)

#endif /* EGL_MESA_drm_image */

/* --------------------- EGL_MESA_image_dma_buf_export -------------------- */

#ifndef EGL_MESA_image_dma_buf_export
#define EGL_MESA_image_dma_buf_export 1

#define EGLEW_MESA_image_dma_buf_export EGLEW_GET_VAR(__EGLEW_MESA_image_dma_buf_export)

#endif /* EGL_MESA_image_dma_buf_export */

/* ------------------------- EGL_MESA_platform_gbm ------------------------ */

#ifndef EGL_MESA_platform_gbm
#define EGL_MESA_platform_gbm 1

#define EGLEW_MESA_platform_gbm EGLEW_GET_VAR(__EGLEW_MESA_platform_gbm)

#endif /* EGL_MESA_platform_gbm */

/* --------------------- EGL_MESA_platform_surfaceless -------------------- */

#ifndef EGL_MESA_platform_surfaceless
#define EGL_MESA_platform_surfaceless 1

#define EGLEW_MESA_platform_surfaceless EGLEW_GET_VAR(__EGLEW_MESA_platform_surfaceless)

#endif /* EGL_MESA_platform_surfaceless */

/* -------------------------- EGL_NOK_swap_region ------------------------- */

#ifndef EGL_NOK_swap_region
#define EGL_NOK_swap_region 1

#define EGLEW_NOK_swap_region EGLEW_GET_VAR(__EGLEW_NOK_swap_region)

#endif /* EGL_NOK_swap_region */

/* ------------------------- EGL_NOK_swap_region2 ------------------------- */

#ifndef EGL_NOK_swap_region2
#define EGL_NOK_swap_region2 1

#define EGLEW_NOK_swap_region2 EGLEW_GET_VAR(__EGLEW_NOK_swap_region2)

#endif /* EGL_NOK_swap_region2 */

/* ---------------------- EGL_NOK_texture_from_pixmap --------------------- */

#ifndef EGL_NOK_texture_from_pixmap
#define EGL_NOK_texture_from_pixmap 1

#define EGLEW_NOK_texture_from_pixmap EGLEW_GET_VAR(__EGLEW_NOK_texture_from_pixmap)

#endif /* EGL_NOK_texture_from_pixmap */

/* ------------------------ EGL_NV_3dvision_surface ----------------------- */

#ifndef EGL_NV_3dvision_surface
#define EGL_NV_3dvision_surface 1

#define EGLEW_NV_3dvision_surface EGLEW_GET_VAR(__EGLEW_NV_3dvision_surface)

#endif /* EGL_NV_3dvision_surface */

/* ------------------------ EGL_NV_coverage_sample ------------------------ */

#ifndef EGL_NV_coverage_sample
#define EGL_NV_coverage_sample 1

#define EGLEW_NV_coverage_sample EGLEW_GET_VAR(__EGLEW_NV_coverage_sample)

#endif /* EGL_NV_coverage_sample */

/* -------------------- EGL_NV_coverage_sample_resolve -------------------- */

#ifndef EGL_NV_coverage_sample_resolve
#define EGL_NV_coverage_sample_resolve 1

#define EGLEW_NV_coverage_sample_resolve EGLEW_GET_VAR(__EGLEW_NV_coverage_sample_resolve)

#endif /* EGL_NV_coverage_sample_resolve */

/* --------------------------- EGL_NV_cuda_event -------------------------- */

#ifndef EGL_NV_cuda_event
#define EGL_NV_cuda_event 1

#define EGLEW_NV_cuda_event EGLEW_GET_VAR(__EGLEW_NV_cuda_event)

#endif /* EGL_NV_cuda_event */

/* ------------------------ EGL_NV_depth_nonlinear ------------------------ */

#ifndef EGL_NV_depth_nonlinear
#define EGL_NV_depth_nonlinear 1

#define EGLEW_NV_depth_nonlinear EGLEW_GET_VAR(__EGLEW_NV_depth_nonlinear)

#endif /* EGL_NV_depth_nonlinear */

/* -------------------------- EGL_NV_device_cuda -------------------------- */

#ifndef EGL_NV_device_cuda
#define EGL_NV_device_cuda 1

#define EGLEW_NV_device_cuda EGLEW_GET_VAR(__EGLEW_NV_device_cuda)

#endif /* EGL_NV_device_cuda */

/* -------------------------- EGL_NV_native_query ------------------------- */

#ifndef EGL_NV_native_query
#define EGL_NV_native_query 1

#define EGLEW_NV_native_query EGLEW_GET_VAR(__EGLEW_NV_native_query)

#endif /* EGL_NV_native_query */

/* --------------------- EGL_NV_post_convert_rounding --------------------- */

#ifndef EGL_NV_post_convert_rounding
#define EGL_NV_post_convert_rounding 1

#define EGLEW_NV_post_convert_rounding EGLEW_GET_VAR(__EGLEW_NV_post_convert_rounding)

#endif /* EGL_NV_post_convert_rounding */

/* ------------------------ EGL_NV_post_sub_buffer ------------------------ */

#ifndef EGL_NV_post_sub_buffer
#define EGL_NV_post_sub_buffer 1

#define EGLEW_NV_post_sub_buffer EGLEW_GET_VAR(__EGLEW_NV_post_sub_buffer)

#endif /* EGL_NV_post_sub_buffer */

/* ----------------- EGL_NV_robustness_video_memory_purge ----------------- */

#ifndef EGL_NV_robustness_video_memory_purge
#define EGL_NV_robustness_video_memory_purge 1

#define EGLEW_NV_robustness_video_memory_purge EGLEW_GET_VAR(__EGLEW_NV_robustness_video_memory_purge)

#endif /* EGL_NV_robustness_video_memory_purge */

/* ----------------- EGL_NV_stream_consumer_gltexture_yuv ----------------- */

#ifndef EGL_NV_stream_consumer_gltexture_yuv
#define EGL_NV_stream_consumer_gltexture_yuv 1

#define EGLEW_NV_stream_consumer_gltexture_yuv EGLEW_GET_VAR(__EGLEW_NV_stream_consumer_gltexture_yuv)

#endif /* EGL_NV_stream_consumer_gltexture_yuv */

/* ---------------------- EGL_NV_stream_cross_display --------------------- */

#ifndef EGL_NV_stream_cross_display
#define EGL_NV_stream_cross_display 1

#define EGLEW_NV_stream_cross_display EGLEW_GET_VAR(__EGLEW_NV_stream_cross_display)

#endif /* EGL_NV_stream_cross_display */

/* ---------------------- EGL_NV_stream_cross_object ---------------------- */

#ifndef EGL_NV_stream_cross_object
#define EGL_NV_stream_cross_object 1

#define EGLEW_NV_stream_cross_object EGLEW_GET_VAR(__EGLEW_NV_stream_cross_object)

#endif /* EGL_NV_stream_cross_object */

/* --------------------- EGL_NV_stream_cross_partition -------------------- */

#ifndef EGL_NV_stream_cross_partition
#define EGL_NV_stream_cross_partition 1

#define EGLEW_NV_stream_cross_partition EGLEW_GET_VAR(__EGLEW_NV_stream_cross_partition)

#endif /* EGL_NV_stream_cross_partition */

/* ---------------------- EGL_NV_stream_cross_process --------------------- */

#ifndef EGL_NV_stream_cross_process
#define EGL_NV_stream_cross_process 1

#define EGLEW_NV_stream_cross_process EGLEW_GET_VAR(__EGLEW_NV_stream_cross_process)

#endif /* EGL_NV_stream_cross_process */

/* ---------------------- EGL_NV_stream_cross_system ---------------------- */

#ifndef EGL_NV_stream_cross_system
#define EGL_NV_stream_cross_system 1

#define EGLEW_NV_stream_cross_system EGLEW_GET_VAR(__EGLEW_NV_stream_cross_system)

#endif /* EGL_NV_stream_cross_system */

/* ------------------------ EGL_NV_stream_fifo_next ----------------------- */

#ifndef EGL_NV_stream_fifo_next
#define EGL_NV_stream_fifo_next 1

#define EGLEW_NV_stream_fifo_next EGLEW_GET_VAR(__EGLEW_NV_stream_fifo_next)

#endif /* EGL_NV_stream_fifo_next */

/* -------------------- EGL_NV_stream_fifo_synchronous -------------------- */

#ifndef EGL_NV_stream_fifo_synchronous
#define EGL_NV_stream_fifo_synchronous 1

#define EGLEW_NV_stream_fifo_synchronous EGLEW_GET_VAR(__EGLEW_NV_stream_fifo_synchronous)

#endif /* EGL_NV_stream_fifo_synchronous */

/* ---------------------- EGL_NV_stream_frame_limits ---------------------- */

#ifndef EGL_NV_stream_frame_limits
#define EGL_NV_stream_frame_limits 1

#define EGLEW_NV_stream_frame_limits EGLEW_GET_VAR(__EGLEW_NV_stream_frame_limits)

#endif /* EGL_NV_stream_frame_limits */

/* ------------------------ EGL_NV_stream_metadata ------------------------ */

#ifndef EGL_NV_stream_metadata
#define EGL_NV_stream_metadata 1

#define EGLEW_NV_stream_metadata EGLEW_GET_VAR(__EGLEW_NV_stream_metadata)

#endif /* EGL_NV_stream_metadata */

/* ------------------------- EGL_NV_stream_remote ------------------------- */

#ifndef EGL_NV_stream_remote
#define EGL_NV_stream_remote 1

#define EGLEW_NV_stream_remote EGLEW_GET_VAR(__EGLEW_NV_stream_remote)

#endif /* EGL_NV_stream_remote */

/* -------------------------- EGL_NV_stream_reset ------------------------- */

#ifndef EGL_NV_stream_reset
#define EGL_NV_stream_reset 1

#define EGLEW_NV_stream_reset EGLEW_GET_VAR(__EGLEW_NV_stream_reset)

#endif /* EGL_NV_stream_reset */

/* ------------------------- EGL_NV_stream_socket ------------------------- */

#ifndef EGL_NV_stream_socket
#define EGL_NV_stream_socket 1

#define EGLEW_NV_stream_socket EGLEW_GET_VAR(__EGLEW_NV_stream_socket)

#endif /* EGL_NV_stream_socket */

/* ----------------------- EGL_NV_stream_socket_inet ---------------------- */

#ifndef EGL_NV_stream_socket_inet
#define EGL_NV_stream_socket_inet 1

#define EGLEW_NV_stream_socket_inet EGLEW_GET_VAR(__EGLEW_NV_stream_socket_inet)

#endif /* EGL_NV_stream_socket_inet */

/* ----------------------- EGL_NV_stream_socket_unix ---------------------- */

#ifndef EGL_NV_stream_socket_unix
#define EGL_NV_stream_socket_unix 1

#define EGLEW_NV_stream_socket_unix EGLEW_GET_VAR(__EGLEW_NV_stream_socket_unix)

#endif /* EGL_NV_stream_socket_unix */

/* -------------------------- EGL_NV_stream_sync -------------------------- */

#ifndef EGL_NV_stream_sync
#define EGL_NV_stream_sync 1

#define EGLEW_NV_stream_sync EGLEW_GET_VAR(__EGLEW_NV_stream_sync)

#endif /* EGL_NV_stream_sync */

/* ------------------------------ EGL_NV_sync ----------------------------- */

#ifndef EGL_NV_sync
#define EGL_NV_sync 1

#define EGLEW_NV_sync EGLEW_GET_VAR(__EGLEW_NV_sync)

#endif /* EGL_NV_sync */

/* -------------------------- EGL_NV_system_time -------------------------- */

#ifndef EGL_NV_system_time
#define EGL_NV_system_time 1

#define EGLEW_NV_system_time EGLEW_GET_VAR(__EGLEW_NV_system_time)

#endif /* EGL_NV_system_time */

/* --------------------- EGL_TIZEN_image_native_buffer -------------------- */

#ifndef EGL_TIZEN_image_native_buffer
#define EGL_TIZEN_image_native_buffer 1

#define EGLEW_TIZEN_image_native_buffer EGLEW_GET_VAR(__EGLEW_TIZEN_image_native_buffer)

#endif /* EGL_TIZEN_image_native_buffer */

/* -------------------- EGL_TIZEN_image_native_surface -------------------- */

#ifndef EGL_TIZEN_image_native_surface
#define EGL_TIZEN_image_native_surface 1

#define EGLEW_TIZEN_image_native_surface EGLEW_GET_VAR(__EGLEW_TIZEN_image_native_surface)

#endif /* EGL_TIZEN_image_native_surface */

/* ------------------------------------------------------------------------- */

#define EGLEW_FUN_EXPORT GLEW_FUN_EXPORT
#define EGLEW_VAR_EXPORT GLEW_VAR_EXPORT
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_0;
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_1;
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_2;
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_3;
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_4;
EGLEW_VAR_EXPORT GLboolean __EGLEW_VERSION_1_5;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_blob_cache;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_create_native_client_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_framebuffer_target;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_front_buffer_auto_refresh;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_image_native_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_native_fence_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_presentation_time;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANDROID_recordable;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANGLE_d3d_share_handle_client_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANGLE_device_d3d;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANGLE_query_surface_pointer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANGLE_surface_d3d_texture_2d_share_handle;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ANGLE_window_fixed_size;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ARM_implicit_external_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_ARM_pixmap_multisample_discard;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_buffer_age;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_client_extensions;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_create_context_robustness;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_device_base;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_device_drm;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_device_enumeration;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_device_openwf;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_device_query;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_gl_colorspace_bt2020_linear;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_gl_colorspace_bt2020_pq;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_gl_colorspace_scrgb_linear;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_image_dma_buf_import;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_image_dma_buf_import_modifiers;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_multiview_window;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_output_base;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_output_drm;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_output_openwf;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_pixel_format_float;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_platform_base;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_platform_device;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_platform_wayland;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_platform_x11;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_protected_content;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_protected_surface;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_stream_consumer_egloutput;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_surface_SMPTE2086_metadata;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_swap_buffers_with_damage;
EGLEW_VAR_EXPORT GLboolean __EGLEW_EXT_yuv_surface;
EGLEW_VAR_EXPORT GLboolean __EGLEW_HI_clientpixmap;
EGLEW_VAR_EXPORT GLboolean __EGLEW_HI_colorformats;
EGLEW_VAR_EXPORT GLboolean __EGLEW_IMG_context_priority;
EGLEW_VAR_EXPORT GLboolean __EGLEW_IMG_image_plane_attribs;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_cl_event;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_cl_event2;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_client_get_all_proc_addresses;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_config_attribs;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_context_flush_control;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_create_context;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_create_context_no_error;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_debug;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_fence_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_get_all_proc_addresses;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_gl_colorspace;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_gl_renderbuffer_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_gl_texture_2D_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_gl_texture_3D_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_gl_texture_cubemap_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_image_base;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_image_pixmap;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_lock_surface;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_lock_surface2;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_lock_surface3;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_mutable_render_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_no_config_context;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_partial_update;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_platform_android;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_platform_gbm;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_platform_wayland;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_platform_x11;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_reusable_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_attrib;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_consumer_gltexture;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_cross_process_fd;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_fifo;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_producer_aldatalocator;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_stream_producer_eglsurface;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_surfaceless_context;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_swap_buffers_with_damage;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_vg_parent_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_KHR_wait_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_MESA_drm_image;
EGLEW_VAR_EXPORT GLboolean __EGLEW_MESA_image_dma_buf_export;
EGLEW_VAR_EXPORT GLboolean __EGLEW_MESA_platform_gbm;
EGLEW_VAR_EXPORT GLboolean __EGLEW_MESA_platform_surfaceless;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NOK_swap_region;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NOK_swap_region2;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NOK_texture_from_pixmap;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_3dvision_surface;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_coverage_sample;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_coverage_sample_resolve;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_cuda_event;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_depth_nonlinear;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_device_cuda;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_native_query;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_post_convert_rounding;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_post_sub_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_robustness_video_memory_purge;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_consumer_gltexture_yuv;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_cross_display;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_cross_object;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_cross_partition;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_cross_process;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_cross_system;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_fifo_next;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_fifo_synchronous;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_frame_limits;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_metadata;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_remote;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_reset;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_socket;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_socket_inet;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_socket_unix;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_stream_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_sync;
EGLEW_VAR_EXPORT GLboolean __EGLEW_NV_system_time;
EGLEW_VAR_EXPORT GLboolean __EGLEW_TIZEN_image_native_buffer;
EGLEW_VAR_EXPORT GLboolean __EGLEW_TIZEN_image_native_surface;
/* ------------------------------------------------------------------------ */

GLEWAPI GLenum GLEWAPIENTRY eglewInit (EGLDisplay display);
GLEWAPI GLboolean GLEWAPIENTRY eglewIsSupported (const char *name);

#define EGLEW_GET_VAR(x) (*(const GLboolean*)&x)
#define EGLEW_GET_FUN(x) x

GLEWAPI GLboolean GLEWAPIENTRY eglewGetExtension (const char *name);

#ifdef __cplusplus
}
#endif

#endif /* __eglew_h__ */
