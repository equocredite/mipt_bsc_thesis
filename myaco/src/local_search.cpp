#include "local_search.h"

#include <chrono>
#include <random>

using namespace myaco;

LocalSearcher::LocalSearcher(Schedule&& schedule, IPerturbator* perturbator = new SimplePerturbator())
        : best_schedule_(std::move(schedule))
        , rng_(std::chrono::system_clock::now().time_since_epoch().count())
        , perturbator_(perturbator) {
}

Schedule& LocalSearcher::GetSchedule() {
    return best_schedule_;
}
#include <iostream>
void LocalSearcher::Log(Timer& timer) {
    std::cout << best_schedule_.GetQuality() << std::endl;
    history_.emplace_back(timer.TimeElapsed(), best_schedule_.GetQuality());
}

