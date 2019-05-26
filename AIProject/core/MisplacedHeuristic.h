#ifndef CORE_MISPLACEDHEURISTIC_H
#define CORE_MISPLACEDHEURISTIC_H

#include <api/IHeuristicFunction.h>
#include <api/EightPuzzleNode.h>

namespace core {

class MisplacedHeuristic : public api::IHeuristicFunction {

public:
    MisplacedHeuristic() = default;

    float calculateCost(std::shared_ptr<api::EightPuzzleNode>& node) const override;
};
} //namespace core

#endif // CORE_MISPLACEDHEURISTIC_H
