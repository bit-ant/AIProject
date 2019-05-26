#include <core/MisplacedHeuristic.h>
#include <memory>

namespace core {

float MisplacedHeuristic::calculateCost(std::shared_ptr<api::EightPuzzleNode> &node) const
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
            for (unsigned int pos = 0; pos < currentBoardState.size(); ++pos)
            {
                if (currentBoardState.at(pos) != api::EightPuzzleNode::emptySquare // Disregard empty square from calculations
                        && currentBoardState.at(pos) != goalState.at(pos))
                {
                    // Misplaced tile found. Increment the cost
                    ++cost;
                }
            }
        }
    }
    return cost;
}

} //namespace core
