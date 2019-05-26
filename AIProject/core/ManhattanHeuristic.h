#ifndef CORE_MANHATTANHEURISTIC_H
#define CORE_MANHATTANHEURISTIC_H

#include <api/IHeuristicFunction.h>
#include <api/EightPuzzleNode.h>

namespace core {

class ManhattanHeuristic : public api::IHeuristicFunction {

public:
    ManhattanHeuristic() = default;

    float calculateCost(std::shared_ptr<api::EightPuzzleNode>& node) const override;
};
} //namespace core

#endif // CORE_MANHATTANHEURISTIC_H
