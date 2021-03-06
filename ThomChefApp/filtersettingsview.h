#ifndef FILTERSETTINGSVIEW_H
#define FILTERSETTINGSVIEW_H

#include <QDialog>
#include <QListWidget>
#include "ThomChefCore/configuration.h"

namespace Ui {
class FilterSettingsView;
}

/**
 * @brief Implementation of the view that manages settings of the filters.
 */
class FilterSettingsView : public QDialog
{
    Q_OBJECT

public:
    explicit FilterSettingsView(QWidget *parent = nullptr);
    ~FilterSettingsView();

    void init(const Configuration &config);
    std::vector<std::string> getDefaultIngredients() const;

private slots:
    void on_button_addDefaultIngredient_clicked();

    void on_button_deleteDefaultIngredient_clicked();

    void on_edit_defaultIngredient_textChanged(const QString &arg1);

    void on_edit_defaultIngredient_returnPressed();

    void on_listDefaultIngredients_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::FilterSettingsView *ui;
    std::vector<std::string> m_defaultIngredients;
};

#endif // FILTERSETTINGSVIEW_H
