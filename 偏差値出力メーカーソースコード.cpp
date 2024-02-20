偏差値出力メーカーソースコード
#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    int change_number;
    double bunsan;
    double average_Nonizyou;
    double* hensati;//偏差値
    double hyouzyun_hensa;//偏差
    double nizyouonogoukei=0;//数値の二乗初期化しないとエラーになるので初期化。
    double nizyou_average;//二乗の平均
    double sum = 0;
    int i; // ループカウンタ用変数
    int n; // 演算子に入れる用に。
    double num1; // ユーザーに入力させる
    int* numbers; // NEW演算子用ポインタ
    double average;
    int end;
    cout << "偏差値を出力します" << endl;
    cout << "計算したい数値の個数を入力してください: " << endl;
    cout << "例えば、10個の数値から平均を求めたい場合は　10　と入力してください" << endl;
    cin >> n;

    system("cls");
    numbers = new int[n + 1]; // 数値分のメモリの動的確保
    hensati = new double[n + 1];//偏差値を確保

    for (i = 0; i < n; i++)
    {
        cout << i + 1 << "個目の数値を入力してください. " << endl;
        cin >> num1;
        system("cls");
        numbers[i] = num1;
        num1 = 0; // num1をまた使えるように初期化
    }



    for (i = 0; i < n; i++)//今まで打った数値を出力
    {
        i++;
        cout << i << "番目の数値";
        i--;
        cout << numbers[i] << endl;
    }



    cout << "入力した数値に間違いはありませんか？" <<endl;
    cout << "入力した数値に間違いがなければ0を、間違いがあれば"<< endl;
    cout << "何番目の数値を間違えたかを入力してください" << endl;
    cout << "例：1番目の数値を間違えた場合　1　と入力";
    cin >> change_number;

    for (change_number = change_number; change_number != 0;)//数値打ち直し
    {

        if (change_number > n)
        {
            system("cls");
            cout << change_number << "番目の数値は存在しません";
        }
        else
        {
            system("cls");
            cout << "正しい" << change_number << "番目の正しい数値を入力してください" << endl;
            cin >> numbers[change_number - 1];
            cout << "この数値でよろしいですか？" <<endl;
            cout << "変更した" << change_number << "番目の数値:" << numbers[change_number - 1];
            cout << "正しければ0を、正しくなければ、この数値が何番目かを入力してください" << endl;
            cout << "例:1番目の場合:1と入力" << endl;
            cin>> change_number;
        }
        if (change_number > n)//存在しない数値を変更しようとした場合の打ち直しpart2
        {
            for (i = 0; i < n; i++)//今まで打った数値を出力
            {
                i++;
                cout << i << "番目の数値";
                i--;
                cout << numbers[i] << endl;
            }



            cout << "入力した数値に間違いはありませんか？" << endl;
            cout << "入力した数値に間違いがなければ0を、間違いがあれば" << endl;
            cout << "何番目の数値を間違えたかを入力してください" << endl;
            cout << "例：1番目の数値を間違えた場合　1　と入力";
            cin >> change_number;
        }
    }

    system("cls");

    for (i = 0; i < n; i++)
    {
        sum = sum + numbers[i];
    }
    average = sum / n; // 平均値を計算する
    average_Nonizyou=pow(average, 2);//平均の二乗

    for (i = 0; i < n; i++)//二乗の和を計算する
    {
        nizyouonogoukei = nizyouonogoukei + pow(numbers[i], 2);
    }
    nizyou_average = nizyouonogoukei / n;
    bunsan = nizyou_average - average_Nonizyou;//分散の計算

    hyouzyun_hensa = sqrt(bunsan);//標準偏差

    for (i = 0; i < n; i++)//今まで打った数値を出力
    {
        i++;
       cout << i << "番目の数値";
        i--;
       cout << numbers[i] << std::endl;
    }


    for (i = 0; i < n; i++)
    {
        hensati[i] = (numbers[i] - average) / hyouzyun_hensa * 10 + 50;
        cout << numbers[i] << "の偏差値は" << hensati[i] << "です" << endl;
    }

   

    cout << "終了するには何か入力してください" << endl;
    cin >> end;

    // メモリの解放
    delete[] numbers;
    delete[] hensati;
    return 0;
}