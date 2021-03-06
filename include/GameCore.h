//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.h                                //
//            █ █        █ █        CoreGenius                                //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CoreGenius_include_GameCore_h__
#define __CoreGenius_include_GameCore_h__

//std
#include <vector>
#include <random>
//CoreGenius
#include "CoreGenius_Utils.h"
//CoreRandom
#include "CoreRandom.h"


NS_COREGENIUS_BEGIN

class GameCore
{
    // Enums / Constants / Typedefs //
public:
    ///@brief Defines the possible states for GameCore.
    ///@see checkSideGuess, getStatus, getCurrentSideGuessIndex.
    enum class Status
    {
        CorrectAndContinue, ///< Player hit the side  - Still Has other sides.
        CorrectAndFinish,   ///< Player hit the side  - Sequence is over.
        Wrong,              ///< Player miss the side - Game is Over.
        None                ///< Game is not stated yet.
    };

    ///@brief Just to easy the typing... "A sequence of ... (sides)".
    typedef std::vector<int> Sequence;


    // CTOR/DTOR //
public:
    ///@brief Construct the Game Core.
    ///@warning No sanity checks are made on the arguments.
    ///@param sidesCount How many sides the core will have.
    ///@param seed The seed that will be used by the random number genrator.
    ///If using CoreRandom::Random::kRandomSeed a random seed
    ///will be used each time.
    ///@see CoreRandom::Random::kRandomSeed.
    GameCore(int sidesCount, int seed = CoreRandom::Random::kRandomSeed);


    // Public Methods //
public:
    ///@brief Selects a random side of possibles sides
    ///and append it to the current sequence.
    ///@returns The side selected - In range of [0, sidesCount).
    int generateNextSide();


    ///@brief Check if the player's side guess matches
    ///with the side at the current index in sequence.
    ///@param guessSide The player's guess.
    ///@returns A status indicating the status of game.
    ///@see Status, getCurrentSideGuessIndex, getSequence
    Status checkSideGuess(int guessSide);

    ///@brief Gets the current side index in the sequence.
    ///@returns The current index.
    ///@see checkSideIndex, generateNextSide
    int getCurrentSideGuessIndex() const;


    ///@brief Gets the whole sequence.
    ///@returns The whole sequence.
    const Sequence& getSequence() const;

    ///@brief Gets the current sequence size.
    ///@returns The size of sequence.
    ///@see getCurrentSideIndex, generateNextSide.
    int getSequenceSize() const;


    ///@brief Gets the current state of game.
    ///@returns The state of game.
    ///@see Status.
    Status getStatus() const;

    ///@brief Gets the actual seed used.
    ///@returns If GameCore is constructed using the
    ///CoreRandom::Random::kRandomSeed the actual seed
    ///used will be returned here.
    ///@see CoreRandom::Random::kRandomSeed.
    int getSeed() const;

    // iVars //
private:
    Sequence m_sequence;
    Status   m_status;

    int m_currentIndex;

    int m_sidesCount;

    CoreRandom::Random m_random;
};

NS_COREGENIUS_END
#endif // defined(__CoreGenius_include_GameCore_h__) //
