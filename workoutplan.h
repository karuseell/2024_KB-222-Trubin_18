#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H

#include <vector>
#include <memory>
#include "exercise.h"

class WorkoutPlan {
public:
    void addExercise(std::shared_ptr<Exercise> exercise);
    int getTotalDuration() const;
    int getTotalCalories() const;
    QString getPlanDetails() const;
    const std::vector<std::shared_ptr<Exercise>>& getExercises() const;

private:
    std::vector<std::shared_ptr<Exercise>> exercises;
    int totalDuration = 0;
    int totalCalories = 0;
};

#endif // WORKOUTPLAN_H
