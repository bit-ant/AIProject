#include <core/ManhattanHeuristic.h>
#include <cmath>

namespace core {

float ManhattanHeuristic::calculateCost(std::shared_ptr<api::EightPuzzleNode> &node) const
{
    float cost = 0.0;
    const static api::EightPuzzleNode::gameBoard goalState = {api::EightPuzzleNode::emptySquare, 1, 2, 3, 4, 5, 6, 7 ,8};

    if (nullptr != node)
    {
        api::EightPuzzleNode::gameBoard currentBoardState = node->getState();
        if (goalState == currentBoardState)
        {
            // Solution found! Return zero cost
            cost = 0.0;
        }
        else
        {
            for (uint8_t pos = 0; pos < currentBoardState.size(); ++pos)
            {
                const auto& currentNumber = currentBoardState.at(pos);
                if (currentNumber != api::EightPuzzleNode::emptySquare // Disregard empty square from calculations
                        && currentNumber != goalState.at(pos))
                {
                    auto distance = std::abs(currentNumber - pos);

                    // Since weare using a single-dimensional array the above calculation is not always corrent
                    // Modify accordingly
                    if (distance >= 4 && distance < 6)
                    {
                        distance-=2;
                    }
                    else if (distance >=6)
                    {
                        distance -=3;
                    }
                    // Now accumulate for all elements of the board
                    cost += distance;
                }
            }
        }
    }
    return cost;
}

} //namespace core
