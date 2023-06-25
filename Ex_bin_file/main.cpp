#include <fstream>
#include <iomanip>

int main() {
    const int model_capacity = 20;  // максимальный размер строки

    struct Device {
        char model[model_capacity];  // модель
        double price;  // цена
        int quantity;  // количество
    };

    int n_devices = 2;
    Device *devices = new Device[n_devices]{
            {"MacBook Pro", 100500.0, 256 + 2},
            {"iMac",        100500.0, 256 + 2}
    };

    const int precision = 2;       // знаков после запятой в поле цены
    const int model_width = 19;    // ширина поля модели в текстовом файле
    const int price_width = 9;     // ширина поля цены в текстовом файле
    const int quantity_width = 4;  // ширина поля количества в текстовом файле

    const int buffer_capacity = 80;  // максимальный размер буфера
    char buffer[buffer_capacity];    // вспомогательный буфер

    // Пример 0.1. Вывод массива структур в текстовый файл
    std::fstream file_txt;
    file_txt.open("devices.txt", std::ios::out);
    file_txt << n_devices << std::endl;
    file_txt.setf(std::ios::left | std::ios::fixed);
    file_txt.precision(precision);
    for (int i = 0; i < n_devices; ++i) {
        file_txt << std::setw(model_width) << devices[i].model << ' ' <<
                 std::setw(price_width) << devices[i].price << ' ' <<
                 std::setw(quantity_width) << devices[i].quantity << std::endl;
    }
    file_txt.close();
    delete[] devices;

    // Пример 0.2. Ввод массива структур из текстового файла
    file_txt.open("devices.txt", std::ios::in);
    file_txt >> n_devices;
    file_txt.getline(buffer, buffer_capacity);  // NB
    devices = new Device[n_devices]{};
    for (int i = 0; i < n_devices; ++i) {
        file_txt.get(devices[i].model, model_capacity);  // NB
        file_txt >> devices[i].price >> devices[i].quantity;
        file_txt.getline(buffer, buffer_capacity);  // NB
    }
    file_txt.close();

    // Пример 1.1. Вывод массива структур в бинарный файл
    std::fstream file_bin;
    file_bin.open("devices.bin", std::ios::out | std::ios::binary);
    file_bin.write((char*) &n_devices, sizeof(n_devices));        // записать набор байтов
    file_bin.write((char*) devices, n_devices * sizeof(Device));  // записать набор байтов
    file_bin.close();
    delete[] devices;

    // Пример 1.2. Ввод массива структур из бинарного файла
    file_bin.open("devices.bin", std::ios::in | std::ios::binary);
    file_bin.read((char*) &n_devices, sizeof(n_devices));        // считать набор байтов
    devices = new Device[n_devices]{};
    file_bin.read((char*) devices, n_devices * sizeof(Device));  // считать набор байтов
    file_bin.close();

    delete[] devices;
    return 0;
}