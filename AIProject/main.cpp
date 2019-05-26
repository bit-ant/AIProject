#include <iostream>
#include <api/EightPuzzleNode.h>
#include <core/MisplacedHeuristic.h>
#include <core/HillClimbSearch.h>
#include <core/ManhattanHeuristic.h>
#include <core/AStarSearch.h>

using namespace std;

int main()
{
    std::shared_ptr<api::EightPuzzleNode> initialState = std::make_shared<api::EightPuzzleNode>(
                api::EightPuzzleNode::gameBoard{1, api::EightPuzzleNode::emptySquare, 2, 3, 4, 5, 6, 7 ,8},
                0.0);

    std::shared_ptr<api::EightPuzzleNode> initialState1 = std::make_shared<api::EightPuzzleNode>(
                api::EightPuzzleNode::gameBoard{8, api::EightPuzzleNode::emptySquare, 6, 5, 4, 7, 2, 3, 1},
                0.0);
    std::shared_ptr<api::EightPuzzleNode> initialState2 = std::make_shared<api::EightPuzzleNode>(
                api::EightPuzzleNode::gameBoard{1, 6, 4, 5, api::EightPuzzleNode::emptySquare, 3, 2, 7, 8},
                0.0);

    std::shared_ptr<api::EightPuzzleNode> goalState = std::make_shared<api::EightPuzzleNode>(
                api::EightPuzzleNode::gameBoard{api::EightPuzzleNode::emptySquare, 1, 2, 3, 4, 5, 6, 7 ,8},
                0.0);
    std::shared_ptr<api::IHeuristicFunction> misplacedHeuristic = std::make_shared<core::MisplacedHeuristic>();
    std::shared_ptr<api::IHeuristicFunction> manhattanHeuristic = std::make_shared<core::ManhattanHeuristic>();
    core::HillClimbSearch hillClimb(initialState, goalState, manhattanHeuristic, 10000);
    core::AStarSearch aStarSearch(initialState1, goalState, manhattanHeuristic, 10000);

    //hillClimb.search();
    aStarSearch.search();
    return 0;
}
