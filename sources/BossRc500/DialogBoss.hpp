#pragma once

#include "Dialog.hpp"

#include <nlohmann/json.hpp>

// --------------------------------------------------------------------------
class BossCopierDialog : public Ui_BossRc500Dialog, public QObject
{
public:
    BossCopierDialog(QDialog& dialog);

private:
    void setup();
    void add_tooltips();
    void add_callbacks();
    void add_combo_items();

    void on_open();
    void on_save();
    void on_quit();

    void on_memory_changed();
    void load_memory();


private:
    QDialog& _parent;

    nlohmann::json _database;
};
