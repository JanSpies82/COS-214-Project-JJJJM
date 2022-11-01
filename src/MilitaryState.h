///@author Jake Mahloko

#include <exception>
#ifndef __MilitaryState_h__
#define __MilitaryState_h__

#include <ctime>
#include <vector>

class Military;
//TODO how does this work? If a state object is constructed in the contructor then what does storeState() do? Why is the "state" object being stored a military? Does this object just make a deep copy of a military and store that?
class MilitaryState
{
	public:
        /**
         * 
         * 
         */ 
        MilitaryState();
        /**
           * @brief construct a MilitaryState Object
           * @param Military object
          **/
          MilitaryState(Military* m);
          /**
           * 
           * 
           * 
           */
          ~MilitaryState();
          /**
           * @brief stores the state of the military
           * @param Military object
           **/
          void storeState(Military * m);
        
          /**
           * @brief getter for the numTroops attribute
           * @return the number of troops of the military
          */
          int getNumTroops();
        
        /**
         * @brief setter for the numTroops attribute
        */
        void setNumTroops(int);
    
        /**
         * @brief getter for the numTanks attribute
         * @return the number of tanks of the military
        */
        int getNumTanks();
    
        /**
         * @brief setter for the numTanks attribute
         * @param numTanks the new number of tanks
        */
        void setNumTanks(int);
    
        /**
         * @brief getter for the number of planes of a country's military
         * @return the number of planes of the military
        */
        int getNumPlanes();
    
        /**
         * @brief setter for the numPlanes attribute
         * @param numPlanes the new number of planes
        */
        void setNumPlanes(int);
    
        /**
         * @brief getter for the number of ships of a country's military
         * @return the number of ships of the military
        */
        int getNumShips();
    
        /**
         * @brief setter for the numShips attribute
         * @param numShips the new number of ships
        */
        void setNumShips(int);
        /**
         * 
         * 
         * 
         */
         Military* getState(); 
    
         /**
          * 
          * 
          */ 
          void setNumBatalion(int);
          /**
           * 
           * 
           * 
           */
          int getNumBattalions();
         /**
          * 
          * 
          */
            
private:
	Military* State;
	int numTroops;
    int numTanks;
    int numPlanes;
    int numShips;
    int numBattalions;
	std::time_t timestamp;

};

#endif
