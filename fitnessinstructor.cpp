#include "fitnessinstructor.h"
#include "exercise.h"

FitnessInstructor::FitnessInstructor(const QString& name)
    : name(name) {}

std::unique_ptr<WorkoutPlan> FitnessInstructor::createWorkoutPlan(const User& user) {
    auto plan = std::make_unique<WorkoutPlan>();
    // Пример добавления упражнений на основе целей пользователя
    if (user.getGoal() == "Похудение") {
        plan->addExercise(std::make_shared<Exercise>("Бег", "Бег на свежем воздухе", 30, 300));
        plan->addExercise(std::make_shared<Exercise>("Скакалка", "Прыжки на скакалке", 15, 200));
    } else if (user.getGoal() == "Наращивание мышечной массы") {
        plan->addExercise(std::make_shared<Exercise>("Приседания", "Приседания с весом", 20, 150));
        plan->addExercise(std::make_shared<Exercise>("Жим лежа", "Жим лежа на скамье", 15, 180));
    } else if (user.getGoal() == "Поддержание формы") {
        plan->addExercise(std::make_shared<Exercise>("Йога", "Упражнения йоги", 30, 100));
        plan->addExercise(std::make_shared<Exercise>("Плавание", "Плавание в бассейне", 30, 250));
    }
    return plan;
}
