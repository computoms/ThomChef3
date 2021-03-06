#include "ingredientfilter.h"

IngredientFilter::IngredientFilter()
{
    m_defaultIngredientFilters.push_back("salt");
    m_defaultIngredientFilters.push_back("pepper");
    m_defaultIngredientFilters.push_back("flour");
}

bool IngredientFilter::isInFilter(const Recipe &recipe) const
{
    for (int i = 0; i < recipe.getNumberOfIngredients(); ++i)
        if (!isInFilter(recipe.getIngredient(i)))
            return false;

    return true;
}

bool IngredientFilter::addIngredientFilter(std::string ingredientFilter)
{
    if (containsFilter(ingredientFilter))
        return false;

    m_ingredientFilters.push_back(ingredientFilter);
    filterUpdated();
    return true;
}

void IngredientFilter::removeIngredientFilter(std::string ingredientFilter)
{
    for (auto it = m_ingredientFilters.begin(); it != m_ingredientFilters.end(); ++it)
    {
        if (*it == ingredientFilter)
        {
            m_ingredientFilters.erase(it);
            break;
        }
    }
    filterUpdated();
}

bool IngredientFilter::isEmpty() const
{
    return m_ingredientFilters.empty();
}

void IngredientFilter::setDefaultIngredients(std::vector<std::string> defaultIngredients)
{
    m_defaultIngredientFilters = defaultIngredients;
}

bool IngredientFilter::isInFilter(Ingredient ingredient) const
{
    for (auto &f : m_ingredientFilters)
        if (this->match(f, ingredient))
            return true;
    for (auto &f : m_defaultIngredientFilters)
        if (this->match(f, ingredient))
            return true;
    return false;
}

bool IngredientFilter::match(std::string ingredientFilter, Ingredient ingredient) const
{
    // Transform to lower-case string
    std::string ingName = ingredient.getName();
    std::transform(ingName.begin(), ingName.end(), ingName.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    std::string filter = ingredientFilter;
    std::transform(filter.begin(), filter.end(), filter.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return ingName.find(filter) != std::string::npos;
}

bool IngredientFilter::containsFilter(std::string filter) const
{
    for (auto &ing : m_ingredientFilters)
        if (ing == filter)
            return true;
    return false;
}
