#ifndef FITNESSINSTRUCTOR_H
#define FITNESSINSTRUCTOR_H

#include <QString>
#include "user.h"
#include "workoutplan.h"

class FitnessInstructor {
public:
    FitnessInstructor(const QString& name);
    std::unique_ptr<WorkoutPlan> createWorkoutPlan(const User& user);

private:
    QString name;
};

#endif // FITNESSINSTRUCTOR_H
