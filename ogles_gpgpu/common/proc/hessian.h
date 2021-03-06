//
// ogles_gpgpu project - GPGPU for mobile devices and embedded systems using OpenGL ES 2.0
//
// See LICENSE file in project repository root for the license.
//

// Copyright (c) 2017, David Hirvonen (this file)

/**
 * GPGPU hessian processor.
 */
#ifndef OGLES_GPGPU_COMMON_PROC_HESSIAN
#define OGLES_GPGPU_COMMON_PROC_HESSIAN

#include "ogles_gpgpu/common/proc/filter3x3.h"

namespace ogles_gpgpu {

/**
 * GPGPU gradient, gradient magnitude and orientation
 */
class HessianProc : public Filter3x3Proc {
public:
    /**
     * Constructor.
     */
    HessianProc(float edgeStrength = 1.f, bool doHessian = true);

    /**
     * Return the processors name.
     */
    virtual const char* getProcName() {
        return "HessianProc";
    }

    void setEdgeStrength(float strength) {
        edgeStrength = strength;
    }

    float getEdgeStrength() const {
        return edgeStrength;
    }

private:
    /**
     * Get the fragment shader source.
     */
    virtual const char* getFragmentShaderSource() {
        return doHessian ? fshaderHessianAndDeterminantSrc : fshaderDeterminantSrc;
    }

    /**
     * Set uniform values;
     */
    virtual void setUniforms();

    /**
     * Get uniform indices.
     */
    virtual void getUniforms();

    bool doHessian = true;

    float edgeStrength = 1.0f;

    GLuint shParamUEdgeStrength = 0;

    static const char* fshaderHessianAndDeterminantSrc; // fragment shader source

    static const char* fshaderDeterminantSrc; // fragment shader source
};
}

#endif
