#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sha256.h"

std::string int_to_string(int num){
    std::string res="";
    while (num>0) {
        res+=char(num%10+48);
        num/=10;
    }
    for(int i=0,j=res.length()-1;i<j;i++,j--)
    {
        char temp=res[i];
        res[i]=res[j];
        res[j]=temp;
    }
    return res;
}

void MainWindow::calculateHashOfBlock1()
{
    QString qstr=ui->lineEdit->text();
    qstr+=ui->lineEdit_2->text();
    qstr+=ui->textEdit->toPlainText();
    qstr+=ui->label_5->text();
    std::string str=qstr.toStdString();
    ui->label_7->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_48->setText(ui->label_7->text());
}

void MainWindow::calculateHashOfBlock2()
{
    QString qstr=ui->lineEdit_13->text();
    qstr+=ui->lineEdit_14->text();
    qstr+=ui->textEdit_7->toPlainText();
    qstr+=ui->label_48->text();
    std::string str=qstr.toStdString();
    ui->label_49->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_55->setText(ui->label_49->text());
}

void MainWindow::calculateHashOfBlock3()
{
    QString qstr=ui->lineEdit_15->text();
    qstr+=ui->lineEdit_16->text();
    qstr+=ui->textEdit_8->toPlainText();
    qstr+=ui->label_55->text();
    std::string str=qstr.toStdString();
    ui->label_56->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
//    ui->label_62->setText(ui->label_56->text());
}

void MainWindow::calculateHashOfBlock4()
{
    QString qstr=ui->lineEdit_17->text();
    qstr+=ui->lineEdit_18->text();
    qstr+=ui->textEdit_9->toPlainText();
    qstr+=ui->label_62->text();
    std::string str=qstr.toStdString();
    ui->label_63->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_69->setText(ui->label_63->text());
}

void MainWindow::calculateHashOfBlock5()
{
    QString qstr=ui->lineEdit_19->text();
    qstr+=ui->lineEdit_20->text();
    qstr+=ui->textEdit_10->toPlainText();
    qstr+=ui->label_69->text();
    std::string str=qstr.toStdString();
    ui->label_70->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_76->setText(ui->label_70->text());
}

void MainWindow::calculateHashOfBlock6()
{
    QString qstr=ui->lineEdit_21->text();
    qstr+=ui->lineEdit_22->text();
    qstr+=ui->textEdit_11->toPlainText();
    qstr+=ui->label_76->text();
    std::string str=qstr.toStdString();
    ui->label_77->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
}

void MainWindow::calculateHashOfBlock7()
{
    QString qstr=ui->lineEdit_23->text();
    qstr+=ui->lineEdit_24->text();
    qstr+=ui->textEdit_12->toPlainText();
    qstr+=ui->label_83->text();
    std::string str=qstr.toStdString();
    ui->label_84->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_90->setText(ui->label_84->text());
}

void MainWindow::calculateHashOfBlock8()
{
    QString qstr=ui->lineEdit_25->text();
    qstr+=ui->lineEdit_26->text();
    qstr+=ui->textEdit_13->toPlainText();
    qstr+=ui->label_90->text();
    std::string str=qstr.toStdString();
    ui->label_91->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
    ui->label_97->setText(ui->label_91->text());
}

void MainWindow::calculateHashOfBlock9()
{
    QString qstr=ui->lineEdit_27->text();
    qstr+=ui->lineEdit_28->text();
    qstr+=ui->textEdit_14->toPlainText();
    qstr+=ui->label_97->text();
    std::string str=qstr.toStdString();
    ui->label_98->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Distributed Blockchain");

    //Block-1 Initialization

    ui->lineEdit->setText("1");
    ui->label_5->setText("0000000000000000000000000000000000000000000000000000000000000000");
    calculateHashOfBlock1();
    for(int i=0;ui->label_7->text().at(0)!='0' || ui->label_7->text().at(1)!='0' || ui->label_7->text().at(2)!='0';i++)
    {
        ui->lineEdit_2->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock1();
    }

    //Block-1 Connections

    connect(ui->lineEdit,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock1();
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_2,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock1();
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->textEdit,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock1();
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->pushButton,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_7->text().at(0)!='0' || ui->label_7->text().at(1)!='0' || ui->label_7->text().at(2)!='0';i++)
        {
            ui->lineEdit_2->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock1();
        }
    });


    //Block-2 Initialization

    ui->lineEdit_13->setText("2");
    ui->label_48->setText(ui->label_7->text());
    calculateHashOfBlock2();
    for(int i=0;ui->label_49->text().at(0)!='0' || ui->label_49->text().at(1)!='0' || ui->label_49->text().at(2)!='0';i++)
    {
        ui->lineEdit_14->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock2();
    }

    //Block-2 Connections

    connect(ui->lineEdit_13,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_14,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->textEdit_7,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock2();
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->pushButton_7,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_49->text().at(0)!='0' || ui->label_49->text().at(1)!='0' || ui->label_49->text().at(2)!='0';i++)
        {
            ui->lineEdit_14->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock2();
        }
    });


    //Block-3 Initialization

    ui->lineEdit_15->setText("3");
    ui->label_55->setText(ui->label_49->text());
    calculateHashOfBlock3();
    for(int i=0;ui->label_56->text().at(0)!='0' || ui->label_56->text().at(1)!='0' || ui->label_56->text().at(2)!='0';i++)
    {
        ui->lineEdit_16->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock3();
    }

    //Block-3 Connections

    connect(ui->lineEdit_15,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_16,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->textEdit_8,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock3();
//        calculateHashOfBlock4();
//        calculateHashOfBlock5();
//        calculateHashOfBlock6();
    });
    connect(ui->pushButton_8,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_56->text().at(0)!='0' || ui->label_56->text().at(1)!='0' || ui->label_56->text().at(2)!='0';i++)
        {
            ui->lineEdit_16->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock3();
        }
    });

    //Block-4 Initialization

    ui->lineEdit_17->setText("1");
    ui->label_62->setText("0000000000000000000000000000000000000000000000000000000000000000");
    calculateHashOfBlock4();
    for(int i=0;ui->label_63->text().at(0)!='0' || ui->label_63->text().at(1)!='0' || ui->label_63->text().at(2)!='0';i++)
    {
        ui->lineEdit_18->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock4();
    }

    //Block-4 Connections

    connect(ui->lineEdit_17,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock4();
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_18,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock4();
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->textEdit_9,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock4();
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->pushButton_9,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_63->text().at(0)!='0' || ui->label_63->text().at(1)!='0' || ui->label_63->text().at(2)!='0';i++)
        {
            ui->lineEdit_18->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock4();
        }
    });

    //Block-5 Initialization

    ui->lineEdit_19->setText("2");
    ui->label_69->setText(ui->label_63->text());
    calculateHashOfBlock5();
    for(int i=0;ui->label_70->text().at(0)!='0' || ui->label_70->text().at(1)!='0' || ui->label_70->text().at(2)!='0';i++)
    {
        ui->lineEdit_20->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock5();
    }

    //Block-5 Connections

    connect(ui->lineEdit_19,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_20,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->textEdit_10,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock5();
        calculateHashOfBlock6();
    });
    connect(ui->pushButton_10,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_70->text().at(0)!='0' || ui->label_70->text().at(1)!='0' || ui->label_70->text().at(2)!='0';i++)
        {
            ui->lineEdit_20->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock5();
        }
    });


    //Block-6 Initialization

    ui->lineEdit_21->setText("3");
    ui->label_76->setText(ui->label_70->text());
    calculateHashOfBlock6();
    for(int i=0;ui->label_77->text().at(0)!='0' || ui->label_77->text().at(1)!='0' || ui->label_77->text().at(2)!='0';i++)
    {
        ui->lineEdit_22->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock6();
    }

    //Block-6 Connections

    connect(ui->lineEdit_21,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock6();
    });
    connect(ui->lineEdit_22,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock6();
    });
    connect(ui->textEdit_11,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock6();
    });
    connect(ui->pushButton_11,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_77->text().at(0)!='0' || ui->label_77->text().at(1)!='0' || ui->label_77->text().at(2)!='0';i++)
        {
            ui->lineEdit_22->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock6();
        }
    });

    //Block-7 Initialization

    ui->lineEdit_23->setText("1");
    ui->label_83->setText("0000000000000000000000000000000000000000000000000000000000000000");
    calculateHashOfBlock7();
    for(int i=0;ui->label_84->text().at(0)!='0' || ui->label_84->text().at(1)!='0' || ui->label_84->text().at(2)!='0';i++)
    {
        ui->lineEdit_24->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock7();
    }

    //Block-7 Connections

    connect(ui->lineEdit_23,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock7();
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->lineEdit_24,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock7();
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->textEdit_12,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock7();
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->pushButton_12,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_84->text().at(0)!='0' || ui->label_84->text().at(1)!='0' || ui->label_84->text().at(2)!='0';i++)
        {
            ui->lineEdit_24->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock7();
        }
    });

    //Block-8 Initialization

    ui->lineEdit_25->setText("2");
    ui->label_90->setText(ui->label_84->text());
    calculateHashOfBlock8();
    for(int i=0;ui->label_91->text().at(0)!='0' || ui->label_91->text().at(1)!='0' || ui->label_91->text().at(2)!='0';i++)
    {
        ui->lineEdit_26->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock8();
    }

    //Block-8 Connections

    connect(ui->lineEdit_25,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->lineEdit_26,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->textEdit_13,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock8();
        calculateHashOfBlock9();
    });
    connect(ui->pushButton_13,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_91->text().at(0)!='0' || ui->label_91->text().at(1)!='0' || ui->label_91->text().at(2)!='0';i++)
        {
            ui->lineEdit_26->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock8();
        }
    });

    //Block-9 Initialization

    ui->lineEdit_27->setText("3");
    ui->label_97->setText(ui->label_91->text());
    calculateHashOfBlock9();
    for(int i=0;ui->label_98->text().at(0)!='0' || ui->label_98->text().at(1)!='0' || ui->label_98->text().at(2)!='0';i++)
    {
        ui->lineEdit_28->setText(QString::fromStdString(int_to_string(i)));
        calculateHashOfBlock9();
    }

    //Block-9 Connections

    connect(ui->lineEdit_27,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock9();
    });
    connect(ui->lineEdit_28,&QLineEdit::textChanged,[=](){
        calculateHashOfBlock9();
    });
    connect(ui->textEdit_14,&QTextEdit::textChanged,[=](){
        calculateHashOfBlock9();
    });
    connect(ui->pushButton_14,&QPushButton::pressed,[=](){
        for(int i=0;ui->label_98->text().at(0)!='0' || ui->label_98->text().at(1)!='0' || ui->label_98->text().at(2)!='0';i++)
        {
            ui->lineEdit_28->setText(QString::fromStdString(int_to_string(i)));
            calculateHashOfBlock9();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

