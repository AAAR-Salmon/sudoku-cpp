# sudoku.cpp

入力を受け取ってナンプレを解くプログラム

# 特徴

解が一意に定まらない場合も全ての解を出力します

# 使い方

```
# このリポジトリをクローンします
$ git clone https://github.com/AAAR-Salmon/sudoku-cpp.git
$ cd sudoku-cpp

# Makefileでコンパイルします
$ make
# makeが入っていない場合はGCCを直接叩きます
# g++ sudoku.cpp --std=c++17 -O2 -Wall -Wextra

# とりあえずサンプルを実行してみます
# 実行ファイル名は適宜変えてください(Windowsなら`a.exe`など)
$ ./a.out samples/sample.txt
000007094
000000500
080053100
700400000
005010400
000005006
001940020
004000000
530600000

---------
253167894
167894532
489253167
716489253
325716489
948325716
671948325
894532671
532671948

total sudoku count: 1

# 引数を指定するとファイルからの読み込みになります
# 指定しなかった場合は標準入力からの読み込みも可能です
```

# ToDo

- オプション引数
  - --output
  - --dry-run
  - --only-one
- ナンプレの生成
- エディタによる入力
  - Gitみたいな感じでVimから入力できるようにしたい

# 開発環境

以下の環境で動作をサポートするものでは**ありません**

|  | Version |
| :--- | :--- |
| CPU | AMD Ryzen 5 2600X |
| RAM | DDR4-2666 16GB |
| OS | WSL Ubuntu 20.04 LTS (Windows 10 Pro) |
| GCC(g++) | 10.2.0 |
| GNU Make | 4.2.1 |
