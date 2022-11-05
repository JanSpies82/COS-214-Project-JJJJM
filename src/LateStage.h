///@author Mekhail Muller

#ifndef __LateStage_h__
#define __LateStage_h__

#include "WarStage.h"

class LateStage;

class LateStage : public WarStage
{

public:
        /**
         * @brief returns warstage via int = 2
         */
        int getWarStage();

        /**
         * @brief Construct a new Late Stage object
         *
         */
        LateStage();

        /**
         * @brief Destroy the Late Stage object
         *
         */
        ~LateStage();

        /**
         * @brief Return a deep copy of the Late Stage object
         *
         * @return LateStage*
         */
        LateStage *clone();
};

#endif
