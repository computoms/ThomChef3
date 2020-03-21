#include "ingredient.h"

Ingredient::Ingredient(std::string name, double quantity, UnitType unit):
    m_name          (name),
    m_quantity      (quantity),
    m_quantityType  (unit)
{

}

std::string Ingredient::getName() const
{
    return m_name;
}

double Ingredient::getQuantity() const
{
    return m_quantity;
}

UnitType Ingredient::getUnit() const
{
    return m_quantityType;
}
