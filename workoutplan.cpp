#include "workoutplan.h"

void WorkoutPlan::addExercise(std::shared_ptr<Exercise> exercise) {
    exercises.push_back(exercise);
    totalDuration += exercise->getDuration();
    totalCalories += exercise->getCalories();
}

int WorkoutPlan::getTotalDuration() const {
    return totalDuration;
}

int WorkoutPlan::getTotalCalories() const {
    return totalCalories;
}

QString WorkoutPlan::getPlanDetails() const {
    QString details;
    for (const auto& exercise : exercises) {
        details += exercise->getName() + ": " + exercise->getDescription() + "\n";
    }
    return details;
}

const std::vector<std::shared_ptr<Exercise>>& WorkoutPlan::getExercises() const {
    return exercises;
}
