#include "recipe.h"

Recipe::Recipe(std::string name, Category category,
               std::string description, double preparationTimeInMinutes):
    m_name              (name),
    m_category          (category),
    m_description       (description),
    m_prepTimeInMinutes (preparationTimeInMinutes)
{

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
