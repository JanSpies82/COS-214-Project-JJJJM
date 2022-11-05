///@author Mekhail Muller

#include <exception>
#include <string>

#ifndef __WarStage_h__
#define __WarStage_h__

class Country;
class WarStage;

class WarStage
{
public:
        /**
         * @brief Virtual function for returning the warstage
         */
        virtual int getWarStage() = 0;

        /**
         * @brief Construct a new War Stage object
         *
         */
        WarStage();

        /**
         * @brief Virtual destructor for the War Stage object
         *
         */
        virtual ~WarStage();

        /**
         * @brief Return a deep copy of the War Stage object
         *
         * @return WarStage*
         */
        virtual WarStage *clone() = 0;
};

#endif