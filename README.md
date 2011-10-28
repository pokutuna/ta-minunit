# ta-minunit
Cのマイクロテストフレームワーク[minunit](http://www.jera.com/techinfo/jtns/jtn002.html)の拡張と、TAの採点を楽にするスクリプト

- minunit.h : テストフレームワーク
- test.rb : 共有ライブラリとしてコンパイル&テストとリンクして実行するスクリプト
- make.rb : コンパイルをするスクリプト
- test-template.c : テストコードテンプレート
- sample/ : テストを行うディレクトリのサンプル
- tests/ : 各問のテスト置き場

# 使い方
## test.rb
### いっきにテストする
1. 提出システムからダウンロードしてきたソースコードを展開する
2. 1を使ったテストを書く、ファイル名は`test-`で始めるようにする。test-template.cをコピーして作るとよい
3. 2のテストコードとtest.rbを1と同じディレクトリに置く
4. `$ ./test.rb` もしくは `$ ruby test.rb` を実行する

### ファイルごとにテストする
`$ ./test.rb -t 0000.c` で特定のソースコードのみをコンパイル&テストする

### できたファイルを消したい時
共有ライブラリは`lib*.so`、テストを行うバイナリは`t-*`の名前にしてるので
`$ rm lib* t-*` とかを行えば良いのではないでしょうか

## make.rb
1. 提出システムからダウンロードしてきたソースコードを展開する
2. make.rb を1と同じディレクトリに置く
3. `$ ./make.rb` もしくは `$ ruby make.rb`

# テストの書き方
[sample/](https://github.com/pokutuna/ta-minunit/tree/master/sample)以下を例に説明する  
完成するテストコードは[sample/test-T5_4.c](https://github.com/pokutuna/ta-minunit/blob/master/sample/test-T5_4.c)

1. テストしたい関数のプロトタイプをかく  
例えば、"整数 x を入力（引数）とし，その3乗を計算して戻り値として返関数 int cubic(int x) を定義せよ"という問題がある場合、学生の書いたコード内の int cubic(int x) を解決できるようにプロトタイプを書く。

2. テスト関数&あさーしょんを書く  
[sample/test-T5_4.c](https://github.com/pokutuna/ta-minunit/blob/master/sample/test-T5_4.c)
を参考にテストを行う関数を書く。  
ここでは、test_cubic, test_cubic_edge_case の2つのテストを書いている。  
テストしたい対象・関心ごとに関数を分けるとよい  
(関数ごとにテストを分けたり、できて当然のテストと加点に値するテストを分けたり)  
関数内では、mu_assertを利用し"テストしたい関数"と"期待する値"を比較する。

3. テスト関数を呼ぶ  
テストを行う関数をall_testsからmu_run_testを通して呼ぶ。mu_run_testに関数名を渡せばよい。

4. テストを実行する
`test.rb`を実行するといい、`sample/` 内でやってみるとわかる
テストが失敗すると`failed assertion cubic(2) == 8`みたいな感じで教えてくれる


中では各ソースコードに以下ようなことを繰り返してる

`nkf -w --overwrite` utf8に変換  
`gcc -fPIC -shared 0000.c -o lib0000.so` 共有ライブラリとしてコンパイル  
`gcc test-hoge.c lib0000.so -o t-0000` テストコードとリンク  
`./t-0000`  テスト実行


# 他
なんかわからないことあったら聞いてください


書いたテストを送ってくれたらtests/以下に置きます


実行結果の#のある行でフィルタしたらファイル名(学籍番号)とテスト通った数だけ見れる
