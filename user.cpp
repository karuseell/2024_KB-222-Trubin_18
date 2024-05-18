#include "user.h"

User::User(const QString& name, int age, int weight, const QString& goal)
    : name(name), age(age), weight(weight), goal(goal) {}

QString User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

int User::getWeight() const {
    return weight;
}

QString User::getGoal() const {
    return goal;
}

void User::setWorkoutPlan(std::unique_ptr<WorkoutPlan> plan) {
    workoutPlan = std::move(plan);
}

const WorkoutPlan* User::getWorkoutPlan() const {
    return workoutPlan.get();
}
