#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connectArduino();
    void updateTemperature(QString);
    void on_btnConnect_clicked();
    void readSerial();
    void writeSerial();
    void realtimeDataSlot();
    void on_btnON_clicked();
    void on_btnOFF_clicked();
    void on_instructions_clicked();
    void on_aboutMe_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    double temperature_value;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H
