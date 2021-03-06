#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "video_capture_thread.h"
#include "audio_capture_thread.h"
#include "audio_playback_thread.h"


#include "movie_encoder_thread.h"

#include "gpio_event_detector_thread.h"
#include "menu_dialog.h"
#include "program_state.h"
#include "bell_thread.h"

//#define BELL_PIN 0 //dummy correct this.
#define BELL_PIN 4 //dummy correct this.


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


    void on_record_or_stop_btn_clicked();

    void on_menu_btn_clicked();

    void ring_bell_slot();

    void on_talk_btn_pressed();

    void on_talk_btn_released();

    void on_hear_btn_pressed();

    void on_hear_btn_released();

private:
    Ui::MainWindow *ui;

    safe_encode_video_context my_safe_encode_video_context;
    safe_encode_audio_context my_safe_encode_audio_context;

    gpio_event_detector_thread  *my_gpio_event_detector_thread;
    bell_thread          *my_bell_thread;
    movie_encoder_thread *my_movie_encoder_thread;
    video_capture_thread *my_video_capture_thread;
    audio_capture_thread *my_audio_capture_thread;
    audio_playback_thread my_audio_playback_thread;

   // PxP my_pxp;
    program_state my_program_state;
    bool record_or_stop_btn_state;
};

#endif // MAINWINDOW_H
