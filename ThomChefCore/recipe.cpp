#include "recipe.h"
#include <ctime>
#include <chrono>

Recipe::Recipe(std::string name, Category category,
               std::string description, double preparationTimeInMinutes):
    m_name              (name),
    m_category          (category),
    m_description       (description),
    m_prepTimeInMinutes (preparationTimeInMinutes)
{
    m_id = generateGuid();
}

Recipe::Recipe(long id, std::string name, Category category,
               std::string description, double prepTimeInMinutes):
    m_id            (id),
    m_name          (name),
    m_category      (category),
    m_description   (description),
    m_prepTimeInMinutes(prepTimeInMinutes)
{

}

long Recipe::getId() const
{
    return m_id;
}

std::string Recipe::getName() const
{
    return m_name;
}

Category Recipe::getCategory() const
{
    return m_category;
}

std::string Recipe::getDescription() const
{
    return m_description;
}

int Recipe::getPreparationTimeInMinutes() const
{
    return m_prepTimeInMinutes;
}

std::string Recipe::getPreparationTime() const
{
    return std::to_string(m_prepTimeInMinutes) + " min";
}

int Recipe::getNumberOfIngredients() const
{
    return m_ingredients.size();
}

Ingredient Recipe::getIngredient(int index) const
{
    if ((int)m_ingredients.size() <= index || index < 0)
        throw std::invalid_argument("The ingredient index is invalid");
    return m_ingredients[index];
}

void Recipe::addIngredient(Ingredient ingredient)
{
    m_ingredients.push_back(ingredient);
}

std::string Recipe::getFriendlyIngredients()
{
    std::string ingredientsDescription;
    for (auto &ingredient : m_ingredients)
    {
        ingredientsDescription += ingredient.getFriendlyName() + "\n";
    }

    return ingredientsDescription;
}

time_t Recipe::generateGuid()
{
    auto now = std::chrono::system_clock::now();
    time_t nowTt = std::chrono::system_clock::to_time_t(now);
    time_t reference = 1577836800; // 01-01-2020
    return nowTt - reference;
}
