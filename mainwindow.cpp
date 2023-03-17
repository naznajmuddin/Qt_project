#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include "secmain.h"
#include "secdialog.h"
#include "thirddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tempLcdNumber->display("------");
    ui->label->setText("Arduino is not connected");
    ui->btnON->setEnabled(false);
    ui->btnOFF->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
            arduino->close(); //    Close the serial port if it's open.
        }
    delete ui;
}

void MainWindow::connectArduino()
{
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    temperature_value = 0.0;

    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
            if(serialPortInfo.hasVendorIdentifier()){
                qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
            }
            qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
            if(serialPortInfo.hasProductIdentifier()){
                qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
            }
        }


    //  For each available serial port
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            //  check if the serialport has both a product identifier and a vendor identifier
            if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
                //  check if the product ID and the vendor ID match those of the arduino uno
                if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                        && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                    arduino_is_available = true; //    arduino uno is available on this port
                    arduino_uno_port_name = serialPortInfo.portName();
                }
            }
        }
        /*
             *  Open and configure the arduino port if available
             */
            if(arduino_is_available){
                qDebug() << "Found the arduino port...\n";
                arduino->setPortName(arduino_uno_port_name);
                arduino->open(QSerialPort::ReadWrite);
                arduino->setBaudRate(QSerialPort::Baud9600);
                arduino->setDataBits(QSerialPort::Data8);
                arduino->setFlowControl(QSerialPort::NoFlowControl);
                arduino->setParity(QSerialPort::NoParity);
                arduino->setStopBits(QSerialPort::OneStop);
                QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
                ui->label->setText("Arduino is Connected");
                ui->btnConnect->setEnabled(false);
                ui->btnON->setEnabled(true);
                ui->btnOFF->setEnabled(true);
            }else{
                qDebug() << "Couldn't find the correct port for the arduino.\n";
                QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
            }
}

void MainWindow::updateTemperature(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->tempLcdNumber->display(sensor_reading);
}

void MainWindow::on_btnConnect_clicked()
{
    connectArduino();
}

void MainWindow::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     * The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature value.
     *
     */
    QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator

    //  Check to see if there less than 3 tokens in buffer_split.
    //  If there are at least 3 then this means there were 2 commas,
    //  means there is a parsed temperature value as the second token (between 2 commas)
    if(buffer_split.length() < 3){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        // the second element of buffer_split is parsed correctly, update the temperature value on temp_lcdNumber
        serialBuffer = "";
        qDebug() << buffer_split << "\n";
        parsed_data = buffer_split[1];
        temperature_value = parsed_data.toDouble(); // convert to fahrenheit
        qDebug() << "Air Quality Index Value: " << temperature_value << "\n";
        parsed_data = QString::number(temperature_value, 'g', 4); // format precision of temperature_value to 4 digits or fewer
        MainWindow::updateTemperature(parsed_data);

        ui->customPlot->addGraph(); // blue line
        ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
         //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        //ui->customPlot->addGraph(); // red line
        //ui->customPlot->graph(0)->setPen(QPen(QColor(255, 110, 40)));

        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%h:%m:%s");
        ui->customPlot->xAxis->setTicker(timeTicker);
        ui->customPlot->axisRect()->setupFullAxesBox();
        ui->customPlot->xAxis->setLabel("Time(s)");
        ui->customPlot->yAxis->setLabel("Digital Value");
        //ui->customPlot->yAxis->setRange(-1.2, 1.2);
        ui->customPlot->yAxis->setRange(0, 1);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));


        // make left and bottom axes transfer their ranges to right and top axes:
        //connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

        // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
        connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
        dataTimer.start(5); // Interval 0 means to refresh as fast as possible
    }


}

void MainWindow::writeSerial()
{

}

void MainWindow::realtimeDataSlot()
{
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    //qDebug() << "Temperature1: " << temperature_value << "\n";
    //if (key-lastPointKey > 0.002) // at most add point every 2 ms
    if (key-lastPointKey > 2) // at most add point every 2 s
    {
      // add data to lines:
      //ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
      parsed_data = QString::number(temperature_value, 'g', 4); // format precision of temperature_value to 4 digits or fewer
      ui->customPlot->graph(0)->addData(key, temperature_value);
      MainWindow::updateTemperature(parsed_data);
      qDebug() << "Air Quality Index Value: " << temperature_value << "\n";
      //ui->customPlot->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
      // rescale value (vertical) axis to fit the current data:
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true);
      lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 12, Qt::AlignRight);
    ui->customPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
      /*ui->statusBar->showMessage(
            QString("%1 FPS, Total Data points: %2")
            .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
            .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
            , 0);*/
      lastFpsKey = key;
      frameCount = 0;
    }
}

void MainWindow::on_btnON_clicked()
{
    if(arduino->isWritable()){
            arduino->write("a");
            ui->btnON->setEnabled(false);
            readSerial();
        }else{
            qDebug() << "Couldn't write to serial!";
        }
}

void MainWindow::on_btnOFF_clicked()
{
    if(arduino->isWritable()){
            arduino->write("b");
            ui->btnON->setEnabled(true);
            ui->tempLcdNumber->display("OFF");
        }else{
            qDebug() << "Couldn't write to serial!";
        }
}


void MainWindow::on_instructions_clicked()
{
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();
}

void MainWindow::on_aboutMe_clicked()
{
    ThirdDialog thirddialog;
    thirddialog.setModal(true);
    thirddialog.exec();
}
