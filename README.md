# Hotrace - ハッシュテーブルアルゴリズム実装

## 📋 プロジェクト概要

Hotraceは、42Tokyoの課題として実装されたハッシュテーブルベースの高速検索システムです。キーと値のペアを効率的に保存し、後から高速に検索できるプログラムです。

## 🎯 目的

このプロジェクトでは以下の技術を学び、実装します：
- **ハッシュテーブル**の実装と理解
- **チェイニング法**による衝突解決
- **メモリ管理**の適切な実装
- **標準入出力**を使ったデータ処理
- **効率的なアルゴリズム**の設計

## 🏗️ プロジェクト構造

```
Hotrace_hashtable_algorithm/
├── includes/
│   └── hotrace.h          # ヘッダーファイル（構造体定義、関数宣言）
├── srcs/
│   ├── main.c             # メイン処理（入出力、フェーズ管理）
│   ├── hash.c             # ハッシュテーブル操作（挿入、検索、解放）
│   └── utils.c            # ユーティリティ関数（文字列操作、エラー処理）
├── Makefile               # ビルド設定
├── input.txt              # サンプル入力ファイル
└── README.md              # このファイル
```

## 🔧 技術仕様

### ハッシュテーブル仕様
- **テーブルサイズ**: 10,007（素数）
- **ハッシュ関数**: DJB2アルゴリズム
- **衝突解決**: チェイニング法（連結リスト）
- **バッファサイズ**: 1,000,000バイト

### データ構造
```c
typedef struct s_entry {
    char *key;              // キー文字列
    char *value;            // 値文字列
    struct s_entry *next;   // 次のエントリ（チェイニング用）
} t_entry;
```

## 🚀 使用方法

### 1. ビルド
```bash
make
```

### 2. 実行
```bash
./hotrace < input.txt
```

または、標準入力から直接入力：
```bash
./hotrace
# キーと値のペアを入力
# 空行で区切り
# 検索したいキーを入力
```

### 3. 入力形式
```
key1
value1
key2
value2
key3
value3

search_key1
search_key2
search_key3
```

- 最初の部分：キーと値のペア（挿入フェーズ）
- 空行：挿入フェーズと検索フェーズの区切り
- 後半部分：検索したいキー（検索フェーズ）

### 4. 出力例
```
value1
value2
search_key3 Not found.
```

## 📝 実装の詳細

### メイン処理（main.c）
1. **挿入フェーズ**: キーと値のペアをハッシュテーブルに保存
2. **検索フェーズ**: 入力されたキーに対応する値を検索・表示

### ハッシュ関数（hash.c）
- **DJB2アルゴリズム**: 高速で分布の良いハッシュ関数
- **モジュロ演算**: テーブルサイズで割った余りをインデックスとして使用

### ユーティリティ関数（utils.c）
- `str_dup`: 文字列の複製
- `str_cmp`: 文字列比較
- `str_len`: 文字列長取得
- `fatal_error`: エラー処理

## 🧪 テスト

### サンプルテスト
```bash
echo -e "apple\nred\nbanana\nyellow\ngrape\npurple\n\nbanana\ngrape\nlemon" | ./hotrace
```

期待される出力：
```
yellow
purple
lemon Not found.
```

### エラーテスト
- 空の入力
- 非常に大きな入力
- 不正な文字を含む入力

## 🔍 アルゴリズムの特徴

### 利点
- **高速検索**: O(1)平均時間複雑度
- **メモリ効率**: 動的メモリ割り当て
- **柔軟性**: 任意の文字列キーと値

### 制限事項
- **ハッシュ衝突**: 最悪の場合O(n)の検索時間
- **メモリ使用量**: 文字列の複製による追加メモリ

## 🛠️ 開発環境

- **コンパイラ**: GCC
- **フラグ**: -Wall -Wextra -Werror
- **OS**: Unix/Linux/macOS
- **標準**: C99

## 📚 学習ポイント

このプロジェクトを通じて学べること：
1. **ハッシュテーブルの実装**
2. **メモリ管理の重要性**
3. **アルゴリズムの時間・空間複雑度**
4. **標準入出力の活用**
5. **エラー処理の実装**
