#include "filtertests.h"

FilterTests::FilterTests():
    m_recipe    ("TestRecipe", Categories().Quick, "", 0)
{

}

void FilterTests::initTestCase()
{
    qDebug("Init called");
    m_recipe = Recipe("TestRecipe", Categories().Quick, "", 0);
    m_recipe.addIngredient(Ingredient("Tomato", 1, UnitTypes().Number));
}

void FilterTests::isInFilter_recipeWithFilterIngredient_ReturnsTrue()
{
    Filter filter;
    filter.addIngredientFilter("Tomato");

    bool result = filter.isInFilter(m_recipe);

    QCOMPARE(result, true);
}

void FilterTests::isInFilter_recipeWithDifferentIngredient_ReturnsFalse()
{
    Filter filter;
    filter.addIngredientFilter("Carotte");

    bool result = filter.isInFilter(m_recipe);

    QCOMPARE(result, false);
}

void FilterTests::isInFilter_recipeWithPartialFilter_ReturnsTrue()
{
    Filter filter;
    filter.addIngredientFilter("Toma");

    bool result = filter.isInFilter(m_recipe);

    QCOMPARE(result, true);
}

void FilterTests::removeIngredientFilter_recipeWithDifferentIngredient_isNowInFilter()
{
    Filter filter;
    filter.addIngredientFilter("Tomato");
    QCOMPARE(filter.isInFilter(m_recipe), true);

    filter.removeIngredientFilter("Tomato");

    QCOMPARE(filter.isInFilter(m_recipe), false);
}
