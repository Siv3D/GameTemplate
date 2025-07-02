# Siv3D v0.6.16 Game Template
1 つの Siv3D アプリケーションを Windows 環境と macOS 環境で共同開発する際に便利な、プロジェクト構成テンプレート

## Windows でのビルド方法
- `GameTemplate/projects/Game/Game.sln` を開きます

## macOS でのビルド方法
- macOS 版 Siv3D（OpenSiv3D v0.6.16 Project Templates for macOS）を別途ダウンロードして展開します
- 展開した中にある `include/` および `lib/` フォルダを、`GameTemplate/` フォルダにコピーします

```
GameTemplate/
├── .gitignore
├── LICENSE.txt
├── README.md
├── include/
├── lib/
└── projects/
    ├── .gitkeep
    └── Game/
```

- `GameTemplate/projects/Game/Game.xcodeproj` を開きます

