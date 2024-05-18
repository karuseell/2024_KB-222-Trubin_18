#ifndef USER_H
#define USER_H

#include <QString>
#include <memory>
#include "workoutplan.h"

class User {
public:
    User(const QString& name, int age, int weight, const QString& goal);
    QString getName() const;
    int getAge() const;
    int getWeight() const;
    QString getGoal() const;
    void setWorkoutPlan(std::unique_ptr<WorkoutPlan> plan);
    const WorkoutPlan* getWorkoutPlan() const;

private:
    QString name;
    int age;
    int weight;
    QString goal;
    std::unique_ptr<WorkoutPlan> workoutPlan;
};

#endif // USER_H
