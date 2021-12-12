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

    // Track callbacks
    void on_reverse_changed(QCheckBox* cb);
    void on_loopfx_changed(QCheckBox* cb);
    void on_oneshot_changed(QCheckBox* cb);

private:
    QDialog& _parent;

    nlohmann::json _database;
};
