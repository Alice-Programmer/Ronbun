平均出力メーカーソースコード
#include <iostream>//標準入出力用ヘッダファイル<iostream>をinclude

int main(void) {// 「main」という関数の中で実行します
    //複数の変数を定義
    int change_number;
    double sum = 0;
    int i; // ループカウンタ用変数
    int n; // 演算子に入れる用に。
    double num1; // ユーザーに入力させる
    int* numbers ; // NEW演算子用ポインタ
    double average;
    int end;
    std::cout << "平均を出力します" << std::endl;//「平均を出力します」を画面に出力。「endl」は改行の意
    std::cout << "計算したい数値の個数を入力してください: " << std::endl;
    std::cout << "例えば、10個の数値から平均を求めたい場合は　10　と入力してください" << std::endl;
    std::cin >> n;//上の「n」という変数にキーボードからの数値を入力

    std::system("cls");//cmd上の文字をリフレッシュ
    numbers = new int[n + 1]; // 数値分のメモリの動的確保

    for (i = 0; i < n; i++)
    {
        std::cout << i + 1 << "個目の数値を入力してください. " << std::endl;
        std::cin >> num1;
        std::system("cls");
        numbers[i] == num1;
        num1 = 0; // num1をまた使えるように初期化
    }



    for (i = 0; i < n; i++)//今まで打った数値を出力　前に触れたプログラムの三要素「反復」を行います
    {  //()の中身は「i=0」として定義し、「i<n」の大小関係である限り{}の中身を実行し、処理後iに1を加える
        i++;
        std::cout << i << "番目の数値";
        i--;
        std::cout << numbers[i] << std::endl;
    }



    std::cout << "入力した数値に間違いはありませんか？" << std::endl;
    std::cout << "入力した数値に間違いがなければ0を、間違いがあれば" << std::endl;
    std::cout << "何番目の数値を間違えたかを入力してください" << std::endl;
    std::cout << "例：1番目の数値を間違えた場合　1　と入力";
    std::cin >> change_number;

    for (change_number = change_number; change_number != 0;)//数値打ち直し
    {

        if (change_number > n)
        {
            std::system("cls");
            std::cout << change_number << "番目の数値は存在しません";
        }
        else
        {
            std::system("cls");
            std::cout << "正しい" << change_number << "番目の正しい数値を入力してください" << std::endl;
            std::cin >> numbers[change_number - 1];
            std::cout << "この数値でよろしいですか？" << std::endl;
            std::cout << "変更した" << change_number << "番目の数値:" << numbers[change_number - 1];
            std::cout << "正しければ0を、正しくなければ、この数値が何番目かを入力してください" << std::endl;
            std::cout << "例:1番目の場合:1と入力" << std::endl;
            std::cin >> change_number;
        }
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + numbers[i];
    }
    average = sum / n; // 平均値を計算する式

    if (change_number == 0)
    {
        std::cout << "平均値: " << average << std::endl;//平均値を出力

        std::cout << "終了するには何か入力してください" << std::endl;
        std::cin >> end;
    }

    // メモリの解放
    delete[] numbers;

    return 0;//0をvoidに渡してプログラム終了
}