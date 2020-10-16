#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Check_Button.H>

extern "C" {
#include "crypto.h"
}

struct run_data {
    Fl_Input* input;
    Fl_Output* output;
    Fl_Check_Button* check_button;
    Fl_Int_Input* s1;
    Fl_Int_Input* s2;
    Fl_Int_Input* s3;
    Fl_Int_Input* s4;
    Fl_Int_Input* s5;
    Fl_Int_Input* s6;
    Fl_Int_Input* s7;
    Fl_Int_Input* s8;
    Fl_Int_Input* s9;
    Fl_Int_Input* s10;
    Fl_Int_Input* s11;
    Fl_Int_Input* s12;
    Fl_Int_Input* s13;
    Fl_Int_Input* s14;
    Fl_Int_Input* s15;
    Fl_Int_Input* s16;
};

void run(Fl_Widget*, void* dat) {
    auto* run_data = reinterpret_cast<struct run_data *>(dat);
    char const* input = run_data->input->value();
    size_t square[16];
    square[0] = std::atoi(run_data->s1->value());
    square[1] = std::atoi(run_data->s2->value());
    square[2] = std::atoi(run_data->s3->value());
    square[3] = std::atoi(run_data->s4->value());
    square[4] = std::atoi(run_data->s5->value());
    square[5] = std::atoi(run_data->s6->value());
    square[6] = std::atoi(run_data->s7->value());
    square[7] = std::atoi(run_data->s8->value());
    square[8] = std::atoi(run_data->s9->value());
    square[9] = std::atoi(run_data->s10->value());
    square[10] = std::atoi(run_data->s11->value());
    square[11] = std::atoi(run_data->s12->value());
    square[12] = std::atoi(run_data->s13->value());
    square[13] = std::atoi(run_data->s14->value());
    square[14] = std::atoi(run_data->s15->value());
    square[15] = std::atoi(run_data->s16->value());
    if (run_data->check_button->value() == 0) {
        char *encrypted = magic_square_encrypt(input, 16, square);
        if (encrypted == nullptr) {
            return;
        }
        run_data->output->value(encrypted);
        free(encrypted);
    } else {
        char* decrypted = magic_square_decrypt(input, 16, square);
        if (decrypted == nullptr) {
            return;
        }
        run_data->output->value(decrypted);
        free(decrypted);
    }
}

int main(int argc, char *argv[]) {
    auto* w = new Fl_Window(800, 300, "Magic square GUI");
    run_data run_data{
            new Fl_Input(80, 10, 660, 40, "Ввод:"),
            new Fl_Output(80, 70, 660, 40, "Вывод:"),
            new Fl_Check_Button(20, 120, 160, 20, "Расшифровать"),
            new Fl_Int_Input(240, 120, 40, 40),
            new Fl_Int_Input(280, 120, 40, 40),
            new Fl_Int_Input(320, 120, 40, 40),
            new Fl_Int_Input(360, 120, 40, 40),
            new Fl_Int_Input(240, 160, 40, 40),
            new Fl_Int_Input(280, 160, 40, 40),
            new Fl_Int_Input(320, 160, 40, 40),
            new Fl_Int_Input(360, 160, 40, 40),
            new Fl_Int_Input(240, 200, 40, 40),
            new Fl_Int_Input(280, 200, 40, 40),
            new Fl_Int_Input(320, 200, 40, 40),
            new Fl_Int_Input(360, 200, 40, 40),
            new Fl_Int_Input(240, 240, 40, 40),
            new Fl_Int_Input(280, 240, 40, 40),
            new Fl_Int_Input(320, 240, 40, 40),
            new Fl_Int_Input(360, 240, 40, 40),
    };
    auto* run_button = new Fl_Button(680, 250, 100, 30, "Запустить");
    run_button->callback(run, &run_data);
    w->end();
    w->show(argc, argv);
    return Fl::run();
}
