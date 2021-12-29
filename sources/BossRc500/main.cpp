#include "BossRc500MainDialog.hpp"

#include <QApplication>
#include <QtPlugin>
#include <QDialog>
#include <QFontDatabase>
#include <QStyleFactory>

#include <iostream>

#ifdef LINUX

Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
#else
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#endif

// --------------------------------------------------------------------------
int
main(int argc, char* argv[])
{
    try {
        QApplication app(argc, argv);

        QApplication::setStyle(QStyleFactory::create("Fusion"));

        int font_id = QFontDatabase::addApplicationFont("./resources/fonts/D-DINCondensed.ttf");
        auto family = QFontDatabase::applicationFontFamilies(font_id).at(0);

        qApp->setFont(QFont{family, 15});
        qApp->setStyleSheet(BossRc500::StyleSheet);

        QDialog dialog;
        BossRc500MainDialog bossUi(dialog);
        dialog.show();

        return QCoreApplication::exec();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
