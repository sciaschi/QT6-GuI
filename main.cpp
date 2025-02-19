#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <csignal> // For signal handling

// Global pointer to QApplication for signal handling
QApplication *appPtr = nullptr;

// Signal handler function
void handleSignal(int signal) {
    if (signal == SIGINT && appPtr) {
        appPtr->quit();
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    appPtr = &app; // Store the QApplication pointer

    // Set up the signal handler
    std::signal(SIGINT, handleSignal);

    QLabel label("Press Ctrl+C to exit");
    label.resize(200, 100);
    label.show();

    return app.exec();
}
