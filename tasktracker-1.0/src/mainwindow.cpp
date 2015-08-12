#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QProcess"
#include "QMessageBox"
#include "QListWidgetItem"


QStringList taskslist;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reload();
    reload_tasks();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Start Fix Checkbox Erorrs
void MainWindow::on_min_every_check_clicked()
{
    if(ui->min_every_check->isChecked() == true){
        ui->min_every_n_check->setChecked(false);
        ui->min_each_selected_check->setChecked(false);
    }
    if(ui->min_every_check->isChecked() == false && ui->min_every_n_check->isChecked() == false && ui->min_each_selected_check->isChecked() == false){
        ui->min_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_min_every_n_check_clicked()
{
    if(ui->min_every_n_check->isChecked() == true){
        ui->min_each_selected_check->setChecked(false);
        ui->min_every_check->setChecked(false);
    }
    if(ui->min_every_check->isChecked() == false && ui->min_every_n_check->isChecked() == false && ui->min_each_selected_check->isChecked() == false){
        ui->min_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_min_each_selected_check_clicked()
{
    if(ui->min_each_selected_check->isChecked() == true){
        ui->min_every_n_check->setChecked(false);
        ui->min_every_check->setChecked(false);
    }
    if(ui->min_every_check->isChecked() == false && ui->min_every_n_check->isChecked() == false && ui->min_each_selected_check->isChecked() == false){
        ui->min_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_hour_every_check_clicked()
{
    if(ui->hour_every_check->isChecked() == true){
        ui->hour_every_n_check->setChecked(false);
        ui->hour_each_selected_check->setChecked(false);
    }
    if(ui->hour_every_check->isChecked() == false && ui->hour_every_n_check->isChecked() == false && ui->hour_each_selected_check->isChecked() == false){
        ui->hour_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_hour_every_n_check_clicked()
{
    if(ui->hour_every_n_check->isChecked() == true){
        ui->hour_each_selected_check->setChecked(false);
        ui->hour_every_check->setChecked(false);
    }
    if(ui->hour_every_check->isChecked() == false && ui->hour_every_n_check->isChecked() == false && ui->hour_each_selected_check->isChecked() == false){
        ui->hour_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_hour_each_selected_check_clicked()
{
    if(ui->hour_each_selected_check->isChecked() == true){
        ui->hour_every_n_check->setChecked(false);
        ui->hour_every_check->setChecked(false);
    }
    if(ui->hour_every_check->isChecked() == false && ui->hour_every_n_check->isChecked() == false && ui->hour_each_selected_check->isChecked() == false){
        ui->hour_every_check->setChecked(true);
    }
    reload();
}
void MainWindow::on_dom_every_check_clicked()
{
    if(ui->dom_every_check->isChecked() == true){
        ui->dom_each_selected_check->setChecked(false);
    }
    if(ui->dom_every_check->isChecked() == false && ui->dom_each_selected_check->isChecked() == false){
        ui->dom_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_dom_each_selected_check_clicked()
{
    if(ui->dom_each_selected_check->isChecked() == true){
        ui->dom_every_check->setChecked(false);
    }
    if(ui->dom_every_check->isChecked() == false && ui->dom_each_selected_check->isChecked() == false){
        ui->dom_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_month_every_check_clicked()
{
    if(ui->month_every_check->isChecked() == true){
        ui->month_each_selected_check->setChecked(false);
    }
    if(ui->month_every_check->isChecked() == false && ui->month_each_selected_check->isChecked() == false){
        ui->month_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_month_each_selected_check_clicked()
{
    if(ui->month_each_selected_check->isChecked() == true){
        ui->month_every_check->setChecked(false);
    }
    if(ui->month_every_check->isChecked() == false && ui->month_each_selected_check->isChecked() == false){
        ui->month_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_dow_every_check_clicked()
{
    if(ui->dow_every_check->isChecked() == true){
        ui->dow_each_selected_check->setChecked(false);
    }
    if(ui->dow_every_check->isChecked() == false && ui->dow_each_selected_check->isChecked() == false){
        ui->dow_every_check->setChecked(true);
    }
    reload();
}

void MainWindow::on_dow_each_selected_check_clicked()
{
    if(ui->dow_each_selected_check->isChecked() == true){
        ui->dow_every_check->setChecked(false);
    }
    if(ui->dow_every_check->isChecked() == false && ui->dow_each_selected_check->isChecked() == false){
        ui->dow_every_check->setChecked(true);
    }
    reload();
}
//End Fix Checkboxs Erorrs

//Start Set sliders value to their labels
void MainWindow::on_hour_n_slider_valueChanged(int value)
{
    ui->hour_n_lbl->setText(QString::number(value));
    reload();
}

void MainWindow::on_min_n_slider_valueChanged(int value)
{
    ui->min_n_lbl->setText(QString::number(value));
    reload();
}
//End set sliders value to their lables

//Start reload items
QString MainWindow::reload_min(){
    if(ui->min_every_check->isChecked() == true){
        return "*";
    }

     if(ui->min_every_n_check->isChecked() == true){
         return "*/" + QString::number(ui->min_n_slider->value());
     }

     if(ui->min_each_selected_check->isChecked() == true){
         QStringList min;
         if(ui->min_btn_each_00->isChecked() == true){min << "00";}
         if(ui->min_btn_each_01->isChecked() == true){min << "01";}
         if(ui->min_btn_each_02->isChecked() == true){min << "02";}
         if(ui->min_btn_each_03->isChecked() == true){min << "03";}
         if(ui->min_btn_each_04->isChecked() == true){min << "04";}
         if(ui->min_btn_each_05->isChecked() == true){min << "05";}
         if(ui->min_btn_each_06->isChecked() == true){min << "06";}
         if(ui->min_btn_each_07->isChecked() == true){min << "07";}
         if(ui->min_btn_each_08->isChecked() == true){min << "08";}
         if(ui->min_btn_each_09->isChecked() == true){min << "09";}
         if(ui->min_btn_each_10->isChecked() == true){min << "10";}
         if(ui->min_btn_each_11->isChecked() == true){min << "11";}
         if(ui->min_btn_each_12->isChecked() == true){min << "12";}
         if(ui->min_btn_each_13->isChecked() == true){min << "13";}
         if(ui->min_btn_each_14->isChecked() == true){min << "14";}
         if(ui->min_btn_each_15->isChecked() == true){min << "15";}
         if(ui->min_btn_each_16->isChecked() == true){min << "16";}
         if(ui->min_btn_each_17->isChecked() == true){min << "17";}
         if(ui->min_btn_each_18->isChecked() == true){min << "18";}
         if(ui->min_btn_each_19->isChecked() == true){min << "19";}
         if(ui->min_btn_each_20->isChecked() == true){min << "20";}
         if(ui->min_btn_each_21->isChecked() == true){min << "21";}
         if(ui->min_btn_each_22->isChecked() == true){min << "22";}
         if(ui->min_btn_each_23->isChecked() == true){min << "23";}
         if(ui->min_btn_each_24->isChecked() == true){min << "24";}
         if(ui->min_btn_each_25->isChecked() == true){min << "25";}
         if(ui->min_btn_each_26->isChecked() == true){min << "26";}
         if(ui->min_btn_each_27->isChecked() == true){min << "27";}
         if(ui->min_btn_each_28->isChecked() == true){min << "28";}
         if(ui->min_btn_each_29->isChecked() == true){min << "29";}
         if(ui->min_btn_each_30->isChecked() == true){min << "30";}
         if(ui->min_btn_each_31->isChecked() == true){min << "31";}
         if(ui->min_btn_each_32->isChecked() == true){min << "32";}
         if(ui->min_btn_each_33->isChecked() == true){min << "33";}
         if(ui->min_btn_each_34->isChecked() == true){min << "34";}
         if(ui->min_btn_each_35->isChecked() == true){min << "35";}
         if(ui->min_btn_each_36->isChecked() == true){min << "36";}
         if(ui->min_btn_each_37->isChecked() == true){min << "37";}
         if(ui->min_btn_each_38->isChecked() == true){min << "38";}
         if(ui->min_btn_each_39->isChecked() == true){min << "39";}
         if(ui->min_btn_each_40->isChecked() == true){min << "40";}
         if(ui->min_btn_each_41->isChecked() == true){min << "41";}
         if(ui->min_btn_each_42->isChecked() == true){min << "42";}
         if(ui->min_btn_each_43->isChecked() == true){min << "43";}
         if(ui->min_btn_each_44->isChecked() == true){min << "44";}
         if(ui->min_btn_each_45->isChecked() == true){min << "45";}
         if(ui->min_btn_each_46->isChecked() == true){min << "46";}
         if(ui->min_btn_each_47->isChecked() == true){min << "47";}
         if(ui->min_btn_each_48->isChecked() == true){min << "48";}
         if(ui->min_btn_each_49->isChecked() == true){min << "49";}
         if(ui->min_btn_each_50->isChecked() == true){min << "50";}
         if(ui->min_btn_each_51->isChecked() == true){min << "51";}
         if(ui->min_btn_each_52->isChecked() == true){min << "52";}
         if(ui->min_btn_each_53->isChecked() == true){min << "53";}
         if(ui->min_btn_each_54->isChecked() == true){min << "54";}
         if(ui->min_btn_each_55->isChecked() == true){min << "55";}
         if(ui->min_btn_each_56->isChecked() == true){min << "56";}
         if(ui->min_btn_each_57->isChecked() == true){min << "57";}
         if(ui->min_btn_each_58->isChecked() == true){min << "58";}
         if(ui->min_btn_each_59->isChecked() == true){min << "59";}

         if(min.join(',').count() == 0){
             return "*";
         }else{
             return min.join(',');
         }
     }

    return "";
}

QString MainWindow::reload_hour(){
    if(ui->hour_every_check->isChecked() == true){
        return "*";
    }

    if(ui->hour_every_n_check->isChecked() == true){
        return "*/" + QString::number(ui->hour_n_slider->value());
    }

    if(ui->hour_each_selected_check->isChecked() == true){
        QStringList hour;
        if(ui->hour_btn_each_00->isChecked() == true){hour << "00";}
        if(ui->hour_btn_each_01->isChecked() == true){hour << "01";}
        if(ui->hour_btn_each_02->isChecked() == true){hour << "02";}
        if(ui->hour_btn_each_03->isChecked() == true){hour << "03";}
        if(ui->hour_btn_each_04->isChecked() == true){hour << "04";}
        if(ui->hour_btn_each_05->isChecked() == true){hour << "05";}
        if(ui->hour_btn_each_06->isChecked() == true){hour << "06";}
        if(ui->hour_btn_each_07->isChecked() == true){hour << "07";}
        if(ui->hour_btn_each_08->isChecked() == true){hour << "08";}
        if(ui->hour_btn_each_09->isChecked() == true){hour << "09";}
        if(ui->hour_btn_each_10->isChecked() == true){hour << "10";}
        if(ui->hour_btn_each_11->isChecked() == true){hour << "11";}
        if(ui->hour_btn_each_12->isChecked() == true){hour << "12";}
        if(ui->hour_btn_each_13->isChecked() == true){hour << "13";}
        if(ui->hour_btn_each_14->isChecked() == true){hour << "14";}
        if(ui->hour_btn_each_15->isChecked() == true){hour << "15";}
        if(ui->hour_btn_each_16->isChecked() == true){hour << "16";}
        if(ui->hour_btn_each_17->isChecked() == true){hour << "17";}
        if(ui->hour_btn_each_18->isChecked() == true){hour << "18";}
        if(ui->hour_btn_each_19->isChecked() == true){hour << "19";}
        if(ui->hour_btn_each_20->isChecked() == true){hour << "20";}
        if(ui->hour_btn_each_21->isChecked() == true){hour << "21";}
        if(ui->hour_btn_each_22->isChecked() == true){hour << "22";}
        if(ui->hour_btn_each_23->isChecked() == true){hour << "23";}

        if(hour.count() == 0){
            return "*";
        }else{
            return hour.join(',');
        }
    }

    return "";
}

QString MainWindow::reload_dom(){
    if(ui->dom_every_check->isChecked() == true){
        return "*";
    }
    if(ui->dom_each_selected_check->isChecked() == true){
        QStringList dom;
        if(ui->dom_btn_each_01->isChecked() == true){dom << "01";}
        if(ui->dom_btn_each_02->isChecked() == true){dom << "02";}
        if(ui->dom_btn_each_03->isChecked() == true){dom << "03";}
        if(ui->dom_btn_each_04->isChecked() == true){dom << "04";}
        if(ui->dom_btn_each_05->isChecked() == true){dom << "05";}
        if(ui->dom_btn_each_06->isChecked() == true){dom << "06";}
        if(ui->dom_btn_each_07->isChecked() == true){dom << "07";}
        if(ui->dom_btn_each_08->isChecked() == true){dom << "08";}
        if(ui->dom_btn_each_09->isChecked() == true){dom << "09";}
        if(ui->dom_btn_each_10->isChecked() == true){dom << "10";}
        if(ui->dom_btn_each_11->isChecked() == true){dom << "11";}
        if(ui->dom_btn_each_12->isChecked() == true){dom << "12";}
        if(ui->dom_btn_each_13->isChecked() == true){dom << "13";}
        if(ui->dom_btn_each_14->isChecked() == true){dom << "14";}
        if(ui->dom_btn_each_15->isChecked() == true){dom << "15";}
        if(ui->dom_btn_each_16->isChecked() == true){dom << "16";}
        if(ui->dom_btn_each_17->isChecked() == true){dom << "17";}
        if(ui->dom_btn_each_18->isChecked() == true){dom << "18";}
        if(ui->dom_btn_each_19->isChecked() == true){dom << "19";}
        if(ui->dom_btn_each_20->isChecked() == true){dom << "20";}
        if(ui->dom_btn_each_21->isChecked() == true){dom << "21";}
        if(ui->dom_btn_each_22->isChecked() == true){dom << "22";}
        if(ui->dom_btn_each_23->isChecked() == true){dom << "23";}
        if(ui->dom_btn_each_24->isChecked() == true){dom << "24";}
        if(ui->dom_btn_each_25->isChecked() == true){dom << "25";}
        if(ui->dom_btn_each_26->isChecked() == true){dom << "26";}
        if(ui->dom_btn_each_27->isChecked() == true){dom << "27";}
        if(ui->dom_btn_each_28->isChecked() == true){dom << "28";}
        if(ui->dom_btn_each_29->isChecked() == true){dom << "29";}
        if(ui->dom_btn_each_30->isChecked() == true){dom << "30";}
        if(ui->dom_btn_each_31->isChecked() == true){dom << "31";}


        if(dom.join(',').count() == 0){
            return "*";
        }else{
            return dom.join(',');
        }
    }
    return "";
}

QString MainWindow::reload_month(){
    if(ui->month_every_check->isChecked() == true){
        return "*";
    }

    if(ui->month_each_selected_check->isChecked() == true){
        QStringList month;
        if(ui->month_btn_each_jan->isChecked() == true){month << "1";}
        if(ui->month_btn_each_feb->isChecked() == true){month << "2";}
        if(ui->month_btn_each_mar->isChecked() == true){month << "3";}
        if(ui->month_btn_each_apr->isChecked() == true){month << "4";}
        if(ui->month_btn_each_may->isChecked() == true){month << "5";}
        if(ui->month_btn_each_jun->isChecked() == true){month << "6";}
        if(ui->month_btn_each_jul->isChecked() == true){month << "7";}
        if(ui->month_btn_each_aug->isChecked() == true){month << "8";}
        if(ui->month_btn_each_sep->isChecked() == true){month << "9";}
        if(ui->month_btn_each_oct->isChecked() == true){month << "10";}
        if(ui->month_btn_each_nov->isChecked() == true){month << "11";}
        if(ui->month_btn_each_dec->isChecked() == true){month << "12";}

        if(month.join(',').count() == 0){
            return "*";
        }else{
            return month.join(',');
        }
    }

    return "";
}

QString MainWindow::reload_dow(){
    if(ui->dow_every_check->isChecked() == true){
        return "*";
    }

    if(ui->dow_each_selected_check->isChecked() == true){
        QStringList dow;
        if(ui->dow_btn_each_sun->isChecked() == true){dow << "0";}
        if(ui->dow_btn_each_mon->isChecked() == true){dow << "1";}
        if(ui->dow_btn_each_tue->isChecked() == true){dow << "2";}
        if(ui->dow_btn_each_wed->isChecked() == true){dow << "3";}
        if(ui->dow_btn_each_thu->isChecked() == true){dow << "4";}
        if(ui->dow_btn_each_fri->isChecked() == true){dow << "5";}
        if(ui->dow_btn_each_sat->isChecked() == true){dow << "6";}

        if(dow.join(',').count() == 0){
            return "*";
        }else{
            return dow.join(',');
        }
    }

    return "";
}

QString MainWindow::reload_all(){
    return reload_min() + " " + reload_hour() + " " + reload_dom() + " " + reload_month() + " " + reload_dow() + " " + ui->te_command->toPlainText();
}

  //Start relaod tasks tab
void MainWindow::reload_tasks(){
    QProcess Process;
    Process.start("sh", QStringList() << "-c" << "crontab -l > ~/.new.cron");
    Process.waitForFinished(-1);

    ui->task_list->clear();
    ui->tasks_command->clear();

    Process.start("crontab", QStringList() << "-l");
    Process.waitForFinished(-1);
    QString stdout = Process.readAllStandardOutput();

    QStringList qlist = stdout.split("\n");

    for (int i = 0; i < qlist.count(); i++){

        QString line = qlist.at(i);
        if(line.left(1) != "#"){
            if(!line.isEmpty()){
                QString command;
                QString desc;
                if(line.contains("#PCE#")){
                    QStringList splited = line.split("#PCE#");
                    command = splited.at(0).right(splited.at(0).length()-splited.at(0).indexOf(splited.at(0).split(" ").at(5)));
                    desc = getBetween(splited.at(1),"<des>","</des>");

                }
                else{
                    command = line.right(line.length()-line.indexOf(line.split(" ").at(5)));
                    desc = "";
                }
                ui->tasks_command->addItem(command);
                if(desc.length() != 0){
                    ui->task_list->addItem(desc);
                }else{
                    ui->task_list->addItem("[No Description Writed]");
                }
                taskslist.append(line);
                on_btn_reset_clicked();
                ui->te_command->clear();
                ui->te_desc->clear();
                ui->te_result->clear();

            }


        }

    }
}
  //End reload tasks tab


//Start reload on click
 void MainWindow::reload(){
     ui->te_result->setText(reload_all());
 }

 //End reload items

 //Start insert
 void MainWindow::on_btn_insert_clicked()
 {
     if(ui->te_command->toPlainText().isEmpty()){
         QMessageBox msgBox;
         msgBox.setText("Please write Command and Description.");
         msgBox.setStandardButtons(QMessageBox::Ok);
         msgBox.setDefaultButton(QMessageBox::Ok);
         msgBox.exec();
         return;
     }
     reload_tasks();
     QProcess Process;
     Process.start("sh", QStringList() << "-c" << "echo '" + ui->te_result->toPlainText().trimmed() + " #PCE#<des>" + ui->te_desc->toPlainText() + "</des>" "' >> ~/.new.cron" );
     Process.waitForFinished(-1);
     Process.start("sh", QStringList() << "-c" << "crontab ~/.new.cron");
     Process.waitForFinished(-1);
     reload_tasks();
 }
 //End insert


void MainWindow::on_min_btn_each_00_clicked()
{
    reload();
}
void MainWindow::on_min_btn_each_01_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_02_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_03_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_04_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_05_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_06_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_07_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_08_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_09_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_10_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_11_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_12_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_13_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_14_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_15_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_16_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_17_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_18_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_19_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_20_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_21_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_22_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_23_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_24_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_25_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_26_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_27_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_28_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_29_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_30_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_31_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_32_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_33_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_34_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_35_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_36_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_37_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_38_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_39_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_40_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_41_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_42_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_43_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_44_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_45_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_46_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_47_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_48_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_49_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_50_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_51_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_52_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_53_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_54_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_55_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_56_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_57_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_58_clicked()
{
    reload();
}

void MainWindow::on_min_btn_each_59_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_00_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_01_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_02_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_03_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_04_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_05_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_06_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_07_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_08_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_09_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_10_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_11_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_12_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_13_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_14_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_15_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_16_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_17_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_18_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_19_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_20_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_21_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_22_clicked()
{
    reload();
}

void MainWindow::on_hour_btn_each_23_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_01_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_02_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_03_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_04_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_05_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_06_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_07_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_08_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_09_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_10_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_11_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_12_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_13_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_14_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_15_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_16_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_17_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_18_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_19_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_20_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_21_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_22_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_23_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_24_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_25_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_26_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_27_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_28_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_29_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_30_clicked()
{
    reload();
}

void MainWindow::on_dom_btn_each_31_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_jan_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_feb_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_mar_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_apr_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_may_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_jun_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_jul_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_aug_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_sep_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_oct_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_nov_clicked()
{
    reload();
}

void MainWindow::on_month_btn_each_dec_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_sun_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_mon_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_tue_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_wed_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_thu_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_fri_clicked()
{
    reload();
}

void MainWindow::on_dow_btn_each_sat_clicked()
{
    reload();
}

void MainWindow::on_te_command_textChanged()
{
    reload();
}

void MainWindow::on_btn_reload_List_clicked()
{
    reload_tasks();
}

//End reload on click

QString MainWindow::getBetween(QString str, QString open, QString close) {
    int startIndex = str.indexOf(open)+open.length();
    if(startIndex <= 0)return QString();
    int endIndex = str.indexOf(close,startIndex);
    if(endIndex <= 0)return QString();
    return str.mid(startIndex,endIndex - startIndex);
}



void MainWindow::on_btn_remove_all_clicked()
{
    QProcess Process;
    Process.start("sh", QStringList() << "-c" << "echo '' > ~/.new.cron");
    Process.waitForFinished(-1);
    Process.start("sh", QStringList() << "-c" << "crontab ~/.new.cron");
    Process.waitForFinished(-1);
    reload_tasks();
}

void MainWindow::on_btn_reset_clicked()
{
    ui->min_every_check->setChecked(true);
    ui->hour_every_check->setChecked(true);
    ui->dom_every_check->setChecked(true);
    ui->month_every_check->setChecked(true);
    ui->dow_every_check->setChecked(true);

    ui->min_n_slider->setValue(1);
    ui->hour_n_slider->setValue(1);

    ui->min_every_n_check->setChecked(false);
    ui->hour_every_n_check->setChecked(false);

    ui->min_each_selected_check->setChecked(false);
    ui->hour_each_selected_check->setChecked(false);
    ui->dom_each_selected_check->setChecked(false);
    ui->month_each_selected_check->setChecked(false);
    ui->dow_each_selected_check->setChecked(false);

    ui->min_btn_each_00->setChecked(false);
    ui->min_btn_each_01->setChecked(false);
    ui->min_btn_each_02->setChecked(false);
    ui->min_btn_each_03->setChecked(false);
    ui->min_btn_each_04->setChecked(false);
    ui->min_btn_each_05->setChecked(false);
    ui->min_btn_each_06->setChecked(false);
    ui->min_btn_each_07->setChecked(false);
    ui->min_btn_each_08->setChecked(false);
    ui->min_btn_each_09->setChecked(false);
    ui->min_btn_each_10->setChecked(false);
    ui->min_btn_each_11->setChecked(false);
    ui->min_btn_each_12->setChecked(false);
    ui->min_btn_each_13->setChecked(false);
    ui->min_btn_each_14->setChecked(false);
    ui->min_btn_each_15->setChecked(false);
    ui->min_btn_each_16->setChecked(false);
    ui->min_btn_each_17->setChecked(false);
    ui->min_btn_each_18->setChecked(false);
    ui->min_btn_each_19->setChecked(false);
    ui->min_btn_each_20->setChecked(false);
    ui->min_btn_each_21->setChecked(false);
    ui->min_btn_each_22->setChecked(false);
    ui->min_btn_each_23->setChecked(false);
    ui->min_btn_each_24->setChecked(false);
    ui->min_btn_each_25->setChecked(false);
    ui->min_btn_each_26->setChecked(false);
    ui->min_btn_each_27->setChecked(false);
    ui->min_btn_each_28->setChecked(false);
    ui->min_btn_each_29->setChecked(false);
    ui->min_btn_each_30->setChecked(false);
    ui->min_btn_each_31->setChecked(false);
    ui->min_btn_each_32->setChecked(false);
    ui->min_btn_each_33->setChecked(false);
    ui->min_btn_each_34->setChecked(false);
    ui->min_btn_each_35->setChecked(false);
    ui->min_btn_each_36->setChecked(false);
    ui->min_btn_each_37->setChecked(false);
    ui->min_btn_each_38->setChecked(false);
    ui->min_btn_each_39->setChecked(false);
    ui->min_btn_each_40->setChecked(false);
    ui->min_btn_each_41->setChecked(false);
    ui->min_btn_each_42->setChecked(false);
    ui->min_btn_each_43->setChecked(false);
    ui->min_btn_each_44->setChecked(false);
    ui->min_btn_each_45->setChecked(false);
    ui->min_btn_each_46->setChecked(false);
    ui->min_btn_each_47->setChecked(false);
    ui->min_btn_each_48->setChecked(false);
    ui->min_btn_each_49->setChecked(false);
    ui->min_btn_each_50->setChecked(false);
    ui->min_btn_each_51->setChecked(false);
    ui->min_btn_each_52->setChecked(false);
    ui->min_btn_each_53->setChecked(false);
    ui->min_btn_each_54->setChecked(false);
    ui->min_btn_each_55->setChecked(false);
    ui->min_btn_each_56->setChecked(false);
    ui->min_btn_each_57->setChecked(false);
    ui->min_btn_each_58->setChecked(false);
    ui->min_btn_each_59->setChecked(false);

    ui->hour_btn_each_00->setChecked(false);
    ui->hour_btn_each_01->setChecked(false);
    ui->hour_btn_each_02->setChecked(false);
    ui->hour_btn_each_03->setChecked(false);
    ui->hour_btn_each_04->setChecked(false);
    ui->hour_btn_each_05->setChecked(false);
    ui->hour_btn_each_06->setChecked(false);
    ui->hour_btn_each_07->setChecked(false);
    ui->hour_btn_each_08->setChecked(false);
    ui->hour_btn_each_09->setChecked(false);
    ui->hour_btn_each_10->setChecked(false);
    ui->hour_btn_each_11->setChecked(false);
    ui->hour_btn_each_12->setChecked(false);
    ui->hour_btn_each_13->setChecked(false);
    ui->hour_btn_each_14->setChecked(false);
    ui->hour_btn_each_15->setChecked(false);
    ui->hour_btn_each_16->setChecked(false);
    ui->hour_btn_each_17->setChecked(false);
    ui->hour_btn_each_18->setChecked(false);
    ui->hour_btn_each_19->setChecked(false);
    ui->hour_btn_each_20->setChecked(false);
    ui->hour_btn_each_21->setChecked(false);
    ui->hour_btn_each_22->setChecked(false);
    ui->hour_btn_each_23->setChecked(false);

    ui->dom_btn_each_01->setChecked(false);
    ui->dom_btn_each_02->setChecked(false);
    ui->dom_btn_each_03->setChecked(false);
    ui->dom_btn_each_04->setChecked(false);
    ui->dom_btn_each_05->setChecked(false);
    ui->dom_btn_each_06->setChecked(false);
    ui->dom_btn_each_07->setChecked(false);
    ui->dom_btn_each_08->setChecked(false);
    ui->dom_btn_each_09->setChecked(false);
    ui->dom_btn_each_10->setChecked(false);
    ui->dom_btn_each_11->setChecked(false);
    ui->dom_btn_each_12->setChecked(false);
    ui->dom_btn_each_13->setChecked(false);
    ui->dom_btn_each_14->setChecked(false);
    ui->dom_btn_each_15->setChecked(false);
    ui->dom_btn_each_16->setChecked(false);
    ui->dom_btn_each_17->setChecked(false);
    ui->dom_btn_each_18->setChecked(false);
    ui->dom_btn_each_19->setChecked(false);
    ui->dom_btn_each_20->setChecked(false);
    ui->dom_btn_each_21->setChecked(false);
    ui->dom_btn_each_22->setChecked(false);
    ui->dom_btn_each_23->setChecked(false);
    ui->dom_btn_each_24->setChecked(false);
    ui->dom_btn_each_25->setChecked(false);
    ui->dom_btn_each_26->setChecked(false);
    ui->dom_btn_each_27->setChecked(false);
    ui->dom_btn_each_28->setChecked(false);
    ui->dom_btn_each_29->setChecked(false);
    ui->dom_btn_each_30->setChecked(false);
    ui->dom_btn_each_31->setChecked(false);

    ui->month_btn_each_jan->setChecked(false);
    ui->month_btn_each_feb->setChecked(false);
    ui->month_btn_each_mar->setChecked(false);
    ui->month_btn_each_apr->setChecked(false);
    ui->month_btn_each_may->setChecked(false);
    ui->month_btn_each_jun->setChecked(false);
    ui->month_btn_each_jul->setChecked(false);
    ui->month_btn_each_aug->setChecked(false);
    ui->month_btn_each_sep->setChecked(false);
    ui->month_btn_each_oct->setChecked(false);
    ui->month_btn_each_nov->setChecked(false);
    ui->month_btn_each_dec->setChecked(false);

    ui->dow_btn_each_sun->setChecked(false);
    ui->dow_btn_each_mon->setChecked(false);
    ui->dow_btn_each_tue->setChecked(false);
    ui->dow_btn_each_wed->setChecked(false);
    ui->dow_btn_each_thu->setChecked(false);
    ui->dow_btn_each_fri->setChecked(false);
    ui->dow_btn_each_sat->setChecked(false);

    reload();
}

void MainWindow::on_tabWidget_tabBarClicked()
{
    reload_tasks();
}

void MainWindow::on_btn_remove_clicked()
{
    if(ui->task_list->currentRow() != -1){
    char *uh = getenv("HOME");
    QString userHome(QString::fromStdString(uh));
    QString filename=userHome + "/.new.cron";
    QFile file( filename );
    if ( file.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &file );
        if(ui->task_list != 0){
            for(int i = 0;i < ui->task_list->count();i++)
            {
                if(taskslist.at(i) != taskslist.at(ui->task_list->currentRow())){
                    stream << taskslist.at(i) + "\n";
                }
            }
        }
    }
    file.close();
    QProcess Process;
    Process.start("sh", QStringList() << "-c" << "crontab ~/.new.cron");
    Process.waitForFinished(-1);
    reload_tasks();
    }
}
