#ifndef INCLUDE_LEARN_ALCNNLEARNER_H
#define INCLUDE_LEARN_ALCNNLEARNER_H
#include "ALLearnFactory.h"
#include "math/ALIGradientDecent.h"
#include "math/ALIMatrix4DOp.h"
#include "cJSON/cJSON.h"


class ALCNNLearner : public ALISuperviseLearner
{
public:
    class LayerStruct;
    
    ALCNNLearner(const cJSON* description);
    virtual ~ ALCNNLearner();
    
    virtual ALIMatrixPredictor* vLearn(const ALFloatMatrix* X, const ALFloatMatrix* Y) const;
    ALGradientMethod* getGDMethod() const;

private:
    ALSp<ALIGradientDecent> mGDMethod;
    ALSp<ALIGradientDecent::DerivativeFunction> mDetFunction;
    unsigned int mIteration;
    unsigned int mBatchSize;
    unsigned int mInputSize;
    LayerStruct* mLayerPredict;
    ALSp<ALFloatMatrix> mProp;
};

#endif
