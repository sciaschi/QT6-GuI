#include <QApplication>
#include <QLabel>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Exiting in 5 seconds...");
    label.resize(200, 100);
    label.show();

    QTimer::singleShot(5000, &app, &QApplication::quit); // Exit after 5 seconds

    return app.exec();
}
