#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListWidgetItem"

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
    void on_min_every_check_clicked();

    void on_min_every_n_check_clicked();

    void on_min_each_selected_check_clicked();

    void on_hour_every_check_clicked();

    void on_hour_every_n_check_clicked();

    void on_hour_each_selected_check_clicked();

    void on_dom_every_check_clicked();

    void on_dom_each_selected_check_clicked();

    void on_month_every_check_clicked();

    void on_month_each_selected_check_clicked();

    void on_dow_every_check_clicked();

    void on_dow_each_selected_check_clicked();

    void on_hour_n_slider_valueChanged(int value);

    void on_min_n_slider_valueChanged(int value);

    QString reload_min();

    QString reload_hour();

    QString reload_dom();

    QString reload_month();

    QString reload_dow();

    QString reload_all();

    void reload();

    void on_btn_insert_clicked();

    void on_min_btn_each_01_clicked();

    void on_min_btn_each_00_clicked();

    void on_min_btn_each_02_clicked();

    void on_min_btn_each_03_clicked();

    void on_min_btn_each_04_clicked();

    void on_min_btn_each_05_clicked();

    void on_min_btn_each_06_clicked();

    void on_min_btn_each_07_clicked();

    void on_min_btn_each_08_clicked();

    void on_min_btn_each_09_clicked();

    void on_min_btn_each_10_clicked();

    void on_min_btn_each_11_clicked();

    void on_min_btn_each_12_clicked();

    void on_min_btn_each_13_clicked();

    void on_min_btn_each_14_clicked();

    void on_min_btn_each_15_clicked();

    void on_min_btn_each_16_clicked();

    void on_min_btn_each_17_clicked();

    void on_min_btn_each_18_clicked();

    void on_min_btn_each_19_clicked();

    void on_min_btn_each_20_clicked();

    void on_min_btn_each_21_clicked();

    void on_min_btn_each_22_clicked();

    void on_min_btn_each_23_clicked();

    void on_min_btn_each_24_clicked();

    void on_min_btn_each_25_clicked();

    void on_min_btn_each_26_clicked();

    void on_min_btn_each_27_clicked();

    void on_min_btn_each_28_clicked();

    void on_min_btn_each_29_clicked();

    void on_min_btn_each_30_clicked();

    void on_min_btn_each_31_clicked();

    void on_min_btn_each_32_clicked();

    void on_min_btn_each_33_clicked();

    void on_min_btn_each_34_clicked();

    void on_min_btn_each_35_clicked();

    void on_min_btn_each_36_clicked();

    void on_min_btn_each_37_clicked();

    void on_min_btn_each_38_clicked();

    void on_min_btn_each_39_clicked();

    void on_min_btn_each_40_clicked();

    void on_min_btn_each_41_clicked();

    void on_min_btn_each_42_clicked();

    void on_min_btn_each_43_clicked();

    void on_min_btn_each_44_clicked();

    void on_min_btn_each_45_clicked();

    void on_min_btn_each_46_clicked();

    void on_min_btn_each_47_clicked();

    void on_min_btn_each_48_clicked();

    void on_min_btn_each_49_clicked();

    void on_min_btn_each_50_clicked();

    void on_min_btn_each_51_clicked();

    void on_min_btn_each_52_clicked();

    void on_min_btn_each_53_clicked();

    void on_min_btn_each_54_clicked();

    void on_min_btn_each_55_clicked();

    void on_min_btn_each_56_clicked();

    void on_min_btn_each_57_clicked();

    void on_min_btn_each_58_clicked();

    void on_min_btn_each_59_clicked();

    void on_hour_btn_each_00_clicked();

    void on_hour_btn_each_01_clicked();

    void on_hour_btn_each_02_clicked();

    void on_hour_btn_each_03_clicked();

    void on_hour_btn_each_04_clicked();

    void on_hour_btn_each_05_clicked();

    void on_hour_btn_each_06_clicked();

    void on_hour_btn_each_07_clicked();

    void on_hour_btn_each_08_clicked();

    void on_hour_btn_each_09_clicked();

    void on_hour_btn_each_10_clicked();

    void on_hour_btn_each_11_clicked();

    void on_hour_btn_each_12_clicked();

    void on_hour_btn_each_13_clicked();

    void on_hour_btn_each_14_clicked();

    void on_hour_btn_each_15_clicked();

    void on_hour_btn_each_16_clicked();

    void on_hour_btn_each_17_clicked();

    void on_hour_btn_each_18_clicked();

    void on_hour_btn_each_19_clicked();

    void on_hour_btn_each_20_clicked();

    void on_hour_btn_each_21_clicked();

    void on_hour_btn_each_22_clicked();

    void on_hour_btn_each_23_clicked();

    void on_dom_btn_each_01_clicked();

    void on_dom_btn_each_02_clicked();

    void on_dom_btn_each_03_clicked();

    void on_dom_btn_each_04_clicked();

    void on_dom_btn_each_05_clicked();

    void on_dom_btn_each_06_clicked();

    void on_dom_btn_each_07_clicked();

    void on_dom_btn_each_08_clicked();

    void on_dom_btn_each_09_clicked();

    void on_dom_btn_each_10_clicked();

    void on_dom_btn_each_11_clicked();

    void on_dom_btn_each_12_clicked();

    void on_dom_btn_each_13_clicked();

    void on_dom_btn_each_14_clicked();

    void on_dom_btn_each_15_clicked();

    void on_dom_btn_each_16_clicked();

    void on_dom_btn_each_17_clicked();

    void on_dom_btn_each_18_clicked();

    void on_dom_btn_each_19_clicked();

    void on_dom_btn_each_20_clicked();

    void on_dom_btn_each_21_clicked();

    void on_dom_btn_each_22_clicked();

    void on_dom_btn_each_23_clicked();

    void on_dom_btn_each_24_clicked();

    void on_dom_btn_each_25_clicked();

    void on_dom_btn_each_26_clicked();

    void on_dom_btn_each_27_clicked();

    void on_dom_btn_each_28_clicked();

    void on_dom_btn_each_29_clicked();

    void on_dom_btn_each_30_clicked();

    void on_dom_btn_each_31_clicked();

    void on_month_btn_each_jan_clicked();

    void on_month_btn_each_feb_clicked();

    void on_month_btn_each_mar_clicked();

    void on_month_btn_each_apr_clicked();

    void on_month_btn_each_may_clicked();

    void on_month_btn_each_jun_clicked();

    void on_month_btn_each_jul_clicked();

    void on_month_btn_each_aug_clicked();

    void on_month_btn_each_sep_clicked();

    void on_month_btn_each_oct_clicked();

    void on_month_btn_each_nov_clicked();

    void on_month_btn_each_dec_clicked();

    void on_dow_btn_each_sun_clicked();

    void on_dow_btn_each_mon_clicked();

    void on_dow_btn_each_tue_clicked();

    void on_dow_btn_each_wed_clicked();

    void on_dow_btn_each_thu_clicked();

    void on_dow_btn_each_fri_clicked();

    void on_dow_btn_each_sat_clicked();

    void on_te_command_textChanged();

    void reload_tasks();

    QString getBetween(QString, QString, QString);

    void on_btn_reload_List_clicked();

    void on_btn_remove_all_clicked();

    void on_btn_reset_clicked();

    void on_tabWidget_tabBarClicked();

    void on_btn_remove_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
