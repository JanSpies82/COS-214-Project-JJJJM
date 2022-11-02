#include <exception>
using namespace std;

#ifndef __EarlyStage_h__
#define __EarlyStage_h__

#include "WarStage.h"

// class WarStage;
class EarlyStage;

class EarlyStage : public WarStage
{
public:
    /**
     * @brief returns warstage via an int = 0
     * */
    int getWarStage();

    /**
     * @brief Construct a new Early Stage object
     *
     */
    EarlyStage();

    /**
     * @brief Destroy the Early Stage object
     *
     */
    ~EarlyStage();

    /**
     * @brief Return a deep copy of the Early Stage object
     *
     * @return EarlyStage*
     */
    EarlyStage *clone();
};

#endif
