#include <iostream>
#include <chrono>
#include <thread>

void showProgress(int progress) {
    const int barWidth = 50;

    // 進捗バーを更新するために前の進捗バーを消去する
    std::cout << "\r[";

    int pos = barWidth * progress / 100;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << "|";
        else
            std::cout << " ";
    }

    std::cout << "] " << progress << "%" << std::flush; // flushを使って出力を即座に行う

    // インジケータの表示速度を遅くするために適当な時間待機を行う
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main() {
    // プログラムの進行状況（仮の値）
    for (int i = 0; i <= 100; ++i) {
        showProgress(i);
    }
    return 0;
}

