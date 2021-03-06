#ifndef LEARN_CNN_CNNDERIVATIVEFUNCTION_H
#define LEARN_CNN_CNNDERIVATIVEFUNCTION_H
#include "math/ALIGradientDecent.h"
#include "LayerWrap.h"
namespace ALCNN {
    class CNNDerivativeFunction : public ALIGradientDecent::DerivativeFunction
    {
    public:
        virtual ALFloatMatrix* vCompute(ALFloatMatrix* coefficient, const ALFloatMatrix* Merge) const override;
        virtual size_t vInitParameters(ALFloatMatrix* coefficient) const override;
        
        CNNDerivativeFunction(ALSp<LayerWrap> first, size_t outputSize);
        virtual ~ CNNDerivativeFunction();
    private:
        ALSp<LayerWrap> mFirst;
        LayerWrap* mLast;
        size_t mOutputSize;
        ALFLOAT mDecay;
        mutable ALFLOAT mCurrentLoss;
    };
}
#endif
